//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the contents of a file
void read_file(FILE *fp, char *buffer) {
    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    fread(buffer, file_size, 1, fp);
}

// Function to write the contents of a file
void write_file(FILE *fp, char *buffer) {
    fwrite(buffer, strlen(buffer), 1, fp);
}

// Function to find the start of a file
int find_start(char *buffer) {
    int start = 0;
    while (buffer[start]!= '\0') {
        if (buffer[start] == '\n') {
            return start + 1;
        }
        start++;
    }
    return 0;
}

// Function to find the end of a file
int find_end(char *buffer) {
    int end = strlen(buffer) - 1;
    while (buffer[end]!= '\n') {
        end--;
    }
    return end;
}

// Function to recover data from a corrupted file
void recover_data(char *filename) {
    FILE *fp = fopen(filename, "r+");
    char buffer[100000];
    read_file(fp, buffer);
    int start = find_start(buffer);
    int end = find_end(buffer);
    buffer[end] = '\0';
    write_file(fp, buffer);
    fclose(fp);
}

int main() {
    char filename[50];
    printf("Enter the name of the corrupted file: ");
    scanf("%s", filename);
    recover_data(filename);
    printf("Data recovery complete!\n");
    return 0;
}