//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the checksum of a string
unsigned int checksum(const char *str) {
  unsigned int sum = 0;
  while (*str) {
    sum += *str++;
  }
  return sum;
}

// Function to test the checksum function
void test_checksum() {
  char *str = "Hello, world!";
  unsigned int csum = checksum(str);
  printf("Checksum of '%s' is %u\n", str, csum);
}

// Function to generate a random string
char *random_string(int length) {
  char *str = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    str[i] = 'a' + rand() % 26;
  }
  str[length] = '\0';
  return str;
}

// Function to test the checksum function with random strings
void test_checksum_random() {
  for (int i = 0; i < 100; i++) {
    char *str = random_string(rand() % 100);
    unsigned int csum = checksum(str);
    printf("Checksum of '%s' is %u\n", str, csum);
    free(str);
  }
}

// Function to test the checksum function with large strings
void test_checksum_large() {
  char *str = malloc(1000000);
  for (int i = 0; i < 1000000; i++) {
    str[i] = 'a';
  }
  str[999999] = '\0';
  unsigned int csum = checksum(str);
  printf("Checksum of '%s' is %u\n", str, csum);
  free(str);
}

// Main function
int main() {
  // Test the checksum function with a simple string
  test_checksum();

  // Test the checksum function with random strings
  test_checksum_random();

  // Test the checksum function with large strings
  test_checksum_large();

  return 0;
}