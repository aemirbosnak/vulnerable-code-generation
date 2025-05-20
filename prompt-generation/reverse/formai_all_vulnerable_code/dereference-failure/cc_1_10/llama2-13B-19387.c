//LLAMA2-13B DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1024
#define THOUGHT_LEN 256

typedef struct {
    char *thought;
    int len;
} thought_t;

void introspect(void) {
    thought_t current_thought;
    char *prev_thought = NULL;
    int i = 0;

    printf("Welcome to my introspective world...\n");

    current_thought.thought = malloc(THOUGHT_LEN * sizeof(char));
    current_thought.len = THOUGHT_LEN;

    while (1) {
        printf("Current thought: %s\n", current_thought.thought);

        // Generate a new thought
        srand(time(NULL));
        for (int j = 0; j < THOUGHT_LEN; j++) {
            current_thought.thought[j] = 'a' + (rand() % 26);
        }

        // Check for similarity with previous thought
        int similarity = 0;
        for (int j = 0; j < THOUGHT_LEN; j++) {
            if (current_thought.thought[j] == prev_thought[j]) {
                similarity++;
            }
        }

        // Print the similarity
        printf("Similarity with previous thought: %d%%\n", ( similarity * 100 ) / THOUGHT_LEN );

        // Update the previous thought
        prev_thought = current_thought.thought;
        current_thought.thought = malloc(THOUGHT_LEN * sizeof(char));
        current_thought.len = THOUGHT_LEN;

        // Check for exit condition
        if (similarity >= 80) {
            break;
        }
    }

    free(current_thought.thought);
    free(prev_thought);

    printf("Thank you for joining me in my introspective world...\n");
}

int main(void) {
    introspect();
    return 0;
}