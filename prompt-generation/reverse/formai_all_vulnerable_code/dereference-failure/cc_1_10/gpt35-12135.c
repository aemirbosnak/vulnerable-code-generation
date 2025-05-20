//FormAI DATASET v1.0 Category: Networking ; Style: statistical
// Statistical Networking Example Program

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {

    int client_socket;
    struct sockaddr_in server_address;
    char message[256];

    // create a TCP socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("ERROR: Could not create socket");
        exit(1);
    }

    // initialize the server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(8080);

    // connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("ERROR: Could not connect to server");
        exit(1);
    }

    // send a message to the server
    sprintf(message, "Hello, server! I am a client.");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("ERROR: Could not send message to server");
        exit(1);
    }

    // wait for a reply from the server
    if (recv(client_socket, message, 256, 0) == -1) {
        perror("ERROR: Could not receive message from server");
        exit(1);
    }

    // print the server's reply
    printf("Server replied: %s\n", message);

    // get random number of seconds to sleep
    srand(time(NULL));
    int seconds = rand() % 10 + 1;  // generate random number between 1 and 10
    printf("Client will sleep for %d seconds\n", seconds);
    sleep(seconds);

    // send another message to the server
    sprintf(message, "Goodbye, server! Thanks for chatting.");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("ERROR: Could not send message to server");
        exit(1);
    }

    // close the socket
    close(client_socket);

    return 0;
}