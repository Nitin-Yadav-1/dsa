#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	cin >> n;

	if( n < 7 ){
		cout << (int)pow(2,n-1) << endl;
		return 0;
	}
	
	long long first = 1;
	long long second = 2;
	long long third = 4;
	long long fourth = 8;
	long long fifth = 16;
	long long sixth = 32;

	n -= 6;
	while( n-- ){
		long long sum = (first + second + third + fourth + fifth + sixth) % 1000000007;
		first = second;
		second = third;
		third = fourth;
		fourth = fifth;
		fifth = sixth;
		sixth = sum;
	}

	cout << sixth << endl;

	return 0;
}