//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 100
#define MAX_CHOICES 5

// Define the structure of a question
typedef struct question {
    char question[100];
    char choices[MAX_CHOICES][100];
    int correct_answer;
} question;

// Define the structure of an examination
typedef struct examination {
    char name[100];
    int num_questions;
    question questions[MAX_QUESTIONS];
} examination;

// Define the function to create a new examination
examination *create_examination(char *name) {
    examination *exam = malloc(sizeof(examination));
    strcpy(exam->name, name);
    exam->num_questions = 0;
    return exam;
}

// Define the function to add a question to an examination
void add_question(examination *exam, char *question, char **choices, int correct_answer) {
    strcpy(exam->questions[exam->num_questions].question, question);
    for (int i = 0; i < MAX_CHOICES; i++) {
        strcpy(exam->questions[exam->num_questions].choices[i], choices[i]);
    }
    exam->questions[exam->num_questions].correct_answer = correct_answer;
    exam->num_questions++;
}

// Define the function to take an examination
int take_examination(examination *exam) {
    int score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        printf("%s\n", exam->questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%d. %s\n", j + 1, exam->questions[i].choices[j]);
        }
        int answer;
        scanf("%d", &answer);
        if (answer == exam->questions[i].correct_answer) {
            score++;
        }
    }
    return score;
}

// Define the main function
int main(int argc, char *argv[]) {
    // Create a new examination
    examination *exam = create_examination("C Online Examination");

    // Add some questions to the examination
    char *choices1[] = {"a", "b", "c", "d", "e"};
    add_question(exam, "What is the output of the following code?\nint main() { printf(\"Hello, world!\n\"); }", choices1, 0);

    char *choices2[] = {"a", "b", "c", "d", "e"};
    add_question(exam, "What is the purpose of the following code?\nint main() { return 0; }", choices2, 4);

    char *choices3[] = {"a", "b", "c", "d", "e"};
    add_question(exam, "What is the difference between a pointer and a reference?", choices3, 2);

    // Take the examination
    int score = take_examination(exam);

    // Print the score
    printf("Your score is %d out of %d\n", score, exam->num_questions);

    return 0;
}