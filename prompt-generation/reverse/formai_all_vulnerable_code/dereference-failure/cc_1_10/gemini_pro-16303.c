//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
    size_t capacity;
} Buffer;

void buffer_init(Buffer *buffer) {
    buffer->data = NULL;
    buffer->size = 0;
    buffer->capacity = 0;
}

void buffer_free(Buffer *buffer) {
    free(buffer->data);
    buffer_init(buffer);
}

int buffer_append(Buffer *buffer, const char *data, size_t size) {
    if (size > buffer->capacity - buffer->size) {
        size_t new_capacity = buffer->capacity ? buffer->capacity * 2 : 1024;
        while (new_capacity < buffer->size + size) {
            new_capacity *= 2;
        }
        char *new_data = realloc(buffer->data, new_capacity);
        if (!new_data) {
            return -1;
        }
        buffer->data = new_data;
        buffer->capacity = new_capacity;
    }
    memcpy(buffer->data + buffer->size, data, size);
    buffer->size += size;
    return 0;
}

int buffer_append_char(Buffer *buffer, char c) {
    return buffer_append(buffer, &c, 1);
}

typedef struct {
    Buffer *fields;
    size_t num_fields;
    size_t capacity;
} CSVRecord;

void csv_record_init(CSVRecord *record) {
    record->fields = NULL;
    record->num_fields = 0;
    record->capacity = 0;
}

void csv_record_free(CSVRecord *record) {
    for (size_t i = 0; i < record->num_fields; i++) {
        buffer_free(&record->fields[i]);
    }
    free(record->fields);
    csv_record_init(record);
}

int csv_record_append(CSVRecord *record, const char *data, size_t size) {
    if (record->num_fields == record->capacity) {
        size_t new_capacity = record->capacity ? record->capacity * 2 : 16;
        Buffer *new_fields = realloc(record->fields, new_capacity * sizeof(Buffer));
        if (!new_fields) {
            return -1;
        }
        record->fields = new_fields;
        record->capacity = new_capacity;
    }
    buffer_init(&record->fields[record->num_fields]);
    int err = buffer_append(&record->fields[record->num_fields], data, size);
    if (err) {
        csv_record_free(record);
        return err;
    }
    record->num_fields++;
    return 0;
}

typedef struct {
    Buffer data;
    size_t line_number;
} CSVParserState;

void csv_parser_init(CSVParserState *state) {
    buffer_init(&state->data);
    state->line_number = 1;
}

void csv_parser_free(CSVParserState *state) {
    buffer_free(&state->data);
    csv_parser_init(state);
}

int csv_parser_parse_line(CSVParserState *state, CSVRecord *record) {
    csv_record_init(record);

    char *data = state->data.data;
    size_t size = state->data.size;
    size_t start = 0;

    for (size_t i = 0; i < size; i++) {
        if (data[i] == '\n') {
            if (i > 0 && data[i - 1] == '\r') {
                i--;
            }

            int err = csv_record_append(record, data + start, i - start);
            if (err) {
                csv_record_free(record);
                return err;
            }

            start = i + 1;
            state->line_number++;
        } else if (data[i] == ',') {
            int err = csv_record_append(record, data + start, i - start);
            if (err) {
                csv_record_free(record);
                return err;
            }

            start = i + 1;
        }
    }

    if (start < size) {
        int err = csv_record_append(record, data + start, size - start);
        if (err) {
            csv_record_free(record);
            return err;
        }
    }

    buffer_init(&state->data);

    return 0;
}

int main() {
    FILE *fp = fopen("input.csv", "r");
    if (!fp) {
        return -1;
    }

    CSVParserState state;
    csv_parser_init(&state);

    CSVRecord record;
    csv_record_init(&record);

    while (!feof(fp)) {
        char buffer[1024];
        size_t size = fread(buffer, 1, sizeof(buffer), fp);

        int err = buffer_append(&state.data, buffer, size);
        if (err) {
            csv_record_free(&record);
            csv_parser_free(&state);
            fclose(fp);
            return err;
        }

        while (csv_parser_parse_line(&state, &record) == 0) {
            for (size_t i = 0; i < record.num_fields; i++) {
                printf("%s", record.fields[i].data);
                if (i < record.num_fields - 1) {
                    printf(",");
                }
            }
            printf("\n");
        }
    }

    csv_record_free(&record);
    csv_parser_free(&state);
    fclose(fp);

    return 0;
}