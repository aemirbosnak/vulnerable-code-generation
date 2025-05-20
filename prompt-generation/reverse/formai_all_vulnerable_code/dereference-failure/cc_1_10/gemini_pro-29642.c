//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 100
#define MAX_CHOICES 5

// Define the structure of a question
typedef struct {
    char question[256];
    char choices[MAX_CHOICES][256];
    int correct_choice;
} Question;

// Define the structure of an exam
typedef struct {
    Question questions[MAX_QUESTIONS];
    int num_questions;
} Exam;

// Create a new exam
Exam *create_exam() {
    Exam *exam = malloc(sizeof(Exam));
    exam->num_questions = 0;
    return exam;
}

// Add a question to an exam
void add_question(Exam *exam, char *question, char **choices, int correct_choice) {
    strcpy(exam->questions[exam->num_questions].question, question);
    for (int i = 0; i < MAX_CHOICES; i++) {
        strcpy(exam->questions[exam->num_questions].choices[i], choices[i]);
    }
    exam->questions[exam->num_questions].correct_choice = correct_choice;
    exam->num_questions++;
}

// Load an exam from a file
Exam *load_exam(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    Exam *exam = create_exam();

    // Read the number of questions from the file
    int num_questions;
    fscanf(fp, "%d", &num_questions);

    // Read each question from the file
    for (int i = 0; i < num_questions; i++) {
        // Read the question text
        char question[256];
        fgets(question, 256, fp);

        // Read the choices for the question
        char choices[MAX_CHOICES][256];
        for (int j = 0; j < MAX_CHOICES; j++) {
            fgets(choices[j], 256, fp);
        }

        // Read the correct choice for the question
        int correct_choice;
        fscanf(fp, "%d", &correct_choice);

        // Add the question to the exam
        add_question(exam, question, choices, correct_choice);
    }

    fclose(fp);

    return exam;
}

// Save an exam to a file
void save_exam(Exam *exam, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Write the number of questions to the file
    fprintf(fp, "%d\n", exam->num_questions);

    // Write each question to the file
    for (int i = 0; i < exam->num_questions; i++) {
        // Write the question text
        fprintf(fp, "%s\n", exam->questions[i].question);

        // Write the choices for the question
        for (int j = 0; j < MAX_CHOICES; j++) {
            fprintf(fp, "%s\n", exam->questions[i].choices[j]);
        }

        // Write the correct choice for the question
        fprintf(fp, "%d\n", exam->questions[i].correct_choice);
    }

    fclose(fp);
}

// Take an exam
int take_exam(Exam *exam) {
    int score = 0;

    // Loop through each question in the exam
    for (int i = 0; i < exam->num_questions; i++) {
        // Print the question
        printf("%s\n", exam->questions[i].question);

        // Print the choices for the question
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%d. %s\n", j + 1, exam->questions[i].choices[j]);
        }

        // Get the user's answer
        int answer;
        scanf("%d", &answer);

        // Check if the user's answer is correct
        if (answer == exam->questions[i].correct_choice) {
            score++;
        }
    }

    return score;
}

// Free the memory allocated for an exam
void free_exam(Exam *exam) {
    free(exam);
}

// Main function
int main() {
    // Create a new exam
    Exam *exam = create_exam();

    // Add some questions to the exam
    add_question(exam, "What is the capital of France?", (char *[]) {"Paris", "London", "Rome", "Berlin", "Madrid"}, 0);
    add_question(exam, "What is the largest country in the world?", (char *[]) {"Russia", "China", "United States", "Canada", "Brazil"}, 0);
    add_question(exam, "What is the highest mountain in the world?", (char *[]) {"Mount Everest", "K2", "Kangchenjunga", "Lhotse", "Makalu"}, 0);

    // Save the exam to a file
    save_exam(exam, "exam.txt");

    // Load the exam from a file
    Exam *loaded_exam = load_exam("exam.txt");

    // Take the exam
    int score = take_exam(loaded_exam);

    // Print the score
    printf("Your score is %d\n", score);

    // Free the memory allocated for the exams
    free_exam(exam);
    free_exam(loaded_exam);

    return 0;
}