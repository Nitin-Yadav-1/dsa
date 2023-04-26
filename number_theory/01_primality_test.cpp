#include<iostream>
using namespace std;

bool is_prime(int n){
	if( n <= 1 )
		return false;
	bool res = true;
	for( int i = 2; i*i <= n; i++ ){
		if( n % i == 0 ){
			res = false;
			break;
		}
	}
	return res;
}

int main(){
	int n;
	cout << "Enter number : ";
	cin >> n;
	cout << ((is_prime(n) ? "prime" : "not prime")) << endl;
	return 0;
}