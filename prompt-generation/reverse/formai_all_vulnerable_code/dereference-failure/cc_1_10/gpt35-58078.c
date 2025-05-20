//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to hold the candidate information
typedef struct {
    char name[50];
    int votes;
} Candidate;

//function to read the candidates from file
void read_candidates(Candidate *cands, int n) {
    FILE *fp;
    fp = fopen("candidates.txt", "r");
    if(fp == NULL) {
        printf("Error reading file");
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        fscanf(fp, "%s", cands[i].name);
        cands[i].votes = 0;
    }
    fclose(fp);
}

//function to print the list of candidates
void print_candidates(Candidate *cands, int n) {
    printf("List of candidates:\n");
    for(int i = 0; i < n; i++) {
        printf("%d. %s\n", i+1, cands[i].name);
    }
}

//function to cast a vote
void cast_vote(Candidate *cands, int n) {
    int choice;
    printf("Enter the number of your candidate: ");
    scanf("%d", &choice);
    if(choice <= 0 || choice > n) {
        printf("Invalid choice");
        return;
    }
    cands[choice-1].votes++;
    printf("Vote cast for %s\n", cands[choice-1].name);
}

//function to print the results
void print_results(Candidate *cands, int n) {
    printf("Results:\n");
    for(int i = 0; i < n; i++) {
        printf("%s: %d votes\n", cands[i].name, cands[i].votes);
    }
}

int main() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    Candidate *candidates = (Candidate*) malloc(num_candidates * sizeof(Candidate));
    read_candidates(candidates, num_candidates);
    printf("Welcome to the electronic voting system!\n");
    while(1) {
        printf("Menu:\n1. Print list of candidates\n2. Cast a vote\n3. Print results\n4. Exit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                print_candidates(candidates, num_candidates);
                break;
            case 2:
                cast_vote(candidates, num_candidates);
                break;
            case 3:
                print_results(candidates, num_candidates);
                break;
            case 4:
                printf("Thank you for using the electronic voting system!\n");
                free(candidates);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}