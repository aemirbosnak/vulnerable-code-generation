//GEMINI-pro DATASET v1.0 Category: System administration ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Constants for the command line arguments
#define ARG_COUNT 5
#define ARG_INFILE 1
#define ARG_OUTFILE 2
#define ARG_SEARCHTERM 3
#define ARG_CASEINSENSITIVE 4
#define ARG_HELP 5

// Helper function to print the usage information
void print_usage() {
  printf("Usage: sherlock [-i infile] [-o outfile] [-s searchterm] [-c] [-h]\n");
  printf("\n");
  printf("  -i infile      The input file to search.\n");
  printf("  -o outfile     The output file to write the results to.\n");
  printf("  -s searchterm  The term to search for.\n");
  printf("  -c             Enable case-insensitive search.\n");
  printf("  -h             Print this usage information and exit.\n");
}

// Helper function to perform a case-insensitive search
int strcicmp(const char *s1, const char *s2) {
  int c1, c2;
  do {
    c1 = *s1++;
    c2 = *s2++;
    if (c1 >= 'A' && c1 <= 'Z') {
      c1 += 'a' - 'A';
    }
    if (c2 >= 'A' && c2 <= 'Z') {
      c2 += 'a' - 'A';
    }
  } while (c1 == c2 && c1 != '\0');
  return c1 - c2;
}

// Main function
int main(int argc, char *argv[]) {
  // Parse the command line arguments
  char *infile = NULL;
  char *outfile = NULL;
  char *searchterm = NULL;
  int caseinsensitive = 0;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-i") == 0) {
      if (i + 1 < argc) {
        infile = argv[i + 1];
        i++;
      } else {
        printf("Error: Missing argument for -i.\n");
        print_usage();
        return 1;
      }
    } else if (strcmp(argv[i], "-o") == 0) {
      if (i + 1 < argc) {
        outfile = argv[i + 1];
        i++;
      } else {
        printf("Error: Missing argument for -o.\n");
        print_usage();
        return 1;
      }
    } else if (strcmp(argv[i], "-s") == 0) {
      if (i + 1 < argc) {
        searchterm = argv[i + 1];
        i++;
      } else {
        printf("Error: Missing argument for -s.\n");
        print_usage();
        return 1;
      }
    } else if (strcmp(argv[i], "-c") == 0) {
      caseinsensitive = 1;
    } else if (strcmp(argv[i], "-h") == 0) {
      print_usage();
      return 0;
    } else {
      printf("Error: Unknown argument: %s.\n", argv[i]);
      print_usage();
      return 1;
    }
  }

  // Check if the required arguments are present
  if (!infile || !outfile || !searchterm) {
    printf("Error: Missing required arguments.\n");
    print_usage();
    return 1;
  }

  // Open the input file
  FILE *fp = fopen(infile, "r");
  if (!fp) {
    printf("Error: Could not open input file: %s.\n", infile);
    return 1;
  }

  // Open the output file
  FILE *fpout = fopen(outfile, "w");
  if (!fpout) {
    printf("Error: Could not open output file: %s.\n", outfile);
    fclose(fp);
    return 1;
  }

  // Read the input file line by line
  char line[1024];
  int line_number = 1;
  while (fgets(line, sizeof(line), fp)) {
    // Remove the newline character from the line
    line[strcspn(line, "\n")] = '\0';

    // Search for the search term in the line
    char *found = NULL;
    if (caseinsensitive) {
      found = strcasestr(line, searchterm);
    } else {
      found = strstr(line, searchterm);
    }

    // If the search term was found, write the line to the output file
    if (found) {
      fprintf(fpout, "%d: %s\n", line_number, line);
    }

    // Increment the line number
    line_number++;
  }

  // Close the input and output files
  fclose(fp);
  fclose(fpout);

  // Print a success message
  printf("The search for \"%s\" in file \"%s\" has completed.\n", searchterm, infile);
  printf("The results have been written to file \"%s\".\n", outfile);

  return 0;
}