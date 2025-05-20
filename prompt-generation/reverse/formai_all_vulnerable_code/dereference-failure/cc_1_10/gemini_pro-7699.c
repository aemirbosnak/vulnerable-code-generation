//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	FILE *fp;
	char buf[1024];
	int i, pid;

	fp = fopen("/proc/sys/kernel/pid_max", "r");
	if (fp == NULL) {
		perror("fopen");
		return -1;
	}

	fgets(buf, sizeof(buf), fp);
	fclose(fp);

	pid = atoi(buf);

	printf("PID\tPPID\tSTAT\tCMD\n");
	for (i = 1; i <= pid; i++) {
		sprintf(buf, "/proc/%d/stat", i);
		fp = fopen(buf, "r");
		if (fp == NULL) {
			continue;
		}

		fgets(buf, sizeof(buf), fp);
		fclose(fp);

		char *p = strtok(buf, " ");
		printf("%s\t", p);

		p = strtok(NULL, " ");
		printf("%s\t", p);

		p = strtok(NULL, " ");
		printf("%c\t", p[0]);

		p = strtok(NULL, "\n");
		printf("%s\n", p);
	}

	return 0;
}