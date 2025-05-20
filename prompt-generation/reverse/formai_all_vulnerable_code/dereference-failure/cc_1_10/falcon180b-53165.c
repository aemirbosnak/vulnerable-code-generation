//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 100 // 100MB

typedef struct {
    char magic[4];
    int version;
    int num_entries;
    struct entry {
        int offset;
        int size;
    } entries[100];
} file_header;

typedef struct {
    char name[64];
    int size;
    char data[1024];
} file_entry;

int main() {
    char* filename = "recovery.dat";
    file_header header;
    FILE* file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    fread(&header, sizeof(file_header), 1, file);

    if (strncmp(header.magic, "RECO", 4)!= 0 || header.version!= 1) {
        printf("Error: invalid file format.\n");
        fclose(file);
        return 1;
    }

    int total_entries = 0;
    for (int i = 0; i < header.num_entries; i++) {
        if (header.entries[i].offset == 0 && header.entries[i].size == 0) {
            break;
        }

        fseek(file, header.entries[i].offset, SEEK_SET);
        file_entry entry;
        fread(&entry, sizeof(file_entry), 1, file);

        if (entry.size > MAX_FILE_SIZE) {
            printf("Error: file too large.\n");
            fclose(file);
            return 1;
        }

        char* data = malloc(entry.size);
        fseek(file, header.entries[i].offset, SEEK_SET);
        fread(data, entry.size, 1, file);

        printf("Recovered file %d: %s\n", total_entries + 1, entry.name);
        printf("Size: %d bytes\n", entry.size);

        FILE* outfile = fopen(entry.name, "wb");
        if (outfile == NULL) {
            printf("Error: could not create output file.\n");
            free(data);
            fclose(file);
            return 1;
        }

        fwrite(data, entry.size, 1, outfile);
        fclose(outfile);

        free(data);
        total_entries++;
    }

    fclose(file);
    return 0;
}