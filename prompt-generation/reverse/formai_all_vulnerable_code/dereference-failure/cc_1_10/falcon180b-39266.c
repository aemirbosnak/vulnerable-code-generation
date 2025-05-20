//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *name;
    char *signature;
} virus_t;

virus_t viruses[] = {
    {"MyDoom", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"},
    {"Sasser", "sasser"},
    {"Melissa", "Melissa"},
    {"ILOVEYOU", "ILOVEYOU"},
    {"Stuxnet", "Stuxnet"},
    {"WannaCry", "WannaCry"},
    {NULL, NULL}
};

int scan_file(char *filename) {
    FILE *fp;
    char buffer[MAX_VIRUS_LENGTH];
    size_t bytes_read;
    int found_virus = 0;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    while ((bytes_read = fread(buffer, 1, MAX_VIRUS_LENGTH, fp)) > 0) {
        for (int i = 0; viruses[i].name!= NULL; i++) {
            if (strstr(buffer, viruses[i].signature)!= NULL) {
                printf("Virus found: %s\n", viruses[i].name);
                found_virus = 1;
                break;
            }
        }
    }

    fclose(fp);
    return found_virus;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_FILE_NAME_LENGTH];
    strcpy(filename, argv[1]);

    if (scan_file(filename)) {
        printf("File is infected with a virus.\n");
    } else {
        printf("File is clean.\n");
    }

    return 0;
}