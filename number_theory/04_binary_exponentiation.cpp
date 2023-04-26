#include<iostream>
using namespace std;

long long binary_expn(int a, int n){
	if( n == 0 ) return 1;
	if( n == 1 ) return a;
	long long res = 1;
	while(n){
		if( n % 2 ){
			res *= a;
			n--;
		}
		a *= a;
		n /= 2;
	}
	return res;
}

int main(){
	int base, power;
	cout << "Enter base and power : ";
	cin >> base >> power;
	cout << binary_expn(base,power) << endl;
	return 0;
}