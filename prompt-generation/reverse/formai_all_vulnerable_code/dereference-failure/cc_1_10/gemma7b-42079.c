//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char **poem = NULL;
    poem = (char **)malloc(10 * sizeof(char *));
    for(int i = 0; i < 10; i++)
    {
        poem[i] = (char *)malloc(20 * sizeof(char));
    }

    poem[0] = "The quick brown fox jumps over the lazy dog.";
    poem[1] = "A red barn stands proud and tall.";
    poem[2] = "The cat sat on the mat.";
    poem[3] = "The old clock strikes twelve.";
    poem[4] = "A merry band of travelers journeyed on.";
    poem[5] = "The river flows to the sea.";
    poem[6] = "The stars twinkle above.";
    poem[7] = "A rainbow arcs across the sky.";
    poem[8] = "The flowers bloom in the spring.";
    poem[9] = "The trees sway in the wind.";

    char **words = NULL;
    words = (char **)malloc(100 * sizeof(char *));
    for(int i = 0; i < 100; i++)
    {
        words[i] = (char *)malloc(20 * sizeof(char));
    }

    int i = 0;
    for(char **p = poem; *p; p++)
    {
        char **w = words;
        char *line = *p;
        int j = 0;
        for(char *word = line; *word; word++)
        {
            int k = 0;
            for(char *w_copy = *w; *w_copy; w_copy++)
            {
                if(strcmp(word, w_copy) == 0)
                {
                    k++;
                }
            }

            if(k > 1)
            {
                sprintf(words[i], "Word: %s, Occurrences: %d", word, k);
                i++;
            }
        }
    }

    printf("Word Frequency Counter\n\n");
    for(int i = 0; words[i]; i++)
    {
        printf("%s\n", words[i]);
    }

    free(poem);
    free(words);
}