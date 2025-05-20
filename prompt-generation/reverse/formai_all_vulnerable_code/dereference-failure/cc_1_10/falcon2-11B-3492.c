//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Player object
typedef struct {
    int cards[5];
    int points;
} Player;

// Deck object
typedef struct {
    int cards[52];
    int top;
} Deck;

// Game object
typedef struct {
    Deck deck;
    int game_over;
} Game;

// Global variables
Player players[2];
Game game;

void shuffle_deck(Deck *deck) {
    // shuffle the deck using surrealist algorithm
    int i, j;
    for (i = deck->top - 1; i >= 0; i--) {
        j = rand() % (i + 1);
        int temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
    deck->top = 0;
}

void deal_cards(Game *game) {
    int i;
    for (i = 0; i < 5; i++) {
        players[game->deck.top % 2].cards[i] = game->deck.cards[i];
        game->deck.top++;
    }
}

void score_cards(Player *player) {
    int score = 0;
    int straight_flush = 0;
    int flush = 0;
    int straight = 0;
    int four_of_a_kind = 0;
    int full_house = 0;
    int three_of_a_kind = 0;
    int two_pair = 0;
    int one_pair = 0;
    int high_card = 0;

    for (int i = 0; i < 5; i++) {
        if (player->cards[i] == player->cards[i + 1]) {
            if (player->cards[i + 1] == player->cards[i + 2]) {
                if (player->cards[i + 2] == player->cards[i + 3]) {
                    if (player->cards[i + 3] == player->cards[i + 4]) {
                        if (player->cards[i + 4] == player->cards[i]) {
                            straight_flush = 1;
                        }
                    }
                }
            }
        } else {
            if (player->cards[i + 1] == player->cards[i + 2]) {
                if (player->cards[i + 2] == player->cards[i + 3]) {
                    if (player->cards[i + 3] == player->cards[i + 4]) {
                        if (player->cards[i + 4] == player->cards[i]) {
                            flush = 1;
                        }
                    }
                }
            } else {
                if (player->cards[i + 1] == player->cards[i + 2]) {
                    if (player->cards[i + 2] == player->cards[i + 3]) {
                        if (player->cards[i + 3] == player->cards[i + 4]) {
                            if (player->cards[i + 4] == player->cards[i]) {
                                straight = 1;
                            }
                        }
                    }
                } else {
                    if (player->cards[i + 1] == player->cards[i + 2]) {
                        if (player->cards[i + 2] == player->cards[i + 3]) {
                            if (player->cards[i + 3] == player->cards[i + 4]) {
                                if (player->cards[i + 4] == player->cards[i]) {
                                    four_of_a_kind = 1;
                                }
                            }
                        }
                    } else {
                        if (player->cards[i + 1] == player->cards[i + 2]) {
                            if (player->cards[i + 2] == player->cards[i + 3]) {
                                if (player->cards[i + 3] == player->cards[i + 4]) {
                                    if (player->cards[i + 4] == player->cards[i]) {
                                        full_house = 1;
                                    }
                                }
                            }
                        } else {
                            if (player->cards[i + 1] == player->cards[i + 2]) {
                                if (player->cards[i + 2] == player->cards[i + 3]) {
                                    if (player->cards[i + 3] == player->cards[i + 4]) {
                                        if (player->cards[i + 4] == player->cards[i]) {
                                            three_of_a_kind = 1;
                                        }
                                    }
                                }
                            } else {
                                if (player->cards[i + 1] == player->cards[i + 2]) {
                                    if (player->cards[i + 2] == player->cards[i + 3]) {
                                        if (player->cards[i + 3] == player->cards[i + 4]) {
                                            if (player->cards[i + 4] == player->cards[i]) {
                                                two_pair = 1;
                                            }
                                        }
                                    } else {
                                        if (player->cards[i + 1] == player->cards[i + 2]) {
                                            if (player->cards[i + 2] == player->cards[i + 3]) {
                                                if (player->cards[i + 3] == player->cards[i + 4]) {
                                                    if (player->cards[i + 4] == player->cards[i]) {
                                                        one_pair = 1;
                                                    }
                                                }
                                            } else {
                                                if (player->cards[i + 1] == player->cards[i + 2]) {
                                                    if (player->cards[i + 2] == player->cards[i + 3]) {
                                                        if (player->cards[i + 3] == player->cards[i + 4]) {
                                                            if (player->cards[i + 4] == player->cards[i]) {
                                                                high_card = 1;
                                                            }
                                                        }
                                                    } else {
                                                        high_card = 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (straight_flush == 1) {
        score = 10;
    } else if (flush == 1) {
        score = 5;
    } else if (straight == 1) {
        score = 4;
    } else if (four_of_a_kind == 1) {
        score = 3;
    } else if (full_house == 1) {
        score = 2;
    } else if (three_of_a_kind == 1) {
        score = 1;
    } else if (two_pair == 1) {
        score = 0.5;
    } else if (one_pair == 1) {
        score = 0.25;
    } else {
        score = 0;
    }

    players[player->cards[0] % 2].points = score;
}

void print_player_info(Player *player) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("%c ", player->cards[i] + 'A');
    }
    printf("Points: %d\n", player->points);
}

void print_game_info(Game *game) {
    printf("Game: %s\n", game->game_over? "OVER" : "NOT OVER");
}

void play_poker() {
    int i;
    for (i = 0; i < 2; i++) {
        shuffle_deck(&game.deck);
        deal_cards(&game);
        print_player_info(players + i);
        score_cards(players + i);
        print_player_info(players + i);
    }
    print_game_info(&game);
}

int main() {
    play_poker();
    return 0;
}