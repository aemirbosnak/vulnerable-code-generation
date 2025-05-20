//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions in the exam
#define MAX_QUESTIONS 100

// Define the structure of a question
typedef struct {
    char *question;
    char *options[4];
    int correct_answer;
} Question;

// Define the structure of the exam
typedef struct {
    char *name;
    int num_questions;
    Question questions[MAX_QUESTIONS];
} Exam;

// Create a new exam
Exam *create_exam(char *name, int num_questions) {
    Exam *exam = malloc(sizeof(Exam));
    exam->name = strdup(name);
    exam->num_questions = num_questions;
    for (int i = 0; i < num_questions; i++) {
        exam->questions[i].question = NULL;
        for (int j = 0; j < 4; j++) {
            exam->questions[i].options[j] = NULL;
        }
        exam->questions[i].correct_answer = -1;
    }
    return exam;
}

// Free the memory allocated for an exam
void free_exam(Exam *exam) {
    free(exam->name);
    for (int i = 0; i < exam->num_questions; i++) {
        free(exam->questions[i].question);
        for (int j = 0; j < 4; j++) {
            free(exam->questions[i].options[j]);
        }
    }
    free(exam);
}

// Add a question to an exam
void add_question(Exam *exam, char *question, char *option1, char *option2, char *option3, char *option4, int correct_answer) {
    int index = exam->num_questions++;
    exam->questions[index].question = strdup(question);
    exam->questions[index].options[0] = strdup(option1);
    exam->questions[index].options[1] = strdup(option2);
    exam->questions[index].options[2] = strdup(option3);
    exam->questions[index].options[3] = strdup(option4);
    exam->questions[index].correct_answer = correct_answer;
}

// Print an exam to the console
void print_exam(Exam *exam) {
    printf("Exam: %s\n", exam->name);
    for (int i = 0; i < exam->num_questions; i++) {
        printf("Question %d:\n", i + 1);
        printf("\t%s\n", exam->questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("\t%d. %s\n", j + 1, exam->questions[i].options[j]);
        }
    }
}

// Grade an exam
int grade_exam(Exam *exam, int *answers) {
    int score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        if (answers[i] == exam->questions[i].correct_answer) {
            score++;
        }
    }
    return score;
}

// Main function
int main() {
    // Create a new exam
    Exam *exam = create_exam("C Online Exam", 10);

    // Add questions to the exam
    add_question(exam, "What is the output of the following code?\nint main() { printf(\"%d\", 1 + 2 * 3); }", "1", "7", "9", "11", 1);
    add_question(exam, "Which of the following is not a valid C data type?", "int", "float", "double", "string", 3);
    add_question(exam, "What is the value of the following expression?\n(5 % 3) * 2", "0", "2", "4", "6", 2);
    add_question(exam, "Which of the following operators has the highest precedence?", "*", "+", "&&", "=", 0);
    add_question(exam, "What is the output of the following code?\nint main() { int x = 10; x++; printf(\"%d\", x); }", "9", "10", "11", "12", 2);

    // Print the exam to the console
    print_exam(exam);

    // Get the answers from the user
    int answers[10];
    for (int i = 0; i < 10; i++) {
        printf("Enter the answer to question %d: ", i + 1);
        scanf("%d", &answers[i]);
    }

    // Grade the exam
    int score = grade_exam(exam, answers);

    // Print the score to the console
    printf("Your score is: %d\n", score);

    // Free the memory allocated for the exam
    free_exam(exam);

    return 0;
}