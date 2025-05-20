//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>

typedef struct {
	int fd;
	char *name;
	char *ip;
	int port;
	int state;
	int time;
} traffic_light;

traffic_light traffic_lights[] = {
	{ 0, "Red", "127.0.0.1", 8000, 0, 30 },
	{ 0, "Yellow", "127.0.0.1", 8001, 0, 5 },
	{ 0, "Green", "127.0.0.1", 8002, 0, 60 },
};

void sig_int(int signo) {
	for (int i = 0; i < sizeof(traffic_lights) / sizeof(traffic_lights[0]); i++) {
		if (traffic_lights[i].fd > 0) {
			close(traffic_lights[i].fd);
		}
	}
	exit(0);
}

void set_state(traffic_light *tl, int state) {
	tl->state = state;
	write(tl->fd, &state, sizeof(state));
}

int main() {
	signal(SIGINT, sig_int);
	for (int i = 0; i < sizeof(traffic_lights) / sizeof(traffic_lights[0]); i++) {
		traffic_light *tl = &traffic_lights[i];
		tl->fd = socket(AF_INET, SOCK_STREAM, 0);
		if (tl->fd < 0) {
			fprintf(stderr, "socket error: %s\n", strerror(errno));
			exit(1);
		}
		struct sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr(tl->ip);
		addr.sin_port = htons(tl->port);
		if (connect(tl->fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
			fprintf(stderr, "connect error: %s\n", strerror(errno));
			exit(1);
		}
		set_state(tl, 0);
	}
	while (true) {
		for (int i = 0; i < sizeof(traffic_lights) / sizeof(traffic_lights[0]); i++) {
			traffic_light *tl = &traffic_lights[i];
			if (tl->time > 0) {
				tl->time--;
			}
			if (tl->time == 0) {
				set_state(tl, 0);
				if (i == sizeof(traffic_lights) / sizeof(traffic_lights[0]) - 1) {
					i = 0;
				} else {
					i++;
				}
				tl = &traffic_lights[i];
				set_state(tl, 1);
				tl->time = tl->state;
			}
		}
		sleep(1);
	}
	return 0;
}