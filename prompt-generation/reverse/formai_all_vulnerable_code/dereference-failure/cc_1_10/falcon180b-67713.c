//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10 MB

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} File;

void load_file(const char *filename, File *file) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);

    if (file->size > MAX_FILE_SIZE) {
        fprintf(stderr, "Error: file '%s' is too large\n", filename);
        exit(1);
    }

    file->data = malloc(file->size);
    if (!file->data) {
        fprintf(stderr, "Error: could not allocate memory for file '%s'\n", filename);
        exit(1);
    }

    if (fread(file->data, 1, file->size, fp)!= file->size) {
        fprintf(stderr, "Error: could not read file '%s'\n", filename);
        exit(1);
    }

    fclose(fp);
}

int scan_file(const char *filename) {
    File file;
    load_file(filename, &file);

    unsigned char *data = file.data;
    size_t size = file.size;

    int infected = 0;

    while (size >= 4) {
        if (data[0] == 0x55 && data[1] == 0xAA) {
            fprintf(stdout, "Potential virus found in file '%s'\n", filename);
            infected = 1;
            break;
        }
        data += 1;
        size -= 1;
    }

    free(file.data);
    return infected;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int infected = scan_file(argv[1]);

    if (infected) {
        return 1;
    } else {
        return 0;
    }
}