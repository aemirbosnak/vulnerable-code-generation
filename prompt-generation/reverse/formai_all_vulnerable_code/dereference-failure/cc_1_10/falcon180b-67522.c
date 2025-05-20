//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void read_file(FILE *fp, char **data);
void write_file(FILE *fp, char *data);
void recover_data(char *filename);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        return 1;
    }

    char *data = NULL;
    read_file(fp, &data);
    fclose(fp);

    recover_data(filename);

    free(data);
    return 0;
}

void read_file(FILE *fp, char **data) {
    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    *data = (char *) malloc(filesize + 1);
    fread(*data, filesize, 1, fp);
    (*data)[filesize] = '\0';
}

void write_file(FILE *fp, char *data) {
    fwrite(data, strlen(data), 1, fp);
}

void recover_data(char *filename) {
    char *ext = strrchr(filename, '.');
    if (ext == NULL) {
        printf("Error: File extension not found.\n");
        return;
    }

    char *new_filename = malloc(strlen(filename) + 5);
    strcpy(new_filename, filename);
    strcat(new_filename, ".rec");

    FILE *fp_in = fopen(filename, "rb");
    FILE *fp_out = fopen(new_filename, "wb");

    if (fp_in == NULL || fp_out == NULL) {
        printf("Error: Could not open file.\n");
        fclose(fp_in);
        fclose(fp_out);
        free(new_filename);
        return;
    }

    char *data = NULL;
    read_file(fp_in, &data);

    int i = 0;
    while (i < strlen(data)) {
        if (data[i] == '\0') {
            i++;
            continue;
        }

        int j = i;
        while (j < strlen(data) && data[j]!= '\0') {
            if (data[j] == '\n') {
                data[j] = '\0';
                break;
            }
            j++;
        }

        write_file(fp_out, data + i);
        i = j;
    }

    fclose(fp_in);
    fclose(fp_out);
    free(data);
    free(new_filename);
}