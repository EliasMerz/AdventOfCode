import sys
import array

with open(sys.argv[1], "r") as f:
    total = 0
    data = f.read().split("\n")
    copies = array.array("I",[1 for i in data])
    for i,line in enumerate(data):
        wins = len([i for i in line.split("|")[1].strip().split() if i in line.split(":")[1].split("|")[0].strip().split()])
        if wins > 0:
            total += pow(2,wins-1);
            for j in range(1,wins+1):
                copies[i+j] += copies[i] 
    print(sum(copies))
    print(total)
       