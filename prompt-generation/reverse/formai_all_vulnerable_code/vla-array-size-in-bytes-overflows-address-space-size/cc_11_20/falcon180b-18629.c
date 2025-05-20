//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, j, k, l, m, count = 0;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int a[n], b[n], c[n], d[n];

    printf("\nEnter the elements of array 1:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nEnter the elements of array 2:\n");
    for(j = 0; j < n; j++) {
        scanf("%d", &b[j]);
    }

    printf("\nEnter the elements of array 3:\n");
    for(k = 0; k < n; k++) {
        scanf("%d", &c[k]);
    }

    printf("\nEnter the elements of array 4:\n");
    for(l = 0; l < n; l++) {
        scanf("%d", &d[l]);
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                for(l = 0; l < n; l++) {
                    if(i!= j && i!= k && i!= l && j!= k && j!= l && k!= l) {
                        m = a[i] + b[j] - c[k] - d[l];
                        if(m!= 0) {
                            count++;
                            printf("\nThe sum of %d, %d, %d and %d is %d", a[i], b[j], c[k], d[l], m);
                        }
                    }
                }
            }
        }
    }

    if(count == 0) {
        printf("\nNo non-zero sums found.");
    }

    return 0;
}