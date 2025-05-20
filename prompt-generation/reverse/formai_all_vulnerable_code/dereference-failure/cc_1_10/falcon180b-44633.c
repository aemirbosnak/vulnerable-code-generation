//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_elements;
    char **elements;
    int i, j;
    int score = 0;
    int num_questions = 10;
    int correct_answers = 0;
    int user_answers[num_questions];
    int correct_answers_array[num_questions];

    srand(time(NULL));

    // Initialize array of elements
    num_elements = 118;
    elements = (char **)malloc(num_elements * sizeof(char *));
    for (i = 0; i < num_elements; i++) {
        elements[i] = (char *)malloc(50 * sizeof(char));
        sprintf(elements[i], "Element %d", i + 1);
    }

    // Shuffle array of elements
    for (i = 0; i < num_elements; i++) {
        j = rand() % num_elements;
        char *temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }

    // Ask questions
    for (i = 0; i < num_questions; i++) {
        int index = rand() % num_elements;
        printf("Question %d: What is the symbol for element %s? ", i + 1, elements[index]);
        scanf("%d", &user_answers[i]);
        correct_answers_array[i] = index + 1;
    }

    // Check answers
    for (i = 0; i < num_questions; i++) {
        if (user_answers[i] == correct_answers_array[i]) {
            correct_answers++;
        }
    }

    // Print results
    printf("\nYou got %d out of %d questions correct.\n", correct_answers, num_questions);

    return 0;
}