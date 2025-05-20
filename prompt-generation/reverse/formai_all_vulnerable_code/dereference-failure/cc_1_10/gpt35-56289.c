//FormAI DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

struct partition {
    int num_blocks;
    int *block_list;
    char *data;
};

typedef struct partition *Partition;

Partition create_partition(int num_blocks) {
    Partition p = (Partition) malloc(sizeof(struct partition));
    if (p == NULL) {
        printf("Error allocating partition!\n");
        exit(1);
    }
    p->num_blocks = num_blocks;
    p->block_list = (int *) calloc(num_blocks, sizeof(int));
    p->data = (char *) calloc(num_blocks * BLOCK_SIZE, sizeof(char));
    if (p->block_list == NULL || p->data == NULL) {
        printf("Error allocating memory for partition blocks!\n");
        exit(1);
    }
    return p;
}

void delete_partition(Partition p) {
    free(p->block_list);
    free(p->data);
    free(p);
}

Partition read_partition(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening partition!\n");
        exit(1);
    }
    int num_blocks;
    if (fread(&num_blocks, sizeof(int), 1, fp) != 1) {
        printf("Error reading partition header!\n");
        exit(1);
    }
    Partition p = create_partition(num_blocks);
    if (fread(p->block_list, sizeof(int), num_blocks, fp) != num_blocks) {
        printf("Error reading partition block list!\n");
        exit(1);
    }
    char buffer[BLOCK_SIZE];
    for (int i = 0; i < num_blocks; i++) {
        if (fread(buffer, sizeof(char), BLOCK_SIZE, fp) != BLOCK_SIZE) {
            printf("Error reading partition block!\n");
            exit(1);
        }
        strncpy(p->data + i * BLOCK_SIZE, buffer, BLOCK_SIZE);
    }
    fclose(fp);
    return p;
}

void write_partition(Partition p, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening partition!\n");
        exit(1);
    }
    fwrite(&p->num_blocks, sizeof(int), 1, fp);
    fwrite(p->block_list, sizeof(int), p->num_blocks, fp);
    char buffer[BLOCK_SIZE];
    for (int i = 0; i < p->num_blocks; i++) {
        strncpy(buffer, p->data + i * BLOCK_SIZE, BLOCK_SIZE);
        fwrite(buffer, sizeof(char), BLOCK_SIZE, fp);
    }
    fclose(fp);
}

void print_block_list(Partition p) {
    for (int i = 0; i < p->num_blocks; i++) {
        if (p->block_list[i])
            printf("%d: %s\n", i, p->data + i * BLOCK_SIZE);
        else
            printf("%d: empty\n", i);
    }
}

void recover_data(Partition p) {
    for (int i = 0; i < p->num_blocks; i++) {
        p->block_list[i] = 1;
    }
    printf("Recovered data!\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <partition>\n", argv[0]);
        exit(1);
    }
    Partition p = read_partition(argv[1]);
    recover_data(p);
    print_block_list(p);
    write_partition(p, "recovered_partition.bin");
    delete_partition(p);
    return 0;
}