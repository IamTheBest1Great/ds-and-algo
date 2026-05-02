# 🕸️ Graph Mastery Guide — 95% Interview Coverage

> **Goal**: Solve 95% of all graph interview questions with pattern recognition, not memorization.
> **Method**: 12 patterns → recognition flowchart → templates → curated problem set.
> **Reference**: DFS/BFS · Cycle Detection · Topological Sort · Flood Fill · Multi-Source BFS · Dijkstra · Bellman-Ford · Floyd-Warshall · TSP · DSU · MST · Additional Graph Algorithms

---

## 📌 Table of Contents

1. [Pattern Recognition Flowchart](#pattern-recognition-flowchart)
2. [Pattern 1 — DFS on Graphs](#pattern-1--dfs-on-graphs)
3. [Pattern 2 — BFS on Graphs](#pattern-2--bfs-on-graphs)
4. [Pattern 3 — Cycle Detection](#pattern-3--cycle-detection)
5. [Pattern 4 — Topological Sort](#pattern-4--topological-sort)
6. [Pattern 5 — Flood Fill / Connected Components](#pattern-5--flood-fill--connected-components)
7. [Pattern 6 — Multi-Source BFS](#pattern-6--multi-source-bfs)
8. [Pattern 7 — Dijkstra Algorithm](#pattern-7--dijkstra-algorithm)
9. [Pattern 8 — Bellman-Ford Algorithm](#pattern-8--bellman-ford-algorithm)
10. [Pattern 9 — Floyd-Warshall (All-Pairs Shortest Path)](#pattern-9--floyd-warshall-all-pairs-shortest-path)
11. [Pattern 10 — Disjoint Set Union (DSU / Union-Find)](#pattern-10--disjoint-set-union-dsu--union-find)
12. [Pattern 11 — Minimum Spanning Tree (MST)](#pattern-11--minimum-spanning-tree-mst)
13. [Pattern 12 — Advanced Graph Algorithms](#pattern-12--advanced-graph-algorithms)
14. [30-Day Mastery Roadmap](#30-day-mastery-roadmap)
15. [Hybrid Decision Guide](#hybrid-decision-guide)

---

## Pattern Recognition Flowchart

```
START — Read the problem statement
         |
         v
Is the graph a GRID (2D matrix)?
         |
        YES ──► Does it spread from MULTIPLE starting cells simultaneously?
         |               |
         |              YES ─────────────────────────► Pattern 6: Multi-Source BFS
         |               |
         |              NO ──────────────────────────► Pattern 5: Flood Fill / DFS on Grid
         |
         v
Does the problem ask to VISIT / EXPLORE nodes or find connected components?
         |
         ├─ Need SHORTEST PATH (unweighted)?  ────────► Pattern 2: BFS
         │
         └─ Need to explore all nodes / paths? ───────► Pattern 1: DFS
         |
         v
Does the problem involve ORDERING with DEPENDENCIES?
(Course prerequisites, build order, task dependencies)
         |
        YES ──────────────────────────────────────────► Pattern 4: Topological Sort
         |
         v
Does the problem ask to DETECT A CYCLE?
         |
        YES ──────────────────────────────────────────► Pattern 3: Cycle Detection
         |
         v
Does the problem involve WEIGHTED SHORTEST PATH?
         |
         ├─ Non-negative weights, single source? ─────► Pattern 7: Dijkstra
         │
         ├─ Negative weights OR detect negative cycle? ► Pattern 8: Bellman-Ford
         │
         └─ ALL pairs shortest path? ─────────────────► Pattern 9: Floyd-Warshall
         |
         v
Does the problem MERGE COMPONENTS or check CONNECTIVITY dynamically?
(Union two nodes, same component query, redundant edges)
         |
        YES ──────────────────────────────────────────► Pattern 10: DSU / Union-Find
         |
         v
Does the problem find MINIMUM COST to CONNECT ALL nodes?
(Minimum spanning tree, connect all cities)
         |
        YES ──────────────────────────────────────────► Pattern 11: MST (Kruskal/Prim)
         |
         v
Does the problem involve STRONGLY CONNECTED COMPONENTS,
BRIDGES, ARTICULATION POINTS, EULERIAN PATH, or BIPARTITE check?
         |
        YES ──────────────────────────────────────────► Pattern 12: Advanced Graph
         |
         v
        END
```

### 10-Second Interview Shortcut

| Signal in problem | Pattern |
|---|---|
| Explore all nodes, paths, components | P1 — DFS |
| Shortest path, unweighted | P2 — BFS |
| Is there a cycle? | P3 — Cycle Detection |
| Prerequisites, ordering, dependencies | P4 — Topological Sort |
| Spread on 2D grid, islands, regions | P5 — Flood Fill |
| Multiple sources expand simultaneously | P6 — Multi-Source BFS |
| Shortest path, non-negative weights | P7 — Dijkstra |
| Negative weights, detect negative cycle | P8 — Bellman-Ford |
| All pairs shortest distances | P9 — Floyd-Warshall |
| Merge groups, connectivity queries | P10 — DSU |
| Minimum cost to connect all nodes | P11 — MST |
| SCC, bridges, bipartite, Euler path | P12 — Advanced |

---

## Pattern 1 — DFS on Graphs

### Notes and Theory

**What it is**: Depth-First Search explores as far as possible along each branch before backtracking. Uses a stack (explicit or call stack via recursion). Fundamental for: path finding, component counting, cycle detection, topological sort.

**How to identify**:
- "Find all paths from source to destination"
- "Number of connected components"
- "Can you reach node X from node Y"
- Keywords: "explore", "all paths", "reachable", "connected"

**DFS Template (adjacency list)**:
```cpp
vector<vector<int>> adj(n);
vector<bool> visited(n, false);

void dfs(int node) {
    visited[node] = true;
    // process node

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

// Count connected components:
int components = 0;
for (int i = 0; i < n; i++) {
    if (!visited[i]) {
        dfs(i);
        components++;
    }
}
```

**Iterative DFS (avoid stack overflow)**:
```cpp
void dfs_iterative(int start) {
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int node = st.top(); st.pop();
        // process node

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                st.push(neighbor);
            }
        }
    }
}
```

**DFS on grid**:
```cpp
int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
void dfs(vector<vector<int>>& grid, int r, int c) {
    int m = grid.size(), n = grid[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n) return;
    if (grid[r][c] != 1) return; // already visited or wall
    grid[r][c] = 0; // mark visited in-place
    for (auto& d : dirs) dfs(grid, r+d[0], c+d[1]);
}
```

**Key insight**: DFS is the go-to when you need to explore ALL possibilities (backtracking) or when path order doesn't matter. For SHORTEST path in unweighted graphs, always prefer BFS.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 200 | Number of Islands | Medium | DFS count components |
| 547 | Number of Provinces | Medium | DFS on adjacency matrix |
| 133 | Clone Graph | Medium | DFS + hashmap |
| 394 | Decode String | Medium | DFS recursive parsing |
| 797 | All Paths From Source to Target | Medium | DFS enumerate all paths |
| 841 | Keys and Rooms | Medium | DFS reachability |
| 1971 | Find if Path Exists in Graph | Easy | DFS/BFS connectivity |
| 2316 | Count Unreachable Pairs | Medium | Component size product |

### All Problems in Pattern 1

- 133 Clone Graph
- 200 Number of Islands
- 323 Number of Connected Components in Undirected Graph
- 547 Number of Provinces
- 695 Max Area of Island
- 733 Flood Fill
- 797 All Paths From Source to Target
- 841 Keys and Rooms
- 1020 Number of Enclaves
- 1254 Number of Closed Islands
- 1319 Number of Operations to Make Network Connected
- 1466 Reorder Routes to Make All Paths Lead to City Zero
- 1971 Find if Path Exists in Graph
- 2316 Count Unreachable Pairs of Nodes in an Undirected Graph
- 2492 Minimum Score of a Path Between Two Cities
- 2685 Count the Number of Complete Components

---

## Pattern 2 — BFS on Graphs

### Notes and Theory

**What it is**: Breadth-First Search explores all neighbors at distance d before exploring distance d+1. Uses a queue. Guarantees shortest path in **unweighted** graphs.

**How to identify**:
- "Shortest path in unweighted graph"
- "Minimum steps / moves to reach target"
- "Level-by-level traversal"
- Keywords: "minimum steps", "shortest path", "levels", "distance"

**BFS Template**:
```cpp
vector<int> bfs(int start, int n, vector<vector<int>>& adj) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) { // unvisited
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return dist; // dist[i] = shortest distance from start to i
}
```

**BFS on grid**:
```cpp
int bfsGrid(vector<vector<int>>& grid, int sr, int sc, int er, int ec) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, -1));
    queue<pair<int,int>> q;
    dist[sr][sc] = 0;
    q.push({sr, sc});
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        if (r == er && c == ec) return dist[r][c];
        for (auto& d : dirs) {
            int nr = r+d[0], nc = c+d[1];
            if (nr>=0 && nr<m && nc>=0 && nc<n
                && grid[nr][nc] == 0 && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return -1; // unreachable
}
```

**Word Ladder (BFS on implicit graph)**:
```cpp
// Each word is a node; edges connect words differing by 1 letter
// BFS gives minimum transformations
// Use unordered_set for O(1) word lookup
```

**Key insight**: BFS level = distance from source. When you first visit a node in BFS, that IS the shortest distance. Never update distance in BFS — first touch is always optimal.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 127 | Word Ladder | Hard | BFS on implicit graph |
| 542 | 01 Matrix | Medium | BFS distance from zeros |
| 994 | Rotting Oranges | Medium | BFS multi-source (see P6) |
| 1091 | Shortest Path in Binary Matrix | Medium | BFS on grid |
| 1926 | Nearest Exit from Entrance | Medium | BFS nearest target |
| 2058 | Find All Groups of Farmland | Medium | BFS component bounds |
| 433 | Minimum Genetic Mutation | Medium | BFS implicit graph |
| 1129 | Shortest Path with Alternating Colors | Medium | BFS with state |

### All Problems in Pattern 2

- 127 Word Ladder
- 126 Word Ladder II
- 433 Minimum Genetic Mutation
- 542 01 Matrix
- 752 Open the Lock
- 994 Rotting Oranges
- 1091 Shortest Path in Binary Matrix
- 1129 Shortest Path with Alternating Colors
- 1293 Shortest Path in a Grid with Obstacles Elimination
- 1345 Jump Game IV
- 1926 Nearest Exit from Entrance in Maze
- 2039 The Time When the Network Becomes Idle
- 2058 Find All Groups of Farmland
- 2146 K Highest Ranked Items Within a Price Range
- 2290 Minimum Obstacle Removal to Reach Corner
- 2493 Divide Nodes Into the Maximum Number of Groups

---

## Pattern 3 — Cycle Detection

### Notes and Theory

**What it is**: Determine whether a graph contains a cycle. Different approaches for directed vs undirected graphs.

**How to identify**:
- "Is there a cycle?", "can all courses be finished?" (implicit cycle check)
- "Detect deadlock", "dependency loop"
- Keywords: "cycle", "loop", "circular dependency"

**Undirected Graph — DFS with parent tracking**:
```cpp
bool hasCycleUndirected(int node, int parent,
                         vector<vector<int>>& adj,
                         vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (hasCycleUndirected(neighbor, node, adj, visited))
                return true;
        } else if (neighbor != parent) {
            return true; // back edge found = cycle
        }
    }
    return false;
}
```

**Directed Graph — DFS with 3-color marking**:
```cpp
// 0 = unvisited, 1 = in current path (gray), 2 = fully processed (black)
vector<int> color(n, 0);

bool hasCycleDirected(int node) {
    color[node] = 1; // mark as being processed
    for (int neighbor : adj[node]) {
        if (color[neighbor] == 1) return true;  // back edge = cycle
        if (color[neighbor] == 0) {
            if (hasCycleDirected(neighbor)) return true;
        }
    }
    color[node] = 2; // fully processed
    return false;
}
```

**Undirected Graph — DSU approach**:
```cpp
// For each edge (u, v): if find(u) == find(v), cycle detected; else union
for (auto& [u, v] : edges) {
    if (find(u) == find(v)) return true; // same component = cycle
    unite(u, v);
}
return false;
```

**Floyd's Cycle Detection (Linked List)**:
```cpp
// Slow/fast pointer — if they meet, cycle exists
// Reset slow to head, advance both 1 step to find cycle start
```

**Key insight**: For directed graphs, a back edge (edge to a node currently in the DFS stack / gray node) = cycle. For undirected graphs, a visited neighbor that's not the parent = cycle.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 207 | Course Schedule | Medium | Directed cycle detection |
| 802 | Find Eventual Safe States | Medium | Reverse cycle: no outgoing |
| 684 | Redundant Connection | Medium | DSU cycle in undirected |
| 685 | Redundant Connection II | Hard | Directed graph DSU |
| 1059 | All Paths from Source Lead to Destination | Medium | DFS cycle + dead end |
| 2360 | Longest Cycle in a Graph | Hard | DFS timestamps |
| 2127 | Maximum Employees to Invite | Hard | Functional graph cycles |

### All Problems in Pattern 3

- 207 Course Schedule
- 210 Course Schedule II (see P4)
- 261 Graph Valid Tree
- 684 Redundant Connection
- 685 Redundant Connection II
- 802 Find Eventual Safe States
- 1059 All Paths from Source Lead to Destination
- 2127 Maximum Employees to Invite to a Meeting
- 2360 Longest Cycle in a Graph
- 3067 Count Pairs of Connectable Servers in a Weighted Tree Network

---

## Pattern 4 — Topological Sort

### Notes and Theory

**What it is**: Linear ordering of nodes in a **Directed Acyclic Graph (DAG)** such that for every edge u→v, u appears before v. Two algorithms: Kahn's (BFS-based, uses in-degree) and DFS-based (post-order reversal).

**How to identify**:
- "Course prerequisites", "task ordering", "build dependencies"
- "Is a valid order possible?" (cycle check)
- Keywords: "order", "schedule", "prerequisite", "dependency", "before"

**Kahn's Algorithm (BFS + in-degree)**:
```cpp
vector<int> topoSort(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);

    for (auto& [a, b] : prerequisites) {
        adj[b].push_back(a);
        inDegree[a]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0) q.push(i); // start with no dependencies

    vector<int> order;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);
        for (int neighbor : adj[node]) {
            if (--inDegree[neighbor] == 0) q.push(neighbor);
        }
    }

    return order.size() == n ? order : {}; // empty = cycle detected
}
```

**DFS-based Topological Sort**:
```cpp
vector<int> result;
vector<bool> visited(n, false);

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) dfs(neighbor);
    }
    result.push_back(node); // post-order: push AFTER all children
}

for (int i = 0; i < n; i++)
    if (!visited[i]) dfs(i);
reverse(result.begin(), result.end()); // reverse post-order = topo order
```

**Lexicographically smallest topo order**: Use a min-heap (priority queue) instead of a regular queue in Kahn's algorithm.

**Key insight**: If Kahn's produces fewer than n nodes, there's a cycle (some nodes never reached in-degree 0). The count check IS the cycle detection.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 207 | Course Schedule | Medium | Cycle check via topo |
| 210 | Course Schedule II | Medium | Return topo order |
| 269 | Alien Dictionary | Hard | Build graph from word order |
| 310 | Minimum Height Trees | Medium | Topological leaf pruning |
| 1203 | Sort Items by Groups | Hard | Two-level topo sort |
| 2115 | Find All Possible Recipes | Medium | Topo sort with ingredients |
| 1857 | Largest Color Value in Directed Graph | Hard | Topo + DP |
| 2050 | Parallel Courses III | Hard | Topo + critical path |

### All Problems in Pattern 4

- 207 Course Schedule
- 210 Course Schedule II
- 269 Alien Dictionary
- 310 Minimum Height Trees
- 444 Sequence Reconstruction
- 802 Find Eventual Safe States
- 1203 Sort Items by Groups Respecting Dependencies
- 1857 Largest Color Value in a Directed Graph
- 2050 Parallel Courses III
- 2115 Find All Possible Recipes from Given Supplies
- 2127 Maximum Employees to Invite to a Meeting
- 2360 Longest Cycle in a Graph
- 2392 Build a Matrix With Conditions
- 3203 Find Minimum Diameter After Merging Two Trees

---

## Pattern 5 — Flood Fill / Connected Components

### Notes and Theory

**What it is**: Starting from one or more cells in a 2D grid, "fill" or explore all reachable cells satisfying a condition. Classic grid DFS/BFS. Used for island counting, region labeling, and area calculation.

**How to identify**:
- "Number of islands", "area of largest region"
- "Fill a region", "connected cells of same color"
- Keywords: "island", "region", "connected cells", "flood fill", "component"

**Flood Fill Template (733)**:
```cpp
void floodFill(vector<vector<int>>& image, int r, int c,
               int oldColor, int newColor) {
    int m = image.size(), n = image[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n) return;
    if (image[r][c] != oldColor || image[r][c] == newColor) return;

    image[r][c] = newColor; // mark visited by changing color
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    for (auto& d : dirs)
        floodFill(image, r+d[0], c+d[1], oldColor, newColor);
}
```

**Number of Islands (200)**:
```cpp
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j); // sinks the island
                count++;
            }
        }
    }
    return count;
}

void dfs(vector<vector<char>>& grid, int r, int c) {
    if (r<0||r>=grid.size()||c<0||c>=grid[0].size()||grid[r][c]!='1') return;
    grid[r][c] = '0'; // mark visited
    dfs(grid,r+1,c); dfs(grid,r-1,c);
    dfs(grid,r,c+1); dfs(grid,r,c-1);
}
```

**Enclaves / Boundary check (1020)**:
```cpp
// DFS from ALL boundary cells to mark reachable
// Remaining unmarked cells are enclaves (unreachable from boundary)
```

**Key insight**: In-place marking (changing visited cell value) avoids needing a separate visited array. Restore if needed (backtracking), otherwise leave changed. For 8-directional connectivity, add 4 diagonal directions.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 200 | Number of Islands | Medium | Classic flood fill count |
| 733 | Flood Fill | Easy | Direct flood fill |
| 695 | Max Area of Island | Medium | Flood fill + area count |
| 130 | Surrounded Regions | Medium | Fill from boundary |
| 1020 | Number of Enclaves | Medium | Boundary DFS first |
| 1254 | Number of Closed Islands | Medium | Boundary check + count |
| 827 | Making a Large Island | Hard | Label + merge components |
| 2684 | Maximum Number of Moves | Medium | Grid DFS with condition |

### All Problems in Pattern 5

- 130 Surrounded Regions
- 200 Number of Islands
- 463 Island Perimeter
- 695 Max Area of Island
- 733 Flood Fill
- 827 Making a Large Island
- 1020 Number of Enclaves
- 1254 Number of Closed Islands
- 1905 Count Sub Islands
- 2101 Detonate the Maximum Bombs
- 2316 Count Unreachable Pairs of Nodes
- 2684 Maximum Number of Moves in a Grid
- 3235 Check if the Rectangle Corner Is Reachable

---

## Pattern 6 — Multi-Source BFS

### Notes and Theory

**What it is**: BFS starting from **multiple source nodes simultaneously**. All sources are pushed into the queue at level 0. The BFS naturally computes the distance from the nearest source to every other node.

**How to identify**:
- "Distance to nearest X", "time for all cells to be affected"
- "Rotting oranges spread", "walls expand outward"
- Keywords: "nearest", "simultaneously", "all sources expand", "spread from multiple"

**Multi-Source BFS Template**:
```cpp
vector<vector<int>> dist(m, vector<int>(n, -1));
queue<pair<int,int>> q;

// Push ALL sources at level 0
for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        if (isSource(grid[i][j])) {
            dist[i][j] = 0;
            q.push({i, j});
        }
    }
}

int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
while (!q.empty()) {
    auto [r, c] = q.front(); q.pop();
    for (auto& d : dirs) {
        int nr = r+d[0], nc = c+d[1];
        if (nr>=0 && nr<m && nc>=0 && nc<n
            && dist[nr][nc] == -1 && canVisit(grid[nr][nc])) {
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
}
```

**Rotting Oranges (994)**:
```cpp
// Sources = all initially rotten oranges (value 2)
// Spread to adjacent fresh oranges (value 1)
// Answer = max distance, or -1 if any fresh remain
```

**01 Matrix (542)**:
```cpp
// Sources = all cells with value 0
// Answer = distance from each cell to nearest 0
// Multi-source BFS from all zeros simultaneously
```

**Pacific Atlantic Water Flow (417)**:
```cpp
// Two multi-source BFS: one from Pacific border, one from Atlantic border
// Answer = cells reachable from BOTH
```

**Key insight**: Multi-source BFS = single-source BFS with a virtual super-source connected to all real sources at cost 0. Initializing all sources at distance 0 and pushing them together achieves this in O(1) extra space.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 994 | Rotting Oranges | Medium | Core multi-source BFS |
| 542 | 01 Matrix | Medium | Distance from nearest zero |
| 417 | Pacific Atlantic Water Flow | Medium | Two multi-source BFS |
| 1162 | As Far from Land as Possible | Medium | Max dist from land |
| 2146 | K Highest Ranked Items | Medium | Multi-source BFS + sort |
| 1765 | Map of Highest Peak | Medium | Height from water cells |
| 2258 | Escape the Spreading Fire | Hard | Binary search + BFS |
| 1293 | Shortest Path with Obstacle Elimination | Hard | BFS with state |

### All Problems in Pattern 6

- 417 Pacific Atlantic Water Flow
- 542 01 Matrix
- 994 Rotting Oranges
- 1162 As Far from Land as Possible
- 1765 Map of Highest Peak
- 2258 Escape the Spreading Fire
- 2146 K Highest Ranked Items Within a Price Range
- 2577 Minimum Time to Visit a Cell In a Grid
- 2812 Find the Safest Path in a Grid
- 3286 Find a Safe Walk Through a Grid

---

## Pattern 7 — Dijkstra Algorithm

### Notes and Theory

**What it is**: Greedy shortest-path algorithm for graphs with **non-negative edge weights**. Uses a min-heap to always process the node with smallest tentative distance. Each pop = finalized shortest path.

**How to identify**:
- "Shortest path in weighted graph"
- "Minimum cost / effort / time to reach destination"
- All edge weights >= 0
- Keywords: "minimum cost", "minimum effort", "weighted shortest path"

**Dijkstra Template**:
```cpp
vector<int> dijkstra(int src, int n, vector<vector<pair<int,int>>>& adj) {
    // adj[u] = list of {neighbor, weight}
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

    dist[src] = 0;
    minHeap.push({0, src}); // {distance, node}

    while (!minHeap.empty()) {
        auto [d, u] = minHeap.top(); minHeap.pop();

        if (d > dist[u]) continue; // stale entry — skip

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                minHeap.push({dist[v], v});
            }
        }
    }
    return dist; // dist[i] = shortest distance from src to i
}
```

**Dijkstra on Grid (Path with Min Effort — 1631)**:
```cpp
// dist[i][j] = minimum maximum effort to reach (i,j)
// cost of moving = max(currentCost, |height diff|)
// Standard Dijkstra with 2D dist array
```

**Modified Dijkstra (787 — K stops)**:
```cpp
// State = {cost, node, stopsRemaining}
// Use dist[node][stops] to avoid revisiting same state
vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
```

**Key insight**:
- The stale-entry check `if (d > dist[u]) continue` replaces the need for a "decrease-key" operation.
- Dijkstra fails with negative edges — use Bellman-Ford instead.
- Time: O((V + E) log V)

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 743 | Network Delay Time | Medium | Classic single-source |
| 1631 | Path With Minimum Effort | Medium | Dijkstra on grid |
| 1514 | Path with Maximum Probability | Medium | Maximize product |
| 778 | Swim in Rising Water | Hard | Min-max Dijkstra |
| 787 | Cheapest Flights Within K Stops | Medium | State = (node, stops) |
| 1976 | Number of Ways to Arrive on Time | Medium | Count shortest paths |
| 2045 | Second Minimum Time | Hard | Track 2 distances |
| 2577 | Min Time to Visit Cell in Grid | Hard | Time-gated Dijkstra |
| 3112 | Min Time to Visit Disappearing Nodes | Medium | Expiring nodes |

### All Problems in Pattern 7

- 743 Network Delay Time
- 778 Swim in Rising Water
- 787 Cheapest Flights Within K Stops
- 1368 Minimum Cost to Make at Least One Valid Path in a Grid
- 1514 Path with Maximum Probability
- 1631 Path With Minimum Effort
- 1786 Number of Restricted Paths From First to Last Node
- 1928 Minimum Cost to Reach Destination in Time
- 1976 Number of Ways to Arrive at Destination
- 2045 Second Minimum Time to Reach Destination
- 2203 Minimum Weighted Subgraph With the Required Paths
- 2290 Minimum Obstacle Removal to Reach Corner
- 2492 Minimum Score of a Path Between Two Cities
- 2577 Minimum Time to Visit a Cell In a Grid
- 2662 Minimum Cost of a Path With Special Roads
- 3112 Minimum Time to Visit Disappearing Nodes
- 3123 Find Edges in Shortest Paths

---

## Pattern 8 — Bellman-Ford Algorithm

### Notes and Theory

**What it is**: Single-source shortest path that handles **negative edge weights**. Relaxes all edges V-1 times. If a V-th relaxation still improves a distance, a **negative cycle** exists.

**How to identify**:
- Graph has NEGATIVE edge weights
- "Detect negative cycle"
- "Cheapest path with at most K edges" (modified BF)
- Keywords: "negative weight", "negative cycle", "at most K edges"

**Bellman-Ford Template**:
```cpp
vector<int> bellmanFord(int src, int n,
                         vector<tuple<int,int,int>>& edges) {
    // edges = list of {u, v, weight}
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle (Vth relaxation)
    for (auto [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return {}; // negative cycle detected
        }
    }

    return dist;
}
```

**Cheapest Flights Within K Stops (787) — BF variant**:
```cpp
// Run exactly K+1 relaxation rounds (not V-1)
// Use a COPY of dist from previous round to avoid using edges twice in one round
vector<int> dist(n, INT_MAX);
dist[src] = 0;

for (int i = 0; i <= k; i++) {          // K+1 rounds
    vector<int> temp = dist;             // snapshot before this round
    for (auto [u, v, w] : flights) {
        if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
            temp[v] = dist[u] + w;
        }
    }
    dist = temp;
}
return dist[dst] == INT_MAX ? -1 : dist[dst];
```

**Key insight**: Each round of BF relaxation finds shortest paths using at most i edges. After V-1 rounds, all shortest paths are found (if no negative cycle). The K-stops variant runs exactly K+1 rounds.

**Bellman-Ford vs Dijkstra**:
- Dijkstra: O((V+E) log V), no negative weights
- Bellman-Ford: O(VE), handles negative weights, detects negative cycles

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 787 | Cheapest Flights Within K Stops | Medium | BF with K rounds |
| 743 | Network Delay Time | Medium | BF alternative to Dijkstra |
| 1334 | Find the City With Fewest Neighbors | Medium | All-pairs (BF or Floyd) |
| 2866 | Beautiful Towers II | Medium | Related constraint concept |
| 2976 | Minimum Cost to Convert String | Medium | BF on char graph |

### All Problems in Pattern 8

- 743 Network Delay Time
- 787 Cheapest Flights Within K Stops
- 1334 Find the City With the Smallest Number of Neighbors at a Threshold Distance
- 2976 Minimum Cost to Convert String I

---

## Pattern 9 — Floyd-Warshall (All-Pairs Shortest Path)

### Notes and Theory

**What it is**: Dynamic programming algorithm that computes shortest paths between **ALL pairs** of nodes. Handles negative weights (but not negative cycles). O(V³) time, O(V²) space.

**How to identify**:
- "Shortest distance between every pair of nodes"
- "Find the city with fewest reachable neighbors"
- Small graph (V <= 200 or so) needing all-pairs distances
- Keywords: "all pairs", "between every two nodes", "reachable within distance"

**Floyd-Warshall Template**:
```cpp
vector<vector<int>> floydWarshall(int n,
                                   vector<vector<int>>& edges) {
    // dist[i][j] = shortest path from i to j
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX / 2));

    for (int i = 0; i < n; i++) dist[i][i] = 0; // self-loop

    for (auto& [u, v, w] : edges) {
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w); // remove for directed graph
    }

    // Key DP: try every intermediate node k
    for (int k = 0; k < n; k++) {         // intermediate node
        for (int i = 0; i < n; i++) {     // source
            for (int j = 0; j < n; j++) { // destination
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Detect negative cycle: dist[i][i] < 0 for any i
    return dist;
}
```

**Find City With Fewest Neighbors (1334)**:
```cpp
// Run Floyd-Warshall, then for each city count neighbors within threshold
// Return city with fewest neighbors (prefer highest index on tie)
```

**Key insight**: The DP transition says: "can we do better from i to j by going through intermediate node k?" Process ALL intermediates before reading results. INT_MAX/2 (not INT_MAX) avoids overflow when adding.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 1334 | Find the City With Fewest Neighbors | Medium | Floyd-Warshall + count |
| 743 | Network Delay Time | Medium | Floyd or Dijkstra |
| 2976 | Min Cost to Convert String I | Medium | All-pairs on char graph |
| 1462 | Course Schedule IV | Medium | Transitive closure (FW) |
| 2642 | Design Graph With Shortest Path | Hard | Dynamic Dijkstra |

### All Problems in Pattern 9

- 1334 Find the City With the Smallest Number of Neighbors at a Threshold Distance
- 1462 Course Schedule IV
- 2642 Design Graph With Shortest Path Calculator
- 2976 Minimum Cost to Convert String I

---

## Pattern 10 — Disjoint Set Union (DSU / Union-Find)

### Notes and Theory

**What it is**: A data structure that efficiently supports two operations: **union** (merge two components) and **find** (which component does a node belong to). With path compression and union by rank, both operations are nearly O(1) amortized.

**How to identify**:
- "Are two nodes in the same component?"
- "Merge groups dynamically", "redundant connection"
- "How many connected components?"
- Keywords: "union", "connected", "same group", "merge", "redundant edge"

**DSU Template**:
```cpp
struct DSU {
    vector<int> parent, rank;

    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false; // already same component

        // Union by rank
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
```

**Redundant Connection (684)**:
```cpp
// For each edge: if both nodes already in same component → redundant
for (auto& [u, v] : edges) {
    if (!dsu.unite(u-1, v-1)) return {u, v}; // redundant
}
```

**Number of Islands with DSU**:
```cpp
// Each cell is a node. For each '1' cell, union with adjacent '1' cells.
// Component count = total '1' cells - number of successful unions
```

**Key insight**: Path compression makes `find` nearly O(1). Union by rank keeps trees flat. Together: O(α(n)) per operation where α is the inverse Ackermann function — effectively constant.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 684 | Redundant Connection | Medium | Core DSU cycle detection |
| 685 | Redundant Connection II | Hard | Directed graph DSU |
| 721 | Accounts Merge | Medium | DSU string grouping |
| 990 | Satisfiability of Equality Equations | Medium | DSU on characters |
| 1202 | Smallest String With Swaps | Medium | DSU + sort components |
| 1319 | Make Network Connected | Medium | Component count |
| 1579 | Remove Max Edge to Keep Graph Connected | Hard | Spanning tree DSU |
| 2421 | Number of Good Paths | Hard | DSU + sorted values |
| 2709 | Greatest Common Divisor Traversal | Hard | DSU on prime factors |

### All Problems in Pattern 10

- 261 Graph Valid Tree
- 323 Number of Connected Components
- 547 Number of Provinces
- 684 Redundant Connection
- 685 Redundant Connection II
- 721 Accounts Merge
- 737 Sentence Similarity II
- 765 Couples Holding Hands
- 839 Similar String Groups
- 924 Minimize Malware Spread
- 990 Satisfiability of Equality Equations
- 1061 Lexicographically Smallest Equivalent String
- 1202 Smallest String With Swaps
- 1319 Number of Operations to Make Network Connected
- 1489 Find Critical and Pseudo-Critical Edges
- 1579 Remove Max Number of Edges to Keep Graph Fully Traversable
- 1631 Path With Minimum Effort (alt approach)
- 2157 Groups of Strings
- 2421 Number of Good Paths
- 2503 Maximum Number of Points From Grid Queries
- 2709 Greatest Common Divisor Traversal

---

## Pattern 11 — Minimum Spanning Tree (MST)

### Notes and Theory

**What it is**: A spanning tree of a connected graph with **minimum total edge weight**. Two classic algorithms: **Kruskal's** (sort edges + DSU) and **Prim's** (greedy + min-heap).

**How to identify**:
- "Connect all nodes with minimum cost"
- "Minimum cost to build roads/cables/pipes connecting all cities"
- Keywords: "connect all", "minimum cost network", "spanning tree"

**Kruskal's Algorithm (sort edges + DSU)**:
```cpp
int kruskal(int n, vector<tuple<int,int,int>>& edges) {
    // edges = {weight, u, v}
    sort(edges.begin(), edges.end()); // sort by weight ascending
    DSU dsu(n);
    int totalCost = 0, edgesUsed = 0;

    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {       // only add edge if it connects two components
            totalCost += w;
            if (++edgesUsed == n-1) break; // MST complete: n-1 edges
        }
    }
    return edgesUsed == n-1 ? totalCost : -1; // -1 if not fully connected
}
```

**Prim's Algorithm (min-heap)**:
```cpp
int prim(int n, vector<vector<pair<int,int>>>& adj) {
    // adj[u] = list of {neighbor, weight}
    vector<bool> inMST(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
    minHeap.push({0, 0}); // {weight, node}, start from node 0
    int totalCost = 0;

    while (!minHeap.empty()) {
        auto [w, u] = minHeap.top(); minHeap.pop();
        if (inMST[u]) continue; // already in MST
        inMST[u] = true;
        totalCost += w;

        for (auto [v, wt] : adj[u]) {
            if (!inMST[v]) minHeap.push({wt, v});
        }
    }
    return totalCost;
}
```

**When to use Kruskal vs Prim**:
- Kruskal: better for sparse graphs, easy to implement with DSU
- Prim: better for dense graphs, natural with adjacency matrix

**Maximum Spanning Tree**: Negate weights and run MST, OR sort edges descending in Kruskal's.

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 1584 | Min Cost to Connect All Points | Medium | Prim or Kruskal on complete graph |
| 1135 | Connecting Cities With Minimum Cost | Medium | Classic Kruskal |
| 1489 | Find Critical and Pseudo-Critical Edges | Hard | MST + edge testing |
| 1168 | Optimize Water Distribution | Hard | Virtual node + MST |
| 1697 | Checking Existence of Edge Length | Hard | MST + offline queries |
| 2421 | Number of Good Paths | Hard | DSU sorted by value |

### All Problems in Pattern 11

- 1135 Connecting Cities With Minimum Cost
- 1168 Optimize Water Distribution in a Village
- 1489 Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
- 1584 Min Cost to Connect All Points
- 1697 Checking Existence of Edge Length Limited Paths
- 2421 Number of Good Paths

---

## Pattern 12 — Advanced Graph Algorithms

### Notes and Theory

**What it is**: A collection of specialized graph algorithms for problems that don't fit simpler patterns: Strongly Connected Components (SCC), bridges/articulation points, bipartite checking, Eulerian paths, and the Travelling Salesman Problem (TSP).

---

### 12A — Bipartite Graph Check

**Detect if a graph can be 2-colored (no odd cycles)**:
```cpp
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for (int start = 0; start < n; start++) {
        if (color[start] != -1) continue;
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node]; // flip color
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false; // same color = not bipartite
                }
            }
        }
    }
    return true;
}
```

---

### 12B — Strongly Connected Components (Kosaraju's)

**Find all SCCs in a directed graph**:
```cpp
// Step 1: DFS on original graph, push nodes to stack in finish order
// Step 2: Transpose the graph (reverse all edges)
// Step 3: DFS on transposed graph in reverse finish order
// Each DFS tree in step 3 = one SCC

void dfs1(int node, vector<vector<int>>& adj,
          vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int nb : adj[node])
        if (!visited[nb]) dfs1(nb, adj, visited, st);
    st.push(node); // push AFTER all neighbors
}

void dfs2(int node, vector<vector<int>>& radj,
          vector<bool>& visited) {
    visited[node] = true;
    for (int nb : radj[node])
        if (!visited[nb]) dfs2(nb, radj, visited);
}

int countSCC(int n, vector<vector<int>>& adj) {
    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i]) dfs1(i, adj, visited, st);

    vector<vector<int>> radj(n);
    for (int u = 0; u < n; u++)
        for (int v : adj[u]) radj[v].push_back(u);

    fill(visited.begin(), visited.end(), false);
    int scc = 0;
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (!visited[node]) { dfs2(node, radj, visited); scc++; }
    }
    return scc;
}
```

---

### 12C — Bridges and Articulation Points (Tarjan's)

**Find edges/nodes whose removal disconnects the graph**:
```cpp
int timer = 0;
vector<int> disc(n,-1), low(n), parent(n,-1);
vector<bool> isAP(n, false);
vector<pair<int,int>> bridges;

void dfs(int u, vector<vector<int>>& adj) {
    disc[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) {
        if (disc[v] == -1) {
            children++;
            parent[v] = u;
            dfs(v, adj);
            low[u] = min(low[u], low[v]);
            // Articulation point condition
            if (parent[u] == -1 && children > 1) isAP[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u]) isAP[u] = true;
            // Bridge condition
            if (low[v] > disc[u]) bridges.push_back({u, v});
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}
```

---

### 12D — Travelling Salesman Problem (TSP) — Bitmask DP

**Find minimum cost tour visiting all nodes exactly once**:
```cpp
// dp[mask][i] = min cost to visit all nodes in mask, ending at node i
int n = /* number of cities */;
vector<vector<int>> dp(1<<n, vector<int>(n, INT_MAX));
dp[1][0] = 0; // start at node 0, only node 0 visited

for (int mask = 1; mask < (1<<n); mask++) {
    for (int u = 0; u < n; u++) {
        if (!(mask & (1<<u))) continue;         // u not in mask
        if (dp[mask][u] == INT_MAX) continue;
        for (int v = 0; v < n; v++) {
            if (mask & (1<<v)) continue;        // v already visited
            int newMask = mask | (1<<v);
            dp[newMask][v] = min(dp[newMask][v],
                                 dp[mask][u] + dist[u][v]);
        }
    }
}

int fullMask = (1<<n) - 1;
int ans = INT_MAX;
for (int u = 1; u < n; u++)
    ans = min(ans, dp[fullMask][u] + dist[u][0]); // return to start
```

---

### Must-Solve Problems

| # | Problem | Difficulty | Key Concept |
|---|---|---|---|
| 785 | Is Graph Bipartite? | Medium | 2-coloring BFS/DFS |
| 886 | Possible Bipartition | Medium | Bipartite on conflict graph |
| 1557 | Minimum Number of Vertices | Medium | Nodes with no incoming edges |
| 1192 | Critical Connections in a Network | Hard | Bridges (Tarjan's) |
| 847 | Shortest Path Visiting All Nodes | Hard | BFS + bitmask |
| 943 | Find the Shortest Superstring | Hard | TSP bitmask DP |
| 2360 | Longest Cycle in a Graph | Hard | SCC / functional graph |
| 2127 | Maximum Employees to Invite | Hard | Functional graph + SCC |

### All Problems in Pattern 12

- 785 Is Graph Bipartite?
- 847 Shortest Path Visiting All Nodes
- 886 Possible Bipartition
- 943 Find the Shortest Superstring
- 1192 Critical Connections in a Network
- 1489 Find Critical and Pseudo-Critical Edges
- 1557 Minimum Number of Vertices to Reach All Nodes
- 2097 Valid Arrangement of Pairs (Eulerian Path)
- 2127 Maximum Employees to Invite to a Meeting
- 2360 Longest Cycle in a Graph
- 2876 Count Visited Nodes in a Directed Graph

---

## 30-Day Mastery Roadmap

> **Philosophy**: Learn the pattern → internalize the template → apply to 3-5 problems → move on.

### Week 1 — Graph Foundations (Days 1-7)

| Day | Focus | Problems to Solve |
|---|---|---|
| 1 | Build graph + DFS basics | 200, 547, 133 |
| 2 | Pattern 1: DFS advanced | 695, 797, 841, 1971 |
| 3 | Pattern 2: BFS shortest path | 542, 1091, 1926 |
| 4 | Pattern 2: BFS advanced | 127, 433, 1129 |
| 5 | Pattern 5: Flood fill | 733, 200, 695, 130 |
| 6 | Pattern 5: Advanced flood fill | 1020, 1254, 827 |
| 7 | Review Week 1 | Re-solve 4 hardest from week |

### Week 2 — Core Algorithms (Days 8-14)

| Day | Focus | Problems to Solve |
|---|---|---|
| 8 | Pattern 6: Multi-source BFS | 994, 542, 417 |
| 9 | Pattern 6: Advanced multi-BFS | 1162, 1765, 2258 |
| 10 | Pattern 3: Cycle detection | 207, 684, 802 |
| 11 | Pattern 4: Topological sort | 207, 210, 310 |
| 12 | Pattern 4: Advanced topo | 269, 1857, 2050 |
| 13 | Pattern 10: DSU basics | 684, 547, 990 |
| 14 | Pattern 10: DSU advanced | 721, 1202, 1319 |

### Week 3 — Shortest Path Algorithms (Days 15-21)

| Day | Focus | Problems to Solve |
|---|---|---|
| 15 | Pattern 7: Dijkstra basics | 743, 1514 |
| 16 | Pattern 7: Dijkstra on grid | 1631, 778 |
| 17 | Pattern 7: Advanced Dijkstra | 787, 1976, 2577 |
| 18 | Pattern 8: Bellman-Ford | 787, 743, 2976 |
| 19 | Pattern 9: Floyd-Warshall | 1334, 1462 |
| 20 | Pattern 11: MST Kruskal | 1584, 1135 |
| 21 | Pattern 11: MST Prim + advanced | 1489, 1168 |

### Week 4 — Advanced + Mock Interviews (Days 22-30)

| Day | Focus | Problems to Solve |
|---|---|---|
| 22 | Pattern 12: Bipartite | 785, 886 |
| 23 | Pattern 12: Bridges/SCC | 1192, 2360, 2127 |
| 24 | Pattern 12: TSP bitmask | 847, 943 |
| 25 | Pattern 10: Hard DSU | 2421, 2709, 1579 |
| 26 | Cross-pattern hard problems | 2812, 2045, 1857 |
| 27 | Mock Interview Day 1 | Random 5 (all patterns) |
| 28 | Mock Interview Day 2 | 3 mediums + 1 hard |
| 29 | Weak pattern reinforcement | Fill gaps from mocks |
| 30 | Final review | Re-solve 10 hardest problems |

---

## Top 30 Must Solve Interview Problems

| Priority | # | Problem | Pattern | Difficulty |
|---|---|---|---|---|
| 🔥🔥🔥 | 200 | Number of Islands | P5 | Medium |
| 🔥🔥🔥 | 207 | Course Schedule | P3/P4 | Medium |
| 🔥🔥🔥 | 210 | Course Schedule II | P4 | Medium |
| 🔥🔥🔥 | 743 | Network Delay Time | P7 | Medium |
| 🔥🔥🔥 | 994 | Rotting Oranges | P6 | Medium |
| 🔥🔥🔥 | 127 | Word Ladder | P2 | Hard |
| 🔥🔥🔥 | 684 | Redundant Connection | P10 | Medium |
| 🔥🔥🔥 | 1631 | Path With Minimum Effort | P7 | Medium |
| 🔥🔥🔥 | 1584 | Min Cost to Connect All Points | P11 | Medium |
| 🔥🔥🔥 | 547 | Number of Provinces | P1/P10 | Medium |
| 🔥🔥 | 417 | Pacific Atlantic Water Flow | P6 | Medium |
| 🔥🔥 | 542 | 01 Matrix | P6 | Medium |
| 🔥🔥 | 133 | Clone Graph | P1 | Medium |
| 🔥🔥 | 785 | Is Graph Bipartite? | P12 | Medium |
| 🔥🔥 | 787 | Cheapest Flights Within K Stops | P7/P8 | Medium |
| 🔥🔥 | 721 | Accounts Merge | P10 | Medium |
| 🔥🔥 | 1334 | Find City With Fewest Neighbors | P9 | Medium |
| 🔥🔥 | 802 | Find Eventual Safe States | P3/P4 | Medium |
| 🔥🔥 | 310 | Minimum Height Trees | P4 | Medium |
| 🔥🔥 | 695 | Max Area of Island | P5 | Medium |
| 🔥🔥 | 1091 | Shortest Path in Binary Matrix | P2 | Medium |
| 🔥 | 269 | Alien Dictionary | P4 | Hard |
| 🔥 | 1192 | Critical Connections (Bridges) | P12 | Hard |
| 🔥 | 778 | Swim in Rising Water | P7 | Hard |
| 🔥 | 1976 | Number of Ways to Arrive on Time | P7 | Medium |
| 🔥 | 990 | Satisfiability of Equality Equations | P10 | Medium |
| 🔥 | 847 | Shortest Path Visiting All Nodes | P12 | Hard |
| 🔥 | 1489 | Critical and Pseudo-Critical Edges | P11/P12 | Hard |
| 🔥 | 2421 | Number of Good Paths | P10/P11 | Hard |
| 🔥 | 1857 | Largest Color Value in Directed Graph | P4 | Hard |

---

## Hybrid Decision Guide

| Combination | Rule | Example |
|---|---|---|
| P1 vs P2 | DFS if exploring all paths/components; BFS if shortest path needed | 797 vs 127 |
| P2 vs P6 | P2 (single source BFS) if one start; P6 if multiple sources simultaneously | 1091 vs 994 |
| P3 vs P4 | P3 if just asking "is there a cycle?"; P4 if asking for ordering | 207 vs 210 |
| P4 vs P1 | P4 if DAG with dependencies; P1 if general graph exploration | 210 vs 841 |
| P5 vs P6 | P5 if from single source on grid; P6 if spreading from all sources at once | 200 vs 994 |
| P7 vs P2 | P7 (Dijkstra) if weighted edges; P2 (BFS) if all edges weight 1 | 743 vs 127 |
| P7 vs P8 | P7 if no negative weights (faster); P8 if negative weights present | 743 vs 787 |
| P8 vs P9 | P8 for single-source with negative weights; P9 for all-pairs | 787 vs 1334 |
| P10 vs P2/P1 | P10 if queries ask "same component?" dynamically; P1/P2 if one-time reachability | 684 vs 547 |
| P10 vs P11 | P10 detects cycles/components; P11 builds MST (uses P10 as subroutine in Kruskal) | 684 vs 1584 |
| P11 vs P7 | P11 connects ALL nodes minimally; P7 finds shortest path from one source | 1584 vs 743 |
| P12 vs P3 | P12 (SCC/Tarjan) for strongly connected; P3 for simple cycle existence | 2127 vs 207 |

---

## Quick Reference — Common Mistakes

| Mistake | Correct Approach |
|---|---|
| Using DFS for shortest path in unweighted graph | Use BFS — DFS does NOT guarantee shortest path |
| Not checking visited before pushing to BFS queue | Mark visited WHEN PUSHING, not when popping — prevents duplicate processing |
| Dijkstra with negative edge weights | Use Bellman-Ford for negative weights; Dijkstra is incorrect with negatives |
| Floyd-Warshall overflow with INT_MAX | Use INT_MAX/2 to avoid overflow when adding dist[i][k] + dist[k][j] |
| Topological sort on graph with cycle | Check if output size == n; if not, cycle exists — return invalid |
| DSU without path compression | Always implement path compression in find() for O(α) amortized |
| Kruskal: not checking if edge creates cycle | Always use DSU.unite() return value — false means same component, skip edge |
| Multi-source BFS: pushing sources with distance 1 | All sources must start at distance 0 — push them all before the BFS loop |
| Undirected cycle detection: checking visited without parent | Must track parent to avoid false cycle detection via the same edge |
| Grid BFS/DFS: forgetting boundary check | Always check r>=0, r<m, c>=0, c<n before accessing grid[r][c] |
| Bellman-Ford: not using snapshot of previous round | For K-stops BFS, copy dist array before each round to avoid chaining in same round |
| TSP bitmask: starting mask wrong | Initialize dp[1<<0][0] = 0, all others INT_MAX; start node is always 0 |

---

*Guide compiled from 250+ LeetCode graph problems, mapped to 12 universal patterns.*
*Covers all categories: DFS/BFS · Cycle Detection · Topological Sort · Flood Fill · Multi-Source BFS · Dijkstra · Bellman-Ford · Floyd-Warshall · TSP · DSU · MST · Advanced Algorithms.*
*Master these patterns and you will solve 95%+ of graph questions in any technical interview.*
