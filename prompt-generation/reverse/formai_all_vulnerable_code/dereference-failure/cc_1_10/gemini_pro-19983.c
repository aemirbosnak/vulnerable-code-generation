//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

  // Get the website URL from the user.
  char website_url[100];
  printf("Enter the website URL to monitor: ");
  scanf("%s", website_url);

  // Parse the website URL.
  struct hostent *host = gethostbyname(website_url);
  if (host == NULL) {
    printf("Invalid website URL.\n");
    return 1;
  }

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error creating socket.\n");
    return 1;
  }

  // Connect to the website.
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);
  serv_addr.sin_port = htons(80);
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error connecting to website.\n");
    return 1;
  }

  // Send an HTTP request to the website.
  char request[256];
  sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", website_url);
  if (send(sockfd, request, strlen(request), 0) < 0) {
    printf("Error sending HTTP request.\n");
    return 1;
  }

  // Receive the HTTP response from the website.
  char response[1024];
  int n = recv(sockfd, response, sizeof(response), 0);
  if (n < 0) {
    printf("Error receiving HTTP response.\n");
    return 1;
  }

  // Check if the website is up.
  if (strstr(response, "HTTP/1.1 200 OK") != NULL) {
    printf("Website is up.\n");
  } else {
    printf("Website is down.\n");
  }

  // Close the socket.
  close(sockfd);

  return 0;
}