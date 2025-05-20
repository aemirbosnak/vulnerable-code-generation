//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256
#define MAX_VIRUS_NAME 32
#define MAX_SIGNATURE_SIZE 1024

typedef union {
    unsigned int integer;
    unsigned char bytes[4];
} word_t;

typedef struct {
    char name[MAX_VIRUS_NAME];
    unsigned int size;
    unsigned char signature[MAX_SIGNATURE_SIZE];
} virus_t;

int read_virus_file(char *filename, virus_t **viruses, int *num_viruses);
int scan_file(char *filename, virus_t *viruses, int num_viruses);

int main(int argc, char *argv[]) {
    virus_t *viruses;
    int num_viruses;
    char filename[MAX_FILENAME];

    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    if (read_virus_file("virus_database.dat", &viruses, &num_viruses) != 0) {
        printf("Error reading virus database file\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        strcpy(filename, argv[i]);
        if (scan_file(filename, viruses, num_viruses) != 0) {
            printf("Virus detected in file: %s\n", filename);
        }
    }

    free(viruses);
    return 0;
}

int read_virus_file(char *filename, virus_t **viruses, int *num_viruses) {
    FILE *fp;
    int num, size;
    virus_t *v;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }

    fread(&num, sizeof(int), 1, fp);
    *viruses = (virus_t *)malloc(num * sizeof(virus_t));
    if (*viruses == NULL) {
        return -1;
    }

    for (int i = 0; i < num; i++) {
        v = &((*viruses)[i]);

        fread(&size, sizeof(int), 1, fp);
        fread(v->name, sizeof(char), MAX_VIRUS_NAME, fp);
        fread(v->signature, sizeof(char), size, fp);

        v->size = size;
    }

    fclose(fp);

    *num_viruses = num;
    return 0;
}

int scan_file(char *filename, virus_t *viruses, int num_viruses) {
    FILE *fp;
    int size, pos = 0, offset = 0;
    unsigned char buffer[MAX_SIGNATURE_SIZE];
    word_t word;
    virus_t *v;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    while (pos < size) {
        fread(&buffer[offset], sizeof(char), MAX_SIGNATURE_SIZE - offset, fp);
        pos += MAX_SIGNATURE_SIZE - offset;

        for (int i = 0; i < num_viruses; i++) {
            v = &viruses[i];
            for (int j = 0; j <= offset; j++) {
                for (int k = 0; k < v->size; k += 4) {
                    memcpy(&word.bytes, &buffer[j + k], 4);
                    if (word.integer == v->signature[k / 4]) {
                        return i;
                    }
                }
            }
        }

        offset = pos % MAX_SIGNATURE_SIZE;
        pos -= offset;
        memmove(buffer, &buffer[MAX_SIGNATURE_SIZE - offset], offset);
    }

    fclose(fp);
    return 0;
}