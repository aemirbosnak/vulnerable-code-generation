//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LEN 50
#define MAX_LINE_LEN 1024

typedef struct {
    char fields[MAX_FIELDS][MAX_FIELD_LEN];
} Record;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("ERROR: Must specify input file name.\n");
        return -1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("ERROR: Could not open file %s.\n", filename);
        return -1;
    }

    char line[MAX_LINE_LEN];
    Record *recs = malloc(sizeof(Record) * MAX_LINE_LEN);

    int rec_count = 0;
    int field_count = 0;

    while (fgets(line, MAX_LINE_LEN, fp)) {

        field_count = 0;

        char *p = strtok(line, ",");

        while (p && field_count < MAX_FIELDS) {

            strcpy(recs[rec_count].fields[field_count], p);
            field_count++;

            p = strtok(NULL, ",");
        }

        rec_count++;

        if (rec_count == MAX_LINE_LEN) {
            printf("WARNING: Hit maximum record count %d.\n", MAX_LINE_LEN);
            break;
        }
    }

    fclose(fp);

    printf("Successfully read %d records from %s\n", rec_count, filename);

    // Print results
    for (int i = 0; i < rec_count; i++) {
        printf("Record %d: ", i);

        for (int j = 0; j < field_count; j++) {
            printf("%s, ", recs[i].fields[j]);
        }

        printf("\n");
    }

    free(recs);

    return 0;
}