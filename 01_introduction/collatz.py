def is_even(x):
    return x % 2 == 0
def next_step(x):
    return x//2 if is_even(x) else 3*x + 1

if __name__ == '__main__':
    while True:
        a,b = map(int,input().split())
        if a == 0 and b == 0: break
        stepA = 0; stepB = 0
        origA = a; origB = b
        steps = {}
        steps[a] = 0; steps[b] = 0
        if a == b:
            print('{} needs {} steps, {} needs {} steps, they meet at {}'.format(origA, 0, origB, 0, a))
            continue
        while(a != 1 or b != 1):
            if a != 1:
                a = next_step(a)
                stepA += 1
                if a in steps:
                    other_step = steps[a]
                    print('{} needs {} steps, {} needs {} steps, they meet at {}'.format(origA, stepA, origB, other_step, a))
                    break
                else:
                    steps[a] = stepA
            if b != 1:
                b = next_step(b)
                stepB += 1
                if b in steps:
                    other_step = steps[b]
                    print('{} needs {} steps, {} needs {} steps, they meet at {}'.format(origA, other_step, origB, stepB, b))
                    break
                else:
                    steps[b] = stepB

