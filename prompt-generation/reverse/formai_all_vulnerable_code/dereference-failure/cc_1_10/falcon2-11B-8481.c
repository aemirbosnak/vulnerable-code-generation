//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <string.h>

char* extractMetadata(const char* fileName) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", fileName);
        return NULL;
    }

    char* metadata = NULL;
    char* line = NULL;
    char* token = NULL;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strlen(line) == 0)
            break;

        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '\n' || line[i] == '\0') {
                token = strtok(NULL, " \t\n");
                if (strcmp(token, "#") == 0)
                    continue;
                if (strcmp(token, "/*") == 0)
                    continue;
                if (strcmp(token, "*/") == 0)
                    continue;
                if (isdigit(token[0]))
                    continue;

                if (metadata == NULL)
                    metadata = strdup(token);
                else
                    strcat(metadata, " ");
                strcat(metadata, token);
            }
        }
    }

    fclose(fp);
    return metadata;
}

int main() {
    char* metadata = extractMetadata("input.c");
    if (metadata!= NULL)
        printf("%s\n", metadata);
    free(metadata);
    return 0;
}