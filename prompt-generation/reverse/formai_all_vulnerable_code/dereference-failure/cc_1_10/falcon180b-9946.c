//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1000000)
#define MAX_VIRUS_SIZE (100)

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} File;

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} Virus;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    File file = {
       .name = filename,
       .data = NULL,
       .size = 0
    };

    if (read_file(&file)!= 0) {
        printf("Error reading file.\n");
        return 1;
    }

    Virus virus = {
       .name = "MyVirus",
       .data = "This is a virus!",
       .size = strlen("This is a virus!")
    };

    if (scan_virus(&file, &virus)!= 0) {
        printf("Virus found!\n");
        return 1;
    }

    printf("No virus found.\n");
    return 0;
}

int read_file(File *file) {
    FILE *f = fopen(file->name, "rb");
    if (f == NULL) {
        return -1;
    }

    fseek(f, 0, SEEK_END);
    file->size = ftell(f);

    if (file->size > MAX_FILE_SIZE) {
        printf("File too large.\n");
        fclose(f);
        return -1;
    }

    rewind(f);
    file->data = malloc(file->size);
    if (file->data == NULL) {
        printf("Memory error.\n");
        fclose(f);
        return -1;
    }

    size_t bytes_read = fread(file->data, 1, file->size, f);
    if (bytes_read!= file->size) {
        printf("Error reading file.\n");
        free(file->data);
        fclose(f);
        return -1;
    }

    fclose(f);
    return 0;
}

int scan_virus(File *file, Virus *virus) {
    size_t i;
    for (i = 0; i < file->size - virus->size; i++) {
        if (memcmp(file->data + i, virus->data, virus->size) == 0) {
            printf("Virus found at offset %zu.\n", i);
            return 1;
        }
    }

    return 0;
}