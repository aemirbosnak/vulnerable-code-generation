//FormAI DATASET v1.0 Category: Socket programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

typedef struct {
  int client_sock;
  struct sockaddr_in client_addr;
  char client_username[50]; // Store username of client
} client_data;

// Global variables
int server_sock;
char *server_ip;
int server_port;
client_data clients[10]; // Storage for up to 10 clients
int client_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Forward declarations
void *client_handler(void *arg);
void send_message_to_all(char *message, int sender_index);
void send_message_to_client(char *message, int client_sock);

int main(int argc, char *argv[]) {

  // Parse command line arguments for server IP and port
  if (argc != 3) {
    printf("Usage: ./chat_server <server_ip> <server_port>\n");
    exit(EXIT_FAILURE);
  }
  server_ip = argv[1];
  server_port = atoi(argv[2]);

  // Create socket for server
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("Failed to create socket");
    exit(EXIT_FAILURE);
  }

  // Bind socket to specified IP and port on server side
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(server_port);
  if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0 ) {
    perror("Invalid server IP address");
    exit(EXIT_FAILURE);
  }
  if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Failed to bind to server IP and port");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_sock, 10) < 0) {
    perror("Failed to listen for connections");
    exit(EXIT_FAILURE);
  }

  printf("Server started on %s:%d\n", server_ip, server_port);

  while (1) {
    // Accept a new client connection
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
    
    if (client_sock < 0) {
      perror("Failed to accept new client connection");
      continue;
    }

    char client_msg[100];
    sprintf(client_msg, "Enter your username: ");
    if (send(client_sock, client_msg, strlen(client_msg), 0) <= 0) {
      perror("Failed to send username prompt to client");
      continue;
    }

    // Create new thread to handle client
    client_data data = {client_sock, client_addr, ""};
    pthread_t client_thread;
    if (pthread_create(&client_thread, NULL, client_handler, (void *)&data) != 0) {
      perror("Failed to create client thread");
      continue;
    }
    printf("New client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
  }

  return 0;
}

void *client_handler(void *arg) {
  client_data data = *((client_data *)arg);
  int client_sock = data.client_sock;
  struct sockaddr_in client_addr = data.client_addr;
  char *client_username = data.client_username;
  char client_msg[100];

  // Receive client username
  ssize_t bytes_received;
  if ((bytes_received = recv(client_sock, client_username, 50, 0)) < 0) {
    perror("Failed to receive client username");
    return NULL;
  }
  client_username[bytes_received-1] = '\0';

  // Add client to list
  pthread_mutex_lock(&mutex);
  int index = client_count++;
  clients[index] = data;
  pthread_mutex_unlock(&mutex);

  // Send welcome message to client
  sprintf(client_msg, "Welcome to the chat room, %s!\n", client_username);
  if (send(client_sock, client_msg, strlen(client_msg), 0) <= 0) {
    perror("Failed to send welcome message to client");
    return NULL;
  }

  while (1) {
    // Receive message from client
    char message[1024];
    bytes_received = recv(client_sock, message, 1024, 0);

    if (bytes_received <= 0) {
      // Client has disconnected
      close(client_sock);
      printf("Client %s from %s:%d has disconnected\n", client_username, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
      pthread_mutex_lock(&mutex);
      for (int i = 0; i < client_count; i++) {
        if (i != index) {
          sprintf(client_msg, "%s has left the chat room\n", client_username);
          send_message_to_client(client_msg, clients[i].client_sock);
        }
        else {
          // Shift all clients after the disconnected one down by one index in the array
          for (int j = i+1; j < client_count; j++) {
            clients[j-1] = clients[j];
          }
          client_count--;
        }
      }
      pthread_mutex_unlock(&mutex);
      break;
    }

    // Add null terminator to message and remove newlines
    message[bytes_received-1] = '\0';
    if (message[strlen(message)-1] == '\n') {
      message[strlen(message)-1] = '\0';
    }

    // Check for special commands
    if (message[0] == '/') {
      if (strncmp(message, "/list", 5) == 0) { // Command to list all clients
        pthread_mutex_lock(&mutex);
        sprintf(client_msg, "Current clients in chat room:\n");
        for (int i = 0; i < client_count; i++) {
          sprintf(client_msg+strlen(client_msg), "  - %s (%s:%d)\n", clients[i].client_username, inet_ntoa(clients[i].client_addr.sin_addr), ntohs(clients[i].client_addr.sin_port));
        }
        pthread_mutex_unlock(&mutex);
      }
      else if (strncmp(message, "/pm", 3) == 0) { // Command to send private message to specific client
        char *whitespace = strchr(message+4, ' ');
        if (whitespace == NULL) {
          sprintf(client_msg, "Usage: /pm <username> <message>\n");
        }
        else {
          *whitespace = '\0';
          char *recipient_username = message+4;
          char *pm_message = whitespace+1;
          pthread_mutex_lock(&mutex);
          int recipient_index = -1;
          for (int i = 0; i < client_count; i++) {
            if (strcmp(clients[i].client_username, recipient_username) == 0) {
              recipient_index = i;
              break;
            }
          }
          if (recipient_index == -1) {
            sprintf(client_msg, "Error: client \"%s\" not found\n", recipient_username);
          }
          else {
            sprintf(client_msg, "[PM from %s] %s\n", client_username, pm_message);
            send_message_to_client(client_msg, clients[recipient_index].client_sock);
          }
          pthread_mutex_unlock(&mutex);
        }
      }
      else {
        sprintf(client_msg, "Invalid command \"%s\"\n", message);
      }
    } 
    else { // Regular message
      sprintf(client_msg, "[%s] %s", client_username, message);
      send_message_to_all(client_msg, index);
    }

  }

  return NULL;
}

void send_message_to_all(char *message, int sender_index) {
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < client_count; i++) {
    if (i != sender_index) {
      send_message_to_client(message, clients[i].client_sock);
    }
  }
  pthread_mutex_unlock(&mutex);
}

void send_message_to_client(char *message, int client_sock) {
  if (send(client_sock, message, strlen(message), 0) <= 0) {
    perror("Failed to send message to client");
  }
}