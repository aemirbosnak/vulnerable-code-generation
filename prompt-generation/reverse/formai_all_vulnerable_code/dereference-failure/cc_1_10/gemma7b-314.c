//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAGIC_NUMBER 13

void extractMetadata(char **data)
{
  int i, magicNumber = MAGIC_NUMBER;
  char **metadata = NULL;

  // Allocate memory for metadata
  metadata = malloc(magicNumber * sizeof(char *));

  // Iterate over data to extract metadata
  for (i = 0; data[i] != NULL; i++)
  {
    char *line = data[i];

    // Check if line starts with "Meta:"
    if (line[0] == 'M' && line[1] == 'e')
    {
      // Extract metadata key-value pair
      char *key = line + 2;
      char *value = strchr(key, ':');

      // Allocate memory for key-value pair
      metadata[magicNumber++] = malloc(strlen(key) + strlen(value) + 1);

      // Copy key-value pair
      strcpy(metadata[magicNumber - 1], key);
      strcpy(metadata[magicNumber - 1] + strlen(key) + 1, value);
    }
  }

  // Return metadata
  *data = metadata;
}

int main()
{
  char **data = NULL;

  // Extract metadata from data
  extractMetadata(data);

  // Print metadata
  for (int i = 0; data[i] != NULL; i++)
  {
    printf("%s: %s\n", data[i]);
  }

  return 0;
}