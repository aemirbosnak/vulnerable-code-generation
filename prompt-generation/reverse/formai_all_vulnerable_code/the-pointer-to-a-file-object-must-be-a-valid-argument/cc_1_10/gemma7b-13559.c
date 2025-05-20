//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader
{
    char **buffer;
    int size;
    int capacity;
    FILE *fp;
} CSVReader;

CSVReader *csv_reader_init(FILE *fp)
{
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->buffer = NULL;
    reader->size = 0;
    reader->capacity = MAX_BUFFER_SIZE;
    reader->fp = fp;

    return reader;
}

void csv_reader_read(CSVReader *reader)
{
    char line[MAX_BUFFER_SIZE];
    int i = 0;

    // Read a line from the file
    fgets(line, MAX_BUFFER_SIZE, reader->fp);

    // Split the line into tokens
    char *token = strtok(line, ",");

    // Add the tokens to the reader's buffer
    while (token)
    {
        reader->buffer = realloc(reader->buffer, (reader->size + 1) * sizeof(char *));
        reader->buffer[reader->size++] = strdup(token);
        token = strtok(NULL, ",");
    }
}

void csv_reader_free(CSVReader *reader)
{
    free(reader->buffer);
    fclose(reader->fp);
    free(reader);
}

int main()
{
    FILE *fp = fopen("data.csv", "r");
    CSVReader *reader = csv_reader_init(fp);

    // Read the CSV file
    csv_reader_read(reader);

    // Print the tokens
    for (int i = 0; i < reader->size; i++)
    {
        printf("%s ", reader->buffer[i]);
    }

    // Free the reader
    csv_reader_free(reader);

    return 0;
}