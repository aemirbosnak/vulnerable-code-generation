//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store questions
typedef struct {
    char *question;
    char *option1;
    char *option2;
    char *option3;
    char *option4;
    char correct_answer;
} Question;

// Function to create a new question
Question *create_question(char *question, char *option1, char *option2, char *option3, char *option4, char correct_answer) {
    Question *new_question = (Question *)malloc(sizeof(Question));
    new_question->question = question;
    new_question->option1 = option1;
    new_question->option2 = option2;
    new_question->option3 = option3;
    new_question->option4 = option4;
    new_question->correct_answer = correct_answer;
    return new_question;
}

// Function to load questions from a file
Question **load_questions(char *filename, int *num_questions) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the number of questions from the file
    fscanf(fp, "%d\n", num_questions);

    // Allocate memory for the questions
    Question **questions = (Question **)malloc(sizeof(Question *) * (*num_questions));

    // Read each question from the file
    for (int i = 0; i < *num_questions; i++) {
        char question[256];
        char option1[256];
        char option2[256];
        char option3[256];
        char option4[256];
        char correct_answer;

        fgets(question, 256, fp);
        fgets(option1, 256, fp);
        fgets(option2, 256, fp);
        fgets(option3, 256, fp);
        fgets(option4, 256, fp);
        fscanf(fp, "%c\n", &correct_answer);

        // Create a new question and add it to the array
        questions[i] = create_question(question, option1, option2, option3, option4, correct_answer);
    }

    fclose(fp);

    return questions;
}

// Function to free the memory allocated for the questions
void free_questions(Question **questions, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        free(questions[i]);
    }
    free(questions);
}

// Function to shuffle the questions
void shuffle_questions(Question **questions, int num_questions) {
    srand(time(NULL));
    for (int i = 0; i < num_questions; i++) {
        int j = rand() % num_questions;
        Question *temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

// Function to take the exam
int take_exam(Question **questions, int num_questions) {
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        // Print the question and options
        printf("%s\n", questions[i]->question);
        printf("1) %s\n", questions[i]->option1);
        printf("2) %s\n", questions[i]->option2);
        printf("3) %s\n", questions[i]->option3);
        printf("4) %s\n", questions[i]->option4);

        // Get the user's answer
        char answer;
        scanf(" %c", &answer);

        // Check if the user's answer is correct
        if (answer == questions[i]->correct_answer) {
            score++;
        }
    }

    return score;
}

// Main function
int main() {
    // Load the questions from the file
    int num_questions;
    Question **questions = load_questions("questions.txt", &num_questions);

    // Shuffle the questions
    shuffle_questions(questions, num_questions);

    // Take the exam
    int score = take_exam(questions, num_questions);

    // Print the score
    printf("Your score is %d out of %d\n", score, num_questions);

    // Free the memory allocated for the questions
    free_questions(questions, num_questions);

    return 0;
}