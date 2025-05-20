//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

typedef struct {
  char name[50];
  char surname[50];
  char email[100];
} knight_t;

typedef struct {
  int socket_desc;
  struct sockaddr_in server;
} client;

void create_knight(knight_t *knight, char *name, char *surname, char *email) {
  strcpy(knight->name, name);
  strcpy(knight->surname, surname);
  strcpy(knight->email, email);
}

void connect_to_server(client *client, char *ip, int port) {
  client->socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  client->server.sin_family = AF_INET;
  client->server.sin_port = htons(port);
  inet_pton(AF_INET, ip, &client->server.sin_addr);

  if (connect(client->socket_desc, (struct sockaddr *)&client->server, sizeof(client->server)) < 0) {
    perror("Could not connect to server");
    exit(1);
  }
}

void send_email(client *client, knight_t *knight) {
  char message[200];
  sprintf(message, "From: %s %s <%s>\r\nTo: your_email@kingdom.com\r\nSubject: New Email\r\n\r\nMessage: %s, %s is in need of your wisdom and assistance.\r\n",
          knight->name, knight->surname, knight->email, knight->name, knight->surname);

  send(client->socket_desc, message, strlen(message), 0);
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <name> <surname> <email>\n", argv[0]);
    return 1;
  }

  knight_t knight;
  create_knight(&knight, argv[1], argv[2], argv[3]);

  client client;
  char ip[] = "127.0.0.1";
  int port = 12345;
  connect_to_server(&client, ip, port);

  send_email(&client, &knight);

  close(client.socket_desc);
  return 0;
}