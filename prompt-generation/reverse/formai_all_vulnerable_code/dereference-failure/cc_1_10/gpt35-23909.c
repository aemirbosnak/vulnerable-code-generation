//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct voter {
    char name[50];
    int age;
    int voted;
} Voter;

void castVote(Voter *v) {
    printf("Hello %s, please enter your vote:\n", v->name);
    printf("1. Candidate A\n2. Candidate B\n3. Candidate C\n");

    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid choice\n");
        return;
    }

    printf("Thank you for voting!\n");
    v->voted = 1;
}

int main() {
    printf("Welcome to the Electronic Voting System!\n");

    int numVoters;
    printf("Enter number of voters: ");
    scanf("%d", &numVoters);

    Voter *voters = (Voter*)malloc(numVoters * sizeof(Voter));

    for (int i = 0; i < numVoters; i++) {
        printf("Enter name of voter %d: ", i+1);
        scanf(" %[^\n]", voters[i].name);

        printf("Enter age of voter %d: ", i+1);
        scanf("%d", &voters[i].age);

        voters[i].voted = 0;
    }

    char anotherVote = 'y';
    while (anotherVote == 'y') {
        char voterName[50];
        printf("Enter voter name: ");
        scanf(" %[^\n]", voterName);

        int voterFound = 0;
        for (int i = 0; i < numVoters; i++) {
            if (strcmp(voters[i].name, voterName) == 0) {
                if (voters[i].voted == 1) {
                    printf("This voter has already cast their vote!\n");
                } else {
                    castVote(&voters[i]);
                    voters[i].voted = 1;
                }
                voterFound = 1;
                break;
            }
        }

        if (voterFound == 0) {
            printf("Voter with the name '%s' not found!\n", voterName);
        }

        printf("Do you want to enter another vote? (y/n): ");
        scanf(" %c", &anotherVote);
    }

    printf("Thank you for using the Electronic Voting System!\n");

    free(voters);
    return 0;
}