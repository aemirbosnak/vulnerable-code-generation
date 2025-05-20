//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Define variables
    int fuel = 100;
    int hull = 100;
    int shields = 100;
    int money = 0;

    // Welcome message
    printf("Welcome to Procedural Space Adventure!\n");

    // Game loop
    while (fuel > 0 && hull > 0)
    {
        // Generate a random event
        int event = rand() % 10 + 1;

        // Handle the event
        switch (event)
        {
            case 1:
                printf("You encounter a hostile alien race!\n");
                printf("Your shields are under attack!\n");
                shields -= 10;
                break;
            case 2:
                printf("A wormhole opens up in front of you!\n");
                printf("You can either choose to enter it or stay on your current course.\n");
                printf("Do you want to enter the wormhole? (y/n)");
                char choice;
                scanf("%c", &choice);
                if (choice == 'y')
                {
                    printf("You enter the wormhole and find yourself in a strange new galaxy!\n");
                }
                else
                {
                    printf("You decide to stay on your current course.\n");
                }
                break;
            case 3:
                printf("You discover a planet rich in resources!\n");
                printf("Do you want to land on the planet and gather resources? (y/n)");
                scanf("%c", &choice);
                if (choice == 'y')
                {
                    printf("You land on the planet and begin gathering resources.\n");
                    money += 100;
                }
                break;
            case 4:
                printf("Your ship is hit by a meteorite!\n");
                printf("Your hull is damaged!\n");
                hull -= 10;
                break;
            case 5:
                printf("You encounter a friendly alien race!\n");
                printf("They offer to sell you fuel for 50 credits.\n");
                printf("Do you want to buy fuel? (y/n)");
                scanf("%c", &choice);
                if (choice == 'y')
                {
                    if (money >= 50)
                    {
                        printf("You buy fuel for 50 credits.\n");
                        fuel += 50;
                        money -= 50;
                    }
                    else
                    {
                        printf("You don't have enough money to buy fuel.\n");
                    }
                }
                break;
            case 6:
                printf("You receive a distress signal from a nearby ship!\n");
                printf("Do you want to investigate? (y/n)");
                scanf("%c", &choice);
                if (choice == 'y')
                {
                    printf("You approach the distress signal and find a damaged ship.\n");
                    printf("The ship's captain offers to pay you 200 credits if you tow him to the nearest spaceport.\n");
                    printf("Do you accept the offer? (y/n)");
                    scanf("%c", &choice);
                    if (choice == 'y')
                    {
                        if (fuel >= 50)
                        {
                            printf("You tow the damaged ship to the nearest spaceport and collect your payment.\n");
                            money += 200;
                            fuel -= 50;
                        }
                        else
                        {
                            printf("You don't have enough fuel to tow the damaged ship.\n");
                        }
                    }
                }
                break;
            case 7:
                printf("You discover an abandoned space station!\n");
                printf("Do you want to explore the station? (y/n)");
                scanf("%c", &choice);
                if (choice == 'y')
                {
                    printf("You explore the space station and find some valuable equipment.\n");
                    money += 150;
                }
                break;
            case 8:
                printf("You encounter a rogue asteroid field!\n");
                printf("Your ship is hit by multiple asteroids!\n");
                hull -= 25;
                break;
            case 9:
                printf("You pass by a beautiful gas giant!\n");
                printf("Your crew marvels at the beauty of the planet.\n");
                break;
            case 10:
                printf("You encounter a mysterious black hole!\n");
                printf("Do you want to explore the black hole? (y/n)");
                scanf("%c", &choice);
                if (choice == 'y')
                {
                    printf("You enter the black hole and find yourself in another dimension!\n");
                    printf("Your crew is terrified, but you manage to navigate your ship back to your own dimension.\n");
                }
                break;
        }

        // Print status update
        printf("Fuel: %d\n", fuel);
        printf("Hull: %d\n", hull);
        printf("Shields: %d\n", shields);
        printf("Money: %d credits\n", money);

        // Deduct fuel
        fuel -= 10;
    }

    // Game over message
    if (fuel <= 0)
    {
        printf("You ran out of fuel and got stranded in space!\n");
    }
    else if (hull <= 0)
    {
        printf("Your ship was destroyed by an enemy attack!\n");
    }

    return 0;
}