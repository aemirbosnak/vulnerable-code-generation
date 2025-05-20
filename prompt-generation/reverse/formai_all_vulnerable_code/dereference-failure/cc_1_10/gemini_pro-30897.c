//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the file header structure
typedef struct {
    char signature[4];  // Magic number to identify the file
    int version;        // Version of the file format
    int num_records;    // Number of records in the file
} FileHeader;

// Define the record structure
typedef struct {
    int id;             // Unique ID of the record
    char data[100];     // Data associated with the record
} Record;

// Function to read the file header from a file
FileHeader *read_file_header(FILE *fp) {
    FileHeader *header = malloc(sizeof(FileHeader));
    fread(header, sizeof(FileHeader), 1, fp);
    return header;
}

// Function to read a record from a file
Record *read_record(FILE *fp) {
    Record *record = malloc(sizeof(Record));
    fread(record, sizeof(Record), 1, fp);
    return record;
}

// Function to write a record to a file
void write_record(FILE *fp, Record *record) {
    fwrite(record, sizeof(Record), 1, fp);
}

// Function to recover data from a corrupted file
void recover_data(FILE *fp) {
    // Read the file header
    FileHeader *header = read_file_header(fp);

    // Iterate over the records in the file
    for (int i = 0; i < header->num_records; i++) {
        // Read the record
        Record *record = read_record(fp);

        // Check if the record is corrupt
        if (record->id == -1) {
            // The record is corrupt, so skip it
            continue;
        }

        // The record is not corrupt, so write it to the output file
        write_record(stdout, record);

        // Free the memory allocated for the record
        free(record);
    }

    // Free the memory allocated for the file header
    free(header);
}

int main() {
    // Open the corrupted file
    FILE *fp = fopen("corrupted.dat", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Recover the data from the file
    recover_data(fp);

    // Close the file
    fclose(fp);

    return EXIT_SUCCESS;
}