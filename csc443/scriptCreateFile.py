import subprocess as sp
index = []
i = 128 + 1
total = 0
while i < 3000000:
    index.append(i)
    for j in range(0,29):
        sp.call(["create_random_file", str(i),str(30000000), str(i)])
    print("")

    i = (i * 2)
print(index)
