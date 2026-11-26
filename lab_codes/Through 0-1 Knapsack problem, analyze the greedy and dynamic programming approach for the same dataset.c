#include <stdio.h>

int main()
{
    int w[3] = {10, 20, 30};
    int p[3] = {60, 100, 120};
    int capacity = 50;

    int i, j;
    int dp[4][51];

    /* Greedy Approach */
    int weight = 0, profit = 0;

    for(i = 0; i < 3; i++)
    {
        if(weight + w[i] <= capacity)
        {
            weight += w[i];
            profit += p[i];
        }
    }

    printf("Greedy Profit = %d\n", profit);

    /* Dynamic Programming */
    for(i = 0; i <= 3; i++)
    {
        for(j = 0; j <= capacity; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(w[i-1] <= j)
            {
                int a = p[i-1] + dp[i-1][j-w[i-1]];
                int b = dp[i-1][j];

                dp[i][j] = (a > b) ? a : b;
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    printf("DP Profit = %d\n", dp[3][capacity]);

    return 0;
}
