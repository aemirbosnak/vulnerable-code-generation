//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char name[32];
    int age;
    float net_worth;
} NeoCitizen;

void swap(NeoCitizen *a, NeoCitizen *b) {
    NeoCitizen temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(NeoCitizen arr[], int low, int high) {
    NeoCitizen pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j].name, pivot.name) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(NeoCitizen arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    NeoCitizen neoCitizens[MAX_SIZE];
    int n;

    printf("\nWelcome to Neo-Tokyo Citizen Records System!\n");

    printf("\nEnter the number of citizens to be recorded: ");
    scanf("%d", &n);

    printf("\nInput the citizen data:\n");
    for (int i = 0; i < n; i++) {
        printf("\nName %d: ", i + 1);
        scanf("%s", neoCitizens[i].name);
        while (getchar() != '\n') {
            putchar(getchar());
        }
        printf("Age: ");
        scanf("%d", &neoCitizens[i].age);
        printf("Net Worth: ");
        scanf("%f", &neoCitizens[i].net_worth);
    }

    printf("\nBefore Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("\nName: %s, Age: %d, Net Worth: %.2f", neoCitizens[i].name, neoCitizens[i].age, neoCitizens[i].net_worth);
    }

    quickSort(neoCitizens, 0, n - 1);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("\nName: %s, Age: %d, Net Worth: %.2f", neoCitizens[i].name, neoCitizens[i].age, neoCitizens[i].net_worth);
    }

    return 0;
}