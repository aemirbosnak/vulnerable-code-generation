//MISTRAL-7B DATASET v1.0 Category: Weather simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WEATHER 5

const char *weather_descriptions[NUM_WEATHER] = {
    "The sky is a canvas of twilight hues,\n"
    "Whispering a love letter to the sunset.\n"
    "The air is warm and sweet,\n"
    "Kissing your skin with gentle caresses.\n"
    "Birds sing lullabies to the twinkling stars,\n"
    "As the world rests in the cradle of the night.\n",

    "Raindrops fall like tears from the heavens above,\n"
    "Nurturing the earth with their tender touch.\n"
    "A symphony of rain beats against the window,\n"
    "Serenading your soul with its soothing rhythm.\n"
    "The scent of wet earth fills the room,\n"
    "Aromas of new beginnings and promises kept.\n",

    "The sun rises, casting golden rays,\n"
    "Igniting the day with its fiery passion.\n"
    "Warm breezes dance through the open windows,\n"
    "Bringing the sweet fragrance of fresh blooms.\n"
    "Birds sing melodies of love and life,\n"
    "In a world where each moment is a gift.\n",

    "The sky is painted with the colors of the night,\n"
    "A tapestry of stars that twinkle and gleam.\n"
    "The moon rises, a beacon of mystery and magic,\n"
    "Guiding lost hearts on their journey home.\n"
    "A gentle mist caresses the earth,\n"
    "Leaving behind a trail of silvered dreams.\n",

    "Dark clouds gather, their thunderous roars,\n"
    "Echoing through the valley like a lover's cry.\n"
    "The rain beats against the windowpanes,\n"
    "A reminder of the passion that lies hidden within.\n"
    "A bolt of lightning illuminates the sky,\n"
    "A flash of brilliance, a fleeting moment of love.\n"
};

void main() {
    int seed;
    int i;

    srand(time(&seed));

    printf("Welcome to the Romantic Weather Forecast!\n");
    printf("Let me share with you the enchanting description of today's weather:\n\n");

    i = rand() % NUM_WEATHER;
    printf("%s\n", weather_descriptions[i]);
}