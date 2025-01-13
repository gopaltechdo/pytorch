import cv2
import torch
import numpy as np

# Load YOLOv5 model (pretrained on COCO dataset)
model = torch.hub.load('ultralytics/yolov5', 'yolov5s', pretrained=True)

# Define a safe distance threshold (in meters, for demonstration)
SAFE_DISTANCE = 2.0  # Adjust based on sensor or application

# Start video capture (0 = default camera, replace with video path if needed)
cap = cv2.VideoCapture(0)

def calculate_distance(bbox, frame_width, frame_height):
    """
    Estimate distance from the object based on bounding box size.
    Adjust the calculation based on actual sensor calibration.
    """
    bbox_width = bbox[2] - bbox[0]
    # Simple heuristic: the smaller the box, the farther the object
    distance = SAFE_DISTANCE * frame_width / (bbox_width + 1e-5)  # Avoid division by zero
    return round(distance, 2)

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        print("Failed to grab frame")
        break

    # Get frame dimensions
    frame_height, frame_width, _ = frame.shape

    # Inference
    results = model(frame)
    detections = results.pred[0].cpu().numpy()  # Get detections as numpy array

    for det in detections:
        x1, y1, x2, y2, conf, cls = det
        if conf > 0.5:  # Confidence threshold
            label = model.names[int(cls)]
            distance = calculate_distance((x1, y1, x2, y2), frame_width, frame_height)

            # Draw bounding box
            cv2.rectangle(frame, (int(x1), int(y1)), (int(x2), int(y2)), (0, 255, 0), 2)
            cv2.putText(frame, f"{label} {distance}m", (int(x1), int(y1) - 10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

            # Alert if object is within the safe distance
            if distance < SAFE_DISTANCE:
                cv2.putText(frame, "WARNING: Object too close!", (10, 30),
                            cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 3)

    # Show frame
    cv2.imshow("Object Detection", frame)

    # Exit on pressing 'q'
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    

# Release resources
cap.release()
cv2.destroyAllWindows()
