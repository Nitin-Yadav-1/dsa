# from end to start find first peak

# moving a peak to left will always result in bigger number
# ex : [  1,   3,    2 ]
# 			 *	
# 				   *
# 		*
# 	 10^2   10^1  10^0

# move a peak to left and sort the remaining part will always
# result in next greater number

# from peak to end the sequence is in non-increasing order,
# find the first value in this sequence from the end such that
# it is greater than value of left of peak and swap with it
# this value could be the peak too

# the sequence is still in non-increasing order
# hence we can just reverse the peak-to-end part to sort it

# Time Complexity = O(n)
# Space Complexity = O(1)

def next_permutation(nums : list) -> None:
	index, n = -1, len(nums)
	for i in range(n-2, -1, -1):
		if nums[i] < nums[i+1]:
			index = i
			break

	if index == -1:
		nums.reverse()
		return

	for i in range(n-1, index, -1):
		if nums[i] > nums[index]:
			nums[i], nums[index] = nums[index], nums[i]
			break

	reverse(nums, index+1, n-1)


def reverse(nums : list, left : int, right : int) -> None:
	while left <= right :
		nums[left], nums[right] = nums[right], nums[left]
		left += 1
		right -= 1


def are_equal(nums1 : list, nums2 : list) -> bool:
	if len(nums1) != len(nums2):
		return False

	for i in range(len(nums1)):
		if nums1[i] != nums2[i]:
			return False

	return True


def main():
	# case, expected
	testcases = [
		([], []),
		([1], [1]),
		([1,2], [2,1]),
		([2,1], [1,2]),
		([1,2,3], [1,3,2]),
		([1,3,2], [2,1,3]),
		([2,1,3], [2,3,1]),
		([2,3,1], [3,1,2]),
		([3,1,2], [3,2,1]),
		([3,2,1], [1,2,3]),
		([1,1], [1,1]),
		([1,1,2], [1,2,1]),
	]

	for index,test in enumerate(testcases):
		case = test[0]
		expected = test[1]
		next_permutation(case)
		if are_equal(case, expected) :
			print(f"Testcase {index+1} passed.")
		else:
			print(f"Testcase {index+1} failed.")
			print(f"Output = {case}")
			print(f"Expected = {expected}")


if __name__ == '__main__':
	main()
