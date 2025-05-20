//Falcon-180B DATASET v1.0 Category: Networking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  int sock;
  struct addrinfo hints, *servinfo, *p;
  char host[NI_MAXHOST];
  char service[NI_MAXSERV];
  int rv;

  if (argc!= 3) {
    fprintf(stderr, "Usage: %s host port\n", argv[0]);
    exit(1);
  }

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  rv = getaddrinfo(argv[1], argv[2], &hints, &servinfo);
  if (rv!= 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    exit(1);
  }

  for (p = servinfo; p!= NULL; p = p->ai_next) {
    if (p->ai_family == AF_INET) {
      inet_ntop(AF_INET, &((struct sockaddr_in *)p->ai_addr)->sin_addr, host, NI_MAXHOST);
      inet_ntop(AF_INET, &((struct sockaddr_in *)p->ai_addr)->sin_port, service, NI_MAXSERV);
    } else if (p->ai_family == AF_INET6) {
      inet_ntop(AF_INET6, &((struct sockaddr_in6 *)p->ai_addr)->sin6_addr, host, NI_MAXHOST);
      inet_ntop(AF_INET6, &((struct sockaddr_in6 *)p->ai_addr)->sin6_port, service, NI_MAXSERV);
    } else {
      fprintf(stderr, "Unknown address family\n");
      exit(1);
    }

    printf("host: %s\n", host);
    printf("port: %s\n", service);

    sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
    if (sock == -1) {
      perror("socket");
      exit(1);
    }

    if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
      close(sock);
      perror("connect");
      continue;
    }

    break;
  }

  freeaddrinfo(servinfo);

  char buffer[1024];
  while (1) {
    bzero(buffer, 1024);
    int bytes_read = read(sock, buffer, 1024);
    if (bytes_read <= 0) {
      printf("Error reading\n");
      break;
    }
    printf("Received: %s", buffer);
  }

  close(sock);

  return 0;
}