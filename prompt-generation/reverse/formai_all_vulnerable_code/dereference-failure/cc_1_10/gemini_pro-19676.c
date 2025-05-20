//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SECTOR_SIZE 512
#define MAX_SECTORS 1024

typedef struct {
    unsigned char* data;
    size_t size;
} sector_t;

typedef struct {
    sector_t* sectors;
    size_t num_sectors;
} disk_t;

disk_t* disk_open(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    disk_t* disk = malloc(sizeof(disk_t));
    if (disk == NULL) {
        fclose(file);
        return NULL;
    }

    disk->sectors = malloc(sizeof(sector_t) * MAX_SECTORS);
    if (disk->sectors == NULL) {
        free(disk);
        fclose(file);
        return NULL;
    }

    disk->num_sectors = 0;

    sector_t* sector = disk->sectors;
    while (fread(sector->data, SECTOR_SIZE, 1, file) == 1) {
        sector->size = SECTOR_SIZE;
        sector++;
        disk->num_sectors++;
    }

    fclose(file);

    return disk;
}

void disk_close(disk_t* disk) {
    for (size_t i = 0; i < disk->num_sectors; i++) {
        free(disk->sectors[i].data);
    }
    free(disk->sectors);
    free(disk);
}

sector_t* disk_read_sector(disk_t* disk, size_t sector_number) {
    if (sector_number >= disk->num_sectors) {
        return NULL;
    }

    return &disk->sectors[sector_number];
}

int disk_write_sector(disk_t* disk, size_t sector_number, const unsigned char* data, size_t size) {
    if (sector_number >= disk->num_sectors) {
        return -1;
    }

    sector_t* sector = &disk->sectors[sector_number];
    if (size > sector->size) {
        return -1;
    }

    memcpy(sector->data, data, size);
    return 0;
}

void print_hex(const unsigned char* data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    disk_t* disk = disk_open(argv[1]);
    if (disk == NULL) {
        printf("Error opening disk image\n");
        return 1;
    }

    sector_t* sector = disk_read_sector(disk, 0);
    if (sector == NULL) {
        printf("Error reading sector 0\n");
        disk_close(disk);
        return 1;
    }

    printf("Sector 0:\n");
    print_hex(sector->data, sector->size);

    sector = disk_read_sector(disk, 1);
    if (sector == NULL) {
        printf("Error reading sector 1\n");
        disk_close(disk);
        return 1;
    }

    printf("Sector 1:\n");
    print_hex(sector->data, sector->size);

    disk_close(disk);

    return 0;
}