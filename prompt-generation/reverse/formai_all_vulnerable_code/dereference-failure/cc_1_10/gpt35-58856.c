//FormAI DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// ARRAY OF CHARACTERS FOR CARD VALUES
char values[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

// FUNCTION TO CREATE A NEW BOARD
int** new_board(int rows, int cols) {
    int **board = (int**)malloc(rows * sizeof(int*));
    for (int i=0; i<rows; i++) {
        board[i] = (int*)malloc(cols * sizeof(int));
        for (int j=0; j<cols; j++) {
            board[i][j] = 0;
        }
    }
    return board;
}

// FUNCTION TO DRAW THE BOARD
void draw_board(int** board, int rows, int cols) {
    printf("\n");
    printf("     Memory Game\n");
    printf("-------------------------\n");
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (board[i][j] == 0) {
                printf(" * ");
            } else {
                printf(" %c ", values[board[i][j]-1]);
            }
        }
        printf("\n");
    }
    printf("-------------------------\n\n");
}

// FUNCTION TO CHOOSE RANDOM CARD
int* random_card(int** board, int rows, int cols) {
    int* card = (int*)malloc(2*sizeof(int));
    int r, c;
    do {
        r = rand() % rows;
        c = rand() % cols;
    } while (board[r][c] != 0);
    card[0] = r;
    card[1] = c;
    return card;
}

// FUNCTION TO PLAY THE GAME
int play_game(int rows, int cols) {
    int **board = new_board(rows, cols);
    int num_cards = rows * cols;
    int* card1;
    int* card2;
    int attempts = 0;
    srand(time(NULL));
    
    // ADD CARDS TO BOARD IN RANDOM POSITIONS
    for (int i=0; i<num_cards/2; i++) {
        int count = 0;
        while (count < 2) {
            int r = rand() % rows;
            int c = rand() % cols;
            if (board[r][c] == 0) {
                board[r][c] = i+1;
                count++;
            }
        }
    }
    
    draw_board(board, rows, cols);
    
    while (1) {
        // GET TWO CHOSEN CARDS FROM USER
        printf("Enter card 1 row and column (ex. 1 2): ");
        int r1, c1;
        scanf("%d %d", &r1, &c1);
        card1 = (int*)malloc(2*sizeof(int));
        card1[0] = r1-1;
        card1[1] = c1-1;
        if (board[card1[0]][card1[1]] == -1) {
            printf("Sorry, that card is already taken. Please choose another.\n");
            continue;
        }
        board[card1[0]][card1[1]] = -1;
        draw_board(board, rows, cols);
        
        printf("Enter card 2 row and column (ex. 2 3): ");
        int r2, c2;
        scanf("%d %d", &r2, &c2);
        card2 = (int*)malloc(2*sizeof(int));
        card2[0] = r2-1;
        card2[1] = c2-1;
        if (board[card2[0]][card2[1]] == -1) {
            printf("Sorry, that card is already taken. Please choose another.\n");
            board[card1[0]][card1[1]] = 0;
            free(card1);
            continue;
        }
        board[card2[0]][card2[1]] = -1;
        draw_board(board, rows, cols);
        
        // CHECK IF CARDS MATCH
        if (board[card1[0]][card1[1]] == board[card2[0]][card2[1]]) {
            printf("Congratulations, you found a match!\n");
            board[card1[0]][card1[1]] = 0;
            board[card2[0]][card2[1]] = 0;
            free(card1);
            free(card2);
            num_cards -= 2;
        } else {
            printf("Sorry, those cards do not match.\n");
            usleep(1000000);
            board[card1[0]][card1[1]] = 0;
            board[card2[0]][card2[1]] = 0;
            free(card1);
            free(card2);
        }
        
        // CHECK IF GAME IS OVER
        if (num_cards == 0) {
            printf("Congratulations, you won!\n");
            printf("It took you %d attempts.\n", attempts);
            break;
        } else {
            attempts++;
        }
    }
    
    // FREE MEMORY AND RETURN
    for (int i=0; i<rows; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}

int main() {
    int rows, cols;
    printf("Welcome to the Memory Game!\n");
    printf("How many rows do you want the board to have? (4-6): ");
    scanf("%d", &rows);
    printf("How many columns do you want the board to have? (4-6): ");
    scanf("%d", &cols);
    if (rows < 4 || rows > 6 || cols < 4 || cols > 6) {
        printf("Invalid size. Please choose again.\n");
        return 1;
    }
    play_game(rows, cols);
    return 0;
}