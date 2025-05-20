//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Candidate {
    char* name;
    int votes;
};

struct Election {
    struct Candidate candidates[5];
    int num_candidates;
};

int main() {
    struct Election* election = (struct Election*)malloc(sizeof(struct Election));
    election->num_candidates = 5;
    char* names[] = {"John Doe", "Jane Smith", "Robert Johnson", "Emily Davis", "Michael Brown"};
    struct Candidate candidates[5];
    int i;

    for (i = 0; i < 5; i++) {
        candidates[i].name = names[i];
        candidates[i].votes = 0;
        election->candidates[i] = candidates[i];
    }

    while (1) {
        printf("Election System\n");
        printf("-----------------\n");
        printf("1. Cast Vote\n");
        printf("2. View Results\n");
        printf("3. Quit\n");
        int choice;
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char* name;
                int votes;
                printf("Enter candidate name: ");
                scanf("%s", &name);
                if (strcmp(name, "quit") == 0) {
                    break;
                }
                for (i = 0; i < 5; i++) {
                    if (strcmp(election->candidates[i].name, name) == 0) {
                        printf("Enter number of votes: ");
                        scanf("%d", &votes);
                        election->candidates[i].votes += votes;
                        break;
                    }
                }
                break;
            }
            case 2: {
                int i;
                for (i = 0; i < 5; i++) {
                    printf("%d. %s: %d\n", i + 1, election->candidates[i].name, election->candidates[i].votes);
                }
                break;
            }
            case 3: {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    free(election);
    return 0;
}