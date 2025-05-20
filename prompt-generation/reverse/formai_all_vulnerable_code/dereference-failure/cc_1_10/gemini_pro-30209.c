//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#define VACANT 0
#define BOOKED 1

struct Room {
  int roomNumber;
  int status;
  int price;
};

struct Booking {
  int bookingId;
  int roomNumber;
  int startDate;
  int endDate;
};

struct Hotel {
  struct Room rooms[100];
  struct Booking bookings[100];
  int numRooms;
  int numBookings;
};

struct Hotel *createHotel(int numRooms) {
  struct Hotel *hotel = malloc(sizeof(struct Hotel));
  hotel->numRooms = numRooms;

  for (int i = 0; i < numRooms; i++) {
    hotel->rooms[i].roomNumber = i;
    hotel->rooms[i].status = VACANT;
    hotel->rooms[i].price = 100;
  }

  hotel->numBookings = 0;

  return hotel;
}

void bookRoom(struct Hotel *hotel, int roomNumber, int startDate, int endDate) {
  if (hotel->rooms[roomNumber].status == VACANT) {
    hotel->rooms[roomNumber].status = BOOKED;

    int bookingId = hotel->numBookings++;

    hotel->bookings[bookingId].bookingId = bookingId;
    hotel->bookings[bookingId].roomNumber = roomNumber;
    hotel->bookings[bookingId].startDate = startDate;
    hotel->bookings[bookingId].endDate = endDate;
  }
}

void cancelBooking(struct Hotel *hotel, int bookingId) {
  for (int i = 0; i < hotel->numBookings; i++) {
    if (hotel->bookings[i].bookingId == bookingId) {
      hotel->rooms[hotel->bookings[i].roomNumber].status = VACANT;
      hotel->bookings[i] = hotel->bookings[hotel->numBookings - 1];
      hotel->numBookings--;
      break;
    }
  }
}

void printHotel(struct Hotel *hotel) {
  printf("Hotel Rooms:\n");
  for (int i = 0; i < hotel->numRooms; i++) {
    printf("Room %d: ", hotel->rooms[i].roomNumber);
    if (hotel->rooms[i].status == VACANT) {
      printf("VACANT\n");
    } else {
      printf("BOOKED\n");
    }
  }

  printf("\nHotel Bookings:\n");
  for (int i = 0; i < hotel->numBookings; i++) {
    printf("Booking %d: Room %d, Start Date: %d, End Date: %d\n",
           hotel->bookings[i].bookingId, hotel->bookings[i].roomNumber,
           hotel->bookings[i].startDate, hotel->bookings[i].endDate);
  }
}

void destroyHotel(struct Hotel *hotel) { free(hotel); }

int main() {
  struct Hotel *hotel = createHotel(10);

  bookRoom(hotel, 0, 1, 3);
  bookRoom(hotel, 2, 5, 7);
  bookRoom(hotel, 4, 9, 11);

  printHotel(hotel);

  cancelBooking(hotel, 1);

  printHotel(hotel);

  destroyHotel(hotel);

  return 0;
}