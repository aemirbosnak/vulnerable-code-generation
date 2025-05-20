//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VOTERS 1000
#define VOTER_FILE "voters.txt"
#define VOTE_FILE "votes.txt"

struct voter {
    char name[50];
    char password[10];
};

int main() {
    FILE *voters_file = fopen(VOTER_FILE, "r");
    FILE *votes_file = fopen(VOTE_FILE, "r");
    struct voter voters[MAX_VOTERS];
    int num_voters = 0, num_votes = 0;
    char name[50], password[10], choice;

    // Load voter data from file
    if (voters_file == NULL) {
        printf("Error: Could not open voter file.\n");
        exit(1);
    }

    while (fscanf(voters_file, "%s %s", voters[num_voters].name, voters[num_voters].password) != EOF) {
        num_voters++;
    }

    fclose(voters_file);

    // Load vote count from file
    if (votes_file == NULL) {
        printf("Error: Could not open vote file.\n");
        exit(1);
    }

    fscanf(votes_file, "%d", &num_votes);

    fclose(votes_file);

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your name and password to vote:\n");

    for (int i = 0; i < num_voters; i++) {
        printf("%d. %s\n", i + 1, voters[i].name);
    }

    scanf("%s", name);
    scanf("%s", password);

    for (int i = 0; i < num_voters; i++) {
        if (strcmp(name, voters[i].name) == 0 && strcmp(password, voters[i].password) == 0) {
            printf("Valid voter. Please choose a candidate (A or B):\n");
            scanf(" %c", &choice);

            FILE *votes_file = fopen(VOTE_FILE, "w");

            fprintf(votes_file, "%d\n", num_votes + 1);
            if (choice == 'A') {
                fprintf(votes_file, "%d %s %d\n", num_votes + 1, voters[i].name, 1);
            } else {
                fprintf(votes_file, "%d %s %d\n", num_votes + 1, voters[i].name, 0);
            }

            fclose(votes_file);

            printf("Thank you for voting! Your vote has been recorded.\n");
            exit(0);
        }
    }

    printf("Invalid voter. Please try again or register to vote.\n");

    return 0;
}