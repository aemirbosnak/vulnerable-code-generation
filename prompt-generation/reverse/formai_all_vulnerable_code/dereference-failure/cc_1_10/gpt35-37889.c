//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<signal.h>

#define PORT 8080
#define MAXLINE 1024

int sockfd;

void sig_handler(int signo)
{
  if (signo == SIGINT)
  {
    printf("Exiting server\n");
    close(sockfd);
    exit(0);
  }
}

void handle_connection(int new_socket)
{
  int n;
  char buffer[MAXLINE];
  while (1) 
  {
    bzero(buffer, MAXLINE);
    n = read(new_socket, buffer, sizeof(buffer));
    if (n <= 0)
    {
      printf("Connection terminated\n");
      break;    
    }
    printf("Client message: %s\n",buffer);
    write(new_socket, buffer, sizeof(buffer));
  }
}

int main(int argc, char *argv[])
{
  signal(SIGINT, sig_handler);

  int new_socket, client_len;
  struct sockaddr_in server_addr, client_addr;
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) 
  {
    printf("Error creating socket: %s\n", strerror(errno));
    exit(1);
  }
  
  bzero(&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) 
  {
    printf("Error binding socket: %s\n", strerror(errno));
    exit(1);
  }

  if (listen(sockfd, 5) < 0) 
  {
    printf("Error listening to socket: %s\n", strerror(errno));
    exit(1);
  }

  printf("Server listening on port %d...\n", PORT);
  
  client_len = sizeof(client_addr);

  while (1) 
  {
    new_socket = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
    if (new_socket < 0) 
    {
      printf("Error accepting connection: %s\n", strerror(errno));
      exit(1);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    pid_t pid;
    if ((pid=fork()) == 0) 
    {
      close(sockfd);
      handle_connection(new_socket);
      exit(0);
    }
  }
  return 0;
}