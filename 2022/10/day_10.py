import sys

program = []
x = 1
cycle,counter,add,delay,sum = 0,0,0,0,0

for line in sys.stdin:
    program.append(line)

while(True):
    if(counter == len(program) and delay == 0 and add == 0):
        break

    if(delay != 0):
        delay -= 1
        continue
    cycle += 1

    if(cycle == 20 or (cycle-20) % 40 == 0):
        sum += x*cycle

    if(cycle % 40 == 1):
        print("\n" , end ="")
    if((cycle-1)%40 >= x -1 and (cycle-1)%40 <= x +1):
        print("#"  ,end="")
    else:
        print("."  ,end="")
    
    if(add != 0):
        x += add
        add = 0
        continue

    if(program[counter][0:4] != "noop"):
        delay = 1
        add = int(program[counter].split()[1])
    counter += 1

print("\n\nSignal Strength:", sum)