import can

def send_can_frame(bus, can_id, data):
    """
    Send a CAN frame.
    :param bus: CAN bus object
    :param can_id: ID of the CAN frame
    :param data: Data payload (bytearray or list of integers)
    """
    msg = can.Message(
        arbitration_id=can_id,  # Set the CAN ID
        data=data,              # Payload data (max 64 bytes for CAN-FD)
        is_fd=True,             # Use CAN-FD
        is_extended_id=can_id > 0x7FF  # Extended ID if ID > 0x7FF
    )
    try:
        bus.send(msg)
        print(f"Message sent: ID={hex(can_id)}, Data={data}")
    except can.CanError as e:
        print(f"Failed to send message: {e}")

def main():
    # Set up the CAN interface
    channel = "vcan0"  # Use 'can0' for a physical CAN interface
    bustype = "socketcan"
    bitrate = 1000000  # Standard bitrate: 1Mbit/s
    data_bitrate = 5000000  # Data bitrate: 5Mbit/s

    try:
        # Initialize the CAN bus
        bus = can.interface.Bus(channel=channel, bustype=bustype, fd=True)

        # Example: Send a frame to servo ID 1 with reply requested
        source_id = 0x00  # 7-bit source ID
        destination_id = 0x01  # 7-bit destination ID (servo ID)
        reply_requested = 1 << 7  # Set 15th bit for reply request

        can_id = (source_id | reply_requested) << 8 | destination_id

        # Data payload example (max 64 bytes for CAN-FD)
        payload = [0x01, 0x02, 0x03, 0x04]

        # Send the frame
        send_can_frame(bus, can_id, payload)

    except Exception as e:
        print(f"Error initializing CAN bus: {e}")

if __name__ == "__main__":
    main()
