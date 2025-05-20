//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <alloca.h>

#define MAX_WORDS 10000
#define WORD_LEN 50

struct word {
    char str[WORD_LEN];
    int count;
};

struct word words[MAX_WORDS];
int num_words = 0;

void str_down(char *s)
{
    int i;
    for (i = 0; s[i]; i++)
        s[i] = tolower(s[i]);
}

int find_word(char *word)
{
    int i;
    for (i = 0; i < num_words; i++)
        if (!strcasecmp(words[i].str, word))
            return i;
    return -1;
}

void add_word(char *word)
{
    if (num_words >= MAX_WORDS) {
        fprintf(stderr, "Too many words!\n");
        exit(1);
    }
    str_down(words[num_words].str);
    strncpy(words[num_words].str, word, WORD_LEN);
    words[num_words].count = 1;
    num_words++;
}

void process_line(char *line)
{
    char *token, *save_ptr;
    int i;

    str_down(line);
    token = strtok_r(line, " \t\n\r,;.:!?()[]{}\"", &save_ptr);
    while (token) {
        i = find_word(token);
        if (i >= 0)
            words[i].count++;
        else
            add_word(token);
        token = strtok_r(NULL, " \t\n\r,;.:!?()[]{}\"", &save_ptr);
    }
}

int main(int argc, char *argv[])
{
    char line[1024];
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp))
        process_line(line);

    fclose(fp);

    printf("Word frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].str, words[i].count);
    }

    return 0;
}