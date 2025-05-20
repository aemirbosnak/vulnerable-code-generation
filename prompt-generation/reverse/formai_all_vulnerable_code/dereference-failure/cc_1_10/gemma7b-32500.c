//Gemma-7B DATASET v1.0 Category: Error handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void handle_error(int error_code) {
    switch (error_code) {
        case 1:
            printf("The file could not be opened.\n");
            break;
        case 2:
            printf("The file could not be read.\n");
            break;
        case 3:
            printf("The file could not be written.\n");
            break;
        case 4:
            printf("An unknown error occurred.\n");
            break;
        default:
            printf("An error occurred.\n");
            break;
    }
    exit(1);
}

int main() {
    FILE *file = NULL;
    int error_code = 0;

    // Attempt to open a file
    file = fopen("my_file.txt", "r");
    if (file == NULL) {
        error_code = 1;
        handle_error(error_code);
    }

    // Attempt to read from the file
    error_code = fread(file, 1024, 1, file);
    if (error_code == 0) {
        error_code = 2;
        handle_error(error_code);
    }

    // Attempt to write to the file
    error_code = fwrite(file, 1024, 1, file);
    if (error_code == 0) {
        error_code = 3;
        handle_error(error_code);
    }

    // Close the file
    fclose(file);

    return 0;
}