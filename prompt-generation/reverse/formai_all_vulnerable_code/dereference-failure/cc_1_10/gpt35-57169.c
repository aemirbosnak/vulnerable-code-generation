//FormAI DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

#define SERVER_PORT 5555
#define MAXLINE 1024

void sig_handler(int signo);
void err_sys(char *msg);
void err_quit(char *msg);
void handle_client_message(int sockfd, char *client_message);

int main(int argc, char **argv) {
  int sockfd;
  struct sockaddr_in serveraddr;
  char client_message[MAXLINE];
  int n;
  fd_set read_set, ready_set;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // Set up the server address
  bzero(&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(SERVER_PORT);
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

  // Bind the socket to the server address
  bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

  // Listen for incoming connections
  listen(sockfd, 10);

  // Set up the signal handler for SIGPIPE
  if (signal(SIGPIPE, sig_handler) == SIG_ERR) {
    err_sys("Error setting signal handler for SIGPIPE");
  }

  // Initialize the read set
  FD_ZERO(&read_set);
  FD_SET(sockfd, &read_set);

  while (1) {
    // Wait for a connection request or a message from a client
    ready_set = read_set;
    if (select(sockfd + 1, &ready_set, NULL, NULL, NULL) < 0) {
      if (errno == EINTR) {
        continue;
      } else {
        err_sys("Error in select");
      }
    }

    // If a connection request is received, accept it and add the new
    // socket to the read set
    if (FD_ISSET(sockfd, &ready_set)) {
      int newsockfd;
      struct sockaddr_in clientaddr;
      socklen_t clientlen = sizeof(clientaddr);
      newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientlen);
      FD_SET(newsockfd, &read_set);
    }

    // Check all sockets for incoming messages
    for (int i = sockfd + 1; i < FD_SETSIZE; i++) {
      if (FD_ISSET(i, &ready_set)) {
        // Handle the message from the client
        handle_client_message(i, client_message);
        // If the client has closed the connection, remove the socket
        // from the read set
        if (n == 0) {
          FD_CLR(i, &read_set);
          close(i);
        }
      }
    }
  }
}

void handle_client_message(int sockfd, char *client_message) {
  int n;
  // Receive the message from the client
  if ((n = recv(sockfd, client_message, MAXLINE, 0)) == 0) {
    printf("Client disconnected\n");
    return;
  } else if (n < 0) {
    err_sys("Error in recv");
  }

  // Process the client message
  client_message[n] = '\0';
  printf("Received message from client: %s\n", client_message);

  // Send a response back to the client
  char *response = "Hello from the server";
  if (send(sockfd, response, strlen(response), 0) != strlen(response)) {
    err_sys("Error in send");
  }
}

void err_sys(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void err_quit(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void sig_handler(int signo)
{
    if (signo == SIGPIPE) {
        printf("Received SIGPIPE signal\n");
    }
}