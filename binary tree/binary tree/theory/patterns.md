Below are **EXACT, COPY-PASTE C++ TEMPLATES** for **each of the 11 Tree patterns** you defined.
These are **canonical interview templates** — minimal, reusable, and battle-tested.

No explanations.
Just **what to write** when you recognize the pattern.

---

# 🌳 TREE — EXACT C++ TEMPLATES (PATTERN-WISE)

---

## 🟢 Pattern 1 — Traversal Only (DFS / BFS)

### DFS (Pre / In / Post)

```cpp
void dfs(TreeNode* root) {
    if (!root) return;

    // preorder
    dfs(root->left);
    // inorder
    dfs(root->right);
    // postorder
}
```

### BFS (Level Order)

```cpp
queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
        TreeNode* cur = q.front(); q.pop();
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}
```

---

## 🟢 Pattern 2 — Height / Subtree DP

```cpp
int dfs(TreeNode* root) {
    if (!root) return 0;

    int L = dfs(root->left);
    int R = dfs(root->right);

    // use L, R
    return 1 + max(L, R);
}
```

Used for:

* Height
* Diameter
* Balanced Tree
* Subtree aggregation

---

## 🟢 Pattern 3A — Root → Leaf Path

```cpp
void dfs(TreeNode* root, int curr) {
    if (!root) return;

    curr = curr * 10 + root->val;

    if (!root->left && !root->right) {
        // leaf reached
        return;
    }

    dfs(root->left, curr);
    dfs(root->right, curr);
}
```

---

## 🟢 Pattern 3B — Any → Any Path (LCA / Turning Point)

```cpp
int ans = INT_MIN;

int dfs(TreeNode* root) {
    if (!root) return 0;

    int L = max(0, dfs(root->left));
    int R = max(0, dfs(root->right));

    ans = max(ans, root->val + L + R);

    return root->val + max(L, R);
}
```

---

## 🟢 Pattern 3C — Counting Paths (Prefix Sum)

```cpp
unordered_map<long long,int> mp;
int count = 0;

void dfs(TreeNode* root, long long sum, int target) {
    if (!root) return;

    sum += root->val;
    count += mp[sum - target];

    mp[sum]++;
    dfs(root->left, sum, target);
    dfs(root->right, sum, target);
    mp[sum]--;
}
```

---

## 🟢 Pattern 4A — Level-wise Logic

```cpp
queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {
    int sz = q.size();
    vector<int> level;

    while (sz--) {
        TreeNode* cur = q.front(); q.pop();
        level.push_back(cur->val);
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    // process level
}
```

---

## 🟢 Pattern 4B — Distance / Time Propagation

```cpp
unordered_map<TreeNode*, TreeNode*> parent;
queue<TreeNode*> q;
unordered_set<TreeNode*> vis;

q.push(start);
vis.insert(start);

int time = 0;
while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
        TreeNode* cur = q.front(); q.pop();

        for (TreeNode* nei : {cur->left, cur->right, parent[cur]}) {
            if (nei && !vis.count(nei)) {
                vis.insert(nei);
                q.push(nei);
            }
        }
    }
    time++;
}
```

---

## 🟢 Pattern 5 — Horizontal / Coordinate (Vertical Order)

```cpp
map<int, vector<int>> mp;
queue<pair<TreeNode*, int>> q;
q.push({root, 0});

while (!q.empty()) {
    auto [node, col] = q.front(); q.pop();
    mp[col].push_back(node->val);
    if (node->left) q.push({node->left, col - 1});
    if (node->right) q.push({node->right, col + 1});
}
```

---

## 🟢 Pattern 6 — Structural Change / Mutation

```cpp
TreeNode* dfs(TreeNode* root) {
    if (!root) return nullptr;

    root->left = dfs(root->left);
    root->right = dfs(root->right);

    // modify pointers here
    return root;
}
```

---

## 🟢 Pattern 7 — Construction (Build Tree)

```cpp
TreeNode* build(vector<int>& pre, int ps, int pe,
                vector<int>& in, int is, int ie) {
    if (ps > pe) return nullptr;

    TreeNode* root = new TreeNode(pre[ps]);
    int idx = is;
    while (in[idx] != pre[ps]) idx++;

    int leftSize = idx - is;
    root->left = build(pre, ps + 1, ps + leftSize, in, is, idx - 1);
    root->right = build(pre, ps + leftSize + 1, pe, in, idx + 1, ie);

    return root;
}
```

---

## 🟢 Pattern 8 — Validation

```cpp
bool dfs(TreeNode* root, long long lo, long long hi) {
    if (!root) return true;
    if (root->val <= lo || root->val >= hi) return false;

    return dfs(root->left, lo, root->val) &&
           dfs(root->right, root->val, hi);
}
```

---

## 🟢 Pattern 9 — Ordering (BST)

```cpp
int prev = INT_MIN;

bool inorder(TreeNode* root) {
    if (!root) return true;
    if (!inorder(root->left)) return false;
    if (root->val <= prev) return false;
    prev = root->val;
    return inorder(root->right);
}
```

---

## 🟢 Pattern 10 — N-ary Tree

```cpp
void dfs(Node* root) {
    if (!root) return;
    for (Node* child : root->children)
        dfs(child);
}
```

---

## 🟢 Pattern 11 — Complex Tree DP / Games

```cpp
pair<int,int> dfs(TreeNode* root) {
    if (!root) return {0, 0};

    auto L = dfs(root->left);
    auto R = dfs(root->right);

    int take = root->val + L.second + R.second;
    int skip = max(L.first, L.second) + max(R.first, R.second);

    return {take, skip};
}
```

---

# ✅ FINAL GUARANTEE

If you:

* Recognize the **pattern**
* Drop in the **matching template**
* Fill the **problem-specific logic**

➡️ **You can solve ANY tree problem on LeetCode or interviews.**

---

If you want next:

* 📌 **One-page Tree Pattern Cheat Sheet**
* 📌 **Tree ↔ Graph Hybrid Templates**
* 📌 **15-question Tree Interview Drill**
* 📌 **Tree Pattern Recognition Flowchart**

Just say the word.
