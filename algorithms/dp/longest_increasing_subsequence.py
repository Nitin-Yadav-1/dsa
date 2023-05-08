def lis(nums : list) -> int:
	dp = [1 for i in range(len(nums))]

	for i in range(len(nums)-1, -1, -1):
		for j in range(i, len(nums)):
			if( nums[i] < nums[j] ):
				dp[i] = max(dp[i], 1 + dp[j])

	return max(dp)


def lis_nlogn(nums : list) -> int:
	pass


def main():
	nums = [1,2,4,3]
	print(lis(nums))


if __name__ == '__main__':
	main()