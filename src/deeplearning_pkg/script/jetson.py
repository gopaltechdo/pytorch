import torch



scalar =torch.tensor(8)
print(scalar)

vector = torch.tensor([4,4,4])
print(vector)

materix= torch.tensor([[2,3],[3,2]])
print(materix)

tensor = torch.tensor([[2,2],[3,4],[4,6]])
print(tensor.size)

#creating random tensor
random_tensor = torch.rand(3,4)

print(random_tensor.ndim)

#create  a random  with similar shape to an image tensor 

random_image_size_tensor = torch.rand(3,224,224)  #  colour channel height, & weidth 
