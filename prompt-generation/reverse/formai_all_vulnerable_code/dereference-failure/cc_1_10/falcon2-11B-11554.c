//Falcon2-11B DATASET v1.0 Category: Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* content = (char*)malloc(size + 1);
    fread(content, size, 1, file);
    content[size] = '\0';

    fclose(file);
    return content;
}

int main() {
    char* filename = "text.txt";
    char* content = readFile(filename);

    printf("In the year 2080, after the nuclear apocalypse, a lone survivor named John trudges through the barren wasteland, searching for any sign of life. The sun beats down relentlessly, and the scorching heat bakes the earth beneath his feet. The only sound he hears is the crunching of the dust beneath his boots as he trudges on...\n");

    printf("Suddenly, he spots a glimmer of hope in the distance. It's a small building, barely standing, but it's something. He quickens his pace, his heart racing with anticipation. As he approaches the building, he sees a flickering neon sign: \"BAR\"\n");

    printf("John enters the bar, his eyes adjusting to the dim light. He spots a few other survivors, huddled around a table, playing a game of cards. They look up as he enters, their eyes narrowing suspiciously.\n");

    printf("\"Who are you?\" one of them asks, his voice hoarse.\n");

    printf("\"Just passing through,\" John replies, trying to sound nonchalant. \"Looking for some company.\"\n");

    printf("The survivors look at each other, then nod. \"We could use some help with our game,\" one of them says. \"You in?\"\n");

    printf("John nods, taking a seat at the table. The survivors shuffle the cards and deal them out. John picks up his hand and examines the cards. They're all different, but somehow, he knows what he needs to do. He lays down his cards, and the survivors gasp in surprise. John has won.\n");

    printf("\"You're good,\" one of them says, grinning. \"Maybe you can help us with something else...\"\n");

    printf("Suddenly, a loud noise interrupts the conversation. The ground shakes, and the building begins to crumble. \"What's happening?\" John exclaims, grabbing his things and running towards the door. \"It's the end of the world!\" one of the survivors shouts. \"We've got to get out of here!\"\n");

    printf("John sprints outside, the dust and debris of the collapsing building swirling around him. He spots a vehicle parked nearby, and without a second thought, he jumps in and starts it up. He races through the wasteland, the wind whipping past him as he speeds towards the horizon. He knows he's not alone in this world, but he's determined to survive, no matter what it takes.\n");

    return 0;
}