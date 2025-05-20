//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DRONE_CTL_DEV "/dev/drone_ctl"
#define DRONE_CTL_MAGIC 'd'
#define DRONE_CTL_TAKEOFF _IOW(DRONE_CTL_MAGIC, 0, int)
#define DRONE_CTL_LAND _IOW(DRONE_CTL_MAGIC, 1, int)
#define DRONE_CTL_UP _IOW(DRONE_CTL_MAGIC, 2, int)
#define DRONE_CTL_DOWN _IOW(DRONE_CTL_MAGIC, 3, int)
#define DRONE_CTL_LEFT _IOW(DRONE_CTL_MAGIC, 4, int)
#define DRONE_CTL_RIGHT _IOW(DRONE_CTL_MAGIC, 5, int)
#define DRONE_CTL_FORWARD _IOW(DRONE_CTL_MAGIC, 6, int)
#define DRONE_CTL_BACKWARD _IOW(DRONE_CTL_MAGIC, 7, int)
#define DRONE_CTL_TURN_LEFT _IOW(DRONE_CTL_MAGIC, 8, int)
#define DRONE_CTL_TURN_RIGHT _IOW(DRONE_CTL_MAGIC, 9, int)
#define DRONE_CTL_FLIP_FORWARD _IOW(DRONE_CTL_MAGIC, 10, int)
#define DRONE_CTL_FLIP_BACKWARD _IOW(DRONE_CTL_MAGIC, 11, int)
#define DRONE_CTL_FLIP_LEFT _IOW(DRONE_CTL_MAGIC, 12, int)
#define DRONE_CTL_FLIP_RIGHT _IOW(DRONE_CTL_MAGIC, 13, int)
#define DRONE_CTL_CALIBRATE _IOW(DRONE_CTL_MAGIC, 14, int)

int main(int argc, char **argv)
{
	int fd;
	int cmd;
	int arg;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s <command> <argument>\n", argv[0]);
		return EXIT_FAILURE;
	}

	cmd = atoi(argv[1]);
	arg = atoi(argv[2]);

	fd = open(DRONE_CTL_DEV, O_RDWR);
	if (fd < 0) {
		perror("open");
		return EXIT_FAILURE;
	}

	if (ioctl(fd, cmd, &arg) < 0) {
		perror("ioctl");
		return EXIT_FAILURE;
	}

	close(fd);

	return EXIT_SUCCESS;
}