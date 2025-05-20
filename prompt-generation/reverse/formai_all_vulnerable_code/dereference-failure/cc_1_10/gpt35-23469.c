//FormAI DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 20 // Number of lines per page
#define LINE_SIZE 100 // Maximum number of characters per line

// Function to read a text file into a buffer
char* load_file(char* filename) {
  FILE* file = fopen(filename, "r"); // Open file for reading
  if (file == NULL) {
    printf("Error: could not open file\n");
    exit(1); // Terminate program with error code
  }

  // Determine file size by seeking to the end of the file
  fseek(file, 0L, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0L, SEEK_SET);

  // Allocate buffer and read file contents
  char* buffer = (char*) malloc(file_size + 1);
  size_t bytesRead = fread(buffer, sizeof(char), file_size, file);
  buffer[bytesRead] = '\0'; // Add null terminator to end of buffer

  fclose(file); // Close file
  return buffer;
}

// Function to display a page of text
void display_page(char* text, int page) {
  // Calculate start and end positions of page in text buffer
  int start = page * PAGE_SIZE * LINE_SIZE;
  int end = (page + 1) * PAGE_SIZE * LINE_SIZE;

  // Print lines from buffer within page range
  for (int i = start; i < end && text[i] != '\0'; i++) {
    putchar(text[i]);
    if (text[i] == '\n' && (i + 1) % LINE_SIZE == 0) {
      printf("\nPress any key to continue...");
      getchar();
     }
  }
}

int main() {
  char* text = load_file("book.txt"); // Load text file into buffer
  int num_pages = strlen(text) / (PAGE_SIZE * LINE_SIZE); // Calculate number of pages

  // Loop to display pages and navigate through book
  int current_page = 0;
  while (1) {
    system("clear"); // Clear terminal screen
    printf("E-Book Reader\n\n");
    display_page(text, current_page);
    printf("\nPage %d/%d", current_page + 1, num_pages + 1);

    // Prompt user for input and navigate through book
    char input = getchar();
    if (input == 'q') {
      break; // Quit program
    } else if (input == 'n' && current_page < num_pages) {
      current_page++; // Go to next page
    } else if (input == 'p' && current_page > 0) {
      current_page--; // Go to previous page
    } else if (input == 'r') {
      current_page = 0; // Return to beginning of book
    }
  }

  free(text); // Deallocate buffer memory
  return 0; // Exit program with success code
}