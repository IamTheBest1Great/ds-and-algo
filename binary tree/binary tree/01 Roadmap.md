# 🌳 Binary Tree Mastery Guide — 95% Interview Coverage

> **Goal**: Solve 95% of all tree interview questions with pattern recognition, not memorization.
> **Method**: 11 patterns → recognition flowchart → templates → curated problem set.

---

## 📌 Table of Contents

1. [Pattern Recognition Flowchart](#pattern-recognition-flowchart)
2. [Pattern 1 — Traversal Only](#pattern-1--traversal-only-dfs--bfs-no-state)
3. [Pattern 2 — Height / Subtree DP](#pattern-2--height--subtree-dp)
4. [Pattern 3A — Root → Leaf Paths](#pattern-3a--root--leaf-paths)
5. [Pattern 3B — Any → Any Path](#pattern-3b--any--any-path-lca--turning-point)
6. [Pattern 3C — Counting Paths](#pattern-3c--counting-paths)
7. [Pattern 4A — Level-wise Logic (BFS)](#pattern-4a--level-wise-logic-bfs)
8. [Pattern 4B — Distance / Time / Propagation](#pattern-4b--distance--time--propagation)
9. [Pattern 5 — Horizontal / Coordinate Position](#pattern-5--horizontal--coordinate-position)
10. [Pattern 6 — Structural Change / Mutation](#pattern-6--structural-change--mutation)
11. [Pattern 7 — Construction](#pattern-7--construction)
12. [Pattern 8 — Validation](#pattern-8--validation)
13. [Pattern 9 — BST Ordering](#pattern-9--ordering--bst-logic)
14. [Pattern 10 — N-Ary / General Tree](#pattern-10--n-ary--general-tree)
15. [Pattern 11 — Complex Tree DP / Games](#pattern-11--complex-tree-dp--games)
16. [30-Day Mastery Roadmap](#30-day-mastery-roadmap)
17. [Hybrid Decision Guide](#hybrid-decision-guide)

---

## Pattern Recognition Flowchart

```
START — Read the problem statement
         |
         ▼
Does the problem ONLY ask to visit / print / compare nodes?
(No subtree dependency, no accumulation, no state carried)
         |
        YES ──────────────────────────► Pattern 1: Traversal Only
         |
         ▼
Does each node's answer depend ONLY on its children?
(Height, diameter, subtree sum, balance)
         |
        YES ──────────────────────────► Pattern 2: Height / Subtree DP
         |
         ▼
Is the problem about PATHS?
         |
         ├─ Path starts at ROOT, ends at LEAF? ────────────► Pattern 3A: Root → Leaf
         │
         ├─ Path can start/end ANYWHERE? ─────────────────► Pattern 3B: Any → Any
         │
         └─ COUNT number of paths satisfying condition? ──► Pattern 3C: Counting Paths
         |
         ▼
Is logic applied LEVEL BY LEVEL?
(BFS, width, zigzag, next pointers)
         |
        YES ──────────────────────────► Pattern 4A: Level-wise Logic
         |
         ▼
Is the problem about DISTANCE / TIME / SPREAD from a node?
(Distance K, infection, burn time, BFS from non-root)
         |
        YES ──────────────────────────► Pattern 4B: Distance / Time
         |
         ▼
Are nodes positioned by COLUMN / ROW / BOUNDARY?
(Vertical order, top view, boundary traversal)
         |
        YES ──────────────────────────► Pattern 5: Horizontal / Coordinate
         |
         ▼
Does the problem MODIFY the tree structure?
(Delete nodes, flatten, invert, add rows, prune)
         |
        YES ──────────────────────────► Pattern 6: Structural Change
         |
         ▼
Does the problem BUILD a new tree?
(From traversals, string, rules, descriptions)
         |
        YES ──────────────────────────► Pattern 7: Construction
         |
         ▼
Does the problem CHECK VALIDITY of a property?
(Is it a valid BST? Complete? Balanced?)
         |
        YES ──────────────────────────► Pattern 8: Validation
         |
         ▼
Is the tree a BST and uses the ORDERING / SORTED property?
(Inorder sorted, kth smallest, successor, range queries)
         |
        YES ──────────────────────────► Pattern 9: BST Ordering
         |
         ▼
Does each node have MORE THAN 2 children? (N-ary)
         |
        YES ──────────────────────────► Pattern 10: N-Ary Tree
         |
         ▼
Does each node need MULTIPLE STATES?
(Take/skip, cameras, game theory, coin distribution)
         |
        YES ──────────────────────────► Pattern 11: Complex Tree DP
         |
         ▼
        END
```

### 10-Second Interview Shortcut

| Signal in problem | Pattern |
|---|---|
| Visit / print / collect only | P1 — Traversal |
| Height, diameter, balance | P2 — Subtree DP |
| Root-to-leaf constraint | P3A — Root → Leaf |
| Arbitrary start/end path | P3B — Any → Any |
| Count paths with condition | P3C — Count Paths |
| Level-by-level / BFS / width | P4A — Level-wise |
| Distance K / time / infection | P4B — Distance |
| Vertical / boundary / column | P5 — Coordinate |
| Delete / invert / flatten | P6 — Mutation |
| Build from traversals / rules | P7 — Construction |
| Validate BST / complete tree | P8 — Validation |
| Kth smallest / successor / range | P9 — BST Order |
| N children per node | P10 — N-Ary |
| Take/skip / states per node | P11 — Tree DP |

---

## Pattern 1 — Traversal Only (DFS / BFS, no state)

### 📖 Notes & Theory

**What it is**: The simplest category. You visit every node and either collect values, compare structures, or compute something that does NOT require knowing what the children returned first. No "bottom-up" computation. The traversal itself is the answer.

**How to identify**:
- Ask yourself: "Do I need the child's result before processing the parent?" If **NO**, it's Pattern 1.
- Keywords: "print all paths", "mirror", "same structure", "collect leaves", "visit every node"
- No global variable being updated by combining left + right subtree results

**Algorithm skeleton**:
```cpp
// DFS Template
void dfs(TreeNode* node) {
    if (!node) return;
    // process node (preorder)
    dfs(node->left);
    dfs(node->right);
    // or process here (postorder)
}

// BFS Template
void bfs(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front(); q.pop();
        // process node
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

**Key insight**: The order of visiting (pre/in/post) matters for the output but not for the logic. Pick the order based on what you want to collect.

---

### ✅ Must-Solve Problems (Starred = High Interview Priority)

| # | Problem | Difficulty | Why Important |
|---|---|---|---|
| ⭐ 94 | Binary Tree Inorder Traversal | Easy | Foundation — iterative stack version is asked |
| ⭐ 101 | Symmetric Tree | Easy | Classic mirror recursion |
| ⭐ 199 | Binary Tree Right Side View | Medium | BFS with level tracking |
| ⭐ 226 | Invert Binary Tree | Easy | Most asked easy tree problem |
| 100 | Same Tree | Easy | Structure comparison |
| 257 | Binary Tree Paths | Easy | DFS with path string |
| 572 | Subtree of Another Tree | Easy | Nested DFS |
| 617 | Merge Two Binary Trees | Easy | Two-pointer tree traversal |
| 993 | Cousins in Binary Tree | Easy | Track parent + depth |
| 2331 | Evaluate Boolean Binary Tree | Easy | Post-order evaluation |

### 📚 All Problems in Pattern 1

- 94 Binary Tree Inorder Traversal
- 100 Same Tree
- 101 Symmetric Tree
- 144 Binary Tree Preorder Traversal
- 145 Binary Tree Postorder Traversal
- 199 Binary Tree Right Side View
- 226 Invert Binary Tree
- 257 Binary Tree Paths
- 341 Flatten Nested List Iterator
- 404 Sum of Left Leaves
- 572 Subtree of Another Tree
- 589 N-ary Tree Preorder Traversal
- 590 N-ary Tree Postorder Traversal
- 606 Construct String from Binary Tree
- 617 Merge Two Binary Trees
- 637 Average of Levels in Binary Tree
- 671 Second Minimum Node In a Binary Tree
- 872 Leaf-Similar Trees
- 951 Flip Equivalent Binary Trees
- 965 Univalued Binary Tree
- 993 Cousins in Binary Tree
- 1315 Sum of Nodes with Even-Valued Grandparent
- 1379 Find a Corresponding Node in a Clone
- 1448 Count Good Nodes in Binary Tree
- 1469 Find All The Lonely Nodes
- 1485 Clone Binary Tree With Random Pointer
- 1506 Find Root of N-Ary Tree
- 2236 Root Equals Sum of Children
- 2331 Evaluate Boolean Binary Tree
- 2368 Reachable Nodes With Restrictions
- 3327 Check if DFS Strings Are Palindromes

---

## Pattern 2 — Height / Subtree DP

### 📖 Notes & Theory

**What it is**: Bottom-up aggregation. Each call to `dfs(node)` returns a value computed from its left and right children's return values. This is where real tree DP begins.

**How to identify**:
- "Maximum/minimum depth", "diameter", "balance", "subtree sum"
- You CANNOT answer for a node without first knowing children's results
- The answer is either: returned directly, or updated via a global variable

**Algorithm skeleton**:
```cpp
int dfs(TreeNode* node) {
    if (!node) return 0; // base case

    int left = dfs(node->left);   // get left subtree result
    int right = dfs(node->right); // get right subtree result

    // update global answer if needed
    ans = max(ans, left + right + something);

    // return value to parent
    return 1 + max(left, right);
}
```

**Two return styles**:
1. **Single value**: Return height, sum, count → parent uses it directly
2. **Pair/struct**: Return multiple values (e.g., `{isBalanced, height}`) when you need more info

**Common trick**: Use `-1` or `INT_MIN` as a sentinel to propagate "invalid" states up (e.g., unbalanced subtree).

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 104 | Maximum Depth of Binary Tree | Easy | Simplest subtree DP |
| ⭐ 110 | Balanced Binary Tree | Easy | Return height or -1 |
| ⭐ 543 | Diameter of Binary Tree | Easy | Global ans = left + right |
| ⭐ 687 | Longest Univalue Path | Medium | Global ans across branches |
| ⭐ 1373 | Maximum Sum BST in Binary Tree | Hard | Complex multi-value return |
| 111 | Minimum Depth of Binary Tree | Easy | Edge case: leaf definition |
| 563 | Binary Tree Tilt | Easy | Bottom-up sum |
| 1245 | Tree Diameter | Medium | Graph version of 543 |
| 1302 | Deepest Leaves Sum | Medium | Depth + sum combination |
| 2049 | Count Nodes With Highest Score | Medium | Subtree size DP |

### 📚 All Problems in Pattern 2

- 104 Maximum Depth of Binary Tree
- 110 Balanced Binary Tree
- 111 Minimum Depth of Binary Tree
- 250 Count Univalue Subtrees
- 298 Binary Tree Longest Consecutive Sequence
- 333 Largest BST Subtree
- 366 Find Leaves of Binary Tree
- 508 Most Frequent Subtree Sum
- 543 Diameter of Binary Tree
- 559 Maximum Depth of N-ary Tree
- 563 Binary Tree Tilt
- 652 Find Duplicate Subtrees
- 663 Equal Tree Partition
- 687 Longest Univalue Path
- 1120 Maximum Average Subtree
- 1245 Tree Diameter
- 1273 Delete Tree Nodes
- 1302 Deepest Leaves Sum
- 1373 Maximum Sum BST in Binary Tree
- 1519 Number of Nodes in Sub-Tree With Same Label
- 1522 Diameter of N-Ary Tree
- 1973 Count Nodes Equal to Sum of Descendants
- 2049 Count Nodes With the Highest Score
- 2265 Count Nodes Equal to Average of Subtree
- 2458 Height of Binary Tree After Subtree Removal Queries
- 2477 Minimum Fuel Cost to Report to the Capital
- 2583 Kth Largest Sum in a Binary Tree
- 2773 Height of Special Binary Tree
- 3157 Find the Level of Tree with Minimum Sum
- 3203 Find Minimum Diameter After Merging Two Trees
- 3249 Count the Number of Good Nodes
- 3319 K-th Largest Perfect Subtree Size in Binary Tree
- 3575 Maximum Good Subtree Score
- 3787 Find Diameter Endpoints of a Tree

---

## Pattern 3A — Root → Leaf Paths

### 📖 Notes & Theory

**What it is**: You carry a **state** as you go **downward** from root to leaf. The state accumulates (sum, XOR, string, max). At the leaf, you check if the accumulated state satisfies the condition.

**How to identify**:
- "Root to leaf path", "path sum equals target", "all paths from root"
- State is built TOP-DOWN (not aggregated bottom-up)
- You typically check at leaf nodes: `!node->left && !node->right`
- Keywords: "from root", "root-to-leaf", "each path"

**Algorithm skeleton**:
```cpp
void dfs(TreeNode* node, int currentSum, int target) {
    if (!node) return;

    currentSum += node->val; // accumulate downward

    if (!node->left && !node->right) {
        // LEAF: check condition
        if (currentSum == target) ans++;
        return;
    }

    dfs(node->left, currentSum, target);
    dfs(node->right, currentSum, target);
}
```

**Backtracking variant** (for collecting paths):
```cpp
void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& result) {
    if (!node) return;
    path.push_back(node->val);
    if (!node->left && !node->right) result.push_back(path);
    dfs(node->left, path, result);
    dfs(node->right, path, result);
    path.pop_back(); // backtrack
}
```

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 112 | Path Sum | Easy | Simplest root-leaf check |
| ⭐ 113 | Path Sum II | Medium | Backtracking path collection |
| ⭐ 1457 | Pseudo-Palindromic Paths | Medium | XOR bitmask trick |
| 129 | Sum Root to Leaf Numbers | Medium | Accumulate as number |
| 1022 | Sum of Root to Leaf Binary Numbers | Easy | Binary accumulation |
| 1080 | Insufficient Nodes in Root to Leaf Paths | Medium | Prune while traversing |
| 1026 | Maximum Difference Between Node and Ancestor | Medium | Track min/max downward |
| 988 | Smallest String Starting From Leaf | Medium | Compare strings at leaf |

### 📚 All Problems in Pattern 3A

- 112 Path Sum
- 113 Path Sum II
- 129 Sum Root to Leaf Numbers
- 257 Binary Tree Paths
- 988 Smallest String Starting From Leaf
- 1022 Sum of Root To Leaf Binary Numbers
- 1026 Maximum Difference Between Node and Ancestor
- 1080 Insufficient Nodes in Root to Leaf Paths
- 1104 Path In Zigzag Labelled Binary Tree
- 1430 Check If a String Is a Valid Sequence from Root to Leaves Path
- 1448 Count Good Nodes in Binary Tree
- 1457 Pseudo-Palindromic Paths in a Binary Tree

---

## Pattern 3B — Any → Any Path (LCA / Turning Point)

### 📖 Notes & Theory

**What it is**: The hardest path pattern. A path can go from any node to any node, including paths that go UP through the tree (using a common ancestor as a "turning point"). The key insight is that the path's highest node is always its LCA.

**How to identify**:
- "Maximum path sum", "longest path", "distance between two nodes"
- The path does NOT have to start at root or end at leaf
- "Lowest Common Ancestor" problems
- Keywords: "any node to any node", "path between two nodes", "maximum path"

**Core insight — The "turning point" pattern**:
```
      root (turning point / LCA)
     /    \
 left      right
```
The max path through `root` = `left_gain + root->val + right_gain`

**Algorithm skeleton**:
```cpp
int ans = INT_MIN;

int dfs(TreeNode* node) {
    if (!node) return 0;

    // Only take positive contributions
    int left = max(0, dfs(node->left));
    int right = max(0, dfs(node->right));

    // Update global answer: path that TURNS at this node
    ans = max(ans, left + node->val + right);

    // Return to parent: can only go one direction
    return node->val + max(left, right);
}
```

**LCA Template**:
```cpp
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    auto left = lca(root->left, p, q);
    auto right = lca(root->right, p, q);
    if (left && right) return root; // p and q on opposite sides
    return left ? left : right;
}
```

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 124 | Binary Tree Maximum Path Sum | Hard | Turning point DP |
| ⭐ 236 | Lowest Common Ancestor of BT | Medium | Classic LCA |
| ⭐ 1372 | Longest ZigZag Path | Medium | Two-state per direction |
| ⭐ 865 | Smallest Subtree with All Deepest Nodes | Medium | LCA of deepest leaves |
| 1123 | LCA of Deepest Leaves | Medium | Same as 865 |
| 1740 | Find Distance in a Binary Tree | Medium | LCA + depth |
| 2096 | Step-By-Step Directions Between Nodes | Medium | LCA + path reconstruction |
| 2467 | Most Profitable Path in a Tree | Medium | Two-player path |
| 742 | Closest Leaf in Binary Tree | Medium | BFS after conversion |
| 549 | Binary Tree Longest Consecutive Sequence II | Medium | Two-direction DP |

### 📚 All Problems in Pattern 3B

- 124 Binary Tree Maximum Path Sum
- 236 Lowest Common Ancestor of a Binary Tree
- 298 Binary Tree Longest Consecutive Sequence
- 549 Binary Tree Longest Consecutive Sequence II
- 742 Closest Leaf in a Binary Tree
- 865 Smallest Subtree with all the Deepest Nodes
- 1123 Lowest Common Ancestor of Deepest Leaves
- 1372 Longest ZigZag Path in a Binary Tree
- 1530 Number of Good Leaf Nodes Pairs
- 1644 Lowest Common Ancestor of a Binary Tree II
- 1650 Lowest Common Ancestor of a Binary Tree III
- 1676 Lowest Common Ancestor of a Binary Tree IV
- 1740 Find Distance in a Binary Tree
- 2096 Step-By-Step Directions From a Binary Tree Node to Another
- 2246 Longest Path With Different Adjacent Characters
- 2421 Number of Good Paths
- 2467 Most Profitable Path in a Tree
- 3425 Longest Special Path
- 3486 Longest Special Path II

---

## Pattern 3C — Counting Paths

### 📖 Notes & Theory

**What it is**: Count the number of paths (not necessarily root-to-leaf) that satisfy a condition (usually a sum equals target). Uses **prefix sums + hashmap** to avoid O(n²) brute force.

**How to identify**:
- "Count paths where sum = target"
- "Number of paths satisfying X"
- Keywords: "count", "how many paths"

**Algorithm skeleton** (prefix sum approach):
```cpp
unordered_map<long long, int> prefixCount;
int ans = 0;

void dfs(TreeNode* node, long long currentSum, int target) {
    if (!node) return;
    currentSum += node->val;

    // Check if any prefix sum makes (currentSum - prefix) == target
    ans += prefixCount[currentSum - target];

    prefixCount[currentSum]++;
    dfs(node->left, currentSum, target);
    dfs(node->right, currentSum, target);
    prefixCount[currentSum]--; // backtrack (undo for other branches)
}

// Call: prefixCount[0] = 1; dfs(root, 0, targetSum);
```

**Why prefix[0] = 1?** To handle the case where the entire path from root is a valid path.

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 437 | Path Sum III | Medium | Prefix sum + hashmap |
| 666 | Path Sum IV | Medium | Array-encoded tree |
| 2791 | Count Paths That Can Form a Palindrome | Hard | Bitmask + LCA |
| 2867 | Count Valid Paths in a Tree | Hard | Prime sieve + DFS |

### 📚 All Problems in Pattern 3C

- 437 Path Sum III
- 666 Path Sum IV
- 2791 Count Paths That Can Form a Palindrome in a Tree
- 2867 Count Valid Paths in a Tree

---

## Pattern 4A — Level-wise Logic (BFS)

### 📖 Notes & Theory

**What it is**: Process the tree level by level. BFS with a queue where you snapshot the queue size at the beginning of each level to know when one level ends and the next begins.

**How to identify**:
- "Level order", "zigzag", "average per level", "rightmost node"
- "Next right pointer", "maximum width"
- Keywords: "level", "row", "layer", "breadth"

**Algorithm skeleton**:
```cpp
void bfs(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // snapshot current level count

        for (int i = 0; i < levelSize; i++) {
            auto node = q.front(); q.pop();
            // process node at current level

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        // all nodes at this level processed
    }
}
```

**Width trick (662)**: Use coordinates `(node, col)` in the queue. Width = rightmost_col - leftmost_col + 1 at each level. Use `unsigned int` or normalize to avoid overflow.

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 102 | Binary Tree Level Order Traversal | Medium | Foundation BFS |
| ⭐ 103 | Binary Tree Zigzag Level Order | Medium | Deque or reverse alternate |
| ⭐ 199 | Binary Tree Right Side View | Medium | Last node per level |
| ⭐ 662 | Maximum Width of Binary Tree | Medium | Column indexing trick |
| ⭐ 1161 | Maximum Level Sum | Medium | Sum per level, find max |
| 107 | Level Order Traversal II | Medium | Reverse of 102 |
| 116 | Populating Next Right Pointers | Medium | O(1) space using level links |
| 513 | Find Bottom Left Tree Value | Medium | First node of last level |
| 515 | Find Largest Value in Each Row | Medium | Max per level |
| 2471 | Sort Binary Tree by Level | Medium | Sort each level |

### 📚 All Problems in Pattern 4A

- 102 Binary Tree Level Order Traversal
- 103 Binary Tree Zigzag Level Order Traversal
- 107 Binary Tree Level Order Traversal II
- 116 Populating Next Right Pointers in Each Node
- 117 Populating Next Right Pointers in Each Node II
- 199 Binary Tree Right Side View
- 513 Find Bottom Left Tree Value
- 515 Find Largest Value in Each Tree Row
- 637 Average of Levels in Binary Tree
- 662 Maximum Width of Binary Tree
- 919 Complete Binary Tree Inserter
- 1161 Maximum Level Sum of a Binary Tree
- 1602 Find Nearest Right Node in Binary Tree
- 1609 Even Odd Tree
- 2471 Minimum Number of Operations to Sort a Binary Tree by Level
- 2583 Kth Largest Sum in a Binary Tree
- 2641 Cousins in Binary Tree II
- 3157 Find the Level of Tree with Minimum Sum

---

## Pattern 4B — Distance / Time / Propagation

### 📖 Notes & Theory

**What it is**: BFS from a specific node (not necessarily root). Because trees don't have "upward" edges, you first convert the tree into an **undirected graph** (or build parent pointers), then run BFS from the target node.

**How to identify**:
- "All nodes at distance K", "time to infect", "which nodes reachable in T steps"
- The source of BFS is NOT the root
- Keywords: "spread", "infect", "distance from node X", "time needed"

**Algorithm skeleton**:
```cpp
// Step 1: Build parent map
void buildParent(TreeNode* node, TreeNode* parent,
                 unordered_map<TreeNode*, TreeNode*>& parentMap) {
    if (!node) return;
    parentMap[node] = parent;
    buildParent(node->left, node, parentMap);
    buildParent(node->right, node, parentMap);
}

// Step 2: BFS from target node in all directions
int bfsFromTarget(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parentMap) {
    unordered_set<TreeNode*> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited.insert(target);
    int time = 0;

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto node = q.front(); q.pop();
            // check left, right, parent — all 3 directions
            for (auto neighbor : {node->left, node->right, parentMap[node]}) {
                if (neighbor && !visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        time++;
    }
    return time - 1;
}
```

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 863 | All Nodes Distance K in Binary Tree | Medium | Parent map + BFS |
| ⭐ 2385 | Amount of Time for BT to Be Infected | Medium | Parent map + BFS timing |
| ⭐ 1376 | Time Needed to Inform Employees | Medium | DFS on N-ary / graph |
| 1443 | Min Time to Collect All Apples | Medium | DFS with backtracking cost |
| 1740 | Find Distance in a Binary Tree | Medium | LCA-based or BFS |
| 582 | Kill Process | Medium | Build adjacency + BFS |
| 3241 | Time Taken to Mark All Nodes | Hard | Two DFS passes |

### 📚 All Problems in Pattern 4B

- 582 Kill Process
- 742 Closest Leaf in a Binary Tree
- 863 All Nodes Distance K in Binary Tree
- 1376 Time Needed to Inform All Employees
- 1377 Frog Position After T Seconds
- 1443 Minimum Time to Collect All Apples in a Tree
- 1740 Find Distance in a Binary Tree
- 2277 Closest Node to Path in Tree
- 2385 Amount of Time for Binary Tree to Be Infected
- 2603 Collect Coins in a Tree
- 3241 Time Taken to Mark All Nodes

---

## Pattern 5 — Horizontal / Coordinate Position

### 📖 Notes & Theory

**What it is**: Assign each node a `(row, col)` coordinate. Root is at `(0, 0)`. Left child: `col - 1`. Right child: `col + 1`. Group nodes by column or boundary membership.

**How to identify**:
- "Vertical order traversal", "top view", "bottom view", "boundary"
- "Print by column"
- Keywords: "vertical", "horizontal", "boundary", "top/bottom view"

**Algorithm skeleton**:
```cpp
map<int, vector<pair<int,int>>> colMap; // col → [(row, val)]

void dfs(TreeNode* node, int row, int col) {
    if (!node) return;
    colMap[col].push_back({row, node->val});
    dfs(node->left, row + 1, col - 1);
    dfs(node->right, row + 1, col + 1);
}
// Then process colMap sorted by col (map auto-sorts)
// For 987: sort each group by (row, val)
```

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 314 | Binary Tree Vertical Order Traversal | Medium | BFS with col tracking |
| ⭐ 987 | Vertical Order Traversal of BT | Hard | DFS + sort by (row, col, val) |
| 545 | Boundary of Binary Tree | Medium | Left boundary + leaves + right boundary |
| 655 | Print Binary Tree | Medium | Row/col grid construction |

### 📚 All Problems in Pattern 5

- 314 Binary Tree Vertical Order Traversal
- 545 Boundary of Binary Tree
- 655 Print Binary Tree
- 987 Vertical Order Traversal of a Binary Tree

---

## Pattern 6 — Structural Change / Mutation

### 📖 Notes & Theory

**What it is**: You physically rewire, delete, or rearrange the tree's pointers. The tree structure itself changes as output.

**How to identify**:
- "Flatten", "invert", "delete nodes", "prune", "add row"
- The OUTPUT is a modified tree
- Keywords: "in-place", "restructure", "remove", "flatten", "reverse"

**Key insight — Morris traversal for O(1) space flattening**:
For flatten (114), the trick is: while processing a node, find the **rightmost node of its left subtree**, make it point to the current node's right child, then move the left subtree to the right.

**Algorithm skeleton**:
```cpp
TreeNode* dfs(TreeNode* node) {
    if (!node) return nullptr;

    node->left = dfs(node->left);
    node->right = dfs(node->right);

    // rewire pointers here
    // example: prune if subtree doesn't satisfy condition
    if (shouldRemove(node)) return nullptr;

    return node; // return modified subtree
}
```

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 114 | Flatten Binary Tree to Linked List | Medium | Morris / recursion rewire |
| ⭐ 1110 | Delete Nodes And Return Forest | Medium | Return null to delete |
| 226 | Invert Binary Tree | Easy | Swap left/right |
| 814 | Binary Tree Pruning | Medium | Prune false subtrees |
| 623 | Add One Row to Tree | Medium | BFS to find level |
| 1325 | Delete Leaves With a Given Value | Medium | Post-order delete |
| 2415 | Reverse Odd Levels of Binary Tree | Medium | BFS level-by-level swap |
| 998 | Maximum Binary Tree II | Medium | Insert in correct position |

### 📚 All Problems in Pattern 6

- 114 Flatten Binary Tree to Linked List
- 156 Binary Tree Upside Down
- 226 Invert Binary Tree
- 450 Delete Node in a BST
- 538 Convert BST to Greater Tree
- 623 Add One Row to Tree
- 669 Trim a BST
- 701 Insert into a BST
- 776 Split BST
- 814 Binary Tree Pruning
- 897 Increasing Order Search Tree
- 998 Maximum Binary Tree II
- 1038 BST to Greater Sum Tree
- 1080 Insufficient Nodes in Root to Leaf Paths
- 1110 Delete Nodes And Return Forest
- 1325 Delete Leaves With a Given Value
- 1382 Balance a BST
- 1516 Move Sub-Tree of N-Ary Tree
- 1660 Correct a Binary Tree
- 1666 Change the Root of a Binary Tree
- 1993 Operations on Tree
- 2415 Reverse Odd Levels of Binary Tree
- 971 Flip Binary Tree To Match Preorder Traversal
- 99 Recover Binary Search Tree

---

## Pattern 7 — Construction

### 📖 Notes & Theory

**What it is**: Build a tree from some representation — two traversals, a sorted array, a string, or a set of rules. Recursion with index bounds is the foundation.

**How to identify**:
- "Construct binary tree from...", "serialize/deserialize", "convert sorted array to BST"
- You're given traversal arrays, a string, or a description
- Keywords: "build", "construct", "serialize", "deserialize", "convert"

**Key formulas for traversal-based construction**:
- **Preorder + Inorder → Tree**: Root = `preorder[0]`. Find root in inorder to split left/right subtrees. Use a hashmap for O(1) inorder lookups.
- **Postorder + Inorder → Tree**: Root = `postorder[last]`. Same split logic.

**Algorithm skeleton (Preorder + Inorder)**:
```cpp
unordered_map<int, int> inorderIndex; // val → index in inorder

TreeNode* build(vector<int>& pre, int preL, int preR,
                vector<int>& in, int inL, int inR) {
    if (preL > preR) return nullptr;
    int rootVal = pre[preL];
    int mid = inorderIndex[rootVal]; // split point in inorder
    int leftSize = mid - inL;

    TreeNode* root = new TreeNode(rootVal);
    root->left = build(pre, preL+1, preL+leftSize, in, inL, mid-1);
    root->right = build(pre, preL+leftSize+1, preR, in, mid+1, inR);
    return root;
}
```

**Serialize/Deserialize (297)**:
```cpp
// Serialize: preorder with null markers "1,2,null,null,3,null,null"
// Deserialize: parse tokens, recursively build
```

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 105 | Construct Tree from Preorder & Inorder | Medium | Hashmap + index bounds |
| ⭐ 106 | Construct Tree from Inorder & Postorder | Medium | Same as 105, reversed |
| ⭐ 297 | Serialize and Deserialize Binary Tree | Hard | String encoding/decoding |
| ⭐ 654 | Maximum Binary Tree | Medium | Recursive max-split |
| ⭐ 894 | All Possible Full Binary Trees | Medium | Memoized recursion |
| 108 | Convert Sorted Array to BST | Easy | Binary search midpoint |
| 889 | Construct from Preorder & Postorder | Medium | Tricky — multiple answers |
| 1008 | Construct BST from Preorder | Medium | BST property to split |
| 1028 | Recover Tree from Preorder | Hard | Parse indentation depth |
| 2196 | Create Binary Tree From Descriptions | Medium | HashMap of nodes |

### 📚 All Problems in Pattern 7

- 105 Construct Tree from Preorder & Inorder
- 106 Construct Tree from Inorder & Postorder
- 108 Convert Sorted Array to BST
- 109 Convert Sorted List to BST
- 297 Serialize and Deserialize Binary Tree
- 427 Construct Quad Tree
- 428 Serialize and Deserialize N-ary Tree
- 431 Encode N-ary Tree to Binary Tree
- 536 Construct Binary Tree from String
- 654 Maximum Binary Tree
- 889 Construct Tree from Preorder & Postorder
- 894 All Possible Full Binary Trees
- 1008 Construct BST from Preorder
- 1028 Recover Tree from Preorder Traversal
- 1597 Build Binary Expression Tree From Infix Expression
- 1628 Design an Expression Tree With Evaluate Function
- 1932 Merge BSTs to Create Single BST
- 2196 Create Binary Tree From Descriptions

---

## Pattern 8 — Validation

### 📖 Notes & Theory

**What it is**: Verify that the tree satisfies a global structural property. Often requires passing down constraints (min/max range for BST) or checking conditions across levels.

**How to identify**:
- "Is it a valid BST?", "is this tree complete?", "verify preorder"
- The OUTPUT is boolean (valid/invalid)
- Keywords: "validate", "verify", "check", "is valid"

**BST validation with range**:
```cpp
bool isValid(TreeNode* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if (node->val <= minVal || node->val >= maxVal) return false;
    return isValid(node->left, minVal, node->val) &&
           isValid(node->right, node->val, maxVal);
}
// Call: isValid(root, LLONG_MIN, LLONG_MAX)
```

**Completeness check (958)**: BFS — once you see a null child, all subsequent nodes must also be null.

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 98 | Validate Binary Search Tree | Medium | Range passing (min/max) |
| ⭐ 958 | Check Completeness of Binary Tree | Medium | BFS null-gap check |
| ⭐ 331 | Verify Preorder Serialization | Medium | Stack/counter trick |
| 110 | Balanced Binary Tree | Easy | Height + balance check |
| 222 | Count Complete Tree Nodes | Easy | BST-style binary search |
| 255 | Verify Preorder Sequence in BST | Medium | Monotonic stack |
| 1361 | Validate Binary Tree Nodes | Medium | Detect cycles + single root |
| 1609 | Even Odd Tree | Medium | Level-by-level parity check |

### 📚 All Problems in Pattern 8

- 98 Validate Binary Search Tree
- 110 Balanced Binary Tree
- 222 Count Complete Tree Nodes
- 255 Verify Preorder Sequence in BST
- 331 Verify Preorder Serialization
- 958 Check Completeness of a Binary Tree
- 1361 Validate Binary Tree Nodes
- 1609 Even Odd Tree
- 2764 Is Array a Preorder of Some Binary Tree

---

## Pattern 9 — Ordering / BST Logic

### 📖 Notes & Theory

**What it is**: Exploit the BST property that **inorder traversal gives sorted output**. Many BST problems reduce to: "do inorder traversal, then apply array logic."

**How to identify**:
- The input is explicitly a BST
- Keywords: "kth smallest", "successor", "range sum", "closest value", "sorted"
- If you replace the BST with a sorted array, does the problem become trivial? → Pattern 9

**Key BST facts**:
- Inorder (left → root → right) = sorted ascending
- Kth smallest = stop at kth node in inorder
- Successor of node N = smallest node > N

**Iterative inorder template** (often asked):
```cpp
stack<TreeNode*> st;
TreeNode* curr = root;
while (curr || !st.empty()) {
    while (curr) { st.push(curr); curr = curr->left; }
    curr = st.top(); st.pop();
    // process curr (kth node, etc.)
    curr = curr->right;
}
```

**BST Search**:
```cpp
TreeNode* search(TreeNode* node, int target) {
    if (!node || node->val == target) return node;
    if (target < node->val) return search(node->left, target);
    return search(node->right, target);
}
```

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 230 | Kth Smallest in BST | Medium | Inorder traversal count |
| ⭐ 235 | LCA of BST | Medium | Exploit BST ranges |
| ⭐ 450 | Delete Node in BST | Medium | Successor replacement |
| ⭐ 653 | Two Sum IV (BST) | Easy | Inorder array + two pointers |
| 270 | Closest BST Value | Easy | Binary search on BST |
| 285 | Inorder Successor in BST | Medium | Smallest node > target |
| 530 | Min Absolute Difference in BST | Easy | Inorder prev tracking |
| 538 | Convert BST to Greater Tree | Medium | Reverse inorder accumulate |
| 700 | Search in BST | Easy | Pure BST property |
| 701 | Insert into BST | Medium | Recursive placement |
| 938 | Range Sum of BST | Easy | Prune branches outside range |
| 1305 | All Elements in Two BSTs | Medium | Merge two inorder sequences |
| 1382 | Balance a BST | Medium | Inorder → sorted → construct |

### 📚 All Problems in Pattern 9

- 230 Kth Smallest in BST
- 235 LCA of BST
- 270 Closest BST Value
- 272 Closest BST Value II
- 285 Inorder Successor in BST
- 426 BST to Sorted Doubly Linked List
- 450 Delete Node in BST
- 501 Find Mode in BST
- 510 Inorder Successor in BST II
- 530 Minimum Absolute Difference in BST
- 538 Convert BST to Greater Tree
- 653 Two Sum IV BST
- 669 Trim a BST
- 700 Search in BST
- 701 Insert into BST
- 776 Split BST
- 783 Min Distance Between BST Nodes
- 897 Increasing Order BST
- 938 Range Sum of BST
- 1038 BST to Greater Sum Tree
- 1214 Two Sum BSTs
- 1305 All Elements in Two BSTs
- 1382 Balance a BST
- 1586 BST Iterator II
- 1902 Depth of BST Given Insertion Order
- 2476 Closest Nodes Queries in BST

---

## Pattern 10 — N-Ary / General Tree

### 📖 Notes & Theory

**What it is**: Trees where each node can have any number of children (stored as a list). The same DFS/BFS patterns apply, but you iterate over `node->children` instead of accessing `.left` and `.right`.

**How to identify**:
- Node has a `children` vector/list
- "N-ary", "general tree", "employee hierarchy"
- Keywords: "children list", "N children", "parent-child relationship"

**Template adaptation**:
```cpp
// Binary tree DFS:  dfs(node->left); dfs(node->right);
// N-ary tree DFS:
void dfs(Node* node) {
    if (!node) return;
    for (auto child : node->children) {
        dfs(child);
    }
}
```

Everything else (BFS, diameter, DP) works identically — just iterate children.

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 429 | N-ary Level Order Traversal | Medium | BFS with children |
| ⭐ 690 | Employee Importance | Medium | DFS on n-ary with hashmap |
| 559 | Maximum Depth of N-ary Tree | Easy | Same as 104 |
| 589 | N-ary Preorder Traversal | Easy | Same as 144 |
| 590 | N-ary Postorder Traversal | Easy | Same as 145 |
| 1522 | Diameter of N-ary Tree | Medium | Same as 543 but n-ary |
| 1490 | Clone N-ary Tree | Medium | Same as clone BT |

### 📚 All Problems in Pattern 10

- 429 N-ary Level Order Traversal
- 559 Maximum Depth of N-ary Tree
- 589 N-ary Preorder Traversal
- 590 N-ary Postorder Traversal
- 690 Employee Importance
- 1490 Clone N-ary Tree
- 1506 Find Root of N-Ary Tree
- 1516 Move Sub-Tree of N-Ary Tree
- 1519 Number of Nodes with Same Label
- 1522 Diameter of N-Ary Tree
- 1600 Throne Inheritance
- 1617 Count Subtrees With Max Distance Between Cities
- 1916 Count Ways to Build Rooms in an Ant Colony

---

## Pattern 11 — Complex Tree DP / Games

### 📖 Notes & Theory

**What it is**: Each node requires **multiple states** to represent different choices or roles. Classic example: house robber (take or skip), cameras (covered or covering), coin distribution.

**How to identify**:
- "Minimum cameras", "maximum profit without adjacent nodes", "distribute coins"
- "Game theory on tree", "choose/not-choose"
- You need to track WHAT STATE each node is in, not just one aggregate value
- Keywords: "cannot select adjacent", "minimize/maximize with constraints"

**General dp[node][state] pattern**:
```cpp
// Example: House Robber III — take (1) or skip (0)
pair<int,int> dfs(TreeNode* node) {
    // returns {skip_value, take_value}
    if (!node) return {0, 0};

    auto [lSkip, lTake] = dfs(node->left);
    auto [rSkip, rTake] = dfs(node->right);

    int skip = max(lSkip, lTake) + max(rSkip, rTake); // children can take or skip
    int take = node->val + lSkip + rSkip;              // if we take, children must skip

    return {skip, take};
}
```

**Camera coverage (968)**:
```
State 0: Node NOT covered
State 1: Node has camera
State 2: Node is covered (by child's camera)
```

**Key insight**: For these problems, think "what does my parent NEED to know about me?" and encode that as the return value.

---

### ✅ Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| ⭐ 337 | House Robber III | Medium | Take/skip DP |
| ⭐ 968 | Binary Tree Cameras | Hard | 3-state DP (hardest pattern 11) |
| ⭐ 979 | Distribute Coins in Binary Tree | Medium | Excess coins flow |
| ⭐ 1339 | Maximum Product of Splitted BT | Medium | Subtree sum split |
| 1145 | Binary Tree Coloring Game | Medium | Subtree size comparison |
| 2581 | Count Number of Possible Root Nodes | Hard | Rerooting DP |
| 2646 | Minimize the Total Price of the Trips | Hard | DP + path counting |
| 2920 | Maximum Points After Collecting Coins | Hard | State = halving count |
| 2005 | Subtree Removal Game | Hard | Nim game on tree |
| 2313 | Min Flips in Binary Tree to Get Result | Hard | Boolean tree DP |

### 📚 All Problems in Pattern 11

- 337 House Robber III
- 968 Binary Tree Cameras
- 979 Distribute Coins in Binary Tree
- 1145 Binary Tree Coloring Game
- 1339 Maximum Product of Splitted Binary Tree
- 1373 Maximum Sum BST in Binary Tree
- 1569 Number of Ways to Reorder Array to Get Same BST
- 1617 Count Subtrees With Max Distance Between Cities
- 1719 Number Of Ways To Reconstruct A Tree
- 1916 Count Ways to Build Rooms in an Ant Colony
- 2003 Smallest Missing Genetic Value in Each Subtree
- 2005 Subtree Removal Game with Fibonacci Tree
- 2049 Count Nodes With Highest Score
- 2246 Longest Path With Different Adjacent Characters
- 2313 Minimum Flips in Binary Tree to Get Result
- 2322 Minimum Score After Removals on a Tree
- 2378 Choose Edges to Maximize Score in a Tree
- 2421 Number of Good Paths
- 2440 Create Components With Same Value
- 2467 Most Profitable Path in a Tree
- 2479 Maximum XOR of Two Non-Overlapping Subtrees
- 2538 Difference Between Maximum and Minimum Price Sum
- 2581 Count Number of Possible Root Nodes
- 2603 Collect Coins in a Tree
- 2646 Minimize the Total Price of the Trips
- 2791 Count Paths That Can Form a Palindrome in a Tree
- 2867 Count Valid Paths in a Tree
- 2920 Maximum Points After Collecting Coins From All Nodes
- 2925 Maximum Score After Applying Operations on a Tree
- 3068 Find the Maximum Sum of Node Values
- 3241 Time Taken to Mark All Nodes
- 3313 Find the Last Marked Nodes in Tree
- 3367 Maximize Sum of Weights after Edge Removals
- 3425 Longest Special Path
- 3486 Longest Special Path II
- 3544 Subtree Inversion Sum
- 3575 Maximum Good Subtree Score

---

## 30-Day Mastery Roadmap

> **Philosophy**: Learn the pattern → internalize the template → apply to 3–5 problems → move on. Do NOT grind 50 easy problems before touching mediums.

### Week 1 — Core DFS Patterns (Days 1–7)

| Day | Focus | Problems to Solve |
|---|---|---|
| 1 | Pattern 1: Traversal foundations | 94, 226, 101, 100 |
| 2 | Pattern 1: Collect + Compare | 199, 257, 572, 617 |
| 3 | Pattern 2: Height DP | 104, 110, 543, 111 |
| 4 | Pattern 2: Complex subtree | 687, 563, 508, 652 |
| 5 | Pattern 3A: Root → Leaf | 112, 113, 129, 1022 |
| 6 | Pattern 3A: Advanced | 1457, 1080, 1026, 988 |
| 7 | Review + Pattern 3C | 437, 666 |

### Week 2 — Path & Level Patterns (Days 8–14)

| Day | Focus | Problems to Solve |
|---|---|---|
| 8 | Pattern 3B: LCA | 236, 235, 1123, 865 |
| 9 | Pattern 3B: Max path | 124, 1372, 549 |
| 10 | Pattern 3B: Distance paths | 1740, 2096, 2467 |
| 11 | Pattern 4A: BFS foundations | 102, 103, 107, 637 |
| 12 | Pattern 4A: BFS advanced | 662, 1161, 513, 515 |
| 13 | Pattern 4B: Distance BFS | 863, 2385, 1443 |
| 14 | Pattern 4B + Review | 1376, 1740, 582 |

### Week 3 — Structural & BST Patterns (Days 15–21)

| Day | Focus | Problems to Solve |
|---|---|---|
| 15 | Pattern 5: Coordinates | 314, 987, 545 |
| 16 | Pattern 6: Mutation | 114, 1110, 814, 1325 |
| 17 | Pattern 6: BST mutation | 450, 669, 701, 538 |
| 18 | Pattern 7: Construction | 105, 106, 108 |
| 19 | Pattern 7: Advanced construction | 297, 654, 889, 1008 |
| 20 | Pattern 8: Validation | 98, 958, 331, 222 |
| 21 | Pattern 9: BST ordering | 230, 270, 285, 530 |

### Week 4 — Advanced DP & Mock Interviews (Days 22–30)

| Day | Focus | Problems to Solve |
|---|---|---|
| 22 | Pattern 9: BST advanced | 538, 653, 938, 1305 |
| 23 | Pattern 10: N-ary | 429, 690, 559, 1522 |
| 24 | Pattern 11: Multi-state DP | 337, 979, 1145 |
| 25 | Pattern 11: Hard DP | 968, 1339, 1373 |
| 26 | Pattern 11: Expert level | 2581, 2646, 2313 |
| 27 | Mock Interview Day 1 | Random 5 (all patterns) |
| 28 | Mock Interview Day 2 | 3 mediums + 1 hard |
| 29 | Weak pattern reinforcement | Fill gaps from mock interviews |
| 30 | Final review | Re-solve 10 hardest problems |

---

## 🎯 Top 30 "Must Solve" Interview Problems

These are the 30 problems most likely to appear in FAANG/top company interviews, covering all 11 patterns:

| Priority | # | Problem | Pattern | Difficulty |
|---|---|---|---|---|
| 🔥🔥🔥 | 124 | Binary Tree Maximum Path Sum | 3B | Hard |
| 🔥🔥🔥 | 236 | Lowest Common Ancestor | 3B | Medium |
| 🔥🔥🔥 | 297 | Serialize and Deserialize BT | 7 | Hard |
| 🔥🔥🔥 | 102 | Level Order Traversal | 4A | Medium |
| 🔥🔥🔥 | 98 | Validate BST | 8 | Medium |
| 🔥🔥🔥 | 543 | Diameter of Binary Tree | 2 | Easy |
| 🔥🔥🔥 | 437 | Path Sum III | 3C | Medium |
| 🔥🔥🔥 | 105 | Construct from Preorder + Inorder | 7 | Medium |
| 🔥🔥🔥 | 337 | House Robber III | 11 | Medium |
| 🔥🔥🔥 | 968 | Binary Tree Cameras | 11 | Hard |
| 🔥🔥 | 199 | Binary Tree Right Side View | 4A | Medium |
| 🔥🔥 | 226 | Invert Binary Tree | 1 | Easy |
| 🔥🔥 | 230 | Kth Smallest in BST | 9 | Medium |
| 🔥🔥 | 863 | All Nodes Distance K | 4B | Medium |
| 🔥🔥 | 110 | Balanced Binary Tree | 2 | Easy |
| 🔥🔥 | 987 | Vertical Order Traversal | 5 | Hard |
| 🔥🔥 | 114 | Flatten BT to Linked List | 6 | Medium |
| 🔥🔥 | 662 | Maximum Width of BT | 4A | Medium |
| 🔥🔥 | 2385 | Amount of Time for BT to Infect | 4B | Medium |
| 🔥🔥 | 1372 | Longest ZigZag Path | 3B | Medium |
| 🔥🔥 | 1110 | Delete Nodes and Return Forest | 6 | Medium |
| 🔥🔥 | 979 | Distribute Coins in BT | 11 | Medium |
| 🔥 | 958 | Check Completeness of BT | 8 | Medium |
| 🔥 | 1457 | Pseudo-Palindromic Paths | 3A | Medium |
| 🔥 | 450 | Delete Node in BST | 9 | Medium |
| 🔥 | 654 | Maximum Binary Tree | 7 | Medium |
| 🔥 | 1161 | Maximum Level Sum | 4A | Medium |
| 🔥 | 538 | Convert BST to Greater Tree | 9 | Medium |
| 🔥 | 1339 | Max Product of Splitted BT | 11 | Medium |
| 🔥 | 2096 | Step-By-Step Directions | 3B | Medium |

---

## Hybrid Decision Guide

> When a problem feels like it belongs to TWO patterns, use the **dominant pattern rule**: ask "what is the PRIMARY structure driving the solution?"

| Combination | Rule | Example |
|---|---|---|
| Tree + Graph | Use tree patterns; convert to graph only for 4B | 863, 2385 |
| BST + DP | Use Pattern 9 for ordering, Pattern 11 for states | 1373 |
| Path + Level | Path dominates if no level-by-level logic | 1372 vs 102 |
| Mutation + Validation | Mutation dominates if output is modified tree | 669 |
| Construction + Traversal | Construction dominates if building is the goal | 105, 297 |
| N-ary + DP | Apply Pattern 11 logic, iterate children instead | 1916 |
| 3A + 3B | 3A if path MUST start at root; 3B if anywhere | 112 vs 124 |

---

## Quick Reference — Common Mistakes

| Mistake | Correct Approach |
|---|---|
| Forgetting null check at start of DFS | Always `if (!node) return baseCase;` first |
| Not initializing global variable before DFS | Set `ans = INT_MIN` or `0` before calling DFS |
| BST validation using only `node->left->val < node->val` | Always pass min/max range — this fails for non-direct ancestors |
| Using `int` for BST range validation | Use `long long` or pass `TreeNode*` bounds to avoid INT_MIN/MAX issues |
| Forgetting to backtrack in path problems (3A) | Always `path.pop_back()` after recursive calls |
| Wrong column index in 987 (vertical order) | Sort by `(row, col, val)` — BFS gives wrong order for same (row,col) |
| Pattern 4B: forgetting to go "upward" through parent | Build parent map first, BFS in all 3 directions |
| Pattern 11: taking max of only one state | Return both states as pair/struct, let PARENT choose |

---

*Guide compiled from 300+ LeetCode tree problems, mapped to 11 universal patterns.*
*Master these patterns and you will solve 95%+ of tree questions in any technical interview.*
