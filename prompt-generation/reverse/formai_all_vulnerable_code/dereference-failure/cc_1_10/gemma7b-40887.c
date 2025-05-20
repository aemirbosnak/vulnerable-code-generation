//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char *question;
    char **answers;
    int answerIndex;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. Business owner", "b. Salesperson", "c. Artist", "d. Lawyer"}, 2},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Lyon", "d. Marseille"}, 0},
    // Add more questions here...
};

int main() {
    time_t start_time = time(NULL);
    int score = 0;
    int currentQuestionIndex = 0;

    // Display questions and get user answers
    while (currentQuestionIndex < MAX_QUESTIONS) {
        // Print the question
        printf("%s\n", questions[currentQuestionIndex].question);

        // Get the user's answer
        char answer[MAX_ANSWERS];
        printf("Enter your answer: ");
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, questions[currentQuestionIndex].answers[questions[currentQuestionIndex].answerIndex]) == 0) {
            score++;
        }

        // Move on to the next question
        currentQuestionIndex++;
    }

    // Calculate the time taken
    time_t end_time = time(NULL);
    int timeTaken = end_time - start_time;

    // Display the results
    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);
    printf("Time taken: %d seconds\n", timeTaken);

    return 0;
}