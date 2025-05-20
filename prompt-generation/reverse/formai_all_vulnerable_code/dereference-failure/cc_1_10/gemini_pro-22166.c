//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Game data
typedef struct {
    char *name;
    char *description;
    int health;
    int attack;
    int defense;
} Enemy;

Enemy enemies[] = {
    { "Goblin", "A small, green creature with sharp teeth and claws.", 10, 2, 1 },
    { "Orc", "A large, muscular creature with tusks and a thick hide.", 20, 4, 2 },
    { "Troll", "A massive, lumbering creature with regenerative abilities.", 30, 6, 3 },
    { "Dragon", "A winged, fire-breathing creature.", 40, 8, 4 }
};

// Player data
typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
    int experience;
    int level;
} Player;

Player player;

// Game functions
void create_player(char *name) {
    player.name = malloc(strlen(name) + 1);
    strcpy(player.name, name);
    player.health = 100;
    player.attack = 10;
    player.defense = 10;
    player.experience = 0;
    player.level = 1;
}

void attack(Enemy *enemy) {
    int damage = player.attack - enemy->defense;
    if (damage < 0) {
        damage = 0;
    }
    enemy->health -= damage;
    printf("You attack the %s for %d damage!\n", enemy->name, damage);
    if (enemy->health <= 0) {
        printf("You have slain the %s!\n", enemy->name);
        player.experience += enemy->health;
        if (player.experience >= 100) {
            player.level++;
            player.experience -= 100;
            printf("You have leveled up to level %d!\n", player.level);
        }
    }
}

void defend(Enemy *enemy) {
    int damage = enemy->attack - player.defense;
    if (damage < 0) {
        damage = 0;
    }
    player.health -= damage;
    printf("The %s attacks you for %d damage!\n", enemy->name, damage);
    if (player.health <= 0) {
        printf("You have been slain by the %s!\n", enemy->name);
        exit(0);
    }
}

void print_status() {
    printf("Your stats:\n");
    printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Attack: %d\n", player.attack);
    printf("Defense: %d\n", player.defense);
    printf("Experience: %d\n", player.experience);
    printf("Level: %d\n", player.level);
}

// Main game loop
int main() {
    // Create the player
    char name[256];
    printf("Enter your name, brave adventurer: ");
    scanf("%s", name);
    create_player(name);

    // Game loop
    while (1) {
        // Print the status
        print_status();

        // Get the player's input
        char input[256];
        printf("What do you want to do? (attack/defend/quit): ");
        scanf("%s", input);

        // Parse the input
        if (strcmp(input, "attack") == 0) {
            // Get the enemy to attack
            int enemy_index;
            printf("Which enemy do you want to attack? (0-%d): ", sizeof(enemies) / sizeof(Enemy) - 1);
            scanf("%d", &enemy_index);

            // Attack the enemy
            attack(&enemies[enemy_index]);
        } else if (strcmp(input, "defend") == 0) {
            // Get the enemy to defend against
            int enemy_index;
            printf("Which enemy do you want to defend against? (0-%d): ", sizeof(enemies) / sizeof(Enemy) - 1);
            scanf("%d", &enemy_index);

            // Defend against the enemy
            defend(&enemies[enemy_index]);
        } else if (strcmp(input, "quit") == 0) {
            // Quit the game
            printf("Farewell, brave adventurer!\n");
            exit(0);
        } else {
            // Invalid input
            printf("Invalid input. Please enter 'attack', 'defend', or 'quit'.\n");
        }
    }

    return 0;
}