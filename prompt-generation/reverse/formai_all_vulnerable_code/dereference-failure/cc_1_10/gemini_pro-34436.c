//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

// File structure
typedef struct {
    char name[256];
    char contents[MAX_FILE_SIZE];
    int size;
} File;

// Backup system structure
typedef struct {
    File files[MAX_FILES];
    int num_files;
} BackupSystem;

// Create a new backup system
BackupSystem* create_backup_system() {
    BackupSystem* bs = malloc(sizeof(BackupSystem));
    bs->num_files = 0;
    return bs;
}

// Add a file to the backup system
void add_file(BackupSystem* bs, File file) {
    if (bs->num_files < MAX_FILES) {
        bs->files[bs->num_files++] = file;
    }
}

// Restore a file from the backup system
File* restore_file(BackupSystem* bs, char* name) {
    for (int i = 0; i < bs->num_files; i++) {
        if (strcmp(bs->files[i].name, name) == 0) {
            return &bs->files[i];
        }
    }
    return NULL;
}

// Save the backup system to a file
void save_backup_system(BackupSystem* bs, char* filename) {
    FILE* fp = fopen(filename, "w");
    fwrite(&bs->num_files, sizeof(int), 1, fp);
    for (int i = 0; i < bs->num_files; i++) {
        fwrite(&bs->files[i], sizeof(File), 1, fp);
    }
    fclose(fp);
}

// Load the backup system from a file
BackupSystem* load_backup_system(char* filename) {
    FILE* fp = fopen(filename, "r");
    BackupSystem* bs = create_backup_system();
    fread(&bs->num_files, sizeof(int), 1, fp);
    for (int i = 0; i < bs->num_files; i++) {
        fread(&bs->files[i], sizeof(File), 1, fp);
    }
    fclose(fp);
    return bs;
}

// Print the backup system
void print_backup_system(BackupSystem* bs) {
    printf("Backup System:\n");
    for (int i = 0; i < bs->num_files; i++) {
        printf("\t%s (%d bytes)\n", bs->files[i].name, bs->files[i].size);
    }
}

// Main function
int main() {
    // Create a new backup system
    BackupSystem* bs = create_backup_system();

    // Add some files to the backup system
    File file1 = {"file1.txt", "Hello, world!", 13};
    add_file(bs, file1);
    File file2 = {"file2.txt", "This is a test file.", 20};
    add_file(bs, file2);

    // Print the backup system
    print_backup_system(bs);

    // Save the backup system to a file
    save_backup_system(bs, "backup.dat");

    // Load the backup system from a file
    BackupSystem* bs2 = load_backup_system("backup.dat");

    // Print the backup system
    print_backup_system(bs2);

    // Restore a file from the backup system
    File* file3 = restore_file(bs2, "file1.txt");

    // Print the restored file
    printf("Restored file: %s (%d bytes)\n", file3->name, file3->size);
    printf("%s\n", file3->contents);

    return 0;
}