//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int main() {
    // Initialize the game board
    int board[BOARD_SIZE][BOARD_SIZE] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };

    // Create a linked list to store the moves of the AI
    Node* moves = NULL;

    // Seed the random number generator
    srand(time(NULL));

    // The AI's turn
    int aiMove = rand() % 9;

    // Make the AI's move
    board[aiMove / BOARD_SIZE][aiMove % BOARD_SIZE] = PLAYER_O;

    // Insert the move into the linked list
    insertAtTail(moves, aiMove);

    // The player's turn
    int playerMove;

    // Get the player's move
    printf("Enter your move (0-8): ");
    scanf("%d", &playerMove);

    // Check if the player's move is valid
    if (board[playerMove / BOARD_SIZE][playerMove % BOARD_SIZE] != 0) {
        printf("Invalid move.\n");
        return 1;
    }

    // Make the player's move
    board[playerMove / BOARD_SIZE][playerMove % BOARD_SIZE] = PLAYER_X;

    // Insert the move into the linked list
    insertAtTail(moves, playerMove);

    // Check if the player has won
    if (board[0][0] == PLAYER_X || board[0][1] == PLAYER_X || board[0][2] == PLAYER_X ||
        board[1][0] == PLAYER_X || board[1][1] == PLAYER_X || board[1][2] == PLAYER_X ||
        board[2][0] == PLAYER_X || board[2][1] == PLAYER_X || board[2][2] == PLAYER_X) {
        printf("You have won!\n");
    } else if (moves == NULL) {
        printf("It's a draw.\n");
    } else {
        printf("The AI has won!\n");
    }

    return 0;
}