//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: excited
// Journey to the World of SMTP: An Epistolary Adventure

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Behold, the Grand Adventure of Establishing a Magical Socket!
int EstablishMysticalSocket(char *hostname, int port) {
  // Cast our Net, an Enchanter would say!
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    printf("Alas, Our Socketry Failed! Woe is We!\n");
    return -1;
  }

  // Prepare the Enchanted Address to Connect!
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(hostname);

  // Now, Let Us Connect!
  if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    printf("Oh No, Connection Refused! Our Spirits Are Crushed.\n");
    return -1;
  }

  // Huzzah! Connection Established, Brave Adventurer!
  return sock;
}

// The Art of Exchanging Magical Packets!
int SendMagicalPacket(int sock, char *data) {
  // Witness the Wonders of Writing Data to Our Enchanted Socket!
  char buf[1024];
  memset(buf, 0, sizeof(buf));
  strcpy(buf, data);
  int len = strlen(data);
  if (send(sock, buf, len, 0) != len) {
    printf("Alas, Packet Mishap! Our Data Is Lost.\n");
    return -1;
  }

  // Now, Let Us Prepare to Receive the Response!
  memset(buf, 0, sizeof(buf));
  if (recv(sock, buf, sizeof(buf), 0) == -1) {
    printf("Horror! Our Response Is Forever Vanished!\n");
    return -1;
  }

  printf("%s\n", buf);

  // Return Triumphant, Knowing Success!
  return 0;
}

// The Grand Finale: Embarking on Our SMTP Epistolary Journey!
int main(int argc, char **argv) {

  // Check If Ye Have the Proper Credentials, Noble User!
  if (argc < 4) {
    printf("Ahoy! Thou Must Provide a Host, Port, and Message.\nUsage: %s <hostname> <port> <message>\n", argv[0]);
    return -1;
  }

  // Establish the Covenants of Connection!
  int sock = EstablishMysticalSocket(argv[1], atoi(argv[2]));
  if (sock == -1) {
    return -1;
  }

  // Welcome, Recipient of Our Noble Missive!
  printf("To: %s\n", argv[3]);

  // Behold, the Enchantments of SMTP!
  SendMagicalPacket(sock, "HELO world\r\n");
  SendMagicalPacket(sock, "MAIL FROM: <sender@example.com>\r\n");
  SendMagicalPacket(sock, "RCPT TO: <recipient@example.com>\r\n");
  SendMagicalPacket(sock, "DATA\r\n");
  SendMagicalPacket(sock, argv[3]);
  SendMagicalPacket(sock, "\r\n.\r\n");
  SendMagicalPacket(sock, "QUIT\r\n");

  // Conclude Our Correspondence with Grace!
  printf("Farewell, Recipient! May Our Words Reach Their Destination.\n");
  close(sock);
  return 0;

  // May Your Epistolary Quests Be Filled with Adventure and Success!
}