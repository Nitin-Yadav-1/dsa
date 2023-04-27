#include<iostream>
#include<vector>
using namespace std;


vector<int> find_prime_factors(int n){
	vector<int> sieve(n+1, -1);
	for( int i = 2; i <= n; i++ ){
		if(sieve[i] != -1) continue;
		for( int j = i; j <= n; j += i ){
			if( sieve[j] == -1 )
				sieve[j] = i;
		}
	}
	vector<int> factors;
	while( n > 1 ){
		factors.push_back(sieve[n]);
		n /= sieve[n];
	}
	return factors;
}

int main(){
	int n;
	cout << "Enter number : ";
	cin >> n;

	vector<int> factors = find_prime_factors(n);
	for( int val : factors )
		cout << val << " ";
	if( factors.size() == 0 )
		cout << "No prime factors.";
	cout << endl;
	
	return 0;
}