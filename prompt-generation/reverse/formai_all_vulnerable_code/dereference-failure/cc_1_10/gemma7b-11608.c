//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

void spell_checker(char **word_list, int word_list_size)
{
    int i, j;
    char word[MAX_WORD_LENGTH];

    printf("Enter a word: ");
    scanf("%s", word);

    for (i = 0; i < word_list_size; i++)
    {
        for (j = 0; j < MAX_WORD_LENGTH; j++)
        {
            if (word[j] == word_list[i][j])
            {
                printf("Word found: %s\n", word_list[i]);
                return;
            }
        }
    }

    printf("Word not found.\n");
}

int main()
{
    char **word_list = NULL;
    int word_list_size = 0;

    word_list = malloc(10 * sizeof(char *));
    word_list_size = 10;

    word_list[0] = "apple";
    word_list[1] = "banana";
    word_list[2] = "orange";
    word_list[3] = "grape";
    word_list[4] = "apricot";
    word_list[5] = "mango";
    word_list[6] = "pineapple";
    word_list[7] = "watermelon";
    word_list[8] = "peach";
    word_list[9] = "apricot";

    spell_checker(word_list, word_list_size);

    return 0;
}