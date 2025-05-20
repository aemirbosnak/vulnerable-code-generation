//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s [port]\n", argv[0]);
    return -1;
  }

  int port = atoi(argv[1]);

  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);
  server_address.sin_addr.s_addr = INADDR_ANY;

  bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

  listen(server_socket, 5);

  char cwd[256];
  getcwd(cwd, sizeof(cwd));

  while (1) {
    int client_socket = accept(server_socket, NULL, NULL);

    char buffer[1024];
    recv(client_socket, buffer, sizeof(buffer), 0);

    char *request_line = strtok(buffer, "\r\n");
    char *method = strtok(request_line, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, " ");

    printf("Received request: %s\n", request_line);

    if (strcmp(method, "GET") == 0) {
      char *file_path = malloc(strlen(cwd) + strlen(path) + 1);
      strcpy(file_path, cwd);
      strcat(file_path, path);

      int file_fd = open(file_path, O_RDONLY);

      if (file_fd < 0) {
        char *error_response = "HTTP/1.1 404 Not Found\r\n\r\n";
        send(client_socket, error_response, strlen(error_response), 0);
      } else {
        char *ok_response = "HTTP/1.1 200 OK\r\n\r\n";
        send(client_socket, ok_response, strlen(ok_response), 0);

        char *file_content = malloc(1024);
        while (read(file_fd, file_content, 1024) > 0) {
          send(client_socket, file_content, 1024, 0);
        }
        close(file_fd);
      }
      free(file_path);
    } else if (strcmp(method, "POST") == 0) {
      char *post_data = strtok(buffer, "\r\n\r\n");

      printf("Received POST data: %s\n", post_data);

      char *ok_response = "HTTP/1.1 200 OK\r\n\r\n";
      send(client_socket, ok_response, strlen(ok_response), 0);

      send(client_socket, post_data, strlen(post_data), 0);
    } else {
      char *error_response = "HTTP/1.1 501 Not Implemented\r\n\r\n";
      send(client_socket, error_response, strlen(error_response), 0);
    }

    close(client_socket);
  }

  close(server_socket);

  return 0;
}