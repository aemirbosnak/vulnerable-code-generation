//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our beautiful rose, the candidate
typedef struct rose {
    char* name;
    int votes;
} rose;

// A bouquet of love, our collection of candidates
rose *bouquet;
int numRoses;

// Our beloved romance, the voting process
int vote(char *name) {
    for (int i = 0; i < numRoses; i++) {
        if (strcmp(name, bouquet[i].name) == 0) {
            bouquet[i].votes++;
            return 1;
        }
    }
    return 0;
}

// The grand declaration, announcing our winner
void declare() {
    int maxVotes = 0;
    rose *winner;
    for (int i = 0; i < numRoses; i++) {
        if (bouquet[i].votes > maxVotes) {
            maxVotes = bouquet[i].votes;
            winner = &bouquet[i];
        }
    }
    printf("Our hearts have spoken! The winner is %s, with %d votes.\n", winner->name, winner->votes);
}

// A sonnet of initialization, setting up our candidates
void initialize() {
    numRoses = 3;
    bouquet = malloc(sizeof(rose) * numRoses);
    bouquet[0].name = "Rose";
    bouquet[1].name = "Lily";
    bouquet[2].name = "Tulip";
    for (int i = 0; i < numRoses; i++) {
        bouquet[i].votes = 0;
    }
}

// A waltz of main, where the magic happens
int main() {
    initialize();
    char input[20];
    int validVote;
    printf("Oh, dear voter, cast your vote for your heart's desire:\n");
    while (1) {
        printf("Enter the name of your beloved rose: ");
        scanf("%s", input);
        validVote = vote(input);
        if (validVote) {
            printf("Your vote has been recorded, my darling.\n");
        } else {
            printf("Alas, your rose is not among our candidates.\n");
        }
        printf("Would you like to cast another vote? (y/n): ");
        scanf(" %c", &input[0]);
        if (input[0] == 'n') {
            break;
        }
    }
    declare();
    return 0;
}