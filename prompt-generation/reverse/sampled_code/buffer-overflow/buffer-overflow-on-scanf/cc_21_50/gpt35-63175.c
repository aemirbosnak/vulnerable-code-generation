//FormAI DATASET v1.0 Category: File system simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10  // Maximum number of files in the file system
#define MAX_SIZE 1024  // Maximum size of each file

typedef struct {
    int file_id;
    int file_size;
    char file_data[MAX_SIZE];
} File;

File file_system[MAX_FILES];

int main() {
    int option, id, size, data;
    while (1) {
        printf("\n======== File System Simulator ========");
        printf("\n1. Create a file");
        printf("\n2. Read a file");
        printf("\n3. Write to a file");
        printf("\n4. Delete a file");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (MAX_FILES <= 0) {
                    printf("\nError: No more files can be created.");
                    break;
                }
                printf("\nEnter file ID (0-%d): ", MAX_FILES - 1);
                scanf("%d", &id);

                if (id >= 0 && id < MAX_FILES) {
                    printf("\nEnter file size (1-%d): ", MAX_SIZE);
                    scanf("%d", &size);

                    if (size >= 1 && size <= MAX_SIZE) {
                        printf("\nFile created successfully.");

                        // Update file system
                        file_system[id].file_id = id;
                        file_system[id].file_size = size;

                        // Clear the file data
                        for (int i = 0; i < size; i++) {
                            file_system[id].file_data[i] = '\0';
                        }
                    } else {
                        printf("\nError: Invalid file size.");
                    }
                } else {
                    printf("\nError: Invalid file ID.");
                }
                break;
            case 2:
                printf("\nEnter file ID (0-%d): ", MAX_FILES - 1);
                scanf("%d", &id);

                if (id >= 0 && id < MAX_FILES) {
                    printf("\nFile data:");
                    for (int i = 0; i < file_system[id].file_size; i++) {
                        printf("%c", file_system[id].file_data[i]);
                    }
                } else {
                    printf("\nError: Invalid file ID.");
                }
                break;
            case 3:
                printf("\nEnter file ID (0-%d): ", MAX_FILES - 1);
                scanf("%d", &id);

                if (id >= 0 && id < MAX_FILES) {
                    printf("\nEnter data to write: ");
                    scanf("%d", &data);

                    // Check if data exceeds file size
                    if (file_system[id].file_size == MAX_SIZE) {
                        printf("\nError: Maximum file size reached.");
                        break;
                    }

                    // Write the data to file
                    file_system[id].file_data[file_system[id].file_size] = (char) data;
                    file_system[id].file_size++;

                    printf("\nData written successfully.");
                } else {
                    printf("\nError: Invalid file ID.");
                }
                break;
            case 4:
                printf("\nEnter file ID (0-%d): ", MAX_FILES - 1);
                scanf("%d", &id);

                if (id >= 0 && id < MAX_FILES) {
                    printf("\nFile deleted successfully.");

                    // Clear the file system entry
                    file_system[id].file_id = -1;
                    file_system[id].file_size = 0;
                    for (int i = 0; i < MAX_SIZE; i++) {
                        file_system[id].file_data[i] = '\0';
                    }
                } else {
                    printf("\nError: Invalid file ID.");
                }
                break;
            case 5:
                return 0;
            default:
                printf("\nInvalid option.");
                break;
        }
    }
}