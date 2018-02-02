import subprocess as sp
avg = 0
i = 128
index = []
opt = 262144
while i < 3000000:
    index.append(i)
    for j in range(0,29):
        sp.call(["create_random_file", str(j), str(30000000), str(opt)])
        sp.call(["get_histogram", str(j), str(i)])
    print("")
    i = i * 2
print(index)