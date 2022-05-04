import random


LENGTH = 256
ROUND = 10
output = []
fp = open("./templates/template_manual.txt", "w")
for _ in range(ROUND):
    seq = ""
    for _ in range(LENGTH):
        ch = "1" if random.randint(0, 2) > 0 else "0"
        seq += ch

    seq += "\n"
    fp.write(seq)

fp.close()
