//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void extract_metadata(char **buffer)
{
  char *ptr = *buffer;
  char *metadata_start = NULL;
  char *metadata_end = NULL;

  // Traverse the buffer for the start of the metadata
  while (*ptr)
  {
    if (strcmp(ptr, "<Metadata>") == 0)
    {
      metadata_start = ptr;
      break;
    }
    ptr++;
  }

  // Traverse the buffer for the end of the metadata
  while (*ptr)
  {
    if (strcmp(ptr, "</Metadata>") == 0)
    {
      metadata_end = ptr;
      break;
    }
    ptr++;
  }

  // Extract the metadata
  if (metadata_start && metadata_end)
  {
    *buffer = malloc((metadata_end - metadata_start) + 1);
    memcpy(*buffer, metadata_start, (metadata_end - metadata_start) + 1);
  }
}

int main()
{
  char *buffer = NULL;
  char *metadata = NULL;

  // Get the buffer
  buffer = malloc(MAX_BUFFER_SIZE);
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Extract the metadata
  extract_metadata(&buffer);

  // Print the metadata
  if (metadata)
  {
    printf("Metadata:\n");
    printf("%s", metadata);
  }

  // Free the memory
  free(buffer);
  free(metadata);

  return 0;
}