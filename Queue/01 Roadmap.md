# 🔄 Queue Mastery Guide — 95% Interview Coverage

> **Goal**: Solve 95% of all queue interview questions with pattern recognition, not memorization.
> **Method**: 10 patterns → recognition flowchart → templates → curated problem set.

---

## 📌 Table of Contents

1. [Pattern Recognition Flowchart](#pattern-recognition-flowchart)
2. [Pattern 1 — Basic Queue Simulation](#pattern-1--basic-queue-simulation)
3. [Pattern 2 — BFS with Queue](#pattern-2--bfs-with-queue)
4. [Pattern 3 — Circular Queue / Ring Buffer](#pattern-3--circular-queue--ring-buffer)
5. [Pattern 4 — Monotonic Deque (Sliding Window)](#pattern-4--monotonic-deque-sliding-window)
6. [Pattern 5 — Priority Queue / Heap](#pattern-5--priority-queue--heap)
7. [Pattern 6 — Queue Reconstruction / Ordering](#pattern-6--queue-reconstruction--ordering)
8. [Pattern 7 — Double-Ended Queue (Deque)](#pattern-7--double-ended-queue-deque)
9. [Pattern 8 — Queue + BFS on Implicit Graph](#pattern-8--queue--bfs-on-implicit-graph)
10. [Pattern 9 — Multi-Source / Level-by-Level Queue](#pattern-9--multi-source--level-by-level-queue)
11. [Pattern 10 — Design Queue Variants](#pattern-10--design-queue-variants)
12. [30-Day Mastery Roadmap](#30-day-mastery-roadmap)
13. [Hybrid Decision Guide](#hybrid-decision-guide)

---

## Pattern Recognition Flowchart

```
START — Read the problem statement
         |
         v
Does the problem ask to SIMULATE a process in FIFO order?
(Process requests, tasks, print jobs in order)
         |
        YES ──────────────────────────► Pattern 1: Basic Queue Simulation
         |
         v
Does the problem find SHORTEST PATH or explore level by level?
(BFS, minimum steps, nearest target)
         |
        YES ──────────────────────────► Pattern 2: BFS with Queue
         |
         v
Does the problem involve a FIXED-SIZE CIRCULAR buffer?
(Design circular queue, ring buffer, wrap-around indexing)
         |
        YES ──────────────────────────► Pattern 3: Circular Queue
         |
         v
Does the problem need MAX or MIN inside a SLIDING WINDOW in O(1)?
(Max of every K elements, constrained window extremum)
         |
        YES ──────────────────────────► Pattern 4: Monotonic Deque
         |
         v
Does the problem need the HIGHEST PRIORITY element at any time?
(Always process most important, Kth largest, scheduling)
         |
        YES ──────────────────────────► Pattern 5: Priority Queue
         |
         v
Does the problem RECONSTRUCT or REORDER a queue by a rule?
(Queue reconstruction by height, rearrange by priority)
         |
        YES ──────────────────────────► Pattern 6: Queue Reconstruction
         |
         v
Does the problem need BOTH ENDS of the queue (front and back)?
(Sliding window, undo operations, steal from either end)
         |
        YES ──────────────────────────► Pattern 7: Deque (Double-Ended)
         |
         v
Does BFS explore an IMPLICIT or ENCODED state space?
(Word ladder, lock combinations, game states)
         |
        YES ──────────────────────────► Pattern 8: BFS on Implicit Graph
         |
         v
Does BFS start from MULTIPLE SOURCES simultaneously?
(Rotting oranges, distance from all zeros, walls spreading)
         |
        YES ──────────────────────────► Pattern 9: Multi-Source BFS Queue
         |
         v
Does the problem ask to DESIGN a custom queue structure?
(Queue using stacks, front-middle-back queue, task queue)
         |
        YES ──────────────────────────► Pattern 10: Design Queue Variants
         |
         v
        END
```

### 10-Second Interview Shortcut

| Signal in problem | Pattern |
|---|---|
| Process in arrival order, FIFO | P1 — Basic Simulation |
| Shortest path, level-by-level | P2 — BFS Queue |
| Fixed-size wrap-around buffer | P3 — Circular Queue |
| Max/min in sliding window O(1) | P4 — Monotonic Deque |
| Always process highest priority | P5 — Priority Queue |
| Reorder queue by given rule | P6 — Reconstruction |
| Add/remove from both ends | P7 — Deque |
| BFS on states (lock, word, game) | P8 — Implicit BFS |
| Multiple sources expand at once | P9 — Multi-Source BFS |
| Design queue with constraints | P10 — Design Variants |

---

## Pattern 1 — Basic Queue Simulation

### Notes and Theory

**What it is**: The most fundamental use of a queue — FIFO processing. Elements are enqueued when they arrive and dequeued when processed. Order of processing = order of arrival.

**How to identify**:
- "Process requests/tasks in order they arrive"
- "First come first served"
- "Simulate a queue of people/tasks"
- Keywords: "in order", "first in first out", "simulate", "process sequentially"

**Queue basics in C++**:
```cpp
queue<int> q;
q.push(x);          // enqueue — O(1)
q.pop();            // dequeue — O(1)
q.front();          // peek front — O(1)
q.back();           // peek back — O(1)
q.empty();          // check empty
q.size();           // current size
```

**Number of Students Unable to Eat Lunch (1700)**:
```cpp
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q(deque<int>(students.begin(), students.end()));
    int top = 0, attempts = 0;

    while (!q.empty() && attempts < (int)q.size()) {
        if (q.front() == sandwiches[top]) {
            q.pop();
            top++;
            attempts = 0;       // reset — progress made
        } else {
            q.push(q.front());  // cycle to back
            q.pop();
            attempts++;
        }
    }
    return q.size();
}
```

**Time Needed to Buy Tickets (2073)**:
```cpp
int timeRequiredToBuy(vector<int>& tickets, int k) {
    int time = 0;
    queue<int> q;
    for (int i = 0; i < tickets.size(); i++) q.push(i);

    while (!q.empty()) {
        int idx = q.front(); q.pop();
        time++;
        tickets[idx]--;
        if (tickets[idx] > 0) q.push(idx);
        if (idx == k && tickets[idx] == 0) return time;
    }
    return time;
}
```

**Key insight**: Queue simulation is straightforward — the challenge is recognizing WHEN to push back vs discard. Elements pushed to the back simulate "going to the end of the line."

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 933 | Number of Recent Calls | Easy | Sliding time window queue |
| 1700 | Number of Students Unable to Eat | Easy | Cycle simulation |
| 2073 | Time Needed to Buy Tickets | Easy | Position tracking |
| 950 | Reveal Cards in Increasing Order | Medium | Simulate deal process |
| 649 | Dota2 Senate | Medium | Two-queue simulation |
| 346 | Moving Average from Data Stream | Easy | Fixed-size queue |
| 2534 | Time to Cross a Bridge | Hard | Multi-queue simulation |

### All Problems in Pattern 1

- 225 Implement Stack Using Queues
- 232 Implement Queue Using Stacks
- 346 Moving Average from Data Stream
- 649 Dota2 Senate
- 933 Number of Recent Calls
- 950 Reveal Cards in Increasing Order
- 1700 Number of Students Unable to Eat Lunch
- 2073 Time Needed to Buy Tickets
- 2534 Time to Cross a Bridge
- 2Queue 1670 Design Front Middle Back Queue

---

## Pattern 2 — BFS with Queue

### Notes and Theory

**What it is**: BFS uses a queue to explore nodes level by level. The queue ensures nodes are processed in the order they were discovered — guaranteeing shortest paths in unweighted graphs.

**How to identify**:
- "Minimum steps/moves to reach target"
- "Shortest path in unweighted graph or grid"
- "Level-order traversal"
- Keywords: "minimum steps", "shortest", "nearest", "levels"

**Standard BFS Template**:
```cpp
int bfs(int start, int target, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int steps = 0;

    while (!q.empty()) {
        int size = q.size(); // current level size
        for (int i = 0; i < size; i++) {
            int node = q.front(); q.pop();
            if (node == target) return steps;
            for (int nb : adj[node]) {
                if (!visited[nb]) {
                    visited[nb] = true;
                    q.push(nb);
                }
            }
        }
        steps++;
    }
    return -1;
}
```

**BFS on Grid**:
```cpp
int bfsGrid(vector<vector<int>>& grid, int sr, int sc, int er, int ec) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int,int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    int steps = 0;
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [r, c] = q.front(); q.pop();
            if (r == er && c == ec) return steps;
            for (auto& d : dirs) {
                int nr = r+d[0], nc = c+d[1];
                if (nr>=0 && nr<m && nc>=0 && nc<n
                    && !visited[nr][nc] && grid[nr][nc] == 0) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        steps++;
    }
    return -1;
}
```

**Key insight**: Mark nodes as visited WHEN PUSHING into the queue, not when popping. This prevents the same node from being added multiple times, keeping BFS O(V + E).

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 102 | Binary Tree Level Order Traversal | Medium | Classic level BFS |
| 542 | 01 Matrix | Medium | BFS distance from zeros |
| 994 | Rotting Oranges | Medium | Multi-source BFS |
| 1091 | Shortest Path in Binary Matrix | Medium | BFS on grid |
| 1926 | Nearest Exit from Entrance | Medium | BFS nearest target |
| 909 | Snakes and Ladders | Medium | BFS on board game |
| 127 | Word Ladder | Hard | BFS implicit graph |
| 433 | Minimum Genetic Mutation | Medium | BFS on strings |

### All Problems in Pattern 2

- 102 Binary Tree Level Order Traversal
- 103 Binary Tree Zigzag Level Order
- 127 Word Ladder
- 199 Binary Tree Right Side View
- 433 Minimum Genetic Mutation
- 513 Find Bottom Left Tree Value
- 515 Find Largest Value in Each Row
- 542 01 Matrix
- 752 Open the Lock
- 909 Snakes and Ladders
- 994 Rotting Oranges
- 1091 Shortest Path in Binary Matrix
- 1129 Shortest Path with Alternating Colors
- 1926 Nearest Exit from Entrance in Maze
- 2039 The Time When the Network Becomes Idle
- 2146 K Highest Ranked Items Within a Price Range

---

## Pattern 3 — Circular Queue / Ring Buffer

### Notes and Theory

**What it is**: A queue implemented using a fixed-size array where the tail wraps around to the front. Uses modular arithmetic `(index + 1) % capacity` to simulate infinite wrapping in a bounded array.

**How to identify**:
- "Design a circular queue"
- "Fixed buffer with wrap-around"
- "Ring buffer", "bounded FIFO"
- Keywords: "circular", "fixed size", "wrap around", "ring"

**Design Circular Queue (622)**:
```cpp
class MyCircularQueue {
    vector<int> data;
    int head, tail, size, capacity;
public:
    MyCircularQueue(int k) : data(k), head(0), tail(0), size(0), capacity(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        data[tail] = value;
        tail = (tail + 1) % capacity; // wrap around
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity; // wrap around
        size--;
        return true;
    }

    int Front() { return isEmpty() ? -1 : data[head]; }
    int Rear()  { return isEmpty() ? -1 : data[(tail-1+capacity) % capacity]; }
    bool isEmpty() { return size == 0; }
    bool isFull()  { return size == capacity; }
};
```

**Design Circular Deque (641)**:
```cpp
// Same idea but support addFront, addRear, deleteFront, deleteRear
// head moves backward on addFront: head = (head - 1 + capacity) % capacity
// tail moves forward on addRear: tail = (tail + 1) % capacity
```

**Moving Average (346)**:
```cpp
class MovingAverage {
    queue<int> window;
    int size;
    double sum = 0;
public:
    MovingAverage(int size) : size(size) {}
    double next(int val) {
        if (window.size() == size) { sum -= window.front(); window.pop(); }
        window.push(val);
        sum += val;
        return sum / window.size();
    }
};
```

**Key insight**: The two key operations are `(index + 1) % capacity` (advance forward) and `(index - 1 + capacity) % capacity` (advance backward). Always add `capacity` before `% capacity` when going backward to avoid negative modulo.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 622 | Design Circular Queue | Medium | Core circular buffer |
| 641 | Design Circular Deque | Medium | Bidirectional circular |
| 346 | Moving Average from Data Stream | Easy | Sliding window queue |
| 1670 | Design Front Middle Back Queue | Medium | Three-part deque |
| 2073 | Time Needed to Buy Tickets | Easy | Index-based simulation |

### All Problems in Pattern 3

- 346 Moving Average from Data Stream
- 622 Design Circular Queue
- 641 Design Circular Deque
- 1670 Design Front Middle Back Queue

---

## Pattern 4 — Monotonic Deque (Sliding Window)

### Notes and Theory

**What it is**: A deque that maintains elements in **monotonically increasing or decreasing** order. Enables O(1) access to the maximum or minimum of a sliding window. Elements are removed from the back when they're dominated, and from the front when they leave the window.

**How to identify**:
- "Maximum / minimum of every window of size K"
- "Sliding window where you need the extremum"
- Keywords: "sliding window max", "window minimum", "constrained window"

**Sliding Window Maximum (239)**:
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores INDICES, front = index of max
    vector<int> result;

    for (int i = 0; i < (int)nums.size(); i++) {
        // Remove front if outside window
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();

        // Remove back if smaller than current (can never be max)
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}
```

**Sliding Window Minimum** — reverse the comparison:
```cpp
// Maintain increasing deque (front = min)
while (!dq.empty() && nums[dq.back()] >= nums[i]) dq.pop_back();
```

**Jump Game VI (1696)** — DP with deque:
```cpp
// dp[i] = max score to reach index i
// dp[i] = nums[i] + max(dp[i-k..i-1])
// Use monotonic deque to get max in window [i-k, i-1] in O(1)
deque<int> dq; // stores indices, front = max dp index
vector<int> dp(n);
dp[0] = nums[0];
dq.push_back(0);

for (int i = 1; i < n; i++) {
    while (!dq.empty() && dq.front() < i - k) dq.pop_front();
    dp[i] = nums[i] + dp[dq.front()];
    while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
    dq.push_back(i);
}
```

**Key insight**: Store INDICES not values — you need indices to check if the front is outside the window (`dq.front() <= i - k`). The deque always has the max (or min) at the front, accessible in O(1).

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 239 | Sliding Window Maximum | Hard | Core monotonic deque |
| 1696 | Jump Game VI | Medium | Deque DP |
| 1499 | Max Value of Equation | Hard | Deque on transformed values |
| 862 | Shortest Subarray with Sum >= K | Hard | Deque on prefix sums |
| 1438 | Longest Subarray Abs Diff <= Limit | Medium | Two deques |
| 2762 | Continuous Subarrays | Medium | Two deques |
| 2944 | Minimum Number of Coins for Fruits | Medium | Deque DP |

### All Problems in Pattern 4

- 239 Sliding Window Maximum
- 862 Shortest Subarray with Sum at Least K
- 1438 Longest Continuous Subarray With Absolute Diff Less Than Limit
- 1499 Max Value of Equation
- 1696 Jump Game VI
- 2071 Maximum Number of Tasks You Can Assign
- 2398 Maximum Number of Robots Within Budget
- 2762 Continuous Subarrays
- 2944 Minimum Number of Coins for Fruits

---

## Pattern 5 — Priority Queue / Heap

### Notes and Theory

**What it is**: A queue where each element has a priority. The element with the highest (or lowest) priority is always dequeued first, regardless of insertion order.

**How to identify**:
- "Always process the most/least important element"
- "K largest elements", "task scheduling"
- Keywords: "priority", "most urgent", "minimum cost next"

**Min-heap and Max-heap in C++**:
```cpp
// Max-heap (default)
priority_queue<int> maxPQ;
maxPQ.push(5);
maxPQ.top(); // largest element

// Min-heap
priority_queue<int, vector<int>, greater<int>> minPQ;
minPQ.push(5);
minPQ.top(); // smallest element

// Custom comparator
auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
    return a.second > b.second; // min by second element
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```

**Task Scheduler (621)**:
```cpp
// Always schedule the most frequent remaining task
// Use max-heap of frequencies + cooldown queue
priority_queue<int> maxHeap;
queue<pair<int,int>> cooldown; // {freq, available_at_time}
```

**Kth Largest Element (215)**:
```cpp
// Min-heap of size K — top = Kth largest
priority_queue<int, vector<int>, greater<int>> minHeap;
for (int x : nums) {
    minHeap.push(x);
    if ((int)minHeap.size() > k) minHeap.pop();
}
return minHeap.top();
```

**Key insight**: Priority queue is a heap under the hood — O(log n) push/pop, O(1) top. Use min-heap for "top K largest" (evict smallest), use max-heap for "top K smallest" (evict largest).

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 215 | Kth Largest Element in Array | Medium | Min-heap size K |
| 347 | Top K Frequent Elements | Medium | Freq + min-heap |
| 621 | Task Scheduler | Medium | Max-heap + cooldown |
| 1046 | Last Stone Weight | Easy | Max-heap simulation |
| 295 | Find Median from Data Stream | Hard | Two heaps |
| 973 | K Closest Points to Origin | Medium | Max-heap on distance |
| 2542 | Maximum Subsequence Score | Medium | Sort + min-heap |
| 1642 | Furthest Building You Can Reach | Medium | Min-heap ladders |

### All Problems in Pattern 5

- 215 Kth Largest Element in an Array
- 295 Find Median from Data Stream
- 347 Top K Frequent Elements
- 621 Task Scheduler
- 692 Top K Frequent Words
- 767 Reorganize String
- 973 K Closest Points to Origin
- 1046 Last Stone Weight
- 1642 Furthest Building You Can Reach
- 2462 Total Cost to Hire K Workers
- 2530 Maximal Score After Applying K Operations
- 2542 Maximum Subsequence Score

---

## Pattern 6 — Queue Reconstruction / Ordering

### Notes and Theory

**What it is**: Reconstruct or build a queue based on a given rule or property. Typically involves sorting by one criterion then inserting by another.

**How to identify**:
- "Reconstruct a queue where each person has height and position info"
- "Reorder elements based on their rank/position"
- Keywords: "reconstruct", "rearrange by position", "insert at index k"

**Queue Reconstruction by Height (406)**:
```cpp
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    // Sort: tallest first; among same height, fewer-in-front first
    sort(people.begin(), people.end(), [](auto& a, auto& b) {
        return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
    });

    // Insert each person at their k-index position
    // Taller people already placed don't affect shorter people's counts
    list<vector<int>> result;
    for (auto& p : people) {
        auto it = result.begin();
        advance(it, p[1]); // move to position p[1]
        result.insert(it, p);
    }
    return vector<vector<int>>(result.begin(), result.end());
}
```

**Reveal Cards in Increasing Order (950)**:
```cpp
// Simulate the reveal process in reverse to find original deck order
vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    sort(deck.begin(), deck.end());
    queue<int> idx;
    for (int i = 0; i < n; i++) idx.push(i);

    vector<int> result(n);
    for (int card : deck) {
        result[idx.front()] = card; idx.pop();
        if (!idx.empty()) { idx.push(idx.front()); idx.pop(); } // cycle
    }
    return result;
}
```

**Key insight**: For reconstruction problems, the key is finding the RIGHT ordering to sort by before inserting. Greedy + insertion = reconstruct. Simulate the process with a queue to find the pattern.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 406 | Queue Reconstruction by Height | Medium | Sort tall first, insert at k |
| 950 | Reveal Cards in Increasing Order | Medium | Queue simulation reverse |
| 649 | Dota2 Senate | Medium | Greedy two-queue |
| 2073 | Time Needed to Buy Tickets | Easy | Position-based simulation |

### All Problems in Pattern 6

- 406 Queue Reconstruction by Height
- 649 Dota2 Senate
- 950 Reveal Cards in Increasing Order
- 2073 Time Needed to Buy Tickets

---

## Pattern 7 — Double-Ended Queue (Deque)

### Notes and Theory

**What it is**: A deque supports O(1) insertion and deletion at BOTH the front and back. More flexible than a queue or stack — can simulate both.

**How to identify**:
- "Add or remove from either end"
- "Undo last action AND process from front"
- "Sliding window requiring both ends"
- Keywords: "both ends", "front and back", "deque"

**Deque in C++**:
```cpp
deque<int> dq;
dq.push_front(x);   // add to front — O(1)
dq.push_back(x);    // add to back — O(1)
dq.pop_front();     // remove from front — O(1)
dq.pop_back();      // remove from back — O(1)
dq.front();         // peek front
dq.back();          // peek back
```

**Design Front Middle Back Queue (1670)**:
```cpp
class FrontMiddleBackQueue {
    deque<int> left, right; // right has >= left size

    void balance() {
        if (right.size() > left.size() + 1) {
            left.push_back(right.front()); right.pop_front();
        }
        if (left.size() > right.size()) {
            right.push_front(left.back()); left.pop_back();
        }
    }
public:
    void pushFront(int val) { left.push_front(val); balance(); }
    void pushMiddle(int val) {
        if (left.size() == right.size()) right.push_front(val);
        else { right.push_front(left.back()); left.pop_back(); left.push_back(val); }
    }
    void pushBack(int val) { right.push_back(val); balance(); }
    int popFront() {
        if (right.empty()) return -1;
        int val = left.empty() ? right.front() : left.front();
        if (left.empty()) right.pop_front(); else left.pop_front();
        balance(); return val;
    }
    int popMiddle() {
        if (right.empty()) return -1;
        int val = (left.size() == right.size()) ? left.back() : right.front();
        if (left.size() == right.size()) left.pop_back(); else right.pop_front();
        return val;
    }
    int popBack() {
        if (right.empty()) return -1;
        int val = right.back(); right.pop_back();
        balance(); return val;
    }
};
```

**Sliding Window with Deque** — see Pattern 4 (monotonic deque).

**Key insight**: Deque = stack + queue combined. When you need LIFO from one end and FIFO from another simultaneously — deque is the tool. Two-deque balance trick is used for median/middle queries.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 239 | Sliding Window Maximum | Hard | Monotonic deque |
| 1670 | Design Front Middle Back Queue | Medium | Two-deque balance |
| 641 | Design Circular Deque | Medium | Circular deque ops |
| 862 | Shortest Subarray with Sum >= K | Hard | Deque on prefix sums |
| 1696 | Jump Game VI | Medium | Deque DP window |

### All Problems in Pattern 7

- 239 Sliding Window Maximum
- 641 Design Circular Deque
- 862 Shortest Subarray with Sum at Least K
- 1438 Longest Continuous Subarray With Absolute Diff Less Than Limit
- 1670 Design Front Middle Back Queue
- 1696 Jump Game VI

---

## Pattern 8 — BFS on Implicit Graph

### Notes and Theory

**What it is**: BFS where nodes are not given explicitly — they are STATES encoded as strings, numbers, or tuples. The graph is "implicit": edges are generated on-the-fly by applying valid transitions.

**How to identify**:
- "Minimum number of operations to transform X to Y"
- "Lock combinations", "word transformations"
- State can be encoded as a string or integer
- Keywords: "minimum moves", "transformation", "states", "combinations"

**Open the Lock (752)**:
```cpp
int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000")) return -1;

    queue<string> q;
    unordered_set<string> visited;
    q.push("0000"); visited.insert("0000");
    int steps = 0;

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            string curr = q.front(); q.pop();
            if (curr == target) return steps;
            // Generate all neighbors (8 transitions: each wheel +1 or -1)
            for (int j = 0; j < 4; j++) {
                for (int d : {1, -1}) {
                    string next = curr;
                    next[j] = ((next[j] - '0' + d + 10) % 10) + '0';
                    if (!dead.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        steps++;
    }
    return -1;
}
```

**Word Ladder (127)**:
```cpp
// Each state = a word
// Transition = change one letter to any valid word
// Use unordered_set for O(1) lookup
// BFS from beginWord to endWord
```

**Key insight**: The visited set is CRITICAL — without it, you'd revisit states infinitely. Use `unordered_set<string>` or `unordered_set<int>` (for encoded states). Bidirectional BFS can speed this up from O(b^d) to O(b^(d/2)).

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 127 | Word Ladder | Hard | BFS on word states |
| 752 | Open the Lock | Medium | BFS on digit states |
| 433 | Minimum Genetic Mutation | Medium | BFS on gene strings |
| 1345 | Jump Game IV | Hard | BFS on index states |
| 909 | Snakes and Ladders | Medium | BFS on board states |
| 2059 | Minimum Operations to Convert | Medium | BFS digit transform |

### All Problems in Pattern 8

- 127 Word Ladder
- 126 Word Ladder II
- 433 Minimum Genetic Mutation
- 752 Open the Lock
- 909 Snakes and Ladders
- 1345 Jump Game IV
- 1293 Shortest Path in Grid With Obstacles Elimination
- 2059 Minimum Operations to Convert Number

---

## Pattern 9 — Multi-Source / Level-by-Level Queue

### Notes and Theory

**What it is**: Initialize BFS with MULTIPLE starting nodes at distance 0. The BFS naturally computes the distance from the nearest source to every reachable node. Used when "spread" happens from multiple origins simultaneously.

**How to identify**:
- "Distance to nearest X from any cell"
- "Spread/infection/rot from multiple starting points"
- Keywords: "simultaneously", "nearest source", "all sources expand", "spread"

**Multi-Source BFS Template**:
```cpp
vector<vector<int>> dist(m, vector<int>(n, -1));
queue<pair<int,int>> q;

// Push ALL sources at level 0
for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
        if (isSource(grid[i][j])) {
            dist[i][j] = 0;
            q.push({i, j});
        }

int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
while (!q.empty()) {
    auto [r, c] = q.front(); q.pop();
    for (auto& d : dirs) {
        int nr = r+d[0], nc = c+d[1];
        if (nr>=0 && nr<m && nc>=0 && nc<n
            && dist[nr][nc] == -1 && canVisit(grid[nr][nc])) {
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
}
```

**Tree Level-Order with Level Tracking**:
```cpp
// Process exactly one level at a time using level size snapshot
while (!q.empty()) {
    int levelSize = q.size(); // snapshot — number of nodes at this level
    for (int i = 0; i < levelSize; i++) {
        auto node = q.front(); q.pop();
        // process node at current level
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    // all nodes at this level done
}
```

**Key insight**: Multi-source BFS = single-source BFS with all sources pre-loaded. The level snapshot trick (`int sz = q.size()`) lets you process exactly one level per outer loop iteration.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 994 | Rotting Oranges | Medium | Core multi-source BFS |
| 542 | 01 Matrix | Medium | Distance from all zeros |
| 417 | Pacific Atlantic Water Flow | Medium | Two multi-source BFS |
| 1162 | As Far from Land as Possible | Medium | Max dist from all land |
| 1765 | Map of Highest Peak | Medium | Height from all water |
| 2812 | Find the Safest Path in a Grid | Medium | BFS + binary search |
| 286 | Walls and Gates | Medium | Multi-source from gates |
| 1293 | Shortest Path Eliminate Obstacles | Hard | BFS with state |

### All Problems in Pattern 9

- 286 Walls and Gates
- 417 Pacific Atlantic Water Flow
- 542 01 Matrix
- 994 Rotting Oranges
- 1162 As Far from Land as Possible
- 1765 Map of Highest Peak
- 2258 Escape the Spreading Fire
- 2812 Find the Safest Path in a Grid

---

## Pattern 10 — Design Queue Variants

### Notes and Theory

**What it is**: Design custom queue-based data structures with non-standard operations. Usually requires combining queue with stack, heap, or linked list.

**How to identify**:
- "Implement queue using stacks"
- "Design a queue with additional operations"
- "Front, middle, back access"
- Keywords: "design", "implement", "support operations"

**Queue Using Two Stacks (232)**:
```cpp
class MyQueue {
    stack<int> inbox, outbox; // inbox: new elements; outbox: elements to pop

    void transfer() {
        if (outbox.empty()) // only transfer when outbox is empty
            while (!inbox.empty()) {
                outbox.push(inbox.top()); inbox.pop();
            }
    }
public:
    void push(int x) { inbox.push(x); }
    int pop()  { transfer(); int v = outbox.top(); outbox.pop(); return v; }
    int peek() { transfer(); return outbox.top(); }
    bool empty() { return inbox.empty() && outbox.empty(); }
};
```

**Stack Using Two Queues (225)**:
```cpp
class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        // Rotate: move all elements before x to after x
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front()); q.pop();
        }
    }
    int pop()  { int v = q.front(); q.pop(); return v; }
    int top()  { return q.front(); }
    bool empty() { return q.empty(); }
};
```

**Hit Counter (362)**:
```cpp
class HitCounter {
    queue<int> hits;
public:
    void hit(int timestamp) { hits.push(timestamp); }
    int getHits(int timestamp) {
        while (!hits.empty() && timestamp - hits.front() >= 300)
            hits.pop(); // remove hits older than 300 seconds
        return hits.size();
    }
};
```

**Key insight**: Queue + stack interconversion is a classic design pattern. The lazy transfer trick in queue-from-stacks achieves amortized O(1) per operation — each element is transferred at most once.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 232 | Implement Queue Using Stacks | Easy | Lazy transfer two stacks |
| 225 | Implement Stack Using Queues | Easy | Rotate on push |
| 622 | Design Circular Queue | Medium | Array-based circular |
| 641 | Design Circular Deque | Medium | Bidirectional circular |
| 1670 | Design Front Middle Back Queue | Medium | Two-deque balance |
| 933 | Number of Recent Calls | Easy | Sliding window queue |
| 362 | Design Hit Counter | Medium | Time-window queue |

### All Problems in Pattern 10

- 225 Implement Stack Using Queues
- 232 Implement Queue Using Stacks
- 346 Moving Average from Data Stream
- 362 Design Hit Counter
- 622 Design Circular Queue
- 641 Design Circular Deque
- 1670 Design Front Middle Back Queue

---

## 30-Day Mastery Roadmap

### Week 1 — Foundation (Days 1-7)

| Day | Focus | Problems to Solve |
|---|---|---|
| 1 | Queue basics + simulation | 933, 1700, 2073 |
| 2 | Pattern 1: Advanced simulation | 649, 950, 346 |
| 3 | Pattern 10: Design variants | 232, 225, 622 |
| 4 | Pattern 3: Circular queue | 622, 641, 1670 |
| 5 | Pattern 2: BFS basics | 102, 542, 1091 |
| 6 | Pattern 2: BFS advanced | 127, 994, 1926 |
| 7 | Review Week 1 | Re-solve 4 hardest |

### Week 2 — Sliding Window + Priority (Days 8-14)

| Day | Focus | Problems to Solve |
|---|---|---|
| 8 | Pattern 4: Monotonic deque | 239 |
| 9 | Pattern 4: Deque DP | 1696, 1499, 862 |
| 10 | Pattern 5: Priority queue | 215, 347, 1046 |
| 11 | Pattern 5: Advanced PQ | 621, 295, 973 |
| 12 | Pattern 7: Deque design | 641, 1670 |
| 13 | Pattern 6: Reconstruction | 406, 950, 649 |
| 14 | Review Week 2 | Re-solve 4 hardest |

### Week 3 — BFS Variants (Days 15-21)

| Day | Focus | Problems to Solve |
|---|---|---|
| 15 | Pattern 9: Multi-source BFS | 994, 542 |
| 16 | Pattern 9: Advanced multi-BFS | 417, 1162, 1765 |
| 17 | Pattern 8: Implicit graph BFS | 752, 433 |
| 18 | Pattern 8: Advanced implicit | 127, 909, 1345 |
| 19 | Mixed BFS patterns | 1293, 2039 |
| 20 | Hard deque problems | 239, 862, 2398 |
| 21 | Review Week 3 | Re-solve hardest |

### Week 4 — Hard + Mock (Days 22-30)

| Day | Focus | Problems to Solve |
|---|---|---|
| 22 | Hard BFS | 127, 1345, 2258 |
| 23 | Hard deque/window | 239, 1438, 2762 |
| 24 | Hard priority queue | 295, 480, 621 |
| 25 | Hard design | 1670, 2534 |
| 26 | Cross-pattern review | Mix all patterns |
| 27 | Mock Interview Day 1 | Random 5 |
| 28 | Mock Interview Day 2 | 3 mediums + 1 hard |
| 29 | Weak pattern fill | Fill gaps |
| 30 | Final review | Re-solve 10 hardest |

---

## Top 30 Must Solve Interview Problems

| Priority | # | Problem | Pattern | Difficulty |
|---|---|---|---|---|
| 🔥🔥🔥 | 239 | Sliding Window Maximum | P4 | Hard |
| 🔥🔥🔥 | 232 | Implement Queue Using Stacks | P10 | Easy |
| 🔥🔥🔥 | 127 | Word Ladder | P8 | Hard |
| 🔥🔥🔥 | 994 | Rotting Oranges | P9 | Medium |
| 🔥🔥🔥 | 542 | 01 Matrix | P9 | Medium |
| 🔥🔥🔥 | 102 | Binary Tree Level Order | P2 | Medium |
| 🔥🔥🔥 | 295 | Find Median from Data Stream | P5 | Hard |
| 🔥🔥🔥 | 622 | Design Circular Queue | P3 | Medium |
| 🔥🔥🔥 | 347 | Top K Frequent Elements | P5 | Medium |
| 🔥🔥🔥 | 406 | Queue Reconstruction by Height | P6 | Medium |
| 🔥🔥 | 862 | Shortest Subarray Sum >= K | P4 | Hard |
| 🔥🔥 | 752 | Open the Lock | P8 | Medium |
| 🔥🔥 | 621 | Task Scheduler | P5 | Medium |
| 🔥🔥 | 417 | Pacific Atlantic Water Flow | P9 | Medium |
| 🔥🔥 | 1670 | Front Middle Back Queue | P7/P10 | Medium |
| 🔥🔥 | 1696 | Jump Game VI | P4 | Medium |
| 🔥🔥 | 649 | Dota2 Senate | P1/P6 | Medium |
| 🔥🔥 | 950 | Reveal Cards in Increasing Order | P6 | Medium |
| 🔥🔥 | 1091 | Shortest Path in Binary Matrix | P2 | Medium |
| 🔥🔥 | 933 | Number of Recent Calls | P1 | Easy |
| 🔥 | 225 | Implement Stack Using Queues | P10 | Easy |
| 🔥 | 909 | Snakes and Ladders | P8 | Medium |
| 🔥 | 1499 | Max Value of Equation | P4 | Hard |
| 🔥 | 1162 | As Far from Land as Possible | P9 | Medium |
| 🔥 | 641 | Design Circular Deque | P3/P7 | Medium |
| 🔥 | 1700 | Students Unable to Eat Lunch | P1 | Easy |
| 🔥 | 346 | Moving Average from Data Stream | P3 | Easy |
| 🔥 | 2762 | Continuous Subarrays | P4 | Medium |
| 🔥 | 1926 | Nearest Exit from Entrance | P2 | Medium |
| 🔥 | 1438 | Longest Subarray Abs Diff Limit | P4 | Medium |

---

## Hybrid Decision Guide

| Combination | Rule | Example |
|---|---|---|
| P1 vs P2 | P1 if FIFO simulation only; P2 if finding shortest path | 1700 vs 1091 |
| P2 vs P8 | P2 if graph is explicit; P8 if graph is implicit (generated states) | 542 vs 752 |
| P2 vs P9 | P2 if single source BFS; P9 if multiple sources start simultaneously | 1091 vs 994 |
| P4 vs P5 | P4 if need window extremum in O(1); P5 if need global extremum across all elements | 239 vs 215 |
| P4 vs sliding window | P4 if need max/min; standard sliding window if need sum/count | 239 vs 3 |
| P7 vs P4 | P7 if both-end operations needed; P4 if only monotone window ops needed | 1670 vs 239 |
| P3 vs P10 | P3 if fixed-size circular buffer needed; P10 if arbitrary design constraints | 622 vs 232 |
| P5 vs P1 | P5 if priority matters (process most important first); P1 if strict FIFO order | 621 vs 1700 |
| P6 vs P1 | P6 if reconstruction requires sorting rule before inserting; P1 if pure sequential | 406 vs 649 |
| P9 vs P6 (multi-source BFS vs graph) | P9 for grid/2D; P2 for general graph with multi-source | 994 vs 743 |

---

## Quick Reference — Common Mistakes

| Mistake | Correct Approach |
|---|---|
| Marking visited when POPPING from BFS queue | Mark visited when PUSHING — prevents duplicate entries |
| Using stack instead of queue for BFS | Queue (FIFO) for BFS; Stack (LIFO) for DFS — never swap |
| Circular queue: negative modulo for rear | Use `(tail - 1 + capacity) % capacity` — always add capacity before mod |
| Monotonic deque: storing values instead of indices | Store INDICES — you need them to check if front is outside window |
| Priority queue: using default max-heap when min needed | `priority_queue<int, vector<int>, greater<int>>` for min-heap |
| Queue from stacks: transferring on every push | Only transfer when outbox is EMPTY — lazy transfer gives amortized O(1) |
| Multi-source BFS: initializing sources at distance 1 | All sources start at distance 0 — push before the BFS loop begins |
| Level-order BFS: not capturing level size | Snapshot `int sz = q.size()` before the inner loop to process one level |
| Implicit BFS: not using visited set | Without visited set, infinite loops or exponential revisiting occurs |
| Deque front check: not removing out-of-window elements | Always check `dq.front() <= i - k` and pop front before adding new element |

---

*Guide compiled from 150+ LeetCode queue problems, mapped to 10 universal patterns.*
*Master these patterns and you will solve 95%+ of queue questions in any technical interview.*
