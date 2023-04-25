
def merge(nums : list, start : int, mid : int, end : int) -> None:
	temp = []
	i, j = start, mid+1
	while( i <= mid and j <= end ):
		if( nums[i] <= nums[j] ):
			temp.append(nums[i])
			i += 1
		else:
			temp.append(nums[j])
			j += 1
	
	while( i <= mid ):
		temp.append(nums[i])
		i += 1
		
	while( j <= end ):
		temp.append(nums[j])
		j += 1
		
	for i,num in enumerate(temp):
		nums[start+i] = num
	

def merge_sort(nums : list, start : int, end : int) -> None:
	if( start >= end ):
		return
	mid = (start + end) // 2;
	merge_sort(nums, start, mid)
	merge_sort(nums, mid+1, end)
	merge(nums, start, mid, end)	
	
nums = [78,23,12,65,2,11,99,34,75,41,54]

merge_sort(nums, 0, len(nums)-1)
print(nums)

