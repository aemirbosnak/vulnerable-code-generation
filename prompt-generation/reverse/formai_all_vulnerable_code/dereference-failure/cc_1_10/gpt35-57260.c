//FormAI DATASET v1.0 Category: Poker Game ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum rank {
    ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
    EIGHT, NINE, TEN, JACK, QUEEN, KING
} rank_t;

typedef enum suit {
    HEARTS, DIAMONDS, CLUBS, SPADES
} suit_t;

typedef struct card {
    rank_t rank;
    suit_t suit;
} card_t;

typedef struct deck {
    card_t *cards;
    int top_card;
} deck_t;

typedef struct player {
    card_t hand[HAND_SIZE];
} player_t;

void shuffle(deck_t *deck) {
    card_t temp_card;
    int i, j;
    for(i=0; i<DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        temp_card = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp_card;
    }
}

void print_card(const card_t *card) {
    char *rank, *suit;
    switch(card->rank) {
        case ACE: rank = "Ace"; break;
        case TWO: rank = "2"; break;
        case THREE: rank = "3"; break;
        case FOUR: rank = "4"; break;
        case FIVE: rank = "5"; break;
        case SIX: rank = "6"; break;
        case SEVEN: rank = "7"; break;
        case EIGHT: rank = "8"; break;
        case NINE: rank = "9"; break;
        case TEN: rank = "10"; break;
        case JACK: rank = "Jack"; break;
        case QUEEN: rank = "Queen"; break;
        case KING: rank = "King"; break;
    }
    switch(card->suit) {
        case HEARTS: suit = "Hearts"; break;
        case DIAMONDS: suit = "Diamonds"; break;
        case CLUBS: suit = "Clubs"; break;
        case SPADES: suit = "Spades"; break;
    }
    printf("%s of %s\n", rank, suit);
}

deck_t *create_deck() {
    deck_t *deck = malloc(sizeof(deck_t));
    deck->cards = malloc(sizeof(card_t) * DECK_SIZE);
    deck->top_card = 0;
    int i, j;
    for(i=0; i<NUM_SUITS; i++) {
        for(j=1; j<=NUM_RANKS; j++) {
            deck->cards[deck->top_card].suit = i;
            deck->cards[deck->top_card].rank = j;
            deck->top_card++;
        }
    }
    shuffle(deck);
    return deck;
}

void deal(deck_t *deck, player_t *player) {
    int i;
    for(i=0; i<HAND_SIZE; i++) {
        player->hand[i] = deck->cards[deck->top_card];
        deck->top_card++;
    }
}

void print_hand(player_t *player) {
    int i;
    for(i=0; i<HAND_SIZE; i++) {
        printf("%d. ", i+1);
        print_card(&player->hand[i]);
    }
}

void discard(deck_t *deck, player_t *player, int index) {
    player->hand[index] = deck->cards[deck->top_card];
    deck->top_card++;
}

void sort_hand(player_t *player) {
    int i, j, min_value, min_index;
    card_t temp_card;
    for(i=0; i<HAND_SIZE; i++) {
        min_index = i;
        min_value = player->hand[i].rank;
        for(j=i+1; j<HAND_SIZE; j++) {
            if(player->hand[j].rank < min_value) {
                min_index = j;
                min_value = player->hand[j].rank;
            }
        }
        if(min_index != i) {
            temp_card = player->hand[i];
            player->hand[i] = player->hand[min_index];
            player->hand[min_index] = temp_card;
        }
    }
}

int is_pair(player_t *player) {
    int i, j;
    for(i=0; i<HAND_SIZE-1; i++) {
        for(j=i+1; j<HAND_SIZE; j++) {
            if(player->hand[i].rank == player->hand[j].rank) {
                return 1;
            }
        }
    }
    return 0;
}

int is_two_pair(player_t *player) {
    int i, j, num_pairs=0;
    for(i=0; i<HAND_SIZE-1; i++) {
        for(j=i+1; j<HAND_SIZE; j++) {
            if(player->hand[i].rank == player->hand[j].rank) {
                num_pairs++;
            }
        }
    }
    if(num_pairs == 2) {
        return 1;
    } else {
        return 0;
    }
}

int is_three_of_a_kind(player_t *player) {
    int i, j, k;
    for(i=0; i<HAND_SIZE-2; i++) {
        for(j=i+1; j<HAND_SIZE-1; j++) {
            for(k=j+1; k<HAND_SIZE; k++) {
                if(player->hand[i].rank == player->hand[j].rank &&
                   player->hand[j].rank == player->hand[k].rank) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int is_four_of_a_kind(player_t *player) {
    int i, j, k, l;
    for(i=0; i<HAND_SIZE-3; i++) {
        for(j=i+1; j<HAND_SIZE-2; j++) {
            for(k=j+1; k<HAND_SIZE-1; k++) {
                for(l=k+1; l<HAND_SIZE; l++) {
                    if(player->hand[i].rank == player->hand[j].rank &&
                       player->hand[j].rank == player->hand[k].rank &&
                       player->hand[k].rank == player->hand[l].rank) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0; 
}

int is_full_house(player_t *player) {
    int i, j, x=0, y=0;
    for(i=0; i<HAND_SIZE-2; i++) {
        for(j=i+1; j<HAND_SIZE-1; j++) {
            if(player->hand[i].rank == player->hand[j].rank) {
                x++;
            } else {
                y++;
            }
        }
    }
    if((x == 3 && y == 6) || (x == 6 && y == 3)) {
        return 1;
    } else {
        return 0;
    }
}

int is_flush(player_t *player) {
    int i;
    suit_t flush_suit = player->hand[0].suit;
    for(i=1; i<HAND_SIZE; i++) {
        if(player->hand[i].suit != flush_suit) {
            return 0;
        }
    }
    return 1;
}

int is_straight(player_t *player) {
    int i;
    for(i=0; i<HAND_SIZE-1; i++) {
        if(player->hand[i].rank + 1 != player->hand[i+1].rank) {
            return 0;
        }
    }
    return 1;
}

int is_straight_flush(player_t *player) {
    if(is_straight(player) && is_flush(player)) {
        return 1;
    } else {
        return 0;
    }
}

int is_royal_flush(player_t *player) {
    if(is_straight_flush(player) && player->hand[0].rank == ACE) {
        return 1;
    } else {
        return 0;
    }
}

int get_winning_hand(player_t *player) {
    if(is_royal_flush(player)) {
        return 10;
    } else if(is_straight_flush(player)) {
        return 9;
    } else if(is_four_of_a_kind(player)) {
        return 8;
    } else if(is_full_house(player)) {
        return 7;
    } else if(is_flush(player)) {
        return 6;
    } else if(is_straight(player)) {
        return 5;
    } else if(is_three_of_a_kind(player)) {
        return 4;
    } else if(is_two_pair(player)) {
        return 3;
    } else if(is_pair(player)) {
        return 2;
    } else {
        return 1;
    }
}

int get_winning_player(player_t *player1, player_t *player2) {
    int player1_rank, player2_rank;
    player1_rank = get_winning_hand(player1);
    player2_rank = get_winning_hand(player2);

    if(player1_rank != player2_rank) {
        return (player1_rank > player2_rank) ? 1 : 2;
    } else {
        sort_hand(player1);
        sort_hand(player2);
        
        int i;

        switch(player1_rank) {
            case 1:
                for(i=HAND_SIZE-1; i>=0; i--) {
                    if(player1->hand[i].rank != player2->hand[i].rank) {
                        return (player1->hand[i].rank > player2->hand[i].rank) ? 1 : 2;
                    }
                }
                return 0;
                
            case 2:
                for(i=0; i<HAND_SIZE; i++) {
                    if(player1->hand[i].rank != player2->hand[i].rank) {
                        return (player1->hand[i].rank > player2->hand[i].rank) ? 1 : 2;
                    }
                }
                return 0;
                
            case 3:
                for(i=HAND_SIZE-1; i>=0; i--) {
                    if(player1->hand[i].rank != player2->hand[i].rank) {
                        return (player1->hand[i].rank > player2->hand[i].rank) ? 1 : 2;
                    }
                }
                return 0;
                
            case 4:
            case 7:
                for(i=0; i<HAND_SIZE-2; i++) {
                    if(player1->hand[i].rank == player1->hand[i+1].rank &&
                       player1->hand[i+1].rank == player1->hand[i+2].rank) {
                        break;
                    }
                }
                for(; i<HAND_SIZE; i++) {
                    if(player1->hand[i].rank != player2->hand[i].rank) {
                        return (player1->hand[i].rank > player2->hand[i].rank) ? 1 : 2;
                    }
                }
                return 0;
                
            case 5:
                if(player1->hand[HAND_SIZE-1].rank != player2->hand[HAND_SIZE-1].rank) {
                    return (player1->hand[HAND_SIZE-1].rank > player2->hand[HAND_SIZE-1].rank) ? 1 : 2;
                } else {
                    return 0;
                }
                
            case 6:
            case 9:
            case 10:
                for(i=HAND_SIZE-1; i>=0; i--) {
                    if(player1->hand[i].rank != player2->hand[i].rank) {
                        return (player1->hand[i].rank > player2->hand[i].rank) ? 1 : 2;
                    }
                }
                return 0;
                
            case 8:
                for(i=0; i<HAND_SIZE-3; i++) {
                    if(player1->hand[i].rank == player1->hand[i+1].rank &&
                       player1->hand[i+1].rank == player1->hand[i+2].rank &&
                       player1->hand[i+2].rank == player1->hand[i+3].rank) {
                        break;
                    }
                }
                for(; i<HAND_SIZE; i++) {
                    if(player1->hand[i].rank != player2->hand[i].rank) {
                        return (player1->hand[i].rank > player2->hand[i].rank) ? 1 : 2;
                    }
                }
                return 0;
        }
    }
}

int main() {
    int i;
    srand(time(NULL));
    deck_t *deck = create_deck();
    player_t player1, player2;

    deal(deck, &player1);
    printf("Player 1's hand:\n");
    print_hand(&player1);
    printf("\n");

    deal(deck, &player2);
    printf("Player 2's hand:\n");
    print_hand(&player2);
    printf("\n");

    int discard_index = 0;
    printf("Which card would Player 1 like to discard? (Enter 1-5 or 0 to keep hand): ");
    scanf("%d", &discard_index);
    if(discard_index != 0) {
        discard(deck, &player1, discard_index-1);
        printf("Player 1's new hand:\n");
        print_hand(&player1);
        printf("\n");
    }
    
    discard_index = 0;
    printf("Which card would Player 2 like to discard? (Enter 1-5 or 0 to keep hand): ");
    scanf("%d", &discard_index);
    if(discard_index != 0) {
        discard(deck, &player2, discard_index-1);
        printf("Player 2's new hand:\n");
        print_hand(&player2);
        printf("\n");
    }

    int winning_player = get_winning_player(&player1, &player2);
    if(winning_player == 0) {
        printf("It's a tie!\n");
    } else {
        printf("Player %d won!\n", winning_player);
    }

    free(deck->cards);
    free(deck);
    return 0;
}