//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
# include <stdio.h>
# include <stdlib.h>

struct pole {
        int top; /* pole index of top disk */
        char *name; /* pole name */
        int *disks; /* array of disks on pole */
        int *avail; /* array of available disks on pole */
};

/* moves disk from one pole to another */
void move(struct pole *from, struct pole *to)
{
        /* move disk from top of 'from' to top of 'to' */
        to->disks[to->top++] = from->disks[from->top--];
}

/* prints disks on poles */
void show(struct pole *poles)
{
        int i, j;

        /* print poles */
        for (i = 0; i < 3; i++) {
                printf("%s: ", poles[i].name);
                /* print disks on pole */
                for (j = 0; j < poles[i].top; j++)
                        printf("%d ", poles[i].disks[j]);
                printf("\n");
        }
}

/* solves tower of hanoi problem */
void toh(struct pole *poles, int n)
{
        /* base case: move single disk from pole 1 to pole 3 */
        if (n == 1) {
                move(&poles[0], &poles[2]);
                return;
        }

        /* move n-1 disks from pole 1 to pole 2 */
        toh(poles, n-1);

        /* move remaining disk from pole 1 to pole 3 */
        move(&poles[0], &poles[2]);

        /* move n-1 disks from pole 2 to pole 3 */
        toh(poles, n-1);
}

/* initializes poles */
void init(struct pole *poles)
{
        int i, j;

        /* initialize pole 1 with n disks */
        poles[0].top = 0;
        poles[0].name = "Pole 1";
        poles[0].disks = malloc(sizeof(int) * 100);
        for (i = 0; i < 100; i++)
                poles[0].disks[i] = i+1;

        /* initialize pole 2 as empty */
        poles[1].top = 0;
        poles[1].name = "Pole 2";
        poles[1].disks = malloc(sizeof(int) * 100);

        /* initialize pole 3 as empty */
        poles[2].top = 0;
        poles[2].name = "Pole 3";
        poles[2].disks = malloc(sizeof(int) * 100);
}

/* frees memory allocated for poles */
void destroy(struct pole *poles)
{
        int i;

        /* free pole 1 disks */
        free(poles[0].disks);

        /* free pole 2 disks */
        free(poles[1].disks);

        /* free pole 3 disks */
        free(poles[2].disks);
}

int main(int argc, char *argv[])
{
        struct pole poles[3];
        int n;

        /* get number of disks */
        if (argc != 2) {
                printf("Usage: %s <number of disks>\n", argv[0]);
                exit(1);
        }
        n = atoi(argv[1]);

        /* initialize poles */
        init(poles);

        /* solve tower of hanoi problem */
        toh(poles, n);

        /* print poles */
        show(poles);

        /* free memory */
        destroy(poles);

        return 0;
}