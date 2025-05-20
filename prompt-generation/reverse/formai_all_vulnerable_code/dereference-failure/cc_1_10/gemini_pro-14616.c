//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *title;
  int rating;
} Movie;

Movie movies[] = {
  { "The Cabinet of Dr. Caligari", 5 },
  { "Nosferatu", 4 },
  { "Metropolis", 5 },
  { "The Passion of Joan of Arc", 5 },
  { "Un Chien Andalou", 4 },
  { "The Gold Rush", 5 },
  { "City Lights", 5 },
  { "Modern Times", 5 },
  { "The Great Dictator", 5 },
  { "Citizen Kane", 5 },
  { "Casablanca", 5 },
  { "Gone with the Wind", 5 },
  { "The Third Man", 5 },
  { "Bicycle Thieves", 5 },
  { "Rashomon", 5 },
  { "Seven Samurai", 5 },
  { "Tokyo Story", 5 },
  { "Vertigo", 5 },
  { "Rear Window", 5 },
  { "North by Northwest", 5 },
  { "Psycho", 5 },
  { "The Birds", 5 },
  { "Marnie", 5 },
  { "The Silence of the Lambs", 5 },
  { "The Shining", 5 },
  { "The Exorcist", 5 },
  { "Jaws", 5 },
  { "Alien", 5 },
  { "The Thing", 5 },
  { "E.T. the Extra-Terrestrial", 5 },
  { "The Terminator", 5 },
  { "Die Hard", 5 },
  { "Indiana Jones and the Raiders of the Lost Ark", 5 },
  { "Star Wars", 5 },
  { "The Empire Strikes Back", 5 },
  { "Return of the Jedi", 5 },
  { "The Matrix", 5 },
  { "The Lord of the Rings: The Fellowship of the Ring", 5 },
  { "The Lord of the Rings: The Two Towers", 5 },
  { "The Lord of the Rings: The Return of the King", 5 },
  { "The Dark Knight", 5 },
  { "Inception", 5 },
  { "Interstellar", 5 },
  { "Dunkirk", 5 },
  { "Tenet", 5 },
};

int num_movies = sizeof(movies) / sizeof(Movie);

int main() {
  int rating;
  char *title;

  printf("Enter a movie title: ");
  scanf("%s", title);

  for (int i = 0; i < num_movies; i++) {
    if (strcmp(title, movies[i].title) == 0) {
      rating = movies[i].rating;
      break;
    }
  }

  if (rating == 0) {
    printf("Movie not found.\n");
  } else {
    printf("Rating: %d\n", rating);
  }

  return 0;
}