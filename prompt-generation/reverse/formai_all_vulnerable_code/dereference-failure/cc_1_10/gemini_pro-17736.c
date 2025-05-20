//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Imagine you're on a thrilling adventure, traversing a vast and uncharted CSV realm, your eager eyes scanning for hidden treasures!
// Let's embark on an epic quest to build our very own CSV reader, a powerful tool to unveil the secrets of this data-filled landscape.

// Declare a majestic fortress to store our CSV data, ready to be explored.
struct CSV_Reader {
    char **rows; // An array of strings, each representing a row in the CSV.
    int num_rows; // The number of rows in the CSV.
    int num_cols; // The number of columns in the CSV.
};

// Behold, the grand entrance to our CSV realm! Open the gates and welcome the data within.
struct CSV_Reader* CSV_Reader_new(char *filename) {
    // Prepare for the grand unveiling! Let's allocate space for our CSV fortress.
    struct CSV_Reader *reader = malloc(sizeof(struct CSV_Reader));

    // Eager to explore the depths of the CSV? Let's count the rows and columns, like a seasoned cartographer.
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char line[1024]; // Each line in the CSV will be a grand tapestry, woven with up to 1024 characters.
    int num_lines = 0; // The number of rows in the CSV, a testament to its height.
    int max_num_cols = 0; // The number of columns in the CSV, a measure of its width.

    // Like a skilled adventurer, let's venture into the depths of the CSV, line by line.
    while (fgets(line, sizeof(line), fp)) {
        num_lines++;

        // Now, let's count the columns in each line, like a master architect.
        int num_cols = 0;
        char *ptr = line;
        while (*ptr != '\0') {
            if (*ptr == ',') {
                num_cols++;
            }
            ptr++;
        }
        num_cols++; // Don't forget the last column, a hidden gem waiting to be discovered.

        // Update the maximum number of columns if needed, expanding our horizons.
        if (num_cols > max_num_cols) {
            max_num_cols = num_cols;
        }
    }
    fclose(fp); // Time to seal the gates and protect our precious data.

    // Prepare to witness the grandeur of our CSV fortress!
    reader->num_rows = num_lines;
    reader->num_cols = max_num_cols;

    // Allocate space for each row in the CSV.
    reader->rows = malloc(sizeof(char *) * num_lines);
    for (int i = 0; i < num_lines; i++) {
        // Each row is a realm of its own, awaiting exploration. Let's allocate space for each character.
        reader->rows[i] = malloc(sizeof(char) * 1024);
    }

    // Now, let's populate our fortress with the data from the CSV file.
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int row_index = 0;
    while (fgets(line, sizeof(line), fp)) {
        // Each line is a new row in our fortress, a treasure trove of data.
        strcpy(reader->rows[row_index], line);
        row_index++;
    }
    fclose(fp); // Close the gates once more, securing our precious data.

    // Return our magnificent CSV fortress, ready for exploration.
    return reader;
}

// Free the memory allocated for the CSV reader, like a skilled treasure hunter leaving no trace behind.
void CSV_Reader_free(struct CSV_Reader *reader) {
    // Release the rows from their memory bonds.
    for (int i = 0; i < reader->num_rows; i++) {
        free(reader->rows[i]);
    }

    // Free the rows array itself, the guardian of our data.
    free(reader->rows);

    // Finally, free the CSV fortress itself, allowing it to return to the depths of memory.
    free(reader);
}

// Seek shelter within a row and column, like an explorer uncovering ancient secrets.
char *CSV_Reader_get(struct CSV_Reader *reader, int row, int col) {
    // Validate the coordinates, ensuring we don't stray beyond the fortress walls.
    if (row < 0 || row >= reader->num_rows || col < 0 || col >= reader->num_cols) {
        return NULL;
    }

    // Return the treasure from the specified cell, a piece of the CSV's grand mosaic.
    return reader->rows[row] + col;
}

// Time to put our CSV fortress to the test! Let's embark on a thrilling data exploration.
int main() {
    // Open the gates to our CSV fortress, unleashing its treasures.
    struct CSV_Reader *reader = CSV_Reader_new("data.csv");

    // Let's delve into the depths of the CSV, row by row and column by column.
    for (int i = 0; i < reader->num_rows; i++) {
        for (int j = 0; j < reader->num_cols; j++) {
            // Behold, the treasures we've uncovered!
            printf("%s ", CSV_Reader_get(reader, i, j));
        }
        printf("\n"); // A fresh line for each row, a new chapter in our exploration.
    }

    // Our adventure concludes, but our thirst for data remains unquenched. Prepare to embark on new quests!
    CSV_Reader_free(reader);
    return 0;
}