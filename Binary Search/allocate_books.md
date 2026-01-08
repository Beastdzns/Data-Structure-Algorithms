## Link : [Allocate Books](https://www.interviewbit.com/problems/allocate-books/)

## Core Observation (common to both)

* Each student gets **contiguous books**
* We want to **minimize the maximum pages** assigned to any student
* The answer is **not which books go to whom**, but **what is the minimum possible maximum page limit**

So instead of directly allocating books, we **guess the answer** and verify it.

---

## Intuition — Linear Search

### Key Idea

The minimum possible maximum pages must lie between:

* **Lower bound:** the largest single book (a student must read at least one book)
* **Upper bound:** sum of all pages (one student reads everything)

So we:

1. Start from the smallest possible answer
2. Increase it step by step
3. Stop when allocation becomes possible

### Why this works

* If we fix a page limit `X`, we can **greedily assign books**:

  * Keep adding books to the current student
  * If pages exceed `X`, assign books to the next student
* If we need more than `M` students → `X` is too small
* The **first valid `X`** is the minimum answer

### Mental Model

> “What is the smallest page limit such that all books can be distributed among `M` students?”

### Drawback

* We check **every possible value** between bounds
* Very slow when page sums are large

---

## Intuition — Binary Search (Optimized)

### Key Insight

The feasibility function is **monotonic**:

* If allocation is possible with `X` pages
  → it will also be possible with any value **greater than X**
* If allocation is **not** possible with `X`
  → it will also fail for any value **less than X**

This monotonic behavior allows **binary search**.

---

### How Binary Search Fits

1. Search space = `[maxBook, sumPages]`
2. Pick `mid` as a guessed maximum page limit
3. Check if allocation is possible:

   * ✅ Possible → try smaller values (move left)
   * ❌ Not possible → try larger values (move right)
4. Keep shrinking the range until the minimum valid answer is found

---

### Mental Model

> “Can we do better than this page limit?”

Binary search finds the **minimum feasible limit efficiently**.

---

## Comparison Summary

| Approach      | Intuition                     | Time Complexity |
| ------------- | ----------------------------- | --------------- |
| Linear Search | Try every possible answer     | O(N × S)        |
| Binary Search | Exploit monotonic feasibility | O(N log S)      |

`N` = number of books
`S` = sum of pages

---

## One-Line Explanation

> “We binary search on the minimum possible maximum pages because the feasibility of allocation is monotonic.”


## Code

```cpp
#include<bits/stdc++.h>
bool possible(vector<int>& arr, int n, int m, int maxPages){
    int studentCnt = 1;
    int pageSum = 0;
    
    for(int i=0;i<n;i++){
        if(pageSum + arr[i] <= maxPages){
            pageSum += arr[i];
        } else {
            studentCnt++;
            pageSum = arr[i];
            if(studentCnt > m)
                return false;
        }
    }
    return true;
}
int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if(B > n) return -1;
    
    int lb = *max_element(A.begin(), A.end());
    int sum = accumulate(A.begin(), A.end(), 0);
    int ans = -1;
    
    while(lb <= sum){
        int mid = lb + (sum-lb) / 2;
        if(possible(A, n, B, mid)){
            ans = mid;
            sum = mid-1;
        } else {
            lb = mid + 1;
        }
    }
    
    return ans;
}

int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if (B > n) return -1;

    int lb = *max_element(A.begin(), A.end());
    int ub = accumulate(A.begin(), A.end(), 0);

    for (int pages = lb; pages <= ub; pages++) {
        if (possible(A, n, B, pages)) {
            return pages;   
        }
    }

    return -1;
}
```