//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int clientSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  /*Create socket*/
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);

  /*Set the address of the server we want to connect to*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(21);
  serverAddr.sin_addr.s_addr = inet_addr("192.168.1.100");

  /*Connect to the server*/
  addr_size = sizeof(serverAddr);
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  /*Send command to server*/
  char command[100];
  sprintf(command, "%s\n", "USER admin");
  send(clientSocket, command, strlen(command), 0);

  /*Receive response from server*/
  recv(clientSocket, buffer, 1024, 0);
  printf("%s", buffer);

  /*Send password to server*/
  sprintf(command, "%s\n", "PASS password");
  send(clientSocket, command, strlen(command), 0);

  /*Receive response from server*/
  recv(clientSocket, buffer, 1024, 0);
  printf("%s", buffer);

  /*Send PASV command to server*/
  sprintf(command, "%s\n", "PASV");
  send(clientSocket, command, strlen(command), 0);

  /*Receive response from server*/
  recv(clientSocket, buffer, 1024, 0);
  printf("%s", buffer);

  /*Parse PASV response to get IP address and port*/
  char *ip, *port;
  strtok(buffer, "(");
  port = strtok(NULL, ",");
  port = strtok(NULL, ",");
  port = strtok(NULL, ",");
  port = strtok(NULL, ",");
  ip = strtok(NULL, ",");
  ip = strtok(NULL, ",");
  ip = strtok(NULL, ",");
  ip = strtok(NULL, ",");
  ip[strlen(ip)-1] = '\0';

  /*Build data socket*/
  struct sockaddr_in dataAddr;
  int dataSocket;
  dataAddr.sin_family = AF_INET;
  dataAddr.sin_port = htons(256*atoi(port) + atoi(strtok(port, ",")));
  dataAddr.sin_addr.s_addr = inet_addr(ip);

  /*Connect data socket to server*/
  addr_size = sizeof(dataAddr);
  dataSocket = socket(PF_INET, SOCK_STREAM, 0);
  connect(dataSocket, (struct sockaddr *) &dataAddr, addr_size);

  /*Send RETR command to server*/
  sprintf(command, "%s\n", "RETR file.txt");
  send(clientSocket, command, strlen(command), 0);

  /*Receive file from server and write to disk*/
  FILE *file = fopen("file.txt", "wb");
  while(recv(dataSocket, buffer, 1024, 0)){
    fwrite(buffer, 1, sizeof(buffer), file);
    memset(buffer, 0, 1024);
  }
  fclose(file);

  /*Send QUIT command to server*/
  sprintf(command, "%s\n", "QUIT");
  send(clientSocket, command, strlen(command), 0);

  /*Receive response from server*/
  recv(clientSocket, buffer, 1024, 0);
  printf("%s", buffer);

  /*Close sockets*/
  close(dataSocket);
  close(clientSocket);

  return 0;
}