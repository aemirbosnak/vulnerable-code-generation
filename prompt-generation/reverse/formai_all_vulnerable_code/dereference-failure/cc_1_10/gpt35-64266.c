//FormAI DATASET v1.0 Category: Simple Web Server ; Style: accurate
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT_NUMBER 8000
#define BUFFER_SIZE 8192

void handle_client(int sock_fd) {
   char buffer[BUFFER_SIZE] = {0};
   ssize_t message_size = recv(sock_fd, buffer, BUFFER_SIZE, 0);
   
   if (message_size == -1) {
      perror("Failed to receive message from client");
      return;
   }

   char* http_method = strtok(buffer, " ");
   char* requested_file = strtok(NULL, " ");

   if (strcmp(http_method, "GET") != 0) {
      printf("Unsupported HTTP method: %s\n", http_method);
      return;
   }

   if (strstr(requested_file, "..") != NULL) { // Prevent path traversal
      printf("Path traversal attempt: %s\n", requested_file);
      return;
   }

   FILE* requested_file_handle = fopen(requested_file, "rb"); // Open file in binary mode

   if (requested_file_handle == NULL) {
      perror("Failed to open requested file");
      return;
   }

   // Send headers
   dprintf(sock_fd, "HTTP/1.1 200 OK\r\n");
   dprintf(sock_fd, "Content-Type: text/html\r\n");
   dprintf(sock_fd, "Connection: close\r\n");
   dprintf(sock_fd, "\r\n");

   // Send file contents
   int bytes_read;
   char send_buffer[BUFFER_SIZE];
   
   while ((bytes_read = fread(send_buffer, sizeof(char), BUFFER_SIZE, requested_file_handle)) > 0) {
      if (send(sock_fd, send_buffer, bytes_read, 0) == -1) {
         perror("Failed to send file contents");
         break;
      }
   }

   fclose(requested_file_handle);
   close(sock_fd);
}

int create_socket(int port) {
   int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

   if (sock_fd == -1) {
      perror("Failed to create new socket");
      exit(EXIT_FAILURE);
   }

   struct sockaddr_in server_address = {
      .sin_family = AF_INET,
      .sin_port = htons(port),
      .sin_addr = {.s_addr = INADDR_ANY},
      .sin_zero = {0}
   };

   if (bind(sock_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
      perror("Failed to bind socket to address");
      exit(EXIT_FAILURE);
   }

   if (listen(sock_fd, SOMAXCONN) == -1) {
      perror("Failed to listen on socket");
      exit(EXIT_FAILURE);
   }

   return sock_fd;
}

int main(int argc, char** argv) {
   int sock_fd = create_socket(PORT_NUMBER);
   printf("Listening on port %d\n", PORT_NUMBER);

   while (1) {
      int client_sock_fd = accept(sock_fd, NULL, NULL);
      
      if (client_sock_fd == -1) {
         perror("Failed to accept incoming connection");
         continue;
      }

      handle_client(client_sock_fd);
   }

   close(sock_fd);
   return EXIT_SUCCESS;
}