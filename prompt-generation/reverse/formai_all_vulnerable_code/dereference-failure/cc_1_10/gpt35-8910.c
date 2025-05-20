//FormAI DATASET v1.0 Category: Online Examination System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// structure to store a question
typedef struct Question {
    int id;
    char text[100];
    char options[4][50];
    int answer;
} Question;

// function to display a menu
void display_menu() {
    printf("1. Add question\n");
    printf("2. Start quiz\n");
    printf("3. Exit\n");
}

// function to add question to the questions file
void add_question(FILE* file) {
    Question question;

    printf("Enter question id: ");
    scanf("%d", &question.id);

    printf("Enter question text: ");
    scanf(" %[^\n]", question.text);

    printf("Enter option A: ");
    scanf(" %[^\n]", question.options[0]);

    printf("Enter option B: ");
    scanf(" %[^\n]", question.options[1]);

    printf("Enter option C: ");
    scanf(" %[^\n]", question.options[2]);

    printf("Enter option D: ");
    scanf(" %[^\n]", question.options[3]);

    printf("Enter answer: ");
    scanf("%d", &question.answer);

    fwrite(&question, sizeof(Question), 1, file);
}

// function to start the quiz
void start_quiz(FILE* file) {
    int num_questions = 0;
    double score = 0;
    Question question;

    // get number of questions in the file
    fseek(file, 0, SEEK_END);
    num_questions = ftell(file) / sizeof(Question);
    rewind(file);

    // allocate memory for questions
    Question* questions = (Question*) malloc(num_questions * sizeof(Question));

    // read questions from file into array
    for (int i = 0; i < num_questions; i++) {
        fread(&questions[i], sizeof(Question), 1, file);
    }

    // randomize the order of questions
    srand(time(NULL));
    for (int i = 0; i < num_questions; i++) {
        int j = rand() % num_questions;
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }

    // ask each question and calculate score
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].text);
        printf("A. %s\n", questions[i].options[0]);
        printf("B. %s\n", questions[i].options[1]);
        printf("C. %s\n", questions[i].options[2]);
        printf("D. %s\n", questions[i].options[3]);

        char answer;
        scanf(" %c", &answer);

        if (answer == 'A' || answer == 'a') {
            if (questions[i].answer == 0) {
                score += 1.0;
            }
        }
        else if (answer == 'B' || answer == 'b') {
            if (questions[i].answer == 1) {
                score += 1.0;
            }
        }
        else if (answer == 'C' || answer == 'c') {
            if (questions[i].answer == 2) {
                score += 1.0;
            }
        }
        else if (answer == 'D' || answer == 'd') {
            if (questions[i].answer == 3) {
                score += 1.0;
            }
        }
        else {
            printf("Invalid answer. Skipping question.\n");
        }
    }

    printf("Score: %f\n", score / num_questions);

    free(questions);
}

int main() {
    FILE* file = fopen("questions.bin", "ab+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (true) {
        display_menu();

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_question(file);
                break;
            case 2:
                start_quiz(file);
                break;
            case 3:
                fclose(file);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}