//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_HOSTS 1024

struct host {
	char *name;
	int port;
	int status;
	time_t last_checked;
};

struct host hosts[MAX_HOSTS];
int num_hosts = 0;

int sockfd;
struct sockaddr_in server_addr;

void sighandler(int signum)
{
	close(sockfd);
	exit(0);
}

int main(int argc, char *argv[])
{
	// Parse command line arguments
	if (argc < 3) {
		fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
		return 1;
	}
	char *host = argv[1];
	int port = atoi(argv[2]);

	// Create a socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("socket");
		return 1;
	}

	// Set up the server address
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(host);
	server_addr.sin_port = htons(port);

	// Connect to the server
	if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
		perror("connect");
		close(sockfd);
		return 1;
	}

	// Set up signal handler
	signal(SIGINT, sighandler);

	// Main loop
	while (1) {
		// Check the status of all hosts
		for (int i = 0; i < num_hosts; i++) {
			struct host *host = &hosts[i];

			// If the host has not been checked in the last 5 minutes, check it now
			if (time(NULL) - host->last_checked > 5 * 60) {
				int status = check_host(host->name, host->port);
				if (status != host->status) {
					// The host's status has changed
					host->status = status;
					printf("%s: %s\n", host->name, status == 0 ? "UP" : "DOWN");
				}
				host->last_checked = time(NULL);
			}
		}

		// Sleep for 1 minute
		sleep(60);
	}

	// Clean up
	close(sockfd);
	return 0;
}

int check_host(char *name, int port)
{
	// Create a socket
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("socket");
		return -1;
	}

	// Set up the server address
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(name);
	server_addr.sin_port = htons(port);

	// Connect to the server
	if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
		perror("connect");
		close(sockfd);
		return -1;
	}

	// Close the socket
	close(sockfd);

	// Return 0 if the host is up, -1 otherwise
	return 0;
}