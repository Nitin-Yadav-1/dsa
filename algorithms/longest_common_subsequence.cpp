#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string lcs(const string& a, const string& b){
	int n = a.length();
	int m = b.length();

	vector<vector<int>> dp(n+1, vector<int>(m+1,0));

	for( int i = 1; i <= n; i++ ){
		for( int j = 1; j <= m; j++ ){
			if( a[i-1] == b[j-1] ){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	string res = "";
	while( n > 0 && m > 0 ){
		if( a[n-1] == b[m-1] ){
			res += a[n-1];
			n--;
			m--;
		}
		else{
			if( dp[n-1][m] >= dp[n][m-1] )
				n--;
			else
				m--;
		}
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	string a, b;
	cout << "string a : ";
	cin >> a;
	cout << "string b : ";
	cin >> b;
	cout << lcs(a,b) << endl;
	return 0;
}