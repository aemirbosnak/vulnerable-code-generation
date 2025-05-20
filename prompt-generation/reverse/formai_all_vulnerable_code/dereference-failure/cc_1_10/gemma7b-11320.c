//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

typedef struct BingoCard
{
    int numbers[ MAX_NUM ];
    int numCards;
    int cardsWon;
} BingoCard;

BingoCard *createBingoCard( int numCards )
{
    BingoCard *card = malloc( sizeof(BingoCard) );
    card->numCards = numCards;
    card->cardsWon = 0;
    for( int i = 0; i < MAX_NUM; i++ )
    {
        card->numbers[ i ] = 0;
    }
    return card;
}

void getRandomNumber( BingoCard *card )
{
    int num = rand() % MAX_NUM;
    if( card->numbers[ num ] == 0 )
    {
        card->numbers[ num ] = 1;
    }
}

void checkBingo( BingoCard *card )
{
    int bingo = 0;
    for( int row = 0; row < card->numCards; row++ )
    {
        for( int col = 0; col < MAX_NUM; col++ )
        {
            if( card->numbers[ col ] == 1 && card->numbers[ col ] == card->numbers[ row ] )
            {
                bingo = 1;
            }
        }
    }
    if( bingo )
    {
        card->cardsWon++;
    }
}

int main()
{
    srand( time( NULL ) );
    BingoCard *card = createBingoCard( 5 );
    for( int i = 0; i < 20; i++ )
    {
        getRandomNumber( card );
        checkBingo( card );
    }
    printf( "Number of cards won: %d\n", card->cardsWon );
    return 0;
}