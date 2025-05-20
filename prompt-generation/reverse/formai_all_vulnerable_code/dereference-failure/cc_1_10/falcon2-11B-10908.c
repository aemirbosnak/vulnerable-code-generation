//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to split a string into tokens based on a delimiter
char** split_string(char* str, char* delim) {
    char** tokens = (char**)malloc(sizeof(char*) * (strlen(str) / strlen(delim) + 1));
    char* token = strtok(str, delim);
    int i = 0;
    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, delim);
    }
    return tokens;
}

// Function to read a log file and print the IP addresses
void read_log(char* filename, int* num_ips) {
    DIR* dir;
    struct dirent* entry;
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    char* token;
    char* delim = " ";

    // Open the log file for reading
    dir = opendir(filename);
    if (dir == NULL) {
        printf("Failed to open directory: %s\n", filename);
        return;
    }

    // Loop through each file in the directory
    while ((entry = readdir(dir))!= NULL) {
        // Skip directories and files that are not log files
        if (strncmp(entry->d_name, "log", 3)!= 0 || (fp = fopen(entry->d_name, "r")) == NULL)
            continue;

        // Read the contents of the log file
        while ((read = getline(&line, &len, fp))!= -1) {
            // Split the line into tokens based on whitespace
            token = strtok(line, delim);
            while (token!= NULL) {
                // Count the occurrences of each IP address
                if (strcmp(token, "10.0.0.1") == 0) {
                    (*num_ips)++;
                }
                token = strtok(NULL, delim);
            }
        }

        // Close the file
        fclose(fp);
    }

    // Close the directory
    closedir(dir);
}

// Function to print the results
void print_results(int num_ips) {
    int i;

    // Print the number of occurrences of each IP address
    for (i = 0; i < num_ips; i++) {
        printf("%s: %d\n", "10.0.0.1", i);
    }
}

int main(int argc, char** argv) {
    int num_ips = 0;

    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Call the function to read the log files
    read_log(argv[1], &num_ips);

    // Print the results
    print_results(num_ips);

    return 0;
}