//FormAI DATASET v1.0 Category: HTML beautifier ; Style: accurate
#include <stdio.h>
#include <string.h>
#define MAX_DEPTH 100

void print_indentation(int indent_level) {
    while(indent_level--) {
        printf("\t");
    }
}

void beautify_html(char* html) {
    char stack[MAX_DEPTH][10];
    int depth = 0, indent_level = 0, in_quote = 0;
    char current_tag[10];

    while (*html) {
        if (*html == '<') {
            if (*(html + 1) == '/') {
                depth--;
                indent_level = depth;
            }
            else {
                strcpy(current_tag, html + 1);
                char* end_of_tag = strchr(current_tag, '>');
                *end_of_tag = '\0';
                if (*(end_of_tag - 1) == '/') {
                    indent_level = depth;
                }
                else {
                    int match_found = 0;
                    for (int i = 0; i < MAX_DEPTH; i++) {
                        if (strcmp(current_tag, stack[i]) == 0) {
                            match_found = 1;
                            indent_level = i;
                            break;
                        }
                    }
                    if (match_found == 0) {
                        strcpy(stack[depth], current_tag);
                        depth++;
                        indent_level = depth - 1;
                    }
                }
            }
            putchar(*html);
            if (*(html + 1) != '/') {
                putchar('\n');
                print_indentation(indent_level);
            }
        } else if (*html == '>') {
            putchar(*html);
            if (in_quote == 0) {
                putchar('\n');
                print_indentation(indent_level);
            }
        } else if (*html == '\"' || *html == '\'') {
            in_quote = !in_quote;
            putchar(*html);
        } else {
            putchar(*html);
        }
        html++;
    }
}

int main() {
    char html[] = "<!DOCTYPE html><html><head><meta charset=\"UTF-8\"><title>Sample Page</title></head><body><h1>Welcome to my website!</h1><p>This is a sample paragraph.</p><div><img src=\"https://via.placeholder.com/150\"><br><a href=\"#\">Click here</a></div></body></html>";
    beautify_html(html);
    return 0;
}