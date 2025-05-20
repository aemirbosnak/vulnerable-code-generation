//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PLAYERS 10
#define MAX_QUESTIONS 20
#define MAX_ATTEMPTS 3
#define CORRECT_ANSWER_VALUE 100
#define INCORRECT_ANSWER_VALUE -50

typedef struct {
    char name[30];
    int score;
} Player;

void shuffleArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int numPlayers;
    char input[30];

    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    int numQuestions;
    char questions[MAX_QUESTIONS][100];
    int answers[MAX_QUESTIONS];
    int correctAnswers[MAX_QUESTIONS];

    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);

    for (int i = 0; i < numQuestions; i++) {
        printf("Enter question %d: ", i + 1);
        scanf("%s", questions[i]);

        int numAnswers;
        printf("Enter the number of answers for question %d: ", i + 1);
        scanf("%d", &numAnswers);

        for (int j = 0; j < numAnswers; j++) {
            printf("Enter answer %d: ", j + 1);
            scanf("%s", &questions[i][strcspn(questions[i], ",") + 1 + j * (strcspn(questions[i], ",") + 1)]);
        }

        correctAnswers[i] = rand() % numAnswers;
    }

    int round = 1;
    while (round <= numQuestions) {
        printf("\nRound %d\n", round);

        for (int i = 0; i < numQuestions; i++) {
            if (i >= round && i < numQuestions) {
                printf("%s\n", questions[i]);

                for (int j = 0; j < strlen(questions[i]); j++) {
                    if (questions[i][j] == ',') {
                        questions[i][j] = '\0';
                    }
                }

                int numAttempts = 0;
                while (numAttempts < MAX_ATTEMPTS) {
                    printf("Player %s, enter your answer: ", players[0].name);
                    scanf("%s", input);

                    if (strcmp(input, questions[i]) == 0) {
                        players[0].score += CORRECT_ANSWER_VALUE;
                        printf("Correct!\n");
                    } else {
                        players[0].score -= INCORRECT_ANSWER_VALUE;
                        printf("Incorrect.\n");
                    }

                    numAttempts++;
                }

                break;
            }
        }

        round++;
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("Player %s's final score: %d\n", players[i].name, players[i].score);
    }

    return 0;
}