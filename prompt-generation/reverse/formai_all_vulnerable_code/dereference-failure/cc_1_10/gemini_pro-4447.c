//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <err.h>

#define SECTOR_SIZE 512
#define BLOCK_SIZE 4096

struct fat_entry {
	uint32_t cluster;
	uint8_t reserved;
	uint8_t flags;
};

struct fat_table {
	struct fat_entry *entries;
	size_t size;
};

struct disk_image {
	FILE *fp;
	uint32_t sector_count;
	uint32_t cluster_size;
	struct fat_table *fat;
};

static int
read_sector(struct disk_image *disk, uint32_t sector, void *buf)
{
	if (fseeko(disk->fp, sector * SECTOR_SIZE, SEEK_SET) < 0)
		return -1;
	if (fread(buf, SECTOR_SIZE, 1, disk->fp) != 1)
		return -1;
	return 0;
}

static int
read_fat_table(struct disk_image *disk, struct fat_table *fat)
{
	uint8_t *buf;
	size_t i;

	buf = malloc(disk->sector_count * SECTOR_SIZE);
	if (buf == NULL)
		return -1;
	if (read_sector(disk, 0, buf) < 0) {
		free(buf);
		return -1;
	}
	fat->size = disk->sector_count * SECTOR_SIZE / sizeof(struct fat_entry);
	fat->entries = malloc(fat->size * sizeof(struct fat_entry));
	if (fat->entries == NULL) {
		free(buf);
		return -1;
	}
	for (i = 0; i < fat->size; i++) {
		fat->entries[i].cluster = be32toh(*(uint32_t *)(buf + (i * sizeof(struct fat_entry))));
		fat->entries[i].reserved = *(buf + (i * sizeof(struct fat_entry)) + 4);
		fat->entries[i].flags = *(buf + (i * sizeof(struct fat_entry)) + 5);
	}
	free(buf);
	return 0;
}

static int
read_cluster(struct disk_image *disk, uint32_t cluster, void *buf)
{
	if (fseeko(disk->fp, (cluster - 2) * disk->cluster_size * SECTOR_SIZE, SEEK_SET) < 0)
		return -1;
	if (fread(buf, disk->cluster_size * SECTOR_SIZE, 1, disk->fp) != 1)
		return -1;
	return 0;
}

static int
recover_file(struct disk_image *disk, uint32_t cluster, FILE *fp)
{
	uint8_t *buf;
	size_t i;

	buf = malloc(disk->cluster_size * SECTOR_SIZE);
	if (buf == NULL)
		return -1;
	while (cluster != 0xFFFFFFFF) {
		if (read_cluster(disk, cluster, buf) < 0) {
			free(buf);
			return -1;
		}
		for (i = 0; i < disk->cluster_size * SECTOR_SIZE; i++) {
			if (buf[i] == 0)
				break;
			if (putc(buf[i], fp) == EOF) {
				free(buf);
				return -1;
			}
		}
		cluster = disk->fat->entries[cluster].cluster;
	}
	free(buf);
	return 0;
}

static int
recover_files(struct disk_image *disk)
{
	uint32_t cluster;
	FILE *fp;
	char filename[256];

	for (cluster = 2; cluster < disk->fat->size; cluster++) {
		if (disk->fat->entries[cluster].flags == 0x00)
			continue;
		if (disk->fat->entries[cluster].flags == 0x0F) {
			sprintf(filename, "file%d.txt", cluster);
			fp = fopen(filename, "wb");
			if (fp == NULL)
				return -1;
			if (recover_file(disk, cluster, fp) < 0) {
				fclose(fp);
				return -1;
			}
			fclose(fp);
		}
	}
	return 0;
}

int
main(int argc, char *argv[])
{
	struct disk_image disk;
	struct fat_table fat;
	FILE *fp;

	if (argc != 2)
		errx(1, "Usage: %s <disk image>", argv[0]);
	fp = fopen(argv[1], "rb");
	if (fp == NULL)
		err(1, "fopen");
	disk.fp = fp;
	if (read_sector(&disk, 0, &disk.sector_count) < 0)
		err(1, "read_sector");
	if (read_sector(&disk, 1, &disk.cluster_size) < 0)
		err(1, "read_sector");
	if (read_fat_table(&disk, &fat) < 0)
		err(1, "read_fat_table");
	if (recover_files(&disk) < 0)
		err(1, "recover_files");
	fclose(fp);
	return 0;
}