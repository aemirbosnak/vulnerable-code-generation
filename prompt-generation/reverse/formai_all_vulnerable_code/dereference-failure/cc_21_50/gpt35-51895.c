//FormAI DATASET v1.0 Category: Chat server ; Style: configurable
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h>

#define PORT 8080 
#define MAX_CLIENTS 5

int main() 
{ 
	int server_fd, new_socket, valread, client_sockets[MAX_CLIENTS]; 
	struct sockaddr_in address; 
	int opt = 1; 
	int addrlen = sizeof(address); 
	char buffer[1024] = {0};

	for (int i = 0; i < MAX_CLIENTS; i++) {
		client_sockets[i] = 0;
	}

	// Create socket file descriptor 
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	{ 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 

	// Set socket options 
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
	{ 
		perror("setsockopt failed"); 
		exit(EXIT_FAILURE); 
	} 

	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons( PORT ); 

	// Bind the socket to the specified port 
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 

	// Listen to the socket for incoming connections 
	if (listen(server_fd, 3) < 0) 
	{ 
		perror("listen failed"); 
		exit(EXIT_FAILURE); 
	} 

	// Wait for incoming connections 
	while(1) {
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
		{ 
			perror("accept failed"); 
			exit(EXIT_FAILURE); 
		}
		
		// Add the new client socket to the list of client sockets 
		for (int i = 0; i < MAX_CLIENTS; i++) {
			if (client_sockets[i] == 0) {
				client_sockets[i] = new_socket;
				break;
			}
		}

		// Listen to incoming messages from clients 
		while(1) {
			fd_set readfds;
			FD_ZERO(&readfds); 

			// Add the client sockets to the set 
			for (int i = 0; i < MAX_CLIENTS; i++) {
				if (client_sockets[i] > 0) {
					FD_SET(client_sockets[i], &readfds);
				}
			}

			// Wait for activity on the set of client sockets 
			int max_sd = 0;
			for (int i = 0; i < MAX_CLIENTS; i++) {
				if (client_sockets[i] > max_sd) {
					max_sd = client_sockets[i];
				}
			}

			if (select(max_sd + 1, &readfds, NULL, NULL, NULL) < 0) {
				perror("select failed");
				exit(EXIT_FAILURE);
			}

			// Handle activity on the set of client sockets 
			for (int i = 0; i < MAX_CLIENTS; i++) {
				int client_socket = client_sockets[i];
				if (FD_ISSET(client_socket, &readfds)) {
					valread = read(client_socket, buffer, 1024); 
					if (valread == 0) {
						close(client_socket);
						client_sockets[i] = 0;
					} else {
						for (int j = 0; j < MAX_CLIENTS; j++) {
							int dest_socket = client_sockets[j];
							if (dest_socket != 0 && dest_socket != client_socket) {
								send(dest_socket, buffer, strlen(buffer), 0);
							}
						}
					}
				}
			}
		}
	} 

	return 0; 
}