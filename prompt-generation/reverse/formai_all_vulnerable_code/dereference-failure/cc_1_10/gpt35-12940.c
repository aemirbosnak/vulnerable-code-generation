//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 256
#define MAX_FIELDS_PER_LINE 10

typedef struct
{
    char **fields;
    int num_fields;
} csv_line;

void free_csv_line(csv_line *line)
{
    int i;

    for (i = 0; i < line->num_fields; i++)
    {
        free(line->fields[i]);
    }

    free(line->fields);
}

csv_line *read_csv_line(char *line_str)
{
    csv_line *line;
    char *field_str;
    char *saveptr = NULL;
    int i;

    line = (csv_line *)malloc(sizeof(csv_line));
    line->fields = (char **)malloc(MAX_FIELDS_PER_LINE * sizeof(char *));
    line->num_fields = 0;

    field_str = strtok_r(line_str, ",", &saveptr);

    while (field_str != NULL && line->num_fields < MAX_FIELDS_PER_LINE)
    {
        line->fields[line->num_fields] = (char *)malloc(MAX_FIELD_SIZE * sizeof(char));
        strncpy(line->fields[line->num_fields], field_str, MAX_FIELD_SIZE);
        line->num_fields++;

        field_str = strtok_r(NULL, ",", &saveptr);
    }

    if (field_str != NULL)
    {
        fprintf(stderr, "Too many fields in line\n");
        free_csv_line(line);
        free(line);
        return NULL;
    }

    return line;
}

int main(int argc, char **argv)
{
    FILE *fp;
    char line[MAX_LINE_SIZE];
    csv_line *line_struct;
    int line_num = 1;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, fp) != NULL)
    {
        line_struct = read_csv_line(line);

        if (line_struct == NULL)
        {
            fprintf(stderr, "Error on line %d\n", line_num);
            return 1;
        }

        // Do something with the line struct here

        free_csv_line(line_struct);

        line_num++;
    }

    fclose(fp);
    return 0;
}