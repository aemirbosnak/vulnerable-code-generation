//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
  char buffer[MAX_BUFFER_SIZE];
  char *pBuffer = buffer;
  FILE *fp = fopen("metadata.txt", "r");

  if (fp == NULL)
  {
    perror("Error opening file");
    exit(1);
  }

  // Read file contents into the buffer
  size_t bytesRead = fread(pBuffer, 1, MAX_BUFFER_SIZE, fp);

  // Check if the file was read successfully
  if (bytesRead == 0)
  {
    perror("Error reading file");
    exit(1);
  }

  // Terminate the buffer with a null character
  pBuffer[bytesRead] = '\0';

  // Search for metadata key-value pairs
  char *pKey, *pValue, *pStart = pBuffer;
  while ((pKey = strstr(pStart, "key: ")) != NULL)
  {
    // Extract the key-value pair
    pValue = strstr(pKey, "value: ");
    if (pValue)
    {
      // Print the key-value pair
      printf("%s: %s\n", pKey, pValue);
    }

    // Move to the next key-value pair
    pStart = pValue + strlen("value: ");
  }

  // Close the file
  fclose(fp);

  return 0;
}