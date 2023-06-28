/*
 * EURECOM: Semester Project
 * Title: IDS for NimBLE BLE stack
 * Student: Baptiste BOYER
 */

#include <syscfg/syscfg.h>
#include <stdarg.h>
#include <stdio.h>
#include <inttypes.h>
#include "os/os.h"

struct ble_npl_mutex lock;

int sniff_HS_to_LL_cmd(void *data, size_t len)
{
    return 0;
}

int sniff_HS_to_LL_acl(struct os_mbuf *om)
{

#if MYNEWT_VAL(KNOB_DETECTION)
    knob_HS_to_LL_acl(struct os_mbuf * om);
#endif

    return 0;
}

int sniff_LL_to_HS_acl(struct os_mbuf *om)
{

#if MYNEWT_VAL(KNOB_DETECTION)
    knob_LL_to_HS_acl(struct os_mbuf * om);
#endif

    return 0;
}

int sniff_LL_to_HS_ev(void *data, size_t len)
{
    return 0;
}

void knob_HS_to_LL_acl(struct os_mbuf *om)
{
    ble_npl_mutex_pend(&lock, OS_TIMEOUT_NEVER);

    while (om)
    {
        parse(om->om_data, om->om_len);
        om = SLIST_NEXT(om, om_next);
    }

    ble_npl_mutex_release(&lock);

    return 0;
}

void knob_LL_to_HS_acl(struct os_mbuf *om)
{
    ble_npl_mutex_pend(&lock, OS_TIMEOUT_NEVER);

    while (om)
    {
        parse(om->om_data, om->om_len);
        om = SLIST_NEXT(om, om_next);
    }

    ble_npl_mutex_release(&lock);

    return 0;
}

void parse(const void *buf, size_t len)
{
    const uint8_t *ch = buf;
    const uint8_t *ch_tmp;
    uint8_t tab_ch[len];
    int i = 0;

    while (len--)   // copy the current packet to tab_ch
    { 
        ch_tmp = ch++;
        tab_ch[i] = *ch_tmp;
        i = i + 1;
    }

    if (tab_ch[6] == 0x06 && tab_ch[7]== 0x00) // Channel ID for SMP
        {
            if (tab_ch[7] == 0x01 || tab_ch[7] == 0x02)  //OP code Pairing request or 
                                                         //Pairing response
            {
                if(tab_ch[12] != MYNEWT_VAL(KNOB_MIN_ENTROPY))      //Check Max entropy
                    {
                        printf("WARNING: entropy value != 16 \n");
                    }
            }
        }
}

