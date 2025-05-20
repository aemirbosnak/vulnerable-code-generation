//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024 * 1024
#define MAX_DOWNLOAD_SIZE 10 * 1024 * 1024

struct timeval start_time, end_time;

void print_usage() {
  printf("Usage: speedtest <server>\n");
  printf("Where <server> is the hostname or IP address of the speed test server.\n");
}

int main(int argc, char **argv) {
  if (argc < 2) {
    print_usage();
    return 1;
  }

  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "Error: could not resolve hostname %s\n", argv[1]);
    return 1;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error: could not create socket\n");
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  server_addr.sin_addr = *((struct in_addr *)host->h_addr);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    fprintf(stderr, "Error: could not connect to server\n");
    return 1;
  }

  // Send the HTTP request to the server
  char request[] = "GET /speedtest.php HTTP/1.1\r\nHost: "
                   "speedtest.net\r\nConnection: close\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) < 0) {
    fprintf(stderr, "Error: could not send HTTP request\n");
    return 1;
  }

  // Start the timer
  gettimeofday(&start_time, NULL);

  // Receive the response from the server
  char buffer[MAX_BUFFER_SIZE];
  int total_bytes_received = 0;
  while (total_bytes_received < MAX_DOWNLOAD_SIZE) {
    int bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received < 0) {
      fprintf(stderr, "Error: could not receive data from server\n");
      return 1;
    }
    total_bytes_received += bytes_received;
  }

  // Stop the timer
  gettimeofday(&end_time, NULL);

  // Calculate the download speed
  double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1e6;
  double download_speed = (double)total_bytes_received / elapsed_time;

  // Print the results
  printf("Download speed: %.2f Mbps\n", download_speed / 1024 / 1024);

  // Close the socket
  close(sockfd);

  return 0;
}