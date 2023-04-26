

def prime_factors(n : int) -> list:
	factors = []
	d = 2;
	while( d*d <= n ):
		while( n % d == 0 ):
			factors.append(d)
			n //= d
		d += 1
	if n > 1:
		factors.append(n)
	return factors


n = int(input("Enter number : "))
factors = prime_factors(n)
if( not factors ):
	print("No prime factors.")
for val in factors:
	print(val, end=' ')
print()