//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: inquisitive
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    // What port shall we use for this inquisitive adventure?
    // If no port was given, let's use the default port for HTTP: 80
    int port = (argc >= 2) ? atoi(argv[1]) : 80;

    // Welcome to our inquisitive chat room!
    printf("Greetings, fellow inquisitor! Welcome to our interactive TCP/IP playground.\n");

    // Let's establish a connection with the server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Where in the vast internet realm shall we connect to?
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, argv[2], &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Time to knock on the server's door and introduce ourselves.
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Here comes the inquisitive part!
    char buffer[1024];
    while (1) {
        printf("Type your inquisitive query, or type 'exit' to bid farewell: ");
        fgets(buffer, 1024, stdin);

        // Let's trim any trailing newline characters.
        buffer[strcspn(buffer, "\n")] = '\0';

        // Are we saying goodbye?
        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        // Send our query to the server.
        write(sockfd, buffer, strlen(buffer));

        // Curious to hear what the server has to say.
        int n = read(sockfd, buffer, 1024);
        buffer[n] = '\0';

        // And here's the server's response!
        printf("Server's response: %s\n\n", buffer);
    }

    // Time to wrap up our inquisitive adventure.
    close(sockfd);

    // Farewell, inquisitive traveler!
    printf("Thank you for your curiosity. Farewell!\n");

    return 0;
}