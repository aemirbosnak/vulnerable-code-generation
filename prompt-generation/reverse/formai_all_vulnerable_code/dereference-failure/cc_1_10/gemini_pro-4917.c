//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BOOT_SECTOR_SIZE 512
#define MAX_FILESYSTEMS 4
#define MAX_FILES_PER_FILESYSTEM 8

typedef struct {
    char name[32];
    uint32_t start_sector;
    uint32_t num_sectors;
} file_entry_t;

typedef struct {
    char name[16];
    uint32_t start_sector;
    uint32_t num_sectors;
    file_entry_t files[MAX_FILES_PER_FILESYSTEM];
} filesystem_entry_t;

typedef struct {
    filesystem_entry_t filesystems[MAX_FILESYSTEMS];
    uint32_t num_filesystems;
} boot_sector_t;

int main() {
    boot_sector_t boot_sector;
    FILE *fp;

    // Parse the boot sector from the disk image
    fp = fopen("disk.img", "rb");
    if (fp == NULL) {
        perror("Error opening disk image");
        return EXIT_FAILURE;
    }
    fread(&boot_sector, sizeof(boot_sector), 1, fp);
    fclose(fp);

    // Print the boot sector information
    printf("Boot sector:\n");
    printf("  Number of filesystems: %d\n", boot_sector.num_filesystems);
    for (int i = 0; i < boot_sector.num_filesystems; i++) {
        filesystem_entry_t *fs = &boot_sector.filesystems[i];
        printf("  Filesystem %d:\n", i + 1);
        printf("    Name: %s\n", fs->name);
        printf("    Start sector: %d\n", fs->start_sector);
        printf("    Number of sectors: %d\n", fs->num_sectors);
        printf("    Files:\n");
        for (int j = 0; j < MAX_FILES_PER_FILESYSTEM; j++) {
            file_entry_t *file = &fs->files[j];
            if (file->name[0] == '\0') {
                continue;
            }
            printf("      - %s (%d sectors)\n", file->name, file->num_sectors);
        }
    }

    return EXIT_SUCCESS;
}