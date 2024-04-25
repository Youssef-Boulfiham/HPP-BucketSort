import matplotlib.pyplot as plt
import numpy as np

x1 = np.array([10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000])
y1 = np.array([
                0.000000048,
                0.00000086,
                0.00000534,
                0.04000937,
                0.047000256,
                0.469000334,
                4.964000523,
                48.539000165,
                487.997000488])

# x = np.array([10, 100, 1000, 10000, 100000])
# y = np.array([0.002, 0.005, 0.023, 0.227, 19.136 ])

fig, ax = plt.subplots()

ax.plot(x, y, label='Niet paralel')
# ax.plot(x1, y1, label='Paralel')

ax.set_xlabel('Input size')
ax.set_ylabel('Duration in seconds')
ax.set_title('Computation speed')

ax.legend()

plt.savefig('computation_speed.png', dpi=300, bbox_inches='tight')