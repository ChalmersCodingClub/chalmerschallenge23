N = int(input())

def isPrime(x):
  for j in range(2,int(x**0.5)+1):
    if x%j==0:
      return False
  return True

def findPrimeNum(num):
  for i in range(num-1,1,-1):
    if isPrime(i):
      return i

def biggest(n):
    if n%3 == 0:
        return pow(3, n//3, 1000000007)
    elif n%3 == 1:
        return (pow(3, n//3 - 1, 1000000007) * 4) % 1000000007
    elif n%3 == 2:
        return (pow(3, n//3, 1000000007) * 2) % 1000000007

def smallest(n):
    # TODO

print(smallest(N), biggest(N))
