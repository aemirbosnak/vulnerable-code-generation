//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

struct timeval start, end;

int main() {
    struct timeval start;
    gettimeofday(&start, NULL);

    printf("Welcome to the Table Game!\n");
    printf("Please enter your name: ");
    char name[20];
    scanf("%s", name);
    printf("Hello, %s!\n", name);

    int* numbers = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        numbers[i] = rand() % 10;
    }

    int* scores = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        scores[i] = 0;
    }

    int current_player = 0;
    int turn_count = 0;
    while (turn_count < 10) {
        printf("Player %d, it's your turn!\n", current_player + 1);
        printf("Choose a number from 1 to 10:\n");
        int choice = scanf("%d", &numbers[current_player]);
        if (choice!= 1) {
            printf("Invalid input! Please try again.\n");
            continue;
        }
        scores[current_player] += numbers[current_player];
        printf("Score: %d\n", scores[current_player]);

        if (scores[current_player] >= 100) {
            printf("Congratulations, Player %d! You win!\n", current_player + 1);
            break;
        }

        turn_count++;
        current_player = (current_player + 1) % 5;
    }

    gettimeofday(&end, NULL);
    long duration = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
    printf("Game duration: %.2fs\n", duration / 1000000);

    return 0;
}