//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* artist;
  char* album;
  char* title;
  int year;
} Song;

void cleanUp(Song* s) {
  if (s != NULL) {
    free(s->artist);
    free(s->album);
    free(s->title);
    free(s);
  }
}

Song* extractMetadata(const char* filename) {
  // Code for extracting metadata goes here
  // For example, if the metadata is stored in a JSON format:
  Song* song = malloc(sizeof(Song));
  if (song == NULL) {
    fprintf(stderr, "Error: failed to allocate memory for Song\n");
    return NULL;
  }
  song->artist = NULL;
  song->album = NULL;
  song->title = NULL;
  song->year = 0;
  FILE* file = fopen(filename, "r");
  char* line = NULL;
  size_t lineBufSize = 0;
  ssize_t lineSize = 0;
  while ((lineSize = getline(&line, &lineBufSize, file)) != -1) {
    if (strstr(line, "\"artist\": ") != NULL) {
      char* startPos = strchr(line, '\"') + 1;
      char* endPos = strrchr(startPos, '\"');
      *endPos = '\0';
      song->artist = strdup(startPos);
    } else if (strstr(line, "\"album\": ") != NULL) {
      char* startPos = strchr(line, '\"') + 1;
      char* endPos = strrchr(startPos, '\"');
      *endPos = '\0';
      song->album = strdup(startPos);
    } else if (strstr(line, "\"title\": ") != NULL) {
      char* startPos = strchr(line, '\"') + 1;
      char* endPos = strrchr(startPos, '\"');
      *endPos = '\0';
      song->title = strdup(startPos);
    } else if (strstr(line, "\"year\": ") != NULL) {
      char* startPos = strchr(line, ':') + 2;
      char* endPos = strchr(startPos, ',');
      if (endPos == NULL) {
        endPos = strchr(startPos, '}');
      }
      *endPos = '\0';
      song->year = atoi(startPos);
    }
  }
  free(line);
  fclose(file);
  return song;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  Song* song = extractMetadata(argv[1]);
  if (song == NULL) {
    return 1;
  }
  printf("Artist: %s\n", song->artist);
  printf("Album: %s\n", song->album);
  printf("Title: %s\n", song->title);
  printf("Year: %d\n", song->year);
  cleanUp(song);
  return 0;
}