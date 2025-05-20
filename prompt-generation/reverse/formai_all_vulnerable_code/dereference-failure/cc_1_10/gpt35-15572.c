//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#define MAXSIZE 2048

void connectToServer(int *socketfd, struct sockaddr_in *serv_addr, char *server_name)
{
  struct hostent *server;
  
  *socketfd = socket(AF_INET, SOCK_STREAM, 0);
  
  if (*socketfd < 0) 
  {
    printf("Error opening socket\n");
    exit(1);
  }

  server = gethostbyname(server_name);

  if (server == NULL) 
  {
    printf("No such host exists");
    exit(1);
  }

  // assign values to the server address struct
  bzero((char *) serv_addr, sizeof(*serv_addr));
  serv_addr->sin_family = AF_INET;
  bcopy((char *) server->h_addr, (char *) &serv_addr->sin_addr.s_addr, server->h_length);
  serv_addr->sin_port = htons(110);

  if (connect(*socketfd, (struct sockaddr *) serv_addr, sizeof(*serv_addr)) < 0) 
  {
    printf("Error connecting\n");
    exit(1);
  }
}

int recvResponse(int socketfd, char *response)
{
  int n = 0;
  char c = '\0';
  int i = 0;

  while (c != '\n') 
  {
    n = recv(socketfd, &c, 1, 0);

    if (n > 0) 
    {
      response[i] = c;
      i++;
    } 
    else 
    {
      printf("Error receiving response\n");
      exit(1);
    }
  }

  response[i] = '\0';

  return i;
}

int sendCommand(int socketfd, char *cmd)
{
  int n = send(socketfd, cmd, strlen(cmd), 0);

  if (n < 0) 
  {
    printf("Error sending command\n");
    exit(1);
  }

  return n;
}

int main(int argc, char *argv[])
{
  int socketfd, n;
  char buffer[MAXSIZE];
  char response[MAXSIZE];
  struct sockaddr_in serv_addr;

  printf("Connecting to the server...\n");
  
  connectToServer(&socketfd, &serv_addr, argv[1]);

  printf("Connected!\n");

  bzero(response, MAXSIZE);
  bzero(buffer, MAXSIZE);
  
  recvResponse(socketfd, response);

  printf("Response from POP3 server: %s", response);

  char user[MAXSIZE];
  printf("Enter your username: ");
  fgets(user, MAXSIZE, stdin);
  sprintf(buffer, "USER %s", user);

  sendCommand(socketfd, buffer);
  recvResponse(socketfd, response);

  printf("Response from POP3 server: %s", response);

  char password[MAXSIZE];
  printf("Enter your password: ");
  fgets(password, MAXSIZE, stdin);
  sprintf(buffer, "PASS %s", password);

  sendCommand(socketfd, buffer);
  recvResponse(socketfd, response);

  printf("Response from POP3 server: %s", response);

  // fetch inbox status
  sendCommand(socketfd, "STAT\r\n");
  recvResponse(socketfd, response);

  printf("Response from POP3 server: %s", response);

  // get message count
  char *p = strtok(response, " ");
  p = strtok(NULL, " ");

  int nMessages = atoi(p);

  char msgBuffer[MAXSIZE];
  char msgResponse[MAXSIZE];

  // fetch inbox messages
  for (int i = 1; i <= nMessages; i++) 
  {
    sprintf(msgBuffer, "RETR %d\r\n", i);

    sendCommand(socketfd, msgBuffer);
    recvResponse(socketfd, msgResponse);

    printf("Message %d:\n%s\n", i, msgResponse);
  }

  // quit session
  sendCommand(socketfd, "QUIT\r\n");
  recvResponse(socketfd, response);

  printf("Response from POP3 server: %s", response);

  // close socket
  close(socketfd);

  return 0;
}