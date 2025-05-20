//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFSIZE 4096

int main(int argc, char **argv) {
  int sfd, cfd;
  struct sockaddr_in saddr, caddr;
  char buf[BUFSIZE];
  int n, i;

  // Parse command-line arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create server socket
  sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set server address and port
  memset(&saddr, 0, sizeof(saddr));
  saddr.sin_family = AF_INET;
  saddr.sin_port = htons(atoi(argv[1]));
  saddr.sin_addr.s_addr = INADDR_ANY;

  // Bind server socket to address and port
  if (bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(sfd, 5) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // Accept incoming connections and handle requests
  while (1) {
    // Accept incoming connection
    cfd = accept(sfd, (struct sockaddr *)&caddr, (socklen_t *)&i);
    if (cfd < 0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    // Read request from client
    n = read(cfd, buf, BUFSIZE);
    if (n < 0) {
      perror("read");
      exit(EXIT_FAILURE);
    }

    // Process request and generate response
    buf[n] = '\0';  // Null-terminate the request
    char *method = strtok(buf, " ");
    char *uri = strtok(NULL, " ");
    // Assuming only GET requests are supported
    if (strcmp(method, "GET") == 0) {
      char *html = "<html><head><title>Hello World</title></head><body><h1>Hello World!</h1></body></html>";
      snprintf(buf, BUFSIZE, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\nContent-Type: text/html\r\n\r\n%s", strlen(html), html);
    } else {
      // Handle other request methods (e.g., POST)
    }

    // Send response to client
    n = write(cfd, buf, strlen(buf));
    if (n < 0) {
      perror("write");
      exit(EXIT_FAILURE);
    }

    // Close client connection
    close(cfd);
  }

  // Close server socket
  close(sfd);

  return EXIT_SUCCESS;
}