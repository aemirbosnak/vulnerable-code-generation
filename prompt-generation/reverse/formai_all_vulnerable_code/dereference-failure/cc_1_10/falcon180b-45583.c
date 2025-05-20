//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 1000

int word_count = 0;
char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];

void read_file(FILE *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int i = 0;
        while (line[i]!= '\0' && line[i]!= '\n') {
            if (isalpha(line[i])) {
                strcat(words[word_count], tolower(line[i]));
            }
            i++;
        }
        if (line[i - 1]!= '\0' && line[i - 1]!= '\n') {
            strcat(words[word_count], tolower(line[i - 1]));
        }
        word_count++;
        if (word_count >= MAX_NUM_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }
    }
}

void print_word_counts() {
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Error: Incorrect number of arguments.\n");
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    read_file(file);
    fclose(file);
    print_word_counts();
    return 0;
}