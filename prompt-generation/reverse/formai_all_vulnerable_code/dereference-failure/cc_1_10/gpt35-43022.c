//FormAI DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_QUESTIONS 50 // maximum number of questions in the database
#define MAX_CHOICES 4 // maximum number of choices for each question
#define MAX_ANSWER_LENGTH 10 // maximum length of answer string
#define MAX_NAME_LENGTH 20 // maximum length of student name string

// structure to hold a question and its choices and answer
struct question {
    char text[100];
    char choices[MAX_CHOICES][50];
    int correct_choice;
};

// function to load questions from file
int load_questions(struct question questions[]) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error loading questions!\n");
        return 0;
    }

    int num_questions = 0;
    char line[200];

    // read questions from file and parse text, choices, and correct answer
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *pch;
        pch = strtok(line, "|");
        strcpy(questions[num_questions].text, pch);
        for (int i = 0; i < MAX_CHOICES; i++) {
            pch = strtok(NULL, "|");
            strcpy(questions[num_questions].choices[i], pch);
        }
        pch = strtok(NULL, "|");
        questions[num_questions].correct_choice = atoi(pch);
        num_questions++;
    }

    fclose(fp);
    return num_questions;
}

// function to administer the examination
void administer_exam(struct question questions[], int num_questions) {
    char name[MAX_NAME_LENGTH];
    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // remove trailing newline character

    int score = 0;

    // randomize order of questions
    int order[num_questions];
    for (int i = 0; i < num_questions; i++) {
        order[i] = i;
    }
    srand(time(NULL));
    for (int i = 0; i < num_questions; i++) {
        int j = rand() % num_questions;
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }

    printf("Please answer the following %d questions:\n", num_questions);

    // ask each randomized question and check answer
    for (int i = 0; i < num_questions; i++) {
        int index = order[i];
        printf("%d. %s\n", i+1, questions[index].text);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%c) %s\n", 'A'+j, questions[index].choices[j]);
        }
        printf("Answer: ");
        char answer[MAX_ANSWER_LENGTH];
        scanf("%s", answer);
        if (answer[0] == 'A' + questions[index].correct_choice - 1) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %c.\n", 'A' + questions[index].correct_choice - 1);
        }
    }

    printf("Thank you for taking the exam, %s. Your score is %d/%d.\n", name, score, num_questions);
}

int main() {
    struct question questions[MAX_QUESTIONS];
    int num_questions = load_questions(questions);
    if (num_questions == 0) {
        return 1;
    }

    administer_exam(questions, num_questions);

    return 0;
}