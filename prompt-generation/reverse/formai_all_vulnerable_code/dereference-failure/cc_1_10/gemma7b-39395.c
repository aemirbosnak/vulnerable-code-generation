//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char *question;
    char **answers;
    int correctAnswer;
} Question;

Question questions[] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A business owner", "b. A scientist", "c. A teacher", "d. A programmer"}, 1},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 2},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Lille"}, 0}
};

int main() {
    int i, score = 0, timeLeft = 60;
    char answer;

    // Initialize the timer
    time_t start = time(NULL);

    // Display the questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);

        // Display the answers
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%s\n", questions[i].answers[j]);
        }

        // Get the user's answer
        scanf(" %c", &answer);

        // Check if the answer is correct
        if (answer == questions[i].correctAnswer) {
            score++;
        }
    }

    // Calculate the time taken
    time_t end = time(NULL);
    int timeTaken = end - start;

    // Display the results
    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);
    printf("Time taken: %d seconds\n", timeTaken);

    return 0;
}