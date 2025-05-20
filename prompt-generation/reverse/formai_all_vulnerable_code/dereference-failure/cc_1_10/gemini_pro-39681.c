//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define DEFAULT_PORT 80
#define DEFAULT_TIMEOUT 5

// Function to get the IP address of a domain name
char *get_ip_address(char *domain_name) {
  struct hostent *host;
  host = gethostbyname(domain_name);
  if (host == NULL) {
    return NULL;
  }
  return inet_ntoa(*((struct in_addr *)host->h_addr));
}

// Function to check the uptime of a website
int check_uptime(char *domain_name, int port, int timeout) {
  int sockfd;
  struct sockaddr_in servaddr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    return -1;
  }

  // Set the socket timeout
  struct timeval tv;
  tv.tv_sec = timeout;
  tv.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1) {
    return -1;
  }

  // Get the IP address of the domain name
  char *ip_address = get_ip_address(domain_name);
  if (ip_address == NULL) {
    return -1;
  }

  // Set the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  if (inet_aton(ip_address, &servaddr.sin_addr) == 0) {
    return -1;
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    return -1;
  }

  // Send a request to the server
  char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) == -1) {
    return -1;
  }

  // Receive a response from the server
  char response[1024];
  int n = recv(sockfd, response, sizeof(response), 0);
  if (n == -1) {
    return -1;
  }

  // Close the socket
  close(sockfd);

  // Check the response code
  char *status_code = strtok(response, " ");
  if (strcmp(status_code, "200") != 0) {
    return -1;
  }

  return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <domain name> [port] [timeout]\n", argv[0]);
    return 1;
  }

  char *domain_name = argv[1];
  int port = DEFAULT_PORT;
  if (argc >= 3) {
    port = atoi(argv[2]);
  }
  int timeout = DEFAULT_TIMEOUT;
  if (argc >= 4) {
    timeout = atoi(argv[3]);
  }

  int uptime = check_uptime(domain_name, port, timeout);
  if (uptime == -1) {
    fprintf(stderr, "Error checking uptime of %s\n", domain_name);
    return 1;
  }

  if (uptime == 0) {
    printf("%s is up\n", domain_name);
  } else {
    printf("%s is down\n", domain_name);
  }

  return 0;
}