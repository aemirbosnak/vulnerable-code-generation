//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Maximum number of peers
#define MAX_PEERS 10

// Server port
#define SERVER_PORT 5555

// File transfer port
#define FILE_PORT 6666

// Maximum file size
#define MAX_FILE_SIZE 1024 * 1024

// File synchronization status
#define FILE_SYNC_NONE 0
#define FILE_SYNC_PENDING 1
#define FILE_SYNC_COMPLETE 2

// File synchronization request
typedef struct {
  char filename[256];
  int filesize;
  int status;
} FileSyncRequest;

// Peer information
typedef struct {
  char ip_address[32];
  int port;
} Peer;

// Create a server socket
int create_server_socket() {
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    exit(1);
  }

  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(SERVER_PORT);

  if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
    perror("bind");
    exit(1);
  }

  if (listen(server_socket, 5) == -1) {
    perror("listen");
    exit(1);
  }

  return server_socket;
}

// Accept a client connection
int accept_client_connection(int server_socket) {
  struct sockaddr_in client_address;
  socklen_t client_address_len = sizeof(client_address);

  int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);
  if (client_socket == -1) {
    perror("accept");
    exit(1);
  }

  return client_socket;
}

// Send a file synchronization request to a peer
void send_file_sync_request(int client_socket, FileSyncRequest *request) {
  if (send(client_socket, request, sizeof(FileSyncRequest), 0) == -1) {
    perror("send");
    exit(1);
  }
}

// Receive a file synchronization request from a peer
void receive_file_sync_request(int client_socket, FileSyncRequest *request) {
  if (recv(client_socket, request, sizeof(FileSyncRequest), 0) == -1) {
    perror("recv");
    exit(1);
  }
}

// Send a file to a peer
void send_file(int client_socket, char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("fopen");
    exit(1);
  }

  fseek(file, 0, SEEK_END);
  int filesize = ftell(file);
  rewind(file);

  char buffer[1024];
  while (filesize > 0) {
    int bytes_read = fread(buffer, 1, sizeof(buffer), file);
    if (bytes_read == -1) {
      perror("fread");
      exit(1);
    }

    if (send(client_socket, buffer, bytes_read, 0) == -1) {
      perror("send");
      exit(1);
    }

    filesize -= bytes_read;
  }

  fclose(file);
}

// Receive a file from a peer
void receive_file(int client_socket, char *filename) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    perror("fopen");
    exit(1);
  }

  char buffer[1024];
  int filesize;
  if (recv(client_socket, &filesize, sizeof(int), 0) == -1) {
    perror("recv");
    exit(1);
  }

  while (filesize > 0) {
    int bytes_read = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_read == -1) {
      perror("recv");
      exit(1);
    }

    fwrite(buffer, 1, bytes_read, file);

    filesize -= bytes_read;
  }

  fclose(file);
}

// Main function
int main() {
  // Create a server socket
  int server_socket = create_server_socket();

  // Create a list of peers
  Peer peers[MAX_PEERS];
  int num_peers = 0;

  // Main loop
  while (1) {
    // Accept a client connection
    int client_socket = accept_client_connection(server_socket);

    // Receive a file synchronization request
    FileSyncRequest request;
    receive_file_sync_request(client_socket, &request);

    // Check if the file exists
    FILE *file = fopen(request.filename, "rb");
    if (file != NULL) {
      // Send the file to the peer
      send_file(client_socket, request.filename);
    } else {
      // Request the file from the peer
      send_file_sync_request(client_socket, &request);
      receive_file(client_socket, request.filename);
    }

    // Close the client socket
    close(client_socket);
  }

  // Close the server socket
  close(server_socket);

  return 0;
}