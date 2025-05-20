//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[1000];
    char *token;
    int i, j;
    int fieldCount = 0;
    char *fields[100];
    int fieldLength[100];

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    // Read the first line to get the field count
    fgets(line, sizeof(line), fp);
    token = strtok(line, ",");
    fieldCount = 0;
    while (token!= NULL) {
        fields[fieldCount] = strdup(token);
        fieldLength[fieldCount] = strlen(token);
        fieldCount++;
        token = strtok(NULL, ",");
    }
    if (fieldCount == 0) {
        printf("No fields found in the first line\n");
        fclose(fp);
        return 1;
    }

    // Read the rest of the lines
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        for (i = 0; i < fieldCount; i++) {
            fields[i] = strdup(token);
            token = strtok(NULL, ",");
        }
        for (i = 0; i < fieldCount; i++) {
            printf("%s", fields[i]);
            free(fields[i]);
        }
        printf("\n");
    }
    fclose(fp);

    return 0;
}