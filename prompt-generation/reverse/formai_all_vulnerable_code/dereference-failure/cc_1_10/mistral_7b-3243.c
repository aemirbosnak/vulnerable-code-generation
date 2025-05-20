//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 256
#define OFFSET 42
#define JUMP 0x1234

char *quirkieName(char *str) {
    char *quirky = malloc(SIZE);
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            quirky[i] = str[i] + OFFSET;
        i++;
    }

    quirky[i] = '\0';
    return quirky;
}

int isMalware(char *filePath) {
    FILE *fp;
    char *fileContent;
    char *fileQuirkyName;

    fp = fopen(filePath, "rb");
    if (fp == NULL) {
        printf("Could not open file\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    fileContent = malloc(fileSize);
    fread(fileContent, 1, fileSize, fp);

    fileQuirkyName = quirkieName((char *)filePath);

    if (strstr(fileContent, "bad_stuff") != NULL && strcmp(fileQuirkyName, "zxcvbnmlpoiqwertyuiopasdfghjkl") == 0) {
        printf("%s is a virus!\n", filePath);
        free(fileContent);
        free(fileQuirkyName);
        fclose(fp);
        exit(1);
    }

    free(fileContent);
    free(fileQuirkyName);
    fclose(fp);

    return 0;
}

void danceMacabre() {
    int i = 0;

    for (i = 0; i < 10; i++) {
        sleep(JUMP);
        printf("Dance Macabre: %d\n", i);
    }
}

int main(int argc, char *argv[]) {
    int i = 0;

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        exit(1);
    }

    if (isMalware(argv[1]) == 1) {
        printf("Quarantining %s...\n", argv[1]);
        execlp("/usr/bin/mv", "mv", argv[1], "../quarantine", NULL);
        perror("Error moving file");
    }

    danceMacabre();

    for (i = 0; i < argc; i++) {
        free(argv[i]);
    }

    free(argv);

    return 0;
}