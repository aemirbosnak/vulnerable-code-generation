//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "This is a virus"
#define MAX_FILE_SIZE 1000000

int is_infected(char* file_contents, int file_size) {
    if (strstr(file_contents, VIRUS_SIGNATURE)) {
        printf("Virus detected in file: %s\n", file_contents);
        return 1;
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large to scan.\n");
        fclose(file);
        return 1;
    }

    char* file_contents = malloc(file_size + 1);
    if (file_contents == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    fread(file_contents, file_size, 1, file);
    file_contents[file_size] = '\0';

    int result = is_infected(file_contents, file_size);

    free(file_contents);
    fclose(file);

    return result;
}