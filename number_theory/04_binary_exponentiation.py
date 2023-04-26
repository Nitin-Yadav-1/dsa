

def binary_expn(a : int, n : int) -> int:
	if( n == 0 ): return 1
	if( n == 1 ): return a
	res = 1
	while(n):
		if( n % 2 ):
			res *= a
			n -= 1
		a *= a
		n //= 2
	return res

base, power = map(int, input("Enter base and power : ").split(" "))
print(binary_expn(base,power))