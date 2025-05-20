//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

#define BUFFER_SIZE 4096
#define MAGIC_HEADER "DATARECOV"
#define CHUNK_SIZE 8192
#define MAX_FILES 100
#define RECOVERY_DIR "RecoveredFiles"

typedef struct {
    char filename[256];
    long filesize;
    int recovered;
} FileInfo;

void create_recovery_directory() {
    struct stat st = {0};

    if (stat(RECOVERY_DIR, &st) == -1) {
        mkdir(RECOVERY_DIR, 0700);
    }
}

void log_recovery_status(FileInfo *files, int count) {
    FILE *logfile = fopen("recovery_log.txt", "w");
    if (logfile == NULL) {
        perror("Log file creation failed");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(logfile, "Recovered: %s | Size: %ld bytes\n", files[i].filename, files[i].filesize);
    }
    fclose(logfile);
}

void recover_file(const char *source, const char *dest) {
    int source_fd = open(source, O_RDONLY);
    if (source_fd < 0) {
        perror("Source file open failed");
        return;
    }

    int dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Destination file open failed");
        close(source_fd);
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
        write(dest_fd, buffer, bytes_read);
    }

    close(source_fd);
    close(dest_fd);
}

void recover_data_files(const char *dir_name) {
    DIR *dir = opendir(dir_name);
    struct dirent *entry;
    FileInfo recovered_files[MAX_FILES];
    int recovered_count = 0;

    if (dir == NULL) {
        perror("Directory open failed");
        return;
    }

    create_recovery_directory();

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char full_path[512];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_name, entry->d_name);

            // Simulate the recovery process
            snprintf(recovered_files[recovered_count].filename, sizeof(recovered_files[recovered_count].filename), 
                     "%s/%s", RECOVERY_DIR, entry->d_name);
            
            recover_file(full_path, recovered_files[recovered_count].filename);
            recovered_files[recovered_count].filesize = access(full_path, F_OK) == 0 ? 
                                                           lseek(open(full_path, O_RDONLY), 0, SEEK_END) : 0;

            recovered_files[recovered_count].recovered = 1; // Mark as recovered
            recovered_count++;
            
            if (recovered_count >= MAX_FILES) {
                printf("Maximum file recovery limit reached!\n");
                break;
            }
        }
    }

    closedir(dir);
    log_recovery_status(recovered_files, recovered_count);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_recover>\n", argv[0]);
        return EXIT_FAILURE;
    }

    recover_data_files(argv[1]);
    printf("Data recovery process completed!\n");

    return EXIT_SUCCESS;
}