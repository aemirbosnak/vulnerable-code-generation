//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: asynchronous
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include <errno.h>

#define BUFFER_SIZE 1024

int build_connection(char *ip_address, int port){
  int sock;
  struct sockaddr_in server_addr;
  struct hostent *he;

  if ((he = gethostbyname(ip_address)) == NULL) {
		herror("gethostbyname");
		exit(1);
	}

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
      perror(" socket call ");
      exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr = *((struct in_addr *)he->h_addr);
  memset(&(server_addr.sin_zero), '\0', 8);

  if (connect(sock, (struct sockaddr *)&server_addr,sizeof(struct sockaddr)) == -1) {
      perror("connect call");
      exit(1);
  }

  return sock;
}

void receive_data(int sock, char *response_buffer){
  struct timeval timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = 0;

	fd_set socket_set;
	FD_ZERO(&socket_set);
	FD_SET(sock, &socket_set);

	if (select(sock+1, &socket_set, NULL, NULL, &timeout) > 0 && FD_ISSET(sock, &socket_set)) {
    memset(response_buffer, 0, BUFFER_SIZE);
    recv(sock, response_buffer, BUFFER_SIZE, 0);
	}
}

void send_data(int sock, char *send_buffer){
  int send_length = strlen(send_buffer);

  if (send(sock, send_buffer, send_length, 0) != send_length) {
    perror("send call");
    exit(1);
  }
}

int main(int argc, char *argv[]){
  if(argc < 4){
    printf("Usage: %s [Server Address] [Server Port] [Username] [Password]\n", argv[0]);
    return 0;
  }

  char *server_address = argv[1];
  int server_port = atoi(argv[2]);
  char *username = argv[3];
  char *password = argv[4];

  int sock = build_connection(server_address, server_port);

  char buffer[BUFFER_SIZE];
  char response_buffer[BUFFER_SIZE];

  // Send the username to the server
  snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
  send_data(sock, buffer);

  receive_data(sock, response_buffer);
  printf(response_buffer);

  // Send the password to the server
  snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
  send_data(sock, buffer);

  receive_data(sock, response_buffer);
  printf(response_buffer);

  // List all the mails in the user's inbox
  send_data(sock, "LIST\r\n");

  receive_data(sock, response_buffer);
  printf(response_buffer);

  // Check if any mail is there
  if(response_buffer[0] == '+'){
    // Parse the mail ids from the server response
    int mail_count = 0;
    char *token;
    strtok(response_buffer, "\r\n");
    while((token = strtok(NULL, " ")) != NULL){
      printf("Mail id: %s\n", token);
      mail_count++;
    }

    // Download the first mail
    if(mail_count > 0){
      snprintf(buffer, BUFFER_SIZE, "RETR %s\r\n", strtok(response_buffer, " "));
      send_data(sock, buffer);

      receive_data(sock, response_buffer);
      printf(response_buffer);
    }
  }

  close(sock);
  return 0;
}