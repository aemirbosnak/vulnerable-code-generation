//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int create_socket() {
   int sockfd;
   if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
      perror("socket failed");
      exit(EXIT_FAILURE);
   }
   return sockfd;
}

void bind_socket(int sockfd, struct sockaddr_in *server) {
   if (bind(sockfd, (struct sockaddr *)server, sizeof(struct sockaddr_in)) == -1) {
      perror("bind failed");
      exit(EXIT_FAILURE);
   }
}

void listen_socket(int sockfd, int backlog) {
   if (listen(sockfd, backlog) == -1) {
      perror("listen failed");
      exit(EXIT_FAILURE);
   }
}

int accept_socket(int sockfd) {
   int newsockfd;
   struct sockaddr_in client;
   socklen_t clientlen = sizeof(client);
   if ((newsockfd = accept(sockfd, (struct sockaddr *)&client, &clientlen)) == -1) {
      perror("accept failed");
      exit(EXIT_FAILURE);
   }
   return newsockfd;
}

char *recv_data(int sockfd, int len) {
   char *buf = (char*)malloc(len);
   if (recv(sockfd, buf, len, 0) == -1) {
      perror("recv failed");
      exit(EXIT_FAILURE);
   }
   return buf;
}

void send_data(int sockfd, char *buf) {
   if (send(sockfd, buf, strlen(buf), 0) == -1) {
      perror("send failed");
      exit(EXIT_FAILURE);
   }
}

void close_socket(int sockfd) {
   if (close(sockfd) == -1) {
      perror("close failed");
      exit(EXIT_FAILURE);
   }
}

int main() {
   int sockfd, newsockfd;
   struct sockaddr_in server;
   struct hostent *host;
   if ((host = gethostbyname("localhost")) == NULL) {
      fprintf(stderr, "ERROR: no such host\n");
      exit(EXIT_FAILURE);
   }
   bzero((char *)&server, sizeof(server));
   server.sin_family = AF_INET;
   bcopy((char *)host->h_addr, (char *)&server.sin_addr.s_addr, host->h_length);
   server.sin_port = htons(5000);
   if ((sockfd = create_socket()) == -1) {
      perror("socket creation failed");
      exit(EXIT_FAILURE);
   }
   if ((newsockfd = accept_socket(sockfd)) == -1) {
      perror("accept failed");
      exit(EXIT_FAILURE);
   }
   if ((newsockfd = accept_socket(sockfd)) == -1) {
      perror("accept failed");
      exit(EXIT_FAILURE);
   }
   printf("Connected\n");
   char *data;
   data = recv_data(newsockfd, sizeof(data));
   printf("Received %s\n", data);
   free(data);
   close_socket(newsockfd);
   close_socket(sockfd);
   exit(EXIT_SUCCESS);
}