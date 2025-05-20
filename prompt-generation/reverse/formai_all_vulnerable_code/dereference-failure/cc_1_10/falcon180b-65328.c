//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int n, i;
    double x, y, z, pi;
    double *a, *b, *c;

    srand(time(NULL));
    n = rand() % 100 + 1;
    pi = M_PI;

    a = (double *)malloc(n * sizeof(double));
    b = (double *)malloc(n * sizeof(double));
    c = (double *)malloc(n * sizeof(double));

    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }

    for (i = 0; i < n; i++) {
        x = a[i];
        y = b[i];
        z = pow(x, 2) + pow(y, 2);
        c[i] = sqrt(z);
    }

    printf("The list of numbers is: \n");
    for (i = 0; i < n; i++) {
        printf("%lf ", a[i]);
    }
    printf("\n");

    printf("The list of numbers is: \n");
    for (i = 0; i < n; i++) {
        printf("%lf ", b[i]);
    }
    printf("\n");

    printf("The list of numbers is: \n");
    for (i = 0; i < n; i++) {
        printf("%lf ", c[i]);
    }
    printf("\n");

    return 0;
}