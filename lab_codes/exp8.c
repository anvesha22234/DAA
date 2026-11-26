#include <stdio.h>
#define INF 999

int main()
{
    int g[4][4] = {
        {0, 4, 1, 0},
        {4, 0, 2, 1},
        {1, 2, 0, 5},
        {0, 1, 5, 0}
    };

    int d[4] = {0, INF, INF, INF};
    int visited[4] = {0};
    int i, j, u, min;

    /* Dijkstra */
    for (i = 0; i < 4; i++)
    {
        min = INF;
        u = 0;

        for (j = 0; j < 4; j++)
            if (!visited[j] && d[j] < min)
            {
                min = d[j];
                u = j;
            }

        visited[u] = 1;

        for (j = 0; j < 4; j++)
            if (g[u][j] && d[u] + g[u][j] < d[j])
                d[j] = d[u] + g[u][j];
    }

    printf("Dijkstra: ");
    for (i = 0; i < 4; i++)
        printf("%d ", d[i]);

    /* Bellman Ford */
    d[0] = 0;
    d[1] = d[2] = d[3] = INF;

    for (i = 0; i < 3; i++)
        for (u = 0; u < 4; u++)
            for (j = 0; j < 4; j++)
                if (g[u][j] && d[u] + g[u][j] < d[j])
                    d[j] = d[u] + g[u][j];

    printf("\nBellman Ford: ");
    for (i = 0; i < 4; i++)
        printf("%d ", d[i]);

    return 0;
}
