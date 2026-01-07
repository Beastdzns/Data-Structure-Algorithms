## Link : [Find Minimum in Rotated Sorted Array
](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)

### Intuition:

O(n) -> Use min_element function

o(log n) -> Use binary search

1. Find sorted array segment and mark its minimum element,
2. Move the low to mid+1 if left segment is sorted, or high to mid-1 if right segment is sorted 
3. The overall lowest element is the answer

### Code: 

TC: O(n)
SC: O(1)

```cpp

class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end());
    }
};

```

TC: O(log n)
SC: O(1)

```cpp

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low=0, high=n-1, ans=INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;
            } else {
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};

```