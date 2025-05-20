//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFFER 1024

void usage(char* program_name)
{
   printf("Usage: %s <proxy_port>\n", program_name);
   exit(1);
}

int main(int argc, char *argv[]) 
{
   // Check arguments
   if (argc < 2) {
      usage(argv[0]);
   }

   // Parse arguments
   int proxy_port = atoi(argv[1]);

   // Create socket for proxy
   int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
   if (proxy_socket < 0) {
      perror("Error creating socket");
      exit(1);
   }

   // Bind socket to port
   struct sockaddr_in proxy_addr;
   memset(&proxy_addr, 0, sizeof(proxy_addr));
   proxy_addr.sin_family = AF_INET;
   proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
   proxy_addr.sin_port = htons(proxy_port);
   if (bind(proxy_socket, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) < 0) {
      perror("Error binding socket");
      exit(1);
   }

   // Start listening
   if (listen(proxy_socket, 10) < 0) {
      perror("Error listening");
      exit(1);
   }

   // Main loop
   while (1) {
      // Accept incoming connection
      printf("Waiting for connection...\n");
      struct sockaddr_in client_addr;
      socklen_t client_addr_len = sizeof(client_addr);
      int client_socket = accept(proxy_socket, (struct sockaddr*)&client_addr, &client_addr_len);
      if (client_socket < 0) {
         perror("Error accepting connection");
         continue;
      }

      // Read request from client
      char buffer[MAX_BUFFER];
      memset(buffer, 0, MAX_BUFFER);
      int num_bytes = recv(client_socket, buffer, MAX_BUFFER, 0);
      if (num_bytes < 0) {
         perror("Error reading request");
         close(client_socket);
         continue;
      }

      // Parse request
      char method[MAX_BUFFER], url[MAX_BUFFER], version[MAX_BUFFER];
      sscanf(buffer, "%s %s %s", method, url, version);

      // Print request
      printf("Received request:\n%s", buffer);

      // Resolve host
      char hostname[MAX_BUFFER];
      sscanf(url, "http://%s", hostname);
      struct hostent* host = gethostbyname(hostname);
      if (host == NULL) {
         perror("Error resolving host");
         close(client_socket);
         continue;
      }

      // Connect to host
      struct sockaddr_in server_addr;
      memset(&server_addr, 0, sizeof(server_addr));
      server_addr.sin_family = AF_INET;
      server_addr.sin_port = htons(80);
      memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
      int server_socket = socket(AF_INET, SOCK_STREAM, 0);
      if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
         perror("Error connecting to server");
         close(client_socket);
         continue;
      }

      // Forward request to server
      if (send(server_socket, buffer, num_bytes, 0) < 0) {
         perror("Error forwarding request");
         close(client_socket);
         close(server_socket);
         continue;
      }

      // Read response from server
      memset(buffer, 0, MAX_BUFFER);
      num_bytes = recv(server_socket, buffer, MAX_BUFFER, 0);
      if (num_bytes < 0) {
         perror("Error reading response");
         close(client_socket);
         close(server_socket);
         continue;
      }

      // Print response
      printf("Received response:\n%s", buffer);

      // Forward response to client
      if (send(client_socket, buffer, num_bytes, 0) < 0) {
         perror("Error forwarding response");
         close(client_socket);
         close(server_socket);
         continue;
      }

      // Close sockets
      close(client_socket);
      close(server_socket);
   }

   // Close socket
   close(proxy_socket);

   return 0;
}