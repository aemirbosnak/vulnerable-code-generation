//FormAI DATASET v1.0 Category: Memory Game ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h> 
#include<time.h> 

#define ROWS 4
#define COLUMNS 4
#define TOTAL_CARDS 16

const char cards[TOTAL_CARDS/2] = {'A','B','C','D'};

enum gameStatus{CONTINUE, WIN, TIE};
typedef struct {
   int row;
   int column;
}Card;

//Function prototypes
void welcomeMessage();
char** createBoard();
void shuffleDeck(Card*);
void printBoard(char**);
enum gameStatus gameWon(char**, int, int);

int main(){
   int currentPlayer = 0;
   int totalPlayers = 1;
   char** board = NULL;
   Card* deck = NULL;
   int rows[TOTAL_CARDS] = {0};
   int columns[TOTAL_CARDS] = {0};
   int selectedCards[TOTAL_CARDS] = {0};
   int matchedCards = 0;
   int totalCardsSelected = 0;
   int playerPoints[totalPlayers];
   int gameLoop = 1;
   int flipAgain = 0;
   
   //Initialize scores to 0 
   for(int i=0;i<totalPlayers;i++){
      playerPoints[i] = 0;
   }
  
   //Initialize card deck and shuffle it
   deck = (Card*) malloc(TOTAL_CARDS*sizeof(Card));
    
   for(int i = 0; i < TOTAL_CARDS; i++){
      deck[i].row = -1;
      deck[i].column = -1;
   }

   for(int i = 0; i < TOTAL_CARDS/2 ; i++){
      deck[2*i].row = i/COLUMNS;
      deck[2*i].column = i%COLUMNS;
      deck[2*i+1].row = i/COLUMNS;
      deck[2*i+1].column = i%COLUMNS + COLUMNS;
   }

   srand(time(NULL)); 
   shuffleDeck(deck);

   welcomeMessage();
   board = createBoard();

   while(gameLoop){    
      printf("Player %d's turn \n", currentPlayer+1);
      printBoard(board);

      //Select cards with valid input
      do{
         printf("Select card (row,column): ");
         scanf("%d,%d",&rows[totalCardsSelected], &columns[totalCardsSelected]);
         rows[totalCardsSelected]--;
         columns[totalCardsSelected]--;
      } while(rows[totalCardsSelected] < 0 || rows[totalCardsSelected] >= ROWS || columns[totalCardsSelected] < 0 || columns[totalCardsSelected] >= COLUMNS || selectedCards[rows[totalCardsSelected]*COLUMNS+columns[totalCardsSelected]]==1);
     totalCardsSelected++;

     printf("\n");

     //Flip and print selected cards
     for(int i=0;i<totalCardsSelected;i++){
         board[rows[i]][columns[i]] = cards[deck[rows[i]*COLUMNS+columns[i]].column%COLUMNS];
         printf("%c\t",board[rows[i]][columns[i]]);
     }
     printf("\n");
     // check if the cards matched or not
     if(board[rows[0]][columns[0]] == board[rows[1]][columns[1]]){
         playerPoints[currentPlayer]++;
         matchedCards+=2;
         printf("Cards Matched! Player %d scores.\n", currentPlayer+1);
         if(matchedCards == TOTAL_CARDS){
            printf("\nAll Cards matched.\n");
            gameLoop = 0;
            break;
         }
         flipAgain = 1;
     } else{
        flipAgain = 0;
     }
     //If not flip again then change the current player
     if(!flipAgain){
         currentPlayer = (currentPlayer+1)%totalPlayers;
         printf("\nCards Not Matched. Player %d's turn\n", currentPlayer+1);
         for(int i=0;i<totalCardsSelected;i++){
            board[rows[i]][columns[i]] = '*';
            selectedCards[rows[i]*COLUMNS+columns[i]] = 1;
         }
    }
     printf("\n");
  }
   printf("\nGame Over!\n");
   //Print final scores
   for(int i=0;i<totalPlayers;i++){
      printf("Player %d: %d\n", i+1, playerPoints[i]);
   }
   //Free memory
   for(int i=0;i<ROWS;i++){
      free(board[i]);
   }
   free(board);
   free(deck);
   return 0;
}

void shuffleDeck(Card* d){
    int tempRow, tempCol;
    Card tempC;
    int index1, index2;

  for(int i=0;i<20;i++){
      index1 = rand()% TOTAL_CARDS;
      index2 = rand()% TOTAL_CARDS;

      tempRow = d[index1].row;
      tempCol = d[index1].column;

      d[index1].row = d[index2].row;
      d[index1].column = d[index2].column;

      d[index2].row = tempRow;
      d[index2].column = tempCol;
   }
}

char** createBoard(){
   char** board = NULL;
   board = (char**) malloc(ROWS*sizeof(char*));
   for(int i=0;i<ROWS;i++){
      board[i] = (char*) malloc(COLUMNS*sizeof(char));
   }
   for(int i=0;i<ROWS;i++){
      for(int j=0;j<COLUMNS;j++){
         board[i][j] = '*';
      }
   }
   return board;
}

void printBoard(char** board){
   for(int i=0;i<COLUMNS;i++){
      printf("----");
   }
   printf("-\n");
   for(int i=0;i<ROWS;i++){
      for(int j=0;j<COLUMNS;j++){
         printf("| %c ",board[i][j]);
      }
      printf("|\n");
      for(int i=0;i<COLUMNS;i++){
         printf("----");
      }
      printf("-\n");
   }   
}

void welcomeMessage(){
   printf("\n--WELCOME TO MEMORY GAME--\n\n");
   printf("-----GAME RULES:-----\n");
   printf("1. A player selects two cards per turn.\n");
   printf("2. If these two cards match, the player scores a point.\n");
   printf("3. The game ends when all cards are matched.\n");
   printf("4. The player with the maximum number of cards matched is the winner.\n\n");
}

enum gameStatus gameWon(char** board, int rowsLeft, int colsLeft){
    int matchFlag = 0;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            if(board[i][j] != '*'){
                matchFlag = 0;
                for(int k = 0; k < ROWS; k++){
                    for(int l = 0; l < COLUMNS; l++){
                        if(board[i][j] == board[k][l] && i != k && j != l){
                            matchFlag = 1;
                        }
                    }
                }
                if(matchFlag == 0){
                    rowsLeft--;
                    colsLeft--;
                }
            }
        }
    }
    if(rowsLeft == 0 || colsLeft == 0){
        return WIN;
    }
   return CONTINUE; 
}