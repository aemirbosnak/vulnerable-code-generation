//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_CHARS 2048

typedef struct {
    char **lines;
    int line_count;
} HTMLDocument;

void initializeDocument(HTMLDocument *doc) {
    doc->lines = (char **)malloc(MAX_CHARS * sizeof(char *));
    for (int i = 0; i < MAX_CHARS; i++) {
        doc->lines[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    doc->line_count = 0;
}

void freeDocument(HTMLDocument *doc) {
    for (int i = 0; i < MAX_CHARS; i++) {
        free(doc->lines[i]);
    }
    free(doc->lines);
}

int isWhiteSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void trimLine(char *line) {
    char *end;

    while (isWhiteSpace(*line)) line++;
    if (*line == 0) return;

    end = line + strlen(line) - 1;
    while (end > line && isWhiteSpace(*end)) end--;
    *(end + 1) = 0;
}

void beautifyHTMLLine(char *line, FILE *output) {
    int indent_level = 0;
    char *token = strtok(line, "<>");
    
    while (token != NULL) {
        if (strstr(token, "/") == token) {
            indent_level--;
        }
        
        for (int i = 0; i < indent_level; i++) {
            fprintf(output, "    ");
        }

        if (strstr(token, "html") || strstr(token, "head") || strstr(token, "body") 
            || strstr(token, "div") || strstr(token, "p") || strstr(token, "span") 
            || strstr(token, "h1") || strstr(token, "h2") || strstr(token, "h3")) {
            fprintf(output, "<%s>\n", token);
            indent_level++;
        } else if (strstr(token, "/html") || strstr(token, "/head") || strstr(token, "/body") 
                   || strstr(token, "/div") || strstr(token, "/p") || strstr(token, "/span") 
                   || strstr(token, "/h1") || strstr(token, "/h2") || strstr(token, "/h3")) {
            fprintf(output, "<%s>\n", token);
            indent_level--;
        } else {
            fprintf(output, "<%s/>", token);
        }

        token = strtok(NULL, "<>");
    }
}

void beautifyHTML(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");
    char line[MAX_LINE_LENGTH];
    HTMLDocument doc;

    if (input == NULL || output == NULL) {
        fprintf(stderr, "Error: could not open files.\n");
        exit(1);
    }

    initializeDocument(&doc);

    while (fgets(line, sizeof(line), input)) {
        trimLine(line);
        if (strlen(line) > 0) {
            beautifyHTMLLine(line, output);
        }
    }

    freeDocument(&doc);
    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return 1;
    }

    beautifyHTML(argv[1], argv[2]);
    printf("HTML beautification completed. Output written to %s\n", argv[2]);
    return 0;
}