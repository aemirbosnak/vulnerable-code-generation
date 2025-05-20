//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Function to simulate file system operations
void fileSystemSimulation(int argc, char* argv[]) {
    int numArgs = argc;

    printf("Simulating file system operations...\n");

    // Iterate over command line arguments
    for (int i = 1; i < argc; i++) {
        // Check if the argument is "create"
        if (strcmp(argv[i], "create") == 0) {
            // Get the filename from the next argument
            char* filename = argv[i + 1];

            // Allocate memory for the file data
            char* fileData = (char*)malloc(100);

            // Fill file data with some random characters
            for (int j = 0; j < 100; j++) {
                fileData[j] = 'A' + rand() % 26;
            }

            // Open the file for writing
            FILE* file = fopen(filename, "w");

            // Write file data to the file
            fwrite(fileData, 100, 1, file);

            // Close the file
            fclose(file);

            // Print success message
            printf("File created: %s\n", filename);

        } else if (strcmp(argv[i], "read") == 0) {
            // Get the filename from the next argument
            char* filename = argv[i + 1];

            // Open the file for reading
            FILE* file = fopen(filename, "r");

            // Read file data
            char* fileData = (char*)malloc(100);
            fread(fileData, 100, 1, file);

            // Close the file
            fclose(file);

            // Print file data
            printf("File contents: %s\n", fileData);

        } else if (strcmp(argv[i], "delete") == 0) {
            // Get the filename from the next argument
            char* filename = argv[i + 1];

            // Open the file for deleting
            FILE* file = fopen(filename, "w");

            // Write 0 bytes to the file
            fwrite("\0", 1, 0, file);

            // Close the file
            fclose(file);

            // Print success message
            printf("File deleted: %s\n", filename);

        } else if (strcmp(argv[i], "list") == 0) {
            // Print all files in the current directory
            printf("Files in current directory:\n");
            char* file = "README.md";
            FILE* fp = fopen(file, "r");
            while (fgets(file, 100, fp)!= NULL) {
                printf("%s\n", file);
            }
            fclose(fp);

        } else {
            printf("Invalid command: %s\n", argv[i]);
        }
    }

    // Clean up allocated memory
    for (int i = 1; i < argc; i++) {
        free(argv[i]);
    }
}

int main(int argc, char* argv[]) {
    fileSystemSimulation(argc, argv);
    return 0;
}