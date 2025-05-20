//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: curious
// Embark on a whimsical POP3 expedition with this code.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Greetings, fair adventurer! Prepare your vessel.
int sockfd;
struct sockaddr_in serveraddr;
char buffer[2048];

// Establish a magical connection to the POP3 realm.
int connect_to_server(char *hostname, int port) {
    // Cast the mystical incantation.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        // Alas, the connection spell failed.
        perror("Socket creation failed");
        return -1;
    }

    // Prepare the server's abode.
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = inet_addr(hostname);

    // Attempt to bridge the realms.
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        // The connection attempt has crumbled.
        perror("Connection failed");
        return -1;
    }

    return sockfd;
}

// Perform the ancient ritual of authentication.
int auth_user(char *username, char *password) {
    // Send the username incantation.
    sprintf(buffer, "USER %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        // The username incantation has failed.
        perror("Username sending failed");
        return -1;
    }
    // Receive the server's response.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        // The server's response has been lost.
        perror("Response receiving failed");
        return -1;
    }

    // Repeat the ritual for the password.
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        // The password incantation has failed.
        perror("Password sending failed");
        return -1;
    }
    // Seek the server's blessing once more.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        // The server's blessing has been withheld.
        perror("Response receiving failed");
        return -1;
    }

    // Check if the incantations were successful.
    if (strncmp(buffer, "+OK", 3) != 0) {
        return -1;
    }

    return 0;
}

// Retrieve the message count, a precious treasure.
int get_message_count() {
    // Send the message count inquiry.
    strcpy(buffer, "STAT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        // The message count inquiry has failed.
        perror("Message count inquiry sending failed");
        return -1;
    }

    // Await the server's revelation.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        // The server's revelation has been lost.
        perror("Response receiving failed");
        return -1;
    }

    // Extract the hidden treasure from the response.
    char *count_str = strstr(buffer, " ");
    if (!count_str) {
        return -1;
    }
    return atoi(count_str + 1);
}

// Retrieve the messages, the heart of the quest.
int get_messages(char *messages[], int message_count) {
    for (int i = 1; i <= message_count; i++) {
        // Request the message's contents.
        sprintf(buffer, "RETR %d\r\n", i);
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            // The message retrieval request has failed.
            perror("Message retrieval request sending failed");
            return -1;
        }

        // Receive the message in its entirety.
        char *message_start = NULL;
        char *message_end = NULL;
        int message_size = 0;
        while (1) {
            int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
            if (bytes_received <= 0) {
                // The message download has been interrupted.
                perror("Message receiving failed");
                return -1;
            }

            // Locate the start and end of the message.
            if (!message_start) {
                message_start = strstr(buffer, "\r\n\r\n");
            }
            message_end = strstr(buffer, "\r\n.\r\n");
            if (message_start && message_end) {
                message_size = message_end - message_start + 5;
                break;
            }
        }

        // Store the message in the provided array.
        messages[i - 1] = malloc(message_size);
        memcpy(messages[i - 1], message_start, message_size);
    }

    return 0;
}

// Close the portal to the POP3 realm.
void disconnect_from_server() {
    // Utter the closing incantation.
    strcpy(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Sever the connection.
    close(sockfd);
}

int main(int argc, char *argv[]) {
    // Check for the proper number of incantations (arguments).
    if (argc != 4) {
        printf("Usage: %s hostname port username password\n", argv[0]);
        return 1;
    }

    // Establish the connection to the POP3 realm.
    printf("Connecting to %s on port %s...\n", argv[1], argv[2]);
    int sockfd = connect_to_server(argv[1], atoi(argv[2]));
    if (sockfd < 0) {
        printf("Connection failed.\n");
        return 1;
    }

    // Authenticate with the POP3 realm's guardian.
    printf("Authenticating as %s...\n", argv[3]);
    int auth_result = auth_user(argv[3], argv[4]);
    if (auth_result < 0) {
        printf("Authentication failed.\n");
        disconnect_from_server();
        return 1;
    }

    // Retrieve the number of messages awaiting us.
    printf("Retrieving message count...\n");
    int message_count = get_message_count();
    if (message_count < 0) {
        printf("Could not retrieve message count.\n");
        disconnect_from_server();
        return 1;
    }
    printf("Found %d messages.\n", message_count);

    // Gather the messages, the treasures we seek.
    printf("Retrieving messages...\n");
    char *messages[message_count];
    int get_messages_result = get_messages(messages, message_count);
    if (get_messages_result < 0) {
        printf("Could not retrieve messages.\n");
        for (int i = 0; i < message_count; i++) {
            free(messages[i]);
        }
        disconnect_from_server();
        return 1;
    }

    // Display the messages, the culmination of our quest.
    for (int i = 0; i < message_count; i++) {
        printf("Message %d:\n", i + 1);
        printf("%s\n", messages[i]);
        free(messages[i]);
    }

    // Depart from the POP3 realm, leaving no trace behind.
    printf("Disconnecting from server...\n");
    disconnect_from_server();

    return 0;
}