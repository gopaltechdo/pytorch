# from ultralytics import YOLO

# # Load a YOLOv8 model
# model = YOLO('yolov8n.pt')  # Replace with your model (e.g., yolov8s.pt)

# # Export to ONNX format
# model.export(format="onnx")

from ultralytics import YOLO

# Load the YOLOv8 model
model = YOLO("yolov8n.pt")

# Export the model to TensorRT format
model.export(format="engine")  # creates 'yolov8n.engine'

# Load the exported TensorRT model
tensorrt_model = YOLO("yolov8n.engine")

# Run inference
results = tensorrt_model("https://ultralytics.com/images/bus.jpg")