//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    char response[BUFFER_SIZE];
    recv(sockfd, response, sizeof(response) - 1, 0);
    printf("Server: %s\n", response);
}

void email_to_heavens(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    
    // Here our fate is written, let false and true intertwine,
    // For we embark upon this quest of love divine.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Creating socket, alas, we find misfortune!");
        exit(EXIT_FAILURE);
    }
    
    host = gethostbyname(smtp_server);
    if (host == NULL) {
        perror("The stars do not align; unable to resolve hostname.");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    
    // A connection to the fated SMTP server we shall make,
    // The destiny of messages awaits—this, we stake.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Alas, the connection fails; lo, the heart is broken!");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    // The spark of conversation ignites with a welcome from the server,
    // Here within this digital realm, our passion shall never waver.
    send_command(sockfd, "EHLO localhost\r\n");
    
    // The emissary of love, the sender must now be declared.
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, cmd);
    
    // The recipient, sweet Juliet, we must now sing her name,
    snprintf(cmd, sizeof(cmd), "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, cmd);
    
    // The stages set, let not love's discourse fall into despair,
    // Henceforth, we shall begin the message, with ardor laid bare.
    send_command(sockfd, "DATA\r\n");
    
    // A love letter crafted with utmost care,
    // A subject to cast a lasting snare.
    snprintf(cmd, sizeof(cmd), 
             "Subject: %s\r\n"
             "From: %s\r\n"
             "To: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n", 
             subject, from, to, body);
    
    send(sockfd, cmd, strlen(cmd), 0);
    
    // As the final period draws near, so soon,
    // A message sent, perhaps to miss the moon.
    send_command(sockfd, "QUIT\r\n");

    // Sweet release obtained, close the socket, let us part,
    // With a heart filled with hope, and love like a dart.
    close(sockfd);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Specify your SMTP server
    const char *from = "romeo@verona.com";      // The sender of our love
    const char *to = "juliet@capulet.com";      // The object of our deep devotion
    const char *subject = "Ode to My Beloved";   // A title befitting of love
    const char *body = "My love is like a summer's day,\n"
                       "Soft and sweet, the sun's perfect ray.\n"
                       "Though trials may come, and fate may conspire,\n"
                       "My heart shall sing for you, my one desire.\n";
    
    // Thus begins our digital serenade,
    email_to_heavens(smtp_server, from, to, subject, body);

    return 0;
}