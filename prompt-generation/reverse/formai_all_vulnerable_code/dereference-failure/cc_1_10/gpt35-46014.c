//FormAI DATASET v1.0 Category: Memory Game ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//function prototypes
void printGameBoard(int *gameBoard, int size);
int *createGameBoard(int size);
void shuffleGameBoard(int *gameBoard, int size);
int validateChoice(int *gameBoard, int *flippedCards, int choice1, int choice2);
void updateFlippedCards(int *flippedCards, int choice1, int choice2);

int main(){
    int size = 4; // size of the game board, can be customized
    int *gameBoard = createGameBoard(size); // create game board
    int *flippedCards = (int*) calloc(size*size, sizeof(int)); //create array to store flipped cards
    int gameOver = 0; //flag for game over
    while(!gameOver){
        printGameBoard(gameBoard, size); //print current game board
        int choice1 = 0, choice2 = 0; //initialize card choices to 0
        while(choice1 == 0){ //loop to get first card choice
            printf("Enter the row and column of the first card to flip: ");
            scanf("%d %d", &choice1, &choice2);
            if(flippedCards[(choice1-1) * size + (choice2-1)] != 0){ //check if card already flipped
                printf("This card has already been flipped.\n");
                choice1 = 0; //reset choice
            }
        }
        int result = validateChoice(gameBoard, flippedCards, choice1, choice2); //check if first card choice is correct
        if(result == 0){ //if incorrect, show feedback and end turn
            printf("Incorrect match!\n");
            updateFlippedCards(flippedCards, choice1, choice2); //flip cards back
        } else { //if correct, store flipped cards and check for game over
            updateFlippedCards(flippedCards, choice1, choice2);
            int gameWon = 1; //flag for game won
            for(int i = 0; i < size*size; i++){ //check all cards to see if game is won
                if(flippedCards[i] == 0){
                    gameWon = 0;
                    break;
                }
            }
            if(gameWon){ // if game won, end game
                printGameBoard(gameBoard, size);
                printf("Congratulations! You have won the game!\n");
                gameOver = 1;
            }
        }
    }
    free(gameBoard); //free memory
    free(flippedCards);
    return 0;
}

//function to create the initial game board
int *createGameBoard(int size){
    int *gameBoard = (int*) malloc(size*size*sizeof(int)); //allocate memory for game board
    for(int i = 0; i < size*size; i+=2){ //populate each pair of cards with numbers 1 to size^2/2 in random order
        gameBoard[i] = (i/2)+1;
        gameBoard[i+1] = (i/2)+1;
    }
    shuffleGameBoard(gameBoard, size*size); //shuffle the game board
    return gameBoard;
}

//function to shuffle the game board
void shuffleGameBoard(int *gameBoard, int size){
    srand(time(NULL)); //initialize random seed
    for(int i = 0; i < size; i++){ //loop through game board array and swap each card with another random card
        int randomIdx = rand() % size;
        int temp = gameBoard[i];
        gameBoard[i] = gameBoard[randomIdx];
        gameBoard[randomIdx] = temp;
    }
}

//function to print the game board
void printGameBoard(int *gameBoard, int size){
    for(int i = 0; i < size*size; i++){ //loop through game board array and print each card
        if(gameBoard[i] == 0){ //if card is flipped over, print X
            printf("[X] ");
        } else { //if card is still facing down, print card number
            printf("[%d] ", gameBoard[i]);
        }
        if((i+1) % size == 0){ //print new line after each row
            printf("\n");
        }
    }
}

//function to validate choice and return result
int validateChoice(int *gameBoard, int *flippedCards, int choice1, int choice2){
    int card1 = gameBoard[(choice1-1) * ((choice2-1) +1) -1]; //calculate index of first card
    int card2 = gameBoard[(choice1-1) * ((choice2-1) +1)]; //calculate index of second card
    if(flippedCards[(choice1-1) * ((choice2-1) +1) -1] != 0 || flippedCards[(choice1-1) * ((choice2-1) +1)] != 0){ //if either card is already flipped, return error
        printf("This card has already been flipped.\n");
        return 0;
    }
    if(card1 == card2){ //if cards match, return success
        printf("Match Found!\n");
        return 1;
    }
    //otherwise return failure
    printf("No match found.\n");
    return 0;
}

//function to flip cards back facedown
void updateFlippedCards(int *flippedCards, int choice1, int choice2){
    flippedCards[(choice1-1) * ((choice2-1) +1) -1] = 0;
    flippedCards[(choice1-1) * ((choice2-1) +1)] = 0;
}