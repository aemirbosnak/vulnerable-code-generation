//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#define SECTOR_SIZE 512
#define MAX_SECTORS 10000
#define FILENAME_LENGTH 256

void print_usage(const char *prog_name) {
    printf("Usage: %s <disk_image_file> <start_sector> <num_sectors>\n", prog_name);
    printf("Example: %s /dev/sda 0 10\n", prog_name);
}

void recover_data(const char *disk_image, long start_sector, long num_sectors) {
    int fd = open(disk_image, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open disk image");
        return;
    }

    unsigned char *buffer = malloc(SECTOR_SIZE * num_sectors);
    if (!buffer) {
        perror("Failed to allocate memory");
        close(fd);
        return;
    }

    lseek(fd, start_sector * SECTOR_SIZE, SEEK_SET);
    ssize_t bytes_read = read(fd, buffer, SECTOR_SIZE * num_sectors);
    if (bytes_read < 0) {
        perror("Failed to read from disk image");
        free(buffer);
        close(fd);
        return;
    }

    char output_filename[FILENAME_LENGTH];
    snprintf(output_filename, sizeof(output_filename), "recovered_data.bin");

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Failed to open output file");
        free(buffer);
        close(fd);
        return;
    }

    fwrite(buffer, 1, bytes_read, output_file);
    printf("Data recovery successful. %ld bytes recovered to %s\n", bytes_read, output_filename);

    fclose(output_file);
    free(buffer);
    close(fd);
}

void interactive_mode() {
    char disk_image[FILENAME_LENGTH];
    long start_sector, num_sectors;

    while (1) {
        printf("Enter disk image file path (or 'exit' to quit): ");
        scanf("%s", disk_image);
        if (strcmp(disk_image, "exit") == 0) {
            break;
        }
        
        printf("Enter start sector (0 to end): ");
        scanf("%ld", &start_sector);
        
        if (start_sector < 0) {
            printf("Start sector must be non-negative.\n");
            continue;
        }

        printf("Enter number of sectors to recover: ");
        scanf("%ld", &num_sectors);
        
        if (num_sectors <= 0 || start_sector + num_sectors > MAX_SECTORS) {
            printf("Invalid number of sectors.\n");
            continue;
        }
        
        recover_data(disk_image, start_sector, num_sectors);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 4) {
        const char *disk_image = argv[1];
        long start_sector = atol(argv[2]);
        long num_sectors = atol(argv[3]);

        if (start_sector < 0 || num_sectors <= 0 || start_sector + num_sectors > MAX_SECTORS) {
            print_usage(argv[0]);
            return 1;
        }

        recover_data(disk_image, start_sector, num_sectors);
    } else if (argc == 1) {
        interactive_mode();
    } else {
        print_usage(argv[0]);
        return 1;
    }

    return 0;
}