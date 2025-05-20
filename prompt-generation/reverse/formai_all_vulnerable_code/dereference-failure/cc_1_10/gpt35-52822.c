//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Oops! You forgot to enter a URL. Try again with a URL like \"http://www.google.com\"\n");
    exit(1);
  }

  char *url = argv[1];
  char *host = url + 7; // skip "http://" prefix
  char *path = strchr(host, '/');
  if (path == NULL) {
    path = "/";
  } else {
    *path = '\0';
    path++;
  }

  printf("Welcome to the HTTP client! We're going to fetch data from %s.\n", url);

  // First, we need to look up the IP address of the server
  struct hostent *server = gethostbyname(host);
  if (server == NULL) {
    printf("Uh oh! Couldn't resolve host %s. Are you sure it's spelled correctly?\n", host);
    exit(1);
  }

  // Now, let's connect to the server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Oops! Failed to create a socket. Is your network connection okay?\n");
    exit(1);
  }

  struct sockaddr_in serveraddr;
  bzero((char *)&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
  serveraddr.sin_port = htons(80);

  if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
    printf("Drat! Failed to connect to host %s. Maybe it's down or something?\n", host);
    exit(1);
  }

  // Okay, we're connected. Let's send an HTTP request to the server
  char request[BUFSIZE];
  sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

  printf("Sending request to server:\n%s\n", request);

  if (write(sockfd, request, strlen(request)) < 0) {
    printf("Argh! Failed to send request to server. Did it disconnect or something?\n");
    exit(1);
  }

  // Now, let's read the response from the server
  char response[BUFSIZE];
  bzero(response, BUFSIZE);

  int bytes_read = read(sockfd, response, BUFSIZE);
  if (bytes_read < 0) {
    printf("Grr! Failed to read response from server. Maybe it's not responding?\n");
    exit(1);
  }

  printf("Response from server:\n%s\n", response);

  printf("All done! Thanks for using the HTTP client. Come again soon!\n");

  return 0;
}