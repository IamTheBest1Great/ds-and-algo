Perfect — understood **precisely** 👍

What I will do now (and what I will NOT do):

### ✅ I WILL

* Keep **every single question exactly as-is** (no deletions)
* Keep **same 11 patterns + same sub-patterns**
* Add a **new column: State meaning**
* **Highlight important / frequently asked questions** using ⭐ **inside the Questions column**
* Maintain **table-only format**
* Questions remain **one below another**
* Spreadsheet / Notion ready

### ❌ I WILL NOT

* Remove or reduce questions
* Add explanations or paragraphs
* Change taxonomy
* Collapse rows

---

# 🌳 TREE PROBLEMS — FINAL STRICT TABLE (WITH STATE MEANING + ⭐)

---

## 🟢 Pattern 1 — Traversal Only

| Pattern   | Sub-pattern | State meaning                                       | Questions                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| --------- | ----------- | --------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Traversal | DFS / BFS   | `dfs(node)` → process node without child dependency | ⭐94 Binary Tree Inorder Traversal<br>100 Same Tree<br>⭐101 Symmetric Tree<br>144 Binary Tree Preorder Traversal<br>145 Binary Tree Postorder Traversal<br>⭐199 Binary Tree Right Side View<br>⭐226 Invert Binary Tree<br>257 Binary Tree Paths<br>341 Flatten Nested List Iterator<br>404 Sum of Left Leaves<br>572 Subtree of Another Tree<br>589 N-ary Tree Preorder Traversal<br>590 N-ary Tree Postorder Traversal<br>606 Construct String from Binary Tree<br>617 Merge Two Binary Trees<br>637 Average of Levels in Binary Tree<br>872 Leaf-Similar Trees<br>951 Flip Equivalent Binary Trees<br>965 Univalued Binary Tree<br>993 Cousins in Binary Tree<br>1379 Find Corresponding Node in Clone<br>1469 Find All the Lonely Nodes<br>1506 Find Root of N-Ary Tree<br>2236 Root Equals Sum of Children<br>2331 Evaluate Boolean Binary Tree |

---

## 🟢 Pattern 2 — Height / Subtree DP

| Pattern     | Sub-pattern           | State meaning                               | Questions                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| ----------- | --------------------- | ------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Height / DP | Bottom-up aggregation | `dfs(node) → height / value using children` | ⭐104 Maximum Depth of Binary Tree<br>⭐110 Balanced Binary Tree<br>⭐543 Diameter of Binary Tree<br>559 Maximum Depth of N-ary Tree<br>563 Binary Tree Tilt<br>⭐687 Longest Univalue Path<br>1120 Maximum Average Subtree<br>1245 Tree Diameter<br>1302 Deepest Leaves Sum<br>⭐1373 Maximum Sum BST in Binary Tree<br>1522 Diameter of N-ary Tree<br>1973 Count Nodes Equal to Sum of Descendants<br>2049 Count Nodes With Highest Score<br>2458 Height of Binary Tree After Removal<br>2773 Height of Special Binary Tree<br>3575 Maximum Good Subtree Score |

---

## 🟢 Pattern 3A — Root → Leaf Paths

| Pattern | Sub-pattern | State meaning                             | Questions                                                                                                                                                                                                                                                                       |
| ------- | ----------- | ----------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Path    | Root → Leaf | `dfs(node, pathState)` → propagate prefix | ⭐112 Path Sum<br>⭐113 Path Sum II<br>129 Sum Root to Leaf Numbers<br>1022 Sum of Root to Leaf Binary Numbers<br>1080 Insufficient Nodes in Root to Leaf Paths<br>1430 Valid Sequence from Root to Leaf<br>⭐1457 Pseudo-Palindromic Paths<br>1530 Number of Good Leaf Node Pairs |

---

## 🟢 Pattern 3B — Any → Any Path

| Pattern | Sub-pattern     | State meaning                        | Questions                                                                                                                                                                                                                                                                                                                                                                                                              |
| ------- | --------------- | ------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Path    | Any → Any (LCA) | `dfs(node)` returns best upward path | ⭐124 Binary Tree Maximum Path Sum<br>⭐236 Lowest Common Ancestor of Binary Tree<br>742 Closest Leaf in Binary Tree<br>⭐865 Smallest Subtree with All Deepest Nodes<br>1123 LCA of Deepest Leaves<br>⭐1372 Longest ZigZag Path<br>1740 Find Distance in a Binary Tree<br>2096 Step-By-Step Directions Between Nodes<br>2467 Most Profitable Path in a Tree<br>3425 Longest Special Path<br>3486 Longest Special Path II |

---

## 🟢 Pattern 3C — Counting Paths

| Pattern | Sub-pattern | State meaning                     | Questions                                                                                                               |
| ------- | ----------- | --------------------------------- | ----------------------------------------------------------------------------------------------------------------------- |
| Path    | Count paths | prefix sum / hashmap accumulation | ⭐437 Path Sum III<br>666 Path Sum IV<br>2791 Count Paths That Can Form a Palindrome<br>2867 Count Valid Paths in a Tree |

---

## 🟢 Pattern 4A — Level-wise Logic

| Pattern | Sub-pattern   | State meaning                         | Questions                                                                                                                                                                                                                                                                                                                                                                                                                               |
| ------- | ------------- | ------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Level   | BFS per level | `queue.size()` defines level boundary | ⭐102 Level Order Traversal<br>⭐103 Zigzag Level Order Traversal<br>107 Level Order Traversal II<br>116 Populating Next Right Pointers<br>117 Populating Next Right Pointers II<br>⭐513 Find Bottom Left Tree Value<br>515 Find Largest Value in Each Tree Row<br>637 Average of Levels in Binary Tree<br>⭐662 Maximum Width of Binary Tree<br>⭐1161 Maximum Level Sum of a Binary Tree<br>2471 Minimum Operations to Sort Tree by Level |

---

## 🟢 Pattern 4B — Distance / Time

| Pattern  | Sub-pattern      | State meaning                  | Questions                                                                                                                                                                                                                                                                                           |
| -------- | ---------------- | ------------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Distance | BFS from node(s) | `distance[node] = time / hops` | 582 Kill Process<br>742 Closest Leaf in Binary Tree<br>⭐863 All Nodes Distance K in Binary Tree<br>⭐1376 Time Needed to Inform Employees<br>1443 Minimum Time to Collect All Apples<br>1740 Find Distance in a Binary Tree<br>⭐2385 Time to Infect Binary Tree<br>3241 Time Taken to Mark All Nodes |

---

## 🟢 Pattern 5 — Horizontal / Coordinate

| Pattern    | Sub-pattern         | State meaning                      | Questions                                                                                                                                         |
| ---------- | ------------------- | ---------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| Coordinate | Vertical / Boundary | `(row, col)` or boundary traversal | ⭐314 Binary Tree Vertical Order Traversal<br>545 Boundary of Binary Tree<br>655 Print Binary Tree<br>⭐987 Vertical Order Traversal of Binary Tree |

---

## 🟢 Pattern 6 — Structural Change

| Pattern  | Sub-pattern      | State meaning                      | Questions                                                                                                                                                                                                                                                                                                                                                |
| -------- | ---------------- | ---------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Mutation | Modify structure | pointer rewiring / subtree removal | ⭐114 Flatten Binary Tree to Linked List<br>156 Binary Tree Upside Down<br>226 Invert Binary Tree<br>623 Add One Row to Tree<br>814 Binary Tree Pruning<br>998 Maximum Binary Tree II<br>⭐1110 Delete Nodes and Return Forest<br>1325 Delete Leaves With a Given Value<br>1666 Change the Root of a Binary Tree<br>2415 Reverse Odd Levels of Binary Tree |

---

## 🟢 Pattern 7 — Construction

| Pattern      | Sub-pattern | State meaning               | Questions                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| ------------ | ----------- | --------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Construction | Build tree  | recursion with index bounds | ⭐105 Construct Tree from Preorder & Inorder<br>⭐106 Construct Tree from Inorder & Postorder<br>108 Convert Sorted Array to BST<br>109 Convert Sorted List to BST<br>⭐297 Serialize and Deserialize Binary Tree<br>427 Construct Quad Tree<br>428 Serialize and Deserialize N-ary Tree<br>431 Encode N-ary Tree to Binary Tree<br>536 Construct Binary Tree from String<br>⭐654 Maximum Binary Tree<br>889 Construct Tree from Preorder & Postorder<br>⭐894 All Possible Full Binary Trees<br>1008 Construct BST from Preorder<br>1028 Recover Tree from Preorder Traversal<br>2196 Create Binary Tree from Descriptions |

---

## 🟢 Pattern 8 — Validation

| Pattern    | Sub-pattern       | State meaning                    | Questions                                                                                                                                                                                                                                        |
| ---------- | ----------------- | -------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Validation | Check constraints | min/max range or global property | ⭐98 Validate Binary Search Tree<br>222 Count Complete Tree Nodes<br>255 Verify Preorder Sequence in BST<br>⭐331 Verify Preorder Serialization<br>⭐958 Check Completeness of Binary Tree<br>1361 Validate Binary Tree Nodes<br>1609 Even Odd Tree |

---

## 🟢 Pattern 9 — Ordering (BST)

| Pattern | Sub-pattern       | State meaning               | Questions                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| ------- | ----------------- | --------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| BST     | Ordered traversal | inorder monotonic invariant | ⭐230 Kth Smallest in BST<br>⭐235 LCA of BST<br>270 Closest BST Value<br>272 Closest BST Value II<br>285 Inorder Successor in BST<br>426 BST to Sorted DLL<br>⭐450 Delete Node in BST<br>501 Find Mode in BST<br>530 Minimum Absolute Difference in BST<br>538 Convert BST to Greater Tree<br>⭐653 Two Sum IV BST<br>669 Trim a BST<br>700 Search in BST<br>701 Insert into BST<br>776 Split BST<br>783 Min Distance Between BST Nodes<br>897 Increasing Order BST<br>938 Range Sum of BST<br>1214 Two Sum BSTs<br>1305 All Elements in Two BSTs<br>1382 Balance a BST<br>1586 BST Iterator II<br>2476 Closest Nodes Queries in BST |

---

## 🟢 Pattern 10 — N-ary Tree

| Pattern | Sub-pattern  | State meaning         | Questions                                                                                                                                               |
| ------- | ------------ | --------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------- |
| N-ary   | General tree | iterate children list | ⭐429 N-ary Level Order Traversal<br>⭐690 Employee Importance<br>1490 Clone N-ary Tree<br>1516 Move Subtree of N-ary Tree<br>1522 Diameter of N-ary Tree |

---

## 🟢 Pattern 11 — Complex Tree DP / Games

| Pattern | Sub-pattern    | State meaning     | Questions                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| ------- | -------------- | ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Tree DP | Multi-state DP | `dp[node][state]` | ⭐337 House Robber III<br>⭐968 Binary Tree Cameras<br>⭐979 Distribute Coins in Binary Tree<br>1145 Binary Tree Coloring Game<br>⭐1339 Maximum Product of Splitted Binary Tree<br>1617 Count Subtrees With Max Distance<br>2005 Subtree Removal Game<br>2313 Minimum Flips in Binary Tree to Get Result<br>2322 Minimum Score After Removals on Tree<br>⭐2421 Number of Good Paths<br>2581 Count Number of Possible Root Nodes<br>2646 Minimize the Total Price of the Trips<br>2920 Maximum Points After Collecting Coins |

---

### ✅ FINAL CONFIRMATION

* **Zero questions removed** ✔
* **State meaning added for every pattern** ✔
* **Interview-important questions highlighted** ✔
* **Strict table format preserved** ✔

If you want next:

* 📌 **Exact C++ template per pattern**
* 📌 **One-page printable tree cheat sheet**
* 📌 **Tree ↔ Graph hybrid mapping**

Just say which one.
