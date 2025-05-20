//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 512

int main(int argc, char * argv[]) {

   int sockfd, n, bytes_rcv, bytes_sent;
   char buffer[BUF_SIZE];
   char * server_address, * username, * password, * filename, * path;
   struct sockaddr_in servaddr;
   struct hostent * serverinfo;

   if (argc != 6) {
      printf("Usage: ./ftpclient <server_address> <username> <password> <filename> <path>\n");
      return 1;
   }

   server_address = argv[1];
   username = argv[2];
   password = argv[3];
   filename = argv[4];
   path = argv[5];

   bzero(&servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(21);

   serverinfo = gethostbyname(server_address);

   if (serverinfo == NULL) {
      printf("ERROR: Could not resolve server address\n");
      return 1;
   }

   bcopy((char *)serverinfo->h_addr,
         (char *)&servaddr.sin_addr.s_addr,
         serverinfo->h_length);

   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0) {
      printf("ERROR: Could not create socket\n");
      return 1;
   }

   if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
      printf("ERROR: Could not connect to server\n");
      return 1;
   }

   strcpy(buffer, "USER ");
   strcat(buffer, username);
   strcat(buffer, "\r\n");

   bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

   if (bytes_sent < 0) {
      printf("ERROR: Failed to send username\n");
      return 1;
   }

   bzero(buffer, BUF_SIZE);
   bytes_rcv = recv(sockfd, buffer, BUF_SIZE-1, 0);

   if (bytes_rcv < 0) {
      printf("ERROR: Failed to receive response from server\n");
      return 1;
   }

   if (strncmp(buffer, "331", 3) != 0) {
      printf("ERROR: Invalid username\n");
      return 1;
   }

   strcpy(buffer, "PASS ");
   strcat(buffer, password);
   strcat(buffer, "\r\n");

   bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

   if (bytes_sent < 0) {
      printf("ERROR: Failed to send password\n");
      return 1;
   }

   bzero(buffer, BUF_SIZE);
   bytes_rcv = recv(sockfd, buffer, BUF_SIZE-1, 0);

   if (bytes_rcv < 0) {
      printf("ERROR: Failed to receive response from server\n");
      return 1;
   }

   if (strncmp(buffer, "230", 3) != 0) {
      printf("ERROR: Invalid password\n");
      return 1;
   }

   strcpy(buffer, "CWD ");
   strcat(buffer, path);
   strcat(buffer, "\r\n");

   bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

   if (bytes_sent < 0) {
      printf("ERROR: Failed to change directory\n");
      return 1;
   }

   bzero(buffer, BUF_SIZE);
   bytes_rcv = recv(sockfd, buffer, BUF_SIZE-1, 0);

   if (bytes_rcv < 0) {
      printf("ERROR: Failed to receive response from server\n");
      return 1;
   }

   if (strncmp(buffer, "250", 3) != 0) {
      printf("ERROR: Failed to change directory\n");
      return 1;
   }

   strcpy(buffer, "TYPE I\r\n");

   bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

   if (bytes_sent < 0) {
      printf("ERROR: Failed to set transfer mode to binary\n");
      return 1;
   }

   bzero(buffer, BUF_SIZE);
   bytes_rcv = recv(sockfd, buffer, BUF_SIZE-1, 0);

   if (bytes_rcv < 0) {
      printf("ERROR: Failed to receive response from server\n");
      return 1;
   }

   if (strncmp(buffer, "200", 3) != 0) {
      printf("ERROR: Failed to set transfer mode to binary\n");
      return 1;
   }

   strcpy(buffer, "RETR ");
   strcat(buffer, filename);
   strcat(buffer, "\r\n");

   bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

   if (bytes_sent < 0) {
      printf("ERROR: Failed to retrieve file\n");
      return 1;
   }

   bzero(buffer, BUF_SIZE);
   bytes_rcv = recv(sockfd, buffer, BUF_SIZE-1, 0);

   if (bytes_rcv < 0) {
      printf("ERROR: Failed to receive response from server\n");
      return 1;
   }

   if (strncmp(buffer, "150", 3) != 0) {
      printf("ERROR: Failed to retrieve file\n");
      return 1;
   }

   FILE * fp;
   fp = fopen(filename, "wb");

   if (fp == NULL) {
      printf("ERROR: Could not create file\n");
      return 1;
   }

   bzero(buffer, BUF_SIZE);
   bytes_rcv = recv(sockfd, buffer, BUF_SIZE-1, 0);

   while (bytes_rcv > 0) {
      fwrite(buffer, sizeof(char), bytes_rcv, fp);
      bzero(buffer, BUF_SIZE);
      bytes_rcv = recv(sockfd, buffer, BUF_SIZE-1, 0);
   }

   fclose(fp);

   bzero(buffer, BUF_SIZE);
   bytes_rcv = recv(sockfd, buffer, BUF_SIZE-1, 0);

   if (bytes_rcv < 0) {
      printf("ERROR: Failed to receive response from server\n");
      return 1;
   }

   if (strncmp(buffer, "226", 3) != 0) {
      printf("ERROR: Failed to retrieve file\n");
      return 1;
   }

   close(sockfd);

   return 0;
}