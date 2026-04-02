# 🌳 TREE PROBLEMS — COMPLETE PATTERN TEMPLATES & EXPLANATIONS

Below you will find a template and detailed explanation for each of the 11 tree problem patterns identified in the previous categorization. For each pattern and its subpatterns, we provide:

- **When to use** – the type of problem that fits this pattern.
- **State meaning** – what information is maintained during recursion / traversal.
- **Template code** in C++ (with comments) that captures the core logic.
- **Key insights** – important observations that help adapt the template.
- **Example problems** – a few starred problems that illustrate the pattern.

By mastering these templates, you will be able to systematically approach and solve nearly every tree problem on LeetCode.

---

## 🟢 Pattern 1 — Traversal Only

**When to use:** The problem simply needs to visit nodes in a specific order (preorder, inorder, postorder, level order) and process each node independently. No dependency on children's results beyond basic accumulation.

**State meaning:** `dfs(node)` processes the current node, then recurses to children. BFS uses a queue.

### Subpattern 1A: DFS Traversals (Preorder / Inorder / Postorder)

```cpp
// Generic DFS traversal template (preorder example)
void dfs(TreeNode* node) {
    if (!node) return;
    
    // 1. Process current node (preorder)
    // e.g., visit(node->val);
    
    dfs(node->left);  // then left
    dfs(node->right); // then right
}

// Inorder: dfs(left); process; dfs(right);
// Postorder: dfs(left); dfs(right); process;
```

**Key insights:**
- Use recursion (or explicit stack) to simulate the order.
- For problems like *Same Tree* or *Symmetric Tree*, you may need to pass two nodes simultaneously.
- For *Right Side View*, you can do a modified preorder (root->right->left) and record first at each depth.

**Example problems:** ⭐94, 100, ⭐101, 144, 145, ⭐199, ⭐226, 257, 404, 572, 589, 590, 606, 617, 637, 872, 951, 965, 993, 1379, 1469, 1506, 2236, 2331

### Subpattern 1B: BFS / Level Order

```cpp
// Level order traversal using queue
vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front(); q.pop();
            currentLevel.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(currentLevel);
    }
    return result;
}
```

**Key insights:**
- The `levelSize` variable captures all nodes at current depth.
- Use this to compute averages, find largest value, etc.
- For zigzag, toggle direction each level.

**Example problems:** ⭐102, ⭐103, 107, 116, 117, 515, 637 (also level-order), 662 (max width needs indexing), 1161.

---

## 🟢 Pattern 2 — Height / Subtree DP

**When to use:** The answer for a node depends on results from its children (e.g., height, diameter, tilt). Postorder traversal is used to aggregate information upward.

**State meaning:** `dfs(node)` returns a value (height, sum, count, etc.) computed from the node’s children. A global variable may track the overall answer.

```cpp
// Generic bottom-up DP template (height example)
int dfs(TreeNode* node, int& globalMax) {
    if (!node) return 0;
    
    int left = dfs(node->left, globalMax);
    int right = dfs(node->right, globalMax);
    
    // Process current node using children's results
    int currentHeight = 1 + max(left, right);
    
    // Update global answer if needed
    globalMax = max(globalMax, left + right); // e.g., diameter
    
    return currentHeight;
}

// Caller:
int solve(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
}
```

**Key insights:**
- The function returns a property of the subtree rooted at `node`.
- The global answer (e.g., diameter, tilt) is often updated by combining left and right results.
- Common return values: height, sum, count, max path sum ending at node, etc.

**Example problems:** ⭐104, ⭐110, ⭐543, 559, 563, ⭐687, 1120, 1245, 1302, ⭐1373, 1522, 1973, 2049, 2458, 2773, 3575.

---

## 🟢 Pattern 3A — Root → Leaf Paths

**When to use:** The problem involves paths that start at the root and end at a leaf, and you need to accumulate some value along the path (sum, string, etc.).

**State meaning:** `dfs(node, currentPathState)` propagates a state (e.g., running sum, current string) down to leaves. At leaf, check condition or update answer.

```cpp
// Template for root-to-leaf path problems (Path Sum example)
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    // Use a helper that carries the current sum
    function<bool(TreeNode*, int)> dfs = [&](TreeNode* node, int cur) {
        cur += node->val;
        if (!node->left && !node->right) { // leaf
            return cur == targetSum;
        }
        bool leftOk = node->left ? dfs(node->left, cur) : false;
        bool rightOk = node->right ? dfs(node->right, cur) : false;
        return leftOk || rightOk;
    };
    return dfs(root, 0);
}
```

**Key insights:**
- The path state is passed by value (or reference with backtracking).
- For problems like *Path Sum II*, collect paths when leaf is reached.
- For *Pseudo-Palindromic Paths*, pass a bitmask of frequencies.
- Pre-order traversal is natural.

**Example problems:** ⭐112, ⭐113, 129, 1022, 1080, 1430, ⭐1457, 1530, 988.

---

## 🟢 Pattern 3B — Any → Any Path (LCA, max path, zigzag)

**When to use:** The path can start and end anywhere in the tree, not necessarily root. Typically involves LCA, maximum path sum, zigzag length, etc. The solution often uses a helper that returns the best path **starting** at the current node and going downward, while a global variable tracks the best path that may go through the node.

**State meaning:** `dfs(node)` returns the best value (length, sum, etc.) of a path that starts at `node` and goes strictly downward (to either left or right, but not both). A global answer is updated by combining left and right results to form a path that goes through the node.

```cpp
// Template for Maximum Path Sum
int maxPathSum(TreeNode* root) {
    int globalMax = INT_MIN;
    
    function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
        if (!node) return 0;
        
        int leftGain = max(dfs(node->left), 0); // only positive contributions
        int rightGain = max(dfs(node->right), 0);
        
        // Path through current node
        int currentPath = node->val + leftGain + rightGain;
        globalMax = max(globalMax, currentPath);
        
        // Return best path starting at node and going down
        return node->val + max(leftGain, rightGain);
    };
    
    dfs(root);
    return globalMax;
}
```

**Key insights:**
- The helper returns the best **downward** path from the node.
- The global answer uses the node as the highest point (combining left and right).
- For LCA, the helper returns whether subtree contains target nodes, and global answer is set when both sides found.

**Example problems:** ⭐124, ⭐236, 742, ⭐865, 1123, ⭐1372, 1740, 2096, 2467, 3425, 3486.

---

## 🟢 Pattern 3C — Counting Paths

**When to use:** Count the number of paths (usually from any node to any descendant) that satisfy a condition (e.g., sum equals target). Often uses prefix sums and hashmap during DFS.

**State meaning:** DFS traversal with a running sum (from root), and a hashmap that stores frequencies of prefix sums along the current path.

```cpp
// Template for Path Sum III
int pathSum(TreeNode* root, int targetSum) {
    unordered_map<long, int> prefixCount; // prefix sum -> frequency
    prefixCount[0] = 1; // base: sum zero before root
    int ans = 0;
    
    function<void(TreeNode*, long)> dfs = [&](TreeNode* node, long curSum) {
        if (!node) return;
        
        curSum += node->val;
        // Check if curSum - targetSum exists in prefixCount
        ans += prefixCount[curSum - targetSum];
        
        prefixCount[curSum]++;
        dfs(node->left, curSum);
        dfs(node->right, curSum);
        prefixCount[curSum]--; // backtrack
    };
    
    dfs(root, 0);
    return ans;
}
```

**Key insights:**
- Use a hashmap to store counts of prefix sums along the current path.
- The number of valid paths ending at current node = frequency of `curSum - target`.
- Backtrack after processing children to remove the contribution of current node.

**Example problems:** ⭐437, 666, 2791, 2867.

---

## 🟢 Pattern 4A — Level-wise Logic

**When to use:** Problems that require processing nodes level by level, often with additional logic per level (e.g., find bottom-left value, max width, level sums).

**State meaning:** BFS with a queue; for each level, we know all nodes at that depth. Use `queue.size()` to demarcate levels.

```cpp
// Generic level-wise BFS template
void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front(); q.pop();
            // Process node at this level
            // e.g., record value, update min/max, etc.
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        // After finishing level, you have aggregated info for that level
    }
}
```

**Key insights:**
- For **max width**, you need to assign indices to nodes (like heap indexing) and track min/max index per level.
- For **zigzag**, use a deque or toggle order of insertion.
- For **even odd tree**, check values against previous at same level.

**Example problems:** ⭐102, ⭐103, 107, 116, 117, ⭐513, 515, 637, ⭐662, ⭐1161, 2471, 2641.

---

## 🟢 Pattern 4B — Distance / Time

**When to use:** Problems that ask for distance from a given node to all others, or time needed to spread information/infection. Usually BFS from one or multiple sources.

**State meaning:** BFS queue stores nodes along with current distance/time. Use visited set to avoid cycles (though tree has none, but we need parent tracking).

```cpp
// Template for All Nodes Distance K in Binary Tree
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    // First, build parent pointers using DFS
    unordered_map<TreeNode*, TreeNode*> parent;
    function<void(TreeNode*, TreeNode*)> buildParent = [&](TreeNode* node, TreeNode* par) {
        if (!node) return;
        parent[node] = par;
        buildParent(node->left, node);
        buildParent(node->right, node);
    };
    buildParent(root, nullptr);
    
    // BFS from target
    queue<pair<TreeNode*, int>> q; // (node, distance)
    q.push({target, 0});
    unordered_set<TreeNode*> visited;
    visited.insert(target);
    vector<int> result;
    
    while (!q.empty()) {
        auto [node, dist] = q.front(); q.pop();
        if (dist == k) {
            result.push_back(node->val);
            continue; // no need to go further
        }
        // Explore neighbors: left, right, parent
        if (node->left && !visited.count(node->left)) {
            visited.insert(node->left);
            q.push({node->left, dist + 1});
        }
        if (node->right && !visited.count(node->right)) {
            visited.insert(node->right);
            q.push({node->right, dist + 1});
        }
        if (parent[node] && !visited.count(parent[node])) {
            visited.insert(parent[node]);
            q.push({parent[node], dist + 1});
        }
    }
    return result;
}
```

**Key insights:**
- For distance problems, first build parent links to move upward.
- BFS ensures shortest distance in an unweighted tree.
- For infection time, start BFS from initially infected node(s) and track max time.

**Example problems:** 582, 742, ⭐863, ⭐1376, 1443, 1740, ⭐2385, 3241.

---

## 🟢 Pattern 5 — Horizontal / Coordinate

**When to use:** Problems that ask for vertical order traversal, boundary traversal, or printing tree in 2D coordinates. Need to assign (row, col) to each node.

**State meaning:** DFS or BFS with additional parameters `row` and `col`. Store nodes in a map keyed by column (and sometimes row) to maintain order.

```cpp
// Template for Vertical Order Traversal
vector<vector<int>> verticalOrder(TreeNode* root) {
    if (!root) return {};
    map<int, vector<int>> columns; // col -> list of node values (top to bottom)
    queue<pair<TreeNode*, int>> q; // (node, column)
    q.push({root, 0});
    
    while (!q.empty()) {
        auto [node, col] = q.front(); q.pop();
        columns[col].push_back(node->val);
        if (node->left) q.push({node->left, col - 1});
        if (node->right) q.push({node->right, col + 1});
    }
    
    vector<vector<int>> result;
    for (auto& [col, vals] : columns) {
        result.push_back(vals);
    }
    return result;
}
```

**Key insights:**
- Use BFS to ensure top-to-bottom order within same column.
- If multiple nodes in same row and column need sorting by value (LeetCode 987), store `(row, val)` pairs and sort.
- For boundary traversal, combine left boundary, leaves, right boundary with careful order.

**Example problems:** ⭐314, 545, 655, ⭐987.

---

## 🟢 Pattern 6 — Structural Change

**When to use:** The problem requires modifying the tree structure: flattening, pruning, inserting, deleting, or rewiring pointers. Recursion often returns the modified subtree.

**State meaning:** `dfs(node)` returns the modified node (or root of modified subtree). The function may also take additional parameters (e.g., value to insert).

```cpp
// Template for pruning (Binary Tree Pruning)
TreeNode* pruneTree(TreeNode* root) {
    if (!root) return nullptr;
    
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    
    // If node is leaf and value is 0, remove it
    if (!root->left && !root->right && root->val == 0) {
        return nullptr;
    }
    return root;
}

// Template for flatten (Flatten Binary Tree to Linked List)
void flatten(TreeNode* root) {
    if (!root) return;
    
    flatten(root->left);
    flatten(root->right);
    
    // Save right subtree
    TreeNode* rightSubtree = root->right;
    
    // Move left to right
    root->right = root->left;
    root->left = nullptr;
    
    // Find the end of new right chain
    TreeNode* cur = root;
    while (cur->right) cur = cur->right;
    cur->right = rightSubtree;
}
```

**Key insights:**
- Often postorder: first modify children, then attach them.
- Return value is the new root of the subtree (useful when nodes are deleted).
- For problems like *Delete Nodes and Return Forest*, collect roots of remaining trees in a global vector.

**Example problems:** ⭐114, 156, 226, 623, 814, 998, ⭐1110, 1325, 1666, 2415, 450, 538, 669, 701, 776, 897, 971, 1038, 1382, 1516.

---

## 🟢 Pattern 7 — Construction

**When to use:** Build a tree from given traversal sequences (preorder+inorder, inorder+postorder, preorder+postorder) or from a string representation.

**State meaning:** Recursively construct tree by picking root from preorder, and splitting inorder into left/right using indexes. Pass index bounds as parameters.

```cpp
// Template for Construct Binary Tree from Preorder and Inorder
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap; // value -> index in inorder
    for (int i = 0; i < inorder.size(); ++i)
        inMap[inorder[i]] = i;
    
    function<TreeNode*(int, int, int, int)> build = [&](int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        int inRootIdx = inMap[rootVal];
        int leftSize = inRootIdx - inStart;
        
        root->left = build(preStart + 1, preStart + leftSize, inStart, inRootIdx - 1);
        root->right = build(preStart + leftSize + 1, preEnd, inRootIdx + 1, inEnd);
        return root;
    };
    
    return build(0, preorder.size()-1, 0, inorder.size()-1);
}
```

**Key insights:**
- Preorder gives root first; inorder gives left/right subtrees.
- Pass ranges to avoid creating new vectors.
- For preorder+postorder, there can be multiple trees; often we need to return all possibilities (e.g., ⭐894 All Possible Full Binary Trees).

**Example problems:** ⭐105, ⭐106, 108, 109, ⭐297, 427, 428, 431, 536, ⭐654, 889, ⭐894, 1008, 1028, 2196.

---

## 🟢 Pattern 8 — Validation

**When to use:** Check whether a tree satisfies a certain property (BST, completeness, etc.). Usually involves passing constraints down or counting nodes.

**State meaning:** For BST, pass valid `(min, max)` range. For completeness, BFS and check for missing children.

```cpp
// Template for Validate BST
bool isValidBST(TreeNode* root) {
    function<bool(TreeNode*, long long, long long)> dfs = [&](TreeNode* node, long long low, long long high) {
        if (!node) return true;
        if (node->val <= low || node->val >= high) return false;
        return dfs(node->left, low, node->val) && dfs(node->right, node->val, high);
    };
    return dfs(root, LLONG_MIN, LLONG_MAX);
}
```

**Key insights:**
- For BST, use `long long` to handle INT_MIN/INT_MAX.
- For completeness, BFS and stop after first missing child; all subsequent nodes must be leaves.
- For preorder serialization validation, use a counter.

**Example problems:** ⭐98, 222, 255, ⭐331, ⭐958, 1361, 1609, 2764.

---

## 🟢 Pattern 9 — Ordering (BST)

**When to use:** Problems that leverage the inorder traversal property of BST (sorted order). Includes kth smallest, LCA in BST, range sum, etc.

**State meaning:** Inorder traversal with early termination, or recursive search using BST value comparisons.

```cpp
// Template for Kth Smallest in BST (inorder with counter)
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    int count = 0;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top(); st.pop();
        count++;
        if (count == k) return cur->val;
        cur = cur->right;
    }
    return -1;
}

// Template for LCA in BST
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
    return nullptr;
}
```

**Key insights:**
- Use iterative inorder to save space and stop early.
- BST properties allow O(h) navigation without recursion.
- For problems like *Two Sum IV*, use inorder to get sorted array then two pointers.

**Example problems:** ⭐230, ⭐235, 270, 272, 285, 426, ⭐450, 501, 530, 538, ⭐653, 669, 700, 701, 776, 783, 897, 938, 1008, 1038, 1214, 1305, 1382, 1586, 1902, 2476.

---

## 🟢 Pattern 10 — N-ary Tree

**When to use:** Problems on trees where each node has a list of children. Traversal and DP adapt to iterating over children.

**State meaning:** Similar to binary tree, but instead of left/right, loop over `node->children`.

```cpp
// Template for N-ary Tree DFS (postorder)
int dfs(Node* node) {
    if (!node) return 0;
    int maxDepth = 0;
    for (Node* child : node->children) {
        maxDepth = max(maxDepth, dfs(child));
    }
    return maxDepth + 1; // example: maximum depth
}

// Template for N-ary Tree BFS
vector<vector<int>> levelOrder(Node* root) {
    if (!root) return {};
    vector<vector<int>> result;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; ++i) {
            Node* node = q.front(); q.pop();
            level.push_back(node->val);
            for (Node* child : node->children) {
                q.push(child);
            }
        }
        result.push_back(level);
    }
    return result;
}
```

**Key insights:**
- Use loops over children instead of left/right.
- Many binary tree problems have direct N-ary counterparts (e.g., diameter, max depth, serialization).
- For problems like *Clone N-ary Tree*, recursion naturally works.

**Example problems:** ⭐429, ⭐559, 589, 590, ⭐690, 1490, 1506, 1516, 1519, 1522, 1600, 1617, 1916.

---

## 🟢 Pattern 11 — Complex Tree DP / Games

**When to use:** Problems that require multiple states per node, often involving decisions (rob or not, place camera or not, color, etc.). The recursion returns a structure or multiple values representing different states.

**State meaning:** `dfs(node)` returns a tuple/struct containing values for each possible state of the node. The answer is derived by combining children’s states.

```cpp
// Template for House Robber III
struct RobResult {
    int rob;   // max money if we rob this node
    int notRob; // max money if we do not rob this node
};

RobResult dfs(TreeNode* node) {
    if (!node) return {0, 0};
    RobResult left = dfs(node->left);
    RobResult right = dfs(node->right);
    
    int rob = node->val + left.notRob + right.notRob;
    int notRob = max(left.rob, left.notRob) + max(right.rob, right.notRob);
    
    return {rob, notRob};
}

int rob(TreeNode* root) {
    RobResult res = dfs(root);
    return max(res.rob, res.notRob);
}
```

**Key insights:**
- Define states clearly (e.g., with camera / without camera, covered / not covered).
- Combine children’s states according to rules.
- Often the recursion returns a small struct or array.

**Example problems:** ⭐337, ⭐968, ⭐979, 1145, ⭐1339, 1617, 2005, 2313, 2322, ⭐2421, 2581, 2646, 2920, 2925, 2973, 3068, 3367, 3575, 3772, and many more (see the long list in Pattern 11).

---

## ✅ Conclusion

By recognizing which pattern a tree problem falls into, you can immediately apply the corresponding template. The templates above are designed to be adaptable; you may need to tweak the state or combine multiple patterns for complex problems. Practice with the starred examples to internalize each pattern.

Remember:
- **Traversal** patterns are about order.
- **DP** patterns aggregate information upward.
- **Path** patterns often involve carrying a state down.
- **BFS** patterns handle level and distance.
- **Construction** patterns build trees from sequences.
- **Validation** patterns use constraints.
- **BST** patterns exploit ordering.
- **N-ary** patterns generalize binary tree logic.

With these tools, you are equipped to tackle virtually any tree problem on LeetCode. Happy coding!
