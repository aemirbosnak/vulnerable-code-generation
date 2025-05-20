//FormAI DATASET v1.0 Category: Interprocess communication ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27	// shared memory size

int main(void)
{
	char c;
	int shmid;
	key_t key;
	char *shm, *s;

	// get a key for our shared memory segment
	key = 5678;

	// create the segment
	if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(1);
	}

	// attach to the segment
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		perror("shmat");
		exit(1);
	}

	// now we put some data into the memory segment
	s = shm;
	for (c = 'a'; c <= 'z'; c++)
		*s++ = c;
	*s = '\0';

	// now fork a child process to read from the segment
	if (fork() == 0) {
		// we're the child process, so we can read
		// from the segment
		for (s = shm; *s != '\0'; s++)
			putchar(*s);
		putchar('\n');

		// detach from the segment
		if (shmdt(shm) == -1) {
			perror("shmdt");
			exit(1);
		}

		// exit with success status
		exit(0);
	} else {
		// parent process waits for child to finish
		wait(NULL);

		// now we can remove the segment
		if (shmctl(shmid, IPC_RMID, 0) == -1) {
			perror("shmctl");
			exit(1);
		}
	}

	return 0;
}