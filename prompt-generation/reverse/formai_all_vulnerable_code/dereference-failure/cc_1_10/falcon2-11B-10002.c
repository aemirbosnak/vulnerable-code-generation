//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Card {
    char suit;
    char value;
} Card;

typedef struct Deck {
    Card cards[52];
    int top;
} Deck;

typedef struct Player {
    int hand[5];
    int points;
} Player;

Deck* deck_init() {
    Deck* deck = (Deck*) malloc(sizeof(Deck));
    for (int i = 0; i < 52; i++) {
        deck->cards[i].suit = 'h';
        deck->cards[i].value = 'A' + i % 13;
    }
    deck->top = -1;
    return deck;
}

void deck_shuffle(Deck* deck) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void deck_deal(Deck* deck, Player* player) {
    for (int i = 0; i < 5; i++) {
        if (deck->top < 52) {
            player->hand[i] = deck->cards[deck->top].value;
            deck->top++;
        } else {
            printf("No more cards to deal.\n");
            break;
        }
    }
}

void print_hand(Player* player) {
    printf("Player %d's hand: ", player->points);
    for (int i = 0; i < 5; i++) {
        printf("%c ", player->hand[i]);
    }
    printf("\n");
}

void player_score(Player* player) {
    int ace_points = 1;
    int straight_flush_points = 8;
    int four_of_a_kind_points = 6;
    int full_house_points = 3;
    int flush_points = 2;
    int straight_points = 4;
    int three_of_a_kind_points = 3;
    int two_pair_points = 2;
    int pair_points = 1;

    for (int i = 0; i < 5; i++) {
        if (player->hand[i] == 'A') {
            ace_points = 11;
        }
    }

    int highest_card = player->hand[0];
    int highest_card_value = (highest_card - 'A') + 1;
    int second_highest_card = player->hand[1];
    int second_highest_card_value = (second_highest_card - 'A') + 1;
    int third_highest_card = player->hand[2];
    int third_highest_card_value = (third_highest_card - 'A') + 1;
    int fourth_highest_card = player->hand[3];
    int fourth_highest_card_value = (fourth_highest_card - 'A') + 1;
    int fifth_highest_card = player->hand[4];
    int fifth_highest_card_value = (fifth_highest_card - 'A') + 1;

    if (player->hand[0] == player->hand[1] && player->hand[2] == player->hand[3] && player->hand[4] == player->hand[5]) {
        player->points += four_of_a_kind_points;
    } else if (player->hand[0] == player->hand[1] || player->hand[2] == player->hand[3] || player->hand[4] == player->hand[5]) {
        player->points += three_of_a_kind_points;
    } else if (player->hand[0] == player->hand[1] || player->hand[2] == player->hand[3] || player->hand[4] == player->hand[5]) {
        player->points += two_pair_points;
    } else if (player->hand[0] == player->hand[1] || player->hand[2] == player->hand[3] || player->hand[4] == player->hand[5]) {
        player->points += pair_points;
    } else if (highest_card_value == second_highest_card_value || second_highest_card_value == third_highest_card_value || third_highest_card_value == fourth_highest_card_value || fourth_highest_card_value == fifth_highest_card_value) {
        player->points += straight_points;
    } else if (highest_card_value == second_highest_card_value || second_highest_card_value == third_highest_card_value || third_highest_card_value == fourth_highest_card_value || fourth_highest_card_value == fifth_highest_card_value || fifth_highest_card_value == highest_card_value) {
        player->points += flush_points;
    } else if (highest_card_value == second_highest_card_value || second_highest_card_value == third_highest_card_value || third_highest_card_value == fourth_highest_card_value || fourth_highest_card_value == fifth_highest_card_value) {
        player->points += straight_flush_points;
    } else if (player->hand[0] == 'A') {
        player->points += ace_points;
    }

    printf("Player %d's score: %d\n", player->points, player->points);
}

int main() {
    Deck* deck = deck_init();
    deck_shuffle(deck);
    Player* player = (Player*) malloc(sizeof(Player));
    deck_deal(deck, player);
    print_hand(player);
    player_score(player);
    return 0;
}