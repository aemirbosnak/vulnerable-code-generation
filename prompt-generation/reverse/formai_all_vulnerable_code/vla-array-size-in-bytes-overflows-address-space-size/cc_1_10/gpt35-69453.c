//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// struct for each candidate
struct Candidate {
    char name[100];
    int num_of_votes;
};

// function to print all candidate names
void print_candidates(struct Candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// function to cast vote
void cast_vote(struct Candidate candidates[], int num_candidates, int candidate_choice) {
    if (candidate_choice < 1 || candidate_choice > num_candidates) {
        printf("Invalid choice. Please try again.\n");
        return;
    }
    candidates[candidate_choice-1].num_of_votes++;
    printf("Thank you for casting your vote!\n");
}

// function to print results
void print_results(struct Candidate candidates[], int num_candidates) {
    printf("------ Results ------\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes.\n", i+1, candidates[i].name, candidates[i].num_of_votes);
    }
}

int main() {
    // get number of candidates
    int num_candidates;
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    // create an array of candidates
    struct Candidate candidates[num_candidates];

    // get names of candidates
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].num_of_votes = 0;
    }

    int user_choice;
    do {
        // print menu
        printf("\n-------- Menu --------\n");
        printf("1. View Candidates\n");
        printf("2. Cast Vote\n");
        printf("3. View Results\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");

        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                print_candidates(candidates, num_candidates);
                break;
            case 2:
                printf("Enter the candidate number you want to vote for: ");
                int candidate_choice;
                scanf("%d", &candidate_choice);
                cast_vote(candidates, num_candidates, candidate_choice);
                break;
            case 3:
                print_results(candidates, num_candidates);
                break;
            case 4:
                printf("Thank you for using our voting system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (user_choice != 4);

    return 0;
}