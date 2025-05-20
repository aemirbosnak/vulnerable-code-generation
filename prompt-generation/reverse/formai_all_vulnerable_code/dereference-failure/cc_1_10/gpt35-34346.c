//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main()
{
  int clientSocket;
  struct sockaddr_in serverAddr;
  char buffer[1024];

  //create socket
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);

  //set server address and port
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(21);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  //connect to server
  connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

  //login to server
  char username[50] = "USERNAME";
  char password[50] = "PASSWORD";

  sprintf(buffer, "USER %s\r\n", username);
  send(clientSocket, buffer, strlen(buffer), 0);
  recv(clientSocket, buffer, 1024, 0);

  sprintf(buffer, "PASS %s\r\n", password);
  send(clientSocket, buffer, strlen(buffer), 0);
  recv(clientSocket, buffer, 1024, 0);
  
  printf("%s", buffer);

  //send commands to server
  sprintf(buffer, "LIST\r\n");
  send(clientSocket, buffer, strlen(buffer), 0);
  recv(clientSocket, buffer, 1024, 0);
  
  printf("%s", buffer);

  //download file from server
  sprintf(buffer, "RETR file.txt\r\n");
  send(clientSocket, buffer, strlen(buffer), 0);
  recv(clientSocket, buffer, 1024, 0);

  FILE *fp;
  fp = fopen("file.txt", "wb");

  char *temp;
  char *rest = buffer;

  while((temp = strtok_r(rest, "\n", &rest)))
  {
    if (strstr(temp, "150"))
      break;
  }

  while(1)
  {
    int bytes_received = recv(clientSocket, buffer, 1024, 0);

    if(bytes_received < 0)
    {
      printf("Error in receiving data from server.\n");
      return -1;
    }
    else if(bytes_received == 0)
    {
      printf("Transfer successful!\n");
      break;
    }

    fwrite(buffer, 1, bytes_received, fp);
  }

  fclose(fp);
  close(clientSocket);
  return 0;
}