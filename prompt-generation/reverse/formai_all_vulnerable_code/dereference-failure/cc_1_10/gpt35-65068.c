//FormAI DATASET v1.0 Category: Log analysis ; Style: ultraprecise
/*
* This unique C Log analysis example program reads in a log file, extracts relevant information, and outputs analyzing data
* The log file contains error and warning messages from a software system
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000   // maximum length of each line in the log file
#define MAX_NUM_LINES 10000    // maximum number of lines in the log file
#define MAX_KEYWORD_LENGTH 20  // maximum length of each keyword to search for

int main(int argc, char *argv[]) {
  char log_filename[100];     // name of the log file to analyze
  char keyword[MAX_KEYWORD_LENGTH];   // keyword to search for in the log file
  char lines[MAX_NUM_LINES][MAX_LINE_LENGTH];   // array of lines from the log file
  int num_lines = 0;          // number of lines in the log file
  int i, j;                   // index variables for loops

  if (argc != 3) {            // check for correct number of arguments
    printf("Usage: %s <log_filename> <keyword>\n", argv[0]);
    exit(1);
  }

  // get input values from command line arguments
  strcpy(log_filename, argv[1]);
  strcpy(keyword, argv[2]);

  // open the file for reading
  FILE *fp = fopen(log_filename, "r");
  if (fp == NULL) {           // check for file open errors
    printf("Error opening file: %s\n", log_filename);
    exit(1);
  }

  // read in each line of the log file and store in array
  while (fgets(lines[num_lines], MAX_LINE_LENGTH, fp) != NULL) {
    num_lines++;
    if (num_lines >= MAX_NUM_LINES) {
      printf("Error: maximum number of lines exceeded\n");
      exit(1);
    }
  }

  // close the file
  fclose(fp);

  // search for the keyword in each line of the log file, count occurrences of error and warning messages
  int num_errors = 0;
  int num_warnings = 0;
  for (i = 0; i < num_lines; i++) {
    char *search_result = strstr(lines[i], keyword);
    if (search_result != NULL) {
      if (strstr(search_result, "error") != NULL) {
        num_errors++;
      }
      else if (strstr(search_result, "warning") != NULL) {
        num_warnings++;
      }
    }
  }

  // output analyzing data
  printf("Log file: %s\n", log_filename);
  printf("Keyword: %s\n", keyword);
  printf("\n");
  printf("Number of lines in log file: %d\n", num_lines);
  printf("\n");
  printf("Number of error messages containing keyword: %d\n", num_errors);
  printf("Number of warning messages containing keyword: %d\n", num_warnings);

  return 0;
}