//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

// Custom data structure to hold website and its status
typedef struct website {
  char *url;
  int status;
  time_t last_checked;
} website;

// Function to check the uptime of a given website
int check_uptime(website *site) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return -1;
  }

  // Get the IP address of the website
  struct hostent *he = gethostbyname(site->url);
  if (he == NULL) {
    perror("Error getting host address");
    return -1;
  }

  // Connect to the website
  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(80);
  serv_addr.sin_addr = *((struct in_addr *)he->h_addr);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to website");
    return -1;
  }

  // Send a HTTP request to the website
  char request[256];
  snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", site->url);

  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("Error sending request");
    return -1;
  }

  // Receive the response from the website
  char response[1024];
  int n = recv(sockfd, response, sizeof(response), 0);
  if (n < 0) {
    perror("Error receiving response");
    return -1;
  }

  // Check the status code in the response
  char *status_line = strtok(response, "\r\n");
  if (status_line == NULL) {
    printf("Error parsing response\n");
    return -1;
  }

  char *status_code = strtok(status_line, " ");
  if (status_code == NULL) {
    printf("Error parsing response\n");
    return -1;
  }

  // Update the status of the website
  site->status = atoi(status_code);

  // Close the socket
  close(sockfd);

  return 0;
}

// Function to print the status of a given website
void print_status(website *site) {
  printf("%s: ", site->url);
  switch (site->status) {
    case 200:
      printf("OK\n");
      break;
    case 404:
      printf("Not Found\n");
      break;
    case 500:
      printf("Internal Server Error\n");
      break;
    default:
      printf("Unknown status code\n");
      break;
  }
}

// Main function
int main() {
  // Create an array of websites
  website websites[] = {
    {"www.google.com", 0, 0},
    {"www.facebook.com", 0, 0},
    {"www.amazon.com", 0, 0},
    {"www.microsoft.com", 0, 0},
    {"www.apple.com", 0, 0},
  };

  // Check the uptime of each website
  for (int i = 0; i < sizeof(websites) / sizeof(website); i++) {
    if (check_uptime(&websites[i]) == 0) {
      print_status(&websites[i]);
    } else {
      printf("Error checking uptime of %s\n", websites[i].url);
    }
  }

  return 0;
}