#include<iostream>
#include<vector>
using namespace std;

long long dfs(int row, int col, vector<vector<long long>>& dp ){
	if( row >= (int)dp.size() || col >= (int)dp.size() )
		return 0;

	if( dp[row][col] != -1 )
		return dp[row][col];

	dp[row][col] = (dfs(row+1, col, dp) + dfs(row, col+1, dp)) % 1000000007;

	return dp[row][col];
}

long long solve(int n, vector<vector<char>>& grid){
	if( grid[0][0] == '*' || grid[n-1][n-1] == '*' )
		return 0;
	vector<vector<long long>> dp(n, vector<long long>(n,-1));
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			if( grid[i][j] == '*' )
				dp[i][j] = 0;
	dp[n-1][n-1] = 1;
	dfs(0,0,dp);

	return dp[0][0];
}

int main(){

	int n;
	cin >> n;

	vector<vector<char>> grid(n, vector<char>(n, 0));

	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			cin >> grid[i][j];

	cout << solve(n,grid) << endl;

	return 0;
}