//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: excited
// Engage in a thrilling underwater adventure in the depths of the ocean!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Unveiling the mysteries of the deep sea
typedef struct {
    int health;
    int damage;
    int speed;
    char name[20];
} Creature;

// A vast ocean teeming with life and danger
typedef struct {
    int width;
    int height;
    Creature **creatures;
} Ocean;

// Setting sail on our undersea adventure
Ocean initializeOcean(int width, int height) {
    Ocean ocean;
    ocean.width = width;
    ocean.height = height;
    ocean.creatures = malloc(sizeof(Creature *) * width * height);
    return ocean;
}

// Populating our ocean with diverse creatures
Creature initializeCreature(int health, int damage, int speed, char *name) {
    Creature creature;
    creature.health = health;
    creature.damage = damage;
    creature.speed = speed;
    strcpy(creature.name, name);
    return creature;
}

// Generating a vibrant and perilous underwater ecosystem
void populateOcean(Ocean *ocean) {
    srand(time(NULL));
    for (int i = 0; i < ocean->width; i++) {
        for (int j = 0; j < ocean->height; j++) {
            int creatureType = rand() % 3;
            switch (creatureType) {
                case 0:
                    ocean->creatures[i][j] = initializeCreature(100, 20, 5, "Shark");
                    break;
                case 1:
                    ocean->creatures[i][j] = initializeCreature(50, 10, 10, "Jellyfish");
                    break;
                case 2:
                    ocean->creatures[i][j] = initializeCreature(200, 50, 1, "Giant Squid");
                    break;
            }
        }
    }
}

// Embark on a thrilling underwater expedition
void exploreOcean(Ocean *ocean) {
    int x = ocean->width / 2;
    int y = ocean->height / 2;
    while (1) {
        // Display the current state of our underwater adventure
        printf("You are at coordinates (%d, %d).\n", x, y);
        printf("Your surroundings:\n");
        for (int i = y - 1; i <= y + 1; i++) {
            for (int j = x - 1; j <= x + 1; j++) {
                if (i >= 0 && i < ocean->height && j >= 0 && j < ocean->width) {
                    printf("%s ", ocean->creatures[j][i].name);
                } else {
                    printf("~ ");
                }
            }
            printf("\n");
        }
        // Allow the player to make their move
        char command;
        printf("Enter your command (w/a/s/d/q): ");
        scanf(" %c", &command);
        switch (command) {
            case 'w':
                if (y > 0) y--;
                break;
            case 'a':
                if (x > 0) x--;
                break;
            case 's':
                if (y < ocean->height - 1) y++;
                break;
            case 'd':
                if (x < ocean->width - 1) x++;
                break;
            case 'q':
                return; // Wave goodbye to the ocean's depths
        }
        // Encounter the creatures inhabiting the ocean
        Creature *currentCreature = &ocean->creatures[x][y];
        printf("You encountered a %s!\n", currentCreature->name);
        // Engage in a thrilling underwater battle
        while (currentCreature->health > 0) {
            printf("Your health: %d, %s's health: %d\n", ocean->creatures[x][y].health, ocean->creatures[x][y].name, currentCreature->health);
            printf("Enter your attack (1/2/3/4): ");
            int attack;
            scanf(" %d", &attack);
            switch (attack) {
                case 1:
                    // Unleash a powerful strike
                    currentCreature->health -= ocean->creatures[x][y].damage;
                    printf("You dealt %d damage to the %s.\n", ocean->creatures[x][y].damage, currentCreature->name);
                    break;
                case 2:
                    // Attempt to evade the creature's attack
                    if (rand() % 2 == 0) {
                        printf("You successfully dodged the %s's attack!\n", currentCreature->name);
                    } else {
                        ocean->creatures[x][y].health -= currentCreature->damage;
                        printf("The %s dealt %d damage to you.\n", currentCreature->name, currentCreature->damage);
                    }
                    break;
                case 3:
                    // Attempt to flee the encounter
                    if (rand() % 2 == 0) {
                        printf("You successfully fled from the %s.\n", currentCreature->name);
                        return;
                    } else {
                        printf("Your escape attempt failed.\n");
                    }
                    break;
                case 4:
                    // Use a special ability (if available)
                    if (ocean->creatures[x][y].damage >= 50) {
                        currentCreature->health -= ocean->creatures[x][y].damage * 2;
                        printf("You unleashed a devastating attack, dealing %d damage to the %s!\n", ocean->creatures[x][y].damage * 2, currentCreature->name);
                    } else {
                        printf("You don't have any special abilities to use.\n");
                    }
                    break;
            }
        }
        // Claim your victory or lament your defeat
        if (currentCreature->health <= 0) {
            printf("You defeated the %s!\n", currentCreature->name);
        } else {
            printf("You were defeated by the %s.\n", currentCreature->name);
        }
    }
}

int main() {
    // Set sail for adventure in the vast ocean
    Ocean ocean = initializeOcean(10, 10);
    populateOcean(&ocean);
    // Dive into the depths and explore the wonders that await
    exploreOcean(&ocean);
    return 0;
}