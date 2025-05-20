//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

// Function to read the log file
void log_read(char* log_file, char** lines, int* num_lines) {
   FILE* fp = fopen(log_file, "r");
   if (fp == NULL) {
      printf("Error opening log file\n");
      exit(1);
   }

   char line[MAX_LINE_LENGTH];
   int line_count = 0;
   while (fgets(line, sizeof(line), fp)) {
      ++line_count;
      if (line_count >= MAX_NUM_LINES) {
         break;
      }
      lines[line_count] = strdup(line);
   }

   fclose(fp);
   *num_lines = line_count;
}

// Function to parse the log file
void log_parse(char** lines, int num_lines) {
   for (int i = 0; i < num_lines; ++i) {
      char* tokens[10];
      char* token;
      sscanf(lines[i], "%s %s %s %s %s %s %s %s %s %s",
         &tokens[0], &tokens[1], &tokens[2], &tokens[3], &tokens[4],
         &tokens[5], &tokens[6], &tokens[7], &tokens[8], &tokens[9]);

      printf("Timestamp: %s\n", tokens[0]);
      printf("User: %s\n", tokens[1]);
      printf("IP: %s\n", tokens[2]);
      printf("Request: %s\n", tokens[3]);
      printf("Status: %s\n", tokens[4]);
      printf("Bytes: %lu\n", (unsigned long)strtol(tokens[5], NULL, 10));
      printf("Duration: %ld\n", (long)strtol(tokens[6], NULL, 10));
      printf("Referrer: %s\n", tokens[7]);
      printf("UA: %s\n", tokens[8]);
      printf("Error: %s\n", tokens[9]);
   }
}

// Function to print the analysis
void log_print(char** lines, int num_lines) {
   log_parse(lines, num_lines);
}

int main(int argc, char** argv) {
   char* log_file = "access.log";
   char** lines;
   int num_lines;

   log_read(log_file, &lines, &num_lines);
   log_print(lines, num_lines);

   free(lines[0]);
   for (int i = 1; i < num_lines; ++i) {
      free(lines[i]);
   }
   free(lines);

   return 0;
}