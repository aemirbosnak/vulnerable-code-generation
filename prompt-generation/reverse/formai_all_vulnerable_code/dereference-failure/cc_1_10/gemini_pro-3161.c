//GEMINI-pro DATASET v1.0 Category: Networking ; Style: Claude Shannon
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

static bool verbose = false;
static int port = 0;
static const char *ip = NULL;
static const char *filename = NULL;

static void usage(const char *name) {
  printf("Usage: %s [-v] [-p port] [-i ip] filename\n", name);
  printf("\n");
  printf("Options:\n");
  printf("  -v\tEnable verbose mode.\n");
  printf("  -p port\tSet the port to connect to (default: 80).\n");
  printf("  -i ip\tSet the IP address to connect to (default: localhost).\n");
  printf("\n");
  printf("filename\tThe file to transfer.\n");
}

static int send_file(int sock, const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (!file) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while (true) {
    char buffer[1024];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
    if (bytes_read == 0) {
      printf("Sent file.\n");
      break;
    }

    int bytes_sent = send(sock, buffer, bytes_read, 0);
    if (bytes_sent < 0) {
      perror("send");
      return EXIT_FAILURE;
    }
  }

  fclose(file);
  return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-v")) {
      verbose = true;
    } else if (!strcmp(argv[i], "-p")) {
      port = atoi(argv[++i]);
    } else if (!strcmp(argv[i], "-i")) {
      ip = argv[++i];
    } else {
      filename = argv[i];
    }
  }

  if (!filename) {
    usage(argv[0]);
    return EXIT_FAILURE;
  }

  if (!port) {
    port = 80;
  }

  if (!ip) {
    ip = "localhost";
  }

  if (verbose) {
    printf("Connecting to %s:%d\n", ip, port);
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in addr = {
    .sin_family = AF_INET,
    .sin_port = htons(port),
    .sin_addr = {
      .s_addr = inet_addr(ip)
    }
  };

  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  if (verbose) {
    printf("Sending file.\n");
  }

  if (send_file(sock, filename) != EXIT_SUCCESS) {
    return EXIT_FAILURE;
  }

  close(sock);

  return EXIT_SUCCESS;
}