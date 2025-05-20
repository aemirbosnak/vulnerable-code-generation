//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_M 1000
#define MAX_W 100000

typedef struct {
    int id;
    int weight;
    int value;
} Item;

void readInput(Item items[], int *n) {
    char filename[50];
    FILE *file;
    int i = 0;

    printf("Enter the input file name: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(file, "%d", n);

    for (; i < *n; i++) {
        fscanf(file, "%d%d%d", &items[i].id, &items[i].weight, &items[i].value);
    }

    fclose(file);
}

void printSolution(int capacity, Item items[], int n) {
    int i, j, w = 0;
    int solution[n];
    int totalValue = 0;

    for (i = 0; i < n; i++) {
        if ((w + items[i].weight) <= capacity) {
            solution[j++] = items[i].id;
            totalValue += items[i].value;
            w += items[i].weight;
        }
    }

    printf("\nSolution:\n");
    for (i = 0; i < j; i++) {
        printf("%d ", solution[i]);
    }
    printf("\nTotal value: %d", totalValue);
}

int main() {
    Item items[MAX_N];
    int n, w, i;

    readInput(items, &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &w);

    // Sort items in decreasing order of value/weight ratio
    for (i = 0; i < n - 1; i++) {
        int bestIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (items[j].value / (float)items[j].weight > items[bestIndex].value / (float)items[bestIndex].weight) {
                bestIndex = j;
            }
        }
        if (bestIndex != i) {
            Item temp = items[i];
            items[i] = items[bestIndex];
            items[bestIndex] = temp;
        }
    }

    printSolution(w, items, n);

    return 0;
}