//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PORTS 65536
#define MAX_HOST_LEN 256
#define MAX_PACKET_LEN 1024

struct hostent *gethostbyname(const char *name);

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <host_name>\n", argv[0]);
    return 1;
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 2;
  }

  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "Failed to resolve hostname: %s\n", argv[1]);
    close(sock);
    return 3;
  }

  struct sockaddr_in sin;
  memset(&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(80);
  inet_pton(AF_INET, host->h_addr, &sin.sin_addr);

  if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
    perror("connect");
    close(sock);
    return 4;
  }

  char packet[MAX_PACKET_LEN];
  memset(packet, 0, MAX_PACKET_LEN);
  ssize_t recv_len = recv(sock, packet, MAX_PACKET_LEN, 0);
  if (recv_len < 0) {
    perror("recv");
    close(sock);
    return 5;
  }

  char *ptr = packet;
  while (*ptr != '\0') {
    printf("%c", *ptr);
    ptr++;
  }

  close(sock);
  return 0;
}