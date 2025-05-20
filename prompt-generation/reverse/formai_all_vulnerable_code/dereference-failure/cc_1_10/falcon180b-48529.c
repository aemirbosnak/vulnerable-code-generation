//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size to scan (1MB)
#define VIRUS_SIGNATURE "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"

int is_virus(char* file_content);

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char* file_path = argv[1];
    FILE* file = fopen(file_path, "rb");

    if (file == NULL) {
        printf("Error: Failed to open file '%s'.\n", file_path);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File size exceeds maximum limit of 1MB.\n");
        fclose(file);
        return 1;
    }

    rewind(file);
    char* file_content = (char*) malloc(file_size + 1);

    if (file_content == NULL) {
        printf("Error: Failed to allocate memory for file content.\n");
        fclose(file);
        return 1;
    }

    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';

    int is_infected = is_virus(file_content);

    if (is_infected) {
        printf("Virus detected in file '%s'.\n", file_path);
    } else {
        printf("No virus detected in file '%s'.\n", file_path);
    }

    free(file_content);
    fclose(file);

    return 0;
}

int is_virus(char* file_content) {
    char* virus_signature = VIRUS_SIGNATURE;
    char* content_ptr = file_content;

    while (*content_ptr!= '\0') {
        if (tolower(*content_ptr) == tolower(*virus_signature)) {
            virus_signature++;
        } else {
            virus_signature = VIRUS_SIGNATURE;
        }

        content_ptr++;

        if (strlen(virus_signature) == 0) {
            return 1;
        }
    }

    return 0;
}