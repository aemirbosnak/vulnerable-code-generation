//Gemma-7B DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAL_SIZE 1024

typedef struct MAL_RECORD {
    char *name;
    struct MAL_RECORD *next;
} MAL_RECORD;

MAL_RECORD *mal_head = NULL;

void scan_malware() {
    char buffer[MAL_SIZE];
    FILE *fp;
    MAL_RECORD *new_record;

    fp = fopen("/home/user/Documents/malware.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(buffer, MAL_SIZE, fp) != NULL) {
        new_record = malloc(sizeof(MAL_RECORD));
        new_record->name = strdup(buffer);
        new_record->next = mal_head;
        mal_head = new_record;
    }

    fclose(fp);
}

void check_malware() {
    char file_name[256];

    printf("Enter file name: ");
    scanf("%s", file_name);

    MAL_RECORD *current_record = mal_head;
    while (current_record) {
        if (strcmp(file_name, current_record->name) == 0) {
            printf("File %s is infected with malware!\n", file_name);
            break;
        }
        current_record = current_record->next;
    }

    if (current_record == NULL) {
        printf("File %s is clean.\n", file_name);
    }
}

int main() {
    scan_malware();
    check_malware();

    return 0;
}