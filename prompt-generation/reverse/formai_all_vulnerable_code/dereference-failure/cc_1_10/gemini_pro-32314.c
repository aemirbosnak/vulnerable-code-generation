//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

// Our very own custom error messages
#define HTTP_200 "HTTP/1.1 200 OK\r\n"
#define HTTP_404 "HTTP/1.1 404 Not Found\r\n"
#define HTTP_500 "HTTP/1.1 500 Internal Server Error\r\n"

// Serve up some static files
char *serve_file(char *filename) {
  // Get the file size
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    return HTTP_404; // Oops, file not found!
  }
  fseek(fp, 0, SEEK_END);
  long filesize = ftell(fp);
  rewind(fp);

  // Allocate a buffer to hold the file contents
  char *contents = malloc(filesize + 1);
  if (contents == NULL) {
    return HTTP_500; // Uh oh, out of memory!
  }

  // Read the file contents into the buffer
  fread(contents, filesize, 1, fp);
  fclose(fp);
  contents[filesize] = '\0'; // Null-terminate the string

  // Create the HTTP response header
  char *response = malloc(strlen(HTTP_200) + strlen(contents) + 1);
  if (response == NULL) {
    free(contents);
    return HTTP_500; // Oh no, more out of memory!
  }

  strcpy(response, HTTP_200);
  strcat(response, contents);

  // Free the allocated memory
  free(contents);

  return response;
}

// The main event: our web server
int main(int argc, char **argv) {
  // Check if we have the right number of arguments
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the port number from the command line
  int port = atoi(argv[1]);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket()");
    return EXIT_FAILURE;
  }

  // Set up the socket address
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(port);

  // Bind the socket to the address
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind()");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(sockfd, 5) < 0) {
    perror("listen()");
    return EXIT_FAILURE;
  }

  // Accept incoming connections
  while (1) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (client_sockfd < 0) {
      perror("accept()");
      continue;
    }

    // Read the HTTP request
    char request[1024];
    memset(request, 0, sizeof(request));
    int bytes_read = read(client_sockfd, request, sizeof(request) - 1);
    if (bytes_read < 0) {
      perror("read()");
      close(client_sockfd);
      continue;
    }

    // Parse the HTTP request
    char *filename = NULL;
    char *method = strtok(request, " ");
    if (strcmp(method, "GET") == 0) {
      filename = strtok(NULL, " ");
    } else {
      // We only support GET requests for now
      close(client_sockfd);
      continue;
    }

    if (filename == NULL) {
      // Oops, invalid request!
      close(client_sockfd);
      continue;
    }

    // Remove the leading slash from the filename
    if (filename[0] == '/') {
      filename++;
    }

    // Serve the requested file
    char *response = serve_file(filename);
    if (response == NULL) {
      // Oops, something went wrong!
      close(client_sockfd);
      continue;
    }

    // Send the HTTP response
    write(client_sockfd, response, strlen(response));

    // Free the allocated memory
    free(response);

    // Close the client socket
    close(client_sockfd);
  }

  // Close the server socket
  close(sockfd);

  return EXIT_SUCCESS;
}