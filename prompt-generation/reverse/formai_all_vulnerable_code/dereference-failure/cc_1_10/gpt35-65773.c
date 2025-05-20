//FormAI DATASET v1.0 Category: Sorting ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PLAYERS 5
#define MAX_SCORES 10

// Function to generate random scores
int* generate_scores() {
    srand(time(0));
    int* scores = (int*)calloc(MAX_SCORES, sizeof(int));
    for(int i=0; i<MAX_SCORES; i++) {
        scores[i] = rand() % 100 + 1;
    }
    return scores;
}

// Function to print scores
void print_scores(int* scores) {
    for(int i=0; i<MAX_SCORES; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");
}

// Selection sort implementation
void selection_sort(int* scores, int n) {
    for(int i=0; i<n-1; i++) {
        int min_index = i;
        for(int j=i+1; j<n; j++) {
            if(scores[j] < scores[min_index]) {
                min_index = j;
            }
        }
        int temp = scores[i];
        scores[i] = scores[min_index];
        scores[min_index] = temp;
    }
}

int main() {
    // Generating scores for each player
    int** player_scores = (int**)calloc(MAX_PLAYERS, sizeof(int*));
    for(int i=0; i<MAX_PLAYERS; i++) {
        player_scores[i] = generate_scores();
    }

    // Sorting each player's scores in descending order
    for(int i=0; i<MAX_PLAYERS; i++) {
        printf("Player %d's scores before sorting: ", i+1);
        print_scores(player_scores[i]);
        selection_sort(player_scores[i], MAX_SCORES);
        printf("Player %d's scores after sorting: ", i+1);
        print_scores(player_scores[i]);
    }

    // Finding the player with the highest average score
    int highest_average = 0;
    int highest_average_player = 0;
    for(int i=0; i<MAX_PLAYERS; i++) {
        int total_score = 0;
        for(int j=0; j<MAX_SCORES; j++) {
            total_score += player_scores[i][j];
        }
        int average_score = total_score / MAX_SCORES;
        if(average_score > highest_average) {
            highest_average = average_score;
            highest_average_player = i+1;
        }
    }

    printf("Player %d has the highest average score of %d\n", 
            highest_average_player, highest_average);

    // Freeing the memory allocated to player_scores
    for(int i=0; i<MAX_PLAYERS; i++) {
        free(player_scores[i]);
    }
    free(player_scores);
    
    return 0;
}