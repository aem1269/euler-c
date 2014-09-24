import sys

def isPrime(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

for line in sys.stdin:
    num = int(line)
    print(isPrime(num))
