//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

typedef struct thread_info {
	int sockfd;
	char *host;
	int port;
	int size;
	int duration;
} thread_info;

static void sighandler(int signo) {
	exit(0);
}

static void *thread_main(void *arg) {
	thread_info *info = (thread_info *)arg;
	int sockfd = info->sockfd;
	char *host = info->host;
	int port = info->port;
	int size = info->size;
	int duration = info->duration;
	clock_t start_time = clock();

	while (clock() - start_time < duration) {
		struct sockaddr_in serv_addr;
		memset(&serv_addr, 0, sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(port);
		serv_addr.sin_addr.s_addr = inet_addr(host);

		if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
			perror("connect");
			exit(1);
		}

		char *buffer = malloc(size);
		memset(buffer, 0, size);

		if (send(sockfd, buffer, size, 0) < 0) {
			perror("send");
			exit(1);
		}

		free(buffer);
		close(sockfd);
	}

	return NULL;
}

int main(int argc, char *argv[]) {
	if (argc < 6) {
		fprintf(stderr, "Usage: %s <host> <port> <size> <duration> <threads>\n", argv[0]);
		exit(1);
	}

	char *host = argv[1];
	int port = atoi(argv[2]);
	int size = atoi(argv[3]);
	int duration = atoi(argv[4]);
	int threads = atoi(argv[5]);

	signal(SIGINT, sighandler);

	pthread_t *tid = malloc(threads * sizeof(pthread_t));

	for (int i = 0; i < threads; i++) {
		thread_info *info = malloc(sizeof(thread_info));
		info->sockfd = socket(AF_INET, SOCK_STREAM, 0);
		info->host = host;
		info->port = port;
		info->size = size;
		info->duration = duration;
		pthread_create(&tid[i], NULL, thread_main, info);
	}

	for (int i = 0; i < threads; i++) {
		pthread_join(tid[i], NULL);
	}

	free(tid);

	return 0;
}