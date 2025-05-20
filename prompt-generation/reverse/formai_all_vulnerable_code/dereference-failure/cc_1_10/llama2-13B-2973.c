//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_RIDDLES 10
#define MAX_GUESS_LENGTH 50

struct riddle {
    char *question;
    char *answer;
};

struct treasure {
    char *name;
    char *location;
} treasure;

void generate_riddles(struct riddle riddles[], int num_riddles) {
    int i;
    for (i = 0; i < num_riddles; i++) {
        char *question = malloc(100);
        char *answer = malloc(100);
        sprintf(question, "What has keys but can't open locks?");
        sprintf(answer, "A keyboard.");
        riddles[i].question = question;
        riddles[i].answer = answer;
    }
}

int check_guess(char *guess, struct riddle riddle) {
    if (strcmp(guess, riddle.answer) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));

    // Generate riddles
    struct riddle riddles[MAX_RIDDLES];
    generate_riddles(riddles, MAX_RIDDLES);

    // Set up treasure
    treasure.name = "The Golden Chalice";
    treasure.location = "In a hidden chamber deep within a ancient castle.";

    // Start game
    int current_riddle = 0;
    char guess[MAX_GUESS_LENGTH];

    while (1) {
        printf("Riddle %d: %s\n", current_riddle + 1, riddles[current_riddle].question);
        fgets(guess, MAX_GUESS_LENGTH, stdin);

        if (check_guess(guess, riddles[current_riddle])) {
            current_riddle++;
            if (current_riddle == MAX_RIDDLES) {
                printf("Congratulations, you found the treasure! It is located at %s.\n", treasure.location);
                break;
            }
        } else {
            printf("Incorrect guess. Try again.\n");
        }
    }

    return 0;
}