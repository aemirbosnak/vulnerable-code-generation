//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char **fields;
    int num_fields;
} CSV_row;

typedef struct {
    CSV_row *rows;
    int num_rows;
} CSV_data;

CSV_data* read_csv(const char *filename)
{
    CSV_data *data = (CSV_data*)malloc(sizeof(CSV_data));
    data->num_rows = 0;
    data->rows = NULL;

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return NULL;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)) {
        char *pos = line;
        CSV_row row;
        row.num_fields = 0;
        while (*pos) {
            row.fields = (char**)realloc(row.fields, sizeof(char*) * (row.num_fields + 1));
            if (*pos == '\"') {
                // field is quoted
                char *end_quote = strchr(pos + 1, '\"');

                if (end_quote) {
                    *(end_quote++) = '\0';
                    row.fields[row.num_fields] = pos + 1;
                    row.num_fields++;
                    pos = end_quote;
                } else {
                    fprintf(stderr, "Error parsing CSV - unmatched quote\n");
                    free(row.fields);
                    return NULL;
                }
            } else {
                // field is not quoted
                char *end_field = strchr(pos, ',');
                if (end_field) {
                    *(end_field++) = '\0';
                    row.fields[row.num_fields] = pos;
                    row.num_fields++;
                    pos = end_field;
                } else {
                    // last field
                    row.fields = (char**)realloc(row.fields, sizeof(char*) * (row.num_fields + 1));
                    row.fields[row.num_fields] = pos;
                    row.num_fields++;
                    break;
                }
            }
        }
        data->rows = (CSV_row*)realloc(data->rows, sizeof(CSV_row) * (data->num_rows + 1));
        data->rows[data->num_rows] = row;
        data->num_rows++;
    }

    fclose(fp);
    return data;
}

void free_csv(CSV_data *data)
{
    if (!data) {
        return;
    }

    for (int i = 0; i < data->num_rows; i++) {
        free(data->rows[i].fields);
    }

    free(data->rows);
    free(data);
}

int main()
{
    CSV_data *data = read_csv("example.csv");

    if (!data) {
        return 1;
    }

    printf("Read %d rows from CSV file\n", data->num_rows);

    for (int i = 0; i < data->num_rows; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < data->rows[i].num_fields; j++) {
            printf("%s, ", data->rows[i].fields[j]);
        }
        printf("\n");
    }

    free_csv(data);
    return 0;
}