//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50
#define FILE_NAME_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compare(const void *a, const void *b) {
    Word *w1 = (Word *)a;
    Word *w2 = (Word *)b;
    return strcmp(w1->word, w2->word);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[FILE_NAME_LENGTH];
    strcpy(filename, argv[1]);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: unable to open file %s\n", filename);
        return 1;
    }

    char line[1000];
    Word words[MAX_WORDS];
    int num_words = 0;

    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, " \t\n\r\f\v.,;:?! ");
        while (token!= NULL) {
            int len = strlen(token);
            if (len > MAX_WORD_LENGTH) {
                len = MAX_WORD_LENGTH;
            }
            strncpy(words[num_words].word, token, len);
            words[num_words].word[len] = '\0';
            words[num_words].count = 0;
            num_words++;

            if (num_words >= MAX_WORDS) {
                printf("Error: maximum number of words exceeded\n");
                fclose(fp);
                return 1;
            }

            token = strtok(NULL, " \t\n\r\f\v.,;:?! ");
        }
    }

    fclose(fp);

    qsort(words, num_words, sizeof(Word), compare);

    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}