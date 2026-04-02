 Pattern 5 — Horizontal / Coordinate (Vertical Order)
map<int, vector<int>> mp;
queue<pair<TreeNode*, int>> q;
q.push({root, 0});

while (!q.empty()) {
    auto [node, col] = q.front(); q.pop();
    mp[col].push_back(node->val);
    if (node->left) q.push({node->left, col - 1});
    if (node->right) q.push({node->right, col + 1});
}
