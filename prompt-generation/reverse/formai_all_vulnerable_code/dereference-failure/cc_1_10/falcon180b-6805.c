//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 1000
#define MAX_NUM_WORDS 1000000

char *words[MAX_NUM_WORDS];
int num_words = 0;

void add_word(char *word)
{
    if (num_words >= MAX_NUM_WORDS) {
        printf("Error: Too many words!\n");
        exit(1);
    }

    int length = strlen(word);
    if (length > MAX_WORD_LENGTH) {
        printf("Error: Word is too long!\n");
        exit(1);
    }

    words[num_words] = malloc(length + 1);
    strcpy(words[num_words], word);

    num_words++;
}

void print_word_counts()
{
    printf("Word Count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], 1);
    }
}

void process_line(char *line)
{
    char *word = strtok(line, " ");
    while (word!= NULL) {
        add_word(word);
        word = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        process_line(line);
    }

    fclose(file);

    print_word_counts();

    return 0;
}