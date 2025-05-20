//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Helper function to indent a string by a given number of spaces
void indent(char* str, int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
    printf("%s", str);
}

// Helper function to determine the level of indentation of a given line
int getIndentation(char* line) {
    int i = 0;
    while (line[i] == ' ') {
        i++;
    }
    return i;
}

// Helper function to remove trailing whitespace from a string
void trim(char* str) {
    int len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t')) {
        len--;
    }
    str[len] = '\0';
}

// Helper function to split a string into an array of tokens
char** tokenize(char* str, int* numTokens) {
    char** tokens = malloc(sizeof(char*) * 10);
    int numAllocated = 10;
    int i = 0;
    char* tokenStart = str;
    while (*str != '\0') {
        if (*str == ' ') {
            if (tokenStart != str) {
                tokens[i++] = strndup(tokenStart, str - tokenStart);
                if (i == numAllocated) {
                    numAllocated *= 2;
                    tokens = realloc(tokens, sizeof(char*) * numAllocated);
                }
            }
            tokenStart = str + 1;
        }
        str++;
    }
    if (tokenStart != str) {
        tokens[i++] = strndup(tokenStart, str - tokenStart);
        if (i == numAllocated) {
            numAllocated *= 2;
            tokens = realloc(tokens, sizeof(char*) * numAllocated);
        }
    }
    *numTokens = i;
    return tokens;
}

// Helper function to free the tokens returned by tokenize()
void freeTokens(char** tokens, int numTokens) {
    for (int i = 0; i < numTokens; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

// Main function to beautify the given HTML code
void beautify(char* html) {
    int indentation = 0;
    int inTag = 0;
    int inComment = 0;
    char* line = strtok(html, "\n");
    while (line != NULL) {
        if (!inComment) {
            if (strstr(line, "<!--") != NULL) {
                inComment = 1;
                indent(line, indentation);
                printf("\n");
            } else if (strstr(line, "-->") != NULL) {
                inComment = 0;
            } else if (!inTag && strstr(line, "<") != NULL) {
                indent(line, indentation);
                printf("\n");
                indentation++;
                inTag = 1;
            } else if (inTag && strstr(line, ">") != NULL) {
                indentation--;
                inTag = 0;
            } else if (inTag) {
                indent(line, indentation);
            } else {
                trim(line);
                if (strlen(line) > 0) {
                    indent(line, indentation);
                }
            }
        } else {
            indent(line, indentation);
        }
        printf("\n");
        line = strtok(NULL, "\n");
    }
}

int main() {
    char* html = "<html>\n\t<head>\n\t\t<title>Hello, world!</title>\n\t</head>\n\t<body>\n\t\t<h1>Hello, world!</h1>\n\t</body>\n</html>";
    beautify(html);
    return 0;
}