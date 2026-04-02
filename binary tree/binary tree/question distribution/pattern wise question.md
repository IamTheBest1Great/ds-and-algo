Great list.
I’ll do this **cleanly, formally, and in a way that proves completeness**, not by dumping noise.

What you asked for is **mapping**, not re-explaining trees — so below is a **pattern → question assignment**, using **exactly the 11 tree patterns you defined**.

> ✅ Every question you listed is mapped
> ✅ No new tree pattern is introduced
> ✅ Hybrids are resolved by **dominant pattern rule**

---

# 🌳 TREE PROBLEMS — COMPLETE PATTERN MAPPING

---

## 🟢 **Pattern 1 — Traversal Only (DFS / BFS, no state)**

**Rule**: Just visit nodes, maybe compare or collect.

* 94 Binary Tree Inorder Traversal
* 100 Same Tree
* 101 Symmetric Tree
* 144 Preorder Traversal
* 145 Postorder Traversal
* 199 Binary Tree Right Side View
* 226 Invert Binary Tree
* 257 Binary Tree Paths
* 341 Flatten Nested List Iterator
* 404 Sum of Left Leaves
* 572 Subtree of Another Tree
* 589 N-ary Preorder Traversal
* 590 N-ary Postorder Traversal
* 606 Construct String from Binary Tree
* 617 Merge Two Binary Trees
* 637 Average of Levels in Binary Tree
* 872 Leaf-Similar Trees
* 951 Flip Equivalent Binary Trees
* 965 Univalued Binary Tree
* 993 Cousins in Binary Tree
* 1379 Corresponding Node in Clone
* 1469 Find All the Lonely Nodes
* 1506 Find Root of N-Ary Tree
* 2236 Root Equals Sum of Children
* 2331 Evaluate Boolean Binary Tree

---

## 🟢 **Pattern 2 — Height / Subtree DP**

**Rule**: Height, depth, diameter, balance, subtree aggregation.

* 104 Maximum Depth of Binary Tree
* 110 Balanced Binary Tree
* 543 Diameter of Binary Tree
* 559 Maximum Depth of N-ary Tree
* 563 Binary Tree Tilt
* 687 Longest Univalue Path
* 1120 Maximum Average Subtree
* 1245 Tree Diameter
* 1302 Deepest Leaves Sum
* 1373 Maximum Sum BST in Binary Tree
* 1522 Diameter of N-ary Tree
* 1973 Count Nodes Equal to Sum of Descendants
* 2049 Count Nodes With Highest Score
* 2458 Height After Subtree Removal Queries
* 2773 Height of Special Binary Tree
* 3575 Maximum Good Subtree Score

---

## 🟢 **Pattern 3A — Root → Leaf Paths**

**Rule**: Accumulate value downward.

* 112 Path Sum
* 113 Path Sum II
* 129 Sum Root to Leaf Numbers
* 1022 Sum of Root to Leaf Binary Numbers
* 1080 Insufficient Nodes in Root to Leaf Paths
* 1430 Valid Sequence from Root to Leaf
* 1457 Pseudo-Palindromic Paths
* 1530 Number of Good Leaf Node Pairs
* 2385 Amount of Time to Infect Tree

---

## 🟢 **Pattern 3B — Any → Any Path (LCA / Turning Point)**

**Rule**: Path may go up then down.

* 124 Binary Tree Maximum Path Sum
* 236 Lowest Common Ancestor (Binary Tree)
* 742 Closest Leaf in Binary Tree
* 865 Smallest Subtree with Deepest Nodes
* 1123 LCA of Deepest Leaves
* 1372 Longest ZigZag Path
* 1740 Find Distance in Binary Tree
* 2096 Step-By-Step Directions Between Nodes
* 2467 Most Profitable Path in a Tree
* 3425 Longest Special Path
* 3486 Longest Special Path II

---

## 🟢 **Pattern 3C — Counting Paths**

**Rule**: Count paths satisfying condition.

* 437 Path Sum III
* 666 Path Sum IV
* 2791 Count Palindromic Paths in Tree
* 2867 Count Valid Paths in Tree

---

## 🟢 **Pattern 4A — Level-Wise Logic (BFS)**

**Rule**: Each level independent.

* 102 Level Order Traversal
* 103 Zigzag Level Order
* 107 Level Order II
* 116 / 117 Populate Next Right Pointers
* 513 Bottom Left Tree Value
* 515 Largest Value per Row
* 637 Average of Levels
* 662 Maximum Width of Binary Tree
* 1161 Maximum Level Sum
* 1302 Deepest Leaves Sum
* 2471 Sort Binary Tree by Level

---

## 🟢 **Pattern 4B — Distance / Time / Propagation**

**Rule**: BFS from node(s).

* 582 Kill Process
* 742 Closest Leaf
* 863 Nodes at Distance K
* 1376 Time Needed to Inform Employees
* 1443 Collect Apples
* 1740 Find Distance
* 2385 Time to Infect Tree
* 3241 Time Taken to Mark All Nodes

---

## 🟢 **Pattern 5 — Horizontal / Coordinate Position**

**Rule**: x-axis / vertical grouping.

* 314 Vertical Order Traversal
* 545 Boundary of Binary Tree
* 655 Print Binary Tree
* 987 Vertical Order Traversal II

---

## 🟢 **Pattern 6 — Structural Change / Mutation**

**Rule**: Modify tree shape.

* 114 Flatten Binary Tree
* 156 Binary Tree Upside Down
* 226 Invert Binary Tree
* 623 Add One Row
* 814 Binary Tree Pruning
* 998 Maximum Binary Tree II
* 1110 Delete Nodes and Return Forest
* 1325 Delete Leaves With Value
* 1666 Change the Root
* 2415 Reverse Odd Levels

---

## 🟢 **Pattern 7 — Construction**

**Rule**: Build tree from info.

* 105 / 106 Construct from Traversals
* 108 / 109 Convert Sorted → BST
* 297 Serialize & Deserialize
* 427 Construct Quad Tree
* 428 Serialize N-ary Tree
* 431 Encode N-ary to Binary
* 536 Construct Tree from String
* 654 Maximum Binary Tree
* 889 Construct from Pre/Post
* 894 All Possible Full Binary Trees
* 1008 BST from Preorder
* 1028 Recover Tree from Preorder
* 2196 Create Tree from Descriptions

---

## 🟢 **Pattern 8 — Validation**

**Rule**: Check global property.

* 98 Validate BST
* 110 Balanced Binary Tree
* 222 Count Complete Tree Nodes
* 255 Verify Preorder BST
* 331 Verify Preorder Serialization
* 958 Check Completeness
* 1361 Validate Binary Tree Nodes
* 1609 Even Odd Tree

---

## 🟢 **Pattern 9 — Ordering / BST Logic**

**Rule**: Exploit sorted property.

* 230 Kth Smallest in BST
* 235 / 236 LCA in BST / BT
* 270 / 272 Closest BST Value
* 285 Inorder Successor
* 426 BST → Doubly Linked List
* 450 Delete Node in BST
* 501 Find Mode in BST
* 530 Min Absolute Diff in BST
* 538 / 1038 Convert to Greater Tree
* 653 Two Sum IV
* 669 Trim BST
* 700 / 701 Search / Insert BST
* 776 Split BST
* 783 Min Distance Between BST Nodes
* 897 Increasing Order BST
* 938 Range Sum BST
* 1214 Two Sum BSTs
* 1305 All Elements in Two BSTs
* 1382 Balance BST
* 1586 BST Iterator II
* 2476 Closest Nodes Queries in BST

---

## 🟢 **Pattern 10 — N-Ary / General Tree**

**Rule**: More than 2 children.

* 429 N-ary Level Order
* 589 / 590 N-ary Traversals
* 690 Employee Importance
* 1490 Clone N-ary Tree
* 1516 Move Subtree
* 1522 Diameter of N-ary Tree

---

## 🟢 **Pattern 11 — Complex Tree DP / Games**

**Rule**: Multiple states per node.

* 337 House Robber III
* 968 Binary Tree Cameras
* 979 Distribute Coins
* 1145 Binary Tree Coloring Game
* 1339 Max Product of Split Tree
* 1530 Good Leaf Pairs
* 1617 Count Subtrees with Max Distance
* 2005 Subtree Removal Game
* 2313 Min Flips to Get Result
* 2322 Min Score After Removals
* 2421 Number of Good Paths
* 2581 Count Possible Root Nodes
* 2646 Minimize Trip Price
* 2920 Max Points from Coins
* 3068 Max Sum of Node Values

---

# ✅ FINAL ANSWER

> **YES — every question you listed is fully covered by the 11 tree patterns.**
> No exception.
> No missing behavior.
> No new pattern required.

If you want next:

* 📌 Table version (Pattern | Sub-pattern | Questions)
* 📌 C++ templates per pattern
* 📌 “30 must-solve tree problems” shortlist
* 📌 Hybrid decision guide (Tree + DP / Tree + Graph)

Just tell me.
