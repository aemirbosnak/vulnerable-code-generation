//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

//Define a structure to hold data for each intrusion
typedef struct {
    int id;
    char *name;
} intruder;

//Define the maximum number of intruders that can be held in the system
#define MAX_INTRUDERS 10

//Create a global array to hold intruders
intruder intruders[MAX_INTRUDERS];

//Function to add a new intruder to the system
void add_intruder(int id, char *name) {
    if (id < 1 || id > MAX_INTRUDERS) {
        printf("Invalid intruder id: %d\n", id);
        return;
    }
    
    if (strlen(name) > 0) {
        intruders[id-1].id = id;
        intruders[id-1].name = malloc(strlen(name) + 1);
        strcpy(intruders[id-1].name, name);
        printf("Added intruder %s with id %d\n", name, id);
    }
    else {
        printf("Invalid intruder name: %s\n", name);
    }
}

//Function to remove an intruder from the system
void remove_intruder(int id) {
    if (id < 1 || id > MAX_INTRUDERS) {
        printf("Invalid intruder id: %d\n", id);
        return;
    }
    
    free(intruders[id-1].name);
    intruders[id-1].name = NULL;
    printf("Removed intruder %d\n", id);
}

//Function to display all intruders in the system
void display_intruders() {
    for (int i = 0; i < MAX_INTRUDERS; i++) {
        if (intruders[i].name!= NULL) {
            printf("Intruder %d: %s\n", i+1, intruders[i].name);
        }
    }
}

//Function to handle SIGINT signal
void sigint_handler(int signo) {
    printf("Received SIGINT signal, exiting...\n");
    exit(1);
}

//Main function
int main() {
    signal(SIGINT, sigint_handler);
    
    add_intruder(1, "Bob");
    add_intruder(2, "Alice");
    display_intruders();
    remove_intruder(2);
    display_intruders();
    
    return 0;
}