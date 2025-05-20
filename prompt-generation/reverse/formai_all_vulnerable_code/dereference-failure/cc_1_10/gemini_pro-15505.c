//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Initialize the random seed
void init_rand() {
    srand(time(NULL));
}

// Generate a random number between 0 and max-1
int rand_int(int max) {
    return rand() % max;
}

// Generate a random string of length len
char *rand_string(int len) {
    char *str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        str[i] = 'a' + rand_int(26);
    }
    str[len] = '\0';
    return str;
}

// Generate a random conspiracy theory
char *gen_conspiracy() {
    // Initialize the random seed
    init_rand();

    // Generate the subject of the conspiracy
    char *subject = rand_string(rand_int(10) + 5);

    // Generate the perpetrators of the conspiracy
    char *perpetrators = rand_string(rand_int(10) + 5);

    // Generate the goal of the conspiracy
    char *goal = rand_string(rand_int(10) + 5);

    // Generate the evidence for the conspiracy
    char *evidence = rand_string(rand_int(20) + 10);

    // Combine all the parts of the conspiracy theory
    char *conspiracy = malloc(strlen(subject) + strlen(perpetrators) + strlen(goal) +
                                strlen(evidence) + 100);
    sprintf(conspiracy, "%s is being controlled by %s in order to achieve %s. The evidence for this is %s.",
            subject, perpetrators, goal, evidence);

    return conspiracy;
}

// Print a random conspiracy theory
void print_conspiracy() {
    char *conspiracy = gen_conspiracy();
    printf("%s\n", conspiracy);
}

int main() {
    // Generate and print 10 random conspiracy theories
    for (int i = 0; i < 10; i++) {
        print_conspiracy();
    }

    return 0;
}