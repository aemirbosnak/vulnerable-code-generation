//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, l, m, f = 0, r = 0, t = 0, d = 0, b = 0;
    char **a, **c, **e, **h, **o, **p, **q, **s, **u, **v, **w, **x, **y, **z;

    a = (char **)malloc(n * sizeof(char *));
    c = (char **)malloc(n * sizeof(char *));
    e = (char **)malloc(n * sizeof(char *));
    h = (char **)malloc(n * sizeof(char *));
    o = (char **)malloc(n * sizeof(char *));
    p = (char **)malloc(n * sizeof(char *));
    q = (char **)malloc(n * sizeof(char *));
    s = (char **)malloc(n * sizeof(char *));
    u = (char **)malloc(n * sizeof(char *));
    v = (char **)malloc(n * sizeof(char *));
    w = (char **)malloc(n * sizeof(char *));
    x = (char **)malloc(n * sizeof(char *));
    y = (char **)malloc(n * sizeof(char *));
    z = (char **)malloc(n * sizeof(char *));

    scanf("Enter the number of nodes: ", &n);

    for (i = 0; i < n; i++)
    {
        a[i] = (char *)malloc(20 * sizeof(char));
        c[i] = (char *)malloc(20 * sizeof(char));
        e[i] = (char *)malloc(20 * sizeof(char));
        h[i] = (char *)malloc(20 * sizeof(char));
        o[i] = (char *)malloc(20 * sizeof(char));
        p[i] = (char *)malloc(20 * sizeof(char));
        q[i] = (char *)malloc(20 * sizeof(char));
        s[i] = (char *)malloc(20 * sizeof(char));
        u[i] = (char *)malloc(20 * sizeof(char));
        v[i] = (char *)malloc(20 * sizeof(char));
        w[i] = (char *)malloc(20 * sizeof(char));
        x[i] = (char *)malloc(20 * sizeof(char));
        y[i] = (char *)malloc(20 * sizeof(char));
        z[i] = (char *)malloc(20 * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the name of node %d: ", i + 1);
        scanf("%s", a[i]);

        printf("Enter the connections of node %d: ", i + 1);
        scanf("%s", c[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < strlen(c[i]); j++)
        {
            if (c[i][j] == ' ')
            {
                r++;
            }
        }
    }

    printf("The total number of connections is: %d", r);

    return 0;
}