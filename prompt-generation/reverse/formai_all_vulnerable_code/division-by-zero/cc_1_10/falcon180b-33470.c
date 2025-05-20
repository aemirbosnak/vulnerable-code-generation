//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

void shuffle(candidate arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].votes > arr[j + 1].votes) {
                temp = arr[j].votes;
                arr[j].votes = arr[j + 1].votes;
                arr[j + 1].votes = temp;
            }
        }
    }
}

void print_results(candidate arr[], int n) {
    int i;
    printf("\nResults:\n");
    for (i = 0; i < n; i++) {
        printf("%s - %d votes\n", arr[i].name, arr[i].votes);
    }
}

int main() {
    int n, i;
    candidate arr[100];
    printf("Enter the number of candidates: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", arr[i].name);
        arr[i].votes = 0;
    }
    printf("\nVoting starts...\n");
    srand(time(NULL));
    for (i = 0; i < 100; i++) {
        int r = rand() % n;
        arr[r].votes++;
    }
    printf("\nVoting ends...\n");
    shuffle(arr, n);
    print_results(arr, n);
    return 0;
}