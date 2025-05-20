//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#define SHADOW 0xDEADBEAF
#define NULL 0

typedef struct {
    char name[32];
    int room_number;
    int check_in;
    int check_out;
} guest_t;

typedef struct {
    guest_t guests[10];
    int num_guests;
} hotel_t;

void encrypt_string(char *str, int key) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = (str[i] + key) & 0xFF;
    }
}

void decrypt_string(char *str, int key) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = (str[i] - key + 0xFF) & 0xFF;
    }
}

hotel_t *hotel_init() {
    hotel_t *hotel = malloc(sizeof(hotel_t));
    hotel->num_guests = 0;
    encrypt_string(hotel->guests[0].name, SHADOW);
    return hotel;
}

void add_guest(hotel_t *hotel, char *name, int room_number, int check_in, int check_out) {
    if (hotel->num_guests < 10) {
        guest_t guest = {name, room_number, check_in, check_out};
        encrypt_string(guest.name, SHADOW);
        hotel->guests[hotel->num_guests++] = guest;
    } else {
        printf("Hotel is full.\n");
    }
}

guest_t *find_guest(hotel_t *hotel, char *name) {
    int i;
    for (i = 0; i < hotel->num_guests; i++) {
        if (strcmp(hotel->guests[i].name, name) == 0) {
            decrypt_string(hotel->guests[i].name, SHADOW);
            return &hotel->guests[i];
        }
    }
    return NULL;
}

void print_guest(guest_t *guest) {
    printf("%s, Room %d: Checked in on %d, Checked out on %d\n", guest->name, guest->room_number, guest->check_in, guest->check_out);
}

void print_hotel(hotel_t *hotel) {
    int i;
    printf("Hotel:\n");
    for (i = 0; i < hotel->num_guests; i++) {
        print_guest(&hotel->guests[i]);
    }
}

int main() {
    hotel_t *hotel = hotel_init();
    add_guest(hotel, "John Doe", 1, 20211015, 20211017);
    add_guest(hotel, "Jane Doe", 2, 20211018, 20211020);
    guest_t *john = find_guest(hotel, "John Doe");
    print_guest(john);
    print_hotel(hotel);
    free(hotel);
    return 0;
}