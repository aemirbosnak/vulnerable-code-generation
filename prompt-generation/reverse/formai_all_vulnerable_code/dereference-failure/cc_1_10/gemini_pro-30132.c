//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// A humble HTTP client, crafted in the spirit of ancient times.
int main(int argc, char *argv[])
{
  // Initialize variables like a valiant knight preparing for battle.
  int sockfd, port;
  struct sockaddr_in server_addr;
  char *host, *path, *request, *response;
  size_t request_len, response_len;

  // Parse command-line arguments like a wise sage.
  if (argc != 4)
  {
    fprintf(stderr, "Usage: %s host port path\n", argv[0]);
    return EXIT_FAILURE;
  }
  host = argv[1];
  port = atoi(argv[2]);
  path = argv[3];

  // Create a socket, like a blacksmith forging a stout weapon.
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
  {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set up the server address like a navigator charting a course.
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(host);

  // Connect to the server like a valiant warrior charging into battle.
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
  {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Craft the HTTP request like a cunning bard composing a sonnet.
  request_len = (snprintf(NULL, 0,
                          "GET %s HTTP/1.1\r\n"
                          "Host: %s\r\n"
                          "Connection: close\r\n\r\n",
                          path, host) + 1);
  request = malloc(request_len);
  sprintf(request,
          "GET %s HTTP/1.1\r\n"
          "Host: %s\r\n"
          "Connection: close\r\n\r\n",
          path, host);

  // Send the request like a messenger delivering a scroll.
  if (write(sockfd, request, request_len) == -1)
  {
    perror("write");
    return EXIT_FAILURE;
  }
  free(request);

  // Receive the response like a scholar poring over ancient texts.
  response_len = 0;
  response = malloc(response_len);
  do
  {
    char buffer[1024];
    int bytes_read = read(sockfd, buffer, sizeof(buffer));

    if (bytes_read <= 0)
    {
      break;
    }

    response = realloc(response, response_len + bytes_read + 1);
    memcpy(response + response_len, buffer, bytes_read);
    response_len += bytes_read;
  } while (1);

  // Display the response like a herald announcing a tournament victory.
  printf("%s", response);
  free(response);

  // Close the socket like a seasoned warrior sheathing their sword.
  close(sockfd);

  return EXIT_SUCCESS;
}