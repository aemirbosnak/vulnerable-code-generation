//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAT_ENTRY_SIZE 4
#define SECTOR_SIZE 512
#define ROOT_DIR_ENTRIES 512

typedef struct {
    char name[8];
    char ext[3];
    char attr;
    char reserved[10];
    short time;
    short date;
    short cluster;
    int size;
} dir_entry;

void print_dir_entry(dir_entry entry) {
    printf("%s.%s %d\n", entry.name, entry.ext, entry.size);
}

int read_sector(FILE *file, int sector_num, char *buffer) {
    fseek(file, sector_num * SECTOR_SIZE, SEEK_SET);
    return fread(buffer, 1, SECTOR_SIZE, file);
}

int read_fat_entry(FILE *file, int entry_num) {
    char buffer[FAT_ENTRY_SIZE];
    fseek(file, 4 + entry_num * FAT_ENTRY_SIZE, SEEK_SET);
    fread(buffer, 1, FAT_ENTRY_SIZE, file);
    return *(int*)buffer;
}

void recover_file(FILE *file, int start_cluster, int file_size) {
    char buffer[SECTOR_SIZE];
    int current_cluster = start_cluster;
    int bytes_left = file_size;

    while (bytes_left > 0 && current_cluster != -1) {
        int sector_num = 31 + current_cluster;
        int bytes_read = read_sector(file, sector_num, buffer);
        fwrite(buffer, 1, bytes_read, stdout);
        bytes_left -= bytes_read;
        current_cluster = read_fat_entry(file, current_cluster);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    char buffer[SECTOR_SIZE];
    read_sector(file, 0, buffer);
    int bytes_per_sector = *(short*)(buffer+11);
    int sectors_per_cluster = *(buffer+13);
    int reserved_sectors = *(short*)(buffer+14);
    int num_fat_tables = *(buffer+16);
    int sectors_per_fat = *(int*)(buffer+36);

    int root_dir_sectors = (ROOT_DIR_ENTRIES * 32) / bytes_per_sector;
    int first_data_sector = reserved_sectors + num_fat_tables * sectors_per_fat + root_dir_sectors;
    int cluster_size = bytes_per_sector * sectors_per_cluster;

    fseek(file, reserved_sectors * SECTOR_SIZE, SEEK_SET);
    fread(buffer, 1, SECTOR_SIZE, file);
    int signature = *(int*)(buffer+508);
    if (signature != 0x54414646) {
        printf("File system is not FAT32\n");
        return 1;
    }

    fseek(file, reserved_sectors * SECTOR_SIZE + root_dir_sectors * SECTOR_SIZE, SEEK_SET);
    while (1) {
        dir_entry entry;
        fread(&entry, sizeof(entry), 1, file);
        if (entry.name[0] == 0xE5) {
            continue;
        } else if (entry.name[0] == 0x00) {
            break;
        } else if (entry.attr & 0x08) {
            continue;
        } else {
            print_dir_entry(entry);
            recover_file(file, entry.cluster, entry.size);
        }
    }

    fclose(file);
    return 0;
}