//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
    char village[50];
    int gold;
} Knight;

typedef struct {
    Knight *knights;
    int knight_count;
} Kingdom;

void initialize_kingdom(Kingdom *kingdom, int count) {
    kingdom->knights = (Knight *)malloc(count * sizeof(Knight));
    kingdom->knight_count = count;

    strcpy(kingdom->knights[0].name, "Sir Lancelot");
    kingdom->knights[0].age = 30;
    strcpy(kingdom->knights[0].village, "Camelot");
    kingdom->knights[0].gold = 50;

    strcpy(kingdom->knights[1].name, "Sir Gawain");
    kingdom->knights[1].age = 25;
    strcpy(kingdom->knights[1].village, "Camelot");
    kingdom->knights[1].gold = 75;

    strcpy(kingdom->knights[2].name, "Sir Arthur");
    kingdom->knights[2].age = 35;
    strcpy(kingdom->knights[2].village, "Camelot");
    kingdom->knights[2].gold = 100;

    strcpy(kingdom->knights[3].name, "Sir Bedivere");
    kingdom->knights[3].age = 28;
    strcpy(kingdom->knights[3].village, "Camelot");
    kingdom->knights[3].gold = 60;

    strcpy(kingdom->knights[4].name, "Sir Percival");
    kingdom->knights[4].age = 22;
    strcpy(kingdom->knights[4].village, "Camelot");
    kingdom->knights[4].gold = 80;
}

void print_knights(Kingdom *kingdom) {
    printf("Knights of the Kingdom:\n");
    printf("Name\t\tAge\tVillage\t\tGold\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < kingdom->knight_count; i++) {
        printf("%s\t%d\t%s\t%d\n", 
               kingdom->knights[i].name, 
               kingdom->knights[i].age,
               kingdom->knights[i].village, 
               kingdom->knights[i].gold);
    }
}

void find_wealthy_knights(Kingdom *kingdom) {
    int threshold = 70;
    printf("\nWealthy Knights (Gold > %d):\n", threshold);
    printf("Name\t\tAge\tVillage\t\tGold\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < kingdom->knight_count; i++) {
        if (kingdom->knights[i].gold > threshold) {
            printf("%s\t%d\t%s\t%d\n", 
                   kingdom->knights[i].name, 
                   kingdom->knights[i].age,
                   kingdom->knights[i].village, 
                   kingdom->knights[i].gold);
        }
    }
}

void free_kingdom(Kingdom *kingdom) {
    free(kingdom->knights);
}

int main() {
    Kingdom camelot;
    int knight_count = 5;

    // Initialize the kingdom
    initialize_kingdom(&camelot, knight_count);

    // Print the details of all knights
    print_knights(&camelot);
    // Print the details of wealthy knights
    find_wealthy_knights(&camelot);
    // Free allocated memory
    free_kingdom(&camelot);

    return 0;
}