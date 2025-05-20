//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePixelArt(int rows, int columns, char* grid[]);
void displayPixelArt(int rows, int columns, char* grid[]);
void getUserInput(int rows, int columns, char* grid[]);

int main()
{
    int rows = 10;
    int columns = 10;
    char grid[rows][columns];

    srand(time(NULL)); // seed random number generator
    generatePixelArt(rows, columns, grid);
    displayPixelArt(rows, columns, grid);
    getUserInput(rows, columns, grid);

    return 0;
}

void generatePixelArt(int rows, int columns, char* grid[])
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            grid[i][j] = 'a' + rand() % 10; // generate random character between a and j
        }
    }
}

void displayPixelArt(int rows, int columns, char* grid[])
{
    printf("\nPixel Art:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void getUserInput(int rows, int columns, char* grid[])
{
    int row, column;
    printf("Enter row and column for character (0-%d, 0-%d): ", rows-1, columns-1);
    scanf("%d %d", &row, &column);
    if (row < 0 || row >= rows || column < 0 || column >= columns) {
        printf("Invalid input. Please try again.\n");
        getUserInput(rows, columns, grid);
    } else {
        printf("Enter desired character (a-j): ");
        char ch;
        scanf("%c", &ch);
        grid[row][column] = ch;
        displayPixelArt(rows, columns, grid);
    }
}