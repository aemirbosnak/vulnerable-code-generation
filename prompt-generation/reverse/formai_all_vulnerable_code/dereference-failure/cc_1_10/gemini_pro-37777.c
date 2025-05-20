//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

#define BUF_SIZE 4096
#define MAX_URLS 100

// Forward declarations
int get_socket(char *host, int port);
int send_request(int sockfd, char *url);
int recv_response(int sockfd);
void handle_signal(int signum);

// Global variables
int urls[MAX_URLS];
int num_urls = 0;

int main(int argc, char *argv[]) {
  // Set up signal handler
  signal(SIGINT, handle_signal);

  // Parse command-line arguments
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <url> [<url> ...]\n", argv[0]);
    return EXIT_FAILURE;
  }
  for (int i = 1; i < argc; i++) {
    urls[num_urls++] = i;
  }

  // Loop through URLs
  while (1) {
    for (int i = 0; i < num_urls; i++) {
      // Get socket
      int sockfd = get_socket(argv[urls[i]], 80);
      if (sockfd == -1) {
        fprintf(stderr, "Error getting socket for %s: %s\n", argv[urls[i]], strerror(errno));
        continue;
      }

      // Send request
      int ret = send_request(sockfd, argv[urls[i]]);
      if (ret == -1) {
        fprintf(stderr, "Error sending request for %s: %s\n", argv[urls[i]], strerror(errno));
        close(sockfd);
        continue;
      }

      // Receive response
      ret = recv_response(sockfd);
      if (ret == -1) {
        fprintf(stderr, "Error receiving response for %s: %s\n", argv[urls[i]], strerror(errno));
        close(sockfd);
        continue;
      }

      // Close socket
      close(sockfd);
    }
  }

  return EXIT_SUCCESS;
}

int get_socket(char *host, int port) {
  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    return -1;
  }

  // Get host IP address
  struct hostent *hostent = gethostbyname(host);
  if (hostent == NULL) {
    close(sockfd);
    return -1;
  }

  // Set up server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  memcpy(&server_addr.sin_addr, hostent->h_addr_list[0], hostent->h_length);

  // Connect to server
  int ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (ret == -1) {
    close(sockfd);
    return -1;
  }

  return sockfd;
}

int send_request(int sockfd, char *url) {
  // Create request
  char request[BUF_SIZE];
  snprintf(request, BUF_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", url, url);

  // Send request
  int ret = send(sockfd, request, strlen(request), 0);
  if (ret == -1) {
    return -1;
  }

  return 0;
}

int recv_response(int sockfd) {
  // Receive response
  char response[BUF_SIZE];
  int ret = recv(sockfd, response, BUF_SIZE, 0);
  if (ret == -1) {
    return -1;
  }

  // Check response code
  if (strncmp(response, "HTTP/1.1 200 OK", 15) != 0) {
    fprintf(stderr, "Error: HTTP response code %s\n", response);
    return -1;
  }

  return 0;
}

void handle_signal(int signum) {
  // Exit program
  exit(EXIT_SUCCESS);
}