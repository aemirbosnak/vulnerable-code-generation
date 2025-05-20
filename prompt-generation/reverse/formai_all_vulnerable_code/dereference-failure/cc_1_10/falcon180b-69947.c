//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096

/* Function to trim leading/trailing whitespace from a string */
void trim(char* str) {
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    /* Trim leading whitespace */
    while (isspace(str[start])) {
        start++;
    }

    /* Trim trailing whitespace */
    while (isspace(str[end])) {
        end--;
    }

    /* Copy the trimmed string back into the original buffer */
    strncpy(str, str + start, end - start + 1);
    str[end - start + 1] = '\0';
}

/* Function to parse a CSS rule */
void parse_rule(char* line, char** selector, char** property, char** value) {
    char* pos = strchr(line, ':');
    if (pos == NULL) {
        *selector = strdup(line);
        *property = NULL;
        *value = NULL;
        return;
    }

    *pos = '\0';
    trim(*selector = strdup(line));
    trim(*property = strdup(pos + 1));

    pos = strchr(*value = strdup(pos + 1), ';');
    if (pos!= NULL) {
        *pos = '\0';
    }
}

/* Function to print a CSS rule */
void print_rule(FILE* out, char* selector, char* property, char* value) {
    fprintf(out, "%s {\n", selector);
    fprintf(out, "    %s: %s;\n", property, value);
    fprintf(out, "}\n");
}

/* Function to print a CSS stylesheet */
void print_stylesheet(FILE* out, char* filename) {
    char line[MAX_LINE_LENGTH];
    char* selector = NULL;
    char* property = NULL;
    char* value = NULL;

    fprintf(out, "/* %s */\n", filename);

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        parse_rule(line, &selector, &property, &value);
        print_rule(out, selector, property, value);
    }

    free(selector);
    free(property);
    free(value);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* in = fopen(argv[1], "r");
    if (in == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    FILE* out = stdout;
    print_stylesheet(out, argv[1]);

    fclose(in);
    return 0;
}