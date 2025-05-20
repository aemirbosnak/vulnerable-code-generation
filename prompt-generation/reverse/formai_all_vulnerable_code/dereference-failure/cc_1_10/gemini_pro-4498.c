//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <server_address>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  struct hostent* host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
    exit(EXIT_FAILURE);
  }
  memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);

  if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send a request to the server
  const char* request = "GET / HTTP/1.1\r\nHost: "
                        "example.com\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response from the server
  char buf[BUF_SIZE];
  int bytes_received = 0;
  struct timeval start_time, end_time;
  gettimeofday(&start_time, NULL);
  while ((bytes_received = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
    gettimeofday(&end_time, NULL);
  }
  if (bytes_received == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Calculate the speed
  double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
  double speed = bytes_received / elapsed_time;

  // Print the speed
  printf("Speed: %.2f KB/s\n", speed / 1024);

  // Clean up
  close(sockfd);

  return EXIT_SUCCESS;
}