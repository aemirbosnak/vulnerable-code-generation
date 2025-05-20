//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold metadata information
typedef struct {
    char *title;
    char *author;
    char *genre;
    int year;
    float rating;
} Metadata;

// Function prototypes
void addMetadata(Metadata *data, const char *title, const char *author, const char *genre, int year, float rating);
void printMetadata(const Metadata *data);
void freeMetadata(Metadata *data);

int main() {
    int numBooks = 0;
    int capacity = 2; // Initial capacity
    Metadata *library = malloc(sizeof(Metadata) * capacity); // Allocate memory for book metadata

    while (1) {
        char input[256];
        printf("Enter book details in the format [Title, Author, Genre, Year, Rating] or 'exit' to finish:\n");
        fgets(input, sizeof(input), stdin);
        
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        char title[100], author[100], genre[100];
        int year;
        float rating;

        // Parse user input
        if (sscanf(input, "%99[^,], %99[^,], %99[^,], %d, %f", title, author, genre, &year, &rating) == 5) {
            // Resize the library if needed
            if (numBooks >= capacity) {
                capacity *= 2; // Double the capacity
                library = realloc(library, sizeof(Metadata) * capacity); // Resize the library
                if (!library) {
                    fprintf(stderr, "Memory allocation failed\n");
                    return 1;
                }
            }

            // Add metadata to library
            addMetadata(&library[numBooks], title, author, genre, year, rating);
            numBooks++;
            printf("Book added successfully!\n");
        } else {
            printf("Invalid input format. Please try again.\n");
        }
    }

    printf("\nLibrary Metadata:\n");
    for (int i = 0; i < numBooks; i++) {
        printMetadata(&library[i]);
    }

    // Free allocated memory
    for (int i = 0; i < numBooks; i++) {
        freeMetadata(&library[i]);
    }
    free(library); // Free the library array

    return 0;
}

// Function to add metadata to a book
void addMetadata(Metadata *data, const char *title, const char *author, const char *genre, int year, float rating) {
    data->title = strdup(title);
    data->author = strdup(author);
    data->genre = strdup(genre);
    data->year = year;
    data->rating = rating;
}

// Function to print metadata
void printMetadata(const Metadata *data) {
    printf("Title: %sAuthor: %sGenre: %sYear: %d\nRating: %.2f\n\n", 
        data->title, data->author, data->genre, data->year, data->rating);
}

// Function to free allocated strings in a Metadata object
void freeMetadata(Metadata *data) {
    free(data->title);
    free(data->author);
    free(data->genre);
}