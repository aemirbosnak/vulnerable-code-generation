//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define DEFAULT_PORT 21

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
    return 1;
  }

  // Resolve hostname
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    perror("gethostbyname");
    return 1;
  }

  // Create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Connect to server
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(DEFAULT_PORT);
  addr.sin_addr = *(struct in_addr *)host->h_addr;
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send login command
  char buf[1024];
  sprintf(buf, "USER anonymous\r\n");
  send(sock, buf, strlen(buf), 0);
  recv(sock, buf, sizeof(buf), 0);

  // Send password command
  sprintf(buf, "PASS anonymous@example.com\r\n");
  send(sock, buf, strlen(buf), 0);
  recv(sock, buf, sizeof(buf), 0);

  // Send CWD command
  sprintf(buf, "CWD /pub/\r\n");
  send(sock, buf, strlen(buf), 0);
  recv(sock, buf, sizeof(buf), 0);

  // Send RETR command
  sprintf(buf, "RETR %s\r\n", argv[2]);
  send(sock, buf, strlen(buf), 0);
  recv(sock, buf, sizeof(buf), 0);

  // Open file for writing
  int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  // Receive data and write to file
  while (recv(sock, buf, sizeof(buf), 0) > 0) {
    write(fd, buf, strlen(buf));
  }

  // Close file and socket
  close(fd);
  close(sock);

  return 0;
}