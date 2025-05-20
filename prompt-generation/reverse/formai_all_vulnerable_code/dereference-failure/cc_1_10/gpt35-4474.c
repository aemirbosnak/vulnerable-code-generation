//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>

// Structure for each player
typedef struct{
    int player_num;
    int score;
} Player;

// Function to sort the players by score in descending order
int compare(const void* a, const void* b){
    Player* player_a = (Player*)a;
    Player* player_b = (Player*)b;
    return player_b->score - player_a->score;
}

int main(){
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    // Initialize the array of players
    Player* players = (Player*)malloc(num_players * sizeof(Player));
    for(int i=0; i<num_players; i++){
        players[i].player_num = i+1;
        players[i].score = 0;
    }

    int num_rounds;
    printf("Enter the number of rounds: ");
    scanf("%d", &num_rounds);

    // Play the game for each round
    for(int round=1; round<=num_rounds; round++){
        printf("\n\nROUND %d\n\n", round);

        // Get input from each player
        for(int i=0; i<num_players; i++){
            printf("Player %d, enter your score for this round: ", players[i].player_num);
            int score;
            scanf("%d", &score);
            players[i].score += score;
        }

        // Sort the players by score
        qsort(players, num_players, sizeof(Player), compare);
        printf("\nSCOREBOARD:\n");
        for(int i=0; i<num_players; i++){
            printf("Player %d: %d\n", players[i].player_num, players[i].score);
        }
    }

    // Declare the winner
    printf("\n\nWINNER: PLAYER %d\n\n", players[0].player_num);

    // Free the memory allocated for the players array
    free(players);
    return 0;
}