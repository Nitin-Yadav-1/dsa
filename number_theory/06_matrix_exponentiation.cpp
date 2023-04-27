#include<iostream>
#include<vector>
using namespace std;

void print_mat(vector<vector<int>>& mat, int row, int col ){
	for( int i = 0; i < row; i++ ){
		for( int j = 0; j < col; j++ )
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

void mul(int n, vector<vector<int>>& to, vector<vector<int>>& from, vector<vector<int>>& via ){
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < n; j++ ){
			via[i][j] = 0;
			for( int k = 0; k < n; k++ )
				via[i][j] += to[i][k] * from[k][j];
		}
	}

	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			to[i][j] = via[i][j];
}

void mat_exp(int n, int power, vector<vector<int>>& mat){
	vector<vector<int>> via(n, vector<int>(n,0));
	vector<vector<int>> id(n, vector<int>(n,0));
	for( int i = 0; i < n; i++ )
		id[i][i] = 1;

	while(power){
		if( power % 2 ){
			mul(n,id,mat,via);
			power--;
		}
		mul(n,mat,mat,via);
		power /= 2;
	}

	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			mat[i][j] = id[i][j];
}


int main(){
	int n, power;
	
	cout << "Enter dimension and power : ";
	cin >> n >> power;
	
	cout << "Enter square matrix of size " << n << " : " << endl;
	vector<vector<int>> mat(n, vector<int>(n,0));
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			cin >> mat[i][j];
	
	mat_exp(n, power, mat);
	print_mat(mat,n,n);
	
	return 0;
}