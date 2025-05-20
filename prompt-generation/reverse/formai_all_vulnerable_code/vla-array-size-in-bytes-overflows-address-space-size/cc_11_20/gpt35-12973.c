//FormAI DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rows, cols;
    printf("Enter number of rows for table: ");
    scanf("%d", &rows);
    printf("Enter number of columns for table: ");
    scanf("%d", &cols);
    
    // Creating the table
    int table[rows][cols];
    srand(time(NULL)); // using current time as seed for randomizing numbers
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            table[i][j] = rand() % 10; // filling each cell with random single digit numbers
        }
    }
    
    // Displaying the table
    printf("The table looks like this:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d\t", table[i][j]); // displaying each cell separated by a tab
        }
        printf("\n"); // moving to the next row
    }
    
    // Asking user to play the game
    char play;
    printf("Do you want to play the game? (Y/N) ");
    scanf(" %c", &play); // using a space before %c to consume the last newline character
    if(play == 'Y' || play == 'y')
    {
        int score = 0;
        printf("The rules of the game are as follows:\n");
        printf("1. Each turn, you will choose a row and a column.\n");
        printf("2. If the number in that cell is even, you earn 2 points.\n");
        printf("3. If the number in that cell is odd, you lose 1 point.\n");
        printf("4. Maximum score is %d.\n", rows * cols * 2);
        printf("Let's start the game!\n");
        
        // Playing the game until user quits or reaches maximum score
        while(score < rows * cols * 2)
        {
            int row, col;
            printf("Enter row and column numbers (starting from 1): ");
            scanf("%d%d", &row, &col);
            
            // Making sure user input is within valid range
            if(row < 1 || row > rows || col < 1 || col > cols)
            {
                printf("Invalid input. Please try again.\n");
                continue;
            }
            int num = table[row-1][col-1];
            if(num % 2 == 0)
            {
                printf("Congratulations! You earned 2 points.\n");
                score += 2;
            }
            else
            {
                printf("Oops! You lost 1 point.\n");
                score -= 1;
            }
            printf("Your current score is %d.\n", score);
            
            // Asking user if they want to continue playing
            printf("Do you want to continue playing? (Y/N) ");
            scanf(" %c", &play);
            if(play == 'N' || play == 'n')
            {
                break;
            }
        }
        printf("Thanks for playing! Your final score is %d.\n", score);
    }
    else
    {
        printf("Thanks for checking out the game.\n");
    }
    
    return 0;
}