//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of connections
#define MAX_CONNECTIONS 5
// Define the maximum buffer size for requests
#define MAX_BUFFER 4096
// Define the web server's listening port
#define PORT 8080

//The main web server function
int main(int argc, char *argv[])
{
   //Create a socket for the web server
   int server_socket = socket(PF_INET, SOCK_STREAM, 0);
   if (server_socket == -1) {
      perror("Server socket creation failed");
      exit(1);
   }

   //Set the server socket to be reusable
   int optval = 1;
   setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

   //Bind the server socket to the listening port
   struct sockaddr_in server_address;
   memset(&server_address, 0, sizeof(server_address));
   server_address.sin_family = AF_INET;
   server_address.sin_port = htons(PORT);
   server_address.sin_addr.s_addr = INADDR_ANY;
   if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
      perror("Bind failed");
      close(server_socket);
      exit(1);
   }

   //Listen for incoming connections on the server socket
   if (listen(server_socket, MAX_CONNECTIONS) == -1) {
      perror("Listen failed");
      close(server_socket);
      exit(1);
   }

   printf("Web server listening on port %d\n", PORT);

   //The main loop of the web server
   while (1) {
      //Accept an incoming connection
      struct sockaddr_in client_address;
      socklen_t client_address_len = sizeof(client_address);
      int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
      if (client_socket == -1) {
         perror("Accept failed");
         continue;
      }

      //Log the client connection
      printf("Client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

      //Read the request from the client
      char buffer[MAX_BUFFER];
      int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
      if (bytes_received == -1) {
         perror("Read failed");
         close(client_socket);
         continue;
      }
      buffer[bytes_received] = '\0';

      //Parse the request
      char *request_line = strtok(buffer, "\r\n");
      char *method = strtok(request_line, " ");
      char *resource = strtok(NULL, " ");
      char *http_version = strtok(NULL, " ");

      //Check if the request is valid
      if (strcmp(method, "GET") != 0) {
         //Send a 405 Method Not Allowed response
         char *response_405 = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
         send(client_socket, response_405, strlen(response_405), 0);
         close(client_socket);
         continue;
      }

      //Check if the resource exists
      FILE *file = fopen(resource, "r");
      if (file == NULL) {
         //Send a 404 Not Found response
         char *response_404 = "HTTP/1.1 404 Not Found\r\n\r\n";
         send(client_socket, response_404, strlen(response_404), 0);
         close(client_socket);
         continue;
      }

      //Read the file contents
      char file_contents[MAX_BUFFER];
      size_t file_size = fread(file_contents, 1, sizeof(file_contents) - 1, file);
      file_contents[file_size] = '\0';
      fclose(file);

      //Send the file contents to the client
      char response[MAX_BUFFER];
      sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %zu\r\n\r\n%s", file_size, file_contents);
      send(client_socket, response, strlen(response), 0);

      //Close the client socket
      close(client_socket);
   }

   //Close the server socket
   close(server_socket);

   return 0;
}