//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: random
#include <stdio.h>
#include <stdlib.h>

// define width and height of the output ASCII art
#define WIDTH 80
#define HEIGHT 20

// define the character set for the ASCII art
char charset[10] = {'#', '@', '(', ')', '[', ']', '+', '-', '/', '\\'};

// define a function to generate and print the ASCII art
void generate_ascii_art(char *text)
{
    // allocate memory for the ASCII art
    char **art = (char **)malloc(sizeof(char *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++)
    {
        art[i] = (char *)malloc(sizeof(char) * WIDTH);
    }
    
    // loop over each row of the ASCII art
    for (int i = 0; i < HEIGHT; i++)
    {
        // loop over each column of the ASCII art
        for (int j = 0; j < WIDTH; j++)
        {
            // calculate the index of the character to use
            int index = abs(i - j) % 10;
            
            // set the current character in the ASCII art
            art[i][j] = charset[index];
        }
    }
    
    // print the ASCII art with the input text
    printf("\n");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == WIDTH / 2 - 4 && i == HEIGHT / 2)
            {
                printf("%s", text);
                j += (int)strlen(text);
            }
            else
            {
                printf("%c", art[i][j]);
            }
        }
        printf("\n");
    }
    
    // free the memory used by the ASCII art
    for (int i = 0; i < HEIGHT; i++)
    {
        free(art[i]);
    }
    free(art);
}

int main()
{
    // get input text from the user
    char text[20];
    printf("Enter text (max 20 characters): ");
    scanf("%s", text);
    
    // generate and print the ASCII art
    generate_ascii_art(text);
    
    return 0;
}