//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char virus_signature[] = "0x39A4D8F6";
// Example virus signature for testing purposes

int detect_virus(char *file_contents) {
    if (strstr(file_contents, virus_signature) != NULL)
        return 1; // Virus detected
    else 
        return 0; // Virus not detected
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file to scan>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char *file_contents;
    long file_size;

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    file_contents = (char*)malloc((file_size + 1) * sizeof(char));
    if (file_contents == NULL) {
        printf("Error allocating memory for file contents!\n");
        fclose(file);
        exit(1);
    }

    fread(file_contents, sizeof(char), file_size, file);
    fclose(file);

    int virus_detected = detect_virus(file_contents);
    if (virus_detected) {
        printf("Virus detected in file %s!\n", argv[1]);
    } else {
        printf("No virus found in file %s.\n", argv[1]);
    }

    free(file_contents);
    return 0;
}