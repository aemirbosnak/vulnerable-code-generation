//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main()
{
    char **phoneBook = NULL;
    int size = 0;

    // Allocate memory for the phone book
    phoneBook = malloc(sizeof(char *) * 10);
    for (int i = 0; i < 10; i++)
    {
        phoneBook[i] = malloc(sizeof(char) * 20);
    }

    // Add some phone numbers to the book
    phoneBook[0] = "John Doe";
    phoneBook[1] = "Jane Doe";
    phoneBook[2] = "Bob Smith";
    phoneBook[3] = "Alice White";
    phoneBook[4] = "Tom Brown";

    // Search for a phone number
    char searchName[20];
    printf("Enter a name: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchName, phoneBook[i]) == 0)
        {
            found = 1;
            printf("Phone number: %s\n", phoneBook[i]);
        }
    }

    if (!found)
    {
        printf("No such phone number.\n");
    }

    // Free the memory allocated for the phone book
    for (int i = 0; i < 10; i++)
    {
        free(phoneBook[i]);
    }
    free(phoneBook);

    return 0;
}