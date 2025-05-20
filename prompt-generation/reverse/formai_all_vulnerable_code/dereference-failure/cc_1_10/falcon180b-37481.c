//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE* file, struct word_count words[MAX_WORDS]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            words[i].word[strlen(words[i].word) - 1] = '\0';
            i++;
        } else {
            strcat(words[i].word, &ch);
        }
    }
    words[i].word[strlen(words[i].word) - 1] = '\0';
    i++;
}

void count_words(struct word_count words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct word_count words[MAX_WORDS];
    read_file(file, words);

    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].count = 1;
        for (int j = i + 1; j < MAX_WORDS; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count++;
                words[j].count = 0;
            }
        }
    }

    count_words(words);

    fclose(file);
    return 0;
}