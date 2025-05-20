//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_DEVICES 16
#define MAX_DEVICE_NAME_LENGTH 32
#define MAX_COMMAND_LENGTH 16

typedef struct device {
  char name[MAX_DEVICE_NAME_LENGTH];
  int socket_fd;
} device_t;

typedef struct command {
  char name[MAX_COMMAND_LENGTH];
  void (*function)(device_t *device);
} command_t;

void turn_on(device_t *device) {
  char message[] = "on";
  send(device->socket_fd, message, sizeof(message), 0);
}

void turn_off(device_t *device) {
  char message[] = "off";
  send(device->socket_fd, message, sizeof(message), 0);
}

void toggle(device_t *device) {
  char message[] = "toggle";
  send(device->socket_fd, message, sizeof(message), 0);
}

void get_status(device_t *device) {
  char message[] = "status";
  send(device->socket_fd, message, sizeof(message), 0);
  char response[16];
  recv(device->socket_fd, response, sizeof(response), 0);
  printf("%s: %s\n", device->name, response);
}

command_t commands[] = {
  {"on", turn_on},
  {"off", turn_off},
  {"toggle", toggle},
  {"status", get_status},
};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage: %s <device ip> [<device ip> ...]\n", argv[0]);
    return EXIT_FAILURE;
  }

  int num_devices = argc - 1;
  device_t devices[MAX_DEVICES];

  for (int i = 0; i < num_devices; i++) {
    devices[i].socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (devices[i].socket_fd == -1) {
      perror("socket");
      return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr(argv[i + 1]);

    if (connect(devices[i].socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
      perror("connect");
      return EXIT_FAILURE;
    }

    strcpy(devices[i].name, argv[i + 1]);
  }

  while (true) {
    char line[1024];
    printf("> ");
    fgets(line, sizeof(line), stdin);
    if (line[0] == '\n') {
      continue;
    }

    char *command_name = strtok(line, " ");
    char *device_name = strtok(NULL, " ");
    char *argument = strtok(NULL, " ");

    if (command_name == NULL || device_name == NULL) {
      printf("invalid command\n");
      continue;
    }

    bool found_device = false;
    for (int i = 0; i < num_devices; i++) {
      if (strcmp(devices[i].name, device_name) == 0) {
        found_device = true;
        for (int j = 0; j < sizeof(commands) / sizeof(command_t); j++) {
          if (strcmp(commands[j].name, command_name) == 0) {
            commands[j].function(&devices[i]);
            break;
          }
        }
        break;
      }
    }

    if (!found_device) {
      printf("device not found\n");
    }
  }

  for (int i = 0; i < num_devices; i++) {
    close(devices[i].socket_fd);
  }

  return EXIT_SUCCESS;
}