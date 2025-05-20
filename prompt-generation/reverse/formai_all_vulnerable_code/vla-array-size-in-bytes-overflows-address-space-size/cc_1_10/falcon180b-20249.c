//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int value;
    int weight;
} Item;

int compare(const void *a, const void *b) {
    return (*(Item*)a).value - (*(Item*)b).value;
}

int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    Item item[n];

    for(i = 0; i < n; i++) {
        item[i].value = val[i];
        item[i].weight = wt[i];
    }

    qsort(item, n, sizeof(Item), compare);

    w = 0;
    for(i = 0; i < n; i++) {
        if(w + item[i].weight <= W) {
            w += item[i].weight;
            W += item[i].value;
        }
    }

    return W;
}

int main() {
    int n, W, i, val[MAX_SIZE], wt[MAX_SIZE];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the values and weights of the items:\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }

    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);

    printf("The maximum value that can be obtained is: %d\n", knapSack(W, wt, val, n));

    return 0;
}