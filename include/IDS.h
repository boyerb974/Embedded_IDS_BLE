extern int sniff_HS_to_LL_cmd(void *data,size_t len);
extern int sniff_HS_to_LL_acl(struct os_mbuf *om);
extern int sniff_LL_to_HS_acl(struct os_mbuf *om);
extern int sniff_LL_to_HS_ev(void *data,size_t len);
