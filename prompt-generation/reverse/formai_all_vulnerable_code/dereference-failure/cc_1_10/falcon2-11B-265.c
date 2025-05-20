//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char **argv) {
    // Check for correct usage
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <directory> <output_file>\n", argv[0]);
        return 1;
    }
    
    // Get input and output file names
    char *directory = argv[1];
    char *output_file = argv[2];
    
    // Open input and output files
    int input_fd = open(directory, O_RDONLY);
    int output_fd = open(output_file, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    
    // Read directory contents
    struct dirent *entry;
    while ((entry = readdir(input_fd))!= NULL) {
        // Skip. and.. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Open file for reading
        int file_fd = open(entry->d_name, O_RDONLY);
        if (file_fd == -1) {
            perror("Error opening file");
            continue;
        }
        
        // Read file contents
        char buffer[1024];
        while (read(file_fd, buffer, sizeof(buffer)) > 0) {
            // Write to output file
            write(output_fd, buffer, strlen(buffer));
        }
        
        // Close file
        close(file_fd);
    }
    
    // Close input and output files
    close(input_fd);
    close(output_fd);
    
    return 0;
}