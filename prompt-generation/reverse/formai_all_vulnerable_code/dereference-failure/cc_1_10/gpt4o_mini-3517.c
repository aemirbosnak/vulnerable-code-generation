//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define INDENTATION "    "
#define MAX_INDENT_DEPTH 10

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int count;
    int capacity;
} CodeBlock;

void initCodeBlock(CodeBlock *cb) {
    cb->count = 0;
    cb->capacity = 10;
    cb->lines = (Line *)malloc(sizeof(Line) * cb->capacity);
}

void addLine(CodeBlock *cb, const char *text) {
    if (cb->count >= cb->capacity) {
        cb->capacity *= 2;
        cb->lines = (Line *)realloc(cb->lines, sizeof(Line) * cb->capacity);
    }
    cb->lines[cb->count].text = strdup(text);
    cb->lines[cb->count].length = strlen(text);
    cb->count++;
}

void freeCodeBlock(CodeBlock *cb) {
    for (int i = 0; i < cb->count; i++) {
        free(cb->lines[i].text);
    }
    free(cb->lines);
}

int isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

void beautifyHTMLLine(char *line, CodeBlock *output, int *indentLevel) {
    char *ptr = line;
    char processedLine[BUFFER_SIZE];
    int position = 0;

    while (*ptr) {
        if (*ptr == '<') {
            // Handle tag opening
            if (strncmp(ptr, "<!--", 4) == 0) {
                // Comment
                while (*ptr && *ptr != '>') {
                    processedLine[position++] = *ptr++;
                }
                if (*ptr == '>') {
                    processedLine[position++] = *ptr++;
                }
            } else if (strncmp(ptr, "</", 2) == 0) {
                // Closing tag
                *indentLevel -= 1;
                for (int i = 0; i < *indentLevel; i++) {
                    for (int j = 0; j < strlen(INDENTATION); j++) {
                        processedLine[position++] = INDENTATION[j];
                    }
                }
                while (*ptr && *ptr != '>') {
                    processedLine[position++] = *ptr++;
                }
                if (*ptr == '>') {
                    processedLine[position++] = *ptr++;
                }
                processedLine[position++] = '\n';
            } else {
                // Opening tag
                for (int i = 0; i < *indentLevel; i++) {
                    for (int j = 0; j < strlen(INDENTATION); j++) {
                        processedLine[position++] = INDENTATION[j];
                    }
                }
                while (*ptr && *ptr != '>') {
                    processedLine[position++] = *ptr++;
                }
                if (*ptr == '>') {
                    processedLine[position++] = *ptr++;
                }
                processedLine[position++] = '\n';
                *indentLevel += 1;
            }
        } else {
            // Normal text
            while (*ptr && !isWhitespace(*ptr) && *ptr != '<') {
                processedLine[position++] = *ptr++;
            }
            processedLine[position++] = ' ';
        }
    }
    processedLine[position] = '\0';
    addLine(output, processedLine);
}

void beautifyHTML(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        return;
    }

    CodeBlock output;
    initCodeBlock(&output);
    char line[BUFFER_SIZE];
    int indentLevel = 0;

    while (fgets(line, BUFFER_SIZE, file)) {
        beautifyHTMLLine(line, &output, &indentLevel);
    }

    fclose(file);

    // Write beautified HTML to file
    FILE *outFile = fopen("beautified_output.html", "w");
    if (!outFile) {
        fprintf(stderr, "Cannot create output file.\n");
        freeCodeBlock(&output);
        return;
    }

    for (int i = 0; i < output.count; i++) {
        fprintf(outFile, "%s", output.lines[i].text);
    }

    fclose(outFile);
    freeCodeBlock(&output);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.html>\n", argv[0]);
        return 1;
    }

    beautifyHTML(argv[1]);
    printf("Your hopeful HTML resurgence is beautified and laid to rest in 'beautified_output.html'.\n");
    return 0;
}