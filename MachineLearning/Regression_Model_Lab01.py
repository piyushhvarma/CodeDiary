import numpy as np
import matplotlib.pyplot as plt

x_train = np.array([1.0, 3.0])
y_train = np.array([300,500])
m = len(x_train)
print(f"Number of training examples is : {m}")

i = 0
x_i = x_train[i]
y_i = y_train[i]
print(f"(x^({i})), (y^({i})) = ({x_i}, {y_i})")

plt.scatter(x_train, y_train, marker='o', c='r')
plt.title("Housing Prices")
plt.ylabel("Prices (in 1000s of dollars)")
plt.xlabel("Size (1000 sqft)")
plt.show()

w = 100
b = 100 
print(f"w : {w}")
print(f"b : {b}")

def calculate_model_output(w,b,x):
    m = x.shape
    f_wb = np.zeros(m)
    for i in range(len(x)):
        f_wb[i] = w * x[i] + b
    return f_wb    


tmp_f_wb = calculate_model_output(w,b,x_train)
plt.plot(x_train, tmp_f_wb, c = 'x', label='production')
plt.scatter(x_train,y_train, marker='y',c='r', label='original values')
plt.title("Housing Prices")
plt.ylabel("Prices (in 1000s of dollars)")
plt.xlabel("Size (1000 sqft)")
plt.legend()
plt.show()
