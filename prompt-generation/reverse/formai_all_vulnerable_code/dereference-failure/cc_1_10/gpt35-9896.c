//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
// Romeo and Juliet: A Tale of C Data Structures

#include <stdio.h>
#include <stdlib.h>

// Romeo, a brave knight, loved Juliet, a beautiful princess.

typedef struct {
    char* name;
    int strength;
    int agility;
    int intelligence;
} Knight;

typedef struct {
    char* name;
    int beauty;
    int kindness;
    int intelligence;
} Princess;

// However, their love was not meant to be, as their families were sworn enemies.

typedef struct {
    Knight* leader;
    int num_knights;
    int total_strength;
} Montague;

typedef struct {
    Princess* leader;
    int num_princesses;
    int total_beauty;
} Capulet;

// But Romeo and Juliet refused to let that stop them. They decided to elope.

typedef struct {
    Knight* groom;
    Princess* bride;
    int happiness;
} Marriage;

// However, their families found out about the marriage and were outraged.

typedef struct {
    Montague* montague;
    Capulet* capulet;
    Marriage* marriage;
} Conflict;

int main() {
    // Romeo and Juliet meet.
    Knight* romeo = (Knight*) malloc(sizeof(Knight));
    romeo->name = "Romeo";
    romeo->strength = 20;
    romeo->agility = 10;
    romeo->intelligence = 15;
    
    Princess* juliet = (Princess*) malloc(sizeof(Princess));
    juliet->name = "Juliet";
    juliet->beauty = 25;
    juliet->kindness = 20;
    juliet->intelligence = 10;
    
    // Their families find out about their love.
    Montague* montague = (Montague*) malloc(sizeof(Montague));
    montague->leader = romeo;
    montague->num_knights = 10;
    montague->total_strength = 200;
    
    Capulet* capulet = (Capulet*) malloc(sizeof(Capulet));
    capulet->leader = juliet;
    capulet->num_princesses = 5;
    capulet->total_beauty = 125;
    
    // Romeo and Juliet decide to elope.
    Marriage* marriage = (Marriage*) malloc(sizeof(Marriage));
    marriage->groom = romeo;
    marriage->bride = juliet;
    marriage->happiness = 100;
    
    // The families find out about the marriage and declare war.
    Conflict* conflict = (Conflict*) malloc(sizeof(Conflict));
    conflict->montague = montague;
    conflict->capulet = capulet;
    conflict->marriage = marriage;
    
    printf("The Montagues declare war on the Capulets!\n");
    printf("Montague leader %s has %d knights with a total strength of %d.\n", 
           montague->leader->name, montague->num_knights, montague->total_strength);
    printf("Capulet leader %s has %d princesses with a total beauty of %d.\n", 
           capulet->leader->name, capulet->num_princesses, capulet->total_beauty);
    printf("Romeo and Juliet elope and get married with a happiness of %d.\n", marriage->happiness);
    
    free(romeo);
    free(juliet);
    free(montague);
    free(capulet);
    free(marriage);
    free(conflict);
    
    return 0;
}