//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "I am a virus!"

int is_infected(char* file_content) {
    int file_size = strlen(file_content);
    char* virus_signature = VIRUS_SIGNATURE;
    int virus_size = strlen(virus_signature);

    for (int i = 0; i <= file_size - virus_size; i++) {
        if (strncmp(file_content + i, virus_signature, virus_size) == 0) {
            return 1;
        }
    }

    return 0;
}

void scan_file(char* file_name) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", file_name);
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* file_content = malloc(file_size + 1);
    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';

    if (is_infected(file_content)) {
        printf("Virus found in file '%s'\n", file_name);
    } else {
        printf("File '%s' is clean\n", file_name);
    }

    fclose(file);
    free(file_content);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);

    return 0;
}