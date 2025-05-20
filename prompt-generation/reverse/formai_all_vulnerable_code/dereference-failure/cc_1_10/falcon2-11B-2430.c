//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

char* elements[100];
int num_elements = 100;

int main() {
    srand(time(NULL));

    // Create a random periodic table
    for (int i = 0; i < num_elements; i++) {
        elements[i] = (char*)malloc(3 * sizeof(char));
        if (elements[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        for (int j = 0; j < 3; j++) {
            elements[i][j] = 'X' + rand() % 7;
        }
    }

    // Display the periodic table
    printf("\nPeriodic Table\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%3s %3s %3s\n", elements[i], elements[i] + 1, elements[i] + 2);
    }

    // Quiz the user
    int correct = 0;
    for (int i = 0; i < num_elements; i++) {
        int num_correct = 0;

        // Prompt user for answer
        char answer[3];
        printf("What element is in the %d row, %d column?\n", i + 1, (rand() % 3) + 1);
        fgets(answer, 3, stdin);

        // Check answer
        char* correct_answer = elements[i] + (rand() % 3);
        if (strcmp(answer, correct_answer) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", correct_answer);
        }

        if (num_correct == 0) {
            printf("Sorry, you got no answers correct. Better luck next time!\n");
        } else {
            printf("You got %d answers correct.\n", num_correct);
        }

        if (num_correct == 0) {
            correct = 0;
        } else {
            correct = 1;
        }
    }

    if (correct) {
        printf("Congratulations! You passed the periodic table quiz.\n");
    } else {
        printf("Sorry, you failed the periodic table quiz.\n");
    }

    return 0;
}