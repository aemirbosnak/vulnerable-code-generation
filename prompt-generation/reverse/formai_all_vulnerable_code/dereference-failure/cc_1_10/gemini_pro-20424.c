//GEMINI-pro DATASET v1.0 Category: Networking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
  char *host, *port;
  struct hostent *he;
  struct sockaddr_in sin;
  int s, n;
  char buf[1024];

  if (argc != 3) {
    fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
    exit(1);
  }

  host = argv[1];
  port = argv[2];

  if ((he = gethostbyname(host)) == NULL) {
    fprintf(stderr, "gethostbyname() failed for %s\n", host);
    exit(1);
  }

  if ((s = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    fprintf(stderr, "socket() failed\n");
    exit(1);
  }

  memset(&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(atoi(port));
  memcpy(&sin.sin_addr, he->h_addr, he->h_length);

  if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
    fprintf(stderr, "connect() failed\n");
    exit(1);
  }

  for (;;) {
    if ((n = read(s, buf, sizeof(buf))) == -1) {
      fprintf(stderr, "read() failed\n");
      exit(1);
    }

    if (n == 0) {
      break;
    }

    if (write(1, buf, n) == -1) {
      fprintf(stderr, "write() failed\n");
      exit(1);
    }
  }

  close(s);

  return 0;
}