//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkFile(FILE *fp) {
    char c = 0;
    while (fread(&c, 1, 1, fp) > 0) {
        if (c == 'C') {
            printf("Warning: Possible virus detected!\n");
            break;
        }
    }
}

void checkDir(char *dir) {
    char buffer[256];
    sprintf(buffer, "ls %s", dir);
    FILE *fp = popen(buffer, "r");
    char filename[256];
    while (fgets(filename, 256, fp) != NULL) {
        if (filename[0] == '.') {
            continue;
        }
        filename[strlen(filename) - 1] = '\0';
        sprintf(buffer, "%s/%s", dir, filename);
        FILE *file = fopen(buffer, "rb");
        if (file == NULL) {
            printf("Error: Could not open file %s\n", buffer);
            continue;
        }
        checkFile(file);
        fclose(file);
    }
    pclose(fp);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file or directory>\n", argv[0]);
        return 1;
    }
    if (argc == 2) {
        FILE *file = fopen(argv[1], "rb");
        if (file == NULL) {
            printf("Error: Could not open file %s\n", argv[1]);
            return 1;
        }
        checkFile(file);
        fclose(file);
    } else {
        checkDir(argv[1]);
    }
    return 0;
}