//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main()
{
    // Let's declare a string and have some fun manipulating it!
    char str[] = "Abracadabra";

    // Curious about the length of this magical string?
    printf("The enigmatic string \"%s\" has a length of %lu characters.\n", str, strlen(str));

    // Let's find the first occurrence of a sneaky 'r' in our string
    char* found = strchr(str, 'r');

    // Did we stumble upon this elusive character?
    if (found != NULL)
    {
        printf("Eureka! We found the elusive 'r' at position %ld!\n", found - str);
    }
    else
    {
        printf("Alas, the 'r' seems to have escaped our clutches..\n");
    }

    // How about we try to copy this enchanting string into a new abode?
    char copy[strlen(str) + 1]; // +1 for the null-terminator
    strcpy(copy, str);

    // Did we successfully duplicate our mystical string?
    printf("Behold, the cloned string: \"%s\"\n", copy);

    // Let's give the copy a new twist by appending some extra enchantment
    strcat(copy, " and Presto!");

    // See the transformation?
    printf("Abracadabra, meet your enhanced counterpart: \"%s\"\n", copy);

    // Curious about the last instance of the mysterious 'a' in our string?
    char* last_a = strrchr(str, 'a');

    // Did we uncover its whereabouts?
    if (last_a != NULL)
    {
        printf("Found the elusive last 'a' at position %ld!\n", last_a - str);
    }
    else
    {
        printf("It seems the last 'a' remains concealed within the mists..\n");
    }

    // Time to compare two strings – let's see if they share a magical bond
    char str1[] = "Hocus Pocus";
    int comparison = strcmp(str1, str);

    // Are these strings identical twins?
    if (comparison == 0)
    {
        printf("Hocus Pocus and Abracadabra, two peas in a magical pod!\n");
    }
    else if (comparison < 0)
    {
        printf("Hocus Pocus comes before Abracadabra in the mystical alphabet.\n");
    }
    else
    {
        printf("Abracadabra precedes Hocus Pocus in the realm of strings.\n");
    }

    // Let's end our magical journey by freeing our string from its memory constraints
    free(copy);

    return 0;
}