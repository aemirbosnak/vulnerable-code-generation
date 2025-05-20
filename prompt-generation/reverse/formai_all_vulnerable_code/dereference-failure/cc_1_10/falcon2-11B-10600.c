//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <ebook_file>\n", argv[0]);
        exit(1);
    }

    // Open the ebook file for reading
    FILE *ebook = fopen(argv[1], "r");
    if (ebook == NULL) {
        fprintf(stderr, "Error opening ebook file: %s\n", argv[1]);
        exit(1);
    }

    // Read the first line of the ebook file
    int length = 0;
    char *line = NULL;
    while ((line = fgets(line, sizeof(line), ebook))!= NULL) {
        length += strlen(line);
    }

    // Close the ebook file
    fclose(ebook);

    // Allocate memory for the entire ebook
    char *ebook_text = (char *)malloc(length);
    if (ebook_text == NULL) {
        fprintf(stderr, "Error allocating memory for ebook text\n");
        exit(1);
    }

    // Re-open the ebook file for reading
    ebook = fopen(argv[1], "r");
    if (ebook == NULL) {
        fprintf(stderr, "Error opening ebook file: %s\n", argv[1]);
        exit(1);
    }

    // Read the entire ebook file into memory
    fseek(ebook, 0, SEEK_SET);
    fread(ebook_text, 1, length, ebook);

    // Close the ebook file
    fclose(ebook);

    // Print the ebook text to the screen
    printf("%s\n", ebook_text);

    // Free the memory allocated for the ebook text
    free(ebook_text);

    return 0;
}