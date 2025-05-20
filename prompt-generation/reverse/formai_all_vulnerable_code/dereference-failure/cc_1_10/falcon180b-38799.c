//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file_header {
    char magic[2];
    int version;
    int num_entries;
    int entry_size;
    char *entries;
};

struct file_entry {
    int offset;
    int length;
    char *data;
};

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_directory>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    struct file_header header;
    fread(&header, sizeof(header), 1, input_file);

    if (header.magic[0]!= 'F' || header.magic[1]!= 'R') {
        printf("Error: Invalid file type.\n");
        fclose(input_file);
        return 1;
    }

    struct file_entry *entries = malloc(header.num_entries * sizeof(struct file_entry));
    fread(entries, header.entry_size, header.num_entries, input_file);

    for (int i = 0; i < header.num_entries; i++) {
        char *data = malloc(entries[i].length + 1);
        fseek(input_file, entries[i].offset, SEEK_SET);
        fread(data, entries[i].length, 1, input_file);
        data[entries[i].length] = '\0';

        char *filename = strrchr(entries[i].data, '/');
        if (!filename) {
            filename = entries[i].data;
        } else {
            filename++;
        }

        printf("Recovering %s...\n", filename);

        FILE *output_file = fopen(argv[2], "wb");
        if (!output_file) {
            printf("Error: Could not create output file.\n");
            free(data);
            continue;
        }

        fwrite(data, entries[i].length, 1, output_file);
        fclose(output_file);

        printf("Recovered %s.\n", filename);

        free(data);
    }

    fclose(input_file);
    free(entries);

    return 0;
}