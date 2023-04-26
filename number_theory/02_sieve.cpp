#include<iostream>
#include<vector>
using namespace std;

//print primes in range [1,n]
void sieve(int n){
	if( n <= 1 ){
		cout << "No primes in this range." << endl;
		return;
	}

	vector<bool> primes(n+1,true);
	primes[0] = false;
	primes[1] = false;

	for( int i = 2; i*i <= n; i++ ){
		if( !primes[i] ) continue;
		for( int j = i*i; j <= n; j += i )
			primes[j] = false;
	}

	for( int i = 0; i <= n; i++ )
		if( primes[i] )
			cout << i << " ";

	cout << endl;
}

int main(){
	int n;
	cout << "find primes upto : ";
	cin >> n;
	sieve(n);
	return 0;
}