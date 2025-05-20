//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 1024) // 1GB

typedef struct {
    char magic[2];
    int version;
    int num_entries;
    struct entry {
        int inode;
        int size;
    } entries[0];
} superblock;

typedef struct {
    int inode;
    int size;
    char data[0];
} inode;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    superblock sb;
    fread(&sb, sizeof(superblock), 1, fp);

    printf("Magic: %s\n", sb.magic);
    printf("Version: %d\n", sb.version);
    printf("Number of entries: %d\n", sb.num_entries);

    for (int i = 0; i < sb.num_entries; i++) {
        inode *in = (inode *)&sb.entries[i];
        printf("Inode %d, size %d\n", in->inode, in->size);

        char *data = malloc(in->size);
        fseek(fp, in->inode * sb.version, SEEK_SET);
        fread(data, in->size, 1, fp);

        printf("Data:\n%s\n", data);
        free(data);
    }

    fclose(fp);
    return 0;
}