//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct _METADATA_RECORD {
    char *tag;
    char *data;
    uint64_t length;
} METADATA_RECORD;

typedef struct _METADATA_HEADER {
    uint64_t version;
    uint64_t num_records;
    METADATA_RECORD *records;
} METADATA_HEADER;

METADATA_HEADER *
extract_metadata(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "error opening file: %s\n", filename);
        return NULL;
    }

    // read the header
    METADATA_HEADER *header = malloc(sizeof(METADATA_HEADER));
    fread(header, sizeof(METADATA_HEADER), 1, fp);

    // read the records
    header->records = malloc(sizeof(METADATA_RECORD) * header->num_records);
    for (uint64_t i = 0; i < header->num_records; i++) {
        METADATA_RECORD *record = &header->records[i];
        fread(record, sizeof(METADATA_RECORD), 1, fp);
        record->tag = malloc(record->length + 1);
        fread(record->tag, record->length, 1, fp);
        record->tag[record->length] = '\0';
        record->data = malloc(record->length + 1);
        fread(record->data, record->length, 1, fp);
        record->data[record->length] = '\0';
    }

    // close the file
    fclose(fp);

    // return the header
    return header;
}

void
print_metadata(METADATA_HEADER *header) {
    printf("metadata version: %llu\n", header->version);
    printf("number of records: %llu\n", header->num_records);
    for (uint64_t i = 0; i < header->num_records; i++) {
        METADATA_RECORD *record = &header->records[i];
        printf("tag: %s\n", record->tag);
        printf("data: %s\n", record->data);
    }
}

void
free_metadata(METADATA_HEADER *header) {
    for (uint64_t i = 0; i < header->num_records; i++) {
        METADATA_RECORD *record = &header->records[i];
        free(record->tag);
        free(record->data);
    }
    free(header->records);
    free(header);
}

int
main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    METADATA_HEADER *header = extract_metadata(argv[1]);
    if (header == NULL) {
        fprintf(stderr, "error extracting metadata from file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    print_metadata(header);

    free_metadata(header);

    return EXIT_SUCCESS;
}