//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LINES 10000
#define MAX_LOG_LINE_LENGTH 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 64

typedef struct {
    char *keyword;
    int count;
} Keyword;

Keyword keywords[MAX_KEYWORDS];
int num_keywords;

void parse_log_file(FILE *log_file) {
    char line[MAX_LOG_LINE_LENGTH];
    char *token;
    char *delimiter = " ";
    int line_count = 0;

    while (fgets(line, MAX_LOG_LINE_LENGTH, log_file)!= NULL) {
        line_count++;

        if (line_count > MAX_LOG_LINES) {
            printf("Error: Log file is too large.\n");
            exit(1);
        }

        token = strtok(line, delimiter);
        while (token!= NULL) {
            if (strlen(token) > 0 && isalpha(token[0])) {
                int i;
                for (i = 0; i < num_keywords; i++) {
                    if (strcmp(token, keywords[i].keyword) == 0) {
                        keywords[i].count++;
                        break;
                    }
                }
                if (i == num_keywords) {
                    if (num_keywords == MAX_KEYWORDS) {
                        printf("Error: Too many keywords.\n");
                        exit(1);
                    }
                    strcpy(keywords[num_keywords].keyword, token);
                    keywords[num_keywords].count = 1;
                    num_keywords++;
                }
            }
            token = strtok(NULL, delimiter);
        }
    }
}

void print_keyword_counts(Keyword *keywords, int num_keywords) {
    int i;

    for (i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *log_file;
    int i;

    if (argc!= 3) {
        printf("Usage: %s <log_file> <keyword>\n", argv[0]);
        exit(1);
    }

    log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: Unable to open log file.\n");
        exit(1);
    }

    num_keywords = 0;
    while (num_keywords < MAX_KEYWORDS && argv[2][0]!= '\0') {
        if (strlen(argv[2]) > MAX_KEYWORD_LENGTH) {
            printf("Error: Keyword is too long.\n");
            exit(1);
        }
        strcpy(keywords[num_keywords].keyword, argv[2]);
        num_keywords++;
        argv[2] += strlen(argv[2]) + 1;
    }

    parse_log_file(log_file);
    fclose(log_file);

    print_keyword_counts(keywords, num_keywords);

    return 0;
}