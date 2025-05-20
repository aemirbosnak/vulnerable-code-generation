//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void indent(int spaces) {
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
}

void print_tag(char* tag, int is_close) {
    if (is_close) {
        printf("</%s>", tag);
    } else {
        printf("<%s>", tag);
    }
}

int main() {
    FILE* input_file = fopen("input.html", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char ch;
    int in_tag = 0;
    char* tag = malloc(100);
    int tag_length = 0;

    while ((ch = fgetc(input_file))!= EOF) {
        if (ch == '<') {
            in_tag = 1;
            tag[tag_length++] = ch;
        } else if (ch == '>') {
            in_tag = 0;
            tag[tag_length] = '\0';
            if (strcmp(tag, "br") == 0) {
                printf("\n");
            } else if (strcmp(tag, "p") == 0) {
                printf("\n\n");
            } else if (strcmp(tag, "h1") == 0 || strcmp(tag, "h2") == 0 || strcmp(tag, "h3") == 0) {
                printf("\n");
                for (int i = 0; i < (int) strlen(tag) - 1; i++) {
                    printf("=");
                }
                printf("\n");
            } else {
                printf(" ");
            }
            tag_length = 0;
        } else if (in_tag) {
            tag[tag_length++] = ch;
        } else {
            printf("%c", ch);
        }
    }

    free(tag);
    fclose(input_file);

    return 0;
}