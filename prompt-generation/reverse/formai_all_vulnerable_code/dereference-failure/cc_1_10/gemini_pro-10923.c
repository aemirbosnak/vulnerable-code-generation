//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

// A heartfelt welcome message to our FTP rendezvous
void greetUser() {
    printf("My dearest, welcome to our FTP escapade! Let us embark on a journey of data exchange.\n");
}

// A graceful farewell message as we bid adieu to our FTP adventure
void bidFarewell() {
    printf("Alas, our FTP rendezvous must come to an end. May your data travels be filled with joy and success.\n");
}

// A utility function to establish a connection with the desired FTP server
int connectToServer(char* hostname, int port) {
    struct sockaddr_in serverAddress;
    int socketDescriptor;

    // Resolve the hostname to its IP address
    struct hostent* hostEntry = gethostbyname(hostname);
    if (hostEntry == NULL) {
        printf("Alas, my love, I could not resolve the hostname '%s'. Are you sure it's correct?\n", hostname);
        return -1;
    }
    memcpy(&serverAddress.sin_addr, hostEntry->h_addr_list[0], hostEntry->h_length);

    // Configure the server address
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    // Create a socket for communication
    socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketDescriptor < 0) {
        printf("My darling, I encountered an issue creating our socket. Are the network gods not smiling upon us today?\n");
        return -1;
    }

    // Connect to the FTP server
    if (connect(socketDescriptor, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        printf("Oh woe is me! I failed to establish a connection with the FTP server. Is it perchance offline?\n");
        return -1;
    }

    // Return the socket descriptor for further communication
    return socketDescriptor;
}

// A helper function to send a command to the FTP server and receive its response
char* sendCommand(int socketDescriptor, char* command) {
    char* response = malloc(1024);
    int bytesReceived;

    // Send the command
    if (send(socketDescriptor, command, strlen(command), 0) < 0) {
        printf("Alas, my love, I encountered an issue sending the command '%s' to the FTP server.\n", command);
        free(response);
        return NULL;
    }

    // Receive the response
    bytesReceived = recv(socketDescriptor, response, 1023, 0);
    if (bytesReceived < 0) {
        printf("Oh woe is me! I failed to receive a response from the FTP server for command '%s'.\n", command);
        free(response);
        return NULL;
    }

    // Null-terminate the response
    response[bytesReceived] = '\0';

    // Return the response
    return response;
}

// The main function, where our FTP adventure begins
int main(int argc, char** argv) {
    int socketDescriptor;
    char* response;
    char command[1024];

    // Greet the user with a touch of romance
    greetUser();

    // Ensure the user provides the necessary arguments
    if (argc != 3) {
        printf("My dearest, it appears you have forgotten to specify the hostname and port of the FTP server. Please try again with the following format:\n%s <hostname> <port>", argv[0]);
        return -1;
    }

    // Establish a connection with the FTP server
    socketDescriptor = connectToServer(argv[1], atoi(argv[2]));
    if (socketDescriptor < 0) {
        return -1;
    }

    // Receive the initial server response
    response = sendCommand(socketDescriptor, "USER anonymous\n");
    if (response == NULL) {
        close(socketDescriptor);
        return -1;
    }
    printf("The FTP server responds with: %s", response);
    free(response);

    // Send a password command, typically not required for anonymous login
    response = sendCommand(socketDescriptor, "PASS myemail@example.com\n");
    if (response == NULL) {
        close(socketDescriptor);
        return -1;
    }
    printf("The FTP server responds with: %s", response);
    free(response);

    // Enter the FTP command loop
    while (1) {
        // Prompt the user for a command
        printf("My love, what command shall we send to the FTP server? (Type 'quit' to end our rendezvous)\n");
        scanf("%s", command);

        // Send the command to the server
        response = sendCommand(socketDescriptor, strcat(command, "\n"));
        if (response == NULL) {
            close(socketDescriptor);
            return -1;
        }

        // Display the server's response
        printf("The FTP server responds with: %s", response);
        free(response);

        // Check if the user wants to quit
        if (strcmp(command, "quit") == 0) {
            break;
        }
    }

    // Close the connection to the FTP server
    close(socketDescriptor);

    // Bid farewell to the user with a touch of sentiment
    bidFarewell();

    return 0;
}