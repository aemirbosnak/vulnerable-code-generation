//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: rigorous
/* A simple Electronic Voting System using C programming language */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* structure to hold candidate information */
struct candidate {
    int id;
    char name[30];
    int votes;
};

/* function prototype */
void cast_vote(int, struct candidate[]);
void display_results(struct candidate[]);

/* main function */
int main() {
    int n_candidates, choice, i;
    struct candidate *c_list;
    
    printf("Enter the number of candidates: ");
    scanf("%d", &n_candidates);
    getchar();  /* to clear buffer */
    
    /* allocate memory dynamically for candidate list */
    c_list = (struct candidate*) malloc(n_candidates * sizeof(struct candidate));
    
    /* get candidate details */
    for (i = 0; i < n_candidates; i++) {
        printf("\nEnter details for candidate %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &c_list[i].id);
        printf("Name: ");
        scanf("%s", c_list[i].name);
        c_list[i].votes = 0;  /* set initial votes to 0 */
    }
    
    /* main menu */
    printf("\nWelcome to Electronic Voting System\n");
    do {
        printf("\n1. Cast your vote\n");
        printf("2. Display voting results\n");
        printf("3. Quit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                cast_vote(n_candidates, c_list);
                break;
            case 2:
                display_results(c_list);
                break;
            case 3:
                printf("\nThank you for using Electronic Voting System\n");
                break;
            default:
                printf("\nInvalid choice! Please choose again.\n");
        }
    } while (choice != 3);
    
    free(c_list);  /* free dynamically allocated memory */
    
    return 0;
}

/* function to cast vote */
void cast_vote(int n, struct candidate c[]) {
    int id, i, flag = 0;
    
    printf("\nEnter candidate ID to vote: ");
    scanf("%d", &id);
    
    /* check if candidate ID is valid */
    for (i = 0; i < n; i++) {
        if (c[i].id == id) {
            c[i].votes++;
            flag = 1;
            printf("\nVote casted successfully for candidate %s\n", c[i].name);
            break;
        }
    }
    
    if (!flag) {
        printf("\nInvalid candidate ID! Please choose again.\n");
    }
}

/* function to display voting results */
void display_results(struct candidate c[]) {
    int i, max_votes = 0, total_votes = 0;
    
    printf("\nID\tName\tVotes\n");
    for (i = 0; c[i].id != 0; i++) {
        printf("%d\t%s\t%d\n", c[i].id, c[i].name, c[i].votes);
        
        /* track candidate with maximum votes */
        if (c[i].votes > max_votes) {
            max_votes = c[i].votes;
        }
        total_votes += c[i].votes;  /* calculate total votes */
    }
    
    printf("\nTotal votes casted: %d\n", total_votes);
    
    /* display candidate(s) with maximum votes */
    printf("Candidate(s) with maximum votes:\n");
    for (i = 0; c[i].id != 0; i++) {
        if (c[i].votes == max_votes) {
            printf("%s\n", c[i].name);
        }
    }
}