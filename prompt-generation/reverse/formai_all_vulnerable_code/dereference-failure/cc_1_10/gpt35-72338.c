//FormAI DATASET v1.0 Category: Online Examination System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

#define MAX_QUESTIONS 100

struct question {
    char description[200];
    char options[4][100];
    int answer;
};

struct student {
    char name[50];
    int roll_number;
    int score;
};

int current_question = 0;
int num_questions;
struct question questions[MAX_QUESTIONS];
struct student current_student;

void load_questions() {
    FILE *fp;
    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        perror("Error reading questions.txt");
        exit(EXIT_FAILURE);
    }
    int len;
    char *line = NULL;
    size_t n = 0;
    int opt_num = 0;
    while ((getline(&line, &n, fp)) != -1) {
        if (strlen(line) > 1) {
            if (line[strlen(line) - 1] == '\n') {
                line[strlen(line) - 1] = '\0';
            }
            if (line[0] == 'Q') {
                len = strlen(line);
                strncpy(questions[num_questions].description, line + 2, len - 2);
                opt_num = 0;
            } else if (line[0] == 'A') {
                questions[num_questions].answer = atoi(line + 2);
            } else {
                len = strlen(line);
                strncpy(questions[num_questions].options[opt_num], line, len);
                opt_num++;
            }
        } else {
            num_questions++;
        }
    }
    fclose(fp);
    if (line) {
        free(line);
    }
}

void print_options() {
    printf("Choose an option:\n");
    printf("1. Start Exam\n");
    printf("2. View Score\n");
    printf("3. Exit\n");
}

void start_exam() {
    printf("\nWelcome %s! You will be presented with a series of multiple choice questions.\n", current_student.name);
    printf("Each question has 4 options, please choose the number of the option you think is the correct answer.\n");
    printf("Your score will be calculated once you have completed the exam.\n");
    printf("Good Luck!\n");

    int choice;
    char entered[5];
    clock_t start_time = clock();
    while (current_question < num_questions) {
        printf("\nQuestion %d:\n", current_question + 1);
        printf("%s\n", questions[current_question].description);
        printf("1. %s\n", questions[current_question].options[0]);
        printf("2. %s\n", questions[current_question].options[1]);
        printf("3. %s\n", questions[current_question].options[2]);
        printf("4. %s\n", questions[current_question].options[3]);
        printf("Enter your answer: ");
        fflush(stdout);
        fgets(entered, sizeof(entered), stdin);
        choice = atoi(entered);
        if (choice == questions[current_question].answer) {
            printf("Correct!\n");
            current_student.score += 1;
        } else {
            printf("Incorrect\n");
        }
        current_question++;
    }
    clock_t end_time = clock();

    double time_spent = (end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nCongratulations! You have completed the exam.\n");
    printf("Your score is: %d/%d\n", current_student.score, num_questions);
    printf("Time taken: %f seconds\n", time_spent);
}

void view_score() {
    printf("\nStudent Name: %s\n", current_student.name);
    printf("Roll Number: %d\n", current_student.roll_number);
    printf("Score: %d/%d\n", current_student.score, num_questions);
}

int main() {
    load_questions();
    printf("Welcome to the online examination system.\n");
    while (1) {
        printf("\n");
        print_options();
        int choice = 0;
        char entered[5];
        fflush(stdout);
        fgets(entered, sizeof(entered), stdin);
        choice = atoi(entered);
        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%[^\n]%*c", current_student.name);
                printf("Enter your roll number: ");
                scanf("%d", &current_student.roll_number);
                current_student.score = 0;
                current_question = 0;
                start_exam();
                break;
            case 2:
                view_score();
                break;
            case 3:
                printf("\nThank you for using the online examination system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}