

## 1. Core Observation

* **Neighbor Comparison:** A peak element is strictly greater than its neighbors. Because the problem defines  and  as , any array will have at least one peak.
* **Search Direction:** If you are at an index `i` and , the sequence is currently increasing, so a peak must exist at or after .
* **Logarithmic Requirement:** The  constraint in the problem description is a direct hint to use Binary Search.

---

## 2. Intuition (Brute / Naive Approach)

* **Linear Scan:** We traverse the array from left to right. Since we know the left boundary is , the first time we see an element that is larger than the next one (), that element **must** be a peak.
* **Why it works:** If we reach index `i` without having found a peak, it implies that . If  is also greater than , it satisfies both conditions of a peak.
* **Efficiency:** It requires checking every element in the worst case (e.g., a strictly increasing array), making it .

---

## 3. Intuition (Optimized Approach)

* **Binary Search on Gradient:** We don't need a sorted array to use binary search. We use the **local slope** to decide which direction to move.
* **Key Property:** By comparing `nums[mid]` and `nums[mid+1]`, we can determine if we are on an upward slope (peak is to the right) or a downward slope (peak is to the left or at `mid`).
* **Optimization:** This effectively cuts the search space in half at every step, even in an unsorted array.

---

## 4. Algorithm Steps

### Linear Search:

1. Iterate through the array from `i = 0` to `n-2`.
2. At each step, check if `nums[i] > nums[i+1]`.
3. If true, return `i`.
4. If the loop finishes without returning, the last element must be the peak.

### Binary Search (using your provided logic):

1. Handle base cases: single element arrays or peaks at index `0` or `n-1`.
2. Set `low` to 1 and `high` to `n-2`.
3. While `low <= high`:
* Calculate `mid`.
* If `nums[mid+1] > nums[mid]`, the peak is further right; set `low = mid + 1`.
* Else, the peak is at `mid` or to the left; set `high = mid - 1`.


4. Return `low`.

---

## 5. Time and Space Complexity

| Approach | Time Complexity | Space Complexity | Justification |
| --- | --- | --- | --- |
| **Linear Search** |  |  | We may traverse the entire array once. No extra space used. |
| **Binary Search** |  |  | The search space is halved in each iteration. No extra space used. |

---

## 6. Final Notes

### Linear Solution Code

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return i;
            }
        }
        return nums.size() - 1;
    }
};

```

### Binary Search Code (As requested)

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        if(nums[0] > nums[1])
            return 0;
        if(nums[n-1] > nums[n-2])
            return n-1;

        int low=1, high=n-2;
        while(low <= high){
            int mid = (low+high) / 2;
            if(nums[mid+1] > nums[mid]) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};

```

* **Interview Tip:** Always clarify if there can be multiple peaks. If there are, the binary search is still valid as it will return *any* one of the peaks.
* **Edge Case:** The problem specifically mentions , which prevents "plateaus" that would break binary search logic.
