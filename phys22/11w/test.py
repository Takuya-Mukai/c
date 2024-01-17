import numpy as np
import matplotlib.pyplot as plt

def f(t):
    return 2*(1+t**2)/((1-t**2)**2 + t*t)
x = np.linspace(0,1,100)
y = f(x)
plt.plot(x,y)
plt.savefig('test.png')
