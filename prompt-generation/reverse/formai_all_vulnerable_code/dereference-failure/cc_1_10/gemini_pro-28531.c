//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
// Where art thou, Romeo, deny thy name,
// And for that name, which is no part of thee,
// Take thou my soul, and all that I hold dear.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// And Montague and Capulet,
// Their ancient grudge break to new mutiny.
typedef struct {
  char name[20];
  char artist[20];
  int year;
} Song;

// But soft, what light through yonder window breaks?
// It is the East, and Juliet is the sun.
Song *library[100];
int num_songs = 0;

// From forth the fatal loins of these two foes
// A pair of star-crossed lovers take their life.
void add_song(char *name, char *artist, int year) {
  library[num_songs] = malloc(sizeof(Song));
  strcpy(library[num_songs]->name, name);
  strcpy(library[num_songs]->artist, artist);
  library[num_songs]->year = year;
  num_songs++;
}

// What's in a name? That which we call a rose
// By any other word would smell as sweet.
void print_song(Song *song) {
  printf("Name: %s\n", song->name);
  printf("Artist: %s\n", song->artist);
  printf("Year: %d\n", song->year);
  printf("\n");
}

// This night I hold my life but of no account,
// Nor I'll not love thee less than I do now.
void print_library() {
  for (int i = 0; i < num_songs; i++) {
    print_song(library[i]);
  }
}

// O happy dagger, this is thy sheath,
// There rust, and let me die.
void free_library() {
  for (int i = 0; i < num_songs; i++) {
    free(library[i]);
  }
}

int main() {
  // Romeo and Juliet, a pair of star-crossed lovers,
  // Whose love is put to the test by their feuding families.
  add_song("Romeo and Juliet", "Sergei Prokofiev", 1935);
  add_song("West Side Story", "Leonard Bernstein", 1957);
  add_song("Love Story", "Francis Lai", 1970);
  add_song("Titanic", "James Horner", 1997);
  add_song("Moulin Rouge!", "Craig Armstrong", 2001);

  // Print the library of songs to the console.
  print_library();

  // When he shall die, take him and cut him out in little stars,
  // And he will make the face of heaven so fine
  // That all the world will be in love with night,
  // And pay no worship to the garish sun.
  free_library();

  return 0;
}