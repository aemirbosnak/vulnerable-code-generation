//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[100];
    int voteCount;
};

void printMenu() {
    printf("Select an option:\n");
    printf("1. Add a candidate\n");
    printf("2. Vote for a candidate\n");
    printf("3. Display results\n");
    printf("4. Quit\n");
}

int main() {
    int option;
    int candidateCount = 0;
    char tempName[100];
    struct Candidate* candidates[100];

    while (1) {
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", tempName);

                candidates[candidateCount] = malloc(sizeof(struct Candidate));
                strcpy(candidates[candidateCount]->name, tempName);
                candidates[candidateCount]->voteCount = 0;
                printf("Candidate added successfully!\n");
                candidateCount++;
                break;

            case 2:
                printf("Enter candidate name: ");
                scanf("%s", tempName);

                for (int i = 0; i < candidateCount; i++) {
                    if (strcmp(tempName, candidates[i]->name) == 0) {
                        candidates[i]->voteCount++;
                        printf("Vote has been cast!\n");
                        break;
                    }
                    if (i == candidateCount - 1) {
                        printf("Invalid candidate name. Please try again.\n");
                    }
                }
                break;

            case 3:
                for (int i = 0; i < candidateCount; i++) {
                    printf("Candidate Name: %s\n", candidates[i]->name);
                    printf("Vote Count: %d\n", candidates[i]->voteCount);
                }
                break;

            case 4:
                printf("Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please select again.\n");
        }
    }
    return 0;
}