//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_COUNT 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *name;
    char *signature;
} virus_t;

virus_t viruses[MAX_VIRUS_COUNT];
int virus_count;

void load_virus_database() {
    FILE *fp;
    char line[256];
    char *token;
    int i = 0;

    fp = fopen("virus.db", "r");
    if (fp == NULL) {
        printf("Error: Unable to open virus database file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        viruses[i].name = strdup(token);
        token = strtok(NULL, ",");
        viruses[i].signature = strdup(token);
        i++;
    }

    fclose(fp);
    virus_count = i;
}

int scan_file(char *filename) {
    FILE *fp;
    char buffer[MAX_FILE_SIZE];
    int filesize, j;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file '%s'.\n", filename);
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    rewind(fp);

    if (filesize > MAX_FILE_SIZE) {
        printf("Warning: File '%s' is larger than 1MB and will not be scanned.\n", filename);
        fclose(fp);
        return 0;
    }

    while (fread(buffer, 1, filesize, fp) == filesize) {
        for (j = 0; j < virus_count; j++) {
            if (memmem(buffer, filesize, viruses[j].signature, strlen(viruses[j].signature))!= NULL) {
                printf("Virus found: %s\n", viruses[j].name);
                return j;
            }
        }
    }

    fclose(fp);
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    load_virus_database();

    int result = scan_file(argv[1]);

    if (result == -1) {
        printf("No viruses found.\n");
    } else if (result >= 0) {
        printf("Virus found: %s\n", viruses[result].name);
    }

    return 0;
}