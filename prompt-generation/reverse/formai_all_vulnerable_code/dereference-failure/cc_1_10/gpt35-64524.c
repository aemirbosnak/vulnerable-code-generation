//FormAI DATASET v1.0 Category: Error handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
  FILE *fp;
  
  fp = fopen("nonexistent.txt", "r");
  
  if (!fp) {
    printf("Oh dear! An error occurred! Error code: %d\n", errno);
    printf("Here's what went wrong: ");
    switch (errno) {
      case ENOENT:
        printf("File not found.\n");
        break;
      case EACCES:
        printf("Permission denied.\n");
        break;
      default:
        printf("Unknown error.\n");
        break;
    }
    
    printf("But don't worry, I'll fix it!\n");
    
    fp = fopen("newfile.txt", "w");
    
    if (!fp) {
      printf("Oh no, something went wrong again! Error code: %d\n", errno);
      printf("Here's what went wrong: ");
      
      switch (errno) {
        case EACCES:
          printf("Permission denied.\n");
          break;
        default:
          printf("Unknown error.\n");
          break;
      }
      
      printf("I'm sorry, I can't fix this one. Goodbye!\n");
      exit(EXIT_FAILURE);
    }
    
    printf("Phew, everything's back to normal now!\n");
    fprintf(fp, "This is a new file created by the program.");
    fclose(fp);
  } else {
    printf("File opened successfully!");
    // Do something with the file here
    fclose(fp);
  }
  
  return 0;
}