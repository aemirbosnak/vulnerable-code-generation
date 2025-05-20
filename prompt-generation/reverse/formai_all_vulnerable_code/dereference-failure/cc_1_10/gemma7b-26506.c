//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_COLS 100

typedef struct CSV_Reader
{
    char **data;
    int num_lines;
    int num_cols;
} CSV_Reader;

CSV_Reader *csv_reader_init(int num_lines, int num_cols)
{
    CSV_Reader *reader = malloc(sizeof(CSV_Reader));
    reader->data = malloc(sizeof(char *) * num_lines);
    for (int i = 0; i < num_lines; i++)
    {
        reader->data[i] = malloc(sizeof(char *) * num_cols);
    }
    reader->num_lines = num_lines;
    reader->num_cols = num_cols;
    return reader;
}

void csv_reader_free(CSV_Reader *reader)
{
    for (int i = 0; i < reader->num_lines; i++)
    {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

void csv_reader_read(CSV_Reader *reader, char **line)
{
    *line = malloc(sizeof(char) * (reader->num_cols + 1));
    for (int i = 0; i < reader->num_cols; i++)
    {
        sprintf((*line) + i * (reader->num_cols + 1), ",%s", reader->data[reader->num_lines - 1][i]);
    }
    (*line)[reader->num_cols] = '\0';
}

int main()
{
    CSV_Reader *reader = csv_reader_init(5, 3);
    reader->data[0][0] = "Alice";
    reader->data[0][1] = "Bob";
    reader->data[0][2] = "Charlie";
    reader->data[1][0] = "Dave";
    reader->data[1][1] = "Eve";
    reader->data[1][2] = "Frank";

    char *line;
    csv_reader_read(reader, &line);
    printf("%s\n", line);

    csv_reader_free(reader);
    return 0;
}