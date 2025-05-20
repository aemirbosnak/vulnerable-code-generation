//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: excited
// Brace yourselves, for the CSV Reading Extravaganza is about to commence!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Step 1: Let's define the glorious CSV reader!
typedef struct CSVReader {
    FILE* file;  // The portal to the CSV realm
    char* line;  // The ever-so-important line buffer
    size_t line_size;  // The size of our buffer (dynamically adjust it, it's 2023!)
} CSVReader;

// Step 2: Bam! Our CSV reader is ready to be summoned!
CSVReader* create_csv_reader(const char* filename) {
    // Memory magic! Allocate space for our reader.
    CSVReader* reader = malloc(sizeof(CSVReader));
    if (!reader) {
        fprintf(stderr, "Oops, we ran out of memory! Aborting mission.");
        return NULL;
    }

    // Time to open the gates to the CSV world!
    reader->file = fopen(filename, "r");
    if (!reader->file) {
        perror("Couldn't open the CSV file.");
        free(reader);
        return NULL;
    }

    // Initialize our line buffer.
    reader->line = NULL;
    reader->line_size = 0;

    // Reader successfully born!
    return reader;
}

// Step 3: Unleash the line grappler!
char* read_csv_line(CSVReader* reader) {
    // Get the next line of CSV goodness.
    ssize_t line_length = getline(&reader->line, &reader->line_size, reader->file);

    // If we're at the end of the file, bid farewell.
    if (line_length <= 0) {
        return NULL;
    }

    // Strip that pesky newline.
    reader->line[line_length - 1] = '\0';

    // Send back our precious line of data!
    return reader->line;
}

// Step 4: Prepare for the grand finale!
void close_csv_reader(CSVReader* reader) {
    // Free the line buffer.
    free(reader->line);

    // Close the CSV file.
    fclose(reader->file);

    // Release the CSV reader.
    free(reader);
}

// Now for the grand performance!
int main(int argc, char** argv) {
    // Check if we have a file to work with.
    if (argc < 2) {
        fprintf(stderr, "Hey there, you need to provide the CSV file name as an argument.");
        return 1;
    }

    // Summon our trusted CSV reader!
    CSVReader* reader = create_csv_reader(argv[1]);
    if (!reader) {
        return 2;
    }

    // Let's iterate through the CSV lines like a boss!
    char* line = read_csv_line(reader);
    while (line) {
        printf("%s\n", line);
        line = read_csv_line(reader);
    }

    // Time to say goodbye to our reader friend.
    close_csv_reader(reader);

    return 0;
}