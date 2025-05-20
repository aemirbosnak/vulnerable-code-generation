//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Our brave little proxy, ready to conquer the digital wilderness!
typedef struct {
    int port;
    int sockfd;
    int clientfd;
    struct sockaddr_in addr;
} Proxy;

// Let's make some room for our proxy and its buddies
Proxy proxy;

// Time to set up our proxy's crib
int setup_proxy(int port) {
    // Creating the socket, like a proud parent welcoming a new baby into the world
    proxy.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy.sockfd == -1) {
        perror("Socket creation failed. Oops, looks like our baby proxy didn't make it.");
        return -1;
    }
    
    // Setting up the proxy's address, like giving it a cozy home to live in
    proxy.addr.sin_family = AF_INET;
    proxy.addr.sin_port = htons(port);
    proxy.addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Binding the socket to the address, like tying a leash to our eager puppy proxy
    if (bind(proxy.sockfd, (struct sockaddr*)&proxy.addr, sizeof(proxy.addr)) == -1) {
        perror("Bind failed. Uh-oh, our puppy proxy can't find its way home.");
        return -1;
    }

    // Listening for incoming connections, like a friendly dog wagging its tail
    if (listen(proxy.sockfd, 10) == -1) {
        perror("Listen failed. Looks like our puppy proxy is deaf, it can't hear the doorbell.");
        return -1;
    }
    return 0;
}

// Let's play the role of a matchmaker and connect our client to the wide world web
int handle_client(int clientfd) {
    char buffer[4096];
    int nbytes;

    // Reading the client's request, like a curious cat listening to its owner's secrets
    nbytes = read(clientfd, buffer, sizeof(buffer));
    if (nbytes == -1) {
        perror("Read failed. Oh no, our cat proxy couldn't understand the client's meows.");
        return -1;
    }
    
    // Parsing the HTTP request, like a detective solving a mystery
    char *host = strstr(buffer, "Host: ");
    if (host == NULL) {
        printf("Invalid HTTP request. Looks like our detective proxy needs more training.");
        return -1;
    }

    // Getting the hostname and port from the request, like a ninja extracting information from a secret scroll
    char *hostname = host + 6;
    char *port_str = strchr(hostname, ':');
    int port;
    if (port_str != NULL) {
        *port_str++ = '\0';
        port = atoi(port_str);
    } else {
        port = 80;
    }

    // Creating a socket to connect to the server, like a brave warrior setting out on a quest
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1) {
        perror("Socket creation failed. Oh no, our warrior proxy couldn't forge its sword.");
        return -1;
    }

    // Setting up the server's address, like giving our warrior a map to the castle
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connecting to the server, like our warrior finally reaching the castle gates
    if (connect(serverfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connect failed. It seems our warrior proxy got lost in the forest.");
        return -1;
    }

    // Sending the client's request to the server, like a messenger delivering a secret message
    if (write(serverfd, buffer, nbytes) == -1) {
        perror("Write failed. Looks like our messenger proxy tripped and dropped the message.");
        return -1;
    }

    // Reading the server's response, like a spy eavesdropping on a secret conversation
    while ((nbytes = read(serverfd, buffer, sizeof(buffer))) > 0) {
        // Sending the server's response back to the client, like a loyal servant relaying a message to its master
        if (write(clientfd, buffer, nbytes) == -1) {
            perror("Write failed. Oops, our servant proxy fumbled the response.");
            return -1;
        }
    }
    
    // Closing the server connection, like our warrior sheathing its sword after a victorious battle
    close(serverfd);
    return 0;
}

int main(int argc, char **argv) {
    // Checking if the user gave us a port number, like a picky eater asking for a specific dish
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return -1;
    }

    // Setting up our proxy, like a chef preparing a delicious meal
    if (setup_proxy(atoi(argv[1])) == -1) {
        return -1;
    }

    // Running the proxy, like a tireless waiter serving customers
    while (1) {
        // Accepting incoming connections, like a friendly host welcoming guests
        proxy.clientfd = accept(proxy.sockfd, NULL, NULL);
        if (proxy.clientfd == -1) {
            perror("Accept failed. Oh no, our host proxy couldn't open the door for the guests.");
            continue;
        }

        // Handling the client's requests, like a skilled barista making the perfect cup of coffee
        if (handle_client(proxy.clientfd) == -1) {
            close(proxy.clientfd);
            continue;
        }

        // Closing the client connection, like a polite guest saying goodbye
        close(proxy.clientfd);
    }

    // Closing the proxy's socket, like a tired chef turning off the lights at the end of the night
    close(proxy.sockfd);
    return 0;
}