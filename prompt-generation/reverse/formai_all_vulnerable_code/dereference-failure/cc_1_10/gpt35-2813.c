//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER 1024
#define MAX_FILENAME 256
#define MIN_PORT 0
#define MAX_PORT 65535

// Function declarations
void ftp_client(int sockfd);
void send_file(int sockfd, char *filename);
void receive_file(int sockfd, char *filename);
int validate_port(char *port);

int main(int argc, char *argv[]) {

   // Check for argument count
   if (argc != 3) {
       printf("Usage: %s <Server IP Address> <Port Number>\n", argv[0]);
       exit(EXIT_FAILURE);
   }

   char *ip_address = argv[1];
   char *port = argv[2];

   // Validate port number
   int port_number = validate_port(port);

   // Create socket
   int sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd == -1) {
       perror("Socket creation failed");
       exit(EXIT_FAILURE);
   }

   // Set up server address struct
   struct sockaddr_in server_address;
   server_address.sin_family = AF_INET;
   server_address.sin_port = htons(port_number);
  
   if (inet_pton(AF_INET, ip_address, &server_address.sin_addr) <= 0) {
       perror("Invalid server IP address");
       exit(EXIT_FAILURE);
   }

   // Connect to server
   if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
       perror("Connection to server failed");
       exit(EXIT_FAILURE);
   }

   // Start FTP client
   ftp_client(sockfd);

   // Close socket
   close(sockfd);

   return 0;
}

void ftp_client(int sockfd) {

   char command[MAX_BUFFER];
   char *filename;

   while(1) {
       // Prompt user for command
       printf("Enter command (get <filename>, put <filename>, quit): ");
       fgets(command, MAX_BUFFER, stdin);

       // Parse command
       char *token = strtok(command, " ");
       if (strcmp(token, "get") == 0) {
           // Get filename
           filename = strtok(NULL, " \n");
           // Send command and filename to server
           write(sockfd, command, strlen(command));
           // Receive file from server
           receive_file(sockfd, filename);
       } else if (strcmp(token, "put") == 0) {
           // Get filename
           filename = strtok(NULL, " \n");
           // Send command and filename to server
           write(sockfd, command, strlen(command));
           // Send file to server
           send_file(sockfd, filename);
       } else if (strcmp(token, "quit") == 0) {
           // Send quit command to server
           write(sockfd, command, strlen(command));
           printf("Exiting FTP client\n");
           break;
       } else {
           printf("Invalid command\n");
       }
   }
}

void send_file(int sockfd, char *filename) {

   // Open file
   FILE *file = fopen(filename, "r");
   if (file == NULL) {
       printf("File not found\n");
       return;
   }

   // Allocate buffer for file data
   char buffer[MAX_BUFFER];

   // Read file data and send to server
   while (fgets(buffer, MAX_BUFFER, file) != NULL) {
       write(sockfd, buffer, strlen(buffer));
   }

   // Close file
   fclose(file);

   printf("File sent successfully\n");
}

void receive_file(int sockfd, char *filename) {

   // Open file
   FILE *file = fopen(filename, "w");
   if (file == NULL) {
       printf("Error creating file\n");
       return;
   }

   // Allocate buffer for file data
   char buffer[MAX_BUFFER];
   int bytes_received = 0;

   // Receive file data from server
   while ((bytes_received = read(sockfd, buffer, MAX_BUFFER)) > 0) {
       fwrite(buffer, 1, bytes_received, file);
   }

   // Close file
   fclose(file);

   printf("File received successfully\n");
}

int validate_port(char *port) {
    // Convert port to integer
    int port_number = atoi(port);

    // Check if port number is within range
    if (port_number < MIN_PORT || port_number > MAX_PORT) {
        printf("Invalid port number\n");
        exit(EXIT_FAILURE);
    }

    return port_number;
}