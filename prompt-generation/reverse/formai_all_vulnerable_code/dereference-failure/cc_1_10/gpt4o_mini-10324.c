//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 256
#define COMPRESSION_RATIO 4

// Structure to represent a knight's tale segment
typedef struct TaleSegment {
    char *text;
    int count;
} TaleSegment;

// Function to compress the tale segments
TaleSegment *compressTales(const char *tale, int *segmentCount) {
    TaleSegment *segments = malloc(MAX_STRING_LENGTH * sizeof(TaleSegment));
    if (!segments) {
        fprintf(stderr, "Alas! Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    int idx = 0; // Current segment index
    int length = strlen(tale);
    char currentChar;
    int count;

    for (int i = 0; i < length; ) {
        currentChar = tale[i];
        count = 0;

        // Count occurrences of the current character
        while (i < length && tale[i] == currentChar) {
            count++;
            i++;
        }

        // Store the segment if it meets the compression criteria
        if(count > 1) {
            segments[idx].text = malloc(4); // e.g., 'a3', 'b5'
            if (!segments[idx].text) {
                fprintf(stderr, "Alas! Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
            snprintf(segments[idx].text, 4, "%c%d", currentChar, count);
        } else {
            segments[idx].text = malloc(2); // Single character
            if (!segments[idx].text) {
                fprintf(stderr, "Alas! Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
            snprintf(segments[idx].text, 2, "%c", currentChar);
        }

        segments[idx].count = count;
        idx++;
    }

    *segmentCount = idx;
    return segments;
}

// Function to display the compressed tale
void displayCompressedTale(TaleSegment *segments, int segmentCount) {
    printf("Behold! The grand tale, now compressed:\n");
    for (int i = 0; i < segmentCount; i++) {
        printf("%s ", segments[i].text);
    }
    printf("\n");
}

// Function to free memory occupied by tale segments
void freeTaleSegments(TaleSegment *segments, int segmentCount) {
    for (int i = 0; i < segmentCount; i++) {
        free(segments[i].text);
    }
    free(segments);
}

int main() {
    char tale[MAX_STRING_LENGTH];

    printf("Enter thy tale of valiance: ");
    fgets(tale, MAX_STRING_LENGTH, stdin);
    tale[strcspn(tale, "\n")] = 0; // Remove newline character

    int segmentCount = 0;
    TaleSegment *compressedSegments = compressTales(tale, &segmentCount);

    displayCompressedTale(compressedSegments, segmentCount);

    freeTaleSegments(compressedSegments, segmentCount);
    return 0;
}