//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Question struct
typedef struct Question {
    char *question;
    char **options;
    int num_options;
    int correct_option;
} Question;

// Exam struct
typedef struct Exam {
    char *name;
    Question **questions;
    int num_questions;
    int total_marks;
} Exam;

// Create a new question
Question *create_question(char *question, char **options, int num_options, int correct_option) {
    Question *new_question = malloc(sizeof(Question));
    new_question->question = question;
    new_question->options = options;
    new_question->num_options = num_options;
    new_question->correct_option = correct_option;
    return new_question;
}

// Create a new exam
Exam *create_exam(char *name, Question **questions, int num_questions, int total_marks) {
    Exam *new_exam = malloc(sizeof(Exam));
    new_exam->name = name;
    new_exam->questions = questions;
    new_exam->num_questions = num_questions;
    new_exam->total_marks = total_marks;
    return new_exam;
}

// Print a question
void print_question(Question *question) {
    printf("%s\n", question->question);
    for (int i = 0; i < question->num_options; i++) {
        printf("%d. %s\n", i + 1, question->options[i]);
    }
}

// Print an exam
void print_exam(Exam *exam) {
    printf("Exam: %s\n", exam->name);
    printf("Total marks: %d\n", exam->total_marks);
    for (int i = 0; i < exam->num_questions; i++) {
        print_question(exam->questions[i]);
        printf("\n");
    }
}

// Take an exam
int take_exam(Exam *exam) {
    int score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        int answer;
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%d", &answer);
        if (answer == exam->questions[i]->correct_option) {
            score++;
        }
    }
    return score;
}

// Free the memory allocated for an exam
void free_exam(Exam *exam) {
    for (int i = 0; i < exam->num_questions; i++) {
        free(exam->questions[i]->question);
        for (int j = 0; j < exam->questions[i]->num_options; j++) {
            free(exam->questions[i]->options[j]);
        }
        free(exam->questions[i]->options);
        free(exam->questions[i]);
    }
    free(exam->questions);
    free(exam->name);
    free(exam);
}

// Main function
int main() {
    // Create some questions
    Question *question1 = create_question("What is the capital of India?", (char *[]){"Delhi", "Mumbai", "Bangalore", "Chennai"}, 4, 1);
    Question *question2 = create_question("Who is the Prime Minister of India?", (char *[]){"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 4, 1);
    Question *question3 = create_question("What is the national animal of India?", (char *[]){"Tiger", "Lion", "Elephant", "Peacock"}, 4, 1);

    // Create an exam
    Exam *exam = create_exam("Indian History Exam", (Question *[]){question1, question2, question3}, 3, 100);

    // Print the exam
    print_exam(exam);

    // Take the exam
    int score = take_exam(exam);

    // Print the score
    printf("Your score is: %d\n", score);

    // Free the memory allocated for the exam
    free_exam(exam);

    return 0;
}