//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 256
#define MAX_NUM_FIELDS 20

typedef struct {
    char data[MAX_FIELD_SIZE];
    int length;
} field_t;

typedef struct {
    field_t fields[MAX_NUM_FIELDS];
    int num_fields;
} record_t;

typedef struct {
    FILE* fp;
    char* buffer;
    int buffer_size;
} csv_reader_t;

void init_csv_reader(csv_reader_t* reader, char* filename, int buffer_size) {
    reader->fp = fopen(filename, "r");
    reader->buffer_size = buffer_size;
    reader->buffer = (char*)malloc(sizeof(char) * buffer_size);
}

void close_csv_reader(csv_reader_t* reader) {
    fclose(reader->fp);
    free(reader->buffer);
}

int next_record(csv_reader_t* reader, record_t* record) {
    char* line = fgets(reader->buffer, reader->buffer_size, reader->fp);
    if (line == NULL) {
        return -1;
    }

    int i = 0;
    char* start = line;
    char* end = NULL;
    while (start != NULL && *start != '\0' && i < MAX_NUM_FIELDS) {
        end = strchr(start, ',');
        if (end == NULL) {
            end = start + strlen(start) - 1;
        }
        int length = (int)(end - start);
        strncpy(record->fields[i].data, start, length);
        record->fields[i].data[length] = '\0';
        record->fields[i].length = length;
        start = end + 1;
        i++;
    }
    record->num_fields = i;

    return i;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s file_name\n", argv[0]);
        exit(1);
    }

    csv_reader_t reader;
    init_csv_reader(&reader, argv[1], MAX_LINE_SIZE);

    record_t record;
    int num_records = 0;

    while (next_record(&reader, &record) != -1) {
        num_records++;
        printf("Record %d:\n", num_records);
        for (int i = 0; i < record.num_fields; i++) {
            printf("Field %d: %s\n", i+1, record.fields[i].data);
        }
    }

    close_csv_reader(&reader);

    return 0;
}