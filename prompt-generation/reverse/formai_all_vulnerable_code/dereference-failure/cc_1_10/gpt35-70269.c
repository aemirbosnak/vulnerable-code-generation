//FormAI DATASET v1.0 Category: Data recovery tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 50

typedef struct FileData {
    char filename[MAX_FILENAME_LENGTH];
    char* data;
} FileData;

int main() {
    char* disk_data = "This is some data recovered from the damaged disk";
    // In a real program, we would read the disk data from a file or device

    FileData recovered_files[MAX_FILES];
    int num_recovered_files = 0;

    // Simulate recovering some files
    char* file1_data = "This is the contents of file 1";
    char* file2_data = "This is the contents of file 2";
    char* file3_data = "This is the contents of file 3";
    char* file4_data = "This is the contents of file 4";

    char* filenames[MAX_FILES] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt"};
    char* data_ptrs[MAX_FILES] = {file1_data, file2_data, file3_data, file4_data};
    int num_files = 4;

    // Create a backup of the disk data so we can modify it for testing purposes
    char* disk_data_backup = strdup(disk_data);

    // Corrupt the disk data by replacing the contents of file 2 with garbage data
    int file2_offset = strstr(disk_data, file2_data) - disk_data;
    memset(disk_data + file2_offset, 'X', strlen(file2_data));

    // Simulate reading the disk data and recovering files
    char* current_pos = disk_data;
    while (current_pos - disk_data < strlen(disk_data)) {
        char* start_of_filename = strstr(current_pos, "Filename:");
        if (start_of_filename == NULL) {
            break;
        }
        char* end_of_filename = strstr(start_of_filename, "\n");
        if (end_of_filename == NULL) {
            break;
        }
        char filename[MAX_FILENAME_LENGTH];
        memcpy(filename, start_of_filename + strlen("Filename:"), end_of_filename - start_of_filename - strlen("Filename:"));
        filename[end_of_filename - start_of_filename - strlen("Filename:")] = '\0';

        char* start_of_data = strstr(end_of_filename, "\nData:");
        if (start_of_data == NULL) {
            break;
        }
        char* end_of_data = strstr(start_of_data, "\nEnd of data");
        if (end_of_data == NULL) {
            break;
        }
        int data_length = end_of_data - start_of_data - strlen("\nData:");
        char* data = malloc(data_length + 1);
        memcpy(data, start_of_data + strlen("\nData:"), data_length);
        data[data_length] = '\0';

        if (strcmp(filename, "") != 0 && strcmp(data, "") != 0) {
            FileData f;
            strncpy(f.filename, filename, MAX_FILENAME_LENGTH);
            f.data = data;
            recovered_files[num_recovered_files] = f;
            num_recovered_files++;
        }

        current_pos = end_of_data + strlen("\nEnd of data");
    }

    // Print the recovered files
    printf("Recovered files:\n");
    for (int i = 0; i < num_recovered_files; i++) {
        printf("%s:\n%s\n", recovered_files[i].filename, recovered_files[i].data);
    }

    // Clean up
    free(disk_data_backup);
    for (int i = 0; i < num_recovered_files; i++) {
        free(recovered_files[i].data);
    }

    return 0;
}