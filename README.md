# Intrusion Detection System (IDS) for BLE using NimBLE Stack

This project focuses on the implementation of an Intrusion Detection System (IDS) for Bluetooth Low Energy (BLE) using the NimBLE stack. The IDS aims to detect and mitigate security attacks targeting BLE communication.

# Overview

The IDS is designed to monitor and analyze the communication exchanges happening within the NimBLE stack. By analyzing the HCI (Host Controller Interface) exchanges, the IDS aims to identify potential security threats and anomalies in real-time. The primary focus of this project has been on detecting the KNOB (Key Negotiation of Bluetooth) attack, which poses a significant security risk in BLE communication.  

# Project Status  

At the moment, the IDS implementation is not yet completed. The progress has been hindered by setup issues encountered during the development process. These issues, primarily related to the Windows operating system, have caused delays and complexities in configuring the NimBLE stack and establishing the required debugging environment.  

# Next Steps

To move forward with the project, the setup issues need to be resolved. This involves addressing the challenges related to warnings treated as errors during compilation and establishing a successful connection between the GDB Server and the GDB Client hosted on the target board. Once these setup issues are resolved, further progress can be made in implementing and refining the IDS functionalities.
