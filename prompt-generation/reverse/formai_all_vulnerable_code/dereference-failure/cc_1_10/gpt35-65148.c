//FormAI DATASET v1.0 Category: Log analysis ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen("logfile.txt", "r");
  if (fp == NULL){
    printf("Error opening file.\n");
    return 1;
  }

  int count[5] = {0,0,0,0,0}; //initialize counters for HTTP methods

  while ((read = getline(&line, &len, fp)) != -1) { // read each line of the file
    char *token = strtok(line, " "); // split the line on whitespace
    if (strcmp(token, "POST") == 0) {
      count[0]++;
    }
    else if (strcmp(token, "GET") == 0) {
      count[1]++;
    }
    else if (strcmp(token, "HEAD") == 0) {
      count[2]++;
    }
    else if (strcmp(token, "PUT") == 0) {
      count[3]++;
    }
    else if (strcmp(token, "DELETE") == 0) {
      count[4]++;
    }
  }

  printf("Count of HTTP Request Methods:\n");
  printf("POST: %d\n", count[0]);
  printf("GET: %d\n", count[1]);
  printf("HEAD: %d\n", count[2]);
  printf("PUT: %d\n", count[3]);
  printf("DELETE: %d\n", count[4]);

  fclose(fp);
  if (line){
    free(line);
  }
  return 0;
}