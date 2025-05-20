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

Question questions[] = {
    {"Which programming language was invented in 1999?", {"Java", "C++", "Python", "JavaScript"}, 1},
    {"What is the meaning of the word 'entrepreneur'?", {"Someone who starts a business", "Someone who sells things", "Someone who is wealthy", "Someone who is smart"}, 2},
    {"Which scientist invented the theory of relativity?", {"Albert Einstein", "Isaac Newton", "Charles Darwin", "Albert Planck"}, 0}
};

int main() {
    time_t start_time, end_time;
    int i, score = 0, totalQuestions = 0;
    char answer;

    start_time = time(NULL);

    for (i = 0; i < MAX_QUESTIONS; i++) {
        totalQuestions++;
        printf("%s\n", questions[i].question);

        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("  %s\n", questions[i].answers[j]);
        }

        printf("Enter your answer: ");
        scanf(" %c", &answer);

        if (answer == questions[i].correctAnswer) {
            score++;
        }
    }

    end_time = time(NULL);

    printf("\nYour total score is: %d/%d", score, totalQuestions);
    printf("\nTime taken: %.2f seconds", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}