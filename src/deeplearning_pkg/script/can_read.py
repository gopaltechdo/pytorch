# import can
# import time

# def send_can_message(bus, arbitration_id, data):
#     """Send a CAN message."""
#     message = can.Message(arbitration_id=arbitration_id, data=data, is_extended_id=False)
#     try:
#         bus.send(message)
#         print(f"Message sent on {bus.channel_info}: {message}")
#     except can.CanError as e:
#         print(f"Message not sent: {e}")

# def read_can_message(bus):
#     """Read a CAN message."""
#     try:
#         message = bus.recv(timeout=1.0)  # Timeout after 1 second
#         if message:
#             print(f"Message received: {message}")
#         else:
#             print("No message received within timeout.")
#     except Exception as e:
#         print(f"Error receiving message: {e}")

# def main():
#     # Initialize the CAN bus
#     try:
#         bus = can.interface.Bus(channel='can0', bustype='socketcan')
#         print(f"Connected to CAN interface: {bus.channel_info}")
#     except Exception as e:
#         print(f"Error initializing CAN bus: {e}")
#         return

#     # Send a CAN message
#     arbitration_id = 0x123  # Standard CAN ID
#     data = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08]
#     send_can_message(bus, arbitration_id, data)

#     # Read a CAN message
#     read_can_message(bus)

# if __name__ == "__main__":
#     main()


# import can_read
# import time

# def read_can_data():
#     try:
#         # Set up the CAN interface (assuming 'can0')
#         bus = can_read.interface.Bus(channel='can0', bustype='socketcan')

#         print("Listening for CAN messages...")
#         while True:
#             # Receive a message
#             message = bus.recv(timeout=1.0)  # Timeout in seconds
#             if message is None:
#                 print("No message received, retrying...")
#                 continue

#             # Display the message
#             print(f"Received CAN message: ID={hex(message.arbitration_id)}, "
#                   f"Data={message.data.hex()}, DLC={message.dlc}")

#     except KeyboardInterrupt:
#         print("Stopped by user.")
#     except Exception as e:
#         print(f"Error: {e}")
#     finally:
#         print("Shutting down CAN interface...")
#         bus.shutdown()

# if __name__ == "__main__":
#     read_can_data()


import can
import time

def read_can_data():
    bus = None
    try:
        # Set up the CAN interface (assuming 'can0')
        bus = can.interface.Bus(channel='can0', bustype='socketcan')

        print("Listening for CAN messages...")
        while True:
            # Receive a message
            message = bus.recv(timeout=1.0)  # Timeout in seconds
            if message is None:
                print("No message received, retrying...")
                continue

            # Display the message
            print(f"Received CAN message: ID={hex(message.arbitration_id)}, "
                  f"Data={message.data.hex()}, DLC={message.dlc}")

    except can.CanError as e:
        print(f"CAN Error: {e}")
    except KeyboardInterrupt:
        print("Stopped by user.")
    except Exception as e:
        print(f"Error: {e}")
    finally:
        if bus is not None:
            print("Shutting down CAN interface...")
            bus.shutdown()

if __name__ == "__main__":
    read_can_data()
