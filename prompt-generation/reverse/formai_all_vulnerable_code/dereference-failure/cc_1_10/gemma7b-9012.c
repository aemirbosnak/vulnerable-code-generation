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
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who sells products", "b. A person who creates and manages businesses", "c. A person who is good at math", "d. A person who is good at science"}, 2},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Albert Planck"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 0},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 3},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. A hum", "c. A click", "d. A whistle"}, 2},
    {"Which animal is known for its sharp claws?", {"a. Lion", "b. Tiger", "c. Cat", "d. Bear"}, 1},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who sells products", "b. A person who creates and manages businesses", "c. A person who is good at math", "d. A person who is good at science"}, 2},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Albert Planck"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 0},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 3}
};

int main() {
    int i, score = 0, timeLeft = 60;
    char answer;

    // Print the questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);

        // Print the answers
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%s) %s\n", j + 1, questions[i].answers[j]);
        }

        // Get the user's answer
        printf("Enter your answer: ");
        scanf(" %c", &answer);

        // Check if the answer is correct
        if (answer - 'a' == questions[i].correctAnswer) {
            score++;
        }

        // Subtract time from the timer
        timeLeft--;
    }

    // Print the results
    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);
    printf("Time left: %d seconds\n", timeLeft);

    return 0;
}