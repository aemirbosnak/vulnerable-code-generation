//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define LIGHT_ON "1"
#define LIGHT_OFF "0"
#define LIGHT_MAX 99

struct light {
  int fd;
  char *name;
  char *state;
};

struct light lights[LIGHT_MAX];

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <light name> [on|off]\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *light_name = argv[1];
  char *light_state = argv[2];

  int i;
  for (i = 0; i < LIGHT_MAX; i++) {
    if (strcmp(lights[i].name, light_name) == 0) {
      break;
    }
  }

  if (i == LIGHT_MAX) {
    fprintf(stderr, "Light '%s' not found.\n", light_name);
    return EXIT_FAILURE;
  }

  if (strcmp(light_state, LIGHT_ON) == 0) {
    lights[i].state = LIGHT_ON;
  } else if (strcmp(light_state, LIGHT_OFF) == 0) {
    lights[i].state = LIGHT_OFF;
  } else {
    fprintf(stderr, "Invalid light state '%s'.\n", light_state);
    return EXIT_FAILURE;
  }

  if (write(lights[i].fd, lights[i].state, strlen(lights[i].state)) == -1) {
    perror("write");
    return EXIT_FAILURE;
  }

  printf("Light '%s' is now '%s'.\n", light_name, lights[i].state);

  return EXIT_SUCCESS;
}