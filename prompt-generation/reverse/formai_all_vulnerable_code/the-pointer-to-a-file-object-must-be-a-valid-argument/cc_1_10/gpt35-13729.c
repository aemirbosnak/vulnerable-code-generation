//FormAI DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

struct Song {
  char title[50];
  char artist[50];
  int year;
  char genre[20];
};

int getNumSongs(FILE *db) {
  int count = 0;
  char line[100];
  while (fgets(line, sizeof(line), db)) {
    count++;
  }
  rewind(db);
  return count;
}

int addSong(struct Song library[], char title[], char artist[], int year, char genre[], int numSongs) {
  if (numSongs == MAX_SONGS) {
    printf("Library is full!");
    return numSongs;
  }
  
  struct Song newSong;
  strcpy(newSong.title, title);
  strcpy(newSong.artist, artist);
  newSong.year = year;
  strcpy(newSong.genre, genre);
  
  library[numSongs] = newSong;
  printf("Added song successfully!\n");
  return numSongs + 1;
}

void printLibrary(struct Song library[], int numSongs) {
  printf("-----------------------------------------------\n");
  printf("| %-20s | %-20s | %-5s | %-12s |\n", "Title", "Artist", "Year", "Genre");
  printf("-----------------------------------------------\n");
  for (int i = 0; i < numSongs; i++) {
    printf("| %-20s | %-20s | %-5d | %-12s |\n", library[i].title, library[i].artist, library[i].year, library[i].genre);
  }
  printf("-----------------------------------------------\n");
}

int main() {
  struct Song library[MAX_SONGS];
  char filename[] = "song_db.txt";
  FILE *db = fopen(filename, "r");
  int numSongs = getNumSongs(db);
  
  char title[50];
  char artist[50];
  int year;
  char genre[20];
  
  int input;
  do {
    printf("1. Add song\n2. Print library\n3. Quit\n");
    printf("Enter selection: ");
    scanf("%d", &input);
  
    switch (input) {
      case 1:
        printf("Enter song title: ");
        scanf("%s", title);
        printf("Enter artist name: ");
        scanf("%s", artist);
        printf("Enter year released: ");
        scanf("%d", &year);
        printf("Enter genre: ");
        scanf("%s", genre);
        numSongs = addSong(library, title, artist, year, genre, numSongs);
        break;
      case 2:
        printLibrary(library, numSongs);
        break;
      default:
        printf("Invalid input.\n");
        break;
    }
  } while (input != 3);

  printf("Writing library to file...\n");
  FILE *out = fopen("song_db_out.txt", "w");
  for (int i = 0; i < numSongs; i++) {
    fprintf(out, "%s,%s,%d,%s\n", library[i].title, library[i].artist, library[i].year, library[i].genre);
  }
  fclose(out);
  printf("Library saved to song_db_out.txt\n");

  fclose(db);
  return 0;
}