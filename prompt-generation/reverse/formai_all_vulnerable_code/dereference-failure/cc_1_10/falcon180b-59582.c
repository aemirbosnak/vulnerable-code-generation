//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct {
    char magic[2];
    int version;
    int num_entries;
    char entries[0];
} directory_header_t;

typedef struct {
    int inode_num;
    char file_name[256];
    int file_size;
} directory_entry_t;

int main(int argc, char *argv[]) {
    FILE *disk_file;
    FILE *output_file;
    char *disk_filename = "disk.img";
    char *output_filename = "output.txt";
    int disk_size;
    directory_header_t *header;
    directory_entry_t *entry;
    int i;

    disk_file = fopen(disk_filename, "rb");
    if (disk_file == NULL) {
        printf("Error: could not open disk file.\n");
        exit(1);
    }

    fseek(disk_file, 0, SEEK_END);
    disk_size = ftell(disk_file);
    rewind(disk_file);

    header = malloc(sizeof(directory_header_t) + disk_size);
    if (header == NULL) {
        printf("Error: could not allocate memory for header.\n");
        exit(1);
    }

    fread(header, sizeof(directory_header_t), 1, disk_file);
    if (header->magic[0]!= 'E' || header->magic[1]!= 'X') {
        printf("Error: invalid disk format.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    fprintf(output_file, "Directory header:\n");
    fprintf(output_file, "Magic: %c%c\n", header->magic[0], header->magic[1]);
    fprintf(output_file, "Version: %d\n", header->version);
    fprintf(output_file, "Num entries: %d\n", header->num_entries);

    for (i = 0; i < header->num_entries; i++) {
        entry = (directory_entry_t *) &header->entries[i * sizeof(directory_entry_t)];

        fprintf(output_file, "\nEntry %d:\n", i);
        fprintf(output_file, "Inode num: %d\n", entry->inode_num);
        fprintf(output_file, "File name: %s\n", entry->file_name);
        fprintf(output_file, "File size: %d bytes\n", entry->file_size);
    }

    free(header);
    fclose(disk_file);
    fclose(output_file);

    return 0;
}