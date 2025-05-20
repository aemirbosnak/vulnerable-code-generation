//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the file system structure
typedef struct file {
    char *name;
    int size;
    time_t last_modified;
} file;

// Define the file system
typedef struct file_system {
    int num_files;
    file *files;
} file_system;

// Create a new file system
file_system *create_file_system() {
    file_system *fs = malloc(sizeof(file_system));
    fs->num_files = 0;
    fs->files = NULL;
    return fs;
}

// Add a file to the file system
void add_file(file_system *fs, char *name, int size, time_t last_modified) {
    fs->num_files++;
    fs->files = realloc(fs->files, fs->num_files * sizeof(file));
    fs->files[fs->num_files - 1] = (file){name, size, last_modified};
}

// Print the file system
void print_file_system(file_system *fs) {
    printf("File system:\n");
    for (int i = 0; i < fs->num_files; i++) {
        printf("  %s (%d bytes, last modified %s)\n", fs->files[i].name, fs->files[i].size, ctime(&fs->files[i].last_modified));
    }
}

// Generate a random file system
file_system *generate_random_file_system(int num_files) {
    file_system *fs = create_file_system();
    for (int i = 0; i < num_files; i++) {
        char name[16];
        sprintf(name, "file%d.txt", i);
        int size = rand() % 10000;
        time_t last_modified = time(NULL) - (rand() % 1000000);
        add_file(fs, name, size, last_modified);
    }
    return fs;
}

// Calculate the average file size
int average_file_size(file_system *fs) {
    int total_size = 0;
    for (int i = 0; i < fs->num_files; i++) {
        total_size += fs->files[i].size;
    }
    return total_size / fs->num_files;
}

// Calculate the standard deviation of file sizes
int standard_deviation_file_size(file_system *fs) {
    int average = average_file_size(fs);
    int sum_of_squares = 0;
    for (int i = 0; i < fs->num_files; i++) {
        sum_of_squares += (fs->files[i].size - average) * (fs->files[i].size - average);
    }
    return sqrt(sum_of_squares / (fs->num_files - 1));
}

// Main function
int main() {
    // Generate a random file system
    file_system *fs = generate_random_file_system(100);

    // Print the file system
    print_file_system(fs);

    // Calculate the average file size
    int average = average_file_size(fs);
    printf("Average file size: %d bytes\n", average);

    // Calculate the standard deviation of file sizes
    int stddev = standard_deviation_file_size(fs);
    printf("Standard deviation of file sizes: %d bytes\n", stddev);

    return 0;
}