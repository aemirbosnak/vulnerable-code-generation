//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define INITIAL_SIZE 1024
#define BUFFER_SIZE 512

typedef struct {
    char *data;
    size_t size;
    size_t capacity;
} FileData;

FileData* createFileData(size_t initial_size) {
    FileData *file_data = malloc(sizeof(FileData));
    file_data->data = malloc(initial_size);
    file_data->size = 0;
    file_data->capacity = initial_size;
    return file_data;
}

void appendToFileData(FileData *file_data, char *buffer, size_t bytes_read) {
    if (file_data->size + bytes_read > file_data->capacity) {
        file_data->capacity *= 2;
        file_data->data = realloc(file_data->data, file_data->capacity);
    }
    memcpy(file_data->data + file_data->size, buffer, bytes_read);
    file_data->size += bytes_read;
}

void freeFileData(FileData *file_data) {
    if (file_data) {
        free(file_data->data);
        free(file_data);
    }
}

void recoverFile(const char *file_path) {
    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    FileData *file_data = createFileData(INITIAL_SIZE);
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        appendToFileData(file_data, buffer, bytes_read);
    }

    if (bytes_read == -1) {
        perror("Error reading file");
    }

    close(fd);

    // Attempt to write the recovered data to a new file
    FILE *recovered_file = fopen("recovered_file.bin", "wb");
    if (!recovered_file) {
        perror("Error creating recovered file");
        freeFileData(file_data);
        return;
    }

    fwrite(file_data->data, 1, file_data->size, recovered_file);
    fclose(recovered_file);
    
    printf("Data recovery complete. Recovered data written to recovered_file.bin\n");

    freeFileData(file_data);
}

void printFileOptions() {
    printf("Select an option:\n");
    printf("1: Recover lost data\n");
    printf("2: Exit\n");
}

int main() {
    while (1) {
        printFileOptions();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char file_path[256];
                printf("Enter the path of the file to recover: ");
                scanf("%s", file_path);
                recoverFile(file_path);
                break;
            }
            case 2:
                printf("Exiting the data recovery tool.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}