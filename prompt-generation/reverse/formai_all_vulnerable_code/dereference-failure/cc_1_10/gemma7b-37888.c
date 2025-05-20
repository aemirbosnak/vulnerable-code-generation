//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 5
#define NUM_VOTES 100

typedef struct Voter {
    char name[50];
    int vote_count;
    struct Voter* next;
} Voter;

typedef struct Poll {
    char candidate_names[NUM_CANDIDATES][50];
    int votes[NUM_CANDIDATES];
    struct Poll* next;
} Poll;

void vote(Voter* voter, Poll* poll) {
    int candidate_num;

    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &candidate_num);

    if (candidate_num < 1 || candidate_num > NUM_CANDIDATES) {
        printf("Invalid candidate number.\n");
        return;
    }

    poll->votes[candidate_num]++;
    voter->vote_count++;
}

void display_results(Poll* poll) {
    int i;

    printf("Results:\n");
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", poll->candidate_names[i], poll->votes[i]);
    }

    printf("Winner: %s\n", poll->candidate_names[0]);
}

int main() {
    Voter* head = NULL;
    Poll* head_poll = NULL;

    // Create a few voters
    Voter* voter1 = malloc(sizeof(Voter));
    strcpy(voter1->name, "John Doe");
    voter1->vote_count = 0;
    voter1->next = NULL;

    Voter* voter2 = malloc(sizeof(Voter));
    strcpy(voter2->name, "Jane Doe");
    voter2->vote_count = 0;
    voter2->next = NULL;

    // Create a few polls
    Poll* poll1 = malloc(sizeof(Poll));
    strcpy(poll1->candidate_names[0], "Romeo");
    strcpy(poll1->candidate_names[1], "Juliet");
    strcpy(poll1->candidate_names[2], "Benvolio");
    poll1->votes[0] = 50;
    poll1->votes[1] = 25;
    poll1->votes[2] = 10;
    poll1->next = NULL;

    Poll* poll2 = malloc(sizeof(Poll));
    strcpy(poll2->candidate_names[0], "Romeo");
    strcpy(poll2->candidate_names[1], "Juliet");
    strcpy(poll2->candidate_names[2], "Benvolio");
    poll2->votes[0] = 60;
    poll2->votes[1] = 20;
    poll2->votes[2] = 10;
    poll2->next = NULL;

    // Add voters and polls to the head
    head = voter1;
    head->next = voter2;
    head_poll = poll1;
    head_poll->next = poll2;

    // Vote
    vote(voter1, head_poll);
    vote(voter2, head_poll);

    // Display results
    display_results(head_poll);

    return 0;
}