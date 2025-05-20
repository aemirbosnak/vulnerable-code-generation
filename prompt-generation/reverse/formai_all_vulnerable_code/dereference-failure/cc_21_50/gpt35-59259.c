//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFERSIZE 4096

int main(int argc, char* argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <listen port> <destination host> <destination port>\n", argv[0]);
    return 1;
  }

  int listen_port = atoi(argv[1]);
  char* dest_host = argv[2];
  int dest_port = atoi(argv[3]);

  int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_fd == -1) {
    fprintf(stderr, "Error creating listen socket: %s\n", strerror(errno));
    return 1;
  }

  int optval = 1;
  if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
    fprintf(stderr, "Error setting SO_REUSEADDR on listen socket: %s\n", strerror(errno));
    return 1;
  }

  struct sockaddr_in listen_addr = {
    .sin_family = AF_INET,
    .sin_addr.s_addr = INADDR_ANY,
    .sin_port = htons(listen_port)
  };
  if (bind(listen_fd, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) == -1) {
    fprintf(stderr, "Error binding listen socket: %s\n", strerror(errno));
    return 1;
  }

  if (listen(listen_fd, 10) == -1) {
    fprintf(stderr, "Error listening on listen socket: %s\n", strerror(errno));
    return 1;
  }

  printf("Listening on port %d\n", listen_port);

  while (1) {
    struct sockaddr_in client_addr;
    socklen_t client_addrlen = sizeof(client_addr);
    int client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_addrlen);
    if (client_fd == -1) {
      fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
      continue;
    }

    printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    int dest_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (dest_fd == -1) {
      fprintf(stderr, "Error creating destination socket: %s\n", strerror(errno));
      close(client_fd);
      continue;
    }

    struct sockaddr_in dest_addr = {
      .sin_family = AF_INET,
      .sin_port = htons(dest_port)
    };
    if (inet_pton(AF_INET, dest_host, &dest_addr.sin_addr) == 0) {
      fprintf(stderr, "Error converting destination address: %s\n", strerror(errno));
      close(client_fd);
      close(dest_fd);
      continue;
    }

    if (connect(dest_fd, (struct sockaddr*)&dest_addr, sizeof(dest_addr)) == -1) {
      fprintf(stderr, "Error connecting to destination: %s\n", strerror(errno));
      close(client_fd);
      close(dest_fd);
      continue;
    }

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(client_fd, &readfds);
    FD_SET(dest_fd, &readfds);

    while (1) {
      int max_fd = client_fd > dest_fd ? client_fd : dest_fd;
      if (select(max_fd+1, &readfds, NULL, NULL, NULL) == -1) {
        fprintf(stderr, "Error waiting for data: %s\n", strerror(errno));
        break;
      }

      char client_buffer[BUFFERSIZE];
      if (FD_ISSET(client_fd, &readfds)) {
        ssize_t nbytes = recv(client_fd, client_buffer, BUFFERSIZE, 0);
        if (nbytes == -1) {
          fprintf(stderr, "Error reading from client: %s\n", strerror(errno));
          break;
        } else if (nbytes == 0) {
          break;
        }

        printf("Received %zd bytes from client\n", nbytes);

        ssize_t sent_bytes = send(dest_fd, client_buffer, nbytes, 0);
        if (sent_bytes == -1) {
          fprintf(stderr, "Error sending to destination: %s\n", strerror(errno));
          break;
        } else if (sent_bytes != nbytes) {
          fprintf(stderr, "Sent %zd bytes but expected to send %zd\n", sent_bytes, nbytes);
          break;
        }

        printf("Sent %zd bytes to destination\n", sent_bytes);
      }

      char dest_buffer[BUFFERSIZE];
      if (FD_ISSET(dest_fd, &readfds)) {
        ssize_t nbytes = recv(dest_fd, dest_buffer, BUFFERSIZE, 0);
        if (nbytes == -1) {
          fprintf(stderr, "Error reading from destination: %s\n", strerror(errno));
          break;
        } else if (nbytes == 0) {
          break;
        }

        printf("Received %zd bytes from destination\n", nbytes);

        ssize_t sent_bytes = send(client_fd, dest_buffer, nbytes, 0);
        if (sent_bytes == -1) {
          fprintf(stderr, "Error sending to client: %s\n", strerror(errno));
          break;
        } else if (sent_bytes != nbytes) {
          fprintf(stderr, "Sent %zd bytes but expected to send %zd\n", sent_bytes, nbytes);
          break;
        }

        printf("Sent %zd bytes to client\n", sent_bytes);
      }
    }

    close(client_fd);
    close(dest_fd);
  }

  return 0;
}