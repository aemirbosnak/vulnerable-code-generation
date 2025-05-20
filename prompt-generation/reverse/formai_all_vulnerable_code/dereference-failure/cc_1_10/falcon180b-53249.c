//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_KEY_LENGTH 100
#define DELIMITER '\t'

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_file_name[MAX_LINE_LENGTH], output_file_name[MAX_LINE_LENGTH];
    char *key = NULL;
    int key_length = 0, file_extension_length = 0;
    char *file_extension = NULL;
    int i, j, line_count = 0;
    char c, delimiter = DELIMITER;
    char input_buffer[MAX_LINE_LENGTH];
    char output_buffer[MAX_LINE_LENGTH];

    printf("Enter the input file name: ");
    scanf("%s", input_file_name);

    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    printf("Enter the output file name: ");
    scanf("%s", output_file_name);

    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    printf("Enter the encryption key: ");
    scanf("%s", input_buffer);
    key = strdup(input_buffer);
    key_length = strlen(key);

    file_extension = strrchr(input_file_name, '.');
    if (file_extension!= NULL) {
        file_extension_length = strlen(file_extension);
        strcat(output_file_name, file_extension);
    } else {
        strcat(output_file_name, ".enc");
    }

    fprintf(output_file, "Encrypted with key: %s\n", key);

    while (fgets(input_buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_count++;
        for (i = 0, j = 0; i < strlen(input_buffer); i++) {
            if (isalpha(input_buffer[i])) {
                c = tolower(input_buffer[i]) + key_length;
                if (c > 'z') {
                    c = c - 26;
                } else if (c < 'a') {
                    c = c + 26;
                }
                output_buffer[j++] = c;
            } else {
                output_buffer[j++] = input_buffer[i];
            }
        }
        output_buffer[j] = '\0';
        fprintf(output_file, "%s%c", output_buffer, delimiter);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Encryption complete. %d lines encrypted.\n", line_count);

    return 0;
}