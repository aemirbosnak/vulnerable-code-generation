//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct candidate {
    char name[100];
    int votes;
};

int main() {
    int n, m, i, j, k, valid_votes = 0;
    char input[100];
    struct candidate *candidates = NULL;

    printf("Enter the number of candidates: ");
    scanf("%d", &n);

    candidates = (struct candidate*)malloc(n * sizeof(struct candidate));

    for (i = 0; i < n; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &m);

    int votes[m];

    for (i = 0; i < m; i++) {
        printf("Enter the vote of voter %d (1-%d): ", i+1, n);
        scanf("%s", input);

        if (atoi(input) >= 1 && atoi(input) <= n) {
            valid_votes++;
            votes[i] = atoi(input) - 1;
        } else {
            printf("Invalid vote.\n");
        }
    }

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (candidates[i].votes > candidates[j].votes) {
                struct candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }

    printf("The winner is %s with %d votes.\n", candidates[0].name, candidates[0].votes);

    free(candidates);
    return 0;
}