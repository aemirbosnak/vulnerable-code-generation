//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#define BUFSZ 1024
#define NUM_LOOPS 10

int main(void) {
  // Initialize random number generator.
  srand(time(NULL));

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the server.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  char *host = "example.com";
  struct hostent *host_info = gethostbyname(host);
  if (host_info == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }
  memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Test the speed.
  int i;
  char buf[BUFSZ];
  double start, end;
  double total_time = 0.0;
  double total_bytes = 0.0;
  for (i = 0; i < NUM_LOOPS; i++) {
    start = time(NULL);
    if (write(sockfd, buf, BUFSZ) == -1) {
      perror("write");
      return EXIT_FAILURE;
    }
    if (read(sockfd, buf, BUFSZ) == -1) {
      perror("read");
      return EXIT_FAILURE;
    }
    end = time(NULL);
    total_time += end - start;
    total_bytes += BUFSZ;
  }

  // Calculate the speed.
  double speed = total_bytes / total_time;

  // Print the speed.
  printf("Speed: %.2f MB/s\n", speed / 1024.0 / 1024.0);

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}