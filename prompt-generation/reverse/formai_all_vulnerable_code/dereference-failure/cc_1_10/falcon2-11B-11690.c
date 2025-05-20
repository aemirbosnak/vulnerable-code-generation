//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_ROW_LENGTH 1000

typedef struct row {
    char *name;
    char *age;
    char *city;
} row;

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int num_rows = 0;

    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    while ((read = getline(&line, &len, fp))!= -1) {
        row *row_data;
        char *name = NULL, *age = NULL, *city = NULL;

        if (read == 0) {
            // end of file
            break;
        }

        row_data = malloc(sizeof(row));
        if (row_data == NULL) {
            fprintf(stderr, "Error allocating memory\n");
            exit(1);
        }

        name = strsep(&line, ",");
        age = strsep(&line, ",");
        city = strsep(&line, ",");

        row_data->name = name;
        row_data->age = age;
        row_data->city = city;

        printf("%s,%s,%s\n", row_data->name, row_data->age, row_data->city);
        num_rows++;

        free(row_data->name);
        free(row_data->age);
        free(row_data->city);
        free(row_data);
    }

    fclose(fp);
    printf("Read %d rows from the CSV file.\n", num_rows);

    return 0;
}