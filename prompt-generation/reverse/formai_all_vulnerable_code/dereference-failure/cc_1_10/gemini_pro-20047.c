//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 1024

typedef struct {
  int socket;
  char *host;
  char *port;
  char *from;
  char *to;
  char *subject;
  char *body;
} email_params_t;

pthread_mutex_t lock;
int num_threads = 0;

void *send_email(void *args) {
  email_params_t *params = (email_params_t *)args;

  // Connect to the SMTP server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(params->port));
  struct hostent *host_info = gethostbyname(params->host);
  if (host_info == NULL) {
    perror("gethostbyname");
    return NULL;
  }
  memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return NULL;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return NULL;
  }

  // Send the HELO command
  char buffer[MAX_LINE_LENGTH];
  snprintf(buffer, MAX_LINE_LENGTH, "HELO %s\r\n", params->host);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return NULL;
  }

  // Send the MAIL FROM command
  snprintf(buffer, MAX_LINE_LENGTH, "MAIL FROM: <%s>\r\n", params->from);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return NULL;
  }

  // Send the RCPT TO command
  snprintf(buffer, MAX_LINE_LENGTH, "RCPT TO: <%s>\r\n", params->to);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return NULL;
  }

  // Send the DATA command
  snprintf(buffer, MAX_LINE_LENGTH, "DATA\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return NULL;
  }

  // Send the email subject and body
  snprintf(buffer, MAX_LINE_LENGTH, "Subject: %s\r\n\r\n%s\r\n.\r\n", params->subject, params->body);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return NULL;
  }

  // Send the QUIT command
  snprintf(buffer, MAX_LINE_LENGTH, "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return NULL;
  }

  // Close the socket
  close(sockfd);

  return NULL;
}

int main(int argc, char **argv) {
  if (argc < 7) {
    fprintf(stderr, "Usage: %s host port from to subject body\n", argv[0]);
    return 1;
  }

  // Initialize the mutex
  pthread_mutex_init(&lock, NULL);

  // Create the threads
  pthread_t threads[MAX_THREADS];
  for (int i = 0; i < MAX_THREADS; i++) {
    email_params_t *params = malloc(sizeof(email_params_t));
    params->host = argv[1];
    params->port = argv[2];
    params->from = argv[3];
    params->to = argv[4];
    params->subject = argv[5];
    params->body = argv[6];

    pthread_create(&threads[i], NULL, send_email, (void *)params);
  }

  // Join the threads
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the mutex
  pthread_mutex_destroy(&lock);

  return 0;
}