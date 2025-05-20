//FormAI DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum book and chapter lengths
#define MAX_BOOK_LENGTH 50
#define MAX_CHAPTER_LENGTH 20

// Define structure for storing book and chapter information
typedef struct {
   char book[MAX_BOOK_LENGTH];
   int chapter;
} BookChapter;

// Define structure for storing Ebook information
typedef struct {
   BookChapter current;
   char* text;
} Ebook;

// Define function for loading a chapter of the Ebook
char* loadChapter(char* book, int chapter) {
   // Open file for reading
   char filename[MAX_BOOK_LENGTH + MAX_CHAPTER_LENGTH + 5];
   sprintf(filename, "%s_chapter%d.txt", book, chapter);
   FILE* file = fopen(filename, "r");

   if (file == NULL) {
      // File could not be opened
      printf("Could not load chapter %d of book %s\n", chapter, book);
      return NULL;
   }

   // Get file size
   fseek(file, 0, SEEK_END);
   long fileSize = ftell(file);
   fseek(file, 0, SEEK_SET);

   // Allocate memory for file contents
   char* fileContents = (char*) malloc(fileSize + 1);

   // Read file contents
   size_t bytesRead = fread(fileContents, sizeof(char), fileSize, file);
   fileContents[bytesRead] = '\0';

   // Close file and return file contents
   fclose(file);
   return fileContents;
}

// Define function for printing the current chapter of the Ebook
void printCurrentChapter(Ebook* ebook) {
   printf("%s\n", ebook->text);
}

// Define function for moving to the next chapter of the Ebook
void nextChapter(Ebook* ebook) {
   ebook->current.chapter++;
   ebook->text = loadChapter(ebook->current.book, ebook->current.chapter);

   if (ebook->text == NULL) {
      // Chapter could not be loaded, go back to previous chapter
      ebook->current.chapter--;
      ebook->text = loadChapter(ebook->current.book, ebook->current.chapter);
   }
}

// Define main function
int main() {
   // Allocate memory for Ebook
   Ebook* ebook = (Ebook*) malloc(sizeof(Ebook));

   // Set initial book and chapter
   strncpy(ebook->current.book, "The Adventures of Tom Sawyer", MAX_BOOK_LENGTH);
   ebook->current.chapter = 1;
   ebook->text = loadChapter(ebook->current.book, ebook->current.chapter);

   if (ebook->text == NULL) {
      printf("Could not load Ebook. Exiting...\n");
      return 0;
   }

   // Print welcome message and first chapter of Ebook
   printf("Welcome to the Ebook reader!\n");
   printf("Book: %s\n", ebook->current.book);
   printf("Chapter: %d\n\n", ebook->current.chapter);
   printCurrentChapter(ebook);

   // Wait for user input to move to next chapter
   while (1) {
      printf("\nPress ENTER to continue, or Q to quit: ");
      char input[2];
      fgets(input, 2, stdin);

      if (input[0] == 'q' || input[0] == 'Q') {
         break;
      }

      nextChapter(ebook);

      // Print current book and chapter, and current chapter of Ebook
      printf("\nBook: %s\n", ebook->current.book);
      printf("Chapter: %d\n\n", ebook->current.chapter);
      printCurrentChapter(ebook);
   }

   // Free memory and exit
   free(ebook->text);
   free(ebook);
   return 0;
}