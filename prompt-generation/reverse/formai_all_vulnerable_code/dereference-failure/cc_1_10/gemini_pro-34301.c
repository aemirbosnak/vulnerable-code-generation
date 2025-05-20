//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define VIRUS_SIGNATURE "ABCDEF"
#define VIRUS_SIGNATURE_LENGTH 6
#define SCAN_BUFFER_SIZE 4096

typedef struct _file_info {
    char *name;
    uint64_t size;
    char *data;
} file_info;

file_info *read_file(char *filename) {
    FILE *fp;
    file_info *fi;
    size_t size;

    fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    fi = malloc(sizeof(file_info));
    if (!fi) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fi->name = malloc(strlen(filename) + 1);
    if (!fi->name) {
        perror("malloc");
        free(fi);
        fclose(fp);
        return NULL;
    }

    strcpy(fi->name, filename);
    fi->data = malloc(size);
    if (!fi->data) {
        perror("malloc");
        free(fi->name);
        free(fi);
        fclose(fp);
        return NULL;
    }

    fread(fi->data, 1, size, fp);
    fclose(fp);

    fi->size = size;
    return fi;
}

void free_file_info(file_info *fi) {
    if (!fi) {
        return;
    }

    if (fi->name) {
        free(fi->name);
    }

    if (fi->data) {
        free(fi->data);
    }

    free(fi);
}

int scan_file(file_info *fi) {
    char *data;
    size_t size;
    size_t i;

    data = fi->data;
    size = fi->size;

    for (i = 0; i < size;) {
        if (memcmp(data, &VIRUS_SIGNATURE, VIRUS_SIGNATURE_LENGTH) == 0) {
            printf("Virus found in file: %s\n", fi->name);
            return 1;
        }

        data++;
        i++;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int i;
    file_info *fi;

    if (argc < 2) {
        printf("Usage: %s <file>...\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; i++) {
        fi = read_file(argv[i]);
        if (!fi) {
            printf("Error reading file: %s\n", argv[i]);
            continue;
        }

        if (scan_file(fi)) {
            free_file_info(fi);
            return 1;
        }

        free_file_info(fi);
    }

    printf("No viruses found.\n");
    return 0;
}