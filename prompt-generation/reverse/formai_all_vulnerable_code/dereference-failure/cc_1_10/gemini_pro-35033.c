//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>

// Return the next line from the given socket connection.
int readLine(int sock, char *buf, int size) {
  int n = 0;
  while (n < size - 1) {
    int r = recv(sock, buf + n, 1, 0);
    if (r == -1) {
      return -1;
    }
    if (r == 0) {
      return n;
    }
    if (buf[n] == '\n') {
      buf[n] = '\0';
      return n;
    }
    n++;
  }
  return n;
}

// Send the given command to the server and return the response.
int sendCommand(int sock, const char *cmd) {
  int n = strlen(cmd);
  if (send(sock, cmd, n, 0) != n) {
    return -1;
  }
  return readLine(sock, cmd, n);
}

// Connect to the given POP3 server and return the socket connection.
int connectToPOP3(const char *hostname, const char *port) {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    return -1;
  }
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    close(sock);
    return -1;
  }
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(port));
  addr.sin_addr = *(struct in_addr *)host->h_addr;
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    close(sock);
    return -1;
  }
  return sock;
}

// POP3 client main function.
int main(int argc, char **argv) {
  int sock = connectToPOP3("pop.example.com", "110");
  if (sock == -1) {
    perror("connect");
    return 1;
  }

  char buf[1024];
  if (readLine(sock, buf, sizeof(buf)) == -1) {
    perror("readLine");
    close(sock);
    return 1;
  }
  printf("%s", buf);

  if (sendCommand(sock, "USER username\n") == -1) {
    perror("sendCommand");
    close(sock);
    return 1;
  }
  printf("%s", buf);

  if (sendCommand(sock, "PASS password\n") == -1) {
    perror("sendCommand");
    close(sock);
    return 1;
  }
  printf("%s", buf);

  if (sendCommand(sock, "STAT\n") == -1) {
    perror("sendCommand");
    close(sock);
    return 1;
  }
  printf("%s", buf);

  if (sendCommand(sock, "LIST\n") == -1) {
    perror("sendCommand");
    close(sock);
    return 1;
  }
  printf("%s", buf);

  if (sendCommand(sock, "RETR 1\n") == -1) {
    perror("sendCommand");
    close(sock);
    return 1;
  }
  printf("%s", buf);

  if (sendCommand(sock, "QUIT\n") == -1) {
    perror("sendCommand");
    close(sock);
    return 1;
  }
  printf("%s", buf);

  close(sock);
  return 0;
}