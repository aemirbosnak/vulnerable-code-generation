//FormAI DATASET v1.0 Category: Table Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

//Global variables
int players = 3; //Number of players
int *scores;   //Scores of players
int currentPlayer = 0; //Current player
int *gameMatrix; //Game matrix

//Functions
void printMatrix();
int rollDice();
void *playGame(void *playerId);

//Mutex Lock
pthread_mutex_t lock;

int main()
{
    //Allocate memory for scores
    scores = (int *)malloc(players * sizeof(int));

    //Allocate memory for game matrix
    gameMatrix = (int *)malloc(10 * 10 * sizeof(int));

    //Initialize mutex lock
    pthread_mutex_init(&lock, NULL);

    //Seed random number generator
    srand(time(NULL));

    //Initialize game matrix
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            *(gameMatrix + i * 10 + j) = rand() % 100;
        }
    }

    //Print game matrix
    printf("Game Matrix:\n");
    printMatrix();

    //Create threads for players
    pthread_t tid[players];
    int playerId[players];
    for (int i = 0; i < players; i++)
    {
        playerId[i] = i + 1;
        pthread_create(&tid[i], NULL, playGame, &playerId[i]);
    }

    //Join threads for players
    for (int i = 0; i < players; i++)
    {
        pthread_join(tid[i], NULL);
    }

    //Determine winner
    int maxScore = scores[0];
    int winner = 1;
    for (int i = 1; i < players; i++)
    {
        if (scores[i] > maxScore)
        {
            maxScore = scores[i];
            winner = i + 1;
        }
    }

    //Print winner
    printf("Player %d wins with a score of %d\n", winner, maxScore);

    //Free memory
    free(scores);
    free(gameMatrix);

    //Destroy mutex lock
    pthread_mutex_destroy(&lock);

    return 0;
}

void printMatrix()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d\t", *(gameMatrix + i * 10 + j));
        }
        printf("\n");
    }
}

int rollDice()
{
    return rand() % 6 + 1;
}

void *playGame(void *playerId)
{
    int id = *((int *)playerId);
    int score = 0;

    printf("Player %d starts the game!\n", id);

    while (score < 100)
    {
        //Roll dice
        int roll = rollDice();

        //Acquire mutex lock
        pthread_mutex_lock(&lock);

        //Update score
        score += *(gameMatrix + currentPlayer * 10 + roll - 1);
        printf("Player %d rolls a %d and moves to %d with a score of %d\n", id, roll, score, score);

        //Update current player
        currentPlayer = (currentPlayer + 1) % players;

        //Release mutex lock
        pthread_mutex_unlock(&lock);
    }

    //Update score
    scores[id - 1] = score;

    printf("Player %d ends the game with a score of %d\n", id, score);
    pthread_exit(NULL);
}