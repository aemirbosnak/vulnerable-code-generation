//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000

void scanFile(char filePath[]);
int checkVirus(char content[]);
void quarantineFile(char filePath[]);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: antivirus <file_path>\n");
        return -1;
    }
    scanFile(argv[1]);
    return 0;
}

void scanFile(char filePath[]) {
    FILE *file;
    char content[MAX_FILE_SIZE];

    file = fopen(filePath, "r");

    if(file == NULL) {
        printf("Could not open file %s\n", filePath);
        exit(-1);
    }

    if(fgets(content, MAX_FILE_SIZE, file) != NULL) {
        if(checkVirus(content)) {
            printf("%s is infected with a virus!\n", filePath);
            quarantineFile(filePath);
        } else {
            printf("%s is clean\n", filePath);
        }
    }

    fclose(file);
}

int checkVirus(char content[]) {
    const char *virusPatterns[] = {"malware", "trojan", "virus", "worm"};
    int i;
    for(i = 0; i < sizeof(virusPatterns)/sizeof(virusPatterns[0]); i++) {
        if(strstr(content, virusPatterns[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

void quarantineFile(char filePath[]) {
    char quarantinePath[100];
    strcpy(quarantinePath, "quarantine/");
    strcat(quarantinePath, filePath);

    if(rename(filePath, quarantinePath) != 0) {
        printf("Could not quarantine file %s\n", filePath);
        exit(-1);
    }

    printf("%s was quarantined successfully\n", filePath);
}