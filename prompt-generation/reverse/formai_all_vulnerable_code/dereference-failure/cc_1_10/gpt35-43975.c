//FormAI DATASET v1.0 Category: System administration ; Style: Sherlock Holmes
/* The Case of the Missing Memory */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 1024

void investigate(char *memory) {
    // Look for signs of tampering
    int i, sum = 0;
    for (i = 0; memory[i] != '\0'; i++) {
        sum += memory[i];
    }

    if (sum == 0) {
        printf("The memory appears to have been wiped clean!\n");
    } else if (sum > 50000) {
        printf("The memory seems to have been overwritten with junk data!\n");
    } else {
        printf("The memory appears to be intact.\n");
    }
}

void recover(char *memory) {
    // Try to restore missing memory
    int i;
    for (i = 0; i < MAX_MEMORY; i++) {
        if (memory[i] == '\0') {
            memory[i] = '0';
        }
    }
}

int main(int argc, char *argv[]) {
    printf("Welcome, Mr. Holmes.\n");

    char *memory = (char *) malloc(MAX_MEMORY * sizeof(char));
    memset(memory, 0, MAX_MEMORY);

    printf("Please share your findings, Dr. Watson.\n");
    fgets(memory, MAX_MEMORY, stdin);

    investigate(memory);

    printf("Attempting to recover missing memory...\n");
    recover(memory);
    investigate(memory);

    free(memory);
    printf("Case solved.\n");
    return 0;
}