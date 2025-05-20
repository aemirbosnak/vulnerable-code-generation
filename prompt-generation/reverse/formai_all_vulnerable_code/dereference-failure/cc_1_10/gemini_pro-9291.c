//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#define BLK_SZ 512

typedef struct {
    char name[12];
    uint32_t f_size;
    uint32_t st_blk;
} fat_entry;

typedef struct {
    uint8_t jmp[3];
    char oem_id[8];
} boot_sector;

typedef struct {
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t num_fats;
    uint16_t num_sectors;
    uint16_t num_hidden_sectors;
    uint8_t num_heads;
} bpb;

typedef struct {
    fat_entry entries[512];
} fat;

bool is_fat32(bpb *bpb) {
    return bpb->bytes_per_sector == 512 && bpb->sectors_per_cluster <= 128;
}

fat *read_fat(FILE *f, bpb *bpb) {
    fseek(f, bpb->num_hidden_sectors * bpb->bytes_per_sector, SEEK_SET);
    fat *fat = malloc(sizeof(fat) * bpb->num_fats);
    for (int i = 0; i < bpb->num_fats; i++) {
        fread(&fat[i], sizeof(fat), 1, f);
    }
    return fat;
}

void print_fat(fat *fat, int num_fats) {
    for (int i = 0; i < num_fats; i++) {
        printf("FAT %d:\n", i + 1);
        for (int j = 0; j < 512; j++) {
            printf("%08x: %08x\n", j, fat[i].entries[j].f_size);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <fat32 image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    boot_sector bs;
    fread(&bs, sizeof(bs), 1, f);
    if (memcmp(bs.jmp, "\xeb\x58\x90", 3) != 0) {
        printf("Invalid FAT32 boot sector\n");
        return EXIT_FAILURE;
    }

    bpb bpb;
    fseek(f, 13, SEEK_SET);
    fread(&bpb, sizeof(bpb), 1, f);

    if (!is_fat32(&bpb)) {
        printf("Not a FAT32 image\n");
        return EXIT_FAILURE;
    }

    fat *fat = read_fat(f, &bpb);
    print_fat(fat, bpb.num_fats);

    fclose(f);
    free(fat);

    return EXIT_SUCCESS;
}