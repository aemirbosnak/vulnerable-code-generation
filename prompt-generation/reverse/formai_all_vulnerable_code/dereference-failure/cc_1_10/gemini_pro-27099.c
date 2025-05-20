//GEMINI-pro DATASET v1.0 Category: Poker Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the suits and ranks of the cards
enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

// Define the structure of a card
struct card {
    enum suit suit;
    enum rank rank;
};

// Define the structure of a player
struct player {
    char name[20];
    struct card hand[5];
    int hand_size;
    int score;
};

// Define the structure of a deck of cards
struct deck {
    struct card cards[52];
    int size;
};

// Create a new deck of cards
struct deck* create_deck() {
    struct deck* deck = malloc(sizeof(struct deck));
    deck->size = 52;

    int i = 0;
    for (enum suit suit = CLUBS; suit <= SPADES; suit++) {
        for (enum rank rank = TWO; rank <= ACE; rank++) {
            deck->cards[i].suit = suit;
            deck->cards[i].rank = rank;
            i++;
        }
    }

    return deck;
}

// Shuffle the deck of cards
void shuffle_deck(struct deck* deck) {
    for (int i = 0; i < deck->size; i++) {
        int j = rand() % deck->size;

        struct card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// Deal a hand of cards to a player
void deal_hand(struct deck* deck, struct player* player) {
    for (int i = 0; i < 5; i++) {
        player->hand[i] = deck->cards[deck->size - 1];
        deck->size--;
        player->hand_size++;
    }
}

// Calculate the score of a player's hand
int calculate_score(struct player* player) {
    int score = 0;

    // Check for pairs
    for (int i = 0; i < player->hand_size; i++) {
        for (int j = i + 1; j < player->hand_size; j++) {
            if (player->hand[i].rank == player->hand[j].rank) {
                score += 1;
            }
        }
    }

    // Check for three of a kind
    for (int i = 0; i < player->hand_size; i++) {
        for (int j = i + 1; j < player->hand_size; j++) {
            for (int k = j + 1; k < player->hand_size; k++) {
                if (player->hand[i].rank == player->hand[j].rank && player->hand[i].rank == player->hand[k].rank) {
                    score += 3;
                }
            }
        }
    }

    // Check for four of a kind
    for (int i = 0; i < player->hand_size; i++) {
        for (int j = i + 1; j < player->hand_size; j++) {
            for (int k = j + 1; k < player->hand_size; k++) {
                for (int l = k + 1; l < player->hand_size; l++) {
                    if (player->hand[i].rank == player->hand[j].rank && player->hand[i].rank == player->hand[k].rank && player->hand[i].rank == player->hand[l].rank) {
                        score += 6;
                    }
                }
            }
        }
    }

    // Check for a straight
    int straight = 1;
    for (int i = 1; i < player->hand_size; i++) {
        if (player->hand[i].rank != player->hand[i - 1].rank + 1) {
            straight = 0;
            break;
        }
    }
    if (straight) {
        score += 4;
    }

    // Check for a flush
    int flush = 1;
    for (int i = 1; i < player->hand_size; i++) {
        if (player->hand[i].suit != player->hand[i - 1].suit) {
            flush = 0;
            break;
        }
    }
    if (flush) {
        score += 5;
    }

    // Check for a full house
    int full_house = 0;
    if (score >= 3 && score < 6) {
        for (int i = 0; i < player->hand_size; i++) {
            for (int j = i + 1; j < player->hand_size; j++) {
                if (player->hand[i].rank == player->hand[j].rank) {
                    full_house = 1;
                    break;
                }
            }
        }
    }
    if (full_house) {
        score += 7;
    }

    // Check for a straight flush
    if (straight && flush) {
        score += 8;
    }

    // Check for a royal flush
    if (straight && flush && player->hand[0].rank == ACE) {
        score += 9;
    }

    return score;
}

// Compare the scores of two players
int compare_scores(struct player* player1, struct player* player2) {
    if (player1->score > player2->score) {
        return 1;
    } else if (player1->score < player2->score) {
        return -1;
    } else {
        return 0;
    }
}

// Print the results of the game
void print_results(struct player* players, int num_players) {
    printf("** Poker Results **\n\n");

    for (int i = 0; i < num_players; i++) {
        printf("%s: ", players[i].name);

        switch (players[i].score) {
            case 0:
                printf("No pair");
                break;
            case 1:
                printf("One pair");
                break;
            case 3:
                printf("Three of a kind");
                break;
            case 4:
                printf("Straight");
                break;
            case 5:
                printf("Flush");
                break;
            case 6:
                printf("Four of a kind");
                break;
            case 7:
                printf("Full house");
                break;
            case 8:
                printf("Straight flush");
                break;
            case 9:
                printf("Royal flush");
                break;
        }

        printf("\n\n");
    }

    // Find the player with the highest score
    int max_score = 0;
    struct player* winner = NULL;
    for (int i = 0; i < num_players; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            winner = &players[i];
        }
    }

    printf("The winner is %s with a score of %d\n\n", winner->name, winner->score);
}

// Main function
int main() {
    // Create a new deck of cards
    struct deck* deck = create_deck();

    // Shuffle the deck
    shuffle_deck(deck);

    // Create the players
    struct player players[2];
    strcpy(players[0].name, "Player 1");
    strcpy(players[1].name, "Player 2");

    // Deal a hand to each player
    deal_hand(deck, &players[0]);
    deal_hand(deck, &players[1]);

    // Calculate the score of each player's hand
    players[0].score = calculate_score(&players[0]);
    players[1].score = calculate_score(&players[1]);

    // Compare the scores of the two players
    int result = compare_scores(&players[0], &players[1]);

    // Print the results of the game
    print_results(players, 2);

    // Free the memory allocated for the deck
    free(deck);

    return 0;
}