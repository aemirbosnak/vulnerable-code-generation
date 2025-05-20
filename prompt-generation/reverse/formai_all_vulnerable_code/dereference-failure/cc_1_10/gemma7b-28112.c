//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: lively
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

    // Insert data into the phone book
    phoneBook[0] = "John Doe";
    phoneBook[1] = "Jane Doe";
    phoneBook[2] = "Bill Gates";
    phoneBook[3] = "Mark Zuckerberg";
    phoneBook[4] = "Jeff Bezos";
    phoneBook[5] = "Elon Musk";
    phoneBook[6] = "Jack Dorsey";
    phoneBook[7] = "Tim Cook";
    phoneBook[8] = "Satya Nadella";
    phoneBook[9] = "Warren Buffett";

    // Search for a name in the phone book
    char searchName[20];
    printf("Enter a name: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchName, phoneBook[i]) == 0)
        {
            found = 1;
            printf("Phone number: %s\n", phoneBook[i + 1]);
        }
    }

    if (!found)
    {
        printf("Name not found.\n");
    }

    // Free memory
    for (int i = 0; i < size; i++)
    {
        free(phoneBook[i]);
    }
    free(phoneBook);

    return 0;
}