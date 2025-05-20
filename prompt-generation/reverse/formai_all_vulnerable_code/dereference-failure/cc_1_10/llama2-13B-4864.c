//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAB_SIZE 4
#define SPACE_SIZE 2

typedef struct {
    char *tag;
    char *text;
} token_t;

void parse_html(const char *html) {
    token_t *tokens = NULL;
    int i = 0;

    // Parse HTML into tokens
    while (html[i]) {
        if (html[i] == '<') {
            // Start of tag
            tokens = realloc(tokens, (i - 1) * sizeof(token_t) + sizeof(token_t));
            tokens[i - 1].tag = html + i + 1;
            while (*html == ' ') {
                i++;
            }
            tokens[i - 1].text = html + i;
            i++;
        } else if (html[i] == '>') {
            // End of tag
            i++;
        } else if (html[i] == ' ') {
            // Skip spaces
        } else {
            // Found text
            tokens[i - 1].text = html + i;
            i++;
        }
    }

    // Beautify HTML
    for (int j = 0; j < i; j++) {
        if (tokens[j].tag[0] == '/') {
            // Close tag
            if (tokens[j].text[0] == '<') {
                // Remove extra <
                tokens[j].text++;
            }
            printf("</%s>", tokens[j].tag + 1);
        } else {
            // Open tag
            printf("<%s", tokens[j].tag + 1);
            if (tokens[j].text[0] == '<') {
                // Remove extra <
                tokens[j].text++;
            }
            for (int k = j + 1; k < i; k++) {
                if (tokens[k].tag[0] == '>') {
                    // End of tag
                    break;
                }
                if (tokens[k].text[0] == ' ') {
                    // Remove spaces
                    tokens[k].text++;
                }
            }
        }
    }

    free(tokens);
}

int main() {
    const char *html = "<b>Hello <i>world</i>!</b>";
    parse_html(html);
    return 0;
}