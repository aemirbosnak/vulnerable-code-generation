//FormAI DATASET v1.0 Category: Image Classification system ; Style: relaxed
// Welcome to my Image Classification system example program!
// This program takes in a directory of images and classifies them based on their content.
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() {
  // Get the directory name from the user
  char directoryName[50]; 
  printf("Enter the directory name: ");
  scanf("%s", directoryName);

  // Open the directory
  DIR* directory = opendir(directoryName);

  if (directory == NULL) {
    printf("Could not open directory.\n");
    return 1;
  }

  // Declare variables used for image classification
  int numImages = 0;
  int numDogs = 0;
  int numCats = 0;
  int numOther = 0;

  struct dirent* entry;
  char filename[256];

  // Loop through each file in the directory
  while ((entry = readdir(directory)) != NULL) {
    // Ignore "." and ".." directories
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    // Build the full file path
    sprintf(filename, "%s/%s", directoryName, entry->d_name);

    // Determine if the file is a dog, cat, or something else
    if (strstr(filename, "dog") != NULL) {
      numDogs++;
    } else if (strstr(filename, "cat") != NULL) {
      numCats++;
    } else {
      numOther++;
    }

    numImages++;
  }

  // Close the directory
  closedir(directory);

  // Print out the classification results
  printf("Number of images: %d\n", numImages);
  printf("Number of dogs: %d\n", numDogs);
  printf("Number of cats: %d\n", numCats);
  printf("Number of other images: %d\n", numOther);

  return 0;
}