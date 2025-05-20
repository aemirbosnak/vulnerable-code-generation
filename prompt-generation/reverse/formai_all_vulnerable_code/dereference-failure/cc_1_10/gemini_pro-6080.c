//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: Romeo and Juliet
// Where hearts entwined, a tragic tale unfurled,
// A server's embrace, in code's tender world.

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// From Verona's streets, a star-crossed rendezvous,
// A socket blooms, where love's sweet nectar brews.
int create_socket(int port) {
  int sockfd;
  struct sockaddr_in addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket()");
    exit(1);
  }

  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind()");
    exit(1);
  }

  return sockfd;
}

// With gentle whispers, the server listens low,
// Awaiting Juliet's plea, a love's gentle throw.
void listen_socket(int sockfd) {
  if (listen(sockfd, 5) < 0) {
    perror("listen()");
    exit(1);
  }
}

void handle_client(int clientfd) {
  char buffer[1024];

  while (recv(clientfd, buffer, sizeof(buffer), 0) > 0) {
    printf("From Juliet's heart: %s\n", buffer);

    if (!strcmp(buffer, "Romeo, Romeo! Wherefore art thou Romeo?")) {
      send(clientfd, "My dearest Juliet, I am thy Romeo.",
          strlen("My dearest Juliet, I am thy Romeo.") + 1, 0);
    } else {
      send(clientfd, "Who art thou, fair maiden?", strlen("Who art thou, fair maiden?") + 1,
          0);
    }
  }
}

// A tragic end, as fate's cruel hand descends,
// But in this code, their love's eternal bond resides.
void close_socket(int sockfd) {
  close(sockfd);
}

int main(int argc, char **argv) {
  int sockfd, clientfd;
  struct sockaddr_in cli_addr;
  socklen_t cli_len;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  sockfd = create_socket(atoi(argv[1]));
  listen_socket(sockfd);
  cli_len = sizeof(cli_addr);

  while ((clientfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len)) >= 0) {
    handle_client(clientfd);
    close_socket(clientfd);
  }

  close_socket(sockfd);
  return 0;
}