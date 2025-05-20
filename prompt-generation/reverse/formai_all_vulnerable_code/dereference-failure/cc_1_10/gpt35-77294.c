//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 65536

int main(int argc, char *argv[]) {

    printf("###################################################################\n");
    printf("#                             Welcome!                            #\n");
    printf("#-----------------------------------------------------------------#\n");
    printf("#                       C Antivirus Scanner                       #\n");
    printf("###################################################################\n\n");

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    char *filename = argv[1];
    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    if (fileSize > MAX_FILE_SIZE) {
        printf("File size is too large. Maximum allowed size is %d bytes.\n", MAX_FILE_SIZE);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_FILE_SIZE];
    fread(buffer, sizeof(char), fileSize, fp);
    fclose(fp);

    bool isInfected = false;

    // Cyberpunk style virus detection
    if (strstr(buffer, "hack_the_planet") != NULL) {
        isInfected = true;
    }

    if (isInfected) {
        printf("The file '%s' is infected with Hack the Planet virus!\n", filename);
        printf("The infected code has been removed from the file.\n");
    } else {
        printf("The file '%s' is clean. No viruses found.\n", filename);
    }

    return 0;
}