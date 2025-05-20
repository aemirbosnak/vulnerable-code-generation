//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char *name;
  char *date;
  char *time;
  char *description;
} Appointment;

Appointment *create_appointment(char *name, char *date, char *time, char *description) {
  Appointment *appointment = malloc(sizeof(Appointment));
  appointment->name = strdup(name);
  appointment->date = strdup(date);
  appointment->time = strdup(time);
  appointment->description = strdup(description);
  return appointment;
}

void print_appointment(Appointment *appointment) {
  printf("%s\n%s\n%s\n%s\n", appointment->name, appointment->date, appointment->time,
         appointment->description);
}

int main() {
  srand(time(NULL));

  // Create a list of surrealist appointment names.
  char *surrealist_names[] = {
      "The Unfathomable Abyss", "The Celestial Symphony", "The Cosmic Tea Party", "The Dali-esque Dream",
      "The Escherian Labyrinth", "The Magrittean Riddle", "The Miroian Tapestry", "The Tanguyan Dream",
      "The Ernstian Collage", "The Chagallian Flight"};

  // Create a list of surrealist appointment dates.
  char *surrealist_dates[] = {
      "The Day the Moon Turned Blue", "The Night the Stars Danced", "The Afternoon the Time Stood Still",
      "The Morning the Sun Sang", "The Evening the Shadows Vanished", "The Hour the Clocks Melted",
      "The Minute the World Turned Upside Down", "The Second the Past Met the Future", "The Moment the Dream Became Reality",
      "The Epoch the Void Stirred"};

  // Create a list of surrealist appointment times.
  char *surrealist_times[] = {
      "The Hour of the Owl", "The Dawn of the Jellyfish", "The Twilight of the Unicorn", "The Midnight of the Sphinx",
      "The Dusk of the Manticore", "The Noon of the Centaur", "The Vespers of the Griffin", "The Matin of the Phoenix",
      "The Eventide of the Basilisk", "The Prime of the Chimera"};

  // Create a list of surrealist appointment descriptions.
  char *surrealist_descriptions[] = {
      "A journey to the center of the subconscious", "A conversation with the unconscious mind",
      "A glimpse into the future", "A retelling of the past", "A dream that defies description",
      "A nightmare that haunts the soul", "A vision that inspires the spirit", "A prophecy that foretells the unknown",
      "A mystery that unravels the fabric of reality", "A truth that shatters the illusion"};

  // Create an array of appointments.
  Appointment *appointments[10];

  // Generate 10 random appointments.
  for (int i = 0; i < 10; i++) {
    int name_index = rand() % 10;
    int date_index = rand() % 10;
    int time_index = rand() % 10;
    int description_index = rand() % 10;
    appointments[i] = create_appointment(surrealist_names[name_index], surrealist_dates[date_index],
                                        surrealist_times[time_index],
                                        surrealist_descriptions[description_index]);
  }

  // Print the appointments.
  for (int i = 0; i < 10; i++) {
    print_appointment(appointments[i]);
    printf("\n");
  }

  return 0;
}