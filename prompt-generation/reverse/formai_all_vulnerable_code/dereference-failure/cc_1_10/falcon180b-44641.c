//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 100
#define MAX_KEYWORD_LENGTH 32

typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    int count;
} Keyword;

void process_log_file(FILE *log_file, Keyword keywords[], int num_keywords) {
    char line[MAX_LINE_LENGTH];
    int i;

    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        for (i = 0; i < num_keywords; i++) {
            if (strstr(line, keywords[i].keyword)!= NULL) {
                keywords[i].count++;
                break;
            }
        }
    }
}

void print_keyword_counts(Keyword keywords[], int num_keywords) {
    int i;

    for (i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *log_file;
    Keyword keywords[MAX_KEYWORDS];
    int num_keywords = 0;

    if (argc < 2) {
        printf("Usage: %s <log_file> <keyword1> [<keyword2>...]\n", argv[0]);
        return 1;
    }

    log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (num_keywords < MAX_KEYWORDS && argv[2]!= NULL) {
        strncpy(keywords[num_keywords].keyword, argv[2], MAX_KEYWORD_LENGTH - 1);
        keywords[num_keywords].keyword[MAX_KEYWORD_LENGTH - 1] = '\0';
        num_keywords++;
        argv++;
    }

    process_log_file(log_file, keywords, num_keywords);
    print_keyword_counts(keywords, num_keywords);

    fclose(log_file);

    return 0;
}