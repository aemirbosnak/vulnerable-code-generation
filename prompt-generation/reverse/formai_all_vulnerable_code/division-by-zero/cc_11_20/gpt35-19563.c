//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int totalWords = 0;
    int correctWords = 0;
    int totalTime = -1;
    int charCount = 0;
    char input[50];

    printf("\nWelcome to the Typing Test Game!\n");
    printf("\nType the following sentence as fast as you can (without any typos):\n\n");

    printf("The quick brown fox jumps over the lazy dog.\n\n");

    time_t begin = time(NULL);

    fgets(input, 50, stdin);

    time_t end = time(NULL);

    if ((end - begin) > 60) {
        printf("\nSorry, you took too long to type!\n");
        return 0;  
    }
 
    totalWords = 9;
    for (int i = 0; input[i] != '\n'; i++) {
        if (input[i] == ' ' && input[i-1] != ' ') {
            totalWords++;
        }
        if (input[i] == ' ' && input[i+1] != ' ' && input[i+1] != '\0') {
            charCount++;
        }
    }

    if (totalWords != 9) {
        printf("\nSorry, you missed a word!\n");
        return 0;
    }

    for (int i = 0; input[i] != '\n'; i++) {
        if (input[i] != ' ' && input[i] != '.') {
            if (input[i] != 't' && input[i] != 'T') {
                printf("\nSorry, that was a typo! Try again.\n");
                return 0;
            }
        } else {
            correctWords++;
        }
    }

    totalTime = (int)difftime(end, begin);

    printf("\nCongratulations! You typed the sentence correctly in %d seconds!\n", totalTime);
    printf("\nTotal Words Typed: %d\n", totalWords);
    printf("Accuracy: %d%%\n", (correctWords * 100) / totalWords);
    printf("Typing Speed: %d WPM\n", (totalWords * 60) / totalTime);

    return 0;
}