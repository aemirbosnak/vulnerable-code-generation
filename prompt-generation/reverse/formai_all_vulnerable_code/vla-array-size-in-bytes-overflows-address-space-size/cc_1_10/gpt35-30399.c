//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* surreal voter struct */
typedef struct {
    char name[50];
    int age;
    char favorite_color[20];
    int num_fingers;
} Voter;

/* surreal candidate struct */
typedef struct {
    char name[50];
    int num_tentacles;
    char favorite_noise[20];
    char political_party[50];
} Candidate;

/* surreal function that prompts user to register */
Voter register_voter() {
    Voter voter;
    printf("Please enter your name: ");
    scanf("%s", voter.name);
    printf("Please enter your age: ");
    scanf("%d", &voter.age);
    printf("Please enter your favorite color: ");
    scanf("%s", voter.favorite_color);
    printf("Please enter the number of fingers on your left hand: ");
    scanf("%d", &voter.num_fingers);
    return voter;
}

/* surreal function that prompts candidate to register */
Candidate register_candidate() {
    Candidate candidate;
    printf("Please enter your name: ");
    scanf("%s", candidate.name);
    printf("Please enter the number of tentacles you have: ");
    scanf("%d", &candidate.num_tentacles);
    printf("Please enter your favorite noise: ");
    scanf("%s", candidate.favorite_noise);
    printf("Please enter your political party: ");
    scanf("%s", candidate.political_party);
    return candidate;
}

/* surreal function that displays the voting options */
void display_voting_options(Candidate candidates[], int num_candidates) {
    printf("VOTING OPTIONS\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%s, %d tentacles)\n", i+1, candidates[i].name, candidates[i].political_party, candidates[i].num_tentacles);
    }
}

/* surreal main function */
int main() {
    int num_voters, num_candidates;
    printf("Welcome to the surreal electronic voting system!\n");
    printf("How many voters will be participating in this election? ");
    scanf("%d", &num_voters);
    printf("How many candidates are running for office? ");
    scanf("%d", &num_candidates);
    Voter voters[num_voters];
    Candidate candidates[num_candidates];
    
    /* surreal loop to register voters */
    for (int i = 0; i < num_voters; i++) {
        printf("\nVoter #%d\n", i+1);
        voters[i] = register_voter();
    }
    
    /* surreal loop to register candidates */
    for (int i = 0; i < num_candidates; i++) {
        printf("\nCandidate #%d\n", i+1);
        candidates[i] = register_candidate();
    }
    
    /* surreal loop to display voting options */
    display_voting_options(candidates, num_candidates);
    
    /* surreal loop to cast votes */
    for (int i = 0; i < num_voters; i++) {
        int vote;
        printf("\n%s, please enter your vote (1-%d): ", voters[i].name, num_candidates);
        scanf("%d", &vote);
        printf("Thank you, %s, for voting for the candidate with %d tentacles.\n", voters[i].name, candidates[vote-1].num_tentacles);
    }
    
    printf("\nThank you for using the surreal electronic voting system!");
    return 0;
}