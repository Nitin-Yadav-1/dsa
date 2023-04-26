#include<iostream>
#include<vector>
using namespace std;

vector<int> prime_factors(int n){
	vector<int> factors;
	for( int d = 2; d*d <= n; d++ ){
		while( n % d == 0 ){
			factors.push_back(d);
			n /= d;
		}
	}
	if( n > 1 )
		factors.push_back(n);
	return factors;
}

int main(){

	int n;
	cout << "Enter number to find its prime factors : ";
	cin >> n;
	vector<int> factors = prime_factors(n);
	for( int val : factors )
		cout << val << " ";
	if( factors.size() == 0 )
		cout << "No prime factors.";
	cout << endl;

	return 0;
}