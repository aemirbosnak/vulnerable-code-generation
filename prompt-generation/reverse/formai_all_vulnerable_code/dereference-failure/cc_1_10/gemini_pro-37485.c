//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
// As the nightingales sang their mournful tune,
// A tale of music unfolded beneath the moon.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fair Juliet's library holds melodies grand,
// A symphony of notes, a musical land.
typedef struct MusicLibrary {
  char title[50];
  char artist[50];
  int year;
  char genre[50];
  struct MusicLibrary *next;
} MusicLibrary;

// Romeo, a suitor so ardent and true,
// With his love for music, a passion he knew.
void addSong(MusicLibrary **library, char *title, char *artist, int year, char *genre) {
  MusicLibrary *newSong = malloc(sizeof(MusicLibrary));
  strcpy(newSong->title, title);
  strcpy(newSong->artist, artist);
  newSong->year = year;
  strcpy(newSong->genre, genre);
  newSong->next = *library;
  *library = newSong;
}

// Juliet, a maiden with a heart full of grace,
// Shared her love for music with her lover's embrace.
void printLibrary(MusicLibrary *library) {
  printf("Sweet music fills the air, a symphony divine,\n");
  while (library != NULL) {
    printf("\"%s\" by %s, a melody so fine,\n", library->title, library->artist);
    printf("In the year %d, it was born,\n", library->year);
    printf("A genre so captivating, %s it's called,\n", library->genre);
    library = library->next;
  }
}

// Their love, a forbidden fruit, cruel fate did decree,
// Yet their passion for music, forever free.
int main() {
  // Where Capulet and Montague's feud had torn,
  // Music brought them together, erasing all scorn.
  MusicLibrary *library = NULL;
  addSong(&library, "Canzone d'Amore", "Claudio Monteverdi", 1610, "Madrigal");
  addSong(&library, "Moonlight Sonata", "Ludwig van Beethoven", 1801, "Classical");
  addSong(&library, "Ave Maria", "Johann Sebastian Bach", 1723, "Baroque");
  addSong(&library, "Clair de Lune", "Claude Debussy", 1890, "Impressionist");
  addSong(&library, "Bohemian Rhapsody", "Queen", 1975, "Rock");

  // In Verona's streets, their hearts entwined,
  // Their love for music, a bond unconfined.
  printLibrary(library);

  // Through time and space, their love and music entwined,
  // A timeless melody, forever enshrined.
  return 0;
}