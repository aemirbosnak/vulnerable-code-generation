//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 1000  // Maximum path length

void print_metadata(char *filename);
char* get_extension(char *filename);
void copy_string(char *destination, char *source, int length);
void clean_string(char *string, int length);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Error: no filename provided\n");
        return 1;
    }

    char *filename = argv[1];

    printf("Metadata for %s:\n", filename);
    print_metadata(filename);

    return 0;
}

void print_metadata(char *filename)
{
    char command[MAX_PATH_LENGTH] = "file ";
    strcat(command, filename); // Append filename to command string

    FILE *fp = popen(command, "r"); // Open process for reading command output

    if (fp == NULL) {
        printf("Error: Failed to open pipe for command\n");
        return;
    }

    char metadata[MAX_PATH_LENGTH];

    if (fgets(metadata, sizeof(metadata), fp) == NULL) { // Read output from command
        printf("Error: Failed to read command output\n");
        pclose(fp);
        return;
    }

    pclose(fp); // Close process

    int file_size = strlen(metadata) - 1; // Size of metadata string, minus newline character

    char extension[10];
    char file_type[50];
    char owner[30];
    char modified_date[20];
    char file_path[MAX_PATH_LENGTH];

    // Extract metadata information from output string using substrings and index manipulation
    copy_string(file_type, metadata, strstr(metadata, ": ") - metadata);
    copy_string(extension, (strstr(file_type, " ") + 1), strlen(file_type) - (strstr(file_type, " ") - file_type));
    copy_string(owner, strstr(metadata, " owner=") + 7, strstr(metadata, " group=") - strstr(metadata, " owner=") - 7);
    copy_string(modified_date, strstr(metadata, " modified: ") + 11, strstr(metadata, ",") - strstr(metadata, " modified: ") - 11);
    copy_string(file_path, strstr(metadata, " in /") + 4, file_size - (strstr(metadata, " in /") - metadata) - 4);

    clean_string(extension, strlen(extension));
    clean_string(file_type, strlen(file_type));
    clean_string(owner, strlen(owner));
    clean_string(modified_date, strlen(modified_date));
    clean_string(file_path, strlen(file_path));

    printf("* Type: %s\n", file_type);
    printf("* Extension: %s\n", extension);
    printf("* Owner: %s\n", owner);
    printf("* Modified date: %s\n", modified_date);
    printf("* Path: %s\n", file_path);
}

char* get_extension(char *filename)
{
    char *dot = strrchr(filename, '.'); // Find last occurrence of '.' in filename

    if (!dot || dot == filename) { // If no '.' found or first character is '.', return empty string
        return "";
    }

    return dot + 1; // Return extension without '.'
}

void copy_string(char *destination, char *source, int length)
{
    for (int i = 0; i < length; ++i) {
        destination[i] = source[i];
    }
}

void clean_string(char *string, int length)
{
    for (int i = 0; i < length; ++i) {
        if (string[i] == '\n' || string[i] == '\r') { // Replace CR and LF with null terminator
            string[i] = '\0';
            break;
        }
    }
}