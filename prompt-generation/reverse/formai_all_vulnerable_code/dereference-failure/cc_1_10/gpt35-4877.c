//FormAI DATASET v1.0 Category: Simple Web Server ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define BUFSIZE 1024
#define PORT 8080

void serve_client(int client_socket) {
  char buf[BUFSIZE];
  char file_buf[BUFSIZE];
  int file_len, bytes_sent;
  FILE *fp;

  recv(client_socket, buf, BUFSIZE, 0);
  
  char *file_name = strtok(buf, " ");
  file_name = strtok(NULL, " ");
  
  if (strcmp(file_name, "/") == 0) {
    file_name = "/index.html";
  }

  file_name++;

  fp = fopen(file_name, "r");

  if (fp == NULL) {
    char *err_msg = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>";
    send(client_socket, err_msg, strlen(err_msg), 0);
    close(client_socket);
    return;
  }
  
  fseek(fp, 0L, SEEK_END);
  file_len = ftell(fp);
  fseek(fp, 0L, SEEK_SET);

  char *ok_msg = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  send(client_socket, ok_msg, strlen(ok_msg), 0);

  while (fgets(file_buf, BUFSIZE, fp) != NULL) {
    send(client_socket, file_buf, strlen(file_buf), 0);
  }

  fclose(fp);
  close(client_socket);
}

int main(int argc, char *argv[]) {
  int socket_desc, client_socket, c, read_size;
  struct sockaddr_in server, client;
  
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    printf("Error creating socket\n");
    return 1;
  }
  
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(PORT);
  
  if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Error binding socket\n");
    return 1;
  }
  
  listen(socket_desc, 3);

  printf("Server listening on http://localhost:%d/\n", PORT);
  printf("Press Ctrl + C to exit\n");

  while (1) {
    c = sizeof(struct sockaddr_in);
    client_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);

    if (client_socket < 0) {
      printf("Error accepting connection\n");
      continue;
    }

    serve_client(client_socket);
  }

  return 0;
}