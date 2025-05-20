//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    printf("Welcome to the Space Adventure!\n");

    char* ship_name = malloc(10);
    char* destination = malloc(10);

    printf("Please enter your ship's name: ");
    scanf("%s", ship_name);

    printf("Please enter your destination: ");
    scanf("%s", destination);

    int* fuel_amount = malloc(10);
    int* cargo_capacity = malloc(10);
    int* cargo_amount = malloc(10);
    int* damage_amount = malloc(10);
    int* enemy_ships_destroyed = malloc(10);

    for (int i = 0; i < 10; i++) {
        fuel_amount[i] = rand() % 100 + 1;
        cargo_capacity[i] = rand() % 100 + 1;
        cargo_amount[i] = rand() % 100 + 1;
        damage_amount[i] = rand() % 100 + 1;
        enemy_ships_destroyed[i] = rand() % 100 + 1;
    }

    printf("Your ship's name is: %s\n", ship_name);
    printf("Your destination is: %s\n", destination);

    printf("Your ship has %d fuel units\n", fuel_amount[0]);
    printf("Your cargo capacity is %d units\n", cargo_capacity[0]);
    printf("Your cargo amount is %d units\n", cargo_amount[0]);
    printf("Your ship has taken %d damage\n", damage_amount[0]);
    printf("You have destroyed %d enemy ships\n", enemy_ships_destroyed[0]);

    int choice;
    printf("What do you want to do? (1) Travel to destination, (2) Fight enemy ships, (3) Trade with other ships, (4) Exit game\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Traveling to %s...\n", destination);
            break;
        case 2:
            printf("Engaging enemy ships...\n");
            int enemy_ships_left = rand() % 100 + 1;
            while (enemy_ships_left > 0) {
                printf("Enemy ship encountered!\n");
                printf("Enemy ship has %d fuel units\n", fuel_amount[rand() % 10 + 1]);
                printf("Enemy ship's cargo capacity is %d units\n", cargo_capacity[rand() % 10 + 1]);
                printf("Enemy ship's cargo amount is %d units\n", cargo_amount[rand() % 10 + 1]);
                printf("Enemy ship has taken %d damage\n", damage_amount[rand() % 10 + 1]);
                printf("Enemy ship has destroyed %d enemy ships\n", enemy_ships_destroyed[rand() % 10 + 1]);
                printf("Do you want to engage? (y/n): ");
                char engage_input = getchar();
                if (engage_input == 'y') {
                    printf("Firing weapons...\n");
                    int enemy_ship_damage = rand() % 100 + 1;
                    printf("You have dealt %d damage to the enemy ship\n", enemy_ship_damage);
                    printf("Enemy ship has %d fuel units remaining\n", fuel_amount[rand() % 10 + 1] - enemy_ship_damage);
                    printf("Enemy ship's cargo capacity is %d units remaining\n", cargo_capacity[rand() % 10 + 1] - cargo_amount[rand() % 10 + 1]);
                    printf("Enemy ship's cargo amount is %d units remaining\n", cargo_amount[rand() % 10 + 1] - cargo_amount[rand() % 10 + 1]);
                    printf("Enemy ship has taken %d damage\n", damage_amount[rand() % 10 + 1] + enemy_ship_damage);
                    printf("Enemy ship has destroyed %d enemy ships\n", enemy_ships_destroyed[rand() % 10 + 1] + 1);
                    printf("Your ship has taken %d damage\n", damage_amount[0] + enemy_ship_damage);
                    printf("Your cargo amount is %d units remaining\n", cargo_amount[0] - cargo_amount[rand() % 10 + 1]);
                    printf("Your cargo capacity is %d units remaining\n", cargo_capacity[0] - cargo_capacity[rand() % 10 + 1]);
                    printf("Enemy ship destroyed!\n");
                    enemy_ships_left--;
                } else {
                    printf("Enemy ship escaped...\n");
                }
            }
            printf("All enemy ships destroyed!\n");
            break;
        case 3:
            printf("Trading with other ships...\n");
            int other_ship_cargo_amount = rand() % 100 + 1;
            int other_ship_cargo_capacity = rand() % 100 + 1;
            printf("Other ship has %d units of cargo\n", other_ship_cargo_amount);
            printf("Other ship's cargo capacity is %d units\n", other_ship_cargo_capacity);
            printf("Do you want to trade? (y/n): ");
            char trade_input = getchar();
            if (trade_input == 'y') {
                int cargo_to_trade = rand() % 100 + 1;
                int cargo_received = rand() % 100 + 1;
                printf("Trading %d units of cargo...\n", cargo_to_trade);
                printf("You received %d units of cargo\n", cargo_received);
                printf("Other ship's cargo amount is now %d units\n", other_ship_cargo_amount + cargo_to_trade);
                printf("Other ship's cargo capacity is now %d units\n", other_ship_cargo_capacity - cargo_to_trade);
                printf("Your cargo amount is now %d units\n", cargo_amount[0] + cargo_received);
                printf("Your cargo capacity is now %d units\n", cargo_capacity[0] - cargo_to_trade);
                printf("Other ship's cargo amount is now %d units\n", other_ship_cargo_amount + cargo_to_trade);
                printf("Other ship's cargo capacity is now %d units\n", other_ship_cargo_capacity - cargo_to_trade);
            } else {
                printf("Other ship declined the trade...\n");
            }
            break;
        case 4:
            printf("Exiting the game...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    free(ship_name);
    free(destination);
    free(fuel_amount);
    free(cargo_capacity);
    free(cargo_amount);
    free(damage_amount);
    free(enemy_ships_destroyed);

    return 0;
}