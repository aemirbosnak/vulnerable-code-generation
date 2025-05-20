//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void scan_file(char* file_path);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./antivirus <file_path>\n");
        return 1;
    }

    char* file_path = argv[1];
    scan_file(file_path);

    return 0;
}

void scan_file(char* file_path) {
    FILE* file = fopen(file_path, "r+");
    if (file == NULL) {
        printf("Error: could not open file %s.\n", file_path);
        return;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* file_contents = (char*) malloc(file_size);
    if (file_contents == NULL) {
        printf("Error: could not allocate memory for file contents.\n");
        fclose(file);
        return;
    }

    fread(file_contents, file_size, 1, file);
    fclose(file);

    // Check if file contains virus signature
    char* virus_signature = "bad_code";
    if (strstr(file_contents, virus_signature) != NULL) {
        char choice;
        printf("Antivirus Alert: File %s is infected with virus.\nDo you want to delete the file?(y/n) ", file_path);
        scanf(" %c", &choice);

        if (choice == 'y') {
            remove(file_path);
            printf("File %s deleted successfully.\n", file_path);
        } else {
            printf("File %s not deleted. Please run a full system scan to ensure your computer is secure.\n", file_path);
        }
    } else {
        printf("Antivirus: File %s is not infected.\n", file_path);
    }

    free(file_contents);
}