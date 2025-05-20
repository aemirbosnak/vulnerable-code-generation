//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void print_phone_book(void)
{
    printf("Welcome to the C Phone Book!\n");
    printf("--------------------\n");
    printf("Dial a number:\n");

    // Create a hash table to store phone numbers
    int **phone_book = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        phone_book[i] = (int *)malloc(20 * sizeof(int));
    }

    // Insert phone numbers into the hash table
    phone_book[0][0] = 12345;
    phone_book[0][1] = 67890;
    phone_book[1][0] = 34567;
    phone_book[1][1] = 26801;
    phone_book[2][0] = 86423;
    phone_book[2][1] = 51934;
    phone_book[3][0] = 93864;
    phone_book[3][1] = 46128;
    phone_book[4][0] = 68214;
    phone_book[4][1] = 15842;

    // Search for a phone number
    int number;
    printf("Enter the phone number you want to find:");
    scanf("%d", &number);

    // Check if the phone number is in the hash table
    int found = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (phone_book[i][j] == number)
            {
                found = 1;
                printf("The phone number is: %d\n", phone_book[i][j]);
            }
        }
    }

    // If the phone number is not found, print an error message
    if (!found)
    {
        printf("The phone number is not found.\n");
    }

    // Free the memory allocated for the phone book
    for (int i = 0; i < 10; i++)
    {
        free(phone_book[i]);
    }
    free(phone_book);
}

int main()
{
    print_phone_book();

    return 0;
}