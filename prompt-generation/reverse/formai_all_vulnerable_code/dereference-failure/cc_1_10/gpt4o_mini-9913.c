//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

// A very serious structure for our CSV data
typedef struct {
    char **columns;
    int column_count;
} CsvRow;

// Declare some very important functions! (They've graduated, you know)
CsvRow* read_csv_line(FILE *file);
void print_csv_row(CsvRow *row);
void free_csv_row(CsvRow *row);

// Here’s a joke: Why did the C programmer get stuck in the shower?
// Because he read the shampoo bottle instructions that said, "Lather, Rinse, Repeat."
// Now, let's program instead! 

int main(int argc, char *argv[]) {
    // Check if user brought along a CSV file...
    if (argc < 2) {
        fprintf(stderr, "Hey there! You forgot to include a CSV file to read. Bye!\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    // If the file simply does not exist, ask for a reality check!
    if (!file) {
        fprintf(stderr, "Oops! No such file exists! Did you try looking behind the couch?\n");
        return EXIT_FAILURE;
    }

    // This is where we party while reading lines...
    while (1) {
        CsvRow *row = read_csv_line(file);
        if (!row) {
            break; // Exit the party when the music stops (or EOF hits)
        }
        print_csv_row(row);
        free_csv_row(row);
    }

    fclose(file);
    printf("All done! Hope you enjoyed this wild read of CSV files. 🎉\n");
    return EXIT_SUCCESS;
}

// Behold, a function for reading a CSV line!
// No, we do NOT mean a queue to the coffee machine.
CsvRow* read_csv_line(FILE *file) {
    char line[MAX_LINE_LENGTH];
    if (!fgets(line, sizeof(line), file)) {
        return NULL; // We ran out of lines, like a sitcom with no more episodes
    }

    CsvRow *row = malloc(sizeof(CsvRow));
    row->columns = malloc(MAX_COLUMNS * sizeof(char*));
    row->column_count = 0;

    char *token = strtok(line, ",");
    while(token) {
        row->columns[row->column_count] = malloc(strlen(token) + 1);
        strcpy(row->columns[row->column_count], token);
        row->column_count++;
        token = strtok(NULL, ",");
    }
    return row;
}

// This function prints out the contents of a CSV row with utmost flair
void print_csv_row(CsvRow *row) {
    printf("🎉 CSV Row (%d columns): ", row->column_count);
    for (int i = 0; i < row->column_count; i++) {
        // Let’s be real, every column needs equal attention
        printf("[%s]", row->columns[i]);
        if (i < row->column_count - 1) {
            printf(" | "); // A separator that deserves applause 
        }
    }
    printf("\n");
}

// It's time to clean the mess! 
void free_csv_row(CsvRow *row) {
    for (int i = 0; i < row->column_count; i++) {
        free(row->columns[i]); // Cleaning up the individual columns like a good citizen
    }
    free(row->columns); // Set the columns free like a bird
    free(row); // And set the row free because nobody should be left alone
}