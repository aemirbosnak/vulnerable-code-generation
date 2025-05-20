//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 30
#define WORD_SIZE 10

char words[MAX_WORDS][WORD_SIZE] = {"programming", "algorithm", "computer", "keyboard", "mouse", "screen", "monitor", "output", "input", "memory", "operating", "system", "binary", "compiler", "debugger", "iteration", "control", "flow", "function", "header", "library", "pointer", "recursive", "variable", "integer", "floating", "point", "structure", "union", "enumeration"};

char input[WORD_SIZE];
clock_t start, end;

void generate_words()
{
    srand(time(NULL));
    for(int i=0; i<MAX_WORDS; i++)
    {
        int n = rand() % MAX_WORDS;
        char temp[WORD_SIZE];
        strcpy(temp, words[i]);
        strcpy(words[i], words[n]);
        strcpy(words[n], temp);
    }
}

int main()
{
    int i;
    int score = 0, time_taken = 0, words_per_min = 0;
    
    printf("Type these words as fast as you can:\n");
    
    generate_words();
    
    for(i=0; i<MAX_WORDS; i++)
    {   
        printf("%s ", words[i]);
        start = clock();
        scanf("%s", input);
        end = clock();
        time_taken += (int) (end - start) / CLOCKS_PER_SEC;
        if(strcmp(words[i], input) == 0)
        {
            score++;
        }
    }
    
    words_per_min = (int) ((float) score / time_taken) * 60;
    
    printf("\nYour score is: %d\nWords per minute: %d\n", score, words_per_min);
    
    return 0;
}