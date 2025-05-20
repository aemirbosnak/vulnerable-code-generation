//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DISTANCE 100
#define MAX_HEALTH 100
#define MAX_SHIELD 50

int main() {
    srand(time(NULL));

    char* name = (char*)malloc(sizeof(char) * 20);
    printf("Welcome adventurer, what is your name?\n");
    scanf("%s", name);

    printf("Hello %s, you are the captain of the USS Starlight on a mission to explore the Alpha Nebula.\n", name);
    printf("Your ship is equipped with a state of the art warp drive that can take you up to %d light years per hour.\n", MAX_DISTANCE / 2);
    printf("You have %d health points and %d shield points to protect you in case of an attack.\n", MAX_HEALTH, MAX_SHIELD);
    printf("Are you ready to begin your adventure? (yes/no)\n");

    char* answer = (char*)malloc(sizeof(char) * 4);
    scanf("%s", answer);

    if (strcmp(answer, "yes") == 0) {
        printf("Great, let's get started!\n");
        printf("You enter the nebula and immediately notice the incredible colors and formations surrounding you.\n");
        printf("Suddenly, your radar detects a foreign object approaching at high speed.\n");

        int distance = rand() % MAX_DISTANCE + 1;
        printf("The object is %d light years away, what do you do? (attack/evade)\n", distance);

        scanf("%s", answer);

        if (strcmp(answer, "attack") == 0) {
            printf("You charge your weapons and fire at the incoming ship.\n");
            int hit = rand() % 2;
            if (hit) {
                printf("Your attack hits the enemy ship and causes damage, but they fire back and hit you too.\n");
                int damage = rand() % 30 + 10;
                printf("You take %d damage, your health is now %d.\n", damage, MAX_HEALTH - damage);
            } else {
                printf("Your attack misses and the enemy ship fires back, but luckily their shot misses too.\n");
            }
        } else {
            printf("You maneuver your ship and try to evade the incoming object.\n");
            printf("You manage to dodge the foreign object and continue on your journey.\n");
        }

        printf("As you venture deeper into the nebula, you come across a strange planet with a strange atmosphere.\n");
        printf("Do you want to land and investigate? (yes/no)\n");

        scanf("%s", answer);

        if (strcmp(answer, "yes") == 0) {
            printf("You land on the planet and immediately notice the oddities of the environment, plants are glowing and the sky is a misty green.\n");
            printf("Suddenly, you feel a strange electromagnetic pulse surround you.\n");
            printf("Your ship shuts off and you begin to lose oxygen.\n");

            int time_left = rand() % 11;
            printf("You have %d minutes of oxygen remaining, what do you do?\n", time_left);
            printf("1. Try to repair the ship\n2. Look for oxygen supply\n");

            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                printf("You quickly assess the situation and locate the source of the EMP, an alien device attached to your ship.\n");
                printf("You manage to remove the device and your ship comes back online.\n");
                printf("You breathe a sigh of relief and continue on your journey.\n");
            } else {
                printf("You quickly exit your ship and look for a source of oxygen.\n");
                printf("You come across a cave with strange markings and decide to enter, hoping to find a solution.\n");
                printf("Inside the cave, you come across an ancient artifact that seems to emit oxygen.\n");
                printf("You take the artifact and return to your ship, where you quickly hook it up to the oxygen supply.\n");
                printf("You breathe a sigh of relief and continue on your journey.\n");
            }
        } else {
            printf("You decide to continue your journey without investigating the planet.\n");
            printf("As you leave the planet's atmosphere, you see in the distance a fleet of alien ships approaching.\n");
            printf("You charge your weapons and prepare for battle.\n");

            int number_of_ships = rand() % 6 + 1;
            printf("There are %d alien ships, what do you do? (attack/evade)\n", number_of_ships);

            scanf("%s", answer);

            if (strcmp(answer, "attack") == 0) {
                printf("You engage the enemy ships and fire your weapons.\n");
                int hits = rand() % number_of_ships + 1;
                int damage = scale_health_and_shields(hits, MAX_HEALTH, MAX_SHIELD);
                printf("You hit %d ships and cause %d damage, but the enemy fleet fires back and hits you too.\n", hits, damage);
                printf("You take %d damage, your health is now %d.\n", damage, MAX_HEALTH - damage);
            } else {
                printf("You maneuver your ship and try to evade the incoming enemy fleet.\n");
                printf("You manage to avoid the alien ships and continue on your journey.\n");
            }
        }
    } else {
        printf("Come back when you are ready for an adventure!\n");
    }

    free(name);
    free(answer);

    return 0;
}

int scale_health_and_shields(int hits, int max_health, int max_shield) {
    int damage = (hits * rand() % max_health + 1) / 2;
    if (damage < max_shield) {
        max_shield -= damage;
        damage = 0;
    } else {
        damage -= max_shield;
        max_shield = 0;
    }
    max_health -= damage;
    return damage;
}