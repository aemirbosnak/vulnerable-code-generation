//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_WORDS 100
#define MAX_CHARS 50

typedef struct {
    char word[MAX_CHARS];
    int speed;
} Word;

void generateWords(Word words[]) {
    FILE *fp;
    char filename[50] = "words.txt";
    char line[MAX_CHARS];
    int i;

    fp = fopen(filename, "r");

    for (i = 0; i < MAX_WORDS && fgets(line, MAX_CHARS, fp) != NULL; i++) {
        sscanf(line, "%s", words[i].word);
        words[i].speed = 0;
    }

    fclose(fp);
}

void printWords(Word words[]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        printf("%s\n", words[i].word);
    }
}

void typeWord(Word *word, int *charIndex, int *timeTaken) {
    char input[MAX_CHARS];
    clock_t start, end;
    int i;

    for (i = 0; word->word[i] != '\0'; i++) {
        scanf(" %c", &input[i]);

        if (word->word[i] != input[i]) {
            printf("Incorrect character! Try again.\n");
            i--;
            continue;
        }
    }

    start = clock();
    for (i = 0; word->word[i] != '\0'; i++) {
        if (word->word[i] != input[i]) {
            printf("Incorrect character! Try again.\n");
            i--;
            break;
        }
    }

    end = clock();

    *timeTaken += end - start;
}

int main() {
    Word words[MAX_WORDS];
    int charIndex = 0, timeTaken = 0, i;

    srand(time(NULL));

    generateWords(words);

    for (i = 0; i < 3; i++) {
        Word *randomWord = words + rand() % MAX_WORDS;
        printf("\nType the following word: %s\n", randomWord->word);

        typeWord(randomWord, &charIndex, &timeTaken);

        printf("Speed: %d words per minute\n", (60 * MAX_CHARS) / timeTaken);
        timeTaken = 0;
    }

    printWords(words);

    return 0;
}