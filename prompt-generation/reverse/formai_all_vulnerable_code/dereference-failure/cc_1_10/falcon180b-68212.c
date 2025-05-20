//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char* argv[]) {

    char input_line[MAX_LINE_LENGTH];
    char* input_ptr;

    while (fgets(input_line, MAX_LINE_LENGTH, stdin)!= NULL) {

        /* Remove leading whitespace */
        input_ptr = input_line;
        while (isspace(*input_ptr)) {
            input_ptr++;
        }

        /* Remove trailing whitespace */
        char* end_ptr = input_ptr + strlen(input_ptr) - 1;
        while (isspace(*end_ptr)) {
            *end_ptr = '\0';
            end_ptr--;
        }

        /* Reverse the string */
        char reversed_line[MAX_LINE_LENGTH];
        strcpy(reversed_line, input_ptr);
        int i = 0, j = strlen(reversed_line) - 1;
        while (i < j) {
            char temp = reversed_line[i];
            reversed_line[i] = reversed_line[j];
            reversed_line[j] = temp;
            i++;
            j--;
        }

        /* Convert to uppercase */
        for (i = 0; reversed_line[i]!= '\0'; i++) {
            reversed_line[i] = toupper(reversed_line[i]);
        }

        /* Output the modified line */
        printf("Modified line: %s\n", reversed_line);

    }

    return 0;
}