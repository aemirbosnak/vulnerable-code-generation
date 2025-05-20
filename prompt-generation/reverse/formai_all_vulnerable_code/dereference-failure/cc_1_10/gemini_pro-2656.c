//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DATA_SIZE 1024*1024
#define TEST_SERVER "www.speedtest.net"
#define TEST_PORT 8080

int main() {
  int sockfd, bytes_received, total_bytes = 0;
  struct sockaddr_in server_addr;
  char *buf;
  struct timeval start, end;

  // Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  // Set the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(TEST_PORT);
  if (inet_pton(AF_INET, TEST_SERVER, &server_addr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(1);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Allocate buffer
  buf = malloc(DATA_SIZE);

  // Start the timer
  gettimeofday(&start, NULL);

  // Send the data
  for (int i = 0; i < DATA_SIZE; i++) {
    buf[i] = rand() % 256;
  }
  if (send(sockfd, buf, DATA_SIZE, 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive the data
  while ((bytes_received = recv(sockfd, buf, DATA_SIZE, 0)) > 0) {
    total_bytes += bytes_received;
  }
  if (bytes_received < 0) {
    perror("recv");
    exit(1);
  }

  // Stop the timer
  gettimeofday(&end, NULL);

  // Calculate the elapsed time and the speed
  double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
  double speed = total_bytes / elapsed_time;

  // Print the results
  printf("Elapsed time: %.3f seconds\n", elapsed_time);
  printf("Total bytes received: %d\n", total_bytes);
  printf("Speed: %.2f MB/s\n", speed / 1024 / 1024);

  // Close the socket
  close(sockfd);

  // Free the buffer
  free(buf);

  return 0;
}