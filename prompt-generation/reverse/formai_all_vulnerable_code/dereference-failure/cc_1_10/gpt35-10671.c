//FormAI DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compare_words(const void* a, const void* b) {
    const Word* word1 = (const Word*)a;
    const Word* word2 = (const Word*)b;
    return word2->count - word1->count;
}

void display_exciting_message() {
    printf("\n\n\tWelcome to the C Ebook Reader!");
    printf("\n\tPrepare to embark on a thrilling journey through the world of C programming!");
    printf("\n\tFasten your seatbelt and get ready to learn some amazing concepts!");
}

void display_word_cloud(Word* words, int num_words) {
    printf("\n\n\tHere's a word cloud of the most frequently occurring words in the ebook:\n");
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < words[i].count; j++) {
            printf("* ");
        }
        printf("%s\n", words[i].word);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }
    Word* words = malloc(sizeof(Word));
    int num_words = 0;
    char word[MAX_WORD_LENGTH] = { 0 };
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c)) {
            if (strlen(word) > 0) {
                int found = 0;
                for (int i = 0; i < num_words; i++) {
                    if (strcmp(word, words[i].word) == 0) {
                        words[i].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found || num_words == 0) {
                    num_words++;
                    words = realloc(words, num_words * sizeof(Word));
                    strcpy(words[num_words - 1].word, word);
                    words[num_words - 1].count = 1;
                }
            }
            memset(word, 0, sizeof(word));
        } else {
            strncat(word, &c, 1);
        }
    }
    qsort(words, num_words, sizeof(Word), compare_words);
    display_exciting_message();
    display_word_cloud(words, num_words);
    fclose(fp);
    free(words);
    return 0;
}