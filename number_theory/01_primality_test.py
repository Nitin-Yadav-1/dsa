

def is_prime(n : int) -> bool:
	if( n <= 1 ):
		return False
	res = True
	i = 2
	while( i*i <= n ):
		if( n % i == 0 ):
			res = False
			break
		i += 1
	return res

n : int = int(input("Enter number : "))
print( "prime" if is_prime(n) else "not prime")