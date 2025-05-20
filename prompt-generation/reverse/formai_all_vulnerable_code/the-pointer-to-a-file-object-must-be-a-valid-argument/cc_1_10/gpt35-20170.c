//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256
#define MAX_SCAN_SIZE 1024

void scan_file(char* filename);
void scan_directory(char* directory);
int is_virus(char* content);

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("No filename or directory provided.\n");
        exit(1);
    }
    if(argc == 2) {
        scan_file(argv[1]);
    } else {
        scan_directory(argv[1]);
    }
    printf("Scan complete.\n");
    return 0;
}

void scan_file(char* filename) {
    FILE* fp;
    char content[MAX_SCAN_SIZE];
    int size;

    fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Unable to open file: %s\n", filename);
        return;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if(size > MAX_SCAN_SIZE) {
        printf("File too large to scan: %s\n", filename);
        fclose(fp);
        return;
    }

    fread(content, 1, size, fp);
    fclose(fp);

    if(is_virus(content)) {
        printf("Virus found in file: %s\n", filename);
        // Code to remove virus goes here
    }
}

void scan_directory(char* directory) {
    char filename[MAX_FILENAME_SIZE];
    sprintf(filename, "%s/*", directory);
    char command[MAX_FILENAME_SIZE+10];
    sprintf(command, "ls %s", filename);

    FILE* cmd_fp = popen(command, "r");

    while(fgets(filename, MAX_FILENAME_SIZE, cmd_fp)) {
        filename[strcspn(filename, "\n")] = 0;
        scan_file(filename);
    }

    pclose(cmd_fp);
}

int is_virus(char* content) {
    // Simplistic virus scanner that just looks for the string "virus"
    return strstr(content, "virus") != NULL;
}