//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Sherlock Holmes
// It was a dark and stormy night, and our protagonist, the IMAP Client, set out on a mission to find some emails

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 993

int main(int argc, char *argv[]) {
  // The Client eyed the keyboard, its fingers poised to begin the quest
  char buffer[1024];
  struct sockaddr_in server_addr;
  struct hostent *server;
  int sockfd, count;

  // First, the Client must connect to the server
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "ERROR: Could not create socket\n");
    exit(1);
  }
  server = gethostbyname("imap.example.com");
  if (server == NULL) {
    fprintf(stderr, "ERROR: Could not find server\n");
    exit(1);
  }
  memset((char *)&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
  server_addr.sin_port = htons(PORT);
  if (connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
    fprintf(stderr, "ERROR: Could not connect to server\n");
    exit(1);
  }

  // With a successful connection, the Client waits for the server's greeting
  count = read(sockfd, buffer, sizeof(buffer)-1);
  if (count < 0) {
    fprintf(stderr, "ERROR: Could not read from socket\n");
    exit(1);
  }
  buffer[count] = 0;
  printf("%s\n", buffer);

  // Now the real quest begins - logging in
  char username[] = "your_username";
  char password[] = "your_password";
  char login_command[1024];
  
  sprintf(login_command, "tag1 LOGIN %s %s\n", username, password);
  count = write(sockfd, login_command, strlen(login_command));
  if (count < 0) {
    fprintf(stderr, "ERROR: Could not write to socket\n");
    exit(1);
  }

  count = read(sockfd, buffer, sizeof(buffer)-1);
  if (count < 0) {
    fprintf(stderr, "ERROR: Could not read from socket\n");
    exit(1);
  }
  buffer[count] = 0;
  printf("%s\n", buffer);

  // Finally, the Client is ready to receive some emails!
  char select_command[] = "tag2 SELECT inbox\n";
  count = write(sockfd, select_command, strlen(select_command));
  if (count < 0) {
    fprintf(stderr, "ERROR: Could not write to socket\n");
    exit(1);
  }

  count = read(sockfd, buffer, sizeof(buffer)-1);
  if (count < 0) {
    fprintf(stderr, "ERROR: Could not read from socket\n");
    exit(1);
  }
  buffer[count] = 0;
  printf("%s\n", buffer);

  // And that's it! The Client has completed its quest.
  close(sockfd);
  return 0;
}