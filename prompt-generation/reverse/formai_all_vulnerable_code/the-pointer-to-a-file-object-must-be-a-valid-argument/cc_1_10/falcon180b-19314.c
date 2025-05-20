//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int correct;
} Word;

void generate_words(Word words[], int num_words) {
    FILE *fp = fopen("words.txt", "r");
    char line[MAX_WORD_LENGTH];
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, fp)) {
        int len = strlen(line);
        if (len > MAX_WORD_LENGTH) {
            len = MAX_WORD_LENGTH;
        }
        strcpy(words[i].word, line);
        words[i].length = len;
        words[i].correct = 0;
        i++;
    }

    fclose(fp);
}

void print_word(Word word) {
    int i;

    for (i = 0; i < word.length; i++) {
        if (isalpha(word.word[i])) {
            printf("%c", word.word[i]);
        } else {
            printf("_");
        }
    }
    printf(" ");
}

int main() {
    Word words[MAX_WORDS];
    int num_words;
    int i, j, correct = 0;
    char input[MAX_WORD_LENGTH];
    int len;
    int start_time, end_time;

    printf("Enter the number of words to type: ");
    scanf("%d", &num_words);

    generate_words(words, num_words);

    srand(time(NULL));
    for (i = 0; i < num_words; i++) {
        words[i].correct = rand() % 2;
    }

    printf("Press enter to start the test.\n");
    scanf("%c", &input[0]);

    start_time = clock();

    for (i = 0; i < num_words; i++) {
        printf("Word %d: ", i + 1);
        fflush(stdout);
        scanf("%s", input);

        len = strlen(input);
        if (len > words[i].length) {
            len = words[i].length;
        }

        for (j = 0; j < len; j++) {
            if (tolower(input[j]) == tolower(words[i].word[j])) {
                correct++;
            }
        }

        if (correct == words[i].correct) {
            printf("Correct!\n");
        } else {
            printf("Incorrect!\n");
        }
    }

    end_time = clock();

    printf("You typed %d words correctly out of %d.\n", correct, num_words);
    printf("Your typing speed is %.2f words per minute.\n", (double)correct / ((double)(end_time - start_time) / CLOCKS_PER_SEC / 60.0));

    return 0;
}