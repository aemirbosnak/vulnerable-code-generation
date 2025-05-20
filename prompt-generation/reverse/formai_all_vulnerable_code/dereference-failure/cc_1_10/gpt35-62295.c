//FormAI DATASET v1.0 Category: File system simulation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This program simulates a file system using
 * a binary file as a disk. */

#define SECTOR_SIZE 256
#define MAX_FILE_SIZE 1024

struct file_system {
    char* disk_name;
    FILE* disk_file;
    int disk_size;
};

struct file_entry {
    char filename[20];
    int file_size;
    int starting_sector;
};

void initialize_filesystem(struct file_system* fs, char* disk_name, int disk_size) {
    /* Create a binary file with given name
     * and size to simulate the disk */
    fs->disk_name = disk_name;
    fs->disk_size = disk_size;
    fs->disk_file = fopen(fs->disk_name, "wb+");
    char sector[SECTOR_SIZE];
    /* Fill the disk with empty sectors */
    memset(sector, 0, SECTOR_SIZE);
    for(int i=0; i<disk_size; i++) {
        fwrite(sector, sizeof(char), SECTOR_SIZE, fs->disk_file);
    }
    /* Write the file system structure at the beginning of the disk */
    fseek(fs->disk_file, 0, SEEK_SET);
    fwrite(fs, sizeof(struct file_system), 1, fs->disk_file);
}

void create_file(struct file_system* fs, char* filename, char* data) {
    /* Write the file content to the disk
     * and update the file system structure */
    fseek(fs->disk_file, 0, SEEK_SET);
    fread(fs, sizeof(struct file_system), 1, fs->disk_file);
    struct file_entry entry;
    strcpy(entry.filename, filename);
    entry.file_size = strlen(data);
    /* Find a free sector to write the file content */
    fseek(fs->disk_file, sizeof(struct file_system), SEEK_SET);
    char sector[SECTOR_SIZE];
    memset(sector, 0, SECTOR_SIZE);
    int free_sector = -1;
    for(int i=0; i<fs->disk_size; i++) {
        fread(sector, sizeof(char), SECTOR_SIZE, fs->disk_file);
        if(memcmp(sector, "\0", SECTOR_SIZE) == 0) {
            free_sector = i;
            fseek(fs->disk_file, i*SECTOR_SIZE, SEEK_SET);
            fwrite(data, sizeof(char), entry.file_size, fs->disk_file);
            break;
        }
    }
    if(free_sector == -1) {
        printf("Disk is full. Cannot create file.\n");
        return;
    }
    entry.starting_sector = free_sector;
    fseek(fs->disk_file, sizeof(struct file_system) + sizeof(struct file_entry)*free_sector, SEEK_SET);
    fwrite(&entry, sizeof(struct file_entry), 1, fs->disk_file);
}

void read_file(struct file_system* fs, char* filename) {
    /* Read the file content from the disk
     * based on the file system structure */
    fseek(fs->disk_file, 0, SEEK_SET);
    fread(fs, sizeof(struct file_system), 1, fs->disk_file);
    struct file_entry entry;
    int found = 0;
    /* Find the file entry corresponding to the filename */
    for(int i=0; i<fs->disk_size; i++) {
        fseek(fs->disk_file, sizeof(struct file_system) + sizeof(struct file_entry)*i, SEEK_SET);
        fread(&entry, sizeof(struct file_entry), 1, fs->disk_file);
        if(strcmp(entry.filename, filename) == 0) {
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("File not found.\n");
        return;
    }
    /* Read the file content from the disk */
    char sector[SECTOR_SIZE];
    memset(sector, 0, SECTOR_SIZE);
    fseek(fs->disk_file, entry.starting_sector*SECTOR_SIZE, SEEK_SET);
    fread(sector, sizeof(char), entry.file_size, fs->disk_file);
    printf("%s", sector);
}

int main() {
    struct file_system fs;
    char* disk_name = "disk.bin";
    int disk_size = 10;
    initialize_filesystem(&fs, disk_name, disk_size);
    char* filename = "hello.txt";
    char* data = "Hello World!\n";
    create_file(&fs, filename, data);
    read_file(&fs, filename);
    fclose(fs.disk_file);
    return 0;
}