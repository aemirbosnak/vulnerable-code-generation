//FormAI DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 5000

void remove_extra_spaces(char* str) {
    int i, j = 0;
    char prev = ' ';
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && prev == ' ') {
            continue;
        }
        prev = str[i];
        str[j++] = str[i];
    }
    str[j] = '\0';
}

void indent_html(char* input_file_name, char* output_file_name) {
    FILE *ifp, *ofp;
    char curr_line[MAX_LEN];

    ifp = fopen(input_file_name, "r");
    ofp = fopen(output_file_name, "w");

    int indent_level = 0;
    while (fgets(curr_line, MAX_LEN, ifp)) {
        remove_extra_spaces(curr_line);

        // check if the line starts with < and ends with >, indicating a tag
        if (curr_line[0] == '<' && curr_line[strlen(curr_line) - 2] == '>') {
            if (curr_line[1] == '/') {
                indent_level --; // decrease indent level for closing tags
            }

            for (int i = 0; i < indent_level; i++) {
                fputc('\t', ofp); // add tabs for indentation
            }
            fwrite(curr_line, strlen(curr_line), 1, ofp); // write the line to output file

            if (curr_line[1] != '/') {
                indent_level ++; // increase indent level for opening tags
            }
        } else if (strlen(curr_line) > 1) {
            // if not a tag, remove extra whitespace and write to output file
            remove_extra_spaces(curr_line);
            for (int i = 0; i < indent_level; i++) {
                fputc('\t', ofp);
            }
            fwrite(curr_line, strlen(curr_line), 1, ofp);
        }
    }

    fclose(ifp);
    fclose(ofp);
}

int main() {
    char input_file_name[] = "input.html";
    char output_file_name[] = "output.html";

    indent_html(input_file_name, output_file_name);

    printf("Successfully beautified HTML file!\n");
    return 0;
}