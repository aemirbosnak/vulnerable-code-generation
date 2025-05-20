//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

int main()
{
    int i, j, k, l, n, t, a[MAX], b[MAX], c[MAX], d[MAX];
    double r, v, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10;
    FILE *fp;

    fp = fopen("circuit.txt", "r");
    fscanf(fp, "%d", &n);
    fscanf(fp, "%lf", &r);
    fclose(fp);

    r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r;

    v1 = v2 = v3 = v4 = v5 = v6 = v7 = v8 = v9 = v10 = 0.0;

    a[0] = b[0] = c[0] = d[0] = 1;

    for (i = 1; i < n; i++)
    {
        fscanf(fp, "%lf", &v);
        a[i] = b[i] = c[i] = d[i] = (int)(v * MAX);
    }

    fclose(fp);

    for (i = 0; i < n; i++)
    {
        v = (double)a[i] / MAX;
        v1 = v2 = v3 = v4 = v5 = v6 = v7 = v8 = v9 = v10 = v;
        r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = r;

        for (j = 0; j < i; j++)
        {
            v = (double)a[j] / MAX;
            r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = v * r;
        }

        for (k = i + 1; k < n; k++)
        {
            v = (double)a[k] / MAX;
            r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = r10 = v * r;
        }

        printf("Node %d: Voltage = %.2lf V\n", i + 1, v);
    }

    return 0;
}