//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int health;
    int money;
} Player;

typedef struct {
    char name[50];
    int price;
    int health;
} Weapon;

Player player;
Weapon *weapons;
int num_weapons;
int current_weapon;

void initialize_player(){
    player.health = 100;
    player.money = 200;
}

void initialize_weapons(){
    num_weapons = 3;
    weapons = malloc(num_weapons * sizeof(Weapon));
    
    strcpy(weapons[0].name, "Laser Pistol");
    weapons[0].price = 50;
    weapons[0].health = 40;
    
    strcpy(weapons[1].name, "Photon Blade");
    weapons[1].price = 75;
    weapons[1].health = 60;
    
    strcpy(weapons[2].name, "Plasma Cannon");
    weapons[2].price = 100;
    weapons[2].health = 80;
    
    current_weapon = 0; //set the initial weapon to laser pistol
}

void display_weapons(){
    printf("Available Weapons:\n");
    for(int i=0; i<num_weapons; i++){
        printf("(%d) %s - Price: $%d Health: %d/%d\n", i+1, weapons[i].name, weapons[i].price, weapons[i].health, weapons[i].health);
    }
}

void display_player(){
    printf("Player Status:\n");
    printf("Health: %d/%d Money: $%d\n", player.health, 100, player.money);
}

void buy_weapon(int index){
    if(index < 0 || index >= num_weapons){
        printf("Invalid weapon selection!\n");
        return;
    }
    
    Weapon weapon = weapons[index];
    if(player.money < weapon.price){
        printf("You don't have enough money to buy %s!\n", weapon.name);
        return;
    }
    
    player.money -= weapon.price;
    printf("You bought %s for $%d!\n", weapon.name, weapon.price);
    current_weapon = index;
}

int main(){
    srand(time(NULL));
    
    initialize_player();
    initialize_weapons();
    
    printf("Welcome to the Procedural Space Adventure!\n");
    
    int current_planet = 0;
    while(1){ //Game loop
        printf("You are currently on Planet %d\n", current_planet+1);
        display_weapons();
        display_player();
        
        int action;
        printf("What would you like to do?\n");
        printf("(1) Explore the planet\n");
        printf("(2) Buy a new weapon\n");
        printf("(3) Move to the next planet\n");
        scanf("%d", &action);
        
        switch(action){
            case 1:
                printf("You explore the planet and find some resources!\n");
                int resource = rand() % 3 + 1; //get random amount of resources between 1 and 3
                player.health += resource * 10;
                player.money += resource * 25;
                break;
            case 2:
                printf("Which weapon would you like to buy?\n");
                int selection;
                scanf("%d", &selection);
                buy_weapon(selection-1); //-1 because the options are 1, 2, 3 instead of 0, 1, 2
                break;
            case 3:
                current_planet++;
                if(current_planet >= 5){
                    printf("Congratulations! You have explored all the planets and beat the game!\n");
                    return 0;
                }
                break;
            default: //Invalid input
                printf("Invalid option selected!\n");
                break;
        }
        
        //Decrease health based on the current planet's hazards
        int hazard = rand() % 4; //0 to 3
        switch(hazard){
            case 0: //No hazard
                break;
            case 1: //Low Hazard
                player.health -= 10;
                break;
            case 2: //Medium Hazard
                player.health -= 20;
                break;
            case 3: //High Hazard
                player.health -= 30;
                break;
        }
        
        //Check if player has died
        if(player.health <= 0){
            printf("Game Over! You have died on planet %d!\n", current_planet+1);
            return 0;
        }
    }
}