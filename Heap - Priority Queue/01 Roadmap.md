# 🏔️ Heap / Priority Queue Mastery Guide — 95% Interview Coverage

> **Goal**: Solve 95% of all heap/priority queue interview questions with pattern recognition, not memorization.
> **Method**: 10 patterns → recognition flowchart → templates → curated problem set.

---

## 📌 Table of Contents

1. [Pattern Recognition Flowchart](#pattern-recognition-flowchart)
2. [Pattern 1 — Top K Elements](#pattern-1--top-k-elements)
3. [Pattern 2 — K-th Largest / Smallest](#pattern-2--k-th-largest--smallest)
4. [Pattern 3 — Merge K Sorted Lists / Arrays](#pattern-3--merge-k-sorted-lists--arrays)
5. [Pattern 4 — Two Heaps (Median Stream)](#pattern-4--two-heaps-median-stream)
6. [Pattern 5 — Greedy + Heap (Task Scheduling)](#pattern-5--greedy--heap-task-scheduling)
7. [Pattern 6 — Dijkstra / Shortest Path](#pattern-6--dijkstra--shortest-path)
8. [Pattern 7 — Sliding Window + Heap](#pattern-7--sliding-window--heap)
9. [Pattern 8 — Multi-Level / Custom Comparator](#pattern-8--multi-level--custom-comparator)
10. [Pattern 9 — Heap + Lazy Deletion](#pattern-9--heap--lazy-deletion)
11. [Pattern 10 — Interval Scheduling + Heap](#pattern-10--interval-scheduling--heap)
12. [30-Day Mastery Roadmap](#30-day-mastery-roadmap)
13. [Hybrid Decision Guide](#hybrid-decision-guide)

---

## Pattern Recognition Flowchart

```
START — Read the problem statement
         |
         v
Does the problem ask for TOP K most frequent / largest / smallest elements?
(Top K frequent, K largest in stream, K closest points)
         |
        YES ──────────────────────────► Pattern 1: Top K Elements
         |
         v
Does the problem ask for the K-TH element specifically?
(Kth largest, kth smallest, kth in a sequence)
         |
        YES ──────────────────────────► Pattern 2: K-th Largest / Smallest
         |
         v
Does the problem MERGE multiple sorted structures?
(Merge K sorted lists, smallest range covering K lists)
         |
        YES ──────────────────────────► Pattern 3: Merge K Sorted
         |
         v
Does the problem need MEDIAN from a STREAM of numbers?
(Running median, balance two halves dynamically)
         |
        YES ──────────────────────────► Pattern 4: Two Heaps
         |
         v
Does the problem involve SCHEDULING TASKS with constraints?
(CPU scheduling, reorganize string, task cooldown, most frequent first)
         |
        YES ──────────────────────────► Pattern 5: Greedy + Heap
         |
         v
Does the problem find SHORTEST PATH or MINIMUM COST in a graph?
(Dijkstra, minimum effort path, network delay time)
         |
        YES ──────────────────────────► Pattern 6: Dijkstra / Shortest Path
         |
         v
Does the problem combine a SLIDING WINDOW with a HEAP?
(Max in sliding window, minimum in range, window-constrained heap)
         |
        YES ──────────────────────────► Pattern 7: Sliding Window + Heap
         |
         v
Does the problem require SORTING BY MULTIPLE CRITERIA simultaneously?
(Sort by frequency then value, custom tie-breaking, multi-key ordering)
         |
        YES ──────────────────────────► Pattern 8: Custom Comparator
         |
         v
Does the problem require REMOVING ARBITRARY ELEMENTS from a heap?
(Mark deleted, skip stale entries, invalidate old entries)
         |
        YES ──────────────────────────► Pattern 9: Heap + Lazy Deletion
         |
         v
Does the problem SCHEDULE or PROCESS INTERVALS with a heap?
(Meeting rooms, minimum platforms, event sweep + heap)
         |
        YES ──────────────────────────► Pattern 10: Interval + Heap
         |
         v
        END
```

### 10-Second Interview Shortcut

| Signal in problem | Pattern |
|---|---|
| Top K frequent / largest / closest | P1 — Top K |
| K-th element in sequence | P2 — K-th Element |
| Merge K sorted structures | P3 — Merge K Sorted |
| Running median, balance two halves | P4 — Two Heaps |
| Task scheduling, cooldown, reorganize | P5 — Greedy + Heap |
| Shortest path, min cost in graph | P6 — Dijkstra |
| Heap inside sliding window | P7 — Window + Heap |
| Sort by multiple keys, custom order | P8 — Custom Comparator |
| Delete arbitrary elements from heap | P9 — Lazy Deletion |
| Interval overlap, room assignment | P10 — Interval + Heap |

---

## Pattern 1 — Top K Elements

### Notes and Theory

**What it is**: Find the K largest, K smallest, or K most frequent elements. Maintain a **min-heap of size K** for top-K largest (pop when size exceeds K — the min gets evicted, keeping only the K largest). Use a **max-heap** for top-K smallest.

**How to identify**:
- "Find K largest elements", "K most frequent words"
- "K closest points to origin"
- Keywords: "top K", "K largest", "K most frequent", "K closest"

**Min-heap of size K for Top K Largest**:
```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;

for (int x : nums) {
    minHeap.push(x);
    if (minHeap.size() > k) minHeap.pop(); // evict smallest
}
// minHeap now contains exactly the K largest elements
// minHeap.top() = Kth largest
```

**Top K Frequent Elements (347)**:
```cpp
unordered_map<int, int> freq;
for (int x : nums) freq[x]++;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
for (auto& [val, cnt] : freq) {
    minHeap.push({cnt, val});
    if (minHeap.size() > k) minHeap.pop();
}

vector<int> result;
while (!minHeap.empty()) {
    result.push_back(minHeap.top().second);
    minHeap.pop();
}
```

**K Closest Points to Origin (973)**:
```cpp
// Use max-heap of size K on distance squared (avoid sqrt)
priority_queue<pair<int,int>> maxHeap; // {dist_sq, index}
for (int i = 0; i < points.size(); i++) {
    int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
    maxHeap.push({d, i});
    if (maxHeap.size() > k) maxHeap.pop(); // evict farthest
}
```

**Why min-heap for top-K largest?** The heap's top is the smallest of the K candidates. When a new element arrives larger than the top, pop the top and push the new one. At the end: heap = K largest seen so far.

**Time complexity**: O(n log K) — much better than O(n log n) full sort when K << n.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 347 | Top K Frequent Elements | Medium | Freq map + min-heap size K |
| 973 | K Closest Points to Origin | Medium | Max-heap size K on distance |
| 692 | Top K Frequent Words | Medium | Custom comparator |
| 215 | Kth Largest Element in Array | Medium | Min-heap size K |
| 1985 | Find the Kth Largest Integer in Array | Medium | String comparison heap |
| 1636 | Sort Array by Increasing Frequency | Easy | Sort by freq then value |
| 2462 | Total Cost to Hire K Workers | Medium | Two min-heaps front/back |
| 1046 | Last Stone Weight | Easy | Max-heap smash |

### All Problems in Pattern 1

- 215 Kth Largest Element in an Array
- 347 Top K Frequent Elements
- 373 Find K Pairs with Smallest Sums
- 451 Sort Characters By Frequency
- 692 Top K Frequent Words
- 767 Reorganize String
- 973 K Closest Points to Origin
- 1046 Last Stone Weight
- 1337 The K Weakest Rows in a Matrix
- 1636 Sort Array by Increasing Frequency
- 1985 Find the Kth Largest Integer in the Array
- 2231 Largest Number After Digit Swaps by Parity
- 2284 Sender With Largest Word Count
- 2402 Meeting Rooms III
- 2462 Total Cost to Hire K Workers
- 2530 Maximal Score After Applying K Operations
- 3264 Final Array State After K Multiplication Operations I

---

## Pattern 2 — K-th Largest / Smallest

### Notes and Theory

**What it is**: Find the exact K-th element in a stream, array, or implicit sequence. Three approaches: (1) min-heap of size K, (2) max-heap pop K times, (3) QuickSelect for O(n) average.

**How to identify**:
- "Kth largest in a stream", "Kth smallest in BST"
- "Find Kth element dynamically as elements are added"
- Keywords: "Kth largest", "Kth smallest", "order statistic"

**Kth Largest in a Stream (703)**:
```cpp
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int x : nums) add(x);
    }
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) minHeap.pop();
        return minHeap.top(); // Kth largest
    }
};
```

**Kth Smallest in Sorted Matrix (378)**:
```cpp
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;
for (int i = 0; i < min(k, n); i++) minHeap.push({matrix[i][0], i, 0});

for (int i = 0; i < k - 1; i++) {
    auto [val, r, c] = minHeap.top(); minHeap.pop();
    if (c + 1 < n) minHeap.push({matrix[r][c+1], r, c+1});
}
return get<0>(minHeap.top());
```

**QuickSelect — O(n) average for Kth largest**:
```cpp
int quickSelect(vector<int>& nums, int lo, int hi, int k) {
    int pivot = nums[hi], p = lo;
    for (int i = lo; i < hi; i++) {
        if (nums[i] >= pivot) swap(nums[i], nums[p++]);
    }
    swap(nums[p], nums[hi]);
    if (p == k) return nums[p];
    return p < k ? quickSelect(nums, p+1, hi, k)
                 : quickSelect(nums, lo, p-1, k);
}
// Call: quickSelect(nums, 0, n-1, k-1) for kth largest
```

**Key insight**: Min-heap of size K gives O(n log K). QuickSelect gives O(n) average. For streaming data (elements added one at a time), only the heap approach works.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 215 | Kth Largest Element in Array | Medium | QuickSelect or heap |
| 703 | Kth Largest Element in Stream | Easy | Live min-heap size K |
| 378 | Kth Smallest in Sorted Matrix | Medium | Heap expand by row |
| 668 | Kth Smallest in Multiplication Table | Hard | BS + heap counting |
| 786 | Kth Smallest Prime Fraction | Medium | Min-heap on fractions |
| 1439 | Kth Smallest Sum of Two Sorted Arrays | Hard | Heap + visited set |
| 719 | Find Kth Smallest Pair Distance | Hard | BS + sliding window |
| 2583 | Kth Largest Sum in a Binary Tree | Medium | BFS + min-heap |

### All Problems in Pattern 2

- 215 Kth Largest Element in an Array
- 378 Kth Smallest Element in a Sorted Matrix
- 668 Kth Smallest Number in Multiplication Table
- 703 Kth Largest Element in a Stream
- 719 Find K-th Smallest Pair Distance
- 786 K-th Smallest Prime Fraction
- 1439 Find the Kth Smallest Sum of a Matrix With Sorted Rows
- 2040 Kth Smallest Product of Two Sorted Arrays
- 2343 Query Kth Smallest Trimmed Number
- 2583 Kth Largest Sum in a Binary Tree

---

## Pattern 3 — Merge K Sorted Lists / Arrays

### Notes and Theory

**What it is**: Merge multiple sorted structures into one sorted output. A min-heap tracks the current smallest element across all K structures. Each time you extract the minimum, you push the next element from that structure.

**How to identify**:
- "Merge K sorted linked lists / arrays"
- "Smallest range covering K lists"
- Keywords: "merge K", "K sorted", "smallest from each"

**Merge K Sorted Lists (23)**:
```cpp
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
    for (auto* node : lists) if (node) minHeap.push(node);

    ListNode dummy(0);
    ListNode* curr = &dummy;

    while (!minHeap.empty()) {
        auto* node = minHeap.top(); minHeap.pop();
        curr->next = node;
        curr = curr->next;
        if (node->next) minHeap.push(node->next);
    }
    return dummy.next;
}
```

**Smallest Range Covering K Lists (632)**:
```cpp
// Heap stores (value, listIndex, elementIndex)
// Track current max across heap elements
// Range = [heap.top().value, currentMax]
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;
int curMax = INT_MIN;

for (int i = 0; i < k; i++) {
    minHeap.push({nums[i][0], i, 0});
    curMax = max(curMax, nums[i][0]);
}

int rangeL = 0, rangeR = INT_MAX;
while (!minHeap.empty()) {
    auto [val, r, c] = minHeap.top(); minHeap.pop();
    if (curMax - val < rangeR - rangeL) { rangeL = val; rangeR = curMax; }
    if (c + 1 == (int)nums[r].size()) break;
    int next = nums[r][c+1];
    minHeap.push({next, r, c+1});
    curMax = max(curMax, next);
}
return {rangeL, rangeR};
```

**K Pairs with Smallest Sums (373)**:
```cpp
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;
for (int i = 0; i < min(k, (int)nums1.size()); i++)
    minHeap.push({nums1[i] + nums2[0], i, 0});

vector<vector<int>> result;
while (result.size() < k && !minHeap.empty()) {
    auto [sum, i, j] = minHeap.top(); minHeap.pop();
    result.push_back({nums1[i], nums2[j]});
    if (j + 1 < (int)nums2.size())
        minHeap.push({nums1[i] + nums2[j+1], i, j+1});
}
return result;
```

**Key insight**: The heap holds exactly one frontier element per source. When you pop the minimum, advance only that source's pointer and push its next element. Total: O(n log K).

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 23 | Merge K Sorted Lists | Hard | Core K-merge pattern |
| 632 | Smallest Range Covering K Lists | Hard | K-merge + range tracking |
| 373 | Find K Pairs with Smallest Sums | Medium | Implicit matrix K-merge |
| 378 | Kth Smallest in Sorted Matrix | Medium | Row-by-row K-merge |
| 786 | Kth Smallest Prime Fraction | Medium | Fraction K-merge |
| 1439 | Kth Smallest Sum of Matrix Rows | Hard | Multi-row K-merge |
| 2402 | Meeting Rooms III | Hard | Sort + merge scheduling |

### All Problems in Pattern 3

- 23 Merge K Sorted Lists
- 373 Find K Pairs with Smallest Sums
- 378 Kth Smallest Element in a Sorted Matrix
- 632 Smallest Range Covering Elements from K Lists
- 786 K-th Smallest Prime Fraction
- 1439 Find the Kth Smallest Sum of a Matrix With Sorted Rows
- 2402 Meeting Rooms III

---

## Pattern 4 — Two Heaps (Median Stream)

### Notes and Theory

**What it is**: Maintain two heaps — a **max-heap for the lower half** and a **min-heap for the upper half**. The median is always at the tops. Balancing ensures the size difference is at most 1.

**How to identify**:
- "Find median from a data stream"
- "Running median as elements are added"
- Keywords: "median", "running median", "balance halves"

**MedianFinder (295)**:
```cpp
class MedianFinder {
    priority_queue<int> maxHeap;                             // lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // upper half

public:
    void addNum(int num) {
        maxHeap.push(num);

        // Balance: max of lower <= min of upper
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        }

        // Balance sizes: maxHeap can have at most 1 more
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top()); minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
```

**Sliding Window Median (480)**:
```cpp
// Same two-heap idea but elements leave the window
// Use lazy deletion (Pattern 9) to remove outgoing elements
// Track "pending deletions" and skip them when they reach the top
```

**Key insight**: max-heap top = largest of lower half. min-heap top = smallest of upper half. Invariant: sizes differ by at most 1, max-heap never has a value greater than min-heap's top.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 295 | Find Median from Data Stream | Hard | Core two-heap pattern |
| 480 | Sliding Window Median | Hard | Two heaps + lazy deletion |
| 1825 | Finding MK Average | Hard | Three heaps for range |
| 2141 | Maximum Running Time of N Computers | Hard | Two-heap balance |

### All Problems in Pattern 4

- 295 Find Median from Data Stream
- 480 Sliding Window Median
- 1825 Finding MK Average
- 2141 Maximum Running Time of N Computers

---

## Pattern 5 — Greedy + Heap (Task Scheduling)

### Notes and Theory

**What it is**: Process tasks greedily — always pick the most urgent or most beneficial next task. A max-heap provides O(log n) access to the best available choice at each step.

**How to identify**:
- "CPU task scheduling with cooldown"
- "Reorganize string so no two adjacent are same"
- Keywords: "cooldown", "most frequent first", "reorganize", "schedule tasks"

**Task Scheduler (621)**:
```cpp
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    for (char t : tasks) freq[t]++;

    priority_queue<int> maxHeap;
    for (auto& [c, f] : freq) maxHeap.push(f);

    queue<pair<int,int>> cooldown; // {remaining_freq, available_time}
    int time = 0;

    while (!maxHeap.empty() || !cooldown.empty()) {
        time++;
        if (!maxHeap.empty()) {
            int f = maxHeap.top() - 1; maxHeap.pop();
            if (f > 0) cooldown.push({f, time + n});
        }
        if (!cooldown.empty() && cooldown.front().second == time) {
            maxHeap.push(cooldown.front().first); cooldown.pop();
        }
    }
    return time;
}
```

**Reorganize String (767)**:
```cpp
string reorganizeString(string s) {
    unordered_map<char,int> freq;
    for (char c : s) freq[c]++;

    priority_queue<pair<int,char>> maxHeap;
    for (auto& [c, f] : freq) maxHeap.push({f, c});

    string result = "";
    while (maxHeap.size() >= 2) {
        auto [f1, c1] = maxHeap.top(); maxHeap.pop();
        auto [f2, c2] = maxHeap.top(); maxHeap.pop();
        result += c1; result += c2;
        if (f1 - 1 > 0) maxHeap.push({f1-1, c1});
        if (f2 - 1 > 0) maxHeap.push({f2-1, c2});
    }
    if (!maxHeap.empty()) {
        if (maxHeap.top().first > 1) return "";
        result += maxHeap.top().second;
    }
    return result;
}
```

**Last Stone Weight (1046)**:
```cpp
priority_queue<int> maxHeap(stones.begin(), stones.end());
while (maxHeap.size() > 1) {
    int a = maxHeap.top(); maxHeap.pop();
    int b = maxHeap.top(); maxHeap.pop();
    if (a != b) maxHeap.push(a - b);
}
return maxHeap.empty() ? 0 : maxHeap.top();
```

**Key insight**: Greedy + heap = always make the locally optimal choice using the best available element. The challenge is defining what "best" means for each problem.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 621 | Task Scheduler | Medium | Cooldown queue + max-heap |
| 767 | Reorganize String | Medium | Interleave most frequent |
| 1046 | Last Stone Weight | Easy | Smash two largest |
| 1405 | Longest Happy String | Medium | Three-way greedy |
| 2462 | Total Cost to Hire K Workers | Medium | Two min-heaps front/back |
| 358 | Rearrange String K Distance Apart | Hard | Cooldown generalized |
| 1642 | Furthest Building You Can Reach | Medium | Min-heap ladders/bricks |
| 2542 | Maximum Subsequence Score | Medium | Sort + min-heap |
| 2558 | Take Gifts From the Richest Pile | Easy | Max-heap sqrt reduce |
| 502 | IPO | Hard | Unlock projects greedy |

### All Problems in Pattern 5

- 358 Rearrange String k Distance Apart
- 502 IPO
- 621 Task Scheduler
- 767 Reorganize String
- 1046 Last Stone Weight
- 1405 Longest Happy String
- 1642 Furthest Building You Can Reach
- 2208 Minimum Operations to Halve Array Sum
- 2335 Minimum Amount of Time to Fill Cups
- 2462 Total Cost to Hire K Workers
- 2530 Maximal Score After Applying K Operations
- 2542 Maximum Subsequence Score
- 2558 Take Gifts From the Richest Pile
- 2593 Find Score of an Array After Marking All Elements
- 3264 Final Array State After K Multiplication Operations I

---

## Pattern 6 — Dijkstra / Shortest Path

### Notes and Theory

**What it is**: Dijkstra's algorithm uses a min-heap to always process the node with the smallest known distance next. Each pop = shortest path found for that node. Push neighbors with updated distances.

**How to identify**:
- "Shortest path in weighted graph", "minimum cost to reach"
- "Network delay time", "path with minimum effort"
- Keywords: "minimum cost", "shortest path", "weighted graph", "minimum effort"

**Dijkstra Template**:
```cpp
vector<int> dijkstra(int src, int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
    // {distance, node}

    dist[src] = 0;
    minHeap.push({0, src});

    while (!minHeap.empty()) {
        auto [d, u] = minHeap.top(); minHeap.pop();

        if (d > dist[u]) continue; // stale entry — skip

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                minHeap.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

**Path With Minimum Effort (1631)**:
```cpp
// dist[i][j] = minimum maximum effort to reach cell (i,j)
// cost = max(currentEffort, abs(height diff))
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;
minHeap.push({0, 0, 0}); // {effort, row, col}

while (!minHeap.empty()) {
    auto [eff, r, c] = minHeap.top(); minHeap.pop();
    if (r == rows-1 && c == cols-1) return eff;
    if (eff > dist[r][c]) continue;
    for (auto [dr, dc] : dirs) {
        int nr = r+dr, nc = c+dc;
        if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
        int newEff = max(eff, abs(heights[nr][nc] - heights[r][c]));
        if (newEff < dist[nr][nc]) {
            dist[nr][nc] = newEff;
            minHeap.push({newEff, nr, nc});
        }
    }
}
return -1;
```

**Key insight**: The stale entry check `if (d > dist[u]) continue` is critical — it skips outdated heap entries without needing explicit deletion. Without it you'd process nodes multiple times.

**Dijkstra vs BFS**: BFS for unweighted graphs (all weights = 1). Dijkstra for non-negative weights. Bellman-Ford for negative weights.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 743 | Network Delay Time | Medium | Classic Dijkstra |
| 1631 | Path With Minimum Effort | Medium | Dijkstra on grid (max cost) |
| 1514 | Path with Maximum Probability | Medium | Dijkstra maximize product |
| 778 | Swim in Rising Water | Hard | Dijkstra on grid |
| 787 | Cheapest Flights Within K Stops | Medium | Modified Dijkstra |
| 1976 | Number of Ways to Arrive on Time | Medium | Count shortest paths |
| 2045 | Second Minimum Time to Reach | Hard | Two-distance Dijkstra |
| 2577 | Minimum Time to Visit a Cell | Hard | Dijkstra with timing |
| 3112 | Minimum Time to Visit Disappearing Nodes | Medium | Dijkstra with expiry |

### All Problems in Pattern 6

- 743 Network Delay Time
- 778 Swim in Rising Water
- 787 Cheapest Flights Within K Stops
- 1368 Minimum Cost to Make at Least One Valid Path in a Grid
- 1514 Path with Maximum Probability
- 1631 Path With Minimum Effort
- 1786 Number of Restricted Paths From First to Last Node
- 1976 Number of Ways to Arrive at Destination
- 2045 Second Minimum Time to Reach Destination
- 2203 Minimum Weighted Subgraph With the Required Paths
- 2290 Minimum Obstacle Removal to Reach Corner
- 2492 Minimum Score of a Path Between Two Cities
- 2577 Minimum Time to Visit a Cell In a Grid
- 2662 Minimum Cost of a Path With Special Roads
- 3112 Minimum Time to Visit Disappearing Nodes
- 3123 Find Edges in Shortest Paths

---

## Pattern 7 — Sliding Window + Heap

### Notes and Theory

**What it is**: Combine a sliding window with a heap to track max/min within the window. Since heaps don't support efficient deletion of arbitrary elements, **lazy deletion** (Pattern 9) is used for the outgoing element.

**How to identify**:
- "Maximum / minimum in every window of size K"
- "Sliding window where answer depends on extreme value"
- Keywords: "window maximum", "window minimum", "sliding max/min"

**Sliding Window Maximum — Heap approach**:
```cpp
priority_queue<pair<int,int>> maxHeap; // {value, index}
vector<int> result;

for (int i = 0; i < (int)nums.size(); i++) {
    maxHeap.push({nums[i], i});

    // Lazy delete: remove elements outside window
    while (maxHeap.top().second <= i - k) maxHeap.pop();

    if (i >= k - 1) result.push_back(maxHeap.top().first);
}
return result;
```

**Note**: For pure sliding window max/min, a **monotonic deque** is O(n) vs heap O(n log n). Use the deque when performance matters; the heap when window constraints are more complex.

**Sliding Window Median (480)** — two heaps + lazy deletion:
```cpp
// Combine Pattern 4 (two heaps) with Pattern 9 (lazy deletion)
// When window slides: mark outgoing element for lazy deletion
// After each slide: re-balance the two heaps
unordered_map<int, int> toDelete;
priority_queue<int> lo;                              // max-heap lower half
priority_queue<int, vector<int>, greater<int>> hi;   // min-heap upper half

auto getMedian = [&](int k) -> double {
    return k % 2 ? lo.top() : ((double)lo.top() + hi.top()) / 2.0;
};
// ... (push first k elements, then slide + lazy delete)
```

**Key insight**: Lazy deletion converts an O(n) arbitrary deletion into O(log n) amortized. Each element is pushed and popped at most once — total O(n log n).

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 239 | Sliding Window Maximum | Hard | Lazy deletion or deque |
| 480 | Sliding Window Median | Hard | Two heaps + lazy deletion |
| 1438 | Longest Subarray Abs Diff ≤ Limit | Medium | Two heaps tracking range |
| 2762 | Continuous Subarrays | Medium | Two heaps variable window |
| 2398 | Maximum Number of Robots | Hard | Deque + heap costs |
| 1499 | Max Value of Equation | Hard | Heap on transformed values |

### All Problems in Pattern 7

- 239 Sliding Window Maximum
- 480 Sliding Window Median
- 1438 Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
- 1499 Max Value of Equation
- 2398 Maximum Number of Robots Within Budget
- 2762 Continuous Subarrays

---

## Pattern 8 — Multi-Level / Custom Comparator

### Notes and Theory

**What it is**: Elements must be ordered by **multiple criteria** simultaneously — first by frequency, then by value; first by deadline, then by profit. The heap comparator encodes the full ordering.

**How to identify**:
- "Sort by frequency, break ties by value"
- "Process jobs by deadline then profit"
- Keywords: "sort by X then Y", "priority", "custom order", "tie-breaking"

**Custom comparator in C++**:
```cpp
auto cmp = [](pair<int,string>& a, pair<int,string>& b) {
    if (a.first != b.first) return a.first < b.first; // higher freq first
    return a.second > b.second;                        // lex smaller first
};
priority_queue<pair<int,string>,
               vector<pair<int,string>>,
               decltype(cmp)> pq(cmp);
```

**Top K Frequent Words (692)**:
```cpp
// Min-heap of size K — evict: lower freq, or same freq but lex larger
auto cmp = [](pair<int,string>& a, pair<int,string>& b) {
    if (a.first != b.first) return a.first > b.first; // evict lower freq first
    return a.second < b.second;                        // evict lex smaller first
};
```

**Ugly Number II (264)**:
```cpp
priority_queue<long long, vector<long long>, greater<long long>> minHeap;
set<long long> seen;
minHeap.push(1); seen.insert(1);
long long ugly = 1;
for (int i = 0; i < n; i++) {
    ugly = minHeap.top(); minHeap.pop();
    for (long long f : {2LL, 3LL, 5LL}) {
        if (!seen.count(ugly * f)) {
            seen.insert(ugly * f);
            minHeap.push(ugly * f);
        }
    }
}
return (int)ugly;
```

**IPO (502)** — unlock projects greedily:
```cpp
priority_queue<int> available;                                      // max-heap profits
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> locked; // min-heap by capital

for (int i = 0; i < n; i++) locked.push({capital[i], profits[i]});

for (int i = 0; i < k; i++) {
    while (!locked.empty() && locked.top().first <= w) {
        available.push(locked.top().second); locked.pop();
    }
    if (available.empty()) break;
    w += available.top(); available.pop();
}
return w;
```

**Key insight**: Encode ALL ordering criteria into the comparator. In C++ `priority_queue`, the comparator returning `true` means the element has LOWER priority (like `operator<` — the "smallest" gets pushed down).

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 692 | Top K Frequent Words | Medium | Freq desc + lex asc |
| 264 | Ugly Number II | Medium | Multi-source min-heap |
| 1834 | Single-Threaded CPU | Medium | Sort arrival + heap priority |
| 2542 | Maximum Subsequence Score | Medium | Sort desc + min-heap |
| 313 | Super Ugly Number | Medium | K-source heap |
| 1882 | Process Tasks Using Servers | Medium | Two heaps: free + busy |
| 2402 | Meeting Rooms III | Hard | Sort + two heaps |
| 630 | Course Schedule III | Hard | Greedy + max-heap swap |

### All Problems in Pattern 8

- 264 Ugly Number II
- 313 Super Ugly Number
- 451 Sort Characters By Frequency
- 502 IPO
- 630 Course Schedule III
- 692 Top K Frequent Words
- 1834 Single-Threaded CPU
- 1882 Process Tasks Using Servers
- 2054 Two Best Non-Overlapping Events
- 2402 Meeting Rooms III
- 2542 Maximum Subsequence Score

---

## Pattern 9 — Heap + Lazy Deletion

### Notes and Theory

**What it is**: Standard heaps don't support O(log n) deletion of arbitrary elements. Lazy deletion marks elements as invalid and skips them when they surface to the top.

**How to identify**:
- Elements need to be removed from the heap but they're not at the top
- Sliding window where old elements exit the window
- Keywords: "remove from heap", "invalidate", "stale entries"

**Lazy deletion template**:
```cpp
unordered_map<int, int> toDelete; // element -> count of pending deletions
priority_queue<int> maxHeap;

// Mark for deletion
void lazyDelete(int val) { toDelete[val]++; }

// Clean stale entries from top
void clean(priority_queue<int>& heap) {
    while (!heap.empty() && toDelete[heap.top()] > 0) {
        toDelete[heap.top()]--;
        heap.pop();
    }
}
```

**Furthest Building You Can Reach (1642)**:
```cpp
// Use ladders for the largest jumps seen so far
// When we run out of ladders, swap the smallest ladder-jump with bricks
priority_queue<int, vector<int>, greater<int>> minHeap; // ladder-allocated jumps
int bricks_left = bricks;

for (int i = 0; i < heights.size() - 1; i++) {
    int diff = heights[i+1] - heights[i];
    if (diff <= 0) continue;
    minHeap.push(diff);
    if ((int)minHeap.size() > ladders) {
        bricks_left -= minHeap.top(); minHeap.pop();
        if (bricks_left < 0) return i;
    }
}
return heights.size() - 1;
```

**Key insight**: Lazy deletion is O(log n) amortized per operation. Each element is pushed at most once and popped at most once (whether legitimately or via lazy deletion) — total O(n log n).

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 480 | Sliding Window Median | Hard | Two heaps + lazy delete |
| 502 | IPO | Hard | Two heaps unlock pattern |
| 1642 | Furthest Building You Can Reach | Medium | Swap bricks for ladders |
| 2402 | Meeting Rooms III | Hard | Free/busy server heaps |
| 1882 | Process Tasks Using Servers | Medium | Available + busy heaps |
| 2163 | Minimum Difference in Sums | Hard | Two heaps prefix/suffix |

### All Problems in Pattern 9

- 480 Sliding Window Median
- 502 IPO
- 1642 Furthest Building You Can Reach
- 1882 Process Tasks Using Servers
- 2163 Minimum Difference in Sums After Removal of Elements
- 2402 Meeting Rooms III

---

## Pattern 10 — Interval Scheduling + Heap

### Notes and Theory

**What it is**: Sort intervals by start time. Use a heap to track active (overlapping) intervals by their **end time**. When a new interval starts, pop all intervals that ended before this start time.

**How to identify**:
- "Minimum number of meeting rooms / platforms"
- "Assign tasks to machines minimally"
- Keywords: "meeting rooms", "overlapping intervals", "assign resources", "minimum platforms"

**Meeting Rooms II (253)**:
```cpp
int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end()); // sort by start
    priority_queue<int, vector<int>, greater<int>> minHeap; // end times

    for (auto& interval : intervals) {
        // Free room if earliest meeting ended before this one starts
        if (!minHeap.empty() && minHeap.top() <= interval[0])
            minHeap.pop();
        minHeap.push(interval[1]);
    }
    return (int)minHeap.size();
}
```

**Why min-heap of end times?** We want to know if the earliest-ending active meeting finishes before the new one starts. If yes, reuse that room. If no, allocate a new room.

**Course Schedule III (630)**:
```cpp
// Sort by deadline. Greedily add each course.
// If total time exceeds current deadline, drop the longest course taken.
sort(courses.begin(), courses.end(),
     [](auto& a, auto& b){ return a[1] < b[1]; });
priority_queue<int> maxHeap; // durations of enrolled courses
int time = 0;

for (auto& course : courses) {
    int dur = course[0], dead = course[1];
    time += dur;
    maxHeap.push(dur);
    if (time > dead) {
        time -= maxHeap.top(); maxHeap.pop(); // drop longest course
    }
}
return (int)maxHeap.size();
```

**Single-Threaded CPU (1834)**:
```cpp
// Sort tasks by enqueue time
// At each CPU-free moment, push all available tasks to min-heap (by duration, then index)
// Process the shortest available task
```

**Key insight**: Sort by start time + min-heap of end times = O(n log n). Heap size at any point = number of currently active intervals = minimum resources needed.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 253 | Meeting Rooms II | Medium | Core interval heap |
| 630 | Course Schedule III | Hard | Greedy swap with max-heap |
| 1235 | Maximum Profit in Job Scheduling | Hard | DP + binary search |
| 2054 | Two Best Non-Overlapping Events | Medium | Sorted events + heap |
| 1834 | Single-Threaded CPU | Medium | Arrival sort + priority |
| 1882 | Process Tasks Using Servers | Medium | Free + busy server heaps |
| 2402 | Meeting Rooms III | Hard | Room reuse + assignment |
| 2406 | Divide Intervals Into Min Groups | Medium | Peak overlap count |

### All Problems in Pattern 10

- 253 Meeting Rooms II
- 630 Course Schedule III
- 1235 Maximum Profit in Job Scheduling
- 1834 Single-Threaded CPU
- 1882 Process Tasks Using Servers
- 2054 Two Best Non-Overlapping Events
- 2402 Meeting Rooms III
- 2406 Divide Intervals Into Minimum Number of Groups

---

## 30-Day Mastery Roadmap

> **Philosophy**: Learn the pattern → internalize the template → apply to 3-5 problems → move on.

### Week 1 — Foundation Patterns (Days 1-7)

| Day | Focus | Problems to Solve |
|---|---|---|
| 1 | Heap basics + STL | 1046, 703, 2558 |
| 2 | Pattern 1: Top K | 347, 973, 692 |
| 3 | Pattern 1: Top K advanced | 215, 1337, 2462 |
| 4 | Pattern 2: Kth element | 215, 703, 378 |
| 5 | Pattern 2: Kth advanced | 786, 373 |
| 6 | Pattern 5: Greedy basics | 1046, 2208, 2530 |
| 7 | Review Week 1 | Re-solve 4 hardest from week |

### Week 2 — Core Patterns (Days 8-14)

| Day | Focus | Problems to Solve |
|---|---|---|
| 8 | Pattern 5: Task scheduling | 621, 767 |
| 9 | Pattern 5: Advanced greedy | 1405, 1642, 2542 |
| 10 | Pattern 3: Merge K sorted | 23, 373 |
| 11 | Pattern 3: Advanced merge | 632, 378, 786 |
| 12 | Pattern 10: Interval basics | 253 |
| 13 | Pattern 10: Advanced intervals | 630, 1834, 2054 |
| 14 | Review Week 2 | Re-solve 4 hardest |

### Week 3 — Advanced Patterns (Days 15-21)

| Day | Focus | Problems to Solve |
|---|---|---|
| 15 | Pattern 4: Two heaps | 295 |
| 16 | Pattern 4: Advanced two heaps | 480, 1825 |
| 17 | Pattern 6: Dijkstra basics | 743, 1514 |
| 18 | Pattern 6: Dijkstra on grid | 1631, 778 |
| 19 | Pattern 6: Advanced Dijkstra | 787, 1976, 2577 |
| 20 | Pattern 8: Custom comparator | 692, 264, 1834 |
| 21 | Pattern 8: Advanced custom | 630, 2402, 313 |

### Week 4 — Hard Problems and Mock Interviews (Days 22-30)

| Day | Focus | Problems to Solve |
|---|---|---|
| 22 | Pattern 9: Lazy deletion | 502, 1642 |
| 23 | Pattern 9 + 7: Window + heap | 239, 480 |
| 24 | Hard Dijkstra | 2045, 2577, 1368 |
| 25 | Hard scheduling | 2402, 1235, 630 |
| 26 | Hard K-th element | 719, 1439, 668 |
| 27 | Mock Interview Day 1 | Random 5 (all patterns) |
| 28 | Mock Interview Day 2 | 3 mediums + 1 hard |
| 29 | Weak pattern reinforcement | Fill gaps from mocks |
| 30 | Final review | Re-solve 10 hardest problems |

---

## Top 30 Must Solve Interview Problems

| Priority | # | Problem | Pattern | Difficulty |
|---|---|---|---|---|
| 🔥🔥🔥 | 23 | Merge K Sorted Lists | P3 | Hard |
| 🔥🔥🔥 | 295 | Find Median from Data Stream | P4 | Hard |
| 🔥🔥🔥 | 347 | Top K Frequent Elements | P1 | Medium |
| 🔥🔥🔥 | 215 | Kth Largest Element in Array | P2 | Medium |
| 🔥🔥🔥 | 621 | Task Scheduler | P5 | Medium |
| 🔥🔥🔥 | 743 | Network Delay Time | P6 | Medium |
| 🔥🔥🔥 | 973 | K Closest Points to Origin | P1 | Medium |
| 🔥🔥🔥 | 253 | Meeting Rooms II | P10 | Medium |
| 🔥🔥🔥 | 703 | Kth Largest in Stream | P2 | Easy |
| 🔥🔥🔥 | 1631 | Path With Minimum Effort | P6 | Medium |
| 🔥🔥 | 767 | Reorganize String | P5 | Medium |
| 🔥🔥 | 502 | IPO | P9 | Hard |
| 🔥🔥 | 480 | Sliding Window Median | P4/P7 | Hard |
| 🔥🔥 | 692 | Top K Frequent Words | P1/P8 | Medium |
| 🔥🔥 | 632 | Smallest Range Covering K Lists | P3 | Hard |
| 🔥🔥 | 378 | Kth Smallest in Sorted Matrix | P2/P3 | Medium |
| 🔥🔥 | 1642 | Furthest Building You Can Reach | P5/P9 | Medium |
| 🔥🔥 | 630 | Course Schedule III | P8/P10 | Hard |
| 🔥🔥 | 1834 | Single-Threaded CPU | P8/P10 | Medium |
| 🔥🔥 | 373 | Find K Pairs with Smallest Sums | P3 | Medium |
| 🔥🔥 | 1046 | Last Stone Weight | P5 | Easy |
| 🔥 | 787 | Cheapest Flights Within K Stops | P6 | Medium |
| 🔥 | 2462 | Total Cost to Hire K Workers | P1/P5 | Medium |
| 🔥 | 264 | Ugly Number II | P8 | Medium |
| 🔥 | 2542 | Maximum Subsequence Score | P5/P8 | Medium |
| 🔥 | 2402 | Meeting Rooms III | P8/P10 | Hard |
| 🔥 | 1882 | Process Tasks Using Servers | P8/P10 | Medium |
| 🔥 | 2054 | Two Best Non-Overlapping Events | P10 | Medium |
| 🔥 | 778 | Swim in Rising Water | P6 | Hard |
| 🔥 | 1405 | Longest Happy String | P5 | Medium |

---

## Hybrid Decision Guide

| Combination | Rule | Example |
|---|---|---|
| P1 vs P2 | P1 if collecting K elements; P2 if finding exact Kth position | 347 vs 703 |
| P2 vs P3 | P2 if single sequence; P3 if merging multiple sorted sources | 215 vs 23 |
| P4 vs P7 | P4 if stream with no window; P7 if fixed sliding window with median | 295 vs 480 |
| P5 vs P10 | P5 if tasks have no time intervals; P10 if tasks have start/end times | 621 vs 253 |
| P6 vs BFS | P6 (Dijkstra) if edges are weighted; BFS if all weights equal 1 | 743 vs 127 |
| P7 vs deque | P7 (heap) if window has complex constraint; deque if just max/min | 480 vs 239 |
| P8 vs P1 | P8 if ordering has multiple keys; P1 if single key only | 692 vs 347 |
| P9 vs P7 | P9 if arbitrary deletions needed; P7 if only window-exit deletion | 502 vs 239 |
| P10 vs P5 | P10 if intervals have fixed start/end; P5 if tasks have cooldowns only | 253 vs 621 |
| P3 vs P6 | P3 if merging sorted data; P6 if finding shortest path in a graph | 23 vs 743 |

---

## Quick Reference — Common Mistakes

| Mistake | Correct Approach |
|---|---|
| Using max-heap for Top K Largest | Use min-heap of size K — min at top gets evicted, keeping K largest |
| Using priority_queue without greater<> for min-heap | Use `priority_queue<int, vector<int>, greater<int>>` for min-heap |
| Forgetting stale entry check in Dijkstra | Always `if (d > dist[u]) continue` after popping from heap |
| Not pushing next element after pop in K-merge | After each pop in merge K, push the next element from that same source |
| Two-heap imbalance after removal | After any deletion or insertion, re-balance so sizes differ by at most 1 |
| Using pair without knowing tie-break order | C++ pairs compare lexicographically — second element breaks ties automatically |
| Lazy deletion: forgetting to clean before reading top | Always clean stale entries before reading top to avoid wrong answers |
| Custom comparator: inverted logic | In priority_queue, comparator returning true = lower priority (gets popped last in max-heap) |
| Dijkstra on graph with negative weights | Dijkstra requires non-negative weights only — use Bellman-Ford for negative edges |
| Heap for sliding window when deque suffices | Monotonic deque is O(n) vs heap O(n log n) — prefer deque for pure max/min window |

---

*Guide compiled from 200+ LeetCode heap/priority queue problems, mapped to 10 universal patterns.*
*Master these patterns and you will solve 95%+ of heap questions in any technical interview.*
