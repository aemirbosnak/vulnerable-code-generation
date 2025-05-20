//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct candidate {
    int id;
    char name[50];
    int vote_count;
};

struct voter {
    int id;
    bool has_voted;
};

int main() {
    int num_candidates, num_voters, choice;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    struct candidate candidates[num_candidates];

    for (int i = 0; i < num_candidates; i++) {
        candidates[i].id = i + 1;

        printf("Enter the name of candidate %d: ", candidates[i].id);
        scanf("%s", candidates[i].name);

        candidates[i].vote_count = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    struct voter voters[num_voters];

    for (int i = 0; i < num_voters; i++) {
        voters[i].id = i + 1;
        voters[i].has_voted = false;
    }

    while (true) {
        printf("\n1. Cast vote\n");
        printf("2. View results\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n");
                printf("List of candidates:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%d. %s\n", candidates[i].id, candidates[i].name);
                }

                int candidate_id;
                bool valid_candidate = false;

                do {
                    printf("Enter the ID of the candidate you want to vote for: ");
                    scanf("%d", &candidate_id);

                    for (int i = 0; i < num_candidates; i++) {
                        if (candidates[i].id == candidate_id) {
                            valid_candidate = true;
                            break;
                        }
                    }

                    if (!valid_candidate) {
                        printf("Invalid candidate ID. Please try again.\n");
                    }
                } while (!valid_candidate);

                int voter_id;
                bool valid_voter = false;

                do {
                    printf("Enter your voter ID: ");
                    scanf("%d", &voter_id);

                    for (int i = 0; i < num_voters; i++) {
                        if (voters[i].id == voter_id) {
                            if (voters[i].has_voted) {
                                printf("You have already voted.\n");
                                break;
                            }
                            else {
                                voters[i].has_voted = true;

                                for (int j = 0; j < num_candidates; j++) {
                                    if (candidates[j].id == candidate_id) {
                                        candidates[j].vote_count++;
                                        printf("Thank you for casting your vote for %s.\n", candidates[j].name);
                                        break;
                                    }
                                }

                                valid_voter = true;
                                break;
                            }
                        }
                    }

                    if (!valid_voter) {
                        printf("Invalid voter ID. Please try again.\n");
                    }
                } while (!valid_voter);

                break;
            case 2:
                printf("\n");
                printf("Results:\n");

                for (int i = 0; i < num_candidates; i++) {
                    printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
                }

                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}