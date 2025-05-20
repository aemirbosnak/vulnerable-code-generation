//MISTRAL-7B DATASET v1.0 Category: HTML beautifier ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

void html_beautify(char *html_code, int *length) {
    int i, j, tag_start, tag_end, space_counter = 0;
    char tag[MAX_BUFFER_SIZE];

    for (i = 0; i < *length; i++) {
        if (html_code[i] == '<') {
            tag_start = i;
            tag[0] = '\0';
            j = i + 1;
            while (j <= *length && html_code[j] != '>') {
                tag[i - tag_start] = html_code[j];
                if (html_code[j] == '/') {
                    tag[i - tag_start++] = '/';
                }
                j++;
            }
            tag[i - tag_start] = '\0';
            if (strcmp(tag, "script") == 0 || strcmp(tag, "style") == 0) {
                for (int k = i; k < *length; k++) {
                    if (html_code[k] == '>') {
                        html_code[k] = '\0';
                        memmove(&html_code[i], &html_code[k + 1], (*length - (k + 1)) * sizeof(char));
                        *length -= (k + 1) - i;
                        i = tag_start;
                        break;
                    }
                }
                continue;
            }
            tag_end = j;
            if (html_code[tag_start - 1] != ' ') {
                html_code[tag_start - 1] = ' ';
                space_counter = 1;
            }
            for (int k = tag_start - 1; k >= 0 && space_counter < 4; k--) {
                if (html_code[k] == '>' || html_code[k] == '<') {
                    html_code[k] = ' ';
                    space_counter++;
                }
            }
            for (int k = tag_end; k < i && space_counter > 0; k--) {
                if (html_code[k] != ' ') {
                    html_code[k] = '\0';
                    memmove(&html_code[k], &html_code[k + 1], (i - k) * sizeof(char));
                    (*length) -= (i - k);
                    i--;
                }
            }
            i += tag_end - tag_start;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <html_code>\n", argv[0]);
        return 1;
    }
    char *html_code = argv[1];
    int length = strlen(html_code);
    html_beautify(html_code, &length);
    printf("%.*s", length, html_code);
    return 0;
}