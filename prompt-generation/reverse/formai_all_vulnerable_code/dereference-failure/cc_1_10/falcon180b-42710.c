//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int (*function)(char *);
} scanner_t;

int scan_file(char *filename) {
    FILE *file;
    char buffer[1024];
    int size;
    int infected = 0;

    file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    while ((size = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < size; i++) {
            if (isprint(buffer[i])) {
                continue;
            }

            printf("Suspicious character found at offset %d in file %s\n", i, filename);
            infected = 1;
        }
    }

    fclose(file);

    if (infected) {
        printf("File %s is infected with a virus!\n", filename);
    } else {
        printf("File %s is clean.\n", filename);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    scanner_t scanners[] = {
        { ".exe", scan_file },
        { ".dll", scan_file },
        { ".sys", scan_file },
        { NULL, NULL }
    };

    char *extension = strrchr(argv[1], '.');

    if (extension == NULL) {
        printf("Error: Unable to determine file type.\n");
        return 1;
    }

    for (int i = 0; scanners[i].name!= NULL; i++) {
        if (strcmp(scanners[i].name, extension) == 0) {
            int result = scanners[i].function(argv[1]);

            if (result!= 0) {
                return result;
            }

            break;
        }
    }

    printf("File type not supported.\n");
    return 1;
}