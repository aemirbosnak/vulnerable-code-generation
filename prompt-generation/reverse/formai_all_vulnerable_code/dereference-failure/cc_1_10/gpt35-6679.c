//FormAI DATASET v1.0 Category: Firewall ; Style: creative
// Welcome to the world of unique C Firewall example program!
// This program helps you to control incoming and outgoing traffic by blocking certain IP addresses and ports.
// Let's get started.

// First, let's include necessary libraries.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

// Now, let's define our main function.
int main()
{
  // Declare necessary variables.
  int sock, conn, len;
  char buffer[1024];
  
  // Create a new socket.
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
  {
    perror("Error creating socket.");
    exit(1);
  }
  
  // Declare a sockaddr_in structure to store address details.
  struct sockaddr_in addr, client_addr;
  memset(&addr, 0, sizeof(addr));
  memset(&client_addr, 0, sizeof(client_addr));
  
  // Set address parameters.
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(8080); // You can change the port number to any port you want.
  
  // Bind socket to the address.
  if (bind(sock, (struct sockaddr*) &addr, sizeof(addr)) < 0)
  {
    perror("Error binding socket.");
    exit(1);
  }
  
  // Listen for incoming connections.
  if (listen(sock, 5) < 0)
  {
    perror("Error listening socket.");
    exit(1);
  }
  
  // Infinite loop to handle incoming connections.
  while (1)
  {
    // Accept incoming connection.
    len = sizeof(client_addr);
    conn = accept(sock, (struct sockaddr*) &client_addr, &len);
    if (conn < 0)
    {
      perror("Error accepting connection.");
      continue;
    }
    
    // Convert IP address to string.
    char* ip = inet_ntoa(client_addr.sin_addr);
    
    // Check if IP is blocked.
    if (strcmp(ip, "127.0.0.1") == 0 || strcmp(ip, "192.168.1.1") == 0)
    {
      // IP is blocked. Send a message and close the connection.
      strcpy(buffer, "Access denied.");
      send(conn, buffer, strlen(buffer), 0);
      close(conn);
      continue;
    }
    
    // Connection is allowed. Receive data from client.
    memset(buffer, 0, sizeof(buffer));
    if (recv(conn, buffer, sizeof(buffer), 0) < 0)
    {
      perror("Error receiving data.");
      close(conn);
      continue;
    }
    
    // Print received data to console.
    printf("Received data: %s\n", buffer);
    
    // Close connection.
    close(conn);
  }
  
  // Close socket.
  close(sock);
  
  // Program ends.
  return 0;
}