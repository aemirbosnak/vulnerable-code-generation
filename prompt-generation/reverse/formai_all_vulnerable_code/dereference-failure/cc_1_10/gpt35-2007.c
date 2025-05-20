//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {

    //seed the random number generator
    srand(time(NULL));

    //store the answers to each question
    char answers[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    //store the user's answers
    char user_answers[10];

    //initialize the score to zero
    int score = 0;

    //welcome the user and provide instructions
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be asked 10 questions about the elements of the periodic table.\n");
    printf("For each question, choose the letter corresponding to the correct answer.\n");

    //loop through each question
    for (int i = 0; i < 10; i++) {

        //generate a random number between 0 and 118 (total number of elements)
        int element_number = rand() % 118;

        //open the periodic table file
        FILE *f = fopen("periodic_table.txt", "r");

        //if the file is not found, exit the program
        if (f == NULL) {
            printf("Error: periodic_table.txt not found.\n");
            return 1;
        }

        //loop through each line of the file until the element is found
        char line[100];
        while (fgets(line, sizeof(line), f)) {

            //split the line into fields using the '|' character as a delimiter
            char *symbol = strtok(line, "|");
            char *name = strtok(NULL, "|");
            char *number = strtok(NULL, "|");
            char *weight = strtok(NULL, "|");

            //if the element number matches the current line, ask the question and record the answer
            if (atoi(number) == element_number) {
                printf("\nQuestion %d: What is the symbol for %s?\n", i+1, name);
                user_answers[i] = tolower(getchar());

                //clear any extra characters from the input stream
                char c;
                while ((c = getchar()) != '\n' && c != EOF);

                //if the user's answer is correct, increment the score
                if (user_answers[i] == answers[i]) {
                    printf("Correct!\n");
                    score++;
                } else {
                    printf("Incorrect. The correct answer is %c.\n", answers[i]);
                }
                break;
            }
        }

        //close the file
        fclose(f);
    }

    //display the user's score
    printf("\nYou scored %d out of 10.\n", score);

    //display the correct answers
    printf("The correct answers were:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %c\n", i+1, answers[i]);
    }

    return 0;
}