//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <string.h>

void display_phone_book()
{
    printf("--------------------------------------------------------\n");
    printf("           Welcome to the Phone Book!\n");
    printf("--------------------------------------------------------\n");

    // Create a phone book array
    char **phone_book = (char **)malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        phone_book[i] = (char *)malloc(20 * sizeof(char));
    }

    // Add some sample data
    strcpy(phone_book[0], "John Doe");
    strcpy(phone_book[0], "555-123-4567");

    strcpy(phone_book[1], "Jane Doe");
    strcpy(phone_book[1], "555-234-5678");

    strcpy(phone_book[2], "Bill Smith");
    strcpy(phone_book[2], "555-345-6789");

    // Display the phone book
    for (int i = 0; i < 10; i++)
    {
        if (phone_book[i] != NULL)
        {
            printf("%s - %s\n", phone_book[i], phone_book[i + 1]);
        }
    }

    // Free the phone book memory
    for (int i = 0; i < 10; i++)
    {
        if (phone_book[i] != NULL)
        {
            free(phone_book[i]);
        }
    }
    free(phone_book);

    printf("--------------------------------------------------------\n");
    printf("Thank you for using the Phone Book!\n");
    printf("--------------------------------------------------------\n");
}

int main()
{
    display_phone_book();

    return 0;
}