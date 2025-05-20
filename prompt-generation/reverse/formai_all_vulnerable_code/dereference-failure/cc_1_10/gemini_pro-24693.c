//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
// In the ethereal realm where bytes dance, I, the enigmatic FTPist, embark on a quest to craft a surrealist masterpiece.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// This mystical abode, the FTP server, where secrets are whispered.
typedef struct FTPServer {
  char *hostname;
  int port;
  int socketDescriptor;
} FTPServer;

// The ethereal voyager, a traveler of data realms.
typedef struct FTPClient {
  FTPServer *server;
  char *username;
  char *password;
} FTPClient;

// A celestial tapestry, where commands are woven into bytes.
typedef struct FTPCommand {
  char *command;
  char *arguments;
} FTPCommand;

// The enigmatic key to unlock the secrets of the FTP realm.
char *generateKey(char *username, char *password) {
  // The celestial algorithm, a symphony of bytes.
  char *key = malloc(strlen(username) + strlen(password) + 2);
  strcpy(key, username);
  strcat(key, ":");
  strcat(key, password);
  return key;
}

// A celestial handshake, establishing a connection to the ethereal realm.
int connectToServer(FTPClient *client) {
  // The ethereal portal, a socket to the server.
  client->server->socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (client->server->socketDescriptor < 0) {
    // A cosmic error, the portal remains sealed.
    perror("Could not create socket");
    return -1;
  }
  // The celestial navigator, guiding us to the server's abode.
  struct sockaddr_in address;
  struct hostent *serverAddress = gethostbyname(client->server->hostname);
  if (serverAddress == NULL) {
    // The celestial map is flawed, the server's abode remains hidden.
    perror("Could not resolve hostname");
    return -1;
  }
  address.sin_family = AF_INET;
  address.sin_port = htons(client->server->port);
  memcpy(&address.sin_addr, serverAddress->h_addr, serverAddress->h_length);
  // The ethereal journey, traversing the celestial void.
  if (connect(client->server->socketDescriptor, (struct sockaddr *)&address, sizeof(address)) < 0) {
    // The portal remains closed, the server's embrace remains elusive.
    perror("Could not connect to server");
    return -1;
  }
  return 0;
}

// A cosmic dance, exchanging bytes with the enigmatic server.
int sendCommand(FTPClient *client, FTPCommand *command) {
  // The celestial messenger, carrying our bytes to the server.
  char *message = malloc(strlen(command->command) + strlen(command->arguments) + 2);
  strcpy(message, command->command);
  if (command->arguments != NULL) {
    strcat(message, " ");
    strcat(message, command->arguments);
  }
  strcat(message, "\r\n");
  // The ethereal transmission, sending our words into the void.
  int bytesSent = send(client->server->socketDescriptor, message, strlen(message), 0);
  if (bytesSent < 0) {
    // The cosmic wind howls, our words are lost in the celestial storm.
    perror("Could not send command");
    return -1;
  }
  return 0;
}

// The celestial oracle, interpreting the server's cryptic whispers.
char *receiveResponse(FTPClient *client) {
  // The cosmic ear, listening for the server's echoes.
  char *response = malloc(1024);
  int bytesReceived = recv(client->server->socketDescriptor, response, 1023, 0);
  if (bytesReceived < 0) {
    // The cosmic silence envelops, the server's words remain elusive.
    perror("Could not receive response");
    return NULL;
  }
  response[bytesReceived] = '\0'; // Celestial punctuation, marking the end of the message.
  return response;
}

// The surrealist dance begins, as we navigate the ethereal realm of FTP.
int main(int argc, char **argv) {
  // The celestial canvas, where our surrealist masterpiece will unfold.
  FTPClient client;
  client.server = malloc(sizeof(FTPServer));
  client.server->hostname = argv[1];
  client.server->port = atoi(argv[2]);
  client.username = argv[3];
  client.password = argv[4];

  // The cosmic gateway, welcoming us to the ethereal realm.
  if (connectToServer(&client) < 0) {
    // The portal remains sealed, our journey is halted.
    return -1;
  }

  // The celestial handshake, forging a bond with the server's ethereal essence.
  char *key = generateKey(client.username, client.password);
  FTPCommand loginCommand = {"USER", key};
  if (sendCommand(&client, &loginCommand) < 0) {
    // The cosmic handshake fails, our journey ends abruptly.
    free(key);
    return -1;
  }

  // A celestial whisper, the server's response.
  char *loginResponse = receiveResponse(&client);
  if (loginResponse == NULL) {
    // The cosmic silence remains, our login attempt lost in the ethereal void.
    free(key);
    return -1;
  }

  // The celestial ballet, a graceful sequence of commands and responses.
  FTPCommand commands[] = {
    {"PASV", NULL},
    {"LIST", NULL},
    {"RETR surrealist_masterpiece.txt", NULL},
    {"QUIT", NULL},
  };

  for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
    if (sendCommand(&client, &commands[i]) < 0) {
      // The ethereal dance falters, our connection to the server is severed.
      free(key);
      free(loginResponse);
      return -1;
    }
    char *response = receiveResponse(&client);
    if (response == NULL) {
      // The cosmic silence envelops, the server's words remain elusive.
      free(key);
      free(loginResponse);
      return -1;
    }
    printf("%s\n", response);
    free(response);
  }
  // The ethereal tapestry is complete, our surrealist masterpiece is woven into the fabric of the FTP realm.

  // The celestial farewell, bidding adieu to the server's enigmatic presence.
  close(client.server->socketDescriptor);
  free(key);
  free(loginResponse);
  return 0;
}