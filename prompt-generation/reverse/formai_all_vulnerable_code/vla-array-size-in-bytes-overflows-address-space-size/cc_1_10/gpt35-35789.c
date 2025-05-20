//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate {
    int id;
    char name[50];
    int votes;
};

void display_candidates(struct candidate list[], int n) {
    printf("List of candidates:\n");
    printf("ID\tName\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%s\n", list[i].id, list[i].name);
    }
}

void cast_vote(struct candidate list[], int n, int id) {
    for(int i=0; i<n; i++) {
        if(list[i].id == id) {
            list[i].votes++;
            printf("Vote casted for %s\n", list[i].name);
            return;
        }
    }
    printf("Invalid candidate ID. Please try again.\n");
}

void display_results(struct candidate list[], int n) {
    int max_votes = -1;
    int winner_id = -1;
    printf("ID\tName\tVotes\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%s\t%d\n", list[i].id, list[i].name, list[i].votes);
        if(list[i].votes > max_votes) {
            max_votes = list[i].votes;
            winner_id = list[i].id;
        }
    }
    printf("The winner is %s with %d votes!\n", list[winner_id-1].name, max_votes);
}

int main() {
    int n;
    printf("Enter the number of candidates: ");
    scanf("%d", &n);
    struct candidate list[n];
    for(int i=0; i<n; i++) {
        printf("Enter the ID and name for candidate %d: ", i+1);
        scanf("%d %s", &list[i].id, list[i].name);
        list[i].votes = 0;
    }
    printf("Welcome to the Electronic Voting System!\n");
    display_candidates(list, n);
    int choice = -1;
    while(choice != 0) {
        printf("Press 1 to cast vote, 2 to display results, 0 to exit: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the candidate ID to cast vote: ");
                int id;
                scanf("%d", &id);
                cast_vote(list, n, id);
                break;
            case 2:
                display_results(list, n);
                break;
            case 0:
                printf("Thank you for using the Electronic Voting System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}