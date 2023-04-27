
def find_prime_factors(n : int) -> list:
	sieve = [-1 for i in range(0,n+1)]
	for i in range(2,n+1):
		if(sieve[i] != -1): continue
		for j in range(i,n+1,i):
			if(sieve[j] != -1): continue
			sieve[j] = i

	factors = []
	while(n > 1):
		factors.append(sieve[n])
		n //= sieve[n]
	return factors


n = int(input("Enter number : "))
factors = find_prime_factors(n)
if( not factors ):
	print("No prime factors.")
for val in factors:
	print(val, end=" ")
print()