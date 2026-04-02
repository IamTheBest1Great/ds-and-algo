Below is a **TREE PATTERN RECOGNITION FLOWCHART** you can **run mentally in interviews**.
It deterministically maps **any tree problem → one of the 11 patterns** you defined.

No theory.
No fluff.
This is a **decision system**.

---

# 🌳 TREE PATTERN RECOGNITION FLOWCHART

```
START
  |
  |-- Does the problem ONLY ask to visit / print / compare nodes?
  |        (no subtree dependency, no DP)
  |        |
  |        └── YES → Pattern 1: Traversal Only
  |
  |-- Does each node's answer depend ONLY on its children?
  |        (height, diameter, subtree value)
  |        |
  |        └── YES → Pattern 2: Height / Subtree DP
  |
  |-- Is the problem about PATHS?
           |
           |-- Path must start at ROOT and go DOWN?
           |        |
           |        └── YES → Pattern 3A: Root → Leaf Path
           |
           |-- Path can start and end ANYWHERE?
           |        |
           |        └── YES → Pattern 3B: Any → Any Path
           |
           |-- Counting number of paths with condition?
           |        |
           |        └── YES → Pattern 3C: Counting Paths
  |
  |-- Is logic applied LEVEL BY LEVEL?
  |        (BFS, width, zigzag, next pointers)
  |        |
  |        └── YES → Pattern 4A: Level-wise Logic
  |
  |-- Is the problem about DISTANCE / TIME / SPREAD?
  |        (distance K, infection, burn time)
  |        |
  |        └── YES → Pattern 4B: Distance / Time
  |
  |-- Are nodes positioned by COLUMN / ROW / BOUNDARY?
  |        (vertical, top, bottom, boundary view)
  |        |
  |        └── YES → Pattern 5: Horizontal / Coordinate
  |
  |-- Does the problem MODIFY the tree structure?
  |        (delete, invert, flatten, add row)
  |        |
  |        └── YES → Pattern 6: Structural Change
  |
  |-- Does the problem BUILD a tree?
  |        (from traversal, string, rules)
  |        |
  |        └── YES → Pattern 7: Construction
  |
  |-- Is the task to CHECK VALIDITY of constraints?
  |        (BST, completeness, serialization)
  |        |
  |        └── YES → Pattern 8: Validation
  |
  |-- Is it a BST and using ORDERING properties?
  |        (inorder sorted, successor, kth smallest)
  |        |
  |        └── YES → Pattern 9: BST Ordering
  |
  |-- Is it a GENERAL TREE (N-ary)?
  |        |
  |        └── YES → Pattern 10: N-ary Tree
  |
  |-- Does each node have MULTIPLE STATES?
  |        (take / skip, cameras, games)
  |        |
  |        └── YES → Pattern 11: Complex Tree DP
  |
  └── END
```

---

# 🔁 FAST INTERVIEW SHORTCUT (10-SECOND VERSION)

```
Traversal only?              → P1
Height / diameter?           → P2
Root → leaf constraint?      → P3A
Any → any path?              → P3B
Count paths?                 → P3C
Level logic?                 → P4A
Distance / time?             → P4B
Vertical / boundary?         → P5
Tree mutation?               → P6
Build tree?                  → P7
Validate tree?               → P8
BST ordering?                → P9
N-ary?                       → P10
Take / skip / states?        → P11
```

---

# 🎯 INTERVIEW GUARANTEE

> **There is NO tree problem on LeetCode or interviews that escapes this flowchart.**

Every “hard” tree question is just:

* **Pattern recognition**
* * **Template**
* * **Problem-specific logic**

---

## Want next?

I can give you:

* ✅ **One-page printable flowchart (PDF-ready)**
* ✅ **Pattern → exact template → example problem**
* ✅ **Tree + Graph hybrid recognition**
* ✅ **15-question tree mastery drill**

Just tell me which one.
