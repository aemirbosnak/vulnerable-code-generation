//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_USERS 10
#define MAX_NAME_LEN 20
#define MAX_MSG_LEN 1024

typedef struct {
  int id;
  char name[MAX_NAME_LEN];
  int sockfd;
} user_t;

typedef struct {
  int sender_id;
  char msg[MAX_MSG_LEN];
} msg_t;

user_t users[MAX_USERS];
int num_users = 0;
pthread_mutex_t users_mutex = PTHREAD_MUTEX_INITIALIZER;

void send_msg_to_all(msg_t *msg) {
  pthread_mutex_lock(&users_mutex);
  for (int i = 0; i < num_users; i++) {
    if (users[i].id != msg->sender_id) {
      send(users[i].sockfd, msg, sizeof(msg_t), 0);
    }
  }
  pthread_mutex_unlock(&users_mutex);
}

void *handle_client(void *arg) {
  int sockfd = *(int *)arg;
  free(arg);

  char name[MAX_NAME_LEN];
  recv(sockfd, name, MAX_NAME_LEN, 0);

  pthread_mutex_lock(&users_mutex);
  users[num_users].id = num_users;
  strcpy(users[num_users].name, name);
  users[num_users].sockfd = sockfd;
  num_users++;
  pthread_mutex_unlock(&users_mutex);

  msg_t msg;
  while (1) {
    recv(sockfd, &msg, sizeof(msg_t), 0);
    if (strcmp(msg.msg, "/quit") == 0) {
      break;
    }
    send_msg_to_all(&msg);
  }

  pthread_mutex_lock(&users_mutex);
  for (int i = 0; i < num_users; i++) {
    if (users[i].id == msg.sender_id) {
      users[i] = users[num_users - 1];
      num_users--;
      break;
    }
  }
  pthread_mutex_unlock(&users_mutex);

  close(sockfd);
  pthread_exit(NULL);
}

int main() {
  int sockfd, newsockfd, port;

  struct sockaddr_in serv_addr, cli_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  bzero((char *)&serv_addr, sizeof(serv_addr));

  port = 12345;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(port);

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  listen(sockfd, 5);

  while (1) {
    socklen_t cli_len = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len);
    if (newsockfd < 0) {
      perror("ERROR on accept");
      continue;
    }

    int *arg = malloc(sizeof(int));
    *arg = newsockfd;
    pthread_t thread;
    pthread_create(&thread, NULL, handle_client, arg);
  }

  close(sockfd);
  return 0;
}