//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char *filename;
    char *virus_name;
} virus_t;

virus_t viruses[] = {
    {"eicar.com", "EICAR test file"},
    {"test.exe", "W32.Stration"},
    {"test.doc", "Macro virus"},
    {NULL, NULL}
};

int scan_file(const char *filename) {
    FILE *fp;
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;
    int i;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, fp)) > 0) {
        for (i = 0; viruses[i].filename!= NULL; i++) {
            if (memcmp(buffer, viruses[i].filename, strlen(viruses[i].filename)) == 0) {
                printf("Virus found in file: %s\n", filename);
                printf("Virus name: %s\n", viruses[i].virus_name);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);

    return 0;
}