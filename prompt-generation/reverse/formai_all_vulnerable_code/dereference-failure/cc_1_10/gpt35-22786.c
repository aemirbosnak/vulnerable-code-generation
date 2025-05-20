//FormAI DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function declarations
void initialize_board(int** board, int rows, int cols);
void shuffle(int* array, int size);
void print_board(int** board, int rows, int cols);
int choose_card(int** board, int rows, int cols, int* guessed_cards);
int check_match(int** board, int rows, int cols, int card1, int card2);

int main(){

    //Initialize random generator
    srand(time(NULL));

    //Game setup
    const int ROWS = 4;
    const int COLS = 4;
    int** board = malloc(ROWS*sizeof(int*));
    for(int i=0; i<ROWS; i++){
        board[i] = malloc(COLS*sizeof(int));
    }

    initialize_board(board, ROWS, COLS);
    int* guessed_cards = malloc(2*sizeof(int));
    guessed_cards[0] = -1; //Initialize guessed_cards array to invalid indices.
    guessed_cards[1] = -1;

    printf("Welcome to the Memory Game, Sherlock Holmes style! Your task is to match pairs of cards with faces of famous literary detectives.\n");
    printf("The board size is %d x %d, you will have to choose two cards per turn. Good luck!\n", ROWS, COLS);
    printf("Here is the initial board:\n");

    print_board(board, ROWS, COLS);

    //Game loop
    int num_pairs_found = 0;
    while(num_pairs_found < ROWS*COLS/2){
        int card1 = choose_card(board, ROWS, COLS, guessed_cards);
        guessed_cards[0] = card1;

        printf("First card chosen, its identity is: %d\n", board[card1/ROWS][card1%COLS]);

        int card2 = choose_card(board, ROWS, COLS, guessed_cards);
        guessed_cards[1] = card2;

        printf("Second card chosen, its identity is: %d\n", board[card2/ROWS][card2%COLS]);

        int match_result = check_match(board, ROWS, COLS, card1, card2);
        if(match_result){
            printf("Congratulations, you found a pair of detectives!\n");

            num_pairs_found++;
            guessed_cards[0] = -1;
            guessed_cards[1] = -1;
        }
        else{
            printf("Sorry, no match this time, keep searching!\n");

            //Show the previous board state
            print_board(board, ROWS, COLS);

            //Hide the chosen cards
            board[card1/ROWS][card1%COLS] = -1;
            board[card2/ROWS][card2%COLS] = -1;
        }
    }

    //Game over message
    printf("Congratulations, %d pairs found, you won the game, Sherlock Holmes would be proud of you!\n", num_pairs_found);

    //Free allocated memory
    for(int i=0; i<ROWS; i++){
        free(board[i]);
    }
    free(board);
    free(guessed_cards);

    return 0;
}

void initialize_board(int** board, int rows, int cols){
    //Create array with pairs of cards
    int num_pairs = rows*cols/2;
    int* pairs = malloc(num_pairs*sizeof(int));
    for(int i=0; i<num_pairs; i++){
        pairs[i] = i;
    }
    shuffle(pairs, num_pairs);

    //Fill board with pairs
    int index = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            board[i][j] = pairs[index%num_pairs];
            index++;
        }
    }

    //Free allocated memory
    free(pairs);
}

void shuffle(int* array, int size){
    for(int i=0; i<size; i++){
        int j = rand()%size;

        //Swap elements i and j
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void print_board(int** board, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(board[i][j] == -1){
                printf(" XX ");
            }
            else{
                printf(" %d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int choose_card(int** board, int rows, int cols, int* guessed_cards){
    int chosen_card = -1;

    while(chosen_card==-1){
        //Randomly choose a card
        chosen_card = rand()%(rows*cols);

        //Check if card is not already found and not already guessed
        if(board[chosen_card/rows][chosen_card%cols]!=-1 &&
           (chosen_card!=guessed_cards[0] && chosen_card!=guessed_cards[1])){
            return chosen_card;
        }
        //If chosen card is not valid, reset its value to -1 and try again
        else{
            chosen_card = -1;
        }
    }

    return chosen_card;
}

int check_match(int** board, int rows, int cols, int card1, int card2){
    return (board[card1/rows][card1%cols] == board[card2/rows][card2%cols]);
}