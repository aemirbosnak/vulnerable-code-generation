//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* This program is a creative word frequency counter that reads input from the user,
   ignores any non-alphabetic characters and counts how many times each word appears. */

typedef struct {
    char *word;
    int count;
} Word;

int main() {
    int numWords = 0;  //the number of words we have counted
    int numAllocated = 10;  //the number of Word structures we have memory for
    Word *words = malloc(sizeof(Word) * numAllocated);  //an array of Word structures
    char currentWord[50] = "";  //a temporary buffer for the current word we are processing

    printf("Enter some text:\n");

    //process each character in the input
    int c;
    while ((c = getchar()) != EOF) {

        if (isalpha(c)) {
            //make sure our word buffer doesn't overflow
            if (strlen(currentWord) < 50 - 1) {
                //add the character to the end of the current word
                int len = strlen(currentWord);
                currentWord[len] = toupper(c);
                currentWord[len+1] = '\0';
            }
        } else {
            //we have reached the end of a word
            if (strlen(currentWord) > 0) {

                //search for this word in our array
                int found = 0;
                for (int i = 0; i < numWords; i++) {
                    if (strcmp(words[i].word, currentWord) == 0) {
                        words[i].count++;
                        found = 1;
                        break;
                    }
                }

                //if we didn't find the word, add it to the array
                if (!found) {
                    if (numWords == numAllocated-1) {  //we need to allocate more space!
                        numAllocated *= 2;
                        words = realloc(words, sizeof(Word) * numAllocated);
                    }
                    words[numWords].word = malloc(strlen(currentWord)+1);
                    strcpy(words[numWords].word, currentWord);
                    words[numWords].count = 1;
                    numWords++;
                }

                //reset the word buffer
                currentWord[0] = '\0';
            }
        }
    }

    //print out the results
    printf("\nWord frequency counts:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
        free(words[i].word);
    }
    free(words);

    return 0;
}