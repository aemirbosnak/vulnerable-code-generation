//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 10

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: csvreader file.csv\n");
        return 1;
    }

    FILE *file;
    char line[MAX_LINE_LENGTH];
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // read the first line to get the headers
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error reading file!\n");
        fclose(file);
        return 1;
    }

    // parse headers
    char *pch;
    char headers[MAX_FIELDS][MAX_FIELD_LENGTH];
    int num_headers = 0;
    pch = strtok(line, ",");
    while (pch != NULL && num_headers < MAX_FIELDS) {
        strcpy(headers[num_headers], pch);
        num_headers++;
        pch = strtok(NULL, ",");
    }

    // read and parse data
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char *data[MAX_FIELDS];
        int num_fields = 0;
        pch = strtok(line, ",");
        while (pch != NULL && num_fields < MAX_FIELDS) {
            data[num_fields] = malloc(MAX_FIELD_LENGTH);
            strcpy(data[num_fields], pch);
            num_fields++;
            pch = strtok(NULL, ",");
        }

        // print data
        printf("\n");
        for (int i = 0; i < num_fields; i++) {
            printf("%s: %s\n", headers[i], data[i]);
            free(data[i]);
        }
    }

    fclose(file);
    return 0;
}