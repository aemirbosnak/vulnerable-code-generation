//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: peaceful
// Building a Peaceful FTP Client

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Serene Greeting
void welcome() {
    printf(
        "\n\t\t\t   _____ _ _     _   \n"
        "\t\t\t  / ____| (_)   | |  \n"
        "\t\t\t | (___ | |_    | |  \n"
        "\t\t\t  \\___ \\| | |   | |  \n"
        "\t\t\t  ____) | | |   | |  \n"
        "\t\t\t |_____/|_|_|   |_|  \n"
        "\t\t\t                       \n\n"
    );
    printf("\t\t\t\tTranquil FTP Client\n");
    printf("\t\t\t\tConnect and transfer files with serenity.\n\n");
}

// Establish a Harmonious Connection
int connect_to_server(const char *hostname, const char *port) {
    // Resolve the hostname to an IP address
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int status = getaddrinfo(hostname, port, &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return -1;
    }

    // Create a socket and connect to the server
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        freeaddrinfo(result);
        return -1;
    }

    status = connect(sockfd, result->ai_addr, result->ai_addrlen);
    if (status == -1) {
        perror("connect");
        close(sockfd);
        freeaddrinfo(result);
        return -1;
    }

    freeaddrinfo(result);
    return sockfd;
}

// Receive a Message with Grace
char *receive_message(int sockfd) {
    // Receive the message length
    int message_length;
    if (recv(sockfd, &message_length, sizeof(int), 0) == -1) {
        perror("recv");
        return NULL;
    }

    // Allocate memory for the message
    char *message = malloc(message_length + 1);
    if (message == NULL) {
        perror("malloc");
        return NULL;
    }

    // Receive the message
    if (recv(sockfd, message, message_length, 0) == -1) {
        perror("recv");
        free(message);
        return NULL;
    }

    message[message_length] = '\0';
    return message;
}

// Send a Message with Tranquility
int send_message(int sockfd, const char *message) {
    // Get the message length
    int message_length = strlen(message);

    // Send the message length
    if (send(sockfd, &message_length, sizeof(int), 0) == -1) {
        perror("send");
        return -1;
    }

    // Send the message
    if (send(sockfd, message, message_length, 0) == -1) {
        perror("send");
        return -1;
    }

    return 0;
}

// List Files with Serenity
void list_files(int sockfd) {
    // Send the LIST command
    if (send_message(sockfd, "LIST") == -1) {
        fprintf(stderr, "Error sending LIST command\n");
        return;
    }

    // Receive the file list
    char *file_list = receive_message(sockfd);
    if (file_list == NULL) {
        fprintf(stderr, "Error receiving file list\n");
        return;
    }

    // Print the file list
    printf("Files:\n%s\n", file_list);
    free(file_list);
}

// Retrieve a File with Tranquility
void retrieve_file(int sockfd, const char *filename) {
    // Send the RETR command
    if (send_message(sockfd, "RETR") == -1) {
        fprintf(stderr, "Error sending RETR command\n");
        return;
    }

    // Send the filename
    if (send_message(sockfd, filename) == -1) {
        fprintf(stderr, "Error sending filename\n");
        return;
    }

    // Receive the file size
    int file_size;
    if (recv(sockfd, &file_size, sizeof(int), 0) == -1) {
        perror("recv");
        return;
    }

    // Allocate memory for the file
    char *file_buffer = malloc(file_size);
    if (file_buffer == NULL) {
        perror("malloc");
        return;
    }

    // Receive the file
    if (recv(sockfd, file_buffer, file_size, 0) == -1) {
        perror("recv");
        free(file_buffer);
        return;
    }

    // Write the file to disk
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("fopen");
        free(file_buffer);
        return;
    }
    fwrite(file_buffer, 1, file_size, file);
    fclose(file);

    free(file_buffer);
    printf("File '%s' retrieved.\n", filename);
}

// Handle User Input with Serenity
void handle_user_input(int sockfd) {
    char command[100];
    char filename[100];

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        // Remove the newline character from the command
        command[strcspn(command, "\n")] = '\0';

        // Parse the command
        if (strcmp(command, "LIST") == 0) {
            list_files(sockfd);
        } else if (strcmp(command, "RETR") == 0) {
            printf("Enter the filename to retrieve: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = '\0';
            retrieve_file(sockfd, filename);
        } else if (strcmp(command, "QUIT") == 0) {
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }
}

int main(int argc, char **argv) {
    // Meditate on the arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Welcome the user with serenity
    welcome();

    // Connect to the server with grace
    int sockfd = connect_to_server(argv[1], argv[2]);
    if (sockfd == -1) {
        fprintf(stderr, "Error connecting to server\n");
        return 1;
    }

    // Handle user input with tranquility
    handle_user_input(sockfd);

    // Close the connection with serenity
    close(sockfd);

    return 0;
}