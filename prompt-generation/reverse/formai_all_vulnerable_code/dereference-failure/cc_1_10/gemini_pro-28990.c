//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MAX_URL_LENGTH 256
#define MAX_PAGE_SIZE 4096

// Function prototypes
char *get_url(void);
char *get_page(char *url);
void display_page(char *page);

// Main function
int main(void) {
  // Get the URL from the user
  char *url = get_url();

  // Get the page from the URL
  char *page = get_page(url);

  // Display the page
  display_page(page);

  // Free the memory allocated for the page
  free(page);

  // Return 0 to indicate success
  return 0;
}

// Function to get the URL from the user
char *get_url(void) {
  // Allocate memory for the URL
  char *url = malloc(MAX_URL_LENGTH);

  // Get the URL from the user
  printf("Enter the URL: ");
  scanf("%s", url);

  // Return the URL
  return url;
}

// Function to get the page from the URL
char *get_page(char *url) {
  // Allocate memory for the page
  char *page = malloc(MAX_PAGE_SIZE);

  // Open the URL
  FILE *fp = fopen(url, "r");

  // Check if the URL was opened successfully
  if (fp == NULL) {
    printf("Error opening URL: %s\n", url);
    return NULL;
  }

  // Read the page from the URL
  fread(page, 1, MAX_PAGE_SIZE, fp);

  // Close the URL
  fclose(fp);

  // Return the page
  return page;
}

// Function to display the page
void display_page(char *page) {
  // Print the page to the console
  printf("%s\n", page);
}