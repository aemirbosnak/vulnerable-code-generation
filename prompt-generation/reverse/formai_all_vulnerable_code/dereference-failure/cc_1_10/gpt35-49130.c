//FormAI DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 4
#define MAX_ANSWERS 100

typedef struct {
    char question[200];
    char choices[MAX_CHOICES][50];
    int answer;
} Question;

int main() {
    srand(time(NULL));
    int num_questions, num_choices, num_answers;
    char student_name[50];
    printf("Welcome to the Online Exam Portal!\n");
    printf("Please enter your name: ");
    scanf("%s", student_name);
    printf("Hello %s, let's get started!\n", student_name);

    // read number of questions from file and allocate memory for questions array
    FILE *fp = fopen("questions.txt", "r");
    fscanf(fp, "%d", &num_questions);
    Question *questions = (Question*) malloc(num_questions * sizeof(Question));
    // read questions, choices, and answers from file
    for (int i = 0; i < num_questions; i++) {
        fscanf(fp, " %[^'\n']%*c", questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            fscanf(fp, " %[^,]%*c", questions[i].choices[j]);
            if (j == MAX_CHOICES - 1) fscanf(fp, "\n");
        }
        fscanf(fp, "%d", &questions[i].answer);
    }
    
    // start the exam
    printf("The exam will start now!\n");
    printf("You will have %d minutes to complete %d questions.\n", num_questions * 2, num_questions);
    int score = 0;
    time_t start_time = time(NULL);
    for (int i = 0; i < num_questions; i++) {
        printf("\n%d. %s\n", i+1, questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%c) %s\n", 'A'+j, questions[i].choices[j]);
        }
        printf("Your answer (A-D): ");
        char student_answer;
        scanf(" %c", &student_answer);
        if (student_answer >= 'A' && student_answer <= 'D') {
            if (student_answer - 'A' == questions[i].answer-1) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %c.\n", questions[i].answer+'A'-1);
            }
        } else {
            printf("Invalid input. Please enter only A, B, C, or D.\n");
        }
    }

    // calculate final score and duration
    time_t end_time = time(NULL);
    int duration = (int) difftime(end_time, start_time);
    int minutes = duration / 60;
    int seconds = duration % 60;
    float percentage = (float) score / num_questions * 100;
    printf("\nCongratulations %s, you have completed the exam!\n", student_name);
    printf("Your score is %.2f%% (%d/%d).\n", percentage, score, num_questions);
    printf("You took %d minutes and %d seconds.\n", minutes, seconds);

    // save the results to file
    fp = fopen("results.txt", "a");
    fprintf(fp, "%s, %.2f%%, %d minutes, %d seconds\n", student_name, percentage, minutes, seconds);
    fclose(fp);

    // free memory and terminate program
    free(questions);
    printf("Thank you for taking the exam.\n");
    return 0;
}