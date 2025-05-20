//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 50
#define MAX_LINE 200
#define MAX_VIRUS_NUM 10

// Struct to store virus information
typedef struct {
    char name[MAX_LINE];
    char signature[MAX_LINE];
    int size;
} Virus;

// Function to read virus signatures from a file
int read_virus_file(FILE *fp, Virus *viruses) {
    int num_viruses = 0;
    char line[MAX_LINE];

    while (fgets(line, MAX_LINE, fp) && num_viruses < MAX_VIRUS_NUM) {
        if (line[0] == '-') {
            strcpy(viruses[num_viruses].name, line + 1);
            fgets(viruses[num_viruses].signature, MAX_LINE, fp);
            viruses[num_viruses].size = strlen(viruses[num_viruses].signature);
            num_viruses++;
        }
    }

    return num_viruses;
}

// Function to scan a file for viruses
void scan_file(FILE *fp, Virus *viruses, int num_viruses) {
    char buffer[MAX_LINE];
    int file_size, i;

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    fread(buffer, file_size, 1, fp);

    for (i = 0; i < num_viruses; i++) {
        if (strstr(buffer, viruses[i].signature) != NULL) {
            printf("%s virus detected!\n", viruses[i].name);
            return;
        }
    }

    printf("No viruses detected.\n");
}

int main(int argc, char *argv[]) {
    FILE *fp;
    Virus viruses[MAX_VIRUS_NUM];
    int num_viruses;

    // Configure file name and virus signature file name
    char file_name[MAX_FILE_NAME];
    char virus_file_name[MAX_FILE_NAME];
    if (argc > 1) {
        strcpy(file_name, argv[1]);
    } else {
        printf("Enter file name to scan: ");
        scanf("%s", file_name);
    }
    if (argc > 2) {
        strcpy(virus_file_name, argv[2]);
    } else {
        printf("Enter virus signature file name: ");
        scanf("%s", virus_file_name);
    }

    // Open virus signature file
    FILE *virus_fp = fopen(virus_file_name, "r");
    if (virus_fp == NULL) {
        printf("ERROR: Virus signature file not found.\n");
        return -1;
    }

    // Read virus signatures from file
    num_viruses = read_virus_file(virus_fp, viruses);

    // Close virus signature file
    fclose(virus_fp);

    // Open file to scan for viruses
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("ERROR: File not found.\n");
        return -1;
    }

    // Scan file for viruses
    scan_file(fp, viruses, num_viruses);

    // Close file
    fclose(fp);

    return 0;
}