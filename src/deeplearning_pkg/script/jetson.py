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

#creating tensor of all zeroes
zeroes = torch.zeros(3,4)
print(zeroes)

#creating tensor of all ones
ones = torch.ones(3,4)
print(ones)
#use torch range

one_to_ten= (torch.arange(1,11))
print(one_to_ten)

range =torch.arange(start=0, end=1000, step=77)
print(range)

#creating tesors likes
ten_zeros= torch.zeros_like(input=one_to_ten)
print(ten_zeros)