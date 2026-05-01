# 👉👈 Two Pointers Mastery Guide — 95% Interview Coverage

> **Goal**: Solve 95% of all two-pointer interview questions with pattern recognition, not memorization.
> **Method**: 10 patterns → recognition flowchart → templates → curated problem set.

---

## 📌 Table of Contents

1. [Pattern Recognition Flowchart](#pattern-recognition-flowchart)
2. [Pattern 1 — Opposite Ends (Converging)](#pattern-1--opposite-ends-converging)
3. [Pattern 2 — Same Direction (Fast & Slow)](#pattern-2--same-direction-fast--slow)
4. [Pattern 3 — Sliding Window (Fixed Size)](#pattern-3--sliding-window-fixed-size)
5. [Pattern 4 — Sliding Window (Variable Size)](#pattern-4--sliding-window-variable-size)
6. [Pattern 5 — Two Arrays / Merge](#pattern-5--two-arrays--merge)
7. [Pattern 6 — Three Pointers](#pattern-6--three-pointers)
8. [Pattern 7 — Linked List Two Pointers](#pattern-7--linked-list-two-pointers)
9. [Pattern 8 — Partitioning / Dutch National Flag](#pattern-8--partitioning--dutch-national-flag)
10. [Pattern 9 — Prefix / Suffix with Two Passes](#pattern-9--prefix--suffix-with-two-passes)
11. [Pattern 10 — Binary Search as Second Pointer](#pattern-10--binary-search-as-second-pointer)
12. [30-Day Mastery Roadmap](#30-day-mastery-roadmap)
13. [Hybrid Decision Guide](#hybrid-decision-guide)

---

## Pattern Recognition Flowchart

```
START — Read the problem statement
         |
         ▼
Is the array/string SORTED (or can be sorted without losing info)?
And are you looking for a PAIR satisfying a condition?
         |
        YES ──────────────────────────► Pattern 1: Opposite Ends (Converging)
         |
         ▼
Do you need to REMOVE / DEDUPLICATE / COMPRESS in-place?
Or detect something with a FAST pointer running ahead?
         |
        YES ──────────────────────────► Pattern 2: Same Direction (Fast & Slow)
         |
         ▼
Is the WINDOW SIZE FIXED? (exactly K elements)
(Max sum of K, average of K, anagram in window)
         |
        YES ──────────────────────────► Pattern 3: Sliding Window Fixed
         |
         ▼
Is the WINDOW SIZE VARIABLE? (at most / at least K)
(Longest substring with condition, smallest subarray with sum ≥ target)
         |
        YES ──────────────────────────► Pattern 4: Sliding Window Variable
         |
         ▼
Are there TWO SEPARATE arrays/lists to process simultaneously?
(Merge, intersect, compare, interleave)
         |
        YES ──────────────────────────► Pattern 5: Two Arrays / Merge
         |
         ▼
Does the problem involve a TRIPLET or requires THREE indices?
(3Sum, closest triplet, three-way partition)
         |
        YES ──────────────────────────► Pattern 6: Three Pointers
         |
         ▼
Is the input a LINKED LIST?
(Cycle detection, middle node, Nth from end, palindrome)
         |
        YES ──────────────────────────► Pattern 7: Linked List Two Pointers
         |
         ▼
Does the problem ask to PARTITION or REARRANGE in-place?
(Move zeros, sort colors, separate odds/evens)
         |
        YES ──────────────────────────► Pattern 8: Partitioning / DNF
         |
         ▼
Does the solution need a LEFT-TO-RIGHT and RIGHT-TO-LEFT pass?
(Product except self, max water trapped, candy)
         |
        YES ──────────────────────────► Pattern 9: Prefix / Suffix Two Pass
         |
         ▼
Is one pointer JUMPING via BINARY SEARCH while the other is linear?
(Find pair with sum, count pairs, kth smallest in matrix)
         |
        YES ──────────────────────────► Pattern 10: Binary Search as Pointer
         |
         ▼
        END
```

### 10-Second Interview Shortcut

| Signal in problem | Pattern |
|---|---|
| Sorted array, find pair with sum/condition | P1 — Opposite Ends |
| Remove duplicates, in-place overwrite | P2 — Fast & Slow |
| Exactly K elements, fixed window | P3 — Fixed Window |
| Longest/shortest with condition, variable window | P4 — Variable Window |
| Two arrays, merge or intersect | P5 — Two Arrays |
| Triplets, 3Sum variants | P6 — Three Pointers |
| Linked list cycle, middle, Nth from end | P7 — Linked List |
| Rearrange, partition, sort in-place | P8 — Partition / DNF |
| Prefix and suffix accumulation | P9 — Prefix / Suffix |
| Binary search for second boundary | P10 — Binary Search Pointer |

---

## Pattern 1 — Opposite Ends (Converging)

### 📖 Notes & Theory

**What it is**: Place one pointer at the start (`left = 0`) and one at the end (`right = n - 1`). Move them toward each other based on a condition. Most commonly used on **sorted arrays** where you need to find a pair satisfying some constraint.

**How to identify**:
- Array is sorted (or sorting doesn't lose required information)
- "Find two numbers that sum to target", "closest pair", "container with most water"
- You need to explore pairs without O(n²) brute force
- Keywords: "pair", "two numbers", "sorted array", "palindrome check"

**Algorithm skeleton**:
```cpp
int left = 0, right = n - 1;
while (left < right) {
    int curr = nums[left] + nums[right];
    if (curr == target) {
        // found — record answer
        left++; right--;
    } else if (curr < target) {
        left++;  // need larger sum
    } else {
        right--; // need smaller sum
    }
}
```

**Why it works**: In a sorted array, moving `left` right increases the sum; moving `right` left decreases the sum. This is a systematic O(n) search of all useful pairs.

**Palindrome check variant**:
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++; right--;
    }
    return true;
}
```

**Trapping Rain Water** — track running max from both sides:
```cpp
int left = 0, right = n - 1, leftMax = 0, rightMax = 0, water = 0;
while (left < right) {
    if (nums[left] <= nums[right]) {
        leftMax = max(leftMax, nums[left]);
        water += leftMax - nums[left++];
    } else {
        rightMax = max(rightMax, nums[right]);
        water += rightMax - nums[right--];
    }
}
```

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 167 | Two Sum II — Sorted Array | Medium | Foundation converging |
| ⭐ 11 | Container With Most Water | Medium | Greedy pointer move |
| ⭐ 42 | Trapping Rain Water | Hard | Two max boundaries |
| ⭐ 125 | Valid Palindrome | Easy | Classic left-right check |
| ⭐ 977 | Squares of Sorted Array | Easy | Merge from ends |
| 1679 | Max Number of K-Sum Pairs | Medium | Count pairs in-place |
| 2824 | Count Pairs Whose Sum is Less than Target | Easy | Count valid pairs |
| 1877 | Minimize Maximum Pair Sum | Medium | Sort + pair ends |

### 📚 All Problems in Pattern 1

- 11 Container With Most Water
- 15 3Sum (see Pattern 6)
- 42 Trapping Rain Water
- 125 Valid Palindrome
- 167 Two Sum II Input Array Is Sorted
- 344 Reverse String
- 345 Reverse Vowels of a String
- 680 Valid Palindrome II
- 977 Squares of a Sorted Array
- 1099 Two Sum Less Than K
- 1498 Number of Subsequences That Satisfy Conditions
- 1679 Max Number of K-Sum Pairs
- 1877 Minimize Maximum Pair Sum in Array
- 2824 Count Pairs Whose Sum is Less than Target
- 2825 Make String a Subsequence Using Cyclic Increments

---

## Pattern 2 — Same Direction (Fast & Slow)

### 📖 Notes & Theory

**What it is**: Both pointers move in the **same direction** (left to right), but at different speeds or with different conditions for advancing. The `slow` pointer marks the position of the last valid element written; the `fast` pointer scans ahead.

**How to identify**:
- "Remove duplicates in-place", "remove element", "compress array"
- "Read pointer" vs "write pointer"
- Keywords: "in-place", "remove", "overwrite", "keep only", "deduplicate"

**Algorithm skeleton (Remove Duplicates)**:
```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (isValid(nums[fast], slow)) {
        nums[slow++] = nums[fast]; // write valid element
    }
    // fast always advances; slow only advances on valid
}
return slow; // new length
```

**Remove Element (27)**:
```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (nums[fast] != val) nums[slow++] = nums[fast];
}
```

**Remove Duplicates II — allow at most 2 (80)**:
```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (slow < 2 || nums[fast] != nums[slow - 2]) {
        nums[slow++] = nums[fast];
    }
}
```

**Key insight**: Think of `slow` as the "write head" of a tape and `fast` as the "read head". Every element `fast` reads either gets written or skipped. The general rule: write `nums[fast]` when `nums[fast]` satisfies the condition relative to `nums[slow - 1]` (the last written).

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 26 | Remove Duplicates from Sorted Array | Easy | Foundation fast/slow |
| ⭐ 27 | Remove Element | Easy | Filter in-place |
| ⭐ 80 | Remove Duplicates II (allow ≤ 2) | Medium | Generalized condition |
| ⭐ 283 | Move Zeroes | Easy | Stable partition |
| 88 | Merge Sorted Arrays | Easy | Reverse two-pointer |
| 443 | String Compression | Medium | Read/write on same array |
| 1750 | Minimum Length of String After Deleting | Medium | Inward erase from both ends |
| 2332 | Latest Time Catch Bus | Medium | Greedy with fast/slow |

### 📚 All Problems in Pattern 2

- 26 Remove Duplicates from Sorted Array
- 27 Remove Element
- 80 Remove Duplicates from Sorted Array II
- 88 Merge Sorted Array
- 283 Move Zeroes
- 443 String Compression
- 487 Max Consecutive Ones II
- 1004 Max Consecutive Ones III (see Pattern 4)
- 1750 Minimum Length of String After Deleting Similar Ends
- 2332 The Latest Time to Catch a Bus
- 2460 Apply Operations to an Array

---

## Pattern 3 — Sliding Window (Fixed Size)

### 📖 Notes & Theory

**What it is**: Maintain a window of **exactly K elements**. Add the new right element and remove the leftmost element as the window slides forward. The window size is always K.

**How to identify**:
- "Subarray of size K", "average of K elements", "max sum of K consecutive"
- "Anagram in string" (window size = pattern length)
- Keywords: "exactly K", "consecutive K", "fixed length"

**Algorithm skeleton**:
```cpp
int windowSum = 0;
// Build initial window
for (int i = 0; i < k; i++) windowSum += nums[i];

int maxSum = windowSum;
// Slide the window
for (int i = k; i < n; i++) {
    windowSum += nums[i];       // add incoming element
    windowSum -= nums[i - k];   // remove outgoing element
    maxSum = max(maxSum, windowSum);
}
```

**Anagram / Character Frequency (fixed window)**:
```cpp
// Use frequency array diff count to track valid window in O(1)
vector<int> freq(26, 0);
int diff = 0; // number of characters whose counts differ

// Build initial window of size k
for (int i = 0; i < k; i++) {
    freq[s[i] - 'a']++;
    freq[p[i] - 'a']--;
}
diff = count_if(freq.begin(), freq.end(), [](int x){ return x != 0; });

// Slide
for (int i = k; i < s.size(); i++) {
    // add s[i], remove s[i-k]
    // update diff accordingly
}
```

**Key insight**: Fixed window problems are easy to spot — the size K never changes. The "add right, remove left" operation runs in O(1) per step, giving O(n) overall.

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 643 | Maximum Average Subarray I | Easy | Foundation fixed window |
| ⭐ 438 | Find All Anagrams in a String | Medium | Frequency diff tracking |
| ⭐ 567 | Permutation in String | Medium | Same as 438 |
| ⭐ 1343 | Number of Subarrays of Size K ≥ threshold | Medium | Fixed window sum |
| 239 | Sliding Window Maximum | Hard | Deque for max in window |
| 1052 | Grumpy Bookstore Owner | Medium | Baseline + window bonus |
| 2090 | K Radius Subarray Averages | Medium | Prefix sum / fixed window |
| 2379 | Minimum Recolors to Get K Consecutive | Easy | Count blacks in window |

### 📚 All Problems in Pattern 3

- 219 Contains Duplicate II
- 239 Sliding Window Maximum
- 438 Find All Anagrams in a String
- 567 Permutation in String
- 643 Maximum Average Subarray I
- 1052 Grumpy Bookstore Owner
- 1343 Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
- 1423 Maximum Points You Can Obtain from Cards
- 1461 Check If a String Contains All Binary Codes of Size K
- 1652 Defuse the Bomb
- 2090 K Radius Subarray Averages
- 2379 Minimum Recolors to Get K Consecutive Black Blocks
- 2461 Maximum Sum of Distinct Subarrays With Length K
- 2841 Maximum Sum of Almost Unique Subarray

---

## Pattern 4 — Sliding Window (Variable Size)

### 📖 Notes & Theory

**What it is**: The window **expands** by moving `right` forward and **shrinks** by moving `left` forward when a constraint is violated. The window size changes dynamically. This is the most powerful and frequently asked sliding window pattern.

**How to identify**:
- "Longest subarray/substring satisfying condition"
- "Smallest subarray with sum ≥ target"
- "At most K distinct characters", "at most K zeros flipped"
- Keywords: "longest", "shortest", "at most", "at least", "minimum window"

**Algorithm skeleton (Longest)**:
```cpp
int left = 0, maxLen = 0;
// some state (hashmap, count, sum)

for (int right = 0; right < n; right++) {
    // expand: add nums[right] to window state

    while (windowViolatesConstraint()) {
        // shrink: remove nums[left] from window state
        left++;
    }

    maxLen = max(maxLen, right - left + 1);
}
```

**Algorithm skeleton (Shortest)**:
```cpp
int left = 0, minLen = INT_MAX;
int windowSum = 0;

for (int right = 0; right < n; right++) {
    windowSum += nums[right];

    while (windowSum >= target) {
        minLen = min(minLen, right - left + 1);
        windowSum -= nums[left++]; // shrink aggressively
    }
}
```

**Minimum Window Substring (76)** — track missing character count:
```cpp
unordered_map<char, int> need, have;
for (char c : t) need[c]++;
int formed = 0, required = need.size();
int left = 0, minLen = INT_MAX, start = 0;

for (int right = 0; right < s.size(); right++) {
    char c = s[right];
    have[c]++;
    if (need.count(c) && have[c] == need[c]) formed++;

    while (formed == required) {
        if (right - left + 1 < minLen) { minLen = right - left + 1; start = left; }
        have[s[left]]--;
        if (need.count(s[left]) && have[s[left]] < need[s[left]]) formed--;
        left++;
    }
}
```

**Key insight**: "At most K" problems can be solved with the trick:
`exactly(K) = atMost(K) − atMost(K−1)`

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 3 | Longest Substring Without Repeating | Medium | Classic variable window |
| ⭐ 76 | Minimum Window Substring | Hard | Full frequency tracking |
| ⭐ 209 | Minimum Size Subarray Sum | Medium | Shortest with sum ≥ target |
| ⭐ 424 | Longest Repeating Character Replacement | Medium | Max freq + window size trick |
| ⭐ 1004 | Max Consecutive Ones III | Medium | At most K zeros |
| ⭐ 904 | Fruit Into Baskets | Medium | At most 2 distinct |
| 340 | Longest Substring with At Most K Distinct | Medium | Hashmap size constraint |
| 992 | Subarrays with K Different Integers | Hard | atMost(K) − atMost(K−1) |
| 1658 | Minimum Operations to Reduce to Zero | Medium | Max subarray = total − target |
| 2962 | Count Subarrays Where Max Element Appears K Times | Medium | Frequency window |

### 📚 All Problems in Pattern 4

- 3 Longest Substring Without Repeating Characters
- 76 Minimum Window Substring
- 159 Longest Substring with At Most Two Distinct Characters
- 209 Minimum Size Subarray Sum
- 340 Longest Substring with At Most K Distinct Characters
- 395 Longest Substring with At Least K Repeating Characters
- 424 Longest Repeating Character Replacement
- 487 Max Consecutive Ones II
- 713 Subarray Product Less Than K
- 904 Fruit Into Baskets
- 992 Subarrays with K Different Integers
- 1004 Max Consecutive Ones III
- 1234 Replace the Substring for Balanced String
- 1493 Longest Subarray of 1s After Deleting One Element
- 1658 Minimum Operations to Reduce X to Zero
- 2024 Maximize the Confusion of an Exam
- 2260 Minimum Consecutive Cards to Pick Up
- 2401 Longest Nice Subarray
- 2461 Maximum Sum of Distinct Subarrays With Length K
- 2537 Count the Number of Good Subarrays
- 2730 Find the Longest Semi-Repetitive Subarray
- 2779 Maximum Beauty of an Array After Applying Operation
- 2962 Count Subarrays Where Max Element Appears at Least K Times
- 3090 Maximum Length Substring With Two Occurrences
- 3297 Count Substrings That Can Be Rearranged to Contain a String

---

## Pattern 5 — Two Arrays / Merge

### 📖 Notes & Theory

**What it is**: Use one pointer per array and advance the one pointing to the smaller (or more relevant) element. Classic examples: merge two sorted arrays, find intersection, compare sequences.

**How to identify**:
- Two separate arrays/lists given as input
- "Merge", "intersect", "find common elements", "compare two sequences"
- Keywords: "two arrays", "intersection", "union", "merge sorted"

**Algorithm skeleton (Merge)**:
```cpp
int i = 0, j = 0;
vector<int> result;

while (i < a.size() && j < b.size()) {
    if (a[i] < b[j]) result.push_back(a[i++]);
    else if (a[i] > b[j]) result.push_back(b[j++]);
    else { result.push_back(a[i]); i++; j++; } // equal — handle based on problem
}
// Handle remaining elements
while (i < a.size()) result.push_back(a[i++]);
while (j < b.size()) result.push_back(b[j++]);
```

**Intersection (349/350)**:
```cpp
// Advance the pointer with smaller value; record when equal
while (i < a.size() && j < b.size()) {
    if (a[i] < b[j]) i++;
    else if (a[i] > b[j]) j++;
    else { result.push_back(a[i]); i++; j++; }
}
```

**Is Subsequence (392)** — one pointer per string:
```cpp
int i = 0; // pointer into s (subsequence)
for (int j = 0; j < t.size() && i < s.size(); j++) {
    if (s[i] == t[j]) i++;
}
return i == s.size();
```

**Key insight**: The two-pointer merge is a generalization of the merge step in merge sort. One pointer always advances — either the one with the smaller value or both when equal.

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 88 | Merge Sorted Array | Easy | Reverse merge (fill from end) |
| ⭐ 392 | Is Subsequence | Easy | One-pointer-per-string |
| ⭐ 349 | Intersection of Two Arrays | Easy | Sorted intersect |
| ⭐ 350 | Intersection of Two Arrays II | Easy | With duplicates |
| 986 | Interval List Intersections | Medium | Interval merge variant |
| 1855 | Maximum Distance Between a Pair of Values | Medium | Two sorted arrays |
| 2540 | Minimum Common Value | Easy | Classic two-array scan |
| 408 | Valid Word Abbreviation | Easy | Character vs digit pointer |

### 📚 All Problems in Pattern 5

- 88 Merge Sorted Array
- 349 Intersection of Two Arrays
- 350 Intersection of Two Arrays II
- 392 Is Subsequence
- 408 Valid Word Abbreviation
- 524 Longest Word in Dictionary through Deleting
- 986 Interval List Intersections
- 1855 Maximum Distance Between a Pair of Values
- 2009 Minimum Number of Operations to Make Array Continuous
- 2540 Minimum Common Value
- 2570 Merge Two 2D Arrays by Summing Values
- 2825 Make String a Subsequence Using Cyclic Increments

---

## Pattern 6 — Three Pointers

### 📖 Notes & Theory

**What it is**: Fix one element and use the two-pointer (converging) technique on the remaining subarray. Reduces O(n³) brute force to O(n²).

**How to identify**:
- "Find all triplets", "3Sum", "closest triplet to target"
- "4Sum" (fix two, then two-pointer on rest)
- Keywords: "triplets", "three numbers", "4Sum"

**Algorithm skeleton (3Sum)**:
```cpp
sort(nums.begin(), nums.end());
vector<vector<int>> result;

for (int i = 0; i < n - 2; i++) {
    if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates for i

    int left = i + 1, right = n - 1;
    while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
            result.push_back({nums[i], nums[left], nums[right]});
            while (left < right && nums[left] == nums[left+1]) left++;   // skip dups
            while (left < right && nums[right] == nums[right-1]) right--; // skip dups
            left++; right--;
        } else if (sum < 0) left++;
        else right--;
    }
}
```

**3Sum Closest (16)**:
```cpp
int closest = INT_MAX;
for (int i = 0; i < n - 2; i++) {
    int left = i + 1, right = n - 1;
    while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (abs(sum - target) < abs(closest - target)) closest = sum;
        if (sum < target) left++;
        else if (sum > target) right--;
        else return sum; // exact match
    }
}
```

**4Sum** — fix two, two-pointer on rest:
```cpp
sort(nums.begin(), nums.end());
for (int i = 0; i < n - 3; i++) {
    for (int j = i + 1; j < n - 2; j++) {
        int left = j + 1, right = n - 1;
        // standard two-pointer for target - nums[i] - nums[j]
    }
}
```

**Key insight**: Always **sort first**. Deduplication is done by skipping consecutive equal elements at each pointer level.

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 15 | 3Sum | Medium | Foundation three-pointer |
| ⭐ 16 | 3Sum Closest | Medium | Track closest sum |
| ⭐ 18 | 4Sum | Medium | Two fixed + two-pointer |
| ⭐ 259 | 3Sum Smaller | Medium | Count pairs, not collect |
| 923 | 3Sum With Multiplicity | Medium | Count with duplicates |
| 1577 | Number of Ways Where Square of Number Equals Product | Medium | Three-pointer variant |
| 2367 | Number of Arithmetic Triplets | Easy | Sorted + two-pointer |

### 📚 All Problems in Pattern 6

- 15 3Sum
- 16 3Sum Closest
- 18 4Sum
- 259 3Sum Smaller
- 923 3Sum With Multiplicity
- 1099 Two Sum Less Than K
- 1577 Number of Ways Where Square of One Number Is Equal to Product of Two Numbers
- 2367 Number of Arithmetic Triplets
- 2908 Minimum Sum of Mountain Triplets I

---

## Pattern 7 — Linked List Two Pointers

### 📖 Notes & Theory

**What it is**: Apply two pointers on a **linked list** where random access is impossible. The fast pointer moves 2x (or K steps ahead), and the slow pointer moves 1x. When fast reaches the end, slow is at the middle or a specific position.

**How to identify**:
- "Find middle of linked list", "detect cycle", "Nth node from end"
- "Check if linked list is palindrome"
- Keywords: "linked list", "cycle", "middle", "nth from end"

**Cycle Detection (Floyd's Algorithm)**:
```cpp
ListNode* slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true; // cycle detected
}
return false;
```

**Cycle Start (142)**:
```cpp
// After detecting meeting point, reset slow to head
slow = head;
while (slow != fast) {
    slow = slow->next;
    fast = fast->next; // both move 1 step now
}
return slow; // cycle start
```

**Middle of Linked List**:
```cpp
ListNode* slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
return slow; // middle (upper-mid for even length)
```

**Nth from End (19)**:
```cpp
ListNode* fast = head;
for (int i = 0; i < n; i++) fast = fast->next; // advance fast by n
ListNode* slow = head;
while (fast->next) { slow = slow->next; fast = fast->next; }
// slow->next is the node to remove
slow->next = slow->next->next;
```

**Key insight**: Fast/slow with 2x speed means when fast reaches the end (length L), slow is at L/2. For the Nth-from-end trick, offset fast by N so both reach the end simultaneously.

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 141 | Linked List Cycle | Easy | Floyd's detection |
| ⭐ 142 | Linked List Cycle II | Medium | Find cycle start |
| ⭐ 876 | Middle of the Linked List | Easy | Fast/slow middle |
| ⭐ 19 | Remove Nth Node From End | Medium | Offset-N trick |
| ⭐ 234 | Palindrome Linked List | Easy | Find middle + reverse |
| 160 | Intersection of Two Linked Lists | Easy | Length-difference align |
| 2095 | Delete the Middle Node | Medium | Slow/fast find middle |
| 457 | Circular Array Loop | Medium | Floyd's on array |

### 📚 All Problems in Pattern 7

- 19 Remove Nth Node From End of List
- 141 Linked List Cycle
- 142 Linked List Cycle II
- 160 Intersection of Two Linked Lists
- 234 Palindrome Linked List
- 457 Circular Array Loop
- 876 Middle of the Linked List
- 1721 Swapping Nodes in a Linked List
- 2095 Delete the Middle Node of a Linked List
- 2130 Maximum Twin Sum of a Linked List

---

## Pattern 8 — Partitioning / Dutch National Flag

### 📖 Notes & Theory

**What it is**: Rearrange an array **in-place** around a pivot or boundary condition using multiple pointers. The Dutch National Flag (DNF) algorithm uses three pointers to partition into three groups in O(n) with O(1) space.

**How to identify**:
- "Move zeros to end", "sort array of 0s, 1s, 2s", "partition by condition"
- "Separate even/odd", "partition around pivot"
- Keywords: "in-place rearrange", "partition", "sort colors", "move zeros"

**Move Zeros (283)**:
```cpp
int slow = 0; // next position to write a non-zero
for (int fast = 0; fast < n; fast++) {
    if (nums[fast] != 0) swap(nums[slow++], nums[fast]);
}
```

**Dutch National Flag — Sort Colors (75)**:
```cpp
int low = 0, mid = 0, high = n - 1;
while (mid <= high) {
    if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
    else if (nums[mid] == 1) mid++;
    else swap(nums[mid], nums[high--]); // DON'T increment mid — recheck
}
```

**Key insight for DNF**: The invariant is:
- `[0, low)` → all 0s
- `[low, mid)` → all 1s
- `(high, n-1]` → all 2s
- `[mid, high]` → unexplored

When swapping with `high`, you don't advance `mid` because the swapped element is unknown. When swapping with `low`, you CAN advance both `low` and `mid` since `[low, mid)` were already 1s.

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 75 | Sort Colors | Medium | Dutch National Flag |
| ⭐ 283 | Move Zeroes | Easy | Stable partition |
| ⭐ 905 | Sort Array By Parity | Easy | Even/odd partition |
| ⭐ partition step of QuickSort | N/A | Core | Lomuto / Hoare partition |
| 922 | Sort Array By Parity II | Easy | Two-pointer interleave |
| 1089 | Duplicate Zeros | Easy | In-place with two passes |
| 2149 | Rearrange Array Elements by Sign | Medium | Positive/negative interleave |
| 1652 | Defuse the Bomb | Easy | Circular window |

### 📚 All Problems in Pattern 8

- 75 Sort Colors
- 283 Move Zeroes
- 905 Sort Array By Parity
- 922 Sort Array By Parity II
- 1089 Duplicate Zeros
- 1822 Sign of the Product of an Array
- 2149 Rearrange Array Elements by Sign
- 2161 Partition Array According to Given Pivot
- 2231 Largest Number After Digit Swaps by Parity

---

## Pattern 9 — Prefix / Suffix with Two Passes

### 📖 Notes & Theory

**What it is**: Make one pass from the **left** (building prefix information) and one pass from the **right** (building suffix information), then combine both for the answer. No actual "moving" pointer — two independent sweeps.

**How to identify**:
- "Product of all elements except self", "max from left and right"
- The answer at position `i` depends on both elements to its left AND right
- Keywords: "except self", "both sides", "left and right maximum"

**Product Except Self (238)**:
```cpp
vector<int> result(n, 1);
// Left pass: result[i] = product of all nums[0..i-1]
int prefix = 1;
for (int i = 0; i < n; i++) { result[i] = prefix; prefix *= nums[i]; }
// Right pass: multiply result[i] by product of all nums[i+1..n-1]
int suffix = 1;
for (int i = n-1; i >= 0; i--) { result[i] *= suffix; suffix *= nums[i]; }
return result;
```

**Trapping Rain Water — two-pass**:
```cpp
vector<int> leftMax(n), rightMax(n);
leftMax[0] = heights[0];
for (int i = 1; i < n; i++) leftMax[i] = max(leftMax[i-1], heights[i]);
rightMax[n-1] = heights[n-1];
for (int i = n-2; i >= 0; i--) rightMax[i] = max(rightMax[i+1], heights[i]);
int water = 0;
for (int i = 0; i < n; i++) water += min(leftMax[i], rightMax[i]) - heights[i];
```

**Key insight**: If the answer at each index requires context from both sides simultaneously, prefix-suffix two-pass gives O(n) time and O(n) space. For O(1) space, use the converging two-pointer (Pattern 1) instead.

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 238 | Product of Array Except Self | Medium | Classic prefix × suffix |
| ⭐ 42 | Trapping Rain Water | Hard | Two-pass max arrays |
| ⭐ 135 | Candy | Hard | Two-pass greedy |
| 1991 | Find the Middle Index | Easy | Prefix sum equality |
| 2574 | Left and Right Sum Differences | Easy | Prefix + suffix sums |
| 2256 | Minimum Average Difference | Medium | Prefix sum + suffix |
| 1855 | Maximum Distance Between a Pair | Medium | Suffix max array |

### 📚 All Problems in Pattern 9

- 42 Trapping Rain Water
- 135 Candy
- 238 Product of Array Except Self
- 724 Find Pivot Index
- 1991 Find the Middle Index in Array
- 2256 Minimum Average Difference
- 2574 Left and Right Sum Differences
- 2906 Construct Product Matrix
- 3152 Special Array II

---

## Pattern 10 — Binary Search as Second Pointer

### 📖 Notes & Theory

**What it is**: Use one pointer that scans linearly and a second pointer that **jumps** via binary search rather than moving one step at a time. Useful when the search space for the second pointer is large but ordered.

**How to identify**:
- "For each element, find the largest/smallest element on the right satisfying a condition"
- "Count pairs (i, j) where i < j and condition holds"
- The array is sorted (or partially sorted) and you need a non-adjacent pair
- Keywords: "count pairs", "find closest", "lower bound", "upper bound"

**Count pairs with sum < target**:
```cpp
sort(nums.begin(), nums.end());
int count = 0;
for (int i = 0; i < n; i++) {
    // Binary search for largest j such that nums[i] + nums[j] < target
    int lo = i + 1, hi = n - 1, pos = i;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (nums[i] + nums[mid] < target) { pos = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    count += pos - i; // all indices from i+1 to pos are valid
}
```

**Longest Subsequence with |a[i] - a[j]| ≤ limit**:
```cpp
sort(nums.begin(), nums.end());
for (int i = 0; i < n; i++) {
    // upper_bound to find rightmost valid j
    auto it = upper_bound(nums.begin() + i, nums.end(), nums[i] + limit);
    maxLen = max(maxLen, (int)(it - nums.begin()) - i);
}
```

**Key insight**: Binary search replaces the inner O(n) loop with O(log n), reducing O(n²) to O(n log n). This pattern appears whenever the problem is sorted AND asks "for each i, how many valid j > i exist?"

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 167 | Two Sum II | Medium | Binary search as right pointer |
| ⭐ 1498 | Number of Subsequences with Condition | Medium | Sort + binary search count |
| ⭐ 2563 | Count the Number of Fair Pairs | Medium | Binary search per element |
| 611 | Valid Triangle Number | Medium | Sort + binary search upper bound |
| 1855 | Max Distance Between Pair of Values | Medium | Binary search right array |
| 2824 | Count Pairs Whose Sum is Less Than Target | Easy | Sort + binary search |
| 2300 | Successful Pairs of Spells and Potions | Medium | Sort potions + lower bound |

### 📚 All Problems in Pattern 10

- 167 Two Sum II Input Array Is Sorted
- 611 Valid Triangle Number
- 1498 Number of Subsequences That Satisfy the Given Sum Condition
- 1855 Maximum Distance Between a Pair of Values
- 2300 Successful Pairs of Spells and Potions
- 2563 Count the Number of Fair Pairs
- 2824 Count Pairs Whose Sum is Less than Target
- 2856 Minimum Array Length After Pair Removals

---

## 30-Day Mastery Roadmap

> **Philosophy**: Learn the pattern → internalize the template → apply to 3–5 problems → move on. Do NOT grind 50 easy problems before touching mediums.

### Week 1 — Foundation Patterns (Days 1–7)

| Day | Focus | Problems to Solve |
|---|---|---|
| 1 | Pattern 1: Opposite ends basics | 167, 125, 977, 344 |
| 2 | Pattern 1: Advanced converging | 11, 42, 1679, 1877 |
| 3 | Pattern 2: Fast & slow in-place | 26, 27, 283, 80 |
| 4 | Pattern 2: Compression & overwrite | 88, 443, 1750 |
| 5 | Pattern 8: Partitioning | 75, 283, 905, 922 |
| 6 | Pattern 9: Prefix / Suffix | 238, 1991, 2574 |
| 7 | Review Week 1 | Re-solve 3–4 hardest from week |

### Week 2 — Sliding Window (Days 8–14)

| Day | Focus | Problems to Solve |
|---|---|---|
| 8 | Pattern 3: Fixed window basics | 643, 1343, 2379 |
| 9 | Pattern 3: Fixed window advanced | 438, 567, 1052 |
| 10 | Pattern 4: Variable window basics | 3, 209, 1004 |
| 11 | Pattern 4: Variable window medium | 424, 904, 340 |
| 12 | Pattern 4: Variable window hard | 76, 992, 1658 |
| 13 | Pattern 4: atMost trick | 992, 2962, 2024 |
| 14 | Sliding window review | Re-solve 5 hardest |

### Week 3 — Multi-Pointer & List Patterns (Days 15–21)

| Day | Focus | Problems to Solve |
|---|---|---|
| 15 | Pattern 6: Three pointers | 15, 16, 18 |
| 16 | Pattern 6: Advanced 3Sum variants | 259, 923, 2367 |
| 17 | Pattern 7: Linked list slow/fast | 141, 876, 234 |
| 18 | Pattern 7: Advanced linked list | 142, 19, 160 |
| 19 | Pattern 5: Two arrays / merge | 88, 349, 350, 392 |
| 20 | Pattern 5: Advanced two-array | 986, 1855, 2540 |
| 21 | Review Week 3 | Mix of P5, P6, P7 |

### Week 4 — Advanced & Mock Interviews (Days 22–30)

| Day | Focus | Problems to Solve |
|---|---|---|
| 22 | Pattern 10: Binary search pointer | 167, 1498, 2563 |
| 23 | Pattern 10: Advanced BS pointer | 611, 2300, 2824 |
| 24 | Mixed hard problems | 42, 135, 76, 84 |
| 25 | Pattern review — hardest missed | Fill personal gaps |
| 26 | Cross-pattern problems | 239, 986, 992 |
| 27 | Mock Interview Day 1 | Random 5 (all patterns) |
| 28 | Mock Interview Day 2 | 3 mediums + 1 hard |
| 29 | Weak pattern reinforcement | Fill gaps from mocks |
| 30 | Final review | Re-solve 10 hardest problems |

---

## 🎯 Top 30 "Must Solve" Interview Problems

These are the 30 problems most likely to appear in FAANG/top company interviews, covering all 10 patterns:

| Priority | # | Problem | Pattern | Difficulty |
|---|---|---|---|---|
| 🔥🔥🔥 | 3 | Longest Substring Without Repeating | P4 | Medium |
| 🔥🔥🔥 | 76 | Minimum Window Substring | P4 | Hard |
| 🔥🔥🔥 | 42 | Trapping Rain Water | P1/P9 | Hard |
| 🔥🔥🔥 | 15 | 3Sum | P6 | Medium |
| 🔥🔥🔥 | 141 | Linked List Cycle | P7 | Easy |
| 🔥🔥🔥 | 11 | Container With Most Water | P1 | Medium |
| 🔥🔥🔥 | 238 | Product of Array Except Self | P9 | Medium |
| 🔥🔥🔥 | 209 | Minimum Size Subarray Sum | P4 | Medium |
| 🔥🔥🔥 | 75 | Sort Colors | P8 | Medium |
| 🔥🔥🔥 | 142 | Linked List Cycle II | P7 | Medium |
| 🔥🔥 | 424 | Longest Repeating Character Replacement | P4 | Medium |
| 🔥🔥 | 167 | Two Sum II | P1/P10 | Medium |
| 🔥🔥 | 19 | Remove Nth Node From End | P7 | Medium |
| 🔥🔥 | 239 | Sliding Window Maximum | P3 | Hard |
| 🔥🔥 | 438 | Find All Anagrams in a String | P3 | Medium |
| 🔥🔥 | 16 | 3Sum Closest | P6 | Medium |
| 🔥🔥 | 26 | Remove Duplicates from Sorted Array | P2 | Easy |
| 🔥🔥 | 876 | Middle of the Linked List | P7 | Easy |
| 🔥🔥 | 234 | Palindrome Linked List | P7 | Easy |
| 🔥🔥 | 1004 | Max Consecutive Ones III | P4 | Medium |
| 🔥🔥 | 904 | Fruit Into Baskets | P4 | Medium |
| 🔥🔥 | 135 | Candy | P9 | Hard |
| 🔥 | 567 | Permutation in String | P3 | Medium |
| 🔥 | 18 | 4Sum | P6 | Medium |
| 🔥 | 80 | Remove Duplicates II | P2 | Medium |
| 🔥 | 283 | Move Zeroes | P2/P8 | Easy |
| 🔥 | 992 | Subarrays with K Different Integers | P4 | Hard |
| 🔥 | 160 | Intersection of Two Linked Lists | P7 | Easy |
| 🔥 | 2563 | Count the Number of Fair Pairs | P10 | Medium |
| 🔥 | 1498 | Number of Subsequences | P10 | Medium |

---

## Hybrid Decision Guide

> When a problem feels like it belongs to TWO patterns, use the **dominant pattern rule**: ask "what is the PRIMARY structure driving the solution?"

| Combination | Rule | Example |
|---|---|---|
| P1 vs P4 | P1 if sorted array + pair; P4 if window on unsorted | 167 vs 3 |
| P2 vs P4 | P2 if fixed overwrite (in-place); P4 if dynamic condition | 26 vs 209 |
| P3 vs P4 | P3 if window size is literally fixed K; P4 if size varies | 438 vs 3 |
| P1 vs P9 | P1 if O(1) space converging; P9 if need both sides at once | 42 (either works) |
| P6 vs P1 | P6 if triplet (fix one, then P1); P1 if just pairs | 15 vs 167 |
| P7 vs P2 | P7 if linked list; P2 if array in-place | 876 vs 26 |
| P4 vs P10 | P4 if shrinkable window; P10 if binary search on sorted | 904 vs 2563 |
| P8 vs P2 | P8 if 3-way partition needed; P2 if simple filter | 75 vs 27 |
| P5 vs P1 | P5 if two separate arrays; P1 if one array from both ends | 349 vs 167 |
| P9 vs P4 | P9 if need both-side context per index; P4 if directional window | 238 vs 3 |

---

## Quick Reference — Common Mistakes

| Mistake | Correct Approach |
|---|---|
| Using P1 (converging) on unsorted array | Sort first, or use hashmap instead |
| Forgetting to skip duplicates in 3Sum | After recording answer, skip `while nums[left] == nums[left+1]` |
| Off-by-one in sliding window length | Length = `right - left + 1`, NOT `right - left` |
| Not decrementing window state before advancing `left` | Remove `nums[left]` from state BEFORE `left++` |
| Using `mid++` after swapping with `high` in DNF | DON'T advance mid — the swapped value is unknown |
| Floyd's cycle: starting fast at `head->next` | Start both `slow` and `fast` at `head` for simplest version |
| Binary search pointer: not sorting the array first | Always sort when using binary search as second pointer |
| Variable window: using `if` instead of `while` to shrink | Use `while` — one shrink step may not restore validity |
| Prefix-suffix: overwriting the array before second pass | Use separate prefix/suffix arrays, or do two passes with a running variable |
| Two-array merge: forgetting to drain remaining elements | After main loop, append all remaining elements from both arrays |

---

*Guide compiled from 250+ LeetCode two-pointer problems, mapped to 10 universal patterns.*
*Master these patterns and you will solve 95%+ of two-pointer questions in any technical interview.*
