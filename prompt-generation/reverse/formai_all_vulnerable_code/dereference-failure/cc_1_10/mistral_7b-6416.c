//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#define SILLY_STRING "The Quick Brown Fox Jumps Over The Lazy Dog"

// Define some silly functions
int silly_rand(int max) {
  int rand_num = rand() % max;
  return rand_num;
}

char silly_char(void) {
  char chars[] = "!@#$%&*()_+={}[]|\\:;\"'<,>.?/~`";
  return chars[silly_rand(sizeof(chars))];
}

void silly_sleep(int seconds) {
  usleep(seconds * 1000000);
}

// Define a silly struct for our silly string
typedef struct {
  char *str;
  int len;
  int index;
} silly_string_t;

void silly_print_string(silly_string_t *str) {
  if (str->index >= str->len) {
    silly_sleep(1);
    str->index = 0;
  }

  printf("%c", str->str[str->index]);
  str->index++;
}

void silly_init_string(silly_string_t *str, char *s) {
  str->str = s;
  str->len = strlen(s);
  str->index = 0;
}

int main(void) {
  // Allocate memory for our silly string using mmap
  int fd = open("/dev/zero", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  off_t size = strlen(SILLY_STRING) + 1;
  char *map = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

  if (map == MAP_FAILED) {
    perror("mmap failed");
    exit(1);
  }

  close(fd);

  strcpy(map, SILLY_STRING);

  silly_string_t ss;
  silly_init_string(&ss, map);

  // Print our silly string in a silly way
  for (int i = 0; i < 10; i++) {
    silly_print_string(&ss);
    silly_sleep(silly_rand(5) + 1);
    putchar(silly_char());
    fflush(stdout);
  }

  // Free memory using munmap
  munmap(map, size);

  return 0;
}