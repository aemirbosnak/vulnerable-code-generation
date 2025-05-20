//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 32

typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    int count;
} Keyword;

int main() {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    int num_keywords = 0;
    Keyword keywords[MAX_NUM_KEYWORDS];
    int i;

    // Read user input for keywords
    printf("Enter keywords (separated by spaces):\n");
    fgets(line, MAX_LINE_LENGTH, stdin);
    num_keywords = strlen(line);
    for (i = 0; i < num_keywords; i++) {
        keywords[i].count = 0;
        strcpy(keywords[i].keyword, strtok(line, " "));
    }

    // Open input file
    input_file = fopen("input.log", "r");
    if (input_file == NULL) {
        printf("Error: unable to open input file\n");
        exit(1);
    }

    // Read input file line by line
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        int j;
        for (j = 0; j < num_keywords; j++) {
            char *ptr = strstr(line, keywords[j].keyword);
            while (ptr!= NULL) {
                keywords[j].count++;
                ptr = strstr(ptr + 1, keywords[j].keyword);
            }
        }
    }

    // Print keyword counts
    printf("Keyword Counts:\n");
    for (i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }

    // Close input file
    fclose(input_file);

    return 0;
}