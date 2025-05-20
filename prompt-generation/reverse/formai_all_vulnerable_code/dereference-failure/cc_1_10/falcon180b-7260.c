//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118 // maximum number of elements in the periodic table
#define MAX_QUESTION_LENGTH 80 // maximum length of a question

struct {
    char symbol[3];
    char name;
    int atomic_number;
    int group;
    int period;
} elements[MAX_ELEMENTS];

int main() {
    srand(time(NULL)); // seed the random number generator

    int num_elements = 0;
    FILE *fp = fopen("elements.txt", "r");
    if (fp!= NULL) {
        char line[MAX_QUESTION_LENGTH];
        while (fgets(line, MAX_QUESTION_LENGTH, fp)!= NULL) {
            if (num_elements >= MAX_ELEMENTS) {
                break;
            }
            char *token = strtok(line, " ");
            strcpy(elements[num_elements].symbol, token);
            elements[num_elements].name = toupper(line[strcspn(line, " ")] - 'A' + 1); // convert group letter to number (1-18)
            elements[num_elements].atomic_number = atoi(token);
            elements[num_elements].group = elements[num_elements].name - 1; // group numbers start at 1
            elements[num_elements].period = rand() % 7 + 1; // periods range from 1 to 7
            num_elements++;
        }
        fclose(fp);
    }

    int score = 0;
    int num_questions = rand() % 10 + 1; // ask between 1 and 10 questions

    for (int i = 0; i < num_questions; i++) {
        int index = rand() % num_elements; // choose a random element
        printf("Question %d: ", i + 1);
        if (index < num_elements) {
            printf("What is the symbol for %s? ", elements[index].name);
            char answer[4];
            scanf(" %s", answer);
            if (strcmp(answer, elements[index].symbol) == 0) {
                score++;
            }
        }
    }

    printf("\nYou scored %d out of %d questions.\n", score, num_questions);

    return 0;
}