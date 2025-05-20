//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: sophisticated
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
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages businesses", "b. A person who is good at selling things", "c. A person who is wealthy", "d. A person who is creative"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 1},
    {"What is the capital of Brazil?", {"a. Rio de Janeiro", "b. São Paulo", "c. Brasilia", "d. Lima"}, 2},
    {"Which animal is known for its sharp eyesight?", {"a. Tiger", "b. Lion", "c. Owl", "d. Giraffe"}, 2},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. A hum", "c. A click", "d. A beep"}, 3},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 3},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages businesses", "b. A person who is good at selling things", "c. A person who is wealthy", "d. A person who is creative"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 1},
    {"What is the capital of Brazil?", {"a. Rio de Janeiro", "b. São Paulo", "c. Brasilia", "d. Lima"}, 2},
    {"Which animal is known for its sharp eyesight?", {"a. Tiger", "b. Lion", "c. Owl", "d. Giraffe"}, 2}
};

int main() {
    time_t t = time(NULL);
    srand(t);

    int numQuestions = rand() % MAX_QUESTIONS;

    for (int i = 0; i < numQuestions; i++) {
        printf("%s\n", questions[i].question);

        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%s) %s\n", j + 1, questions[i].answers[j]);
        }

        int answer = rand() % MAX_ANSWERS;

        if (questions[i].correctAnswer == answer) {
            printf("Congratulations! You answered correctly.\n");
        } else {
            printf("Sorry, your answer is incorrect. The correct answer is %d.\n", questions[i].correctAnswer);
        }
    }

    return 0;
}