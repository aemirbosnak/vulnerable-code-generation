//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 10
#define TRUE 1
#define FALSE 0

typedef struct {
    int id;
    char name[50];
} candidate_t;

typedef struct {
    int id;
    char name[50];
} voter_t;

candidate_t candidates[MAX_CANDIDATES];
voter_t voters[MAX_VOTERS];

int num_candidates = 0;
int num_voters = 0;

void *voter_thread(void *arg) {
    int voter_id = *(int *) arg;
    printf("Voter %d is voting...\n", voter_id);
    sleep(1);
    printf("Voter %d has voted!\n", voter_id);
    pthread_exit(NULL);
}

int main() {
    int i, j, choice;

    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name: ", i+1);
        scanf("%s", candidates[i].name);
    }

    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    for (i = 0; i < num_voters; i++) {
        printf("Enter voter %d's name: ", i+1);
        scanf("%s", voters[i].name);
    }

    pthread_t voters_threads[num_voters];

    for (i = 0; i < num_voters; i++) {
        pthread_create(&voters_threads[i], NULL, voter_thread, (void *) &i);
    }

    for (i = 0; i < num_voters; i++) {
        pthread_join(voters_threads[i], NULL);
    }

    printf("Election completed!\n");

    return 0;
}