//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SECTOR_SIZE 512

typedef struct {
    char filename[12];
    char ext[3];
    unsigned short attributes;
    unsigned short reserved;
    unsigned short creation_date;
    unsigned short creation_time;
    unsigned short last_access_date;
    unsigned short first_cluster;
    unsigned int file_size;
} FAT_ENTRY;

typedef struct {
    unsigned short first_sector;
    unsigned short num_sectors;
} FAT_SECTOR;

FAT_ENTRY *fat_table;
FAT_SECTOR *fat_sectors;
unsigned char *data_area;
FILE *disk_image;

void load_fat_table() {
    fseek(disk_image, 0, SEEK_SET);
    fread(fat_table, sizeof(FAT_ENTRY), 256, disk_image);
}

void load_fat_sectors() {
    fseek(disk_image, 512, SEEK_SET);
    fread(fat_sectors, sizeof(FAT_SECTOR), 256, disk_image);
}

void load_data_area() {
    fseek(disk_image, 32256, SEEK_SET);
    data_area = malloc(65536);
    fread(data_area, 1, 65536, disk_image);
}

void print_file_info(FAT_ENTRY *entry) {
    char *filename = entry->filename;
    char *ext = entry->ext;
    unsigned int file_size = entry->file_size;
    printf("%s.%s (%d bytes)\n", filename, ext, file_size);
}

void recover_file(FAT_ENTRY *entry) {
    char *filename = entry->filename;
    char *ext = entry->ext;
    unsigned int file_size = entry->file_size;
    unsigned short cluster = entry->first_cluster;
    unsigned char *buffer = malloc(file_size);

    while (cluster != 0xFFF) {
        unsigned int sector = fat_sectors[cluster].first_sector;
        fseek(disk_image, sector * SECTOR_SIZE, SEEK_SET);
        fread(buffer, 1, SECTOR_SIZE, disk_image);
        cluster = fat_sectors[cluster].num_sectors;
    }

    FILE *file = fopen(filename, "wb");
    fwrite(buffer, 1, file_size, file);
    fclose(file);

    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <disk image>\n", argv[0]);
        return 1;
    }

    disk_image = fopen(argv[1], "rb");
    if (disk_image == NULL) {
        printf("Error opening disk image\n");
        return 1;
    }

    load_fat_table();
    load_fat_sectors();
    load_data_area();

    for (int i = 0; i < 256; i++) {
        FAT_ENTRY *entry = &fat_table[i];
        if (entry->filename[0] != 0) {
            print_file_info(entry);
            recover_file(entry);
        }
    }

    fclose(disk_image);
    free(fat_table);
    free(fat_sectors);
    free(data_area);

    return 0;
}