//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Visionary "Ebook" Structure
typedef struct {
  char *title;               // Title of the ebook
  int num_chapters;          // Number of chapters
  char **chapters;          // Array of chapter texts
  int *chapter_lengths;     // Array of chapter lengths
  int total_length;         // Total length of the ebook in characters
} Ebook;

// Loads an ebook from a file
Ebook *load_ebook(const char *filename) {
  FILE *fp;
  Ebook *ebook;

  // Open the file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read the title of the ebook
  char *title = malloc(100);
  fscanf(fp, "%s", title);

  // Read the number of chapters in the ebook
  int num_chapters;
  fscanf(fp, "%d", &num_chapters);

  // Allocate memory for the ebook struct
  ebook = malloc(sizeof(Ebook));
  ebook->title = title;
  ebook->num_chapters = num_chapters;

  // Allocate memory for the array of chapter texts
  ebook->chapters = malloc(sizeof(char *) * num_chapters);

  // Allocate memory for the array of chapter lengths
  ebook->chapter_lengths = malloc(sizeof(int) * num_chapters);

  // Read the text of each chapter
  int total_length = 0;
  for (int i = 0; i < num_chapters; i++) {
    // Read the length of the chapter
    int chapter_length;
    fscanf(fp, "%d", &chapter_length);

    // Allocate memory for the chapter text
    char *chapter = malloc(chapter_length + 1);

    // Read the text of the chapter
    fscanf(fp, "%s", chapter);

    // Store the chapter text and length
    ebook->chapters[i] = chapter;
    ebook->chapter_lengths[i] = chapter_length;

    // Update the total length of the ebook
    total_length += chapter_length;
  }

  // Close the file
  fclose(fp);

  // Set the total length of the ebook
  ebook->total_length = total_length;

  // Return the ebook
  return ebook;
}

// Unloads an ebook from memory
void unload_ebook(Ebook *ebook) {
  // Free the title of the ebook
  free(ebook->title);

  // Free the array of chapter texts
  for (int i = 0; i < ebook->num_chapters; i++) {
    free(ebook->chapters[i]);
  }
  free(ebook->chapters);

  // Free the array of chapter lengths
  free(ebook->chapter_lengths);

  // Free the ebook struct
  free(ebook);
}

// Prints the table of contents of an ebook
void print_toc(Ebook *ebook) {
  printf("Table of Contents\n");
  for (int i = 0; i < ebook->num_chapters; i++) {
    printf("%d. %s\n", i + 1, ebook->chapters[i]);
  }
}

// Reads a chapter from an ebook
char *read_chapter(Ebook *ebook, int chapter_num) {
  if (chapter_num < 1 || chapter_num > ebook->num_chapters) {
    printf("Invalid chapter number\n");
    return NULL;
  }

  // Get the start and end positions of the chapter in the ebook
  int start_pos = 0;
  int end_pos = ebook->total_length;
  for (int i = 0; i < chapter_num - 1; i++) {
    start_pos += ebook->chapter_lengths[i];
    end_pos += ebook->chapter_lengths[i];
  }

  // Allocate memory for the chapter text
  char *chapter = malloc(ebook->chapter_lengths[chapter_num - 1] + 1);

  // Copy the chapter text from the ebook
  for (int i = start_pos; i < end_pos; i++) {
    chapter[i - start_pos] = ebook->chapters[chapter_num - 1][i];
  }

  // Add a null terminator to the end of the chapter text
  chapter[ebook->chapter_lengths[chapter_num - 1]] = '\0';

  // Return the chapter text
  return chapter;
}

// Main function
int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <ebook file>\n", argv[0]);
    return 1;
  }

  // Load the ebook
  Ebook *ebook = load_ebook(argv[1]);
  if (ebook == NULL) {
    return 1;
  }

  // Print the table of contents
  print_toc(ebook);

  // Read a chapter from the ebook
  int chapter_num;
  printf("Enter the number of the chapter you want to read: ");
  scanf("%d", &chapter_num);

  char *chapter = read_chapter(ebook, chapter_num);
  if (chapter == NULL) {
    return 1;
  }

  // Print the chapter
  printf("%s\n", chapter);

  // Free the chapter text
  free(chapter);

  // Unload the ebook
  unload_ebook(ebook);

  return 0;
}