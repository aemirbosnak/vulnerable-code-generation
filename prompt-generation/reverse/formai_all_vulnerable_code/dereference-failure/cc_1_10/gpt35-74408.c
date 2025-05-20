//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[])
{
   int sock_fd, num_bytes;
   char buffer[MAX_BUFF_SIZE], username[MAX_BUFF_SIZE], password[MAX_BUFF_SIZE];
   struct addrinfo hints, *servinfo, *p;

   memset(&hints, 0, sizeof(hints));
   hints.ai_family = AF_UNSPEC;
   hints.ai_socktype = SOCK_STREAM;

   if(argc != 3) {
      fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
      return 1;
   }

   if(getaddrinfo(argv[1], argv[2], &hints, &servinfo) != 0) {
      fprintf(stderr, "getaddrinfo error\n");
      return 1;
   }

   for(p = servinfo; p != NULL; p = p->ai_next) {

      if((sock_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
         fprintf(stderr, "socket error\n");
         continue;
      }

      if(connect(sock_fd, p->ai_addr, p->ai_addrlen) == -1) {
         close(sock_fd);
         fprintf(stderr, "connect error\n");
         continue;
      }

      break;
   }

   if(p == NULL) {
      fprintf(stderr, "failed to connect\n");
      return 1;
   }

   freeaddrinfo(servinfo);

   printf("Username: ");
   fgets(username, MAX_BUFF_SIZE, stdin);

   printf("Password: ");
   fgets(password, MAX_BUFF_SIZE, stdin);

   sprintf(buffer, "LOGIN %s %s\n", username, password);
   write(sock_fd, buffer, strlen(buffer));

   memset(buffer, 0, sizeof(buffer));
   num_bytes = read(sock_fd, buffer, MAX_BUFF_SIZE-1);

   printf("%.*s\n", num_bytes, buffer);

   sprintf(buffer, "SELECT INBOX\n");
   write(sock_fd, buffer, strlen(buffer));

   memset(buffer, 0, sizeof(buffer));
   num_bytes = read(sock_fd, buffer, MAX_BUFF_SIZE-1);

   printf("%.*s\n", num_bytes, buffer);

   sprintf(buffer, "SEARCH ALL\n");
   write(sock_fd, buffer, strlen(buffer));

   memset(buffer, 0, sizeof(buffer));
   num_bytes = read(sock_fd, buffer, MAX_BUFF_SIZE-1);

   printf("%.*s\n", num_bytes, buffer);

   close(sock_fd);

   return 0;
}