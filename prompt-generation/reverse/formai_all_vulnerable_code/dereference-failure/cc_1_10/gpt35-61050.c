//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
  int sock;
  struct sockaddr_in serv_addr;
  char message[1024];

  if (argc != 3)
  {
     printf("Usage: %s <IP> <PORT>\n", argv[0]);
     exit(1);
  }

  sock = socket(PF_INET, SOCK_STREAM, 0);
  if (sock == -1)
  {
     error_handling("socket() error");
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_addr.sin_port = htons(atoi(argv[2]));

  if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
  {
     error_handling("connect() error!");
  }

  printf("Connected to server\n");

  sprintf(message, "GET / HTTP/1.1\r\n\r\n");

  if (send(sock, message, strlen(message), 0) == -1)
  {
    error_handling("send() error");
  }

  char buffer[1024];
  int bytesRead = 0;

  while ((bytesRead = read(sock, buffer, sizeof(buffer))) > 0)
  {
    printf("%.*s", bytesRead, buffer);
  }

  close(sock);
  return 0;
}

void error_handling(char *message)
{
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}