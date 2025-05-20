//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
  // Romeo's opening gambit
  int sd = socket(AF_INET, SOCK_STREAM, 0);
  if (sd == -1)
  {
    perror("socket() failed");
    exit(1);
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(80);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
  {
    perror("bind() failed");
    exit(1);
  }

  if (listen(sd, 5) == -1)
  {
    perror("listen() failed");
    exit(1);
  }

  for (;;)
  {
    // Juliet's response
    int client_sd = accept(sd, NULL, NULL);
    if (client_sd == -1)
    {
      perror("accept() failed");
      continue;
    }

    // Romeo's sweet nothings
    char *req = malloc(1024);
    int r = read(client_sd, req, 1023);
    if (r == -1)
    {
      perror("read() failed");
      free(req);
      continue;
    }
    req[r] = '\0';

    // Juliet's reply
    char *resp = malloc(strlen("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>My heart is full of love!</h1></body></html>") + 1);
    strcpy(resp, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>My heart is full of love!</h1></body></html>");

    // Romeo's final act
    int w = write(client_sd, resp, strlen(resp));
    if (w == -1)
    {
      perror("write() failed");
      free(req);
      free(resp);
      continue;
    }

    close(client_sd);
    free(req);
    free(resp);
  }

  close(sd);
  return 0;
}