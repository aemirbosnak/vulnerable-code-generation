//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_entry(char **entries, int *num_entries);

int main()
{
    char **entries = NULL;
    int num_entries = 0;

    // Loop to get user input
    while (1)
    {
        char entry[200];
        printf("Enter your entry: ");
        fgets(entry, 200, stdin);

        // Check if the user wants to quit
        if (strcmp(entry, "quit") == 0)
        {
            break;
        }

        // Insert the entry into the digital diary
        insert_entry(&entries, &num_entries);
    }

    // Print the entries
    for (int i = 0; i < num_entries; i++)
    {
        printf("Entry %d: %s\n", i + 1, entries[i]);
    }

    return 0;
}

void insert_entry(char **entries, int *num_entries)
{
    // Allocate memory for the new entry
    entries = realloc(entries, (*num_entries + 1) * sizeof(char *));

    // Create a new entry
    entries[*num_entries] = malloc(200);

    // Get the user's input for the new entry
    printf("Enter your entry: ");
    fgets((*entries[*num_entries]), 200, stdin);

    // Increment the number of entries
    (*num_entries)++;
}