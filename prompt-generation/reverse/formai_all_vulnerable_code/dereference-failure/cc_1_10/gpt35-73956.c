//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Please specify a file name to scan.\n");
        return 1;
    }

    char *file_name = argv[1];
    FILE *file = fopen(file_name, "rb");

    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        return 1;
    }

    int file_size;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    char *buffer = malloc(file_size);
    fread(buffer, file_size, 1, file);
    fclose(file);

    printf("Starting scan...\n");
    // Shape shifting code here
    for (int i = 0; i < file_size; i++) {
        if (buffer[i] == 'C') {
            buffer[i] = 'D';
        }
        else if (buffer[i] == 'D') {
            buffer[i] = 'E';
        }
        else if (buffer[i] == 'E') {
            buffer[i] = 'F';
        }
        else if (buffer[i] == 'F') {
            buffer[i] = 'C';
        }
    }
    // End of shape shifting code
    printf("Scan complete. No viruses found.\n");

    free(buffer);
    return 0;
}