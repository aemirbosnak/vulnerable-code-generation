//FormAI DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void beautify_html(char **input_html, char **output_html, int *len) {
    char *new_html = (char *)malloc((*len) * sizeof(char));
    int new_len = 0;
    int tabs = 0;
    int indent = 4; // default indentation level of 4 spaces

    for(int i = 0; i < (*len); i++) {
        char c = (*input_html)[i];

        if(c == '<') {
            if(isalnum((*input_html)[i+1])) {
                new_html[new_len++] = c;

                // add indentation
                for(int j = 0; j < tabs*indent; j++) {
                    new_html[new_len++] = ' ';
                }

                tabs++;
            }
            else if((*input_html)[i+1] == '/') {
                tabs--;
                new_html[new_len++] = '\n';

                // add indentation
                for(int j = 0; j < tabs*indent; j++) {
                    new_html[new_len++] = ' ';
                }
            }
        }
        else if(c == '>') {
            new_html[new_len++] = c;

            if((*input_html)[i-1] == '/') {
                tabs--;
                new_html[new_len++] = '\n';

                // add indentation
                for(int j = 0; j < tabs*indent; j++) {
                    new_html[new_len++] = ' ';
                }
            }
        }
        else {
            new_html[new_len++] = c;
        }
    }

    *output_html = new_html;
    *len = new_len;
}

int main() {
    char *input_html = "<html><head><title>My Website</title></head><body><h1>Welcome to my website!</h1><p>Here you will find <a href=\"stuff.html\">stuff</a></p></body></html>";
    int len = strlen(input_html);

    char *output_html = NULL;
    beautify_html(&input_html, &output_html, &len);

    printf("%s\n", output_html);

    free(output_html);

    return 0;
}