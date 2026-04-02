# 🌳 TREE PROBLEMS — COMPLETE CATEGORIZATION (With Patterns, Sub-patterns, State Meaning)

Below is a comprehensive categorization of all tree-related LeetCode problems from your list. Each problem is placed into one of the 11 core patterns and corresponding subpatterns, with a clear **state meaning** that defines the DP or traversal approach. This table follows the same structure as before, ensuring you can quickly identify the technique needed for any problem.

---

## 🟢 Pattern 1 — Traversal Only
**State meaning:** `dfs(node)` processes the node without dependency on children’s results. Typically used for simple traversals, comparisons, or building strings.

| Sub-pattern | Questions |
| :--- | :--- |
| **DFS / BFS** | ⭐94 Binary Tree Inorder Traversal (Easy)<br>100 Same Tree (Easy)<br>⭐101 Symmetric Tree (Easy)<br>144 Binary Tree Preorder Traversal (Easy)<br>145 Binary Tree Postorder Traversal (Easy)<br>⭐199 Binary Tree Right Side View (Med)<br>⭐226 Invert Binary Tree (Easy)<br>257 Binary Tree Paths (Easy)<br>341 Flatten Nested List Iterator (Med)<br>404 Sum of Left Leaves (Easy)<br>572 Subtree of Another Tree (Easy)<br>589 N-ary Tree Preorder Traversal (Easy)<br>590 N-ary Tree Postorder Traversal (Easy)<br>606 Construct String from Binary Tree (Med)<br>617 Merge Two Binary Trees (Easy)<br>637 Average of Levels in Binary Tree (Easy)<br>671 Second Minimum Node In a Binary Tree (Easy)<br>872 Leaf-Similar Trees (Easy)<br>951 Flip Equivalent Binary Trees (Med)<br>965 Univalued Binary Tree (Easy)<br>993 Cousins in Binary Tree (Easy)<br>1315 Sum of Nodes with Even-Valued Grandparent (Med)<br>1379 Find a Corresponding Node in a Clone (Easy)<br>1448 Count Good Nodes in Binary Tree (Med)<br>1469 Find All The Lonely Nodes (Easy)<br>1485 Clone Binary Tree With Random Pointer (Med)<br>1602 Find Nearest Right Node in Binary Tree (Med)<br>1612 Check If Two Expression Trees are Equivalent (Med)<br>2236 Root Equals Sum of Children (Easy)<br>2331 Evaluate Boolean Binary Tree (Easy)<br>2368 Reachable Nodes With Restrictions (Med)<br>2689 Extract Kth Character From The Rope Tree (Easy)<br>3327 Check if DFS Strings Are Palindromes (Hard) |

---

## 🟢 Pattern 2 — Height / Subtree DP
**State meaning:** `dfs(node)` returns a value (height, sum, count, etc.) computed from its children. Used for bottom-up aggregation.

| Sub-pattern | Questions |
| :--- | :--- |
| **Bottom-up aggregation** | ⭐104 Maximum Depth of Binary Tree (Easy)<br>⭐110 Balanced Binary Tree (Easy)<br>111 Minimum Depth of Binary Tree (Easy)<br>⭐543 Diameter of Binary Tree (Easy)<br>250 Count Univalue Subtrees (Med)<br>298 Binary Tree Longest Consecutive Sequence (Med)<br>333 Largest BST Subtree (Med)<br>366 Find Leaves of Binary Tree (Med)<br>508 Most Frequent Subtree Sum (Med)<br>563 Binary Tree Tilt (Easy)<br>⭐687 Longest Univalue Path (Med)<br>652 Find Duplicate Subtrees (Med)<br>663 Equal Tree Partition (Med)<br>1120 Maximum Average Subtree (Med)<br>1245 Tree Diameter (Med)<br>1273 Delete Tree Nodes (Med)<br>1302 Deepest Leaves Sum (Med)<br>1339 Maximum Product of Splitted Binary Tree (Med)<br>1373 Maximum Sum BST in Binary Tree (Hard)<br>1519 Number of Nodes in Sub-Tree With Same Label (Med)<br>1522 Diameter of N-Ary Tree (Med)<br>1973 Count Nodes Equal to Sum of Descendants (Med)<br>2049 Count Nodes With the Highest Score (Med)<br>2265 Count Nodes Equal to Average of Subtree (Med)<br>2445 Number of Nodes With Value One (Med)<br>2477 Minimum Fuel Cost to Report to the Capital (Med)<br>2583 Kth Largest Sum in a Binary Tree (Med)<br>2673 Make Costs of Paths Equal in a Binary Tree (Med)<br>2773 Height of Special Binary Tree (Med)<br>2792 Count Nodes That Are Great Enough (Hard)<br>2872 Maximum Number of K-Divisible Components (Hard)<br>3004 Maximum Subtree of the Same Color (Med)<br>3067 Count Pairs of Connectable Servers in a Weighted Tree Network (Med)<br>3157 Find the Level of Tree with Minimum Sum (Med)<br>3203 Find Minimum Diameter After Merging Two Trees (Hard)<br>3249 Count the Number of Good Nodes (Med)<br>3319 K-th Largest Perfect Subtree Size in Binary Tree (Med)<br>3331 Find Subtree Sizes After Changes (Med)<br>3544 Subtree Inversion Sum (Hard)<br>3575 Maximum Good Subtree Score (Hard)<br>3585 Find Weighted Median Node in Tree (Hard)<br>3593 Minimum Increments to Equalize Leaf Paths (Med)<br>3715 Sum of Perfect Square Ancestors (Hard)<br>3787 Find Diameter Endpoints of a Tree (Med) |

---

## 🟢 Pattern 3A — Root → Leaf Paths
**State meaning:** `dfs(node, pathState)` propagates a prefix (sum, string, max/min) down the path.

| Sub-pattern | Questions |
| :--- | :--- |
| **Root → Leaf** | ⭐112 Path Sum (Easy)<br>⭐113 Path Sum II (Med)<br>129 Sum Root to Leaf Numbers (Med)<br>257 Binary Tree Paths (Easy)<br>988 Smallest String Starting From Leaf (Med)<br>1022 Sum of Root To Leaf Binary Numbers (Easy)<br>1026 Maximum Difference Between Node and Ancestor (Med)<br>1080 Insufficient Nodes in Root to Leaf Paths (Med)<br>1104 Path In Zigzag Labelled Binary Tree (Med)<br>1430 Check If a String Is a Valid Sequence from Root to Leaves Path (Med)<br>1448 Count Good Nodes in Binary Tree (Med)<br>⭐1457 Pseudo-Palindromic Paths in a Binary Tree (Med) |

---

## 🟢 Pattern 3B — Any → Any Path (LCA, max path, zigzag)
**State meaning:** `dfs(node)` returns the best upward path, and global answer is updated using left+right combinations.

| Sub-pattern | Questions |
| :--- | :--- |
| **Any → Any (LCA / Path)** | ⭐124 Binary Tree Maximum Path Sum (Hard)<br>⭐236 Lowest Common Ancestor of a Binary Tree (Med)<br>298 Binary Tree Longest Consecutive Sequence (Med)<br>549 Binary Tree Longest Consecutive Sequence II (Med)<br>742 Closest Leaf in a Binary Tree (Med)<br>⭐865 Smallest Subtree with all the Deepest Nodes (Med)<br>1123 Lowest Common Ancestor of Deepest Leaves (Med)<br>⭐1372 Longest ZigZag Path in a Binary Tree (Med)<br>1530 Number of Good Leaf Nodes Pairs (Med)<br>1644 Lowest Common Ancestor of a Binary Tree II (Med)<br>1650 Lowest Common Ancestor of a Binary Tree III (Med)<br>1676 Lowest Common Ancestor of a Binary Tree IV (Med)<br>1740 Find Distance in a Binary Tree (Med)<br>2096 Step-By-Step Directions From a Binary Tree Node to Another (Med)<br>2246 Longest Path With Different Adjacent Characters (Hard)<br>2421 Number of Good Paths (Hard)<br>2467 Most Profitable Path in a Tree (Med)<br>3425 Longest Special Path (Hard)<br>3486 Longest Special Path II (Hard)<br>3590 Kth Smallest Path XOR Sum (Hard) |

---

## 🟢 Pattern 3C — Counting Paths
**State meaning:** Uses prefix sum / hashmap to count paths with given property (often from root or any node).

| Sub-pattern | Questions |
| :--- | :--- |
| **Count paths** | ⭐437 Path Sum III (Med)<br>666 Path Sum IV (Med)<br>2791 Count Paths That Can Form a Palindrome in a Tree (Hard)<br>2867 Count Valid Paths in a Tree (Hard) |

---

## 🟢 Pattern 4A — Level-wise Logic
**State meaning:** BFS where `queue.size()` defines level boundaries; often used for level-order traversals and level-based computations.

| Sub-pattern | Questions |
| :--- | :--- |
| **BFS per level** | ⭐102 Binary Tree Level Order Traversal (Med)<br>⭐103 Binary Tree Zigzag Level Order Traversal (Med)<br>107 Binary Tree Level Order Traversal II (Med)<br>116 Populating Next Right Pointers in Each Node (Med)<br>117 Populating Next Right Pointers in Each Node II (Med)<br>⭐513 Find Bottom Left Tree Value (Med)<br>515 Find Largest Value in Each Tree Row (Med)<br>637 Average of Levels in Binary Tree (Easy)<br>⭐662 Maximum Width of Binary Tree (Med)<br>919 Complete Binary Tree Inserter (Med)<br>⭐1161 Maximum Level Sum of a Binary Tree (Med)<br>1602 Find Nearest Right Node in Binary Tree (Med)<br>1609 Even Odd Tree (Med)<br>2471 Minimum Number of Operations to Sort a Binary Tree by Level (Med)<br>2583 Kth Largest Sum in a Binary Tree (Med)<br>2641 Cousins in Binary Tree II (Med)<br>3157 Find the Level of Tree with Minimum Sum (Med) |

---

## 🟢 Pattern 4B — Distance / Time
**State meaning:** BFS from one or multiple nodes to compute distances (time, hops) in a tree.

| Sub-pattern | Questions |
| :--- | :--- |
| **BFS from node(s)** | 582 Kill Process (Med)<br>742 Closest Leaf in a Binary Tree (Med)<br>⭐863 All Nodes Distance K in Binary Tree (Med)<br>⭐1376 Time Needed to Inform All Employees (Med)<br>1377 Frog Position After T Seconds (Hard)<br>1443 Minimum Time to Collect All Apples in a Tree (Med)<br>1740 Find Distance in a Binary Tree (Med)<br>⭐2385 Amount of Time for Binary Tree to Be Infected (Med)<br>2277 Closest Node to Path in Tree (Hard)<br>2603 Collect Coins in a Tree (Hard)<br>3241 Time Taken to Mark All Nodes (Hard) |

---

## 🟢 Pattern 5 — Horizontal / Coordinate
**State meaning:** Uses `(row, col)` coordinates or boundary order to traverse the tree in vertical or boundary order.

| Sub-pattern | Questions |
| :--- | :--- |
| **Vertical / Boundary** | ⭐314 Binary Tree Vertical Order Traversal (Med)<br>545 Boundary of Binary Tree (Med)<br>655 Print Binary Tree (Med)<br>⭐987 Vertical Order Traversal of a Binary Tree (Hard) |

---

## 🟢 Pattern 6 — Structural Change
**State meaning:** Modifies the tree structure (pointer rewiring, subtree removal, insertion) often via recursion.

| Sub-pattern | Questions |
| :--- | :--- |
| **Modify structure** | ⭐114 Flatten Binary Tree to Linked List (Med)<br>156 Binary Tree Upside Down (Med)<br>226 Invert Binary Tree (Easy)<br>623 Add One Row to Tree (Med)<br>814 Binary Tree Pruning (Med)<br>998 Maximum Binary Tree II (Med)<br>⭐1110 Delete Nodes And Return Forest (Med)<br>1325 Delete Leaves With a Given Value (Med)<br>1666 Change the Root of a Binary Tree (Med)<br>2415 Reverse Odd Levels of Binary Tree (Med)<br>99 Recover Binary Search Tree (Med)<br>426 Convert BST to Sorted Doubly Linked List (Med)<br>450 Delete Node in a BST (Med)<br>538 Convert BST to Greater Tree (Med)<br>669 Trim a BST (Med)<br>701 Insert into a BST (Med)<br>776 Split BST (Med)<br>897 Increasing Order Search Tree (Easy)<br>971 Flip Binary Tree To Match Preorder Traversal (Med)<br>1038 BST to Greater Sum Tree (Med)<br>1080 Insufficient Nodes in Root to Leaf Paths (Med)<br>1382 Balance a BST (Med)<br>1516 Move Sub-Tree of N-Ary Tree (Hard)<br>1660 Correct a Binary Tree (Med)<br>1993 Operations on Tree (Med) |

---

## 🟢 Pattern 7 — Construction
**State meaning:** Builds a tree from given traversals or representations using recursion with index bounds.

| Sub-pattern | Questions |
| :--- | :--- |
| **Build tree** | ⭐105 Construct Tree from Preorder & Inorder (Med)<br>⭐106 Construct Tree from Inorder & Postorder (Med)<br>108 Convert Sorted Array to BST (Easy)<br>109 Convert Sorted List to BST (Med)<br>⭐297 Serialize and Deserialize Binary Tree (Hard)<br>427 Construct Quad Tree (Med)<br>428 Serialize and Deserialize N-ary Tree (Hard)<br>431 Encode N-ary Tree to Binary Tree (Hard)<br>536 Construct Binary Tree from String (Med)<br>⭐654 Maximum Binary Tree (Med)<br>889 Construct Tree from Preorder & Postorder (Med)<br>⭐894 All Possible Full Binary Trees (Med)<br>1008 Construct BST from Preorder (Med)<br>1028 Recover Tree from Preorder Traversal (Hard)<br>2196 Create Binary Tree From Descriptions (Med)<br>1597 Build Binary Expression Tree From Infix Expression (Hard)<br>1628 Design an Expression Tree With Evaluate Function (Med)<br>1932 Merge BSTs to Create Single BST (Hard) |

---

## 🟢 Pattern 8 — Validation
**State meaning:** Checks tree properties (BST, completeness, etc.) using constraints (min/max range) or global counters.

| Sub-pattern | Questions |
| :--- | :--- |
| **Check constraints** | ⭐98 Validate Binary Search Tree (Med)<br>222 Count Complete Tree Nodes (Easy)<br>255 Verify Preorder Sequence in BST (Med)<br>⭐331 Verify Preorder Serialization (Med)<br>⭐958 Check Completeness of a Binary Tree (Med)<br>1361 Validate Binary Tree Nodes (Med)<br>1609 Even Odd Tree (Med)<br>2764 Is Array a Preorder of Some Binary Tree (Med) |

---

## 🟢 Pattern 9 — Ordering (BST)
**State meaning:** Uses inorder traversal or BST properties to solve problems related to order, successors, or range queries.

| Sub-pattern | Questions |
| :--- | :--- |
| **BST / Inorder** | ⭐230 Kth Smallest in BST (Med)<br>⭐235 LCA of BST (Med)<br>270 Closest BST Value (Easy)<br>272 Closest BST Value II (Hard)<br>285 Inorder Successor in BST (Med)<br>426 BST to Sorted DLL (Med)<br>⭐450 Delete Node in BST (Med)<br>501 Find Mode in BST (Easy)<br>510 Inorder Successor in BST II (Med)<br>530 Minimum Absolute Difference in BST (Easy)<br>538 Convert BST to Greater Tree (Med)<br>⭐653 Two Sum IV BST (Easy)<br>669 Trim BST (Med)<br>700 Search in BST (Easy)<br>701 Insert into BST (Med)<br>703 Kth Largest in Stream (Easy) – (though not strictly tree, often related)<br>776 Split BST (Med)<br>783 Min Distance Between BST Nodes (Easy)<br>897 Increasing Order BST (Easy)<br>938 Range Sum of BST (Easy)<br>1008 Construct BST from Preorder (Med)<br>1038 BST to Greater Sum Tree (Med)<br>1214 Two Sum BSTs (Med)<br>1305 All Elements in Two BSTs (Med)<br>1382 Balance a BST (Med)<br>1586 BST Iterator II (Med)<br>1902 Depth of BST Given Insertion Order (Med)<br>2476 Closest Nodes Queries in BST (Med) |

---

## 🟢 Pattern 10 — N-ary Tree
**State meaning:** Problems on general trees where each node has a list of children; traversal or DP adapts to iterate over children.

| Sub-pattern | Questions |
| :--- | :--- |
| **General tree** | ⭐429 N-ary Level Order Traversal (Med)<br>⭐559 Maximum Depth of N-ary Tree (Easy)<br>589 N-ary Preorder (Easy)<br>590 N-ary Postorder (Easy)<br>⭐690 Employee Importance (Med)<br>1490 Clone N-ary Tree (Med)<br>1506 Find Root of N-Ary Tree (Med)<br>1516 Move Sub-Tree of N-Ary Tree (Hard)<br>1519 Number of Nodes with Same Label (Med)<br>1522 Diameter of N-Ary Tree (Med)<br>1600 Throne Inheritance (Med)<br>1617 Count Subtrees With Max Distance Between Cities (Hard)<br>1916 Count Ways to Build Rooms in an Ant Colony (Hard) |

---

## 🟢 Pattern 11 — Complex Tree DP / Games
**State meaning:** Multi-state DP on trees, often with states like `dp[node][state]` for problems involving cameras, coins, coloring, or game theory.

| Sub-pattern | Questions |
| :--- | :--- |
| **Multi-state DP** | ⭐337 House Robber III (Med)<br>⭐968 Binary Tree Cameras (Hard)<br>⭐979 Distribute Coins in Binary Tree (Med)<br>1145 Binary Tree Coloring Game (Med)<br>⭐1339 Maximum Product of Splitted Binary Tree (Med)<br>1373 Maximum Sum BST in Binary Tree (Hard)<br>1569 Number of Ways to Reorder Array to Get Same BST (Hard)<br>1617 Count Subtrees With Max Distance Between Cities (Hard)<br>1719 Number Of Ways To Reconstruct A Tree (Hard)<br>1916 Count Ways to Build Rooms in an Ant Colony (Hard)<br>2003 Smallest Missing Genetic Value in Each Subtree (Hard)<br>2005 Subtree Removal Game with Fibonacci Tree (Hard)<br>2049 Count Nodes With Highest Score (Med)<br>2246 Longest Path With Different Adjacent Characters (Hard)<br>2313 Minimum Flips in Binary Tree to Get Result (Hard)<br>2322 Minimum Score After Removals on a Tree (Hard)<br>2378 Choose Edges to Maximize Score in a Tree (Med)<br>2421 Number of Good Paths (Hard)<br>2440 Create Components With Same Value (Hard)<br>2467 Most Profitable Path in a Tree (Med)<br>2479 Maximum XOR of Two Non-Overlapping Subtrees (Hard)<br>2509 Cycle Length Queries in a Tree (Hard)<br>2538 Difference Between Maximum and Minimum Price Sum (Hard)<br>2581 Count Number of Possible Root Nodes (Hard)<br>2603 Collect Coins in a Tree (Hard)<br>2646 Minimize the Total Price of the Trips (Hard)<br>2791 Count Paths That Can Form a Palindrome in a Tree (Hard)<br>2846 Minimum Edge Weight Equilibrium Queries (Hard)<br>2867 Count Valid Paths in a Tree (Hard)<br>2920 Maximum Points After Collecting Coins From All Nodes (Hard)<br>2925 Maximum Score After Applying Operations on a Tree (Med)<br>2973 Find Number of Coins to Place in Tree Nodes (Hard)<br>3068 Find the Maximum Sum of Node Values (Hard)<br>3241 Time Taken to Mark All Nodes (Hard)<br>3313 Find the Last Marked Nodes in Tree (Hard)<br>3367 Maximize Sum of Weights after Edge Removals (Hard)<br>3372, 3373 Maximize Target Nodes (Med/Hard)<br>3425 Longest Special Path (Hard)<br>3486 Longest Special Path II (Hard)<br>3515 Shortest Path in a Weighted Tree (Hard)<br>3544 Subtree Inversion Sum (Hard)<br>3553, 3558, 3559 Edge Weight Assignments (Med/Hard)<br>3575 Maximum Good Subtree Score (Hard)<br>3585 Find Weighted Median Node (Hard)<br>3590 Kth Smallest Path XOR Sum (Hard)<br>3593 Minimum Increments to Equalize Leaf Paths (Med)<br>3715 Sum of Perfect Square Ancestors (Hard)<br>3772 Maximum Subgraph Score in a Tree (Hard)<br>3786 Total Sum of Interaction Cost (Hard)<br>3812 Minimum Edge Toggles (Hard)<br>3820 Pythagorean Distance Nodes (Med) |

---

### ✅ Summary

This table organizes **over 300 tree problems** from your list into 11 core patterns and their subpatterns. Each problem is placed according to the primary technique required, with a clear **state meaning** to guide your solution approach. Use this as a roadmap to master tree problems on LeetCode.

If you need further refinement, templates for any pattern, or explanations for specific problems, feel free to ask!
