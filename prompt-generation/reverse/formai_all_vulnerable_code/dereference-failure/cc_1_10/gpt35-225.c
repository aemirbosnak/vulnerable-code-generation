//FormAI DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CARDS 20
#define MAX_NAME_LENGTH 20

typedef struct {
    int value;
    int revealed;
} Card;

void reset_game(Card* cards, int* counts, int num_cards);
int is_game_over(Card* cards, int num_cards);
void print_board(Card* cards, int num_cards);
int get_card_value(Card* cards, int num_cards, int selected_card);
void reveal_card(Card* cards, int num_cards, int selected_card);
void hide_cards(Card* cards, int num_cards, int first_card, int second_card);

int main() {
    srand(time(NULL));
    char player_name[MAX_NAME_LENGTH];
    printf("Welcome to the Memory Game! Enter your name: ");
    fgets(player_name, MAX_NAME_LENGTH, stdin);
    player_name[strcspn(player_name, "\n")] = 0; // Remove newline character from fgets input
    printf("Hello, %s!\n", player_name);
  
    int num_cards;
    printf("Select the number of cards to play with (max %d): ", MAX_CARDS);
    scanf("%d", &num_cards);
    getchar(); // Consume newline character from scanf input
  
    if (num_cards > MAX_CARDS) {
        printf("Error: Number of cards is too high. Setting number of cards to %d.\n", MAX_CARDS);
        num_cards = MAX_CARDS;
    } else if (num_cards < 2) {
        printf("Error: Number of cards is too low. Setting number of cards to 2.\n");
        num_cards = 2;
    }
  
    int total_pairs = num_cards / 2;
    Card* cards = (Card*)calloc(num_cards, sizeof(Card));
    int* counts = (int*)calloc(num_cards, sizeof(int));
  
    reset_game(cards, counts, num_cards);
  
    int score = 0;
    int attempts = 0;
  
    while (!is_game_over(cards, num_cards)) {
        print_board(cards, num_cards);
      
        int first_card;
        printf("Enter the number of the first card to flip over: ");
        scanf("%d", &first_card);
        getchar(); // Consume newline character from scanf input
      
        while (first_card < 1 || first_card > num_cards || cards[first_card - 1].revealed || counts[first_card - 1] >= 2) {
            printf("Invalid selection. Please try again.\n");
            printf("Enter the number of the first card to flip over: ");
            scanf("%d", &first_card);
            getchar(); // Consume newline character from scanf input
        }
      
        reveal_card(cards, num_cards, first_card);
        print_board(cards, num_cards);
      
        int second_card;
        printf("Enter the number of the second card to flip over: ");
        scanf("%d", &second_card);
        getchar(); // Consume newline character from scanf input
      
        while (second_card == first_card || second_card < 1 || second_card > num_cards || cards[second_card - 1].revealed || counts[second_card - 1] >= 2) {
            printf("Invalid selection. Please try again.\n");
            printf("Enter the number of the second card to flip over: ");
            scanf("%d", &second_card);
            getchar(); // Consume newline character from scanf input
        }
      
        reveal_card(cards, num_cards, second_card);
        print_board(cards, num_cards);
      
        int first_card_value = get_card_value(cards, num_cards, first_card);
        int second_card_value = get_card_value(cards, num_cards, second_card);
      
        if (first_card_value == second_card_value) {
            printf("You found a match!\n");
            counts[first_card - 1]++;
            counts[second_card - 1]++;
            score++;
        } else {
            printf("Sorry, no match...\n");
            hide_cards(cards, num_cards, first_card, second_card);
        }
      
        attempts++;
    }
  
    printf("\nCongratulations, %s! You found all %d pairs in %d attempts!\n", player_name, total_pairs, attempts);
    printf("Final score: %d\n", score);
  
    free(cards);
    free(counts);
  
    return 0;
}

void reset_game(Card* cards, int* counts, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        cards[i].value = i / 2;
        cards[i].revealed = 0;
        counts[i] = 0;
    }
  
    for (int i = num_cards - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

int is_game_over(Card* cards, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        if (cards[i].revealed == 0) {
            return 0;
        }
    }
  
    return 1;
}

void print_board(Card* cards, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        if (cards[i].revealed) {
            printf("%d ", cards[i].value);
        } else {
            printf("* ");
        }
    }
  
    printf("\n");
}

int get_card_value(Card* cards, int num_cards, int selected_card) {
    return cards[selected_card - 1].value;
}

void reveal_card(Card* cards, int num_cards, int selected_card) {
    cards[selected_card - 1].revealed = 1;
}

void hide_cards(Card* cards, int num_cards, int first_card, int second_card) {
    cards[first_card - 1].revealed = 0;
    cards[second_card - 1].revealed = 0;
}