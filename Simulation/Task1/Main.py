from random import choices
import matplotlib.pyplot as plt

import numpy
population = [43, 44,45, 46, 47]
weight = [0.1, 0.2, 0.4, 0.2, 0.1]

c1 = choices(population, weight, k =   10**6)
c2 = numpy.random.randint(low = 80 , high = 101, size = 10**6)
x =  numpy.random.normal(15000 , 4500 , size = 10**6)
cnt = 0
mx =0
profit= []

for i in range (0,10**6):
    # c1 = choices(population, weight , k =1)


    res = (249 -c1[i] -c2[i])*x[i] - 1000000
    if(res<0):
        cnt+=1
    mx = max(res  , mx)
    profit.insert(i,res)

print("max profit = ",mx)
print("probability of loss", cnt/10**6)
print("probability of win ", 1- cnt/10**6)
plt.hist(profit , density = True , bins = 50)
plt.ylabel('probability')
plt.show()
plt.hist(c1, density =True , bins = 30)
plt.ylabel('probability of c1')
plt.show()
plt.hist(c2, density=True, bins=30)
plt.ylabel('probability of c2')
plt.show()
plt.hist(x, density=True, bins=30)
# plt.axis([1500 , 28000 , 0, 0.0001])
plt.ylabel('probability of x')
plt.show()

