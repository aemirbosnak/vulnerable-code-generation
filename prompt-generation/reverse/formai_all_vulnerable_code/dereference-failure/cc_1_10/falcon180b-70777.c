//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 1024
#define MAX_KEYWORDS 1024

// Keyword list
char* keyword_list[] = {
    "int",
    "float",
    "double",
    "char",
    "bool",
    "void",
    "if",
    "else",
    "while",
    "for",
    "switch",
    "case",
    "default",
    "break",
    "continue",
    "return",
    "main",
    "printf",
    "scanf",
    "gets",
    "puts"
};

int keyword_count = sizeof(keyword_list) / sizeof(keyword_list[0]);

char* token_buffer[MAX_TOKENS];
int token_count = 0;

char* line_buffer;
int line_length;

void read_file(FILE* file) {
    while (fgets(line_buffer, MAX_LINE_LENGTH, file)!= NULL) {
        line_length = strlen(line_buffer);
        for (int i = 0; i < line_length; i++) {
            if (isalnum(line_buffer[i]) || line_buffer[i] == '_') {
                token_buffer[token_count++] = &line_buffer[i];
            } else {
                if (token_count > 0) {
                    token_buffer[token_count] = NULL;
                    token_count++;
                }
            }
        }
    }
}

void extract_keywords() {
    for (int i = 0; i < MAX_TOKENS; i++) {
        if (token_buffer[i]!= NULL) {
            int keyword_index = -1;
            for (int j = 0; j < keyword_count; j++) {
                if (strcmp(token_buffer[i], keyword_list[j]) == 0) {
                    keyword_index = j;
                    break;
                }
            }
            if (keyword_index!= -1) {
                printf("%s ", keyword_list[keyword_index]);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    read_file(file);
    fclose(file);

    extract_keywords();
    printf("\n");

    return 0;
}