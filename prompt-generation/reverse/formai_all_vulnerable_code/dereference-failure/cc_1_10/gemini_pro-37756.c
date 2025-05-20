//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096
#define SECTOR_SIZE 512
#define CLUSTER_SIZE 4096

typedef struct {
    uint8_t boot_jmp[3];
    uint8_t oem_name[8];
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t number_of_fats;
    uint16_t max_root_dir_entries;
    uint16_t total_sectors_in_fat;
    uint16_t sectors_per_track;
    uint16_t number_of_heads;
    uint32_t hidden_sectors;
    uint32_t total_sectors;
    uint32_t large_sector_count;
    uint8_t drive_number;
    uint8_t win_flags;
    uint8_t signature;
    uint16_t volume_id;
    uint8_t volume_label[11];
    uint8_t file_system_type[8];
} boot_sector_t;

typedef struct {
    uint8_t filename[8];
    uint8_t extension[3];
    uint8_t attributes;
    uint16_t reserved;
    uint16_t creation_time;
    uint16_t creation_date;
    uint16_t access_date;
    uint16_t first_cluster;
    uint32_t file_size;
} directory_entry_t;

typedef struct {
    uint32_t cluster;
    uint32_t next_cluster;
} fat_entry_t;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    void *image = mmap(NULL, PAGE_SIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (image == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    boot_sector_t *boot_sector = (boot_sector_t *)image;
    if (boot_sector->signature != 0xaa55) {
        fprintf(stderr, "Invalid boot sector signature\n");
        return 1;
    }

    uint32_t fat_offset = boot_sector->reserved_sectors * SECTOR_SIZE;
    uint32_t root_dir_offset = fat_offset + boot_sector->total_sectors_in_fat * SECTOR_SIZE;
    uint32_t data_area_offset = root_dir_offset + (boot_sector->max_root_dir_entries * sizeof(directory_entry_t));

    // Read the root directory
    directory_entry_t *root_dir = (directory_entry_t *)(image + root_dir_offset);

    // Iterate over the root directory entries
    for (int i = 0; i < boot_sector->max_root_dir_entries; i++) {
        directory_entry_t *entry = &root_dir[i];

        // Check if the entry is valid
        if (entry->filename[0] == 0x00 || entry->filename[0] == 0xe5) {
            continue;
        }

        // Print the entry information
        printf("%s.%s %u bytes\n", entry->filename, entry->extension, entry->file_size);

        // Recover the file data
        uint32_t cluster = entry->first_cluster;
        while (cluster != 0xffff) {
            // Read the FAT entry
            fat_entry_t *fat_entry = (fat_entry_t *)(image + fat_offset + (cluster * sizeof(fat_entry_t)));

            // Read the data cluster
            uint8_t *data_cluster = (uint8_t *)(image + data_area_offset + ((cluster - 2) * CLUSTER_SIZE));

            // Write the data cluster to a file
            FILE *f = fopen(entry->filename, "wb");
            if (f == NULL) {
                perror("fopen");
                return 1;
            }
            fwrite(data_cluster, CLUSTER_SIZE, 1, f);
            fclose(f);

            // Get the next cluster
            cluster = fat_entry->next_cluster;
        }
    }

    munmap(image, PAGE_SIZE);
    close(fd);

    return 0;
}