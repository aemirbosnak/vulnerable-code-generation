//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_LINE_LENGTH 1024

typedef struct {
  int sockfd;
  char *host;
  char *username;
  char *password;
} pop3_client_args;

void *pop3_client_thread(void *args) {
  pop3_client_args *args_struct = (pop3_client_args *)args;
  int sockfd = args_struct->sockfd;
  char *host = args_struct->host;
  char *username = args_struct->username;
  char *password = args_struct->password;

  // Send the USER command
  char user_cmd[MAX_LINE_LENGTH];
  snprintf(user_cmd, sizeof(user_cmd), "USER %s\r\n", username);
  send(sockfd, user_cmd, strlen(user_cmd), 0);

  // Receive the USER response
  char user_resp[MAX_LINE_LENGTH];
  recv(sockfd, user_resp, sizeof(user_resp), 0);

  // Send the PASS command
  char pass_cmd[MAX_LINE_LENGTH];
  snprintf(pass_cmd, sizeof(pass_cmd), "PASS %s\r\n", password);
  send(sockfd, pass_cmd, strlen(pass_cmd), 0);

  // Receive the PASS response
  char pass_resp[MAX_LINE_LENGTH];
  recv(sockfd, pass_resp, sizeof(pass_resp), 0);

  // Send the STAT command
  char stat_cmd[MAX_LINE_LENGTH];
  snprintf(stat_cmd, sizeof(stat_cmd), "STAT\r\n");
  send(sockfd, stat_cmd, strlen(stat_cmd), 0);

  // Receive the STAT response
  char stat_resp[MAX_LINE_LENGTH];
  recv(sockfd, stat_resp, sizeof(stat_resp), 0);

  // Send the LIST command
  char list_cmd[MAX_LINE_LENGTH];
  snprintf(list_cmd, sizeof(list_cmd), "LIST\r\n");
  send(sockfd, list_cmd, strlen(list_cmd), 0);

  // Receive the LIST response
  char list_resp[MAX_LINE_LENGTH];
  recv(sockfd, list_resp, sizeof(list_resp), 0);

  // Send the RETR command
  char retr_cmd[MAX_LINE_LENGTH];
  snprintf(retr_cmd, sizeof(retr_cmd), "RETR 1\r\n");
  send(sockfd, retr_cmd, strlen(retr_cmd), 0);

  // Receive the RETR response
  char retr_resp[MAX_LINE_LENGTH];
  recv(sockfd, retr_resp, sizeof(retr_resp), 0);

  // Send the QUIT command
  char quit_cmd[MAX_LINE_LENGTH];
  snprintf(quit_cmd, sizeof(quit_cmd), "QUIT\r\n");
  send(sockfd, quit_cmd, strlen(quit_cmd), 0);

  // Close the socket
  close(sockfd);

  return NULL;
}

int main(int argc, char **argv) {
  if (argc != 5) {
    printf("Usage: %s <host> <username> <password> <num_threads>\n", argv[0]);
    return -1;
  }

  char *host = argv[1];
  char *username = argv[2];
  char *password = argv[3];
  int num_threads = atoi(argv[4]);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  // Connect to the POP3 server
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(host);
  server_addr.sin_port = htons(POP3_PORT);
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return -1;
  }

  // Create the thread pool
  pthread_t threads[num_threads];

  // Create the arguments for each thread
  pop3_client_args args[num_threads];
  for (int i = 0; i < num_threads; i++) {
    args[i].sockfd = sockfd;
    args[i].host = host;
    args[i].username = username;
    args[i].password = password;
  }

  // Create the threads
  for (int i = 0; i < num_threads; i++) {
    if (pthread_create(&threads[i], NULL, pop3_client_thread, &args[i]) != 0) {
      perror("pthread_create");
      return -1;
    }
  }

  // Join the threads
  for (int i = 0; i < num_threads; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      perror("pthread_join");
      return -1;
    }
  }

  // Close the socket
  close(sockfd);

  return 0;
}