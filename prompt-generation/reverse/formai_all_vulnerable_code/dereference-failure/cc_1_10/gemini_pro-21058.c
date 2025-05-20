//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inspector File Synchronizer
// By Sherlock Holmes

// The case of the missing files
// Inspector Lestrade called upon the world's greatest detective to investigate the curious case of two files that seemed to have vanished. Upon closer examination, it was clear that these files were merely scattered across two different locations.

// The inspector's assistant, young Watson, had managed to gather some clues. He had discovered partial copies of the files in both locations. It was clear that the perpetrator had split the files in two and distributed them across the city.

// Holmes, with his keen intellect, realized that the perpetrator must have used a cunning method to split the files. He deduced that the criminal had used a modulo operation to divide the files into two parts.

// Inspector Lestrade was skeptical. "Modulo? But that's a mathematical concept."

// "Elementary, my dear Lestrade," Holmes replied. "The perpetrator used the modulo operation to determine which part of the file went to which location."

// Holmes's theory was brilliant. He quickly devised a program to stitch the two partial files back together.

// And so, the Inspector File Synchronizer was born.

int main() {
  // Read the two partial files
  FILE *file1 = fopen("part1.txt", "r");
  FILE *file2 = fopen("part2.txt", "r");

  if (file1 == NULL || file2 == NULL) {
    printf("Error opening files.\n");
    return 1;
  }

  // Determine the file size
  fseek(file1, 0, SEEK_END);
  long file1_size = ftell(file1);
  fseek(file1, 0, SEEK_SET);

  fseek(file2, 0, SEEK_END);
  long file2_size = ftell(file2);
  fseek(file2, 0, SEEK_SET);

  // Check if the files are the same size
  if (file1_size != file2_size) {
    printf("Error: Files are not the same size.\n");
    return 1;
  }

  // Create a buffer to store the combined file
  char *combined_file = malloc(file1_size + file2_size);

  // Read the first part of the file
  fread(combined_file, 1, file1_size, file1);

  // Read the second part of the file
  fread(combined_file + file1_size, 1, file2_size, file2);

  // Write the combined file to a new file
  FILE *combined_file_out = fopen("combined.txt", "w");

  if (combined_file_out == NULL) {
    printf("Error opening output file.\n");
    return 1;
  }

  fwrite(combined_file, 1, file1_size + file2_size, combined_file_out);

  fclose(combined_file_out);

  printf("Files successfully synchronized.\n");

  return 0;
}