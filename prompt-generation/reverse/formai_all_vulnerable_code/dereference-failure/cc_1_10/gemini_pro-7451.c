//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 100
#define MAX_CHOICES 5

// Define the structure of a question
typedef struct Question {
    char question[100];
    char choices[MAX_CHOICES][100];
    int correct_answer;
} Question;

// Define the structure of an examination
typedef struct Examination {
    char name[100];
    int number_of_questions;
    Question questions[MAX_QUESTIONS];
} Examination;

// Create a new examination
Examination* create_examination(char* name) {
    Examination* examination = malloc(sizeof(Examination));
    strcpy(examination->name, name);
    examination->number_of_questions = 0;
    return examination;
}

// Add a question to an examination
void add_question(Examination* examination, Question question) {
    examination->questions[examination->number_of_questions++] = question;
}

// Print an examination
void print_examination(Examination* examination) {
    printf("Examination: %s\n", examination->name);
    for (int i = 0; i < examination->number_of_questions; i++) {
        Question question = examination->questions[i];
        printf("Question %d: %s\n", i + 1, question.question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("Choice %d: %s\n", j + 1, question.choices[j]);
        }
        printf("Correct Answer: %d\n", question.correct_answer);
    }
}

// Grade an examination
int grade_examination(Examination* examination, int* answers) {
    int score = 0;
    for (int i = 0; i < examination->number_of_questions; i++) {
        Question question = examination->questions[i];
        if (answers[i] == question.correct_answer) {
            score++;
        }
    }
    return score;
}

// Main function
int main() {
    // Create a new examination
    Examination* examination = create_examination("Futuristic Examination");

    // Add some questions to the examination
    Question question1 = {
        "What is the capital of the United States?",
        {"Washington, D.C.", "New York City", "Los Angeles", "Chicago", "San Francisco"},
        1
    };
    add_question(examination, question1);

    Question question2 = {
        "What is the largest ocean in the world?",
        {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Southern Ocean"},
        1
    };
    add_question(examination, question2);

    Question question3 = {
        "What is the highest mountain in the world?",
        {"Mount Everest", "K2", "Kangchenjunga", "Lhotse", "Makalu"},
        1
    };
    add_question(examination, question3);

    // Print the examination
    print_examination(examination);

    // Get the user's answers
    int answers[MAX_QUESTIONS];
    for (int i = 0; i < examination->number_of_questions; i++) {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%d", &answers[i]);
    }

    // Grade the examination
    int score = grade_examination(examination, answers);

    // Print the score
    printf("Your score is: %d\n", score);

    return 0;
}