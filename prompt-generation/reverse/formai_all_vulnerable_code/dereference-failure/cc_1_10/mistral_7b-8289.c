//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_ALIENS 10
#define NUM_SATELLITES 20

typedef struct {
    int id;
    int detection_range;
} Satellite;

typedef struct {
    int id;
    int attack_power;
} Alien;

void initialize_satellites(Satellite* satellites) {
    for (int i = 0; i < NUM_SATELLITES; i++) {
        satellites[i].id = i + 1;
        satellites[i].detection_range = rand() % 5 + 1;
    }
}

void initialize_aliens(Alien* aliens) {
    for (int i = 0; i < NUM_ALIENS; i++) {
        aliens[i].id = i + 1;
        aliens[i].attack_power = rand() % 10 + 1;
    }
}

int detect_aliens(Satellite* satellites, Alien* aliens, int num_aliens) {
    int num_detected = 0;

    for (int i = 0; i < num_aliens; i++) {
        for (int j = 0; j < NUM_SATELLITES; j++) {
            if (aliens[i].id < satellites[j].detection_range) {
                printf("Satellite %d detected Alien %d!\n", satellites[j].id, aliens[i].id);
                num_detected++;
                break;
            }
        }
    }

    return num_detected;
}

int main() {
    srand(time(NULL));

    Satellite satellites[NUM_SATELLITES];
    Alien aliens[NUM_ALIENS];

    printf("Initializing satellites...\n");
    initialize_satellites(satellites);

    printf("Initializing aliens...\n");
    initialize_aliens(aliens);

    int num_aliens = rand() % 50 + 1;

    printf("Number of aliens: %d\n", num_aliens);

    int num_detected = detect_aliens(satellites, aliens, num_aliens);

    int invasion_probability = (num_detected * 100) / NUM_SATELLITES;

    printf("Invasion probability: %d%%\n", invasion_probability);

    if (invasion_probability >= 50) {
        printf("ALIEN INVASION PROBABLE!\n");
        printf("Prepare for battle, human!\n");
    } else {
        printf("Alien invasion unlikely.\n");
        printf("Relax and enjoy your day.\n");
    }

    return 0;
}