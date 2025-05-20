//FormAI DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 4

void initialize(char array[SIZE][SIZE], char symbol);
void display(char array[SIZE][SIZE]);
void play(char array[SIZE][SIZE]);

int main()
{
    char array[SIZE][SIZE];

    srand(time(0));
    initialize(array, '-');
    play(array);

    return 0;
}

void initialize(char array[SIZE][SIZE], char symbol)
{
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            array[i][j] = symbol;
        }
    }
}

void display(char array[SIZE][SIZE])
{
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

void play(char array[SIZE][SIZE])
{
    int i, j, x1, y1, x2, y2, found_pairs = 0, attempts = 0;
    char symbol = 'A', temp;

    while(found_pairs < SIZE*SIZE/2)
    {
        // Display the current state of the game
        system("cls");
        display(array);

        // Read the first cell
        printf("Try to find a pair of symbols.\n");
        printf("Enter the coordinates of the first cell (row column): ");
        scanf("%d%d", &x1, &y1);

        if(x1 >= SIZE || y1 >= SIZE || array[x1][y1] != '-')
        {
            printf("Invalid cell.\n");
            continue;
        }

        // Show the symbol in the first cell
        array[x1][y1] = symbol;

        // Display the updated state of the game
        system("cls");
        display(array);

        // Read the second cell
        printf("Try to find a pair of symbols.\n");
        printf("Enter the coordinates of the second cell (row column): ");
        scanf("%d%d", &x2, &y2);

        if(x2 >= SIZE || y2 >= SIZE || array[x2][y2] != '-')
        {
            // Hide the symbol in the first cell
            array[x1][y1] = '-';
            printf("Invalid cell.\n");
            continue;
        }

        // Show the symbol in the second cell
        array[x2][y2] = symbol;

        // Display the updated state of the game
        system("cls");
        display(array);
        attempts++;

        if(array[x1][y1] != array[x2][y2])
        {
            // Hide the symbols if they don't match
            array[x1][y1] = '-';
            array[x2][y2] = '-';

            printf("No match.\n");
        }
        else
        {
            found_pairs++;
            printf("Match found.\n");
        }

        // Increment the symbol
        symbol++;

        // Wait a bit before clearing the screen
        temp = getchar();
        temp = getchar();
    }

    printf("Congratulations! You found all the pairs in %d attempts.\n", attempts);
}