//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
  uint32_t offset;
  uint32_t size;
  char *name;
} metadata_entry_t;

typedef struct {
  uint32_t count;
  metadata_entry_t *entries;
} metadata_t;

static int read_metadata(const char *filename, metadata_t *metadata) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    return -1;
  }

  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  rewind(fp);

  uint8_t *buffer = malloc(size);
  if (buffer == NULL) {
    fclose(fp);
    return -1;
  }

  fread(buffer, 1, size, fp);
  fclose(fp);

  uint32_t offset = 0;
  uint32_t count = 0;

  while (offset < size) {
    uint32_t size = *(uint32_t *)(buffer + offset);
    offset += sizeof(uint32_t);

    char *name = malloc(size + 1);
    if (name == NULL) {
      free(buffer);
      return -1;
    }

    memcpy(name, buffer + offset, size);
    name[size] = '\0';
    offset += size;

    metadata->entries = realloc(metadata->entries,
                               (count + 1) * sizeof(metadata_entry_t));
    if (metadata->entries == NULL) {
      free(name);
      free(buffer);
      return -1;
    }

    metadata->entries[count].offset = offset;
    metadata->entries[count].size = size;
    metadata->entries[count].name = name;
    count++;
  }

  metadata->count = count;

  free(buffer);

  return 0;
}

static void print_metadata(metadata_t *metadata) {
  for (uint32_t i = 0; i < metadata->count; i++) {
    printf("%s: %u (%u)\n", metadata->entries[i].name,
           metadata->entries[i].offset, metadata->entries[i].size);
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  metadata_t metadata;
  metadata.count = 0;
  metadata.entries = NULL;

  if (read_metadata(argv[1], &metadata) != 0) {
    fprintf(stderr, "Error reading metadata from %s\n", argv[1]);
    return 1;
  }

  print_metadata(&metadata);

  for (uint32_t i = 0; i < metadata.count; i++) {
    free(metadata.entries[i].name);
  }
  free(metadata.entries);

  return 0;
}