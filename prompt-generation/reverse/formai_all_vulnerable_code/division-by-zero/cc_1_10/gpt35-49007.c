//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10
#define MAX_HEALTH 100
#define MAX_ATTACK 50
#define MAX_DEFENSE 30

struct player {
    char name[20];
    int health;
    int attack;
    int defense;
};

struct enemy {
    char type[20];
    int health;
    int attack;
    int defense;
};

void generate_enemy(struct enemy *e) {
    int r = rand() % 5;
    switch(r) {
        case 0:
            sprintf(e->type, "Gangster");
            e->health = 50;
            e->attack = 20;
            e->defense = 5;
            break;
        case 1:
            sprintf(e->type, "Cyborg");
            e->health = 75;
            e->attack = 30;
            e->defense = 10;
            break;
        case 2:
            sprintf(e->type, "Mutant");
            e->health = 100;
            e->attack = 40;
            e->defense = 15;
            break;
        case 3:
            sprintf(e->type, "Ninja");
            e->health = 125;
            e->attack = 50;
            e->defense = 20;
            break;
        case 4:
            sprintf(e->type, "Robot");
            e->health = 150;
            e->attack = 60;
            e->defense = 25;
            break;
        default:
            sprintf(e->type, "Unknown");
            e->health = 50;
            e->attack = 10;
            e->defense = 1;
            break;
    }
}

void fight(struct player *p, struct enemy *e) {
    while(p->health > 0 && e->health > 0) {
        int damage = (rand() % (p->attack - e->defense)) + 1;
        if(damage < 0) {
            damage = 0;
        }
        e->health -= damage;
        printf("You hit the %s for %d damage. It has %d health left.\n", e->type, damage, e->health);
        if(e->health <= 0) {
            printf("You have defeated the %s!\n", e->type);
            break;
        }
        damage = (rand() % (e->attack - p->defense)) + 1;
        if(damage < 0) {
            damage = 0;
        }
        p->health -= damage;
        printf("The %s hit you for %d damage. You have %d health left.\n", e->type, damage, p->health);
        if(p->health <= 0) {
            printf("You have been defeated by the %s.\n", e->type);
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    struct player p;
    printf("Enter your name: ");
    scanf("%s", p.name);
    p.health = MAX_HEALTH;
    p.attack = MAX_ATTACK;
    p.defense = MAX_DEFENSE;
    printf("\nWelcome, %s. You are the last hope for humanity.\n", p.name);
    printf("Your mission is to fight your way through the streets of this cyberpunk world and defeat the evil forces that control it.\n");
    printf("You have a total of %d enemies to defeat.\n", MAX_ENEMIES);

    for(int i=1; i<=MAX_ENEMIES; i++) {
        struct enemy e;
        generate_enemy(&e);
        printf("\nEnemy #%d: %s\n", i, e.type);
        printf("Health: %d\n", e.health);
        printf("Attack: %d\n", e.attack);
        printf("Defense: %d\n\n", e.defense);
        printf("Press enter to begin the fight...");
        getchar();
        getchar();
        printf("-----\n");
        fight(&p, &e);
        printf("-----\n");
        if(p.health <= 0) {
            printf("You have been defeated. Game over.\n");
            return 0;
        }
    }
    printf("Congratulations, %s! You have saved the world from the cyberpunk apocalypse!\n", p.name);
    return 0;
}