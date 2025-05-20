//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The "questions" and "answers" arrays store the questions and answers for the exam.
char *questions[] = {
    "What is the capital of France?",
    "What is the name of the largest ocean in the world?",
    "What is the chemical symbol for gold?",
    "Who painted the Mona Lisa?",
    "What is the name of the first book in the Harry Potter series?"
};

char *answers[] = {
    "Paris",
    "Pacific Ocean",
    "Au",
    "Leonardo da Vinci",
    "Harry Potter and the Sorcerer's Stone"
};

// The "studentAnswers" array will store the student's answers to the exam questions.
char *studentAnswers[5];

// The "grading" function checks the student's answers against the correct answers and returns a score.
int grading(char *studentAnswers[]) {
    int score = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(studentAnswers[i], answers[i]) == 0) {
            score++;
        }
    }
    return score;
}

int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Generate a random number between 0 and 4 to select a question.
    int questionIndex = rand() % 5;

    // Print the question to the student.
    printf("Question: %s\n", questions[questionIndex]);

    // Get the student's answer.
    char *answer = malloc(100);
    scanf("%s", answer);

    // Store the student's answer in the "studentAnswers" array.
    studentAnswers[questionIndex] = answer;

    // Grade the student's answer.
    int score = grading(studentAnswers);

    // Print the student's score.
    printf("Your score: %d\n", score);

    return 0;
}