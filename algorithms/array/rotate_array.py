
def reverse(arr : list, start : int, end : int ) -> None:
	while( start < end ):
		arr[start], arr[end] = arr[end], arr[start]
		start += 1
		end -= 1

def rotate_right(nums : list, k : int) -> None:
	n = len(nums)
	if( n == 0 ) : return
	k = k % n
	if k == 0 : return
	reverse(nums, 0, n-k-1)
	reverse(nums, n-k, n-1)
	nums.reverse()

def main():
	testcases = [
		([], 0, []),
		([], 1, []),
		([], 2, []),
		([1], 0, [1]),
		([1], 1, [1]),
		([1], 2, [1]),
		([1,2], 0, [1,2]),
		([1,2], 1, [2,1]),
		([1,2], 2, [1,2]),
		([1,2], 3, [2,1]),
		([1,2,3], 0, [1,2,3]),
		([1,2,3], 1, [3,1,2]),
		([1,2,3], 2, [2,3,1]),
		([1,2,3], 3, [1,2,3]),
		([1,2,3], 4, [3,1,2]),
		([1,2,3], 5, [2,3,1]),
	]

	for index,test in enumerate(testcases):
		arr = test[0]
		k = test[1]
		expected = test[2]
		rotate_right(arr, k)

		for i in range(len(arr)):
			if arr[i] != expected[i]:
				print(f"Testcase failed on {index+1}.")
				print(f"Output : {arr}")
				print(f"Expected : {expected}")
				return

		print(f"Testcase {index+1} passed.")


if __name__ == '__main__':
	main()