//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct record {
    char *col1;
    char *col2;
    char *col3;
};

void csv_reader(const char *filename, struct record **records, int *num_records) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        *records = NULL;
        *num_records = 0;
        return;
    }

    char line[1024];
    int count = 0;

    while (fgets(line, 1024, fp)) {
        char *token;
        struct record rec;

        token = strtok(line, ",");
        rec.col1 = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(rec.col1, token);

        token = strtok(NULL, ",");
        rec.col2 = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(rec.col2, token);

        token = strtok(NULL, ",");
        rec.col3 = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(rec.col3, token);

        (*records)[count++] = rec;
    }

    *num_records = count;

    fclose(fp);
}

int main() {
    struct record *records;
    int num_records;

    csv_reader("data.csv", &records, &num_records);

    for (int i = 0; i < num_records; i++) {
        printf("%s, %s, %s\n", records[i].col1, records[i].col2, records[i].col3);
    }

    return 0;
}