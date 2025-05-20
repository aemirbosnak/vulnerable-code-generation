//FormAI DATASET v1.0 Category: Online Examination System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a struct to store data for each question in our exam
struct Question {
    char question[100];
    char options[4][100];
    int correct_option;
};

// Define a struct to represent our exam
struct Exam {
    char title[100];
    int num_questions;
    struct Question* questions;
};

// Function to create a new exam
struct Exam* create_exam() {
    printf("\nEnter exam title: ");
    char title[100];
    gets(title);

    printf("\nEnter number of questions: ");
    int num_questions;
    scanf("%d", &num_questions);
    getchar(); // consume the newline character left by scanf

    struct Exam* exam = (struct Exam*) malloc(sizeof(struct Exam));
    strcpy(exam->title, title);
    exam->num_questions = num_questions;
    exam->questions = (struct Question*) malloc(sizeof(struct Question) * num_questions);

    int i, j, option_num;
    for (i = 0; i < num_questions; i++) {
        printf("\nEnter question %d: ", i + 1);
        gets(exam->questions[i].question);

        for (j = 0; j < 4; j++) {
            printf("\nEnter option %c for question %d: ", 'A' + j, i + 1);
            gets(exam->questions[i].options[j]);
        }

        printf("\nEnter correct option (1-4) for question %d: ", i + 1);
        scanf("%d", &option_num);
        getchar(); // consume the newline character left by scanf
        exam->questions[i].correct_option = option_num - 1;
    }

    printf("\nExam created successfully!\n");
    return exam;
}

// Function to take a given exam
void take_exam(struct Exam* exam) {
    printf("\nWelcome to the %s exam!\n", exam->title);
    printf("\nYou will now proceed to answer %d questions.\n", exam->num_questions);

    int i, j, user_choice, score = 0;
    for (i = 0; i < exam->num_questions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, exam->questions[i].question);

        for (j = 0; j < 4; j++) {
            printf("%c. %s\n", 'A' + j, exam->questions[i].options[j]);
        }

        printf("Enter your choice (1-4): ");
        scanf("%d", &user_choice);
        getchar(); // consume the newline character left by scanf

        if (user_choice - 1 == exam->questions[i].correct_option) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("\nYou have completed the exam.\n");
    printf("Your score is %d/%d.\n", score, exam->num_questions);
}

int main() {
    printf("Welcome to the Online Examination System!\n");

    int choice;
    struct Exam* exam = NULL;

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Create a new exam\n");
        printf("2. Take an existing exam\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // consume the newline character left by scanf

        switch (choice) {
            case 1:
                exam = create_exam();
                break;
            case 2:
                if (exam == NULL) {
                    printf("\nNo exam exists. Please create one first.\n");
                    break;
                }
                take_exam(exam);
                break;
            case 3:
                printf("\nThank you for using the Online Examination System. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}