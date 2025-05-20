//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of questions in the exam
#define NUM_QUESTIONS 10

// Define the maximum number of choices for each question
#define MAX_CHOICES 4

// Define the structure of a question
typedef struct question {
    char *text;
    char *choices[MAX_CHOICES];
    int correct_answer;
} question;

// Define the structure of an exam
typedef struct exam {
    question questions[NUM_QUESTIONS];
    int num_questions;
} exam;

// Create a new exam
exam *new_exam() {
    exam *e = malloc(sizeof(exam));
    e->num_questions = NUM_QUESTIONS;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        e->questions[i].text = NULL;
        for (int j = 0; j < MAX_CHOICES; j++) {
            e->questions[i].choices[j] = NULL;
        }
        e->questions[i].correct_answer = -1;
    }
    return e;
}

// Free an exam
void free_exam(exam *e) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        free(e->questions[i].text);
        for (int j = 0; j < MAX_CHOICES; j++) {
            free(e->questions[i].choices[j]);
        }
    }
    free(e);
}

// Load an exam from a file
exam *load_exam(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    exam *e = new_exam();

    char line[1024];
    int line_num = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the line
        char *p = strtok(line, ",");
        if (p == NULL) {
            continue;
        }
        e->questions[line_num].text = strdup(p);

        for (int i = 0; i < MAX_CHOICES; i++) {
            p = strtok(NULL, ",");
            if (p == NULL) {
                break;
            }
            e->questions[line_num].choices[i] = strdup(p);
        }

        p = strtok(NULL, ",");
        if (p == NULL) {
            continue;
        }
        e->questions[line_num].correct_answer = atoi(p);

        line_num++;
    }

    fclose(fp);

    return e;
}

// Save an exam to a file
void save_exam(exam *e, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        fprintf(fp, "%s,", e->questions[i].text);
        for (int j = 0; j < MAX_CHOICES; j++) {
            fprintf(fp, "%s,", e->questions[i].choices[j]);
        }
        fprintf(fp, "%d\n", e->questions[i].correct_answer);
    }

    fclose(fp);
}

// Print an exam to the console
void print_exam(exam *e) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("%s\n", e->questions[i].text);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("    %d. %s\n", j + 1, e->questions[i].choices[j]);
        }
    }
}

// Grade an exam
int grade_exam(exam *e, int *answers) {
    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (answers[i] == e->questions[i].correct_answer) {
            score++;
        }
    }
    return score;
}

// Main function
int main() {
    // Create a new exam
    exam *e = new_exam();

    // Load the exam from a file
    e = load_exam("exam.txt");

    // Print the exam to the console
    print_exam(e);

    // Get the answers from the user
    int answers[NUM_QUESTIONS];
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%d", &answers[i]);
    }

    // Grade the exam
    int score = grade_exam(e, answers);

    // Print the score
    printf("Your score is %d/%d\n", score, NUM_QUESTIONS);

    // Free the exam
    free_exam(e);

    return 0;
}