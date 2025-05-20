//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_HOST "speedtest.googlefiber.net"
#define SERVER_PORT 8080
#define BUF_SIZE 1024

int main() {
  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Resolve the server hostname
  struct hostent *host = gethostbyname(SERVER_HOST);
  if (host == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Set up the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

  // Connect to the server
  if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send a request to the server
  char request[] = "GET /speedtest.txt HTTP/1.1\r\nHost: speedtest.googlefiber.net\r\n\r\n";
  if (send(sock, request, strlen(request), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Read the response from the server
  char buf[BUF_SIZE];
  int bytes_read = recv(sock, buf, BUF_SIZE, 0);
  if (bytes_read < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Parse the response from the server
  char *start_ptr = strstr(buf, "Content-Length: ");
  if (start_ptr == NULL) {
    fprintf(stderr, "Could not find Content-Length header in response\n");
    return EXIT_FAILURE;
  }

  char *end_ptr = strstr(start_ptr, "\r\n");
  if (end_ptr == NULL) {
    fprintf(stderr, "Could not find end of Content-Length header in response\n");
    return EXIT_FAILURE;
  }

  *end_ptr = '\0';
  int content_length = atoi(start_ptr + 15);

  // Download the file
  int total_bytes_downloaded = 0;
  struct timeval start_time, end_time;
  gettimeofday(&start_time, NULL);
  while (total_bytes_downloaded < content_length) {
    bytes_read = recv(sock, buf, BUF_SIZE, 0);
    if (bytes_read < 0) {
      perror("recv");
      return EXIT_FAILURE;
    }
    total_bytes_downloaded += bytes_read;
  }
  gettimeofday(&end_time, NULL);

  // Calculate the download speed
  double time_elapsed = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
  double download_speed = total_bytes_downloaded / time_elapsed / 1024.0 / 1024.0;

  // Print the download speed
  printf("Download speed: %.2f MB/s\n", download_speed);

  // Close the socket
  close(sock);

  return EXIT_SUCCESS;
}