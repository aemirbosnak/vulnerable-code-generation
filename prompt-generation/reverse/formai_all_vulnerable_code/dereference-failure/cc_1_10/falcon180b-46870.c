//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "I am a virus"
#define MAX_FILE_SIZE 1024000 // 1 MB

int main(int argc, char *argv[]) {
    FILE *file;
    char file_name[256];
    char *buffer, *pos;
    int file_size;

    printf("Enter the file name to scan: ");
    scanf("%s", file_name);

    file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    fseek(file, 0L, SEEK_END);
    file_size = ftell(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File too large.\n");
        fclose(file);
        return 1;
    }

    rewind(file);
    buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error: Not enough memory.\n");
        fclose(file);
        return 1;
    }

    fread(buffer, file_size, 1, file);
    fclose(file);

    pos = strstr(buffer, VIRUS_SIGNATURE);

    if (pos!= NULL) {
        printf("Virus found in file: %s\n", file_name);
    } else {
        printf("File is clean.\n");
    }

    free(buffer);
    return 0;
}