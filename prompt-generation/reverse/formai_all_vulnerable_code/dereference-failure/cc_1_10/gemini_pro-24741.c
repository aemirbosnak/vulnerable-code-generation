//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: post-apocalyptic
// In the desolate wasteland, a lone wanderer seeks to breach the silence.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

// A message for the unknown receiver, scrawled on a tattered scroll.
#define MESSAGE "Greetings from the ruins!"

int main() {
  // Establish a beacon of connection in the desolate void.
  struct sockaddr_in server;
  struct hostent *host;

  // Seek the lair of the SMTP beast.
  host = gethostbyname("smtp.example.com");
  if (host == NULL) {
    printf("Host not found. Try a different wasteland.\n");
    return -1;
  }

  // Craft the socket, a lifeline in the desolate expanse.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Socket creation failed. Despair consumes us.\n");
    return -1;
  }

  // Guide the socket to the SMTP lair.
  server.sin_family = AF_INET;
  memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);
  server.sin_port = htons(25);

  // Attempt to breach the fortifications of the SMTP server.
  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Connection failed. The SMTP stronghold remains impenetrable.\n");
    return -1;
  }

  // Initiate a dialogue with the SMTP warden.
  char buffer[1024];

  // Begin the ritual, a forgotten incantation from a lost era.
  recv(sockfd, buffer, 1024, 0);
  printf("%s\n", buffer);
  
  // Identify ourselves as weary wanderers seeking solace.
  sprintf(buffer, "HELO wasteland\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, 1024, 0);
  printf("%s\n", buffer);

  // Prepare to unveil the hidden message.
  sprintf(buffer, "MAIL FROM: wanderer@wasteland.com\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, 1024, 0);
  printf("%s\n", buffer);

  // Specify the intended recipients, those who yearn for our words.
  sprintf(buffer, "RCPT TO: survivor@ruins.com\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, 1024, 0);
  printf("%s\n", buffer);

  // Unleash the message, a beacon of hope amidst the desolation.
  sprintf(buffer, "DATA\n%s\n.\n", MESSAGE);
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, 1024, 0);
  printf("%s\n", buffer);

  // Conclude the transmission, leaving behind a whisper in the digital wilderness.
  sprintf(buffer, "QUIT\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, 1024, 0);
  printf("%s\n", buffer);

  // Seal the connection, severing the link to the SMTP stronghold.
  close(sockfd);

  return 0;
}