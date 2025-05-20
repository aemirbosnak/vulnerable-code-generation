//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate {
    char name[50];
    int votes;
};

void vote(struct candidate* c_arr, int num_candidates) {
    char name[50];
    int flag = 0;
    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", name);
    for(int i=0; i<num_candidates; i++) {
        if(strcmp(c_arr[i].name, name) == 0) {
            c_arr[i].votes++;
            printf("Thank you for voting for %s\n", name);
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        printf("Candidate not found\n");
    }
}

void display_result(struct candidate* c_arr, int num_candidates) {
    struct candidate temp;
    for(int i=0; i<num_candidates; i++) {
        for(int j=i+1; j<num_candidates; j++) {
            if(c_arr[j].votes > c_arr[i].votes) {
                temp = c_arr[i];
                c_arr[i] = c_arr[j];
                c_arr[j] = temp;
            }
        }
    }
    printf("=====================\n");
    printf("Election Result\n");
    printf("=====================\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%s: %d votes\n", c_arr[i].name, c_arr[i].votes);
    }
}

int main() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    struct candidate* c_arr = (struct candidate*)malloc(num_candidates * sizeof(struct candidate));
    for(int i=0; i<num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", c_arr[i].name);
        c_arr[i].votes = 0;
    }
    int choice = -1;
    while(choice != 0) {
        printf("=====================\n");
        printf("Electronic Voting System\n");
        printf("=====================\n");
        printf("1. Vote\n");
        printf("2. Display Result\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                vote(c_arr, num_candidates);
                break;
            case 2:
                display_result(c_arr, num_candidates);
                break;
            case 0:
                printf("Thank you for using Electronic Voting System\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    free(c_arr);
    return 0;
}