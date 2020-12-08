import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

fig = plt.figure()
graph = fig.add_subplot(111)
x = []
y = []

for m in range(1, 101):

    if m < 10:
        out = open('../output/output00'+str(m)+'.txt', 'r')
    elif m < 100:
        out = open('../output/output0'+str(m)+'.txt', 'r')
    else:
        out = open('../output/output100.txt', 'r')

    input_argv = out.read().splitlines()

    x.append(int(input_argv[0]))
    y.append(int(input_argv[1]))
    out.close()

f = input('enter the name of the file: ')

graph.plot(x, y)
graph.grid(which='major', color='k')
graph.minorticks_on()
graph.grid(which='minor', color='gray', linestyle=':')
graph.set_xlabel('number of elements')
graph.set_ylabel('microseconds')
fig.savefig("../" + f + '.png')
