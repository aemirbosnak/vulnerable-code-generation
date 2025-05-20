//FormAI DATASET v1.0 Category: HTML beautifier ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char* input = "<html><body><h1>Welcome to my website</h1><p>This is some paragraph text.</p></body></html>";
    char* output = (char*)malloc(strlen(input) * 2); // must be long enough for beautified HTML

    int tab_count = 0;
    int current_index = 0;

    for(int i=0; i<strlen(input); i++) {
        char current_char = input[i];
        if(current_char == '<') {
            if(input[i+1] == '/') { // closing tag
                tab_count--;
                current_index--;
            }

            for(int j=0; j<tab_count; j++) {
                output[current_index] = '\t';
                current_index++;
            }

            if(input[i+1] != '/') { // opening tag
                tab_count++;
            }

            output[current_index] = current_char;
            current_index++;

        }
        else if(current_char == '>') {
            if(input[i-1] == '/') { // self-closing tag
                tab_count--;
            }

            output[current_index] = current_char;
            current_index++;
            output[current_index] = '\n';
            current_index++;
        }
        else {
            output[current_index] = current_char;
            current_index++;
        }
    }

    printf("Original:\n%s\n", input);
    printf("Beautified:\n%s\n", output);

    free(output);

    return 0;
}