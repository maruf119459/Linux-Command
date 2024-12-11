The given problem can be solved using the 0/1 Knapsack dynamic programming approach, as illustrated in the program. The goal is to calculate the maximum value achievable by selecting items within the weight capacity. Let's solve it step-by-step:

---

### Input Details:
- **Weights**: {1, 3, 4, 5}
- **Values**: {1, 4, 5, 7}
- **Capacity (W)**: 7

---

### Dynamic Programming Table:

We will build the DP table as follows:

1. Create a matrix `dp[n+1][W+1]` where:
   - Rows (`i`) represent items (0 to `n`).
   - Columns (`w`) represent weights (0 to `W`).

2. **Rules**:
   - If the current item's weight (`wt[i-1]`) is less than or equal to the current capacity (`w`), include it:
     \[
     dp[i][w] = \max\left(\text{val[i-1]} + dp[i-1][w-\text{wt[i-1]}],\ dp[i-1][w]\right)
     \]
   - Else, exclude the item:
     \[
     dp[i][w] = dp[i-1][w]
     \]

---

### Step-by-Step Solution:

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

### Explanation:
1. Item 1 is included, providing value **1**.
2. Item 2 is included, providing value **4**.
3. Item 3 is included, providing value **5**.
4. Item 4 is excluded as it would exceed the weight capacity.

---

### Code Confirmation:
The given code in the image correctly implements this solution, and the result matches the analysis. The output is **9**, as expected.
