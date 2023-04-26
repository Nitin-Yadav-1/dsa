
def sieve(n : int) -> list:
	if( n == 0 ):
		return [False]
	if( n == 1 ):
		return [False,False]

	primes = [True for i in range(0,n+1)]
	primes[0] = False
	primes[1] = False

	i = 2
	while( i*i <= n ):
		if( not primes[i] ):
			i += 1
			continue
		for j in range(i*i, n+1, i):
			primes[j] = False
		i += 1

	return primes



n = int(input("find primes upto : "))
primes = sieve(n)
for i,val in enumerate(primes):
	if(val):
		print(i, end=' ')
print()