//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <errno.h>
/*
 * Macros for the semaphore and shared memory.
 */
#define SEMKEY (key_t)15675
#define SHMKEY (key_t)15676

/*
 * The semaphore structure.
 */
union semun {
       int val;
       struct semid_ds *buf;
       unsigned short *array;
       struct seminfo *__buf;
};

/*
 * The shared memory structure.
 */
typedef struct {
       int mode;
       int lamp;
       int bright;
       int fridge;
       int aircon;
       int fan;
} house;

/*
 * The main function.
 */
int main(int argc, char *argv[]) {
       int semid, shmid;
       house *home;
       union semun arg;

       /*
        * Get the semaphore and shared memory identifiers.
        */
       semid = semget(SEMKEY, 1, 0666 | IPC_CREAT);
       shmid = shmget(SHMKEY, sizeof(house), 0666 | IPC_CREAT);
       if (semid < 0 || shmid < 0) {
               perror("semget or shmget failed");
               exit(1);
       }

       /*
        * Attach the shared memory to the address space of the process.
        */
       home = (house *)shmat(shmid, NULL, 0);
       if (home == (house *)-1) {
               perror("shmat failed");
               exit(1);
       }

       /*
        * Parse the command line arguments.
        */
       if (argc != 2) {
               fprintf(stderr, "Usage: %s <command>\n", argv[0]);
               exit(1);
       }

       /*
        * Process the command.
        */
       switch (argv[1][0]) {
               case 'm':
                       /*
                        * Change the mode of the house.
                        */
                       if (strcmp(argv[1], "mhome") == 0) {
                               home->mode = 0;
                       } else if (strcmp(argv[1], "maway") == 0) {
                               home->mode = 1;
                       } else {
                               fprintf(stderr, "Unknown mode: %s\n", argv[1]);
                               exit(1);
                       }
                       break;
               case 'l':
                       /*
                        * Turn the lamp on or off.
                        */
                       if (strcmp(argv[1], "lon") == 0) {
                               home->lamp = 1;
                       } else if (strcmp(argv[1], "loff") == 0) {
                               home->lamp = 0;
                       } else {
                               fprintf(stderr, "Unknown lamp command: %s\n", argv[1]);
                               exit(1);
                       }
                       break;
               case 'b':
                       /*
                        * Change the brightness of the lamp.
                        */
                       home->bright = atoi(argv[1] + 1);
                       if (home->bright < 0 || home->bright > 100) {
                               fprintf(stderr, "Invalid brightness: %s\n", argv[1]);
                               exit(1);
                       }
                       break;
               case 'f':
                       /*
                        * Turn the fridge on or off.
                        */
                       if (strcmp(argv[1], "fon") == 0) {
                               home->fridge = 1;
                       } else if (strcmp(argv[1], "foff") == 0) {
                               home->fridge = 0;
                       } else {
                               fprintf(stderr, "Unknown fridge command: %s\n", argv[1]);
                               exit(1);
                       }
                       break;
               case 'a':
                       /*
                        * Turn the air conditioner on or off.
                        */
                       if (strcmp(argv[1], "aon") == 0) {
                               home->aircon = 1;
                       } else if (strcmp(argv[1], "aoff") == 0) {
                               home->aircon = 0;
                       } else {
                               fprintf(stderr, "Unknown air conditioner command: %s\n", argv[1]);
                               exit(1);
                       }
                       break;
               case 'v':
                       /*
                        * Turn the fan on or off.
                        */
                       if (strcmp(argv[1], "von") == 0) {
                               home->fan = 1;
                       } else if (strcmp(argv[1], "voff") == 0) {
                               home->fan = 0;
                       } else {
                               fprintf(stderr, "Unknown fan command: %s\n", argv[1]);
                               exit(1);
                       }
                       break;
               default:
                       /*
                        * Unknown command.
                        */
                       fprintf(stderr, "Unknown command: %s\n", argv[1]);
                       exit(1);
       }

       /*
        * Unlock the semaphore.
        */
       arg.val = 1;
       if (semctl(semid, 0, SETVAL, arg) < 0) {
               perror("semctl failed");
               exit(1);
       }

       /*
        * Detach the shared memory from the address space of the process.
        */
       if (shmdt(home) < 0) {
               perror("shmdt failed");
               exit(1);
       }

       return 0;
}