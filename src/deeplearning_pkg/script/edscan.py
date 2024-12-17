import canopen
import os

eds_file = "Easy-ak_v1.31.eds"



network = canopen.Network()

try:
    
    network.connect(interface='socketcan', channel='vcan0', bitrate=500000)

    node_id = 35  
    node = network.add_node(node_id, eds_file)

    device_name = node.sdo[0x1008].raw  
    vendor_id = node.sdo[0x1018][1].raw  

    print(f"Device Name: {device_name}")
    print(f"Vendor ID: {vendor_id}")

    node.nmt.state = 'RESET COMMUNICATION'
    node.nmt.wait_for_bootup(timeout=10)
    print(f"Node State after reset: {node.nmt.state}")

    error_log = node.sdo[0x1003]  
    print("Error Log:")
    for idx, error in error_log.items():
        print(f"  Error Index {idx}: {error.raw}")

    node.rpdo.read()  
    node.rpdo[1]['Controlword'].raw = 0x06  
    node.rpdo[1].transmit()
    print("PDO transmitted successfully")

except Exception as e:
    print(f"Error: {e}")
finally:
    network.disconnect()
    print("Disconnected from CAN network.")
