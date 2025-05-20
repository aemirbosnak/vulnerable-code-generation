//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: unmistakable
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define PORT 8080

int main() {
  int listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd < 0) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(listenfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    return 1;
  }

  if (listen(listenfd, 10) < 0) {
    perror("listen");
    return 1;
  }

  int clientfd;
  while ((clientfd = accept(listenfd, NULL, NULL)) >= 0) {
    char buf[1024];
    int n;
    while ((n = read(clientfd, buf, sizeof(buf))) > 0) {
      if (write(clientfd, buf, n) < 0) {
        perror("write");
        break;
      }
    }

    if (n < 0) {
      perror("read");
    }

    close(clientfd);
  }

  if (clientfd < 0 && errno != EINTR) {
    perror("accept");
  }

  close(listenfd);
  return 0;
}