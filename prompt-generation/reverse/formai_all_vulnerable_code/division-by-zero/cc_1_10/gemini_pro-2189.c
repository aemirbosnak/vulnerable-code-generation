//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_QUESTIONS 10
#define MAX_TIME 60

typedef struct {
    char name[32];
    int score;
    int time;
} Player;

Player players[MAX_PLAYERS];
char questions[MAX_QUESTIONS][128];
int answers[MAX_QUESTIONS];

void generate_questions() {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int a = rand() % 100;
        int b = rand() % 100;
        int op = rand() % 4;
        char *ops[] = {"+", "-", "*", "/"};
        snprintf(questions[i], 128, "%d %s %d", a, ops[op], b);
        switch (op) {
            case 0:
                answers[i] = a + b;
                break;
            case 1:
                answers[i] = a - b;
                break;
            case 2:
                answers[i] = a * b;
                break;
            case 3:
                answers[i] = a / b;
                break;
        }
    }
}

void start_game() {
    srand(time(NULL));
    generate_questions();
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        players[i].time = MAX_TIME;
    }
    printf("\n");
}

void show_question(int q) {
    printf("%s = ?\n", questions[q]);
}

void get_answer(int p) {
    int ans;
    printf("%s's turn: ", players[p].name);
    scanf("%d", &ans);
    if (ans == answers[p]) {
        players[p].score++;
        printf("Correct!\n");
    } else {
        printf("Wrong answer. The correct answer is %d\n", answers[p]);
        players[p].time -= 5;
    }
}

void show_results() {
    printf("\nResults:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d points, %d seconds remaining\n", players[i].name, players[i].score, players[i].time);
    }
}

int main() {
    start_game();
    for (int q = 0; q < MAX_QUESTIONS; q++) {
        show_question(q);
        for (int p = 0; p < MAX_PLAYERS; p++) {
            get_answer(p);
        }
    }
    show_results();
    return 0;
}