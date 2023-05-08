#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int lis(vector<int>& nums){

	vector<int> dp(nums.size(), 1);

	for( int i = 0; i < nums.size(); i++ ){
		for( int j = 0; j < i; j++ ){
			if( nums[j] < nums[i] )
				dp[i] = max(dp[i], 1 + dp[j]);
		}
	}

	return *max_element(dp.begin(), dp.end());
}

void restore_lis(vector<int>& nums){

	vector<int> dp(nums.size(), 1);
	vector<int> parent(nums.size(), -1);

	for( int i = 0; i < nums.size(); i++ ){
		for( int j = 0; j < i; j++ ){
			if( nums[j] > nums[i] ) continue;
			if( dp[j] + 1 > dp[i] ){
				dp[i] = dp[j] + 1;
				parent[i] = j;
			}
		}
	}

	vector<int> lis;
	int max_pos = max_element(dp.begin(), dp.end()) - dp.begin();
	do{
		lis.push_back(nums[max_pos]);
		max_pos = parent[max_pos];
	}
	while( max_pos != -1 );

	reverse(lis.begin(), lis.end());

	for( int val : lis )
		cout << val << " ";
	cout << endl;
}


int main(){

	vector<int> nums = {1,2,4,3};

	cout << lis(nums) << endl;
	restore_lis(nums);

	return 0;
}