//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_SIZE 1024

int main(int argc, char *argv[]) {
    char *virus_sig = "virus";   // signature of the virus to detect
    char file_buf[MAX_FILE_SIZE];   // buffer to store file contents
    FILE *file = NULL;     // file pointer
    long file_size = 0;    // size of the target file
    size_t read_size = 0;  // size of the bytes read from file
    int virus_found = 0;  

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");   // open file in read binary mode
    if (!file) {
        printf("Error: Cannot open the file!\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);   // calculate the size of the file
    file_size = ftell(file);
    rewind(file);   // rewind file pointer to the beginning

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File size is too large!\n");
        return 1;
    }

    read_size = fread(file_buf, 1, file_size, file); // read file contents into buffer
    fclose(file);   // close file

    if (read_size != file_size) {
        printf("Error: Cannot read the entire file!\n");
        return 1;
    }

    for (int i = 0; i < file_size; i++) { // search for the virus signature in the buffer
        if (memcmp(&file_buf[i], virus_sig, strlen(virus_sig)) == 0) {
            printf("Virus Found!\n");
            virus_found = 1;
            break;
        }
    }

    if (!virus_found) {
        printf("Virus Not Found!\n");
    }

    return 0;
}