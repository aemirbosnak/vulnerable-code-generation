//GEMINI-pro DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store file metadata
typedef struct file_info {
    char *name;         // File name
    size_t size;        // File size
    char *data;         // File data
} file_info;

// Function to read a file into a file_info structure
file_info *read_file(const char *filename) {
    FILE *fp;
    file_info *fi;

    // Open the file in read-only mode
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    // Allocate memory for the file_info structure and the file data
    fi = malloc(sizeof(file_info));
    if (fi == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }
    fi->name = strdup(filename);
    if (fi->name == NULL) {
        perror("strdup");
        free(fi);
        fclose(fp);
        return NULL;
    }
    fi->size = size;
    fi->data = malloc(size);
    if (fi->data == NULL) {
        perror("malloc");
        free(fi->name);
        free(fi);
        fclose(fp);
        return NULL;
    }

    // Read the file data into the buffer
    if (fread(fi->data, 1, size, fp) != size) {
        perror("fread");
        free(fi->data);
        free(fi->name);
        free(fi);
        fclose(fp);
        return NULL;
    }

    // Close the file
    fclose(fp);

    // Return the file_info structure
    return fi;
}

// Function to write a file_info structure to a file
int write_file(const file_info *fi, const char *filename) {
    FILE *fp;

    // Open the file in write-only mode
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Write the file data to the file
    if (fwrite(fi->data, 1, fi->size, fp) != fi->size) {
        perror("fwrite");
        fclose(fp);
        return -1;
    }

    // Close the file
    fclose(fp);

    // Return 0 on success
    return 0;
}

// Function to print the contents of a file_info structure
void print_file_info(const file_info *fi) {
    printf("Name: %s\n", fi->name);
    printf("Size: %zu bytes\n", fi->size);
    printf("Data:\n%s\n", fi->data);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return -1;
    }

    // Read the input file
    file_info *fi = read_file(argv[1]);
    if (fi == NULL) {
        fprintf(stderr, "Error reading input file\n");
        return -1;
    }

    // Print the file info
    print_file_info(fi);

    // Write the output file
    if (write_file(fi, argv[2]) != 0) {
        fprintf(stderr, "Error writing output file\n");
        free(fi->data);
        free(fi->name);
        free(fi);
        return -1;
    }

    // Free the file info structure
    free(fi->data);
    free(fi->name);
    free(fi);

    return 0;
}