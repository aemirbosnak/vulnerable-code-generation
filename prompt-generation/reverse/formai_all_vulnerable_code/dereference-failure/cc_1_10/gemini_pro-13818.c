//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the player struct
typedef struct {
  int id;
  char name[256];
  int score;
} Player;

// Define the game struct
typedef struct {
  Player players[MAX_PLAYERS];
  int num_players;
  int current_player;
  int game_over;
} Game;

// Initialize the game
Game game;

// Initialize the mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Create the server
int create_server(char *ip, int port) {
  int sockfd;
  struct sockaddr_in servaddr;

  // Create the socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  // Set the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(ip);
  servaddr.sin_port = htons(port);

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("bind");
    return -1;
  }

  // Listen for connections
  if (listen(sockfd, MAX_PLAYERS) == -1) {
    perror("listen");
    return -1;
  }

  return sockfd;
}

// Accept a connection
int accept_connection(int sockfd) {
  int connfd;
  struct sockaddr_in cliaddr;
  socklen_t len = sizeof(cliaddr);

  // Accept the connection
  connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
  if (connfd == -1) {
    perror("accept");
    return -1;
  }

  return connfd;
}

// Send a message to a client
int send_message(int connfd, char *message) {
  int len = strlen(message);

  // Send the message length
  if (send(connfd, &len, sizeof(int), 0) == -1) {
    perror("send");
    return -1;
  }

  // Send the message
  if (send(connfd, message, len, 0) == -1) {
    perror("send");
    return -1;
  }

  return 0;
}

// Receive a message from a client
int receive_message(int connfd, char *message) {
  int len;

  // Receive the message length
  if (recv(connfd, &len, sizeof(int), 0) == -1) {
    perror("recv");
    return -1;
  }

  // Receive the message
  if (recv(connfd, message, len, 0) == -1) {
    perror("recv");
    return -1;
  }

  return 0;
}

// Handle a client connection
void *handle_client(void *arg) {
  int connfd = *(int *)arg;
  char message[256];

  // Receive the player name
  if (receive_message(connfd, message) == -1) {
    perror("receive_message");
    pthread_exit(NULL);
  }

  // Lock the mutex
  pthread_mutex_lock(&mutex);

  // Add the player to the game
  game.players[game.num_players].id = connfd;
  strcpy(game.players[game.num_players].name, message);
  game.players[game.num_players].score = 0;
  game.num_players++;

  // Unlock the mutex
  pthread_mutex_unlock(&mutex);

  // Send the player id
  sprintf(message, "%d", connfd);
  if (send_message(connfd, message) == -1) {
    perror("send_message");
    pthread_exit(NULL);
  }

  // Send the game state
  if (send_message(connfd, (char *)&game) == -1) {
    perror("send_message");
    pthread_exit(NULL);
  }

  // Handle client input
  while (!game.game_over) {
    // Receive the player input
    if (receive_message(connfd, message) == -1) {
      perror("receive_message");
      pthread_exit(NULL);
    }

    // Handle the player input
    if (strcmp(message, "roll") == 0) {
      // Roll the dice
      int dice1 = rand() % 6 + 1;
      int dice2 = rand() % 6 + 1;

      // Add the dice roll to the player's score
      pthread_mutex_lock(&mutex);
      game.players[game.current_player].score += dice1 + dice2;

      // Check if the player has won
      if (game.players[game.current_player].score >= 100) {
        game.game_over = 1;

        // Send the game over message to all players
        sprintf(message, "%s has won the game!", game.players[game.current_player].name);
        for (int i = 0; i < game.num_players; i++) {
          if (send_message(game.players[i].id, message) == -1) {
            perror("send_message");
          }
        }
      }

      // Unlock the mutex
      pthread_mutex_unlock(&mutex);

      // Send the game state to all players
      if (send_message(connfd, (char *)&game) == -1) {
        perror("send_message");
      }
    }
  }

  // Close the client connection
  close(connfd);

  // Free up the player slot
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < game.num_players; i++) {
    if (game.players[i].id == connfd) {
      game.players[i] = game.players[game.num_players - 1];
      game.num_players--;
      break;
    }
  }
  // Unlock the mutex
  pthread_mutex_unlock(&mutex);

  // Exit the thread
  pthread_exit(NULL);
}

// Main function
int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
    return 1;
  }

  char *ip = argv[1];
  int port = atoi(argv[2]);

  // Initialize the game
  game.num_players = 0;
  game.current_player = 0;
  game.game_over = 0;

  // Create the server
  int sockfd = create_server(ip, port);
  if (sockfd == -1) {
    return 1;
  }

  // Main loop
  while (1) {
    // Accept a connection
    int connfd = accept_connection(sockfd);
    if (connfd == -1) {
      continue;
    }

    // Create a new thread to handle the client connection
    pthread_t thread;
    pthread_create(&thread, NULL, handle_client, &connfd);
  }

  // Close the server
  close(sockfd);

  return 0;
}