//LLAMA2-13B DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Define some constants and variables
#define PI 3.14159
#define COOKIE_COUNT 10
#define COOKIE_SIZE 5
#define MAX_GUESTS 5
#define GUEST_NAME_LEN 20

// Function to print a message
void print_message(const char* message) {
  printf("%s\n", message);
}

// Function to generate a random name for a guest
char* generate_guest_name() {
  char name[GUEST_NAME_LEN];
  int i;

  // Generate a random name
  for (i = 0; i < GUEST_NAME_LEN; i++) {
    name[i] = 'a' + (rand() % 26);
  }

  return name;
}

// Function to create a cookie
void create_cookie(int size) {
  printf("Baking a delicious %dx%d cookie...\n", size, size);

  // Generate a random filling
  char filling[COOKIE_SIZE * COOKIE_SIZE];
  int i, j;

  for (i = 0; i < COOKIE_SIZE; i++) {
    for (j = 0; j < COOKIE_SIZE; j++) {
      filling[i * COOKIE_SIZE + j] = 'a' + (rand() % 26);
    }
  }

  // Print the cookie
  printf("Cookie filled with: %s\n", filling);
}

// Function to serve cookies to guests
void serve_cookies(int guest_count) {
  int i;

  for (i = 0; i < guest_count; i++) {
    char* guest_name = generate_guest_name();
    create_cookie(COOKIE_SIZE);
    printf("Serving %s a delicious cookie!\n", guest_name);
  }
}

int main() {
  srand(time(NULL)); // Seed the random number generator

  // Invite some guests
  int guest_count = MAX_GUESTS;
  char** guest_names = malloc(guest_count * sizeof(char*));

  for (int i = 0; i < guest_count; i++) {
    guest_names[i] = generate_guest_name();
  }

  // Serve cookies to the guests
  serve_cookies(guest_count);

  // Clean up
  for (int i = 0; i < guest_count; i++) {
    free(guest_names[i]);
  }
  free(guest_names);

  return 0;
}