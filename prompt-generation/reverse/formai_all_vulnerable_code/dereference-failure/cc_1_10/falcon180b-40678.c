//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_KEYWORDS 50
#define MAX_KEYWORD_LENGTH 50

struct keyword {
    char *word;
    int count;
};

struct keyword parse_line(char *line) {
    struct keyword keyword = {0};
    char *word = strtok(line, " ");
    while (word!= NULL) {
        if (strlen(word) >= MAX_KEYWORD_LENGTH) {
            printf("Error: keyword '%s' is too long.\n", word);
            exit(1);
        }
        if (strlen(keyword.word) == 0) {
            strncpy(keyword.word, word, MAX_KEYWORD_LENGTH);
        } else {
            strncat(keyword.word, ",", MAX_KEYWORD_LENGTH - strlen(keyword.word));
            strncat(keyword.word, word, MAX_KEYWORD_LENGTH - strlen(keyword.word));
        }
        keyword.count++;
        word = strtok(NULL, " ");
    }
    return keyword;
}

void add_keyword(struct keyword *keywords, int count, char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(keywords[i].word, word) == 0) {
            keywords[i].count++;
            return;
        }
    }
    if (count >= MAX_KEYWORDS) {
        printf("Error: too many keywords.\n");
        exit(1);
    }
    strncpy(keywords[count].word, word, MAX_KEYWORD_LENGTH);
    keywords[count].count = 1;
    count++;
}

void print_keywords(struct keyword *keywords, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", keywords[i].word, keywords[i].count);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    struct keyword keywords[MAX_KEYWORDS] = {0};
    int count = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        struct keyword keyword = parse_line(line);
        add_keyword(keywords, count, keyword.word);
        count++;
    }

    print_keywords(keywords, count);

    return 0;
}