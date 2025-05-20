//GEMINI-pro DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>

int main() {
  // Get the current user's name
  char *username = getlogin();
  if (username == NULL) {
    perror("getlogin() failed");
    return EXIT_FAILURE;
  }

  // Get the current time
  time_t now = time(NULL);
  if (now == (time_t)-1) {
    perror("time() failed");
    return EXIT_FAILURE;
  }

  // Print a message to the user
  printf("Hello, %s!\n", username);
  printf("The current time is %s\n", ctime(&now));

  // Get the user's home directory
  struct passwd *pw = getpwnam(username);
  if (pw == NULL) {
    perror("getpwnam() failed");
    return EXIT_FAILURE;
  }

  // Print the user's home directory
  printf("Your home directory is %s\n", pw->pw_dir);

  // Change the user's current working directory to their home directory
  if (chdir(pw->pw_dir) != 0) {
    perror("chdir() failed");
    return EXIT_FAILURE;
  }

  // Print the current working directory
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) == NULL) {
    perror("getcwd() failed");
    return EXIT_FAILURE;
  }
  printf("Your current working directory is %s\n", cwd);

  // Create a new file in the user's home directory
  FILE *f = fopen("test.txt", "w");
  if (f == NULL) {
    perror("fopen() failed");
    return EXIT_FAILURE;
  }

  // Write a message to the file
  fprintf(f, "Hello, world!\n");

  // Close the file
  fclose(f);

  // Print a message to the user
  printf("File created successfully!\n");

  return EXIT_SUCCESS;
}