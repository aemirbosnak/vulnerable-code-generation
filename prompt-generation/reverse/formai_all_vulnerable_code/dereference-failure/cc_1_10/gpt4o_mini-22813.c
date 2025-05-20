//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_SIZE 4096
#define MAX_FILES 10

void perform_recovery(const char *file_path, int recovery_attempt);
void display_recovery_status(const char *file_name, int status);
void restore_file(const char *original_path, const char *restore_path);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_to_recover>\n", argv[0]);
        return 1;
    }

    const char *file_to_recover = argv[1];

    // Starting the recovery process
    printf("🎉 Starting Data Recovery Tool... 🎉\n");
    for (int attempt = 1; attempt <= MAX_FILES; attempt++) {
        printf("🔍 Attempting recovery number %d for file: %s...\n", attempt, file_to_recover);
        perform_recovery(file_to_recover, attempt);
    }

    printf("✨ Data Recovery process completed! Please check the restored files! ✨\n");
    return 0;
}

void perform_recovery(const char *file_path, int recovery_attempt) {
    char buffer[BUFFER_SIZE];
    char restore_file_name[256];
    int input_file = open(file_path, O_RDONLY);
    
    if (input_file < 0) {
        display_recovery_status(file_path, -1);
        return;
    }
    
    // Creating a unique restore file name
    snprintf(restore_file_name, sizeof(restore_file_name), "restored_%d_%s", recovery_attempt, strrchr(file_path, '/') ? strrchr(file_path, '/') + 1 : file_path);

    int output_file = open(restore_file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    
    if (output_file < 0) {
        display_recovery_status(restore_file_name, -1);
        close(input_file);
        return;
    }

    // Attempting to read and write data
    ssize_t bytes_read;
    ssize_t bytes_written;
    while ((bytes_read = read(input_file, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(output_file, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            display_recovery_status(restore_file_name, -1);
            close(input_file);
            close(output_file);
            return;
        }
    }

    // Ending the file handling with a proper closure
    close(input_file);
    close(output_file);
    display_recovery_status(restore_file_name, 0);
}

void display_recovery_status(const char *file_name, int status) {
    if (status == 0) {
        printf("✅ Successfully recovered: %s\n", file_name);
    } else {
        printf("❌ Failed to recover: %s. Error: %s\n", file_name, strerror(errno));
    }
}