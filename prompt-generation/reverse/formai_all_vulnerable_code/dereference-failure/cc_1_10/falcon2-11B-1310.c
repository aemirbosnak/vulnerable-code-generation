//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 100

void spell_check(char *s)
{
    int i;
    char *temp;
    int count = 0;
    int num_words = 0;

    for (i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            num_words++;
            temp = strdup(s);
            temp[i] = '\0';
            count = 0;
            while (count < num_words)
            {
                if (strcmp(temp, s + i) == 0)
                {
                    i++;
                    while (s[i]!= '\0')
                    {
                        if (isalpha(s[i]))
                        {
                            temp[count] = s[i];
                            count++;
                        }
                        i++;
                    }
                    temp[count] = '\0';
                    count++;
                }
                else
                {
                    count++;
                }
            }
            printf("Misspelled word found: %s\n", temp);
        }
    }
}

int main()
{
    char s[MAX_LEN];
    printf("Enter a sentence: ");
    fgets(s, MAX_LEN, stdin);

    spell_check(s);

    return 0;
}