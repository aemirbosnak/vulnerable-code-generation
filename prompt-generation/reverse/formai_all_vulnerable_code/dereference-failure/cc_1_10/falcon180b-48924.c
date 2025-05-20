//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1 MB
#define MAX_VIRUS_SIZE 10000 // 10 KB

typedef struct {
    char name[100];
    int size;
    char *data;
} File;

typedef struct {
    char *name;
    int size;
} Virus;

int main() {
    FILE *fp;
    char ch;
    int i = 0, j = 0;
    char filename[100];

    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    File file;
    file.name[0] = '\0';
    strcat(file.name, filename);

    fseek(fp, 0, SEEK_END);
    file.size = ftell(fp);
    rewind(fp);

    if (file.size > MAX_FILE_SIZE) {
        printf("Error: File too large!\n");
        exit(1);
    }

    file.data = malloc(file.size);
    if (file.data == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        file.data[i++] = ch;
    }

    fclose(fp);

    Virus virus;
    virus.name[0] = '\0';
    strcat(virus.name, "EICAR.COM"); // example virus name
    virus.size = strlen(virus.name);

    int found = 0;
    for (i = 0; i < file.size - virus.size + 1; i++) {
        for (j = 0; j < virus.size; j++) {
            if (file.data[i + j]!= virus.name[j]) {
                break;
            }
        }
        if (j == virus.size) {
            printf("Virus found: %s\n", virus.name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No virus found.\n");
    }

    free(file.data);
    return 0;
}