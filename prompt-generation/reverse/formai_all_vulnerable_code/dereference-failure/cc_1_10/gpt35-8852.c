//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scanFile(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("[%s] not found!\n", filename);
        return;
    }

    unsigned long imageSize;
    fseek(file, 0L, SEEK_END);
    imageSize = ftell(file);
    rewind(file);
    printf("[%s] size: %lu bytes\n", filename, imageSize);

    unsigned char* buffer = (unsigned char*)malloc(sizeof(unsigned char) * imageSize);
    if (buffer == NULL) {
        fclose(file);
        printf("Memory allocation error!\n");
        return;
    }

    fread(buffer, sizeof(unsigned char), imageSize, file);
    fclose(file);

    int numOfViruses = 0;
    const char* viruses[] = {"Trojan", "Worm", "Keylogger", "Spyware", "Adware"};
    const char* foundVirus = NULL;

    for (int i = 0; i < sizeof(viruses) / sizeof(viruses[0]); i++) {
        size_t virusSize = strlen(viruses[i]);

        for (int j = 0; j < imageSize; j++) {
            if (memcmp(&buffer[j], viruses[i], virusSize) == 0) {
                numOfViruses++;
                foundVirus = viruses[i];
                break;
            }
        }

        if (foundVirus != NULL) {
            printf("[%s] contains %s\n", filename, foundVirus);
            foundVirus = NULL;
        }
    }

    if (numOfViruses == 0) {
        printf("[%s] is clean!\n", filename);
    }

    free(buffer);
}

int main() {
    printf("Welcome to C Antivirus scanner!\n");

    scanFile("file1.exe");
    scanFile("file2.dll");
    scanFile("file3.txt");

    return 0;
}