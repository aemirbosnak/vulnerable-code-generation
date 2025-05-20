//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BLOCK_SIZE 512
#define FAT_SIZE 4096
#define FAT_ENTRIES 512

enum {
    FAT_UNUSED = 0x00,
    FAT_EOF = 0xff,
    FAT_BAD = 0xf7,
};

struct fat_entry {
    uint8_t value;
    uint8_t reserved;
};

struct fat_table {
    struct fat_entry entries[FAT_ENTRIES];
    uint8_t signature[2];
};

struct directory_entry {
    uint8_t filename[11];
    uint8_t attributes;
    uint8_t reserved;
    uint8_t checksum;
    uint16_t last_modified_date;
    uint16_t last_modified_time;
    uint16_t first_cluster;
    uint32_t file_size;
};

struct boot_sector {
    uint8_t jump_code[3];
    uint8_t oem_id[8];
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t number_of_fat_tables;
    uint16_t total_sectors;
    uint16_t media_descriptor;
    uint16_t sectors_per_fat;
    uint16_t sectors_per_track;
    uint16_t number_of_heads;
    uint32_t hidden_sectors;
    uint32_t total_sectors_large;
};

struct fat_file {
    struct directory_entry *dirent;
    uint32_t cluster;
    uint32_t size;
};

static int read_fat_table(int fd, struct fat_table *fat) {
    if (lseek(fd, 0, SEEK_SET) < 0)
        return -1;
    if (read(fd, fat, FAT_SIZE) != FAT_SIZE)
        return -1;
    return 0;
}

static int read_directory(int fd, uint32_t cluster, struct directory_entry *entries) {
    if (lseek(fd, cluster * BLOCK_SIZE, SEEK_SET) < 0)
        return -1;
    if (read(fd, entries, BLOCK_SIZE) != BLOCK_SIZE)
        return -1;
    return 0;
}

static int read_file(int fd, struct fat_file *file, uint8_t *buffer, size_t size) {
    if (lseek(fd, file->cluster * BLOCK_SIZE, SEEK_SET) < 0)
        return -1;
    if (read(fd, buffer, size) != size)
        return -1;
    return 0;
}

static int find_file(int fd, const char *filename, struct fat_file *file) {
    struct fat_table fat;
    struct directory_entry entries[16];
    uint32_t cluster = 2;
    uint32_t size = 0;

    while (cluster != FAT_EOF) {
        if (read_directory(fd, cluster, entries) < 0)
            return -1;
        for (int i = 0; i < 16; i++) {
            if (entries[i].filename[0] == 0x00)
                break;
            if (entries[i].attributes & 0x10)
                continue;
            if (strcmp((char *) entries[i].filename, filename) == 0) {
                file->dirent = &entries[i];
                file->cluster = entries[i].first_cluster;
                file->size = entries[i].file_size;
                return 0;
            }
        }
        if (read_fat_table(fd, &fat) < 0)
            return -1;
        cluster = fat.entries[cluster].value;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image> <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct fat_table fat;
    if (read_fat_table(fd, &fat) < 0) {
        perror("read_fat_table");
        return 1;
    }

    struct fat_file file;
    if (find_file(fd, argv[2], &file) < 0) {
        fprintf(stderr, "File not found\n");
        return 1;
    }

    uint8_t buffer[file.size];
    if (read_file(fd, &file, buffer, file.size) < 0) {
        perror("read_file");
        return 1;
    }

    char filename[1024];
    snprintf(filename, sizeof(filename), "%s.recovered", argv[2]);
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    fwrite(buffer, file.size, 1, fp);
    fclose(fp);

    close(fd);
    return 0;
}