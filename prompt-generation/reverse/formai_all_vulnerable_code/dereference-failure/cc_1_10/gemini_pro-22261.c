//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in a CSV row
#define MAX_COLUMNS 10

// Define the maximum length of a CSV field
#define MAX_FIELD_LENGTH 100

// Define the character used to separate fields in a CSV row
#define FIELD_SEPARATOR ','

// Define the character used to enclose fields in a CSV row
#define FIELD_ENCLOSURE '"'

// Define the character used to denote the end of a line in a CSV file
#define LINE_ENDING '\n'

// Define the structure of a CSV reader
typedef struct csv_reader {
    // The file pointer for the CSV file
    FILE *file;

    // The current line number in the CSV file
    int line_number;

    // The current column number in the CSV file
    int column_number;

    // The current field value in the CSV file
    char *field_value;

    // The length of the current field value in the CSV file
    int field_value_length;

    // The maximum length of the current field value in the CSV file
    int field_value_max_length;
} csv_reader;

// Create a new CSV reader
csv_reader *csv_reader_new(FILE *file) {
    // Allocate memory for the CSV reader
    csv_reader *reader = malloc(sizeof(csv_reader));

    // Initialize the CSV reader
    reader->file = file;
    reader->line_number = 1;
    reader->column_number = 0;
    reader->field_value = NULL;
    reader->field_value_length = 0;
    reader->field_value_max_length = 0;

    // Return the CSV reader
    return reader;
}

// Free the memory used by a CSV reader
void csv_reader_free(csv_reader *reader) {
    // Free the memory used by the CSV reader's field value
    free(reader->field_value);

    // Free the memory used by the CSV reader
    free(reader);
}

// Read the next field from a CSV row
int csv_reader_next_field(csv_reader *reader) {
    // Increment the column number
    reader->column_number++;

    // Reset the field value
    reader->field_value = NULL;
    reader->field_value_length = 0;
    reader->field_value_max_length = 0;

    // Read the next character from the CSV file
    int c = fgetc(reader->file);

    // If the end of the line has been reached, return 0
    if (c == LINE_ENDING) {
        return 0;
    }

    // If the field is enclosed in quotes, read the field value until the closing quote is reached
    if (c == FIELD_ENCLOSURE) {
        while ((c = fgetc(reader->file)) != FIELD_ENCLOSURE) {
            // If the end of the line has been reached, return 0
            if (c == LINE_ENDING) {
                return 0;
            }

            // If the maximum field value length has been reached, reallocate the memory used by the field value
            if (reader->field_value_length == reader->field_value_max_length) {
                reader->field_value_max_length *= 2;
                reader->field_value = realloc(reader->field_value, reader->field_value_max_length);
            }

            // Append the character to the field value
            reader->field_value[reader->field_value_length++] = c;
        }
    } else {
        // Read the field value until the field separator is reached
        while (c != FIELD_SEPARATOR && c != LINE_ENDING) {
            // If the maximum field value length has been reached, reallocate the memory used by the field value
            if (reader->field_value_length == reader->field_value_max_length) {
                reader->field_value_max_length *= 2;
                reader->field_value = realloc(reader->field_value, reader->field_value_max_length);
            }

            // Append the character to the field value
            reader->field_value[reader->field_value_length++] = c;

            // Read the next character from the CSV file
            c = fgetc(reader->file);
        }
    }

    // If the end of the line has been reached, return 0
    if (c == LINE_ENDING) {
        return 0;
    }

    // Terminate the field value with a null character
    reader->field_value[reader->field_value_length] = '\0';

    // Return 1 to indicate that a field has been read
    return 1;
}

// Read the next row from a CSV file
int csv_reader_next_row(csv_reader *reader) {
    // Increment the line number
    reader->line_number++;

    // Reset the column number
    reader->column_number = 0;

    // Read the next field from the CSV row
    int field_count = 0;
    while (csv_reader_next_field(reader)) {
        field_count++;
    }

    // If no fields were read, return 0
    if (field_count == 0) {
        return 0;
    }

    // Return 1 to indicate that a row has been read
    return 1;
}

// Get the field value from the current row and column
char *csv_reader_get_field_value(csv_reader *reader) {
    return reader->field_value;
}

// Get the length of the field value from the current row and column
int csv_reader_get_field_value_length(csv_reader *reader) {
    return reader->field_value_length;
}

// Get the line number of the current row
int csv_reader_get_line_number(csv_reader *reader) {
    return reader->line_number;
}

// Get the column number of the current column
int csv_reader_get_column_number(csv_reader *reader) {
    return reader->column_number;
}

// Print the contents of a CSV file
void csv_reader_print(csv_reader *reader) {
    // Read the next row from the CSV file
    while (csv_reader_next_row(reader)) {
        // Print the field values from the current row
        for (int i = 0; i < reader->column_number; i++) {
            printf("%s", csv_reader_get_field_value(reader));

            if (i < reader->column_number - 1) {
                printf(", ");
            }
        }

        printf("\n");
    }
}

// The main function
int main() {
    // Open the CSV file
    FILE *file = fopen("data.csv", "r");

    // If the CSV file could not be opened, print an error message and exit
    if (file == NULL) {
        printf("Error: could not open CSV file\n");
        return 1;
    }

    // Create a CSV reader
    csv_reader *reader = csv_reader_new(file);

    // Read the contents of the CSV file
    csv_reader_print(reader);

    // Free the memory used by the CSV reader
    csv_reader_free(reader);

    // Close the CSV file
    fclose(file);

    return 0;
}