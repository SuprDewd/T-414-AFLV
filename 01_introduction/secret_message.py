import math
for q in range(int(input())):
    message = input()
    l = len(message)
    m = math.ceil(math.sqrt(l)) ** 2
    message += '*' * (m - l)
    k = int(round(math.sqrt(m)))

    secret = ""

    for i in range(k):
        for j in range(k):
            if message[(k - j - 1) * k + i] != '*':
                secret += message[(k - j - 1) * k + i]
    print(secret)
