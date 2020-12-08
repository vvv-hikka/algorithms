import subprocess
from subprocess import PIPE
import random


def check_results(a):
    for l in range(len(a)-2):
        if a[l] > a[l+1]:
            return 'false'
    return 'true'


f = input('enter the name of the program: ')
subprocess.run("gcc -o ../" + f + ".exe ../" + f + ".c")

i = 1
i = random.randint(i, 300+i)

for m in range(1, 101):

    if m < 10:
        inp_t = '../input/input00'+str(m)+'.txt'
        inp = open(inp_t, 'w+')
        out = open('../output/output00'+str(m)+'.txt', 'w')
    elif m < 100:
        inp_t = '../input/input0'+str(m)+'.txt'
        inp = open(inp_t, 'w+')
        out = open('../output/output0'+str(m)+'.txt', 'w')
    else:
        inp_t = '../input/input100.txt'
        inp = open(inp_t, 'w+')
        out = open('../output/output100.txt', 'w')

    i += 300
    inp.write(str(i)+'\n')

    for k in range(i):
        n = str(random.randint(1, 100))
        inp.write(n+' ')

    inp.close()

    cmd = subprocess.Popen("../" + f + ".exe " + inp_t, stdout=PIPE)
    print(m)
    cmd_out, cmd_err = cmd.communicate()

    to_file = cmd_out.decode("utf-8")

    checking = [int(item) for item in to_file.split()]
    out.write(str(i)+'\n'+to_file+'\n'+check_results(checking))

    out.close()
