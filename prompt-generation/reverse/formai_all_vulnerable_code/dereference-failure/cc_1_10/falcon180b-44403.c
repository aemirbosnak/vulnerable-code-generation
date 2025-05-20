//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1048576 // 1 MB

typedef struct {
    char *filename;
    char *virus_name;
} Virus;

Virus viruses[] = {
    {"W32.Mydoom", "Mydoom"},
    {"W32.Sasser", "Sasser"},
    {"W32.Blaster", "Blaster"},
    {"W32.Sobig", "Sobig"},
    {NULL, NULL}
};

void scan_file(FILE *file, Virus *viruses) {
    char buffer[MAX_FILE_SIZE];
    int buffer_size = 0;

    while ((buffer_size = fread(buffer, 1, MAX_FILE_SIZE, file)) > 0) {
        char *pattern = viruses->virus_name;
        char *ptr = buffer;

        while ((ptr = strstr(ptr, pattern))) {
            printf("Virus '%s' found in file '%s'!\n", viruses->virus_name, viruses->filename);
            exit(1);
        }

        ptr += strlen(pattern);
        buffer_size -= (ptr - buffer);
        memmove(buffer, ptr, buffer_size);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (!file) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    Virus *virus = viruses;

    while (virus->filename) {
        if (!strcmp(virus->filename, argv[1])) {
            scan_file(file, virus);
            break;
        }
        virus++;
    }

    fclose(file);

    return 0;
}