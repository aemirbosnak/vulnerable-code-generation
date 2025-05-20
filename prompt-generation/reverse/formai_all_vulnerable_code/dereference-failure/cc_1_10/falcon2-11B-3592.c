//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *fileName = NULL;
    char *line = NULL;
    size_t len = 0;
    size_t pos = 0;
    size_t start = 0;
    size_t end = 0;
    char *metadata = NULL;

    printf("Enter the file name: ");
    fgets(fileName, sizeof(fileName), stdin);

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((line = fgets(line, sizeof(line), fp))!= NULL) {
        len = strlen(line);
        pos = 0;
        start = 0;
        end = 0;
        metadata = (char *)malloc(len + 1);
        if (metadata == NULL) {
            printf("Error allocating memory.\n");
            return 1;
        }
        while (pos < len) {
            if (isspace(line[pos])) {
                if (start == 0) {
                    start = pos;
                }
                end = pos;
            } else {
                if (start == 0) {
                    continue;
                } else {
                    metadata[end] = line[pos];
                    end++;
                }
                if (end >= len) {
                    break;
                }
                start = end;
            }
            pos++;
        }
        metadata[end] = '\0';
        printf("Metadata: %s\n", metadata);
        free(metadata);
    }

    fclose(fp);

    return 0;
}