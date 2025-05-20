//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MINUTE 60
#define STR_LEN 100

void print_quote(void);
void print_string(char *str);
long long get_time_difference(struct timespec start, struct timespec end);

int main(void) {
  char str[STR_LEN] = "The quick brown fox jumps over the lazy dog.";
  int wpm;
  struct timespec start, end;
  long long time_taken;

  // Greeting message and funny quote
  printf("-------------------------------------------\n");
  printf("| Hello, I'm your friendly typing guru, Tycho! |\n");
  printf("| Remember, the only way to be good at typing |\n");
  printf("| is to practice, practice, and practice!     |\n");
  print_quote();
  printf("-------------------------------------------\n");

  // Initialize the variable to store the typing speed
  wpm = 0;

  while (1) {
    clock_gettime(CLOCK_MONOTONIC, &start);
    print_string(str);
    clock_gettime(CLOCK_MONOTONIC, &end);

    time_taken = get_time_difference(start, end);
    wpm = (MINUTE * STR_LEN) / time_taken;

    printf("Typing Speed: %d wpm\n", wpm);
  }

  return EXIT_SUCCESS;
}

void print_quote(void) {
  printf("| 'Typing is the glue that holds the digital world together.' |\n");
  printf("|                                                          |\n");
}

void print_string(char *str) {
  printf("| Type the following string:                               |\n");
  printf("| %s                                                      |\n", str);
  printf("-----------------------------------------------------------\n");
}

long long get_time_difference(struct timespec start, struct timespec end) {
  return (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
}