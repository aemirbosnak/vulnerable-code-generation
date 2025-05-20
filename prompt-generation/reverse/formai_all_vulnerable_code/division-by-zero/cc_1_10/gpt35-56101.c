//FormAI DATASET v1.0 Category: Math exercise ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_QUESTIONS 10

pthread_mutex_t lock;

typedef struct {
    int a, b;
    char operator;
    int answer;
} Question;

Question questions[MAX_QUESTIONS];

int score = 0;
int current_question = 0;

void *ask_question(void *arg) {
    Question *q = (Question *)arg;
    printf("Question %d: %d %c %d = ", current_question + 1, q->a, q->operator, q->b);
    scanf("%d", &q->answer);
    current_question++;
    return NULL;
}

void generate_questions() {
    srand(time(NULL));
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int a = rand() % 100;
        int b = rand() % 100;
        char operators[4] = {'+', '-', '*', '/'};
        char op = operators[rand() % 4];
        Question q = {a, b, op};
        switch (op) {
            case '+':
                q.answer = a + b;
                break;
            case '-':
                q.answer = a - b;
                break;
            case '*':
                q.answer = a * b;
                break;
            case '/':
                q.answer = a / b;
                break;
            default:
                break;
        }
        questions[i] = q;
    }
}

bool check_answer(Question q) {
    return q.answer == q.a + q.b || q.answer == q.a - q.b || q.answer == q.a * q.b || q.answer == q.a / q.b;
}

int main() {
    generate_questions();
    printf("Welcome to the Math Quiz Game!\n\n");
    printf("You will be presented with 10 math questions.\n");
    printf("Answer as many as you can correctly in 30 seconds.\n\n");
    printf("Press enter to start the quiz...");
    getchar();

    pthread_t threads[MAX_QUESTIONS];
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        pthread_create(&threads[i], NULL, ask_question, &questions[i]);
    }

    printf("You have 30 seconds to answer the questions...\n");
    sleep(30);

    printf("Time's up!\n\n");
    printf("Calculating your score...\n\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        pthread_join(threads[i], NULL);
        pthread_mutex_lock(&lock);
        if (check_answer(questions[i])) {
            score++;
        }
        pthread_mutex_unlock(&lock);
    }

    printf("You scored %d out of 10.\n\n", score);

    if (score == 10) {
        printf("Congratulations! You are a math genius!\n");
    } else if (score >= 7) {
        printf("Great job! You have a good grasp on the basics of math.\n");
    } else {
        printf("Better luck next time. Keep practicing!\n");
    }

    return 0;
}