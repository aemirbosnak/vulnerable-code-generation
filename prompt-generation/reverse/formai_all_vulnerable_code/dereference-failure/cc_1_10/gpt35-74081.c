//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char name[20];
    int age;
    float account_balance;
} Citizen;

void hackCitizenAccounts(Citizen *citizens, int numCitizens) {
    // Code for hacking into the citizen accounts and adding some credits to them
    // Be careful when running this code!
    srand(time(NULL));
    for(int i=0; i<numCitizens; i++) {
        int randInt = rand() % 1000;
        citizens[i].account_balance += randInt;
        printf("Citizen %d (%s) received %d credits.\n", citizens[i].id, citizens[i].name, randInt);
    }
}

int main() {
    // Generate some random citizens
    int numCitizens = 5;
    Citizen *citizens = (Citizen*) malloc(numCitizens * sizeof(Citizen));
    for(int i=0; i<numCitizens; i++) {
        citizens[i].id = i+1;
        sprintf(citizens[i].name, "Citizen%d", i+1);
        citizens[i].age = i+20;
        citizens[i].account_balance = 1000.0f;
    }

    // Display the pre-hack information
    printf("Before hack:\n");
    for(int i=0; i<numCitizens; i++) {
        printf("Citizen %d - Name: %s, Age: %d, Account Balance: %.2f\n", citizens[i].id, citizens[i].name, citizens[i].age, citizens[i].account_balance);
    }

    // Hack the citizen accounts
    hackCitizenAccounts(citizens, numCitizens);

    // Display the post-hack information
    printf("After hack:\n");
    for(int i=0; i<numCitizens; i++) {
        printf("Citizen %d - Name: %s, Age: %d, Account Balance: %.2f\n", citizens[i].id, citizens[i].name, citizens[i].age, citizens[i].account_balance);
    }

    // Deallocate the memory
    free(citizens);

    return 0;
}