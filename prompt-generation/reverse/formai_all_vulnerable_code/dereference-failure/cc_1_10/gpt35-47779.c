//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

// Artistic style - using a maritime metaphor for our proxy:

// Before the main function, we define some ship-related structs, for our proxy has to navigate the seas of the internet.

typedef struct ship {
    int sock_fd;                    // socket file descriptor
    struct sockaddr_in my_addr;     // our address
    struct sockaddr_in their_addr;  // their address
} Ship;

typedef struct message {
    char *data;                     // message data
    int length;                     // message length
} Message;

// Set sail! In the main function we run our proxy.

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: ./proxy <port number>\n");
        return 1;
    }

    int port_num = atoi(argv[1]);

    // Create our ship and set up our address.

    Ship my_ship;
    my_ship.sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (my_ship.sock_fd < 0) {
        perror("ERROR creating socket");
        return 1;
    }
    memset(&my_ship.my_addr, 0, sizeof(my_ship.my_addr));
    my_ship.my_addr.sin_family = AF_INET;
    my_ship.my_addr.sin_addr.s_addr = INADDR_ANY;
    my_ship.my_addr.sin_port = htons(port_num);

    // Bind our ship to the given port and listen for incoming connections.

    if (bind(my_ship.sock_fd, (struct sockaddr *) &my_ship.my_addr, sizeof(my_ship.my_addr)) < 0) {
        close(my_ship.sock_fd);
        perror("ERROR binding socket");
        return 1;
    }
    listen(my_ship.sock_fd, 5);

    // Set up our message buffer

    char buffer[BUFFER_SIZE];
    
    // And now we wait for incoming ships to arrive!

    while (1) {

        printf("Awaiting incoming ship...\n");

        // Accept the incoming ship and set up their address.

        socklen_t their_addr_len = sizeof(my_ship.their_addr);
        int new_sock_fd = accept(my_ship.sock_fd, (struct sockaddr *) &my_ship.their_addr, &their_addr_len);
        if (new_sock_fd < 0) {
            perror("ERROR accepting incoming connection");
            continue;
        }

        // Print out the address of our visitor

        char* ip_addr_str = inet_ntoa(my_ship.their_addr.sin_addr);
        printf("Incoming ship has arrived from %s\n", ip_addr_str);

        // Read the incoming message.

        memset(buffer, 0, BUFFER_SIZE);
        int bytes_read = read(new_sock_fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            perror("ERROR reading from socket");
            continue;
        }

        // Display the message and send it on its way!

        printf("Message from incoming ship:\n%s\n", buffer);

        // Create our message and copy the data from the buffer.
        
        Message incoming_message;
        incoming_message.length = bytes_read;
        incoming_message.data = malloc(bytes_read);
        memcpy(incoming_message.data, buffer, bytes_read);

        // Write the message to the screen.

        printf("Outgoing message:\n%s\n", incoming_message.data);

        // Send the message out to sea and hope it reaches its destination!

        int bytes_written = write(new_sock_fd, incoming_message.data, incoming_message.length);
        if (bytes_written < 0) {
            perror("ERROR writing to socket");
        }

        // Clean up and wait for the next visitor.

        close(new_sock_fd);
        free(incoming_message.data);
    }

    return 0;
}