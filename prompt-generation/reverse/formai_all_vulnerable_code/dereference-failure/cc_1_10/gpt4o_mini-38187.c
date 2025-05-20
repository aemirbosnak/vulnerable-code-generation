//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_usage(const char *program_name) {
    printf("Usage: %s <source_file> <backup_file>\n", program_name);
    printf("Backs up the specified source file to the designated backup file.\n");
}

int copy_file(const char *source, const char *destination) {
    FILE *src_file = fopen(source, "rb");
    if (src_file == NULL) {
        fprintf(stderr, "Error opening source file '%s': %s\n", source, strerror(errno));
        return -1;
    }

    FILE *dest_file = fopen(destination, "wb");
    if (dest_file == NULL) {
        fclose(src_file);
        fprintf(stderr, "Error opening destination file '%s': %s\n", destination, strerror(errno));
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);

    if (ferror(src_file)) {
        fprintf(stderr, "Error reading from source file '%s': %s\n", source, strerror(errno));
        return -1;
    }

    if (ferror(dest_file)) {
        fprintf(stderr, "Error writing to destination file '%s': %s\n", destination, strerror(errno));
        return -1;
    }

    return 0;
}

int verify_backup(const char *source, const char *destination) {
    struct stat source_stat, dest_stat;

    if (stat(source, &source_stat) != 0) {
        fprintf(stderr, "Error getting information for source file '%s': %s\n", source, strerror(errno));
        return -1;
    }

    if (stat(destination, &dest_stat) != 0) {
        fprintf(stderr, "Error getting information for backup file '%s': %s\n", destination, strerror(errno));
        return -1;
    }

    if (source_stat.st_size != dest_stat.st_size) {
        fprintf(stderr, "Backup file size does not match! Source: %ld, Backup: %ld\n",
                source_stat.st_size, dest_stat.st_size);
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source = argv[1];
    const char *backup = argv[2];

    // Step 1: Copy the file
    if (copy_file(source, backup) != 0) {
        return EXIT_FAILURE;
    }

    // Step 2: Verify the backup
    if (verify_backup(source, backup) != 0) {
        fprintf(stderr, "Backup verification failed.\n");
        return EXIT_FAILURE;
    }

    printf("Backup of '%s' successfully created as '%s'.\n", source, backup);
    return EXIT_SUCCESS;
}