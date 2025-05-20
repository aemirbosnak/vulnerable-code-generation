//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_TIME 60

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS] = {{"Romeo"}, {"Juliet"}, {"Tybalt"}, {"Mercutio"}, {"Benvolio"}, {"Capulet"}, {"Montague"}, {"Nurse"}, {"Friar"}, {"Prince"}};

int main() {
    srand(time(NULL));
    int numWords = rand() % MAX_WORDS + 1;
    Word *selectedWords = malloc(sizeof(Word) * numWords);
    int i, j;
    for (i = 0; i < numWords; i++) {
        selectedWords[i] = words[rand() % MAX_WORDS];
    }
    printf("Welcome to the Romeo and Juliet Typing Speed Test!\n");
    printf("You will have %d seconds to type the following words:\n", MAX_TIME);
    for (i = 0; i < numWords; i++) {
        printf("%s ", selectedWords[i].word);
    }
    printf("\n");
    fflush(stdout);
    sleep(1);
    int correctWords = 0;
    int totalWords = numWords;
    int startTime = time(NULL);
    while (totalWords > 0 && (difftime(time(NULL), startTime) < MAX_TIME)) {
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);
        for (i = 0; i < numWords; i++) {
            if (strcmp(input, selectedWords[i].word) == 0) {
                correctWords++;
                break;
            }
        }
        totalWords--;
    }
    printf("You typed %d out of %d words correctly in %d seconds.\n", correctWords, numWords, MAX_TIME - difftime(time(NULL), startTime));
    free(selectedWords);
    return 0;
}