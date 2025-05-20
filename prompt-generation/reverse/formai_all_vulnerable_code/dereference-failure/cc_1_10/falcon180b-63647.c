//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define MAX_SCORE 100

struct question {
    char *text;
    int answer;
    int difficulty;
};

void generate_question(struct question *q) {
    int i, j;
    char *answers[4] = {"A", "B", "C", "D"};
    char buf[100];

    q->text = malloc(100);
    q->answer = rand() % 4;
    sprintf(buf, "Question %d: %s (%c)", q->answer + 1, "What is the meaning of life?", 'A');
    strcpy(q->text, buf);

    for (i = 0; i < 4; i++) {
        if (i == q->answer) {
            strcat(q->text, " (correct)");
        } else {
            strcat(q->text, " (incorrect)");
        }
    }
}

int main() {
    int i, j, score = 0;
    struct question questions[NUM_QUESTIONS];

    srand(time(NULL));

    for (i = 0; i < NUM_QUESTIONS; i++) {
        generate_question(&questions[i]);
    }

    for (i = 0; i < NUM_QUESTIONS; i++) {
        printf("%s\n", questions[i].text);
        scanf("%d", &j);

        if (j == questions[i].answer) {
            score += questions[i].difficulty;
        }
    }

    printf("Your final score is: %d out of %d\n", score, MAX_SCORE);

    return 0;
}