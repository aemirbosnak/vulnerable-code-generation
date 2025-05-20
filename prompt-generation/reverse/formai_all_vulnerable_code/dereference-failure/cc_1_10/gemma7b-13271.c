//Gemma-7B DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

char **find_suspect(char **suspect_list, int current_index, char *suspect_name)
{
    int i;
    char **new_suspect_list;

    // Compare the suspect name with the current suspect
    if (strcmp(suspect_name, suspect_list[current_index]) == 0)
    {
        return suspect_list;
    }

    // If the current suspect is not the suspect, create a new list and add the current suspect
    else
    {
        new_suspect_list = malloc(sizeof(char *) * (current_index + 1));
        for (i = 0; i < current_index; i++)
        {
            new_suspect_list[i] = suspect_list[i];
        }
        new_suspect_list[current_index] = suspect_name;

        return find_suspect(new_suspect_list, current_index + 1, suspect_name);
    }
}

int main()
{
    char **suspect_list = NULL;
    char *suspect_name = "Mr. Moriarty";

    suspect_list = find_suspect(suspect_list, 0, suspect_name);

    if (suspect_list)
    {
        printf("The suspect is: ");
        for (int i = 0; suspect_list[i] != NULL; i++)
        {
            printf("%s, ", suspect_list[i]);
        }
        printf("\n");
    }
    else
    {
        printf("The suspect is not found.\n");
    }

    return 0;
}