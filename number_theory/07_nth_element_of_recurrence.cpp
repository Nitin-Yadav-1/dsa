#include<iostream>
using namespace std;
#define mod 1000000007

void print_matrix(int arr[][2], int rows, int cols){
	for( int i = 0; i < rows; i++ ){
		for( int j = 0; j < cols; j++ ){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
}

void matrix_mul(long long to[2][2], long long from[2][2], long long via[2][2]){
	for( int i = 0; i < 2; i++ ){
		for( int j = 0; j < 2; j++ ){
			via[i][j] = 0;
			for( int k = 0; k < 2; k++ ){
				long long x = (to[i][k] * from[k][j]) % mod;
				via[i][j] += x % mod;
			}
		}
	}

	for( int i = 0; i < 2; i++ )
		for( int j = 0; j < 2; j++ )
			to[i][j] = via[i][j];
}

void matrix_exponentiation(long long arr[2][2], int power){
	long long id[2][2] = { 1, 0, 0, 1};
	long long via[2][2] = {0, 0, 0, 0};

	while(power){
		if(power % 2){
			matrix_mul(id,arr,via);
			power--;
		}
		matrix_mul(arr,arr,via);
		power /= 2;
	}

	arr[0][0] = id[0][0];
	arr[0][1] = id[0][1];
	arr[1][0] = id[1][0];
	arr[1][1] = id[1][1];
}


long long nth_fib( int a, int b, int n ){
	if( n == 0 ) return a;
	if( n == 1 ) return b;

	long long arr[1][2] = {a , b};
	long long m[2][2] = {0, 1, 1, 1};
	matrix_exponentiation(m, n-1);

	return ((arr[0][0] * m[0][1]) + (arr[0][1] * m[1][1])) % mod;
}

int main(){
	int t;
	cin >> t;

	while(t--){
		int a, b, n;
		cin >> a >> b >> n;
		cout << nth_fib(a, b, n) << "\n";
	}

	return 0;
}