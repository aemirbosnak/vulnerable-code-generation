//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char *question;
    char **answers;
    int correctAnswer;
} Question;

Question questions[] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and operates a business", "b. A person who is good at selling", "c. A person who is wealthy", "d. A person who is creative"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 2},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 3},
    {"What is the most common color of the human eye?", {"a. Blue", "b. Brown", "c. Grey", "d. Hazel"}, 4},
    {"Which animal is known for its ability to swim?", {"a. Dog", "b. Cat", "c. Fish", "d. Horse"}, 5},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. Silence", "c. A click", "d. A hum"}, 6},
    {"Which planet is the largest?", {"a. Mars", "b. Earth", "c. Jupiter", "d. Saturn"}, 7},
    {"What is the meaning of the word 'entrepreneur' in a synonym?", {"a. A person who is good at business", "b. A person who is successful", "c. A person who is wealthy", "d. All of the above"}, 8},
    {"Which scientist discovered the vaccine for smallpox?", {"a. Edward Jenner", "b. Louis Pasteur", "c. Jonas Salk", "d. William Howard Russell"}, 9},
    {"What is the chemical symbol for gold?", {"a. Au", "b. Ag", "c. Cu", "d. Fe"}, 10}
};

int main() {
    time_t t = time(NULL);
    srand(t);

    int numQuestions = rand() % MAX_QUESTIONS;

    for (int i = 0; i < numQuestions; i++) {
        Question currentQuestion = questions[i];

        printf("%s\n", currentQuestion.question);

        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%s) %s\n", j + 1, currentQuestion.answers[j]);
        }

        int answer = rand() % MAX_ANSWERS + 1;

        if (answer == currentQuestion.correctAnswer) {
            printf("CORRECT!\n");
        } else {
            printf("Incorrect. The answer is %d.\n", currentQuestion.correctAnswer);
        }
    }

    return 0;
}