//FormAI DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the cards
void shuffle(int *deck, int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

//Function to print the board
void print_board(int *deck, int n)
{
    printf("==============================\n");
    printf("|     Memory Game Board      |\n");
    printf("==============================\n");
    for (int i = 0; i < n; i++)
    {
        if (i % 4 == 0)
            printf("\n");
        printf("%d\t", i);
    }
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        if (i % 4 == 0 && i != 0)
            printf("\n");
        printf("%c\t", deck[i] == -1 ? ' ' : 'X');
    }
    printf("\n\n");
}

//Function to check if two cards are a match
int check_match(int *deck, int a, int b)
{
    if (deck[a] == deck[b])
    {
        deck[a] = -1;
        deck[b] = -1;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n = 16;
    int *deck = (int *)malloc(n * sizeof(int));

    // Initializing the deck
    for (int i = 0; i < n / 2; i++)
    {
        deck[i] = i;
        deck[i + (n / 2)] = i;
    }

    shuffle(deck, n);
    print_board(deck, n);

    int pos1, pos2, tries = 0, matches = 0;
    printf("Enter two positions to reveal the cards:\n");

    while (matches < n / 2)
    {
        scanf("%d%d", &pos1, &pos2);
        if (pos1 < 0 || pos1 >= n || pos2 < 0 || pos2 >= n || pos1 == pos2 || deck[pos1] == -1 || deck[pos2] == -1)
        {
            printf("Invalid input, please enter valid positions:\n");
        }
        else
        {
            tries++;
            print_board(deck, n);
            if (check_match(deck, pos1, pos2))
            {
                matches++;
                printf("Match found!\n");
            }
            else
            {
                printf("No match found.\n");
            }
            printf("Enter two positions to reveal the cards:\n");
        }
    }

    printf("Game over! You completed the game in %d tries.\n", tries);

    return 0;
}