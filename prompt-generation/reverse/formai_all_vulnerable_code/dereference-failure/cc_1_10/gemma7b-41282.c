//Gemma-7B DATASET v1.0 Category: System administration ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_CMD_LEN 255

int main() {

    char cmd[MAX_CMD_LEN];
    int cmd_len;
    struct stat sb;
    char *filename;
    FILE *fp;

    printf("Protected C System Administration Example\n");
    printf("Enter a command: ");

    // Get the command length and store it in cmd_len
    cmd_len = getline(cmd, MAX_CMD_LEN, stdin);

    // Check if the command length is greater than the maximum command length
    if (cmd_len > MAX_CMD_LEN - 1) {
        printf("Error: Command length too long.\n");
        return 1;
    }

    // Extract the filename from the command
    filename = strchr(cmd, '/');

    // If there is no filename, prompt the user to enter one
    if (filename == NULL) {
        printf("Error: No filename specified.\n");
        return 1;
    }

    // Remove the filename from the command
    *filename = '\0';

    // Open the file
    fp = fopen(filename, "r");

    // If the file is not open, print an error message
    if (fp == NULL) {
        printf("Error: File not open.\n");
        return 1;
    }

    // Get the file status
    stat(filename, &sb);

    // Print the file status
    printf("File status:\n");
    printf("  Size: %d bytes\n", sb.st_size);
    printf("  Permissions: %o\n", sb.st_mode & 0777);
    printf("  Owner: %u\n", sb.st_uid);
    printf("  Group: %u\n", sb.st_gid);

    // Close the file
    fclose(fp);

    return 0;
}