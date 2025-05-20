//GEMINI-pro DATASET v1.0 Category: File handling ; Style: retro
/*
           _
        .-' ':'-.
       /  ,  :  ,  \
      /  /    :    \  \
     /  /    ,    \  \       ,
    /  /    :    \  \     / \
    \  \    ,    /  /   ,'   \
     \  \  :  /  /  ,'     \_,'.
      \  `'  `'  ,'  ,' ,' ,-'
       `.     ,'   ,'/ ,' /
         `. ,"' .-.,. / /
           '    '.__,-'
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *fileName = "ascii_art.txt";
  char *buffer;
  FILE *file = fopen(fileName, "r");
  if (file == NULL) {
    printf("Error: Could not open file %s\n", fileName);
    return 1;
  }

  // Get the size of the file
  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  rewind(file);

  // Allocate memory for the buffer
  buffer = (char *)malloc(fileSize + 1);
  if (buffer == NULL) {
    printf("Error: Could not allocate memory for buffer\n");
    fclose(file);
    return 1;
  }

  // Read the file into the buffer
  fread(buffer, fileSize, 1, file);
  fclose(file);

  // Print the buffer to the console
  printf("%s", buffer);

  // Free the memory allocated for the buffer
  free(buffer);

  return 0;
}