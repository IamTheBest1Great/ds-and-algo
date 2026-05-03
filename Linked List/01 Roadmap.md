# 🔗 Linked List Mastery Guide — 95% Interview Coverage

> **Goal**: Solve 95% of all linked list interview questions with pattern recognition, not memorization.
> **Method**: 10 patterns → recognition flowchart → templates → curated problem set.

---

## 📌 Table of Contents

1. [Pattern Recognition Flowchart](#pattern-recognition-flowchart)
2. [Pattern 1 — Fast and Slow Pointers](#pattern-1--fast-and-slow-pointers)
3. [Pattern 2 — Reversal](#pattern-2--reversal)
4. [Pattern 3 — Merge / Sort](#pattern-3--merge--sort)
5. [Pattern 4 — Two Pointers / Remove Nodes](#pattern-4--two-pointers--remove-nodes)
6. [Pattern 5 — Dummy Head Technique](#pattern-5--dummy-head-technique)
7. [Pattern 6 — In-Place Modification](#pattern-6--in-place-modification)
8. [Pattern 7 — Linked List + HashMap](#pattern-7--linked-list--hashmap)
9. [Pattern 8 — Recursive Linked List](#pattern-8--recursive-linked-list)
10. [Pattern 9 — Design Linked List Structures](#pattern-9--design-linked-list-structures)
11. [Pattern 10 — Math on Linked Lists](#pattern-10--math-on-linked-lists)
12. [30-Day Mastery Roadmap](#30-day-mastery-roadmap)
13. [Hybrid Decision Guide](#hybrid-decision-guide)

---

## Pattern Recognition Flowchart

```
START — Read the problem statement
         |
         v
Does the problem involve CYCLE DETECTION or finding MIDDLE / Nth FROM END?
(Detect cycle, find cycle start, middle node, Kth from end)
         |
        YES ──────────────────────────► Pattern 1: Fast and Slow Pointers
         |
         v
Does the problem ask to REVERSE all or part of the list?
(Reverse entire list, reverse k-group, reverse between positions)
         |
        YES ──────────────────────────► Pattern 2: Reversal
         |
         v
Does the problem MERGE or SORT linked lists?
(Merge two sorted lists, merge K lists, sort a linked list)
         |
        YES ──────────────────────────► Pattern 3: Merge / Sort
         |
         v
Does the problem REMOVE or FIND nodes by position or value?
(Remove Nth from end, remove duplicates, delete node)
         |
        YES ──────────────────────────► Pattern 4: Two Pointers / Remove
         |
         v
Does inserting a DUMMY HEAD simplify edge cases?
(Insert at beginning, delete head, merge at boundaries)
         |
        YES ──────────────────────────► Pattern 5: Dummy Head
         |
         v
Does the problem MODIFY the list structure IN-PLACE?
(Flatten, rotate, reorder, partition, odd-even)
         |
        YES ──────────────────────────► Pattern 6: In-Place Modification
         |
         v
Does the problem use a HASHMAP alongside the list?
(Clone with random pointer, detect cycle, LRU cache)
         |
        YES ──────────────────────────► Pattern 7: Linked List + HashMap
         |
         v
Does RECURSION naturally model the list's structure?
(Reverse recursively, merge recursively, palindrome check)
         |
        YES ──────────────────────────► Pattern 8: Recursive
         |
         v
Does the problem ask to DESIGN a data structure using linked lists?
(LRU cache, LFU cache, browser history, skiplist)
         |
        YES ──────────────────────────► Pattern 9: Design Structures
         |
         v
Does the problem perform ARITHMETIC on numbers stored in lists?
(Add two numbers, multiply, sum in reverse)
         |
        YES ──────────────────────────► Pattern 10: Math on Lists
         |
         v
        END
```

### 10-Second Interview Shortcut

| Signal in problem | Pattern |
|---|---|
| Cycle, middle, Nth from end | P1 — Fast & Slow |
| Reverse all or part of list | P2 — Reversal |
| Merge two/K sorted lists | P3 — Merge/Sort |
| Remove by position or value | P4 — Two Pointers |
| Edge cases at head/tail | P5 — Dummy Head |
| Flatten, rotate, reorder | P6 — In-Place Modify |
| Clone with random, LRU | P7 — HashMap |
| Natural recursive structure | P8 — Recursive |
| Design LRU/LFU/skiplist | P9 — Design |
| Add numbers as linked lists | P10 — Math |

---

## Pattern 1 — Fast and Slow Pointers

### Notes and Theory

**What it is**: Two pointers moving at different speeds through the list. Fast pointer moves 2 steps, slow moves 1 step. When fast reaches the end, slow is at the middle. If they ever meet, there's a cycle.

**How to identify**:
- "Detect cycle in linked list"
- "Find middle node"
- "Find Nth node from end"
- "Palindrome check"
- Keywords: "cycle", "middle", "Nth from end", "meets"

**Cycle Detection — Floyd's Algorithm (141)**:
```cpp
bool hasCycle(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true; // cycle
    }
    return false;
}
```

**Find Cycle Start (142)**:
```cpp
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head; // reset slow to head
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next; // both move 1 step
            }
            return slow; // meeting point = cycle start
        }
    }
    return nullptr;
}
```

**Find Middle (876)**:
```cpp
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // for even length: returns second middle
}
```

**Nth from End (19)**:
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0, head);
    ListNode* fast = &dummy, *slow = &dummy;
    for (int i = 0; i <= n; i++) fast = fast->next; // offset fast by n+1
    while (fast) { slow = slow->next; fast = fast->next; }
    slow->next = slow->next->next; // remove Nth from end
    return dummy.next;
}
```

**Key insight**: Fast at 2x speed → when fast finishes (length L), slow is at L/2 = middle. For Nth from end: offset fast by N steps so both reach the end simultaneously. Slow then points to N+1th from end.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 141 | Linked List Cycle | Easy | Floyd's detection |
| 142 | Linked List Cycle II | Medium | Find cycle start |
| 876 | Middle of the Linked List | Easy | Fast/slow middle |
| 19 | Remove Nth Node From End | Medium | Offset-N trick |
| 234 | Palindrome Linked List | Easy | Middle + reverse |
| 457 | Circular Array Loop | Medium | Floyd's on array |
| 2095 | Delete the Middle Node | Medium | Find middle + remove |
| 2130 | Maximum Twin Sum | Medium | Middle + reverse |

### All Problems in Pattern 1

- 19 Remove Nth Node From End of List
- 141 Linked List Cycle
- 142 Linked List Cycle II
- 160 Intersection of Two Linked Lists
- 234 Palindrome Linked List
- 457 Circular Array Loop
- 876 Middle of the Linked List
- 1721 Swapping Nodes in a Linked List
- 2095 Delete the Middle Node of a Linked List
- 2130 Maximum Twin Sum of a Linked List

---

## Pattern 2 — Reversal

### Notes and Theory

**What it is**: Reverse the direction of pointers in a linked list — either the entire list, a portion between two indices, or groups of K nodes. Core operation: maintain `prev`, `curr`, `next` pointers.

**How to identify**:
- "Reverse a linked list"
- "Reverse between positions L and R"
- "Reverse in groups of K"
- Keywords: "reverse", "flip", "invert order"

**Reverse Entire List (206)**:
```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr, *curr = head;
    while (curr) {
        ListNode* next = curr->next; // save next
        curr->next = prev;           // reverse pointer
        prev = curr;                 // advance prev
        curr = next;                 // advance curr
    }
    return prev; // new head
}
```

**Reverse Between L and R (92)**:
```cpp
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy(0, head);
    ListNode* pre = &dummy;

    // Move pre to node just before position left
    for (int i = 0; i < left - 1; i++) pre = pre->next;

    ListNode* curr = pre->next;
    for (int i = 0; i < right - left; i++) {
        ListNode* next = curr->next;
        curr->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummy.next;
}
```

**Reverse K-Group (25)**:
```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    // Check if k nodes remain
    ListNode* check = head;
    for (int i = 0; i < k; i++) {
        if (!check) return head; // fewer than k nodes: don't reverse
        check = check->next;
    }
    // Reverse k nodes
    ListNode* prev = nullptr, *curr = head;
    for (int i = 0; i < k; i++) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = reverseKGroup(curr, k); // head is now tail of reversed group
    return prev; // prev is new head
}
```

**Key insight**: The three-pointer technique (`prev`, `curr`, `next`) is fundamental. For reversal between positions: use a dummy node before the segment. For K-group: check if K nodes exist before reversing.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 206 | Reverse Linked List | Easy | Core reversal |
| 92 | Reverse Linked List II | Medium | Reverse between positions |
| 25 | Reverse Nodes in K-Group | Hard | Recursive K-group |
| 24 | Swap Nodes in Pairs | Medium | K=2 special case |
| 2074 | Reverse Nodes in Even Length Groups | Medium | Conditional reversal |
| 1721 | Swapping Nodes in a Linked List | Medium | Find + swap values |
| 2816 | Double a Number Represented as Linked List | Medium | Reverse + add |

### All Problems in Pattern 2

- 24 Swap Nodes in Pairs
- 25 Reverse Nodes in K-Group
- 92 Reverse Linked List II
- 206 Reverse Linked List
- 1721 Swapping Nodes in a Linked List
- 2074 Reverse Nodes in Even Length Groups
- 2130 Maximum Twin Sum of a Linked List
- 2816 Double a Number Represented as a Linked List

---

## Pattern 3 — Merge / Sort

### Notes and Theory

**What it is**: Combine two or more sorted linked lists into one sorted list, or sort an unsorted list. Merge sort is ideal for linked lists because it doesn't require random access.

**How to identify**:
- "Merge two sorted lists"
- "Merge K sorted lists"
- "Sort a linked list"
- Keywords: "merge", "sorted", "combine", "sort"

**Merge Two Sorted Lists (21)**:
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) { curr->next = l1; l1 = l1->next; }
        else                    { curr->next = l2; l2 = l2->next; }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2; // attach remaining
    return dummy.next;
}
```

**Merge K Sorted Lists (23) — divide and conquer**:
```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    int n = lists.size();
    while (n > 1) {
        for (int i = 0; i < n / 2; i++)
            lists[i] = mergeTwoLists(lists[i], lists[n-1-i]);
        n = (n + 1) / 2;
    }
    return lists[0];
}
```

**Sort List (148) — Merge Sort**:
```cpp
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    // Find middle and split
    ListNode* slow = head, *fast = head->next;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    ListNode* mid = slow->next;
    slow->next = nullptr; // split into two halves

    // Recursively sort both halves then merge
    return mergeTwoLists(sortList(head), sortList(mid));
}
```

**Key insight**: Always use a dummy node as the head of the merged list to avoid special-casing the first node. Merge sort on linked lists is O(n log n) time and O(log n) space (recursion stack).

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 21 | Merge Two Sorted Lists | Easy | Core merge with dummy |
| 23 | Merge K Sorted Lists | Hard | Divide and conquer merge |
| 148 | Sort List | Medium | Merge sort on list |
| 147 | Insertion Sort List | Medium | In-place insertion sort |
| 1669 | Merge In Between Linked Lists | Medium | Splice sub-list |
| 2181 | Merge Nodes in Between Zeros | Medium | Accumulate between zeros |

### All Problems in Pattern 3

- 21 Merge Two Sorted Lists
- 23 Merge K Sorted Lists
- 147 Insertion Sort List
- 148 Sort List
- 1669 Merge In Between Linked Lists
- 2181 Merge Nodes in Between Zeros

---

## Pattern 4 — Two Pointers / Remove Nodes

### Notes and Theory

**What it is**: Use two pointers to find and remove nodes by position, value, or condition. One pointer finds the node to remove; the other maintains the predecessor to re-link.

**How to identify**:
- "Remove Nth node from end"
- "Remove all nodes with value X"
- "Remove duplicates"
- Keywords: "remove", "delete", "eliminate duplicates"

**Remove Nth From End (19)** — see Pattern 1.

**Remove Duplicates from Sorted List (83)**:
```cpp
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;
    while (curr && curr->next) {
        if (curr->val == curr->next->val)
            curr->next = curr->next->next; // skip duplicate
        else
            curr = curr->next;
    }
    return head;
}
```

**Remove All Duplicates (82) — keep only unique**:
```cpp
ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* prev = &dummy;

    while (prev->next) {
        ListNode* curr = prev->next;
        // Check if curr is a duplicate
        if (curr->next && curr->val == curr->next->val) {
            int dupVal = curr->val;
            while (prev->next && prev->next->val == dupVal)
                prev->next = prev->next->next; // skip all with dupVal
        } else {
            prev = prev->next;
        }
    }
    return dummy.next;
}
```

**Remove Linked List Elements (203)**:
```cpp
ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0, head);
    ListNode* curr = &dummy;
    while (curr->next) {
        if (curr->next->val == val) curr->next = curr->next->next;
        else curr = curr->next;
    }
    return dummy.next;
}
```

**Key insight**: Always use a dummy node before the head when removing nodes — it eliminates the special case of removing the head itself. The predecessor pointer is the key to O(1) deletion.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 19 | Remove Nth Node From End | Medium | Fast/slow offset |
| 83 | Remove Duplicates from Sorted List | Easy | Skip duplicate |
| 82 | Remove Duplicates II (keep unique) | Medium | Skip all duplicates |
| 203 | Remove Linked List Elements | Easy | Dummy + predecessor |
| 1171 | Remove Zero Sum Consecutive Nodes | Medium | Prefix sum + hashmap |
| 2487 | Remove Nodes From Linked List | Medium | Monotonic stack |
| 2095 | Delete the Middle Node | Medium | Fast/slow + remove |

### All Problems in Pattern 4

- 19 Remove Nth Node From End of List
- 82 Remove Duplicates from Sorted List II
- 83 Remove Duplicates from Sorted List
- 203 Remove Linked List Elements
- 237 Delete Node in a Linked List
- 1171 Remove Zero Sum Consecutive Nodes from Linked List
- 2095 Delete the Middle Node of a Linked List
- 2487 Remove Nodes From Linked List

---

## Pattern 5 — Dummy Head Technique

### Notes and Theory

**What it is**: Create a dummy (sentinel) node before the actual head. Its `next` pointer always points to the current head. This eliminates edge cases when inserting/deleting at the beginning of the list.

**How to identify**:
- The head itself might be deleted or changed
- Inserting nodes at the front
- Merging lists where result head is unknown
- Keywords: any problem where head changes

**Why dummy head works**:
```cpp
ListNode dummy(0);    // val doesn't matter
dummy.next = head;    // dummy.next = true head
ListNode* prev = &dummy;

// After operations:
return dummy.next;    // always correct new head
```

**Partition List (86)**:
```cpp
ListNode* partition(ListNode* head, int x) {
    ListNode lessHead(0), greaterHead(0);
    ListNode* less = &lessHead, *greater = &greaterHead;

    ListNode* curr = head;
    while (curr) {
        if (curr->val < x) { less->next = curr; less = less->next; }
        else { greater->next = curr; greater = greater->next; }
        curr = curr->next;
    }
    greater->next = nullptr;   // terminate greater list
    less->next = greaterHead.next; // connect less to greater
    return lessHead.next;
}
```

**Odd Even Linked List (328)**:
```cpp
ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;
    ListNode* odd = head, *even = head->next;
    ListNode* evenHead = even;
    while (even && even->next) {
        odd->next = even->next;  // link odd nodes
        odd = odd->next;
        even->next = odd->next;  // link even nodes
        even = even->next;
    }
    odd->next = evenHead; // connect odd list to even list
    return head;
}
```

**Key insight**: Two dummy heads (for less and greater, or odd and even) let you build two parallel lists simultaneously without worrying about empty list edge cases.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 21 | Merge Two Sorted Lists | Easy | Dummy head merge |
| 86 | Partition List | Medium | Two dummy lists |
| 328 | Odd Even Linked List | Medium | Two-list separation |
| 203 | Remove Linked List Elements | Easy | Dummy handles head removal |
| 82 | Remove Duplicates II | Medium | Dummy + predecessor |
| 1669 | Merge In Between Linked Lists | Medium | Dummy splice |

### All Problems in Pattern 5

- 21 Merge Two Sorted Lists
- 82 Remove Duplicates from Sorted List II
- 86 Partition List
- 203 Remove Linked List Elements
- 328 Odd Even Linked List
- 1669 Merge In Between Linked Lists
- 2181 Merge Nodes in Between Zeros

---

## Pattern 6 — In-Place Modification

### Notes and Theory

**What it is**: Restructure the linked list in-place without extra memory. Involves re-wiring pointers to achieve rotation, flattening, reordering, or rearrangement.

**How to identify**:
- "Rotate the list by K positions"
- "Flatten a multilevel list"
- "Reorder list (first + last interleaved)"
- Keywords: "reorder", "flatten", "rotate", "rearrange", "in-place"

**Reorder List (143)**:
```cpp
void reorderList(ListNode* head) {
    // Step 1: Find middle
    ListNode* slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next; fast = fast->next->next;
    }
    // Step 2: Reverse second half
    ListNode* second = slow->next;
    slow->next = nullptr;
    ListNode* prev = nullptr, *curr = second;
    while (curr) { ListNode* next = curr->next; curr->next = prev; prev = curr; curr = next; }
    second = prev;
    // Step 3: Merge interleaved
    ListNode* first = head;
    while (second) {
        ListNode* tmp1 = first->next, *tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
    }
}
```

**Rotate List (61)**:
```cpp
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    // Find length and tail
    int len = 1;
    ListNode* tail = head;
    while (tail->next) { tail = tail->next; len++; }
    // Make circular
    tail->next = head;
    // Find new tail: (len - k % len - 1) steps from head
    int steps = len - k % len - 1;
    ListNode* newTail = head;
    for (int i = 0; i < steps; i++) newTail = newTail->next;
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}
```

**Flatten Multilevel List (430)**:
```cpp
Node* flatten(Node* head) {
    Node* curr = head;
    while (curr) {
        if (curr->child) {
            Node* child = curr->child;
            Node* next = curr->next;
            // Insert child list between curr and next
            curr->next = child;
            child->prev = curr;
            curr->child = nullptr;
            // Find tail of child list
            Node* tail = child;
            while (tail->next) tail = tail->next;
            tail->next = next;
            if (next) next->prev = tail;
        }
        curr = curr->next;
    }
    return head;
}
```

**Key insight**: Reorder List = find middle + reverse second half + merge. This avoids O(n) extra space. Rotation = form circle + cut at right position. Flattening = insert child list inline.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 143 | Reorder List | Medium | Middle + reverse + merge |
| 61 | Rotate List | Medium | Form cycle + cut |
| 430 | Flatten a Multilevel Doubly Linked List | Medium | Insert child inline |
| 328 | Odd Even Linked List | Medium | Two-list interleave |
| 725 | Split Linked List in Parts | Medium | Distribute evenly |
| 1290 | Convert Binary Number to Integer | Easy | Traverse + compute |

### All Problems in Pattern 6

- 61 Rotate List
- 143 Reorder List
- 328 Odd Even Linked List
- 430 Flatten a Multilevel Doubly Linked List
- 725 Split Linked List in Parts
- 1290 Convert Binary Number in a Linked List to Integer
- 2074 Reverse Nodes in Even Length Groups

---

## Pattern 7 — Linked List + HashMap

### Notes and Theory

**What it is**: Use a hashmap alongside the linked list to enable O(1) lookups by value or node reference. Essential for cloning, LRU cache, and cycle detection by node identity.

**How to identify**:
- "Clone a linked list with random pointers"
- "LRU Cache"
- "Find node by value in O(1)"
- Keywords: "clone", "copy", "random pointer", "cache", "O(1) access"

**Clone List with Random Pointer (138)**:
```cpp
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    unordered_map<Node*, Node*> oldToNew; // original -> copy

    // Pass 1: create all copy nodes
    Node* curr = head;
    while (curr) {
        oldToNew[curr] = new Node(curr->val);
        curr = curr->next;
    }
    // Pass 2: wire next and random pointers
    curr = head;
    while (curr) {
        oldToNew[curr]->next   = oldToNew[curr->next];
        oldToNew[curr]->random = oldToNew[curr->random];
        curr = curr->next;
    }
    return oldToNew[head];
}
```

**LRU Cache (146)**:
```cpp
class LRUCache {
    int capacity;
    list<pair<int,int>> lru;  // {key, value} — front = most recent
    unordered_map<int, list<pair<int,int>>::iterator> cache; // key -> iterator

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (!cache.count(key)) return -1;
        lru.splice(lru.begin(), lru, cache[key]); // move to front O(1)
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (cache.count(key)) lru.erase(cache[key]);
        lru.push_front({key, value});
        cache[key] = lru.begin();
        if ((int)lru.size() > capacity) {
            cache.erase(lru.back().first);
            lru.pop_back(); // evict LRU
        }
    }
};
```

**Key insight**: The doubly-linked list + hashmap combination is the backbone of LRU/LFU caches. The list maintains ORDER (most to least recent), and the hashmap provides O(1) access to any node for O(1) move-to-front operations.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 138 | Copy List with Random Pointer | Medium | Two-pass hashmap clone |
| 146 | LRU Cache | Medium | Doubly linked + hashmap |
| 460 | LFU Cache | Hard | Two hashmaps + freq list |
| 1171 | Remove Zero Sum Nodes | Medium | Prefix sum + hashmap |
| 160 | Intersection of Two Lists | Easy | Length align or hashset |
| 141 | Linked List Cycle | Easy | Hashset visited |

### All Problems in Pattern 7

- 138 Copy List with Random Pointer
- 141 Linked List Cycle (hashset approach)
- 146 LRU Cache
- 160 Intersection of Two Linked Lists
- 460 LFU Cache
- 1171 Remove Zero Sum Consecutive Nodes from Linked List

---

## Pattern 8 — Recursive Linked List

### Notes and Theory

**What it is**: Use recursion to process linked lists by reducing to a smaller subproblem. The call stack naturally handles the "reverse traversal" of the list.

**How to identify**:
- Problem structure is naturally recursive (process rest, then handle head)
- "Reverse recursively"
- "Check palindrome by comparing with tail via recursion"
- Keywords: "recursive", "bottom-up", "process rest first"

**Reverse List Recursively (206)**:
```cpp
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head; // base case
    ListNode* newHead = reverseList(head->next); // reverse rest
    head->next->next = head; // make next node point back to head
    head->next = nullptr;    // head is now tail
    return newHead;
}
```

**Palindrome Check Recursively**:
```cpp
ListNode* front; // global pointer to front

bool check(ListNode* curr) {
    if (!curr) return true;
    if (!check(curr->next)) return false; // check rest first
    if (curr->val != front->val) return false; // compare with front
    front = front->next; // advance front
    return true;
}
// Initialize: front = head; check(head);
```

**Merge Two Lists Recursively (21)**:
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
```

**Swap Nodes in Pairs Recursively (24)**:
```cpp
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* second = head->next;
    head->next = swapPairs(second->next); // solve rest
    second->next = head;                  // swap
    return second;
}
```

**Key insight**: Recursive linked list solutions use the call stack as implicit storage. They naturally process the list from tail to head. Beware of stack overflow for very long lists (n > 10^4) — use iterative solutions then.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 206 | Reverse Linked List | Easy | Recursive reversal |
| 21 | Merge Two Sorted Lists | Easy | Recursive merge |
| 24 | Swap Nodes in Pairs | Medium | Recursive swap |
| 25 | Reverse Nodes in K-Group | Hard | Recursive K-group |
| 234 | Palindrome Linked List | Easy | Recursive back comparison |
| 2487 | Remove Nodes From Linked List | Medium | Recursive max-suffix remove |

### All Problems in Pattern 8

- 21 Merge Two Sorted Lists
- 24 Swap Nodes in Pairs
- 25 Reverse Nodes in K-Group
- 206 Reverse Linked List
- 234 Palindrome Linked List
- 2487 Remove Nodes From Linked List

---

## Pattern 9 — Design Linked List Structures

### Notes and Theory

**What it is**: Design data structures that use linked lists internally to achieve specific time complexities. LRU Cache and LFU Cache are the most asked design problems involving linked lists.

**How to identify**:
- "Design a data structure with O(1) get and put"
- "Design with most recently used eviction"
- Keywords: "design", "O(1) operations", "cache", "eviction policy"

**MyLinkedList (707)**:
```cpp
class MyLinkedList {
    struct Node { int val; Node* next; Node(int v) : val(v), next(nullptr) {} };
    Node* dummy;
    int size;
public:
    MyLinkedList() : dummy(new Node(0)), size(0) {}

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = dummy->next;
        for (int i = 0; i < index; i++) curr = curr->next;
        return curr->val;
    }
    void addAtHead(int val) { addAtIndex(0, val); }
    void addAtTail(int val) { addAtIndex(size, val); }
    void addAtIndex(int index, int val) {
        if (index > size) return;
        Node* prev = dummy;
        for (int i = 0; i < index; i++) prev = prev->next;
        Node* node = new Node(val);
        node->next = prev->next;
        prev->next = node;
        size++;
    }
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* prev = dummy;
        for (int i = 0; i < index; i++) prev = prev->next;
        prev->next = prev->next->next;
        size--;
    }
};
```

**LFU Cache (460)** — key insight:
```cpp
// Maintain: key->value map, key->freq map, freq->list of keys map
// Also track minFreq to find LFU element in O(1)
// On get/put: increment frequency, move key to new freq bucket
// On evict: remove from minFreq bucket's tail (LRU within same freq)
```

**Skip List (1206)**:
```cpp
// Multiple levels of linked lists for O(log n) search
// Each higher level is a "fast lane" that skips multiple nodes
// Probabilistically build levels on insert
```

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 146 | LRU Cache | Medium | DLL + hashmap |
| 460 | LFU Cache | Hard | Two maps + freq buckets |
| 707 | Design Linked List | Medium | Full linked list API |
| 1206 | Design Skiplist | Hard | Multi-level linked list |
| 432 | All O(1) Data Structure | Hard | DLL + hashmap |

### All Problems in Pattern 9

- 146 LRU Cache
- 432 All O(1) Data Structure
- 460 LFU Cache
- 707 Design Linked List
- 1206 Design Skiplist

---

## Pattern 10 — Math on Linked Lists

### Notes and Theory

**What it is**: Perform arithmetic operations on numbers stored in linked lists (usually in reverse order — least significant digit first, or most significant first).

**How to identify**:
- "Add two numbers stored as linked lists"
- "Multiply two numbers in linked list form"
- Keywords: "digits stored", "sum of lists", "add numbers"

**Add Two Numbers (2) — digits in reverse**:
```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }
    return dummy.next;
}
```

**Add Two Numbers II (445) — digits in forward order**:
```cpp
// Option 1: Reverse both lists → apply Add Two Numbers (2) → reverse result
// Option 2: Use two stacks to process from least significant digit
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (l1) { s1.push(l1->val); l1 = l1->next; }
    while (l2) { s2.push(l2->val); l2 = l2->next; }

    ListNode* result = nullptr;
    int carry = 0;
    while (!s1.empty() || !s2.empty() || carry) {
        int sum = carry;
        if (!s1.empty()) { sum += s1.top(); s1.pop(); }
        if (!s2.empty()) { sum += s2.top(); s2.pop(); }
        carry = sum / 10;
        ListNode* node = new ListNode(sum % 10);
        node->next = result; // prepend
        result = node;
    }
    return result;
}
```

**Double a Number (2816)**:
```cpp
// Reverse list → double each digit with carry → reverse back
// OR: reverse + add to itself using Add Two Numbers logic
```

**Key insight**: For reverse-order lists, traverse and add with carry directly. For forward-order lists, use stacks to process from least significant digit, OR reverse → compute → reverse back.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 2 | Add Two Numbers | Medium | Reverse order addition |
| 445 | Add Two Numbers II | Medium | Stack or reverse first |
| 1634 | Add Two Polynomials | Medium | Merge by exponent |
| 2816 | Double a Number as Linked List | Medium | Reverse + carry |
| 1290 | Convert Binary in List to Integer | Easy | Traverse bit by bit |

### All Problems in Pattern 10

- 2 Add Two Numbers
- 445 Add Two Numbers II
- 1290 Convert Binary Number in a Linked List to Integer
- 1634 Add Two Polynomials Represented as Linked Lists
- 2816 Double a Number Represented as a Linked List

---

## 30-Day Mastery Roadmap

### Week 1 — Foundation (Days 1-7)

| Day | Focus | Problems to Solve |
|---|---|---|
| 1 | List basics + traversal | 206, 237, 203 |
| 2 | Pattern 1: Fast & slow | 141, 876, 234 |
| 3 | Pattern 1: Advanced | 142, 19, 2095 |
| 4 | Pattern 2: Reversal basics | 206, 92 |
| 5 | Pattern 2: Advanced reversal | 25, 24, 2074 |
| 6 | Pattern 5: Dummy head | 21, 203, 82 |
| 7 | Review Week 1 | Re-solve 4 hardest |

### Week 2 — Core Patterns (Days 8-14)

| Day | Focus | Problems to Solve |
|---|---|---|
| 8 | Pattern 4: Remove nodes | 83, 82, 203, 2487 |
| 9 | Pattern 3: Merge lists | 21, 23 |
| 10 | Pattern 3: Sort list | 148, 147 |
| 11 | Pattern 6: In-place modify | 143, 61 |
| 12 | Pattern 6: Advanced modify | 430, 328, 725 |
| 13 | Pattern 10: Math on lists | 2, 445, 2816 |
| 14 | Review Week 2 | Re-solve 4 hardest |

### Week 3 — Advanced Patterns (Days 15-21)

| Day | Focus | Problems to Solve |
|---|---|---|
| 15 | Pattern 7: HashMap + list | 138, 160 |
| 16 | Pattern 7: LRU cache | 146 |
| 17 | Pattern 7: LFU cache | 460 |
| 18 | Pattern 8: Recursive | 206, 21, 24, 25 |
| 19 | Pattern 8: Advanced recursive | 234, 2487 |
| 20 | Pattern 9: Design | 707, 146 |
| 21 | Pattern 9: Advanced design | 460, 1206, 432 |

### Week 4 — Hard + Mock (Days 22-30)

| Day | Focus | Problems to Solve |
|---|---|---|
| 22 | Hard reversal | 25, 2074, 92 |
| 23 | Hard merge | 23, 148 |
| 24 | Hard design | 460, 1206 |
| 25 | Mixed hard | 143, 138, 1171 |
| 26 | Cross-pattern review | Mix all patterns |
| 27 | Mock Interview Day 1 | Random 5 |
| 28 | Mock Interview Day 2 | 3 mediums + 1 hard |
| 29 | Weak pattern fill | Fill gaps |
| 30 | Final review | Re-solve 10 hardest |

---

## Top 30 Must Solve Interview Problems

| Priority | # | Problem | Pattern | Difficulty |
|---|---|---|---|---|
| 🔥🔥🔥 | 206 | Reverse Linked List | P2/P8 | Easy |
| 🔥🔥🔥 | 21 | Merge Two Sorted Lists | P3/P5 | Easy |
| 🔥🔥🔥 | 141 | Linked List Cycle | P1 | Easy |
| 🔥🔥🔥 | 146 | LRU Cache | P7/P9 | Medium |
| 🔥🔥🔥 | 142 | Linked List Cycle II | P1 | Medium |
| 🔥🔥🔥 | 23 | Merge K Sorted Lists | P3 | Hard |
| 🔥🔥🔥 | 19 | Remove Nth Node From End | P1/P4 | Medium |
| 🔥🔥🔥 | 138 | Copy List with Random Pointer | P7 | Medium |
| 🔥🔥🔥 | 25 | Reverse Nodes in K-Group | P2/P8 | Hard |
| 🔥🔥🔥 | 143 | Reorder List | P6 | Medium |
| 🔥🔥 | 876 | Middle of the Linked List | P1 | Easy |
| 🔥🔥 | 148 | Sort List | P3 | Medium |
| 🔥🔥 | 234 | Palindrome Linked List | P1/P8 | Easy |
| 🔥🔥 | 92 | Reverse Linked List II | P2 | Medium |
| 🔥🔥 | 2 | Add Two Numbers | P10 | Medium |
| 🔥🔥 | 82 | Remove Duplicates II | P4/P5 | Medium |
| 🔥🔥 | 160 | Intersection of Two Lists | P1/P7 | Easy |
| 🔥🔥 | 328 | Odd Even Linked List | P5/P6 | Medium |
| 🔥🔥 | 460 | LFU Cache | P7/P9 | Hard |
| 🔥🔥 | 86 | Partition List | P5 | Medium |
| 🔥 | 24 | Swap Nodes in Pairs | P2/P8 | Medium |
| 🔥 | 61 | Rotate List | P6 | Medium |
| 🔥 | 83 | Remove Duplicates I | P4 | Easy |
| 🔥 | 430 | Flatten Multilevel List | P6 | Medium |
| 🔥 | 445 | Add Two Numbers II | P10 | Medium |
| 🔥 | 2095 | Delete the Middle Node | P1 | Medium |
| 🔥 | 2487 | Remove Nodes From List | P4/P8 | Medium |
| 🔥 | 707 | Design Linked List | P9 | Medium |
| 🔥 | 2130 | Maximum Twin Sum | P1/P2 | Medium |
| 🔥 | 1171 | Remove Zero Sum Nodes | P4/P7 | Medium |

---

## Hybrid Decision Guide

| Combination | Rule | Example |
|---|---|---|
| P1 vs P4 | P1 if using fast/slow speed difference; P4 if both pointers same speed with offset | 876 vs 19 |
| P2 vs P8 | P2 if iterative reversal clearer; P8 if recursion is more natural (short list) | 206 iter vs 206 recur |
| P3 vs P5 | Always use dummy head in P3 merge — they naturally combine | 21 uses both |
| P5 vs P4 | Dummy head is a TECHNIQUE used inside P4 removal, not a separate pattern | 82 uses P4+P5 |
| P6 vs P2 | P6 if restructuring list shape; P2 if just reversing a segment | 143 vs 92 |
| P7 vs P1 | P7 (hashmap) for cycle detection is O(n) space; P1 (Floyd's) is O(1) space | 141 |
| P8 vs iterative | P8 (recursion) is elegant but O(n) stack space; iterative is O(1) space | 206 |
| P9 vs P7 | P9 if full design problem asked; P7 if hashmap is just a helper tool | 146 is both |
| P10 vs P6 | P10 for arithmetic; P6 if rearranging without computing a number | 2 vs 143 |
| P3 vs P6 | P3 if combining multiple lists; P6 if rearranging within one list | 23 vs 143 |

---

## Quick Reference — Common Mistakes

| Mistake | Correct Approach |
|---|---|
| Not using dummy node when head might change | Always create `ListNode dummy(0, head)` when head removal is possible |
| Losing next pointer before reversing | Save `ListNode* next = curr->next` BEFORE `curr->next = prev` |
| Fast/slow: wrong termination for even-length middle | `while (fast && fast->next)` — slow lands on first middle for even |
| Cycle detection: starting fast at head->next | Start BOTH slow and fast at head for standard Floyd's |
| K-group reversal: not checking if K nodes remain | Count K nodes first; if fewer remain, return head unchanged |
| Merge: not attaching remaining tail | After while loop: `curr->next = l1 ? l1 : l2` |
| LRU cache: not updating on get (only on put) | Move to front on BOTH get AND put operations |
| Rotate: not handling k >= length | Use `k = k % length` before rotating |
| Add numbers: forgetting final carry | Handle `while (l1 || l2 || carry)` — carry can generate extra node |
| Recursive reversal: memory limit for n > 10^4 | Prefer iterative for long lists — recursion stack = O(n) space |

---

*Guide compiled from 100+ LeetCode linked list problems, mapped to 10 universal patterns.*
*Master these patterns and you will solve 95%+ of linked list questions in any technical interview.*
