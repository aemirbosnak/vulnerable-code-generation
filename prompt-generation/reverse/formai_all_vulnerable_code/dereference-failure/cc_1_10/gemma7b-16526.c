//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");

    printf("   /\n"
           "  ||||_\n"
           "  \__)\n"
           "  /|__)\n"
           "  \___)\n"
           "\n");

    printf("Please enter the name you want to search for: ");
    char name[20];
    scanf("%s", name);

    printf("Results for %s:\n\n", name);

    int i = 0;
    char **phone_book = (char**)malloc(100 * sizeof(char*));

    for (i = 0; i < 10; i++)
    {
        phone_book[i] = (char*)malloc(20 * sizeof(char));
    }

    phone_book[0] = "John Doe\n123 Main St.\nNew York, NY 10001\n(555) 123-4567";
    phone_book[1] = "Jane Doe\n456 Oak Ave.\nLos Angeles, CA 90210\n(555) 456-7890";
    phone_book[2] = "Bill Smith\n789 Oak St.\nChicago, IL 60601\n(555) 321-5498";
    phone_book[3] = "Mary Johnson\n123 Main St.\nNew York, NY 10001\n(555) 123-4567";
    phone_book[4] = "Bob Brown\n456 Oak Ave.\nLos Angeles, CA 90210\n(555) 456-7890";
    phone_book[5] = "Alice White\n789 Oak St.\nChicago, IL 60601\n(555) 321-5498";
    phone_book[6] = "Tom Jones\n123 Main St.\nNew York, NY 10001\n(555) 123-4567";
    phone_book[7] = "Harry Smith\n456 Oak Ave.\nLos Angeles, CA 90210\n(555) 456-7890";
    phone_book[8] = "Mary Johnson\n123 Main St.\nNew York, NY 10001\n(555) 123-4567";
    phone_book[9] = "Bob Brown\n456 Oak Ave.\nLos Angeles, CA 90210\n(555) 456-7890";

    for (i = 0; phone_book[i] != NULL; i++)
    {
        if (strstr(phone_book[i], name) != NULL)
        {
            printf("%s\n", phone_book[i]);
        }
    }

    free(phone_book);

    return 0;
}