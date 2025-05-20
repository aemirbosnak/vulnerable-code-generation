//FormAI DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void initializeGame(int** selection, int** board);
void playGame(int** selection, int** board);
void printBoard(int** board);
int checkForMatches(int** board, int x1, int y1, int x2, int y2);
void clearSelection(int** selection, int x1, int y1, int x2, int y2);

int main() {
    int** selection; // 2D array to store player's current selection
    int** board; // 2D array to store the game board

    // Dynamically allocate memory for selection and board arrays
    selection = (int**) malloc(sizeof(int*) * 2);
    for(int i=0; i<2; i++){
        selection[i] = (int*) malloc(sizeof(int) * 2);
    }

    board = (int**) malloc(sizeof(int*) * 4);
    for(int i=0; i<4; i++){
        board[i] = (int*) malloc(sizeof(int) * 4);
    }

    // Initialize game
    initializeGame(selection, board);

    // Play game
    playGame(selection, board);

    // Free memory
    for(int i=0; i<2; i++){
        free(selection[i]);
    }
    free(selection);

    for(int i=0; i<4; i++){
        free(board[i]);
    }
    free(board);

    return 0;
}

/**
 * initializeGame - Initializes the game board with numbers from 1 to 8
 *                  Each number appears twice on the board.
 * @selection: Pointer to 2D selection array
 * @board: Pointer to 2D board array
 */
void initializeGame(int** selection, int** board){
    int num_pairs = 8;
    int numbers[num_pairs*2];

    // Seed random number generator
    srand(time(NULL));

    // Populate numbers[] array with unique numbers
    for(int i=0; i<num_pairs*2; i++){
        numbers[i] = i+1;
    }

    // Shuffle numbers[] array
    for(int i=0; i<num_pairs*2-1; i++){
        int j = i + rand() % (num_pairs*2 - i);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Fill board[][] array with shuffled numbers
    int k = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            board[i][j] = numbers[k];
            k++;
        }
    }

    // Initialize selection[][] array to -1
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            selection[i][j] = -1;
        }
    }
}

/**
 * playGame - Main game loop
 * @selection: Pointer to 2D selection array
 * @board: Pointer to 2D board array
 */
void playGame(int** selection, int** board){
    int x1, y1, x2, y2;
    int num_matches = 0; // Counter for number of matches found

    while(num_matches != 8){
        printf("Enter the row and column for first selection: ");
        scanf("%d %d", &x1, &y1);

        printf("Enter the row and column for second selection: ");
        scanf("%d %d", &x2, &y2);

        // Check if selections are valid
        if(x1 < 0 || x1 > 3 || x2 < 0 || x2 > 3 || y1 < 0 || y1 > 3 || y2 < 0 || y2 > 3 || (x1==x2 && y1==y2)){
            printf("Invalid selection. Try again.\n");
            continue;
        }

        // Check if selections match
        if(checkForMatches(board, x1, y1, x2, y2)){
            printf("Match found!\n");
            num_matches++;
        }
        else{
            printf("No match found. Try again.\n");
            clearSelection(selection, x1, y1, x2, y2);
        }

        // Print current board state
        printBoard(board);
    }

    printf("Congratulations! You won the game!\n");
}

/**
 * printBoard - Prints the current state of the game board
 * @board: Pointer to 2D board array
 */
void printBoard(int** board){
    printf("    0   1   2   3\n");
    printf("-------------------\n");
    for(int i=0; i<4; i++){
        printf("%d | ", i);
        for(int j=0; j<4; j++){
            if(board[i][j] == -1){
                printf("    ");
            }
            else{
                printf("%2d  ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("-------------------\n");
}

/**
 * checkForMatches - Checks if the selections made by the player match
 * @board: Pointer to 2D board array
 * @x1: X-coordinate of first selection
 * @y1: Y-coordinate of first selection
 * @x2: X-coordinate of second selection
 * @y2: Y-coordinate of second selection
 *
 * Returns 1 if matches found, 0 if not.
 */
int checkForMatches(int** board, int x1, int y1, int x2, int y2){
    int num1 = board[x1][y1];
    int num2 = board[x2][y2];

    if(num1 == num2){
        board[x1][y1] = -1; // Mark numbers as removed from board
        board[x2][y2] = -1;
        return 1;
    }
    else{
        return 0;
    }
}

/**
 * clearSelection - Clears the player's current selection
 * @selection: Pointer to 2D selection array
 * @x1: X-coordinate of first selection
 * @y1: Y-coordinate of first selection
 * @x2: X-coordinate of second selection
 * @y2: Y-coordinate of second selection
 */
void clearSelection(int** selection, int x1, int y1, int x2, int y2){
    selection[0][0] = -1;
    selection[0][1] = -1;
    selection[1][0] = -1;
    selection[1][1] = -1;
}