//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* metadata = "TITLE=In the Aeroplane Over the Sea\nARTIST=Neutral Milk Hotel\nYEAR=1998\nGENRE=Indie Rock\n";

  // First, let's extract the title
  char* title = strstr(metadata, "TITLE=");
  title += strlen("TITLE="); // move pointer to start of title
  char* end_ptr = strchr(title, '\n');
  int title_len = end_ptr - title;
  char* album_title = malloc(title_len+1);
  strncpy(album_title, title, title_len);
  album_title[title_len] = '\0';
  printf("Album Title: %s\n", album_title);

  // Next, let's extract the artist
  char* artist = strstr(metadata, "ARTIST=");
  artist += strlen("ARTIST="); // move pointer to start of artist
  end_ptr = strchr(artist, '\n');
  int artist_len = end_ptr - artist;
  char* album_artist = malloc(artist_len+1);
  strncpy(album_artist, artist, artist_len);
  album_artist[artist_len] = '\0';
  printf("Album Artist: %s\n", album_artist);

  // Let's extract the year
  char* year = strstr(metadata, "YEAR=");
  year += strlen("YEAR="); // move pointer to start of year
  end_ptr = strchr(year, '\n');
  int year_len = end_ptr - year;
  char* album_year = malloc(year_len+1);
  strncpy(album_year, year, year_len);
  album_year[year_len] = '\0';
  printf("Album Year: %s\n", album_year);

  // Finally, let's extract the genre
  char* genre = strstr(metadata, "GENRE=");
  genre += strlen("GENRE="); // move pointer to start of genre
  end_ptr = strchr(genre, '\n');
  int genre_len = end_ptr - genre;
  char* album_genre = malloc(genre_len+1);
  strncpy(album_genre, genre, genre_len);
  album_genre[genre_len] = '\0';
  printf("Album Genre: %s\n", album_genre);

  // Free all allocated memory
  free(album_title);
  free(album_artist);
  free(album_year);
  free(album_genre);
  
  return 0;
}