//FormAI DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// shape shifting function prototypes
void set_question(char*, int, char*);
void add_question(char*, int*, char***);
void remove_question(char*, int*, char***);
void display_questions(int, char**);
void shift_questions(int, char**);

int main() {
    int num_questions = 0;
    char **questions = NULL;
    char input[100];

    // prompt user for input
    while (1) {
        printf("\nEnter command (add, remove, shift, display, quit):\n");
        fgets(input, 100, stdin);

        // remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // check user input
        if (strcmp(input, "add") == 0) {
            add_question("Enter new question:", &num_questions, &questions);
        } else if (strcmp(input, "remove") == 0) {
            remove_question("Enter question to remove:", &num_questions, &questions);
        } else if (strcmp(input, "shift") == 0) {
            shift_questions(num_questions, questions);
        } else if (strcmp(input, "display") == 0) {
            display_questions(num_questions, questions);
        } else if (strcmp(input, "quit") == 0) {
            break;
        }
    }

    // free allocated memory
    for (int i = 0; i < num_questions; i++) {
        free(questions[i]);
    }
    free(questions);

    return 0;
}

// function to set question
void set_question(char *prompt, int num, char *question) {
    printf("%s %d: ", prompt, num);
    fgets(question, 100, stdin);
    question[strcspn(question, "\n")] = 0;
}

// function to add question
void add_question(char *prompt, int *num, char ***questions) {
    // allocate memory for new question
    char *new_question = (char*) malloc(sizeof(char) * 100);

    // set new question
    set_question(prompt, *num + 1, new_question);

    // reallocate memory for questions array
    *questions = (char**) realloc(*questions, sizeof(char*) * (*num + 1));

    // add new question to questions array
    (*questions)[*num] = new_question;

    // increment number of questions
    (*num)++;
}

// function to remove question
void remove_question(char *prompt, int *num, char ***questions) {
    // get question to remove
    char remove_question[100];
    set_question(prompt, 0, remove_question);

    // check if question exists in questions array
    int index = -1;
    for (int i = 0; i < *num; i++) {
        if (strcmp(remove_question, (*questions)[i]) == 0) {
            index = i;
            break;
        }
    }

    // remove question from questions array
    if (index != -1) {
        free((*questions)[index]);
        for (int i = index; i < *num-1; i++) {
            (*questions)[i] = (*questions)[i+1];
        }
        (*num)--;
        *questions = (char**) realloc(*questions, sizeof(char*) * (*num));
    } else {
        printf("Question not found.\n");
    }
}

// function to display questions
void display_questions(int num, char **questions) {
    printf("Questions:\n");
    for (int i = 0; i < num; i++) {
        printf("%d. %s\n", i+1, questions[i]);
    }
}

// function to shift questions
void shift_questions(int num, char **questions) {
    // prompt user for number of shifts
    printf("Enter number of shifts: ");
    int shift;
    scanf("%d", &shift);

    // perform shifts
    for (int i = 0; i < shift; i++) {
        char *temp = questions[num-1];
        for (int j = num-1; j > 0; j--) {
            questions[j] = questions[j-1];
        }
        questions[0] = temp;
    }

    // clear input buffer
    while (getchar() != '\n');
}