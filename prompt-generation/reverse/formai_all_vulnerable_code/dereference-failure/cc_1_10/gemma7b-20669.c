//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the C Phone Book!\n");
    printf("------------------------\n");

    // Create an associative array to store phone numbers
    int **phoneBook = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        phoneBook[i] = (int *)malloc(20 * sizeof(int));
    }

    // Insert some sample phone numbers
    phoneBook[0][0] = 123456;
    phoneBook[0][1] = 987632;
    phoneBook[1][0] = 468213;
    phoneBook[2][0] = 236589;
    phoneBook[3][0] = 648231;

    // Search for a phone number
    int searchNumber = 648231;
    int found = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (phoneBook[i][j] == searchNumber)
            {
                found = 1;
                printf("Phone number found: %d\n", phoneBook[i][j]);
                break;
            }
        }
    }

    // If the phone number was not found, display an error message
    if (!found)
    {
        printf("Phone number not found.\n");
    }

    // Free the memory allocated for the phone book
    for (int i = 0; i < 10; i++)
    {
        free(phoneBook[i]);
    }
    free(phoneBook);

    return 0;
}