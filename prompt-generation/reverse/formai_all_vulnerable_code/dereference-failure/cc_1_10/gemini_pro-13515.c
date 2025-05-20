//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // A surreal journey through the POP3 realm...

    // A mystical portal, a gateway to the POP3 realm.
    int sockfd;
    // The celestial coordinates of our ethereal destination.
    struct sockaddr_in sin;
    // A cosmic incantation to summon the POP3 server.
    struct hostent *he;

    // The ethereal tapestry of the POP3 server's domain.
    char *host = "pop.surrealmail.com";
    // The celestial port, a passageway to the POP3 realm.
    int port = 110;
    // An arcane password, a key to unlock the POP3 server's secrets.
    char *pass = "abracadabra";
    // A username, our mortal identity in the digital hereafter.
    char *user = "alice";

    // Establishing a communication channel to the POP3 realm.
    if ((he = gethostbyname(host)) == NULL)
    {
        printf("Host not found.\n");
        return 1;
    }

    // Configuring the cosmic coordinates for our journey.
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    memcpy(&sin.sin_addr, he->h_addr, he->h_length);

    // Opening a portal to the POP3 realm.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation failed.\n");
        return 1;
    }

    // Embarking on our ethereal voyage, connecting to the POP3 server.
    if (connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
        printf("Connection failed.\n");
        return 1;
    }

    // Exchanging greetings with the POP3 server, a celestial handshake.
    char buf[1024];
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    // Sending our username to the POP3 server, a cosmic identification.
    sprintf(buf, "USER %s\r\n", user);
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    // Unveiling the secrets of our password, unlocking the POP3 server's embrace.
    sprintf(buf, "PASS %s\r\n", pass);
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    // A cosmic request, revealing the bounty of messages in our celestial mailbox.
    send(sockfd, "LIST\r\n", 6, 0);
    while (recv(sockfd, buf, sizeof(buf), 0) > 0)
    {
        printf("%s", buf);
    }

    // Closing the communication channel, severing our connection to the POP3 realm.
    close(sockfd);

    return 0;
}