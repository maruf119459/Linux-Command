

---

### Input Details:
- **Weights**: {1, 3, 4, 5}
- **Values**: {1, 4, 5, 7}
- **Capacity (W)**: 7

---

### Dynamic Programming Table:

#### Initialize DP Table (Weights: {1, 3, 4, 5}, Values: {1, 4, 5, 7}, Capacity: 7)

| i\w | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|-----|---|---|---|---|---|---|---|---|
|  0  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
|  1  | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
|  2  | 0 | 1 | 1 | 4 | 5 | 5 | 5 | 5 |
|  3  | 0 | 1 | 1 | 4 | 5 | 6 | 6 | 9 |
|  4  | 0 | 1 | 1 | 4 | 5 | 7 | 8 | 9 |

---

### Result:
The maximum value for capacity \( W = 7 \) is found in cell `dp[4][7]`, which is **9**.

---
Let's solve the 0/1 Knapsack problem using the **dynamic programming table approach** step-by-step.

### Step 1: Input
- **Weights**: {2, 3, 4, 6}
- **Values**: {3, 4, 8, 9}
- **Capacity (W)**: 8


### Step 4: Solve the Problem
Here is the table-filled step-by-step solution:

#### Table Construction
| \( i \) (items) | \( w = 0 \) | \( w = 1 \) | \( w = 2 \) | \( w = 3 \) | \( w = 4 \) | \( w = 5 \) | \( w = 6 \) | \( w = 7 \) | \( w = 8 \) |
|-----------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|
| 0              | 0          | 0          | 0          | 0          | 0          | 0          | 0          | 0          | 0          |
| 1              | 0          | 0          | 3          | 3          | 3          | 3          | 3          | 3          | 3          |
| 2              | 0          | 0          | 3          | 4          | 4          | 7          | 7          | 7          | 7          |
| 3              | 0          | 0          | 3          | 4          | 8          | 8          | 11         | 12         | 12         |
| 4              | 0          | 0          | 3          | 4          | 8          | 8          | 11         | 12         | 12         |



### Step 5: Result
The maximum value for capacity \( W = 8 \) is in \( dp[4][8] = 12 \).



