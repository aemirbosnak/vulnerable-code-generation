//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct candidate {
    char name[20];
    int votes;
} Candidate;

typedef struct party {
    char name[20];
    int members;
    Candidate* candidates;
} Party;

void printCandidates(Party* party) {
    for (int i = 0; i < party->members; i++) {
        printf("%s has %d votes.\n", party->candidates[i].name, party->candidates[i].votes);
    }
}

int main() {
    srand(time(NULL));

    Party* party1 = (Party*) malloc(sizeof(Party));
    Party* party2 = (Party*) malloc(sizeof(Party));

    strcpy(party1->name, "Democrats");
    strcpy(party2->name, "Republicans");
    party1->members = 3;
    party2->members = 3;

    Candidate* candidate1 = (Candidate*) malloc(sizeof(Candidate));
    Candidate* candidate2 = (Candidate*) malloc(sizeof(Candidate));
    Candidate* candidate3 = (Candidate*) malloc(sizeof(Candidate));

    strcpy(candidate1->name, "Joe Biden");
    strcpy(candidate2->name, "Donald Trump");
    strcpy(candidate3->name, "Kamala Harris");

    candidate1->votes = 100;
    candidate2->votes = 150;
    candidate3->votes = 120;

    party1->candidates = (Candidate*) malloc(sizeof(Candidate));
    party2->candidates = (Candidate*) malloc(sizeof(Candidate));

    strcpy(party1->candidates[0].name, candidate1->name);
    strcpy(party1->candidates[1].name, candidate2->name);
    strcpy(party1->candidates[2].name, candidate3->name);

    strcpy(party2->candidates[0].name, candidate2->name);
    strcpy(party2->candidates[1].name, candidate1->name);
    strcpy(party2->candidates[2].name, candidate3->name);

    printf("Here are the candidates:\n");
    printCandidates(party1);
    printCandidates(party2);

    int votes[2][2];

    printf("Vote for a party: 1 - Democrats, 2 - Republicans\n");
    scanf("%d", &votes[0][0]);

    printf("Vote for a candidate: 1 - Joe Biden, 2 - Donald Trump, 3 - Kamala Harris\n");
    scanf("%d", &votes[1][0]);

    if (votes[0][0] == 1) {
        votes[0][1] = party1->candidates[votes[1][0] - 1].votes;
        votes[0][1] += 10;
    } else if (votes[0][0] == 2) {
        votes[0][1] = party2->candidates[votes[1][0] - 1].votes;
        votes[0][1] += 10;
    }

    printf("Here are the updated candidates:\n");
    printCandidates(party1);
    printCandidates(party2);

    free(party1->candidates);
    free(party2->candidates);
    free(party1);
    free(party2);

    return 0;
}