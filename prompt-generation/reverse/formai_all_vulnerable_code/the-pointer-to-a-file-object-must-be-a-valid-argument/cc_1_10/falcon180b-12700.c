//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 50
#define MAX_KEYWORD_LENGTH 50

typedef struct {
    char* keyword;
    int line_number;
} Keyword;

int main() {
    FILE* file = fopen("resume.txt", "r");
    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    int num_keywords = 0;
    Keyword* keywords = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        line[strcspn(line, "\n")] = '\0'; // remove newline character from end of line
        char* keyword = strtok(line, " ");
        while (keyword!= NULL) {
            if (num_keywords == MAX_KEYWORDS) {
                printf("Error: too many keywords\n");
                exit(1);
            }
            if (strlen(keyword) > MAX_KEYWORD_LENGTH) {
                printf("Error: keyword too long\n");
                exit(1);
            }
            keywords = realloc(keywords, sizeof(Keyword) * ++num_keywords);
            keywords[num_keywords - 1].keyword = strdup(keyword);
            keywords[num_keywords - 1].line_number = line_number;
            keyword = strtok(NULL, " ");
        }
        line_number++;
    }

    printf("Keywords:\n");
    for (int i = 0; i < num_keywords; i++) {
        printf("%d: %s\n", keywords[i].line_number, keywords[i].keyword);
    }

    free(keywords);
    fclose(file);

    return 0;
}