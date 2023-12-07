def binary_search(nums, target):
    left = 0
    right = len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] > target:
            right = mid - 1
        else:
            left = mid
    return -1


print(binary_search([1, 2, 3, 4, 5, 6, 7, 8, 9], 7))
# 輸出：7
