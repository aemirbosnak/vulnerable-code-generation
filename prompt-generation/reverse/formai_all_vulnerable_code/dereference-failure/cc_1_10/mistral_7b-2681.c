//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MEW "Mew\n"
#define GRRR "Grrr\n"

typedef struct {
    char name[50];
    int hungerLevel;
} Cat;

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int fd;
    char filename[50];
    int i;
    int numCats;
    Cat *catArray;

    if (argc < 2) {
        printf("Usage: %s <number_of_cats>\n", argv[0]);
        return 1;
    }

    numCats = atoi(argv[1]);

    catArray = malloc(numCats * sizeof(Cat));

    for (i = 0; i < numCats; i++) {
        sprintf(filename, "cat%d.txt", i + 1);
        fd = open(filename, O_RDONLY);

        read(fd, catArray[i].name, sizeof(catArray[i].name));
        close(fd);

        catArray[i].hungerLevel = rand() % 10 + 1;
        printf("Name: %s, Hunger Level: %d\n", catArray[i].name, catArray[i].hungerLevel);
    }

    while (1) {
        for (i = 0; i < numCats; i++) {
            if (catArray[i].hungerLevel > 5) {
                printf("%s %s\n", MEW, catArray[i].name);
                sleep(1);

                int j;
                int foodIndex;

                for (j = 0; j < numCats; j++) {
                    if (catArray[j].hungerLevel <= 2) {
                        foodIndex = j;
                        break;
                    }
                }

                if (foodIndex == -1) {
                    continue;
                }

                printf("%s %s\n", GRRR, catArray[i].name);
                printf("%s %s\n", MEW, catArray[foodIndex].name);
                catArray[i].hungerLevel -= 3;
                catArray[foodIndex].hungerLevel += 3;
                sleep(1);
            }
        }
    }

    free(catArray);

    return 0;
}