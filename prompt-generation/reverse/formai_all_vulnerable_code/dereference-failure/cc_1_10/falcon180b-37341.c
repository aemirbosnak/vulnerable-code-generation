//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB
#define VIRUS_SIGNATURE "EICAR-STANDARD-ANTIVIRUS-TEST-FILE!"

int is_virus(char *file_content, int file_size) {
    if (file_size >= strlen(VIRUS_SIGNATURE) &&
        strcmp(file_content + file_size - strlen(VIRUS_SIGNATURE), VIRUS_SIGNATURE) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    char file_name[256];
    FILE *file;
    char *file_content = NULL;
    long file_size;

    printf("Enter the file name to scan for viruses: ");
    scanf("%s", file_name);

    file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        fclose(file);
        return 1;
    }

    rewind(file);
    file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Memory error.\n");
        fclose(file);
        return 1;
    }

    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';

    if (is_virus(file_content, file_size)) {
        printf("Virus found!\n");
    } else {
        printf("No virus found.\n");
    }

    free(file_content);
    fclose(file);

    return 0;
}