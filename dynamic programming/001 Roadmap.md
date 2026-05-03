# 🧠 Dynamic Programming Mastery Guide — 95% Interview Coverage

> **Goal**: Solve 95% of all DP interview questions with pattern recognition, not memorization.
> **Method**: 15 patterns → recognition flowchart → templates → curated problem set.
> **Reference**: Linear DP · 2D DP · DP on Grid · Knapsack · LIS · LCS · DP on String · Cumulative Sum · Matrix Chain · Kadane · Bitmask DP · Digit DP · DP on Trees · DP with Math · DP with Probability

---

## 📌 Table of Contents

1. [Pattern Recognition Flowchart](#pattern-recognition-flowchart)
2. [Pattern 1 — Linear DP](#pattern-1--linear-dp)
3. [Pattern 2 — 2 Dimensional DP](#pattern-2--2-dimensional-dp)
4. [Pattern 3 — DP on Grid](#pattern-3--dp-on-grid)
5. [Pattern 4 — Knapsack DP](#pattern-4--knapsack-dp)
6. [Pattern 5 — Longest Increasing Subsequence (LIS)](#pattern-5--longest-increasing-subsequence-lis)
7. [Pattern 6 — Longest Common Subsequence (LCS)](#pattern-6--longest-common-subsequence-lcs)
8. [Pattern 7 — DP on Strings](#pattern-7--dp-on-strings)
9. [Pattern 8 — Cumulative Sum DP](#pattern-8--cumulative-sum-dp)
10. [Pattern 9 — Matrix Chain Multiplication](#pattern-9--matrix-chain-multiplication)
11. [Pattern 10 — Kadane's Algorithm](#pattern-10--kadanes-algorithm)
12. [Pattern 11 — DP with Bitmask](#pattern-11--dp-with-bitmask)
13. [Pattern 12 — Digit DP](#pattern-12--digit-dp)
14. [Pattern 13 — DP on Trees](#pattern-13--dp-on-trees)
15. [Pattern 14 — DP with Math](#pattern-14--dp-with-math)
16. [Pattern 15 — DP with Probability](#pattern-15--dp-with-probability)
17. [30-Day Mastery Roadmap](#30-day-mastery-roadmap)
18. [Hybrid Decision Guide](#hybrid-decision-guide)

---

## Pattern Recognition Flowchart

```
START — Read the problem statement
         |
         v
Is the input a 1D array/sequence and dp[i] depends only on previous elements?
         |
        YES ──────────────────────────────────────────► Pattern 1: Linear DP
         |
         v
Does dp[i][j] depend on two indices or two sequences?
(Two strings, two arrays, row+col state)
         |
        YES ──────────────────────────────────────────► Pattern 2: 2D DP
         |
         v
Is the input a 2D GRID and you move cell to cell?
(Min path sum, unique paths, robot movement)
         |
        YES ──────────────────────────────────────────► Pattern 3: DP on Grid
         |
         v
Is the problem about SELECTING ITEMS with a WEIGHT/CAPACITY constraint?
(0/1 knapsack, unbounded knapsack, subset sum, coin change)
         |
        YES ──────────────────────────────────────────► Pattern 4: Knapsack DP
         |
         v
Does the problem find the LONGEST INCREASING subsequence or similar?
(LIS, number of LIS, Russian dolls, patience sorting)
         |
        YES ──────────────────────────────────────────► Pattern 5: LIS
         |
         v
Does the problem compare TWO SEQUENCES for common patterns?
(LCS, edit distance, shortest common supersequence)
         |
        YES ──────────────────────────────────────────► Pattern 6: LCS
         |
         v
Is the input a SINGLE STRING and dp depends on substrings?
(Palindrome partition, word break, regex matching)
         |
        YES ──────────────────────────────────────────► Pattern 7: DP on Strings
         |
         v
Does the problem use PREFIX SUMS as part of the DP transition?
(Range sum DP, subarray sum optimization)
         |
        YES ──────────────────────────────────────────► Pattern 8: Cumulative Sum DP
         |
         v
Does the problem SPLIT a sequence into parts and combine results?
(Burst balloons, matrix chain, stone merge, interval DP)
         |
        YES ──────────────────────────────────────────► Pattern 9: Matrix Chain / Interval DP
         |
         v
Does the problem find MAX/MIN SUBARRAY SUM in a contiguous range?
(Kadane's, circular subarray, maximum product subarray)
         |
        YES ──────────────────────────────────────────► Pattern 10: Kadane's Algorithm
         |
         v
Does the state include a BITMASK representing a SET of visited items?
(TSP, assign tasks, cover all states, shortest path visiting all nodes)
         |
        YES ──────────────────────────────────────────► Pattern 11: Bitmask DP
         |
         v
Does the problem COUNT numbers in a RANGE satisfying digit constraints?
(Count numbers with digit sum X, no consecutive digits, etc.)
         |
        YES ──────────────────────────────────────────► Pattern 12: Digit DP
         |
         v
Is the input a TREE and dp[node] depends on children's dp values?
(Tree diameter, house robber on tree, max independent set)
         |
        YES ──────────────────────────────────────────► Pattern 13: DP on Trees
         |
         v
Does the DP use MATHEMATICAL properties (combinatorics, GCD, primes)?
(Catalan numbers, nth Fibonacci, count via math formula + DP)
         |
        YES ──────────────────────────────────────────► Pattern 14: DP with Math
         |
         v
Does the problem compute EXPECTED VALUE or PROBABILITY?
(Expected steps, probability of reaching state, random walk)
         |
        YES ──────────────────────────────────────────► Pattern 15: DP with Probability
         |
         v
        END
```

### 10-Second Interview Shortcut

| Signal in problem | Pattern |
|---|---|
| dp[i] from previous elements, 1D array | P1 — Linear DP |
| Two sequences or two indices | P2 — 2D DP |
| Grid movement, min path, robot | P3 — Grid DP |
| Items + capacity/weight limit | P4 — Knapsack |
| Longest strictly increasing sequence | P5 — LIS |
| Two strings, edit/match/common | P6 — LCS |
| Single string, palindrome, word break | P7 — String DP |
| Prefix sum inside DP transition | P8 — Cumulative Sum DP |
| Split interval, merge parts, burst | P9 — Interval / Matrix Chain |
| Max/min contiguous subarray | P10 — Kadane |
| Visited set as bitmask, TSP | P11 — Bitmask DP |
| Count integers in range by digits | P12 — Digit DP |
| Tree, dp flows from children | P13 — Tree DP |
| Catalan, Fibonacci, combinatorics | P14 — Math DP |
| Probability, expected value | P15 — Probability DP |

---

## Pattern 1 — Linear DP

### Notes and Theory

**What it is**: The simplest DP. `dp[i]` represents the answer for the first `i` elements, and transitions come from a constant number of previous states. The array is processed left to right.

**How to identify**:
- Single 1D array or sequence input
- "Maximum profit", "number of ways", "minimum cost" over a sequence
- `dp[i]` depends on `dp[i-1]`, `dp[i-2]`, or a few previous states
- Keywords: "climbing stairs", "jump game", "house robber", "decode ways"

**Climbing Stairs (70)**:
```cpp
int climbStairs(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
```

**House Robber (198)**:
```cpp
int rob(vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int x : nums) {
        int curr = max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
    // dp[i] = max(dp[i-1], dp[i-2] + nums[i])
}
```

**Decode Ways (91)**:
```cpp
int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = s[0] != '0' ? 1 : 0;
    for (int i = 2; i <= n; i++) {
        int one = s[i-1] - '0';
        int two = stoi(s.substr(i-2, 2));
        if (one >= 1) dp[i] += dp[i-1];
        if (two >= 10 && two <= 26) dp[i] += dp[i-2];
    }
    return dp[n];
}
```

**Jump Game II (45) — min jumps**:
```cpp
int jump(vector<int>& nums) {
    int jumps = 0, currEnd = 0, farthest = 0;
    for (int i = 0; i < (int)nums.size()-1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == currEnd) { jumps++; currEnd = farthest; }
    }
    return jumps;
}
```

**Key insight**: Space optimization is almost always possible for linear DP — if `dp[i]` only depends on the last K states, keep only K variables instead of the full array. Common K values: 1 (`dp[i-1]`), 2 (`dp[i-1]` and `dp[i-2]`).

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 70 | Climbing Stairs | Easy | Fibonacci-style linear DP |
| 198 | House Robber | Medium | Skip adjacent elements |
| 213 | House Robber II | Medium | Circular — run twice |
| 91 | Decode Ways | Medium | Conditional transitions |
| 45 | Jump Game II | Medium | Greedy / DP jumps |
| 322 | Coin Change | Medium | Unbounded — see P4 |
| 139 | Word Break | Medium | Check all breakpoints |
| 300 | Longest Increasing Subsequence | Medium | See P5 |
| 746 | Min Cost Climbing Stairs | Easy | Min of two prev |
| 740 | Delete and Earn | Medium | Reduce to house robber |

### All Problems in Pattern 1

- 45 Jump Game II
- 55 Jump Game
- 70 Climbing Stairs
- 91 Decode Ways
- 139 Word Break
- 152 Maximum Product Subarray
- 198 House Robber
- 213 House Robber II
- 264 Ugly Number II
- 279 Perfect Squares
- 300 Longest Increasing Subsequence
- 322 Coin Change
- 338 Counting Bits
- 343 Integer Break
- 377 Combination Sum IV
- 413 Arithmetic Slices
- 650 2 Keys Keyboard
- 740 Delete and Earn
- 746 Min Cost Climbing Stairs
- 873 Length of Longest Fibonacci Subsequence
- 983 Minimum Cost For Tickets
- 1137 N-th Tribonacci Number
- 1653 Minimum Deletions to Make String Balanced
- 2140 Solving Questions With Brainpower
- 2466 Count Ways To Build Good Strings
- 2770 Maximum Number of Jumps to Reach the Last Index

---

## Pattern 2 — 2 Dimensional DP

### Notes and Theory

**What it is**: `dp[i][j]` represents the answer for a state defined by two indices — usually processing two sequences simultaneously, or tracking two variables. Transitions come from neighboring states in the 2D table.

**How to identify**:
- Two input sequences (strings, arrays)
- State requires two dimensions to fully describe
- "For each prefix of A and prefix of B, what is...?"
- Keywords: "two arrays", "two strings", "matches", "align"

**2D DP Table Setup**:
```cpp
// dp[i][j] = answer considering first i elements of A and first j elements of B
int m = A.size(), n = B.size();
vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

// Base cases: dp[0][j] and dp[i][0] (empty prefix)
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        if (A[i-1] == B[j-1]) {
            dp[i][j] = dp[i-1][j-1] + 1; // characters match
        } else {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // take best of skipping
        }
    }
}
```

**Unique Paths (62)**:
```cpp
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    return dp[m-1][n-1];
}
```

**Space optimization — rolling array**:
```cpp
// Often dp[i][j] only depends on dp[i-1][...] and dp[i][j-1]
// Use two 1D arrays (prev row and curr row)
vector<int> prev(n+1, 0), curr(n+1, 0);
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        curr[j] = /* transition using prev[j] and curr[j-1] */;
    }
    swap(prev, curr);
}
```

**Key insight**: Fill the 2D table row by row, left to right. Identify which cells the current cell depends on, and make sure those are computed first. Space can often be reduced to O(n) using a rolling array.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 62 | Unique Paths | Medium | Grid paths 2D |
| 1143 | Longest Common Subsequence | Medium | Classic 2D DP |
| 72 | Edit Distance | Hard | 2D string DP |
| 1312 | Minimum Insertion for Palindrome | Hard | 2D palindrome DP |
| 516 | Longest Palindromic Subsequence | Medium | 2D on same string |
| 97 | Interleaving String | Medium | 2D check DP |
| 115 | Distinct Subsequences | Hard | Count 2D DP |
| 1035 | Uncrossed Lines | Medium | Same as LCS |

### All Problems in Pattern 2

- 62 Unique Paths
- 63 Unique Paths II
- 72 Edit Distance
- 97 Interleaving String
- 115 Distinct Subsequences
- 516 Longest Palindromic Subsequence
- 583 Delete Operation for Two Strings
- 712 Minimum ASCII Delete Sum
- 1035 Uncrossed Lines
- 1143 Longest Common Subsequence
- 1312 Minimum Insertion Steps to Make a String Palindrome
- 2707 Extra Characters in a String

---

## Pattern 3 — DP on Grid

### Notes and Theory

**What it is**: The state is a cell `(i, j)` in a 2D grid. Movement is typically from top-left to bottom-right (or along valid directions). `dp[i][j]` = best answer to reach or pass through cell `(i,j)`.

**How to identify**:
- 2D grid/matrix input
- Robot moves on grid, path from corner to corner
- "Minimum path sum", "number of ways to reach"
- Keywords: "grid", "robot", "path", "top-left to bottom-right"

**Minimum Path Sum (64)**:
```cpp
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    // Use grid itself as DP table (in-place)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            else if (i == 0) grid[i][j] += grid[i][j-1];
            else if (j == 0) grid[i][j] += grid[i-1][j];
            else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }
    return grid[m-1][n-1];
}
```

**Triangle (120) — top-down path**:
```cpp
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp = triangle[n-1]; // start from bottom row
    for (int i = n-2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
    return dp[0];
}
```

**Dungeon Game (174) — reverse DP**:
```cpp
// Fill from bottom-right to top-left
// dp[i][j] = minimum HP needed at cell (i,j) to survive
int m = dungeon.size(), n = dungeon[0].size();
vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
dp[m][n-1] = dp[m-1][n] = 1; // sentinel
for (int i = m-1; i >= 0; i--)
    for (int j = n-1; j >= 0; j--)
        dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
return dp[0][0];
```

**Key insight**: When you can only move right and down, `dp[i][j]` always depends on `dp[i-1][j]` (above) and `dp[i][j-1]` (left). For problems requiring minimum HP or survival, fill in reverse (bottom-right to top-left).

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 62 | Unique Paths | Medium | Count paths |
| 64 | Minimum Path Sum | Medium | Min cost top-left to bottom-right |
| 120 | Triangle | Medium | Bottom-up grid DP |
| 174 | Dungeon Game | Hard | Reverse grid DP |
| 221 | Maximal Square | Medium | Square DP recurrence |
| 931 | Minimum Falling Path Sum | Medium | 3-direction min |
| 1301 | Number of Paths with Max Score | Hard | Grid DP + count |
| 2304 | Minimum Path Cost in a Grid | Medium | Row-to-row DP |

### All Problems in Pattern 3

- 62 Unique Paths
- 63 Unique Paths II
- 64 Minimum Path Sum
- 120 Triangle
- 174 Dungeon Game
- 221 Maximal Square
- 329 Longest Increasing Path in a Matrix
- 741 Cherry Pickup
- 931 Minimum Falling Path Sum
- 1014 Best Sightseeing Pair
- 1301 Number of Paths with Max Score
- 2267 Check if There Is a Valid Parentheses String Path
- 2304 Minimum Path Cost in a Grid
- 2435 Paths in Matrix Whose Sum Is Divisible by K

---

## Pattern 4 — Knapsack DP

### Notes and Theory

**What it is**: Select items from a collection to optimize a value under a capacity constraint. Three variants: 0/1 knapsack (each item once), unbounded knapsack (infinite copies), and bounded knapsack (limited copies).

**How to identify**:
- "Select items with weight/cost ≤ capacity to maximize value"
- "Can we form sum X using these numbers?"
- "Coin change", "subset sum", "partition equal subset"
- Keywords: "capacity", "weight", "select items", "target sum", "can we make"

**0/1 Knapsack**:
```cpp
// dp[j] = max value achievable with capacity j
vector<int> dp(W+1, 0);
for (auto [weight, value] : items) {
    // Iterate BACKWARDS to prevent using same item twice
    for (int j = W; j >= weight; j--) {
        dp[j] = max(dp[j], dp[j - weight] + value);
    }
}
return dp[W];
```

**Unbounded Knapsack (Coin Change)**:
```cpp
// dp[j] = min coins to make amount j
vector<int> dp(amount+1, INT_MAX);
dp[0] = 0;
for (int coin : coins) {
    // Iterate FORWARDS — same coin can be used multiple times
    for (int j = coin; j <= amount; j++) {
        if (dp[j - coin] != INT_MAX)
            dp[j] = min(dp[j], dp[j - coin] + 1);
    }
}
return dp[amount] == INT_MAX ? -1 : dp[amount];
```

**Subset Sum / Partition Equal Subset (416)**:
```cpp
bool canPartition(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) return false;
    int target = total / 2;
    // dp[j] = can we form sum j
    vector<bool> dp(target+1, false);
    dp[0] = true;
    for (int x : nums) {
        for (int j = target; j >= x; j--) { // backwards = 0/1 knapsack
            dp[j] = dp[j] || dp[j - x];
        }
    }
    return dp[target];
}
```

**Key insight**: 
- **0/1 knapsack**: iterate capacity BACKWARDS (ensures each item used at most once)
- **Unbounded knapsack**: iterate capacity FORWARDS (allows reusing same item)
- This single direction difference is the key to all knapsack variants.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 322 | Coin Change | Medium | Unbounded — min coins |
| 518 | Coin Change II | Medium | Unbounded — count ways |
| 416 | Partition Equal Subset Sum | Medium | 0/1 knapsack bool |
| 494 | Target Sum | Medium | +/- assignment = knapsack |
| 474 | Ones and Zeroes | Medium | 2D knapsack |
| 1049 | Last Stone Weight II | Medium | Partition — min diff |
| 879 | Profitable Schemes | Hard | 2D knapsack profit+people |
| 2915 | Length of Longest Subarray | Medium | Knapsack variant |

### All Problems in Pattern 4

- 322 Coin Change
- 377 Combination Sum IV
- 416 Partition Equal Subset Sum
- 474 Ones and Zeroes
- 494 Target Sum
- 518 Coin Change II
- 638 Shopping Offers
- 879 Profitable Schemes
- 1049 Last Stone Weight II
- 1155 Number of Dice Rolls With Target Sum
- 1449 Number of Students Doing Homework
- 2915 Length of the Longest Subsequence That Sums to Target

---

## Pattern 5 — Longest Increasing Subsequence (LIS)

### Notes and Theory

**What it is**: Find the length (or count) of the longest strictly increasing subsequence. Two approaches: O(n²) DP or O(n log n) patience sorting with binary search.

**How to identify**:
- "Longest increasing subsequence"
- "Number of LIS", "Russian dolls", "envelopes"
- Keywords: "increasing", "strictly", "non-decreasing", "nested", "stack envelopes"

**O(n²) LIS DP**:
```cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // dp[i] = LIS ending at index i
    int maxLen = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}
```

**O(n log n) LIS — Patience Sorting**:
```cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails; // tails[i] = smallest tail of IS with length i+1
    for (int x : nums) {
        // Find first tail >= x (lower_bound for strict increasing)
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x); // extend LIS
        else *it = x;                               // replace with smaller tail
    }
    return tails.size();
}
```

**Russian Doll Envelopes (354)**:
```cpp
// Sort by width ASC, then by height DESC (same width: DESC to prevent chaining)
// Then LIS on heights only
sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b) {
    return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
});
// Apply O(n log n) LIS on heights
```

**Key insight**: The patience sorting tails array is NOT the actual LIS — it's a virtual structure whose LENGTH equals the LIS length. The DESC sort trick for same-width envelopes prevents "cheating" by stacking same-width envelopes.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 300 | Longest Increasing Subsequence | Medium | Core LIS O(n log n) |
| 354 | Russian Doll Envelopes | Hard | 2D LIS with sort trick |
| 673 | Number of Longest Increasing Subsequences | Medium | Count LIS |
| 1964 | Find the Longest Valid Obstacle Course | Hard | LIS with non-strict |
| 2370 | Longest Ideal Subsequence | Medium | LIS with tolerance k |
| 646 | Maximum Length of Pair Chain | Medium | Sort + greedy LIS |
| 1626 | Best Team With No Conflicts | Medium | 2D LIS variant |

### All Problems in Pattern 5

- 300 Longest Increasing Subsequence
- 354 Russian Doll Envelopes
- 646 Maximum Length of Pair Chain
- 673 Number of Longest Increasing Subsequence
- 1048 Longest String Chain
- 1626 Best Team With No Conflicts
- 1964 Find the Longest Valid Obstacle Course at Each Position
- 2370 Longest Ideal Subsequence

---

## Pattern 6 — Longest Common Subsequence (LCS)

### Notes and Theory

**What it is**: Find the longest subsequence common to two sequences (not necessarily contiguous). Foundation for edit distance, diff tools, DNA alignment, and many string DP problems.

**How to identify**:
- "Common subsequence of two strings/arrays"
- "Edit distance", "minimum deletions to make equal"
- "Uncrossed lines", "interleaving"
- Keywords: "common", "both strings", "align", "delete to make equal"

**LCS Template**:
```cpp
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;        // characters match
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // skip one
        }
    }
    return dp[m][n];
}
```

**Deriving other problems from LCS**:
```
Edit Distance = LCS + insert/delete/replace costs
Min Deletions to Make Equal = len(A) + len(B) - 2 * LCS(A, B)
Shortest Common Supersequence = len(A) + len(B) - LCS(A, B)
Longest Palindromic Subsequence = LCS(s, reverse(s))
```

**Edit Distance (72)**:
```cpp
// dp[i][j] = min operations to convert text1[0..i-1] to text2[0..j-1]
if (text1[i-1] == text2[j-1])
    dp[i][j] = dp[i-1][j-1];                              // no op needed
else
    dp[i][j] = 1 + min({dp[i-1][j],    // delete from text1
                         dp[i][j-1],    // insert into text1
                         dp[i-1][j-1]}); // replace
```

**Key insight**: LCS is the base of all "two-string comparison" DP. When characters match: extend diagonal. When they don't: take max of skipping either string. The O(mn) table can be space-optimized to O(n) with rolling array.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 1143 | Longest Common Subsequence | Medium | Core LCS |
| 72 | Edit Distance | Hard | LCS with edit costs |
| 583 | Delete Operation for Two Strings | Medium | min deletions = n+m-2*LCS |
| 1035 | Uncrossed Lines | Medium | Identical to LCS |
| 1092 | Shortest Common Supersequence | Hard | SCS = n+m-LCS |
| 516 | Longest Palindromic Subsequence | Medium | LCS(s, reverse(s)) |
| 712 | Minimum ASCII Delete Sum | Medium | Weighted LCS |
| 1312 | Minimum Insertion for Palindrome | Hard | n - LPS |

### All Problems in Pattern 6

- 72 Edit Distance
- 115 Distinct Subsequences
- 516 Longest Palindromic Subsequence
- 583 Delete Operation for Two Strings
- 712 Minimum ASCII Delete Sum for Two Strings
- 1035 Uncrossed Lines
- 1092 Shortest Common Supersequence
- 1143 Longest Common Subsequence
- 1312 Minimum Insertion Steps to Make a String Palindrome

---

## Pattern 7 — DP on Strings

### Notes and Theory

**What it is**: DP where the state is defined over substrings of a single input string. Common forms: `dp[i]` (prefix ending at i) or `dp[i][j]` (substring from i to j).

**How to identify**:
- Single string input, DP on its substrings or prefixes
- "Palindrome partitioning", "word break", "regex matching"
- Keywords: "substring", "split string", "palindrome", "match pattern"

**Word Break (139)**:
```cpp
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true; // empty string

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i-j))) {
                dp[i] = true; break;
            }
        }
    }
    return dp[n];
}
```

**Palindrome Partitioning II (132) — min cuts**:
```cpp
// Precompute isPalin[i][j] using DP
// Then dp[i] = min cuts for s[0..i]
vector<vector<bool>> isPalin(n, vector<bool>(n, false));
for (int len = 1; len <= n; len++)
    for (int i = 0; i+len-1 < n; i++) {
        int j = i+len-1;
        isPalin[i][j] = (s[i] == s[j]) && (len <= 2 || isPalin[i+1][j-1]);
    }

vector<int> dp(n, INT_MAX);
for (int i = 0; i < n; i++) {
    if (isPalin[0][i]) { dp[i] = 0; continue; }
    for (int j = 1; j <= i; j++)
        if (isPalin[j][i]) dp[i] = min(dp[i], dp[j-1] + 1);
}
return dp[n-1];
```

**Regular Expression Matching (10)**:
```cpp
// dp[i][j] = does s[0..i-1] match p[0..j-1]
// If p[j-1] == '*': dp[i][j] = dp[i][j-2] (zero occurrences)
//                             || dp[i-1][j] (one+ occurrences, if s[i-1] matches p[j-2])
// If p[j-1] != '*': dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.')
```

**Key insight**: For palindrome problems on a single string, `dp[i][j]` where `i <= j` represents whether `s[i..j]` is a palindrome. Expand from length 1 outward. For word break, try all split points `j < i`.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 139 | Word Break | Medium | Split at all valid words |
| 132 | Palindrome Partitioning II | Hard | Min cuts with isPalin |
| 5 | Longest Palindromic Substring | Medium | Expand or 2D DP |
| 10 | Regular Expression Matching | Hard | Pattern match DP |
| 44 | Wildcard Matching | Hard | * matches any sequence |
| 647 | Palindromic Substrings | Medium | Count all palindromes |
| 1216 | Valid Palindrome III | Hard | Max deletions = n - LPS |
| 1531 | String Compression II | Hard | Multi-state string DP |

### All Problems in Pattern 7

- 5 Longest Palindromic Substring
- 10 Regular Expression Matching
- 44 Wildcard Matching
- 131 Palindrome Partitioning
- 132 Palindrome Partitioning II
- 139 Word Break
- 140 Word Break II
- 516 Longest Palindromic Subsequence
- 647 Palindromic Substrings
- 1216 Valid Palindrome III
- 1531 String Compression II
- 2707 Extra Characters in a String

---

## Pattern 8 — Cumulative Sum DP

### Notes and Theory

**What it is**: Use prefix sums inside DP transitions to reduce O(n) inner loops to O(1). The prefix sum of `dp` values enables computing "sum of all dp[j] for j < i satisfying condition" in constant time.

**How to identify**:
- DP transition sums over a range of previous states
- "Number of ways to reach i from any j" (needs sum of dp[j..i-1])
- Keywords: "any starting point", "sum of ways", "total paths"

**Arithmetic Slices II (446)**:
```cpp
// dp[i][d] = number of arithmetic subsequences ending at i with diff d
// ans += dp[j][d] for all j < i where diff = nums[i]-nums[j]
vector<unordered_map<long long,long long>> dp(n);
long long ans = 0;
for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
        long long d = (long long)nums[i] - nums[j];
        long long cnt = dp[j].count(d) ? dp[j][d] : 0;
        ans += cnt;
        dp[i][d] += cnt + 1;
    }
}
return ans;
```

**Count Number of Texts (2266)**:
```cpp
// dp[i] = ways to decode s[0..i-1]
// Use modular prefix sums for efficiency
```

**Key insight**: When `dp[i] = sum(dp[j]) for j in some range`, maintain a running prefix sum of dp values. This is the bridge between prefix sum (Pattern 8 of prefix sum guide) and DP.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 446 | Arithmetic Slices II | Hard | HashMap + prefix DP |
| 91 | Decode Ways | Medium | Linear with prefix logic |
| 2266 | Count Number of Texts | Medium | Prefix sum DP |
| 1262 | Greatest Sum Divisible by Three | Medium | Modular DP |
| 1269 | Number of Ways to Stay in Same Place | Hard | Cumulative state DP |

### All Problems in Pattern 8

- 91 Decode Ways
- 446 Arithmetic Slices II - Subsequence
- 1262 Greatest Sum Divisible by Three
- 1269 Number of Ways to Stay in the Same Place After Some Steps
- 2266 Count Number of Texts
- 2327 Number of People Aware of a Secret

---

## Pattern 9 — Matrix Chain Multiplication / Interval DP

### Notes and Theory

**What it is**: Solve problems by splitting an interval `[i, j]` at every possible split point `k` and combining results. The DP fills a triangular table from small intervals to large ones.

**How to identify**:
- "Burst balloons", "stone merging", "optimal matrix chain"
- "Split array and combine sub-results"
- "Minimum cost to merge all items"
- Keywords: "merge", "burst", "split", "interval cost", "parenthesization"

**Interval DP Template**:
```cpp
// dp[i][j] = optimal answer for interval [i, j]
int n = arr.size();
vector<vector<int>> dp(n, vector<int>(n, 0));

// Fill by increasing interval length
for (int len = 2; len <= n; len++) {        // interval length
    for (int i = 0; i <= n - len; i++) {    // left endpoint
        int j = i + len - 1;                // right endpoint
        dp[i][j] = INT_MAX;
        for (int k = i; k < j; k++) {       // split point
            dp[i][j] = min(dp[i][j],
                           dp[i][k] + dp[k+1][j] + cost(i, k, j));
        }
    }
}
return dp[0][n-1];
```

**Burst Balloons (312)**:
```cpp
// dp[i][j] = max coins from bursting all balloons between i and j (exclusive)
// Add sentinel balloons: nums[-1] = nums[n] = 1
// dp[i][j] = max over k in (i,j): dp[i][k] + nums[i]*nums[k]*nums[j] + dp[k][j]
// k is the LAST balloon to burst in range (i, j)
```

**Stone Merge (minimum cost)**:
```cpp
// dp[i][j] = min cost to merge stones[i..j] into one pile
// cost of merging = sum(stones[i..j]) = prefix[j+1] - prefix[i]
// dp[i][j] = min over k: dp[i][k] + dp[k+1][j] + (prefix[j+1] - prefix[i])
```

**Key insight**: Fill the table by INTERVAL LENGTH (from 2 to n), not by index. The split point `k` divides the interval into two independent sub-problems. The "last to burst" trick in Balloon problem inverts the usual thinking.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 312 | Burst Balloons | Hard | Last balloon trick |
| 1000 | Minimum Cost to Merge Stones | Hard | Interval + prefix sum |
| 1039 | Minimum Score Triangulation | Medium | Triangle interval DP |
| 375 | Guess Number Higher or Lower II | Medium | Min cost strategy |
| 1547 | Minimum Cost to Cut a Stick | Hard | Interval cut cost |
| 1130 | Minimum Cost Tree From Leaf Values | Medium | Interval or mono stack |
| 664 | Strange Printer | Hard | Interval DP on string |

### All Problems in Pattern 9

- 312 Burst Balloons
- 375 Guess Number Higher or Lower II
- 516 Longest Palindromic Subsequence (interval DP form)
- 664 Strange Printer
- 1000 Minimum Cost to Merge Stones
- 1039 Minimum Score Triangulation of Polygon
- 1130 Minimum Cost Tree From Leaf Values
- 1547 Minimum Cost to Cut a Stick
- 2019 The Score of Students Solving Math Expression

---

## Pattern 10 — Kadane's Algorithm

### Notes and Theory

**What it is**: Find the maximum (or minimum) sum contiguous subarray in O(n). Kadane's key insight: at each position, either extend the previous subarray or start fresh.

**How to identify**:
- "Maximum sum subarray"
- "Maximum product subarray"
- "Circular subarray maximum"
- Keywords: "contiguous", "subarray", "maximum sum", "product"

**Kadane's Algorithm (53)**:
```cpp
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], curr = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        curr = max(nums[i], curr + nums[i]); // extend or restart
        maxSum = max(maxSum, curr);
    }
    return maxSum;
}
```

**Maximum Product Subarray (152)**:
```cpp
// Track both max and min (min * negative = large positive)
int maxProd = nums[0], minProd = nums[0], result = nums[0];
for (int i = 1; i < (int)nums.size(); i++) {
    if (nums[i] < 0) swap(maxProd, minProd);
    maxProd = max(nums[i], maxProd * nums[i]);
    minProd = min(nums[i], minProd * nums[i]);
    result = max(result, maxProd);
}
return result;
```

**Circular Subarray Maximum (918)**:
```cpp
// Case 1: max subarray doesn't wrap = standard Kadane
// Case 2: max subarray wraps = total - min subarray
// Edge: if all negative, return Case 1 result (can't use empty array)
int totalSum = 0, maxSum = nums[0], currMax = 0;
int minSum = nums[0], currMin = 0;
for (int x : nums) {
    currMax = max(currMax + x, x);  maxSum = max(maxSum, currMax);
    currMin = min(currMin + x, x);  minSum = min(minSum, currMin);
    totalSum += x;
}
return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
```

**Key insight**: `curr = max(nums[i], curr + nums[i])` means: "start fresh at nums[i]" vs "extend previous subarray". For product variant, track both max and min because a negative times a negative becomes positive.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 53 | Maximum Subarray | Medium | Classic Kadane |
| 152 | Maximum Product Subarray | Medium | Kadane with min tracking |
| 918 | Maximum Sum Circular Subarray | Medium | Total - min subarray |
| 2321 | Maximum Score of Spliced Array | Hard | Kadane on difference |
| 1749 | Maximum Absolute Sum of Any Subarray | Medium | Max + min Kadane |
| 2606 | Find the Substring With Maximum Cost | Medium | Kadane with char map |

### All Problems in Pattern 10

- 53 Maximum Subarray
- 152 Maximum Product Subarray
- 918 Maximum Sum Circular Subarray
- 1749 Maximum Absolute Sum of Any Subarray
- 2321 Maximum Score of Spliced Array
- 2606 Find the Substring With Maximum Cost

---

## Pattern 11 — DP with Bitmask

### Notes and Theory

**What it is**: The DP state includes a bitmask representing which items/nodes have been visited. Used when n is small (typically n ≤ 20) and you need to track a subset of visited elements.

**How to identify**:
- Small n (≤ 20), need to track visited set
- "Assign tasks to workers", "visit all nodes"
- TSP-style problems
- Keywords: "assign", "cover all", "visit all", "permutation"

**Bitmask DP Template**:
```cpp
// dp[mask][i] = answer having visited nodes in mask, currently at node i
int n = /* number of items */;
vector<vector<int>> dp(1<<n, vector<int>(n, INT_MAX));
dp[1<<start][start] = 0; // visited only start, currently at start

for (int mask = 0; mask < (1<<n); mask++) {
    for (int u = 0; u < n; u++) {
        if (!(mask & (1<<u))) continue;         // u not visited
        if (dp[mask][u] == INT_MAX) continue;
        for (int v = 0; v < n; v++) {
            if (mask & (1<<v)) continue;        // v already visited
            int newMask = mask | (1<<v);
            dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + dist[u][v]);
        }
    }
}
```

**Shortest Path Visiting All Nodes (847)**:
```cpp
// BFS + bitmask: state = (node, visitedMask)
// Start from all nodes simultaneously (multi-source BFS)
// Target: mask == (1<<n) - 1 (all visited)
queue<tuple<int,int,int>> q; // {node, mask, dist}
set<pair<int,int>> visited;
for (int i = 0; i < n; i++) {
    q.push({i, 1<<i, 0});
    visited.insert({i, 1<<i});
}
```

**Key insight**: Bitmask DP trades exponential states (2^n) for polynomial time per state. Total: O(2^n × n²). Only feasible for n ≤ 20. Enumerate subsets in increasing mask order — smaller masks always computed before larger ones.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 847 | Shortest Path Visiting All Nodes | Hard | BFS + bitmask |
| 943 | Find the Shortest Superstring | Hard | TSP bitmask DP |
| 1986 | Min Number of Work Sessions | Medium | Bitmask subset DP |
| 2172 | Maximum AND Sum of Array | Hard | Bitmask assignment |
| 1655 | Distribute Repeating Integers | Hard | Bitmask demand cover |
| 2305 | Fair Distribution of Cookies | Medium | Bitmask partition |

### All Problems in Pattern 11

- 847 Shortest Path Visiting All Nodes
- 943 Find the Shortest Superstring
- 1986 Minimum Number of Work Sessions to Finish the Tasks
- 2002 Maximum Product of the Length of Two Palindromic Subsequences
- 2172 Maximum AND Sum of Array
- 2305 Fair Distribution of Cookies
- 2403 Minimum Time to Kill All Monsters
- 2741 Special Permutations

---

## Pattern 12 — Digit DP

### Notes and Theory

**What it is**: Count integers in range `[0, N]` satisfying digit-level constraints. State tracks: current digit position, whether we're still bounded by N (tight constraint), and any accumulated state (sum, last digit, etc.).

**How to identify**:
- "Count numbers from 1 to N where..."
- "Digit sum equals X", "no two consecutive same digits"
- Keywords: "count numbers", "digit", "range [1,N]", "at most N"

**Digit DP Template**:
```cpp
string num = to_string(N);
int n = num.size();

// dp[pos][tight][...state...] = count of valid numbers
// tight: are we still bounded by num's digits?
// Memoize with map or array

function<long long(int, bool, int)> solve =
    [&](int pos, bool tight, int state) -> long long {
    if (pos == n) return isValid(state) ? 1 : 0;

    int limit = tight ? (num[pos] - '0') : 9;
    long long result = 0;
    for (int digit = 0; digit <= limit; digit++) {
        bool newTight = tight && (digit == limit);
        result += solve(pos+1, newTight, nextState(state, digit));
    }
    return result;
};
return solve(0, true, initialState);
```

**Count Numbers with Unique Digits (357)**:
```cpp
// dp approach: count of n-digit numbers with all unique digits
// P(10, n) = 10 * 9 * 8 * ... for n digits
```

**Key insight**: The "tight" flag is what makes digit DP work. When `tight = true`, the current digit can go at most `num[pos]`. When `tight = false` (we've already placed a smaller digit), current digit can be 0-9. Always memoize on `(pos, tight, otherState)`.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 357 | Count Numbers with Unique Digits | Medium | Count unique digit combos |
| 600 | Non-negative Integers without Consecutive Ones | Hard | Binary digit DP |
| 902 | Numbers At Most N Given Digit Set | Hard | Digit DP with set |
| 1012 | Numbers With Repeated Digits | Hard | Complement digit DP |
| 2376 | Count Special Integers | Medium | No repeated digits |
| 2719 | Count of Integers | Hard | Digit sum range |

### All Problems in Pattern 12

- 357 Count Numbers with Unique Digits
- 600 Non-negative Integers without Consecutive Ones
- 788 Rotated Digits
- 902 Numbers At Most N Given Digit Set of Digits
- 1012 Numbers With Repeated Digits
- 2376 Count Special Integers
- 2719 Count of Integers

---

## Pattern 13 — DP on Trees

### Notes and Theory

**What it is**: DP where state is defined at each tree node and computed bottom-up (post-order DFS). Each node's result depends on its children's results. Covered in detail in the Binary Tree guide (Patterns 2 and 11).

**How to identify**:
- Tree input, answer aggregated from subtrees
- "Maximum independent set on tree", "house robber on tree"
- Keywords: "tree DP", "subtree", "take or skip children"

**House Robber III (337)**:
```cpp
// Return {robThisNode, skipThisNode}
pair<int,int> dfs(TreeNode* node) {
    if (!node) return {0, 0};
    auto [lRob, lSkip] = dfs(node->left);
    auto [rRob, rSkip] = dfs(node->right);

    int rob  = node->val + lSkip + rSkip; // take this, skip children
    int skip = max(lRob, lSkip) + max(rRob, rSkip); // skip this
    return {rob, skip};
}
```

**Diameter of Binary Tree (543)**:
```cpp
int ans = 0;
function<int(TreeNode*)> height = [&](TreeNode* node) -> int {
    if (!node) return 0;
    int l = height(node->left), r = height(node->right);
    ans = max(ans, l + r); // path through this node
    return 1 + max(l, r);
};
height(root); return ans;
```

**Max Path Sum (124)**:
```cpp
int ans = INT_MIN;
function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
    if (!node) return 0;
    int l = max(0, dfs(node->left));
    int r = max(0, dfs(node->right));
    ans = max(ans, node->val + l + r);
    return node->val + max(l, r);
};
```

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 337 | House Robber III | Medium | Take/skip tree DP |
| 124 | Binary Tree Maximum Path Sum | Hard | Max path through node |
| 543 | Diameter of Binary Tree | Easy | Height DP |
| 968 | Binary Tree Cameras | Hard | 3-state tree DP |
| 979 | Distribute Coins in Binary Tree | Medium | Excess flow DP |
| 2246 | Longest Path With Different Adjacent | Medium | Tree LIS variant |
| 2538 | Difference Between Max and Min Price | Hard | Rerooting DP |

### All Problems in Pattern 13

- 124 Binary Tree Maximum Path Sum
- 337 House Robber III
- 543 Diameter of Binary Tree
- 687 Longest Univalue Path
- 968 Binary Tree Cameras
- 979 Distribute Coins in Binary Tree
- 1245 Tree Diameter
- 1373 Maximum Sum BST in Binary Tree
- 2246 Longest Path With Different Adjacent Characters
- 2538 Difference Between Maximum and Minimum Price Sum

---

## Pattern 14 — DP with Math

### Notes and Theory

**What it is**: DP problems that rely on mathematical identities, combinatorics, or number theory. The recurrence is derived from a mathematical formula rather than pure sequence logic.

**How to identify**:
- Catalan numbers, Fibonacci, Pascal's triangle
- "Number of BSTs", "number of bracket sequences"
- "GCD/LCM constraints", "prime factorization"
- Keywords: "count structures", "number of ways", "mathematical pattern"

**Unique BSTs (Catalan Number — 96)**:
```cpp
// dp[n] = number of structurally unique BSTs with n nodes
// dp[n] = sum(dp[i-1] * dp[n-i]) for i = 1 to n
// This is the nth Catalan number
vector<long long> dp(n+1, 0);
dp[0] = dp[1] = 1;
for (int i = 2; i <= n; i++)
    for (int j = 1; j <= i; j++)
        dp[i] += dp[j-1] * dp[i-j];
return dp[n];
```

**Integer Break (343)**:
```cpp
// dp[n] = max product of integers summing to n
// Key math insight: break into 3s as much as possible
// dp[i] = max(j * (i-j), j * dp[i-j]) for j in 2..i-1
```

**Nth Digit Fibonacci / Tribonacci**:
```cpp
// dp[i] = dp[i-1] + dp[i-2] + dp[i-3]  (Tribonacci)
// Space optimize to O(1) with 3 variables
```

**Key insight**: Recognizing the mathematical pattern (Catalan, Fibonacci, Stirling numbers) is the key skill. Once you know the formula, the DP table fills mechanically.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 96 | Unique Binary Search Trees | Medium | Catalan number DP |
| 343 | Integer Break | Medium | Math insight + DP |
| 509 | Fibonacci Number | Easy | Base Fibonacci |
| 1137 | N-th Tribonacci Number | Easy | 3-term recurrence |
| 264 | Ugly Number II | Medium | 3-pointer merge DP |
| 1259 | Handshakes That Don't Cross | Hard | Catalan variant |

### All Problems in Pattern 14

- 96 Unique Binary Search Trees
- 264 Ugly Number II
- 343 Integer Break
- 509 Fibonacci Number
- 1137 N-th Tribonacci Number
- 1259 Handshakes That Don't Cross
- 2338 Count the Number of Ideal Arrays

---

## Pattern 15 — DP with Probability

### Notes and Theory

**What it is**: Compute the probability of reaching a state, or the expected number of steps/operations. States have fractional values; transitions involve multiplication by probabilities.

**How to identify**:
- "Probability of reaching state X"
- "Expected number of steps"
- "Random walk", "dice rolls"
- Keywords: "probability", "expected", "random", "chance"

**New 21 Game (837)**:
```cpp
// dp[i] = probability of having exactly i points
// At each step: draw random card 1..maxPts with equal probability
// Use sliding window sum for efficiency
double new21Game(int n, int k, int maxPts) {
    if (k == 0 || n >= k + maxPts) return 1.0;
    vector<double> dp(n+1, 0.0);
    dp[0] = 1.0;
    double windowSum = 1.0;
    for (int i = 1; i <= n; i++) {
        dp[i] = windowSum / maxPts;
        if (i < k) windowSum += dp[i];
        if (i >= maxPts) windowSum -= dp[i - maxPts];
    }
    double ans = 0;
    for (int i = k; i <= n; i++) ans += dp[i];
    return ans;
}
```

**Knight Probability (688)**:
```cpp
// dp[k][r][c] = probability of being at (r,c) after k moves
// Base: dp[0][row][col] = 1.0
// Transition: dp[k][r][c] = sum(dp[k-1][pr][pc]) / 8.0 for all valid prev positions
```

**Soup Servings (808)**:
```cpp
// dp[a][b] = probability of soup A running out first when a units of A and b of B remain
// 4 operations each with probability 0.25
```

**Key insight**: Probability DP transitions multiply by probability at each step. Use double/float. When exact fractions needed, track numerator/denominator separately. Sliding window sum optimization avoids O(maxPts) inner loop.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 837 | New 21 Game | Medium | Probability + window sum |
| 688 | Knight Probability in Chessboard | Medium | 3D probability DP |
| 808 | Soup Servings | Medium | Expected probability DP |
| 1227 | Airplane Seat Assignment | Medium | Math + probability |
| 1467 | Probability of a Two Boxes | Hard | Combinatorial probability |

### All Problems in Pattern 15

- 688 Knight Probability in Chessboard
- 808 Soup Servings
- 837 New 21 Game
- 1227 Airplane Seat Assignment Probability
- 1467 Probability of a Two Boxes Having the Same Number of Distinct Balls

---

## 30-Day Mastery Roadmap

### Week 1 — DP Level 1 Foundations (Days 1-7)

| Day | Focus | Problems to Solve |
|---|---|---|
| 1 | Pattern 1: Linear DP basics | 70, 198, 746 |
| 2 | Pattern 1: Linear DP advanced | 91, 139, 740 |
| 3 | Pattern 10: Kadane | 53, 152, 918 |
| 4 | Pattern 4: Knapsack basics | 322, 416 |
| 5 | Pattern 4: Knapsack variants | 518, 494, 1049 |
| 6 | Pattern 3: Grid DP | 62, 64, 120 |
| 7 | Review Week 1 | Re-solve 4 hardest |

### Week 2 — Subsequence Patterns (Days 8-14)

| Day | Focus | Problems to Solve |
|---|---|---|
| 8 | Pattern 5: LIS O(n²) | 300, 673 |
| 9 | Pattern 5: LIS O(n log n) | 354, 646, 1964 |
| 10 | Pattern 6: LCS core | 1143, 583, 1035 |
| 11 | Pattern 6: LCS derivatives | 72, 1092, 516 |
| 12 | Pattern 7: String DP | 139, 5, 647 |
| 13 | Pattern 7: Hard string DP | 10, 132, 44 |
| 14 | Review Week 2 | Re-solve 4 hardest |

### Week 3 — 2D and Advanced DP (Days 15-21)

| Day | Focus | Problems to Solve |
|---|---|---|
| 15 | Pattern 2: 2D DP | 62, 97, 115 |
| 16 | Pattern 2: Advanced 2D | 1312, 712, 1143 |
| 17 | Pattern 9: Interval DP | 312, 1039 |
| 18 | Pattern 9: Advanced interval | 1000, 664, 1547 |
| 19 | Pattern 8: Cumulative sum DP | 446, 1262 |
| 20 | Pattern 14: Math DP | 96, 343, 264 |
| 21 | Pattern 13: Tree DP | 337, 543, 124 |

### Week 4 — Level 2 DP + Mock (Days 22-30)

| Day | Focus | Problems to Solve |
|---|---|---|
| 22 | Pattern 11: Bitmask DP | 847, 2305 |
| 23 | Pattern 11: Hard bitmask | 943, 1986, 2172 |
| 24 | Pattern 12: Digit DP | 357, 2376, 600 |
| 25 | Pattern 15: Probability DP | 837, 688 |
| 26 | Pattern 13: Advanced tree DP | 968, 979, 2246 |
| 27 | Mock Interview Day 1 | Random 5 (all patterns) |
| 28 | Mock Interview Day 2 | 3 mediums + 1 hard |
| 29 | Weak pattern reinforcement | Fill gaps from mocks |
| 30 | Final review | Re-solve 10 hardest |

---

## Top 30 Must Solve Interview Problems

| Priority | # | Problem | Pattern | Difficulty |
|---|---|---|---|---|
| 🔥🔥🔥 | 53 | Maximum Subarray | P10 | Medium |
| 🔥🔥🔥 | 70 | Climbing Stairs | P1 | Easy |
| 🔥🔥🔥 | 198 | House Robber | P1 | Medium |
| 🔥🔥🔥 | 300 | Longest Increasing Subsequence | P5 | Medium |
| 🔥🔥🔥 | 322 | Coin Change | P4 | Medium |
| 🔥🔥🔥 | 416 | Partition Equal Subset Sum | P4 | Medium |
| 🔥🔥🔥 | 1143 | Longest Common Subsequence | P6 | Medium |
| 🔥🔥🔥 | 72 | Edit Distance | P6 | Hard |
| 🔥🔥🔥 | 139 | Word Break | P7 | Medium |
| 🔥🔥🔥 | 312 | Burst Balloons | P9 | Hard |
| 🔥🔥 | 91 | Decode Ways | P1 | Medium |
| 🔥🔥 | 64 | Minimum Path Sum | P3 | Medium |
| 🔥🔥 | 152 | Maximum Product Subarray | P10 | Medium |
| 🔥🔥 | 354 | Russian Doll Envelopes | P5 | Hard |
| 🔥🔥 | 518 | Coin Change II | P4 | Medium |
| 🔥🔥 | 337 | House Robber III | P13 | Medium |
| 🔥🔥 | 5 | Longest Palindromic Substring | P7 | Medium |
| 🔥🔥 | 494 | Target Sum | P4 | Medium |
| 🔥🔥 | 221 | Maximal Square | P3 | Medium |
| 🔥🔥 | 132 | Palindrome Partitioning II | P7 | Hard |
| 🔥🔥 | 96 | Unique Binary Search Trees | P14 | Medium |
| 🔥🔥 | 847 | Shortest Path Visiting All Nodes | P11 | Hard |
| 🔥 | 124 | Binary Tree Maximum Path Sum | P13 | Hard |
| 🔥 | 213 | House Robber II | P1 | Medium |
| 🔥 | 516 | Longest Palindromic Subsequence | P6 | Medium |
| 🔥 | 968 | Binary Tree Cameras | P13 | Hard |
| 🔥 | 1049 | Last Stone Weight II | P4 | Medium |
| 🔥 | 2376 | Count Special Integers | P12 | Medium |
| 🔥 | 837 | New 21 Game | P15 | Medium |
| 🔥 | 1000 | Minimum Cost to Merge Stones | P9 | Hard |

---

## Hybrid Decision Guide

| Combination | Rule | Example |
|---|---|---|
| P1 vs P4 | P1 if no capacity constraint; P4 if selecting items within a weight/sum limit | 70 vs 416 |
| P4 vs P5 | P4 if selecting items with constraint; P5 if finding longest increasing order | 322 vs 300 |
| P5 vs P6 | P5 for single sequence increasing; P6 for two sequences common | 300 vs 1143 |
| P6 vs P7 | P6 if two strings compared; P7 if single string with substrings | 1143 vs 139 |
| P2 vs P3 | P2 if two sequences; P3 if a 2D grid with movement | 1143 vs 64 |
| P9 vs P2 | P9 if splitting ONE sequence into parts; P2 if comparing TWO sequences | 312 vs 1143 |
| P10 vs P1 | P10 if contiguous subarray sum/product; P1 if general subsequence | 53 vs 300 |
| P11 vs P4 | P11 if tracking WHICH items used (set); P4 if tracking HOW MANY used (count) | 847 vs 416 |
| P13 vs P2 | P13 if input is a tree; P2 if input is two flat sequences | 337 vs 1143 |
| P12 vs P1 | P12 if counting integers with digit constraints; P1 if standard array DP | 2376 vs 91 |
| P14 vs P1 | P14 if recurrence has mathematical structure (Catalan, Fibonacci); P1 if plain sequence | 96 vs 70 |
| P15 vs P2 | P15 if values are probabilities (0 to 1); P2 if values are counts or costs | 837 vs 62 |

---

## Quick Reference — Common Mistakes

| Mistake | Correct Approach |
|---|---|
| Knapsack 0/1: iterating capacity forward | Iterate BACKWARDS for 0/1 knapsack; FORWARDS for unbounded |
| LIS: using lower_bound for non-strict increasing | Use lower_bound for strict increasing; upper_bound for non-strict (>=) |
| LCS: forgetting to initialize dp[0][j] = dp[i][0] = 0 | Base cases are 0 (empty prefix LCS = 0) — already handled by vector init |
| Grid DP: forgetting boundary conditions | Handle i==0 and j==0 separately or pad with extra row/col |
| Interval DP: not iterating by length | Must iterate len from 2 to n; direct index iteration gives wrong order |
| Bitmask DP: wrong initial mask | Start with mask = 1<<startNode, not mask = 0 |
| Digit DP: not resetting memo for tight vs non-tight | Always memoize on (pos, tight, state) — tight is part of the state |
| Kadane: not handling all-negative array | Initialize maxSum = nums[0], not 0 — "empty subarray" not always valid |
| Tree DP: forgetting to return both states | Return pair/struct {take, skip} — parent needs BOTH to decide |
| Probability DP: using int instead of double | Always use double/long double for probability DP values |
| 2D DP space: copying wrong previous row | When optimizing to 1D, process j in correct order (left-to-right or right-to-left) |
| Word Break: not handling empty string base case | dp[0] = true is essential — empty prefix is always breakable |

---

*Guide compiled from 300+ LeetCode DP problems, mapped to 15 universal patterns.*
*Covers all categories from the curriculum: Linear DP · 2D DP · Grid DP · Knapsack · LIS · LCS · String DP · Cumulative Sum · Matrix Chain · Kadane · Bitmask DP · Digit DP · Tree DP · Math DP · Probability DP.*
*Master these patterns and you will solve 95%+ of DP questions in any technical interview.*
