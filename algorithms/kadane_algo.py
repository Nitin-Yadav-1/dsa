
def max_subarray_sum(nums : list) -> int:
	curr_sum = 0
	max_sum = float('-inf')
	for val in nums:
		curr_sum += val
		max_sum = max(max_sum, curr_sum)
		if curr_sum < 0: curr_sum = 0
	return max_sum


def main():
	testcases = [
		([1], 1),
		([-1], -1),
		([0], 0),
		([-1, -2], -1),
		([-2, -1], -1),
		([1, 2], 3),
		([1,-1, 2], 2),
		([1,-4, 2], 2),
		([1,-4, 2, 3, -1, 4], 8),
	]

	for index,case in enumerate(testcases):
		output = max_subarray_sum(case[0])
		expected_output = case[1]
		if output == expected_output:
			print(f"Test case {index+1} passed.")
		else:
			print(f"Test case {index+1} failed.")
			print(case[0])
			print(f"Expected : {expected_output}, Got : {output}")
			break


if __name__ == '__main__':
	main()