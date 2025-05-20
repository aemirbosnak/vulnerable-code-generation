//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024 // set buffer size for message exchange with server

int main(int argc,char **argv){

  if(argc!=4 || atoi(argv[3])<=0){
    printf("USAGE: ./imapclient <server-address> <username> <port>\n");
    exit(EXIT_FAILURE);
  }

  char *server_address=argv[1]; // get server address from command line
  char *username=argv[2]; // get username from command line
  int port=atoi(argv[3]); // get port number from command line

  int sockfd,bytes_received;
  struct sockaddr_in server_address_info;
  struct hostent *server_handle;
  char buffer[BUFFER_SIZE+1],recv_buffer[BUFFER_SIZE+1];

  sockfd=socket(AF_INET,SOCK_STREAM,0); // create socket with TCP protocol

  if(sockfd==-1){ // check for socket creation error
    perror("SOCKET CREATION ERROR");
    exit(EXIT_FAILURE);
  }

  server_handle=gethostbyname(server_address); // get server host information

  if(server_handle==NULL){ // check for server information retrieval error
    perror("SERVER INFO RETRIEVAL ERROR");
    exit(EXIT_FAILURE);
  }

  memset(&server_address_info,0,sizeof(server_address_info)); // set server address information
  server_address_info.sin_family=AF_INET;
  server_address_info.sin_addr=*((struct in_addr*)server_handle->h_addr);
  server_address_info.sin_port=htons(port);

  if(connect(sockfd,(struct sockaddr*)&server_address_info,sizeof(server_address_info))<0){ // connect to server
    perror("CONNECTION ERROR");
    exit(EXIT_FAILURE);
  }

  bytes_received=recv(sockfd,recv_buffer,BUFFER_SIZE,0); // receive server greeting message
  recv_buffer[bytes_received]='\0';

  printf("%s\n",recv_buffer);

  sprintf(buffer,"LOGIN %s\r\n",username); // prepare login command
  send(sockfd,buffer,strlen(buffer),0); // send login command to server
  bytes_received=recv(sockfd,recv_buffer,BUFFER_SIZE,0); // receive login response from server
  recv_buffer[bytes_received]='\0';

  printf("%s\n",recv_buffer);

  sprintf(buffer,"SELECT INBOX\r\n"); // prepare select command
  send(sockfd,buffer,strlen(buffer),0); // send select command to server
  bytes_received=recv(sockfd,recv_buffer,BUFFER_SIZE,0); // receive select response from server
  recv_buffer[bytes_received]='\0';

  printf("%s\n",recv_buffer);

  sprintf(buffer,"FETCH 1 FULL\r\n"); // prepare fetch command for first message
  send(sockfd,buffer,strlen(buffer),0); // send fetch command to server
  bytes_received=recv(sockfd,recv_buffer,BUFFER_SIZE,0); // receive fetch response from server
  recv_buffer[bytes_received]='\0';

  printf("%s\n",recv_buffer);

  sprintf(buffer,"LOGOUT\r\n"); // prepare logout command
  send(sockfd,buffer,strlen(buffer),0); // send logout command to server
  bytes_received=recv(sockfd,recv_buffer,BUFFER_SIZE,0); // receive logout response from server
  recv_buffer[bytes_received]='\0';

  printf("%s\n",recv_buffer);

  close(sockfd); // close socket

  return 0;

}