//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define NUM_QUESTIONS 10

//Define a struct to hold information about each element
typedef struct Element {
    char *symbol;
    char *name;
    int atomic_number;
    char *category;
} Element;

//Define a struct to hold information about each question
typedef struct Question {
    Element element;
    char *hint;
} Question;

//Declare functions
void populate_elements(Element *elements);
void populate_questions(Question *questions, Element *elements);
void play_quiz(Question *questions);

int main() {
    //Seed random number generator
    srand(time(NULL));

    //Allocate memory for elements array and populate it with information from file
    Element *elements = malloc(118 * sizeof(Element));
    populate_elements(elements);

    //Allocate memory for questions array and populate it with elements and hints
    Question *questions = malloc(NUM_QUESTIONS * sizeof(Question));
    populate_questions(questions, elements);

    //Start quiz
    play_quiz(questions);

    //Free memory
    free(elements);
    free(questions);

    return 0;
}

//Populate the elements array with information from a file
void populate_elements(Element *elements) {
    FILE *file = fopen("elements.txt", "r");
    if (file) {
        int i = 0;
        char line[100];
        while (fgets(line, sizeof(line), file)) {
            //Split each line by commas and populate struct with information
            char *symbol = strtok(line, ",");
            char *name = strtok(NULL, ",");
            int atomic_number = atoi(strtok(NULL, ","));
            char *category = strtok(NULL, ",");

            elements[i].symbol = symbol;
            elements[i].name = name;
            elements[i].atomic_number = atomic_number;
            elements[i].category = category;

            i++;
        }
        fclose(file);
    } else {
        printf("Error: could not open file\n");
        exit(1);
    }
}

//Populates the questions array with elements and hints
void populate_questions(Question *questions, Element *elements) {
    char *hints[NUM_QUESTIONS] = {
        "This element is a noble gas",
        "This element is a metal found in group 1",
        "This element is a halogen",
        "This element is a metal found in group 2",
        "This element is a non-metal found in group 16",
        "This element is a transition metal",
        "This element is a rare earth metal",
        "This element is used in nuclear energy",
        "This element is used in batteries",
        "This element is a gas at room temperature"
    };

    //Randomly select NUM_QUESTIONS elements to use for questions
    int used_indices[NUM_QUESTIONS];
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int random_num;
        do {
            random_num = rand() % 118;
        } while (used_indices[random_num]);
        used_indices[random_num] = 1;

        Element element = elements[random_num];
        char *hint = hints[i];

        Question question;
        question.element = element;
        question.hint = hint;

        questions[i] = question;
    }
}

//Runs the quiz with the provided questions
void play_quiz(Question *questions) {
    int score = 0;

    printf("Welcome to the Paranoid Periodic Table Quiz!\n");
    printf("Can you answer these %d questions about elements in the periodic table?\n", NUM_QUESTIONS);

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        Question question = questions[i];

        printf("\nQuestion %d: What element has the symbol %s? Hint: %s\n", i+1, question.element.symbol, question.hint);

        char user_answer[100];
        fgets(user_answer, sizeof(user_answer), stdin);
        user_answer[strlen(user_answer)-1] = '\0';

        if (strcmp(user_answer, question.element.name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %s\n", question.element.name);
        }
    }

    printf("\nYou scored %d out of %d!\n", score, NUM_QUESTIONS);
    if (score == NUM_QUESTIONS) {
        printf("Congratulations, you are a periodic table genius!\n");
    } else {
        printf("Better luck next time!\n");
    }
}