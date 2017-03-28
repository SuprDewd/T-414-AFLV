import sys

def fibword_slow(n):

    cur = 'A'
    nxt = 'B'

    for i in range(n - 1):

        cur, nxt = nxt, cur + nxt

    return cur

def fibonacci(n):

    cur = 1
    nxt = 1

    for i in range(n - 1):

        cur, nxt = nxt, cur + nxt

    return cur


def fibword_ith_char(n, k):

    if n == 1:
        assert k == 0
        return 'A'

    if n == 2:
        assert k == 0
        return 'B'

    if k < fibonacci(n-2):
        return fibword_ith_char(n-2, k)
    else:
        return fibword_ith_char(n-1, k-fibonacci(n-2))


n = 1000
k_lo = 2309479823749832749823498327432
k_hi = 2309479823749832749823498327432 + 100

for k in range(k_lo, k_hi + 1):
    sys.stdout.write(fibword_ith_char(n, k))

sys.stdout.write('\n')

# for k in range(k_lo, k_hi + 1):
#     sys.stdout.write(fibword(n)[k])
# 
# sys.stdout.write('\n')

# for i in range(1, 11):
# 
#     print(fibword(i))
# 

