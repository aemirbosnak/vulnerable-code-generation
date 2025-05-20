//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

char* input_file = "input.txt";
char* output_file = "output.txt";

int main() {
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    char buffer[MAX_SIZE];
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, input))!= -1) {
        buffer[0] = '\0';
        strcat(buffer, line);
        int count = 0;
        char* word = strtok(buffer, " ");
        while (word!= NULL) {
            if (count == 0) {
                strcat(buffer, toupper(word));
            } else {
                strcat(buffer, word);
            }
            count++;
            word = strtok(NULL, " ");
        }
        fprintf(output, "%s\n", buffer);
    }

    fclose(input);
    fclose(output);

    printf("Conversion completed successfully.\n");
    return 0;
}