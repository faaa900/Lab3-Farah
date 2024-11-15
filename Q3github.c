

#include <stdio.h>
#include <string.h>

#define NUM_TEAMS 10
#define SQUAD_SIZE 25

//Data structs
typedef struct {
    int day, month, year;
} birth_date_t;//Creates a struct to store birthdays

typedef struct {
    char name[25];
    int kit_number;
    char club[20];
    birth_date_t dob;
    char position[15];
} player_t;//Creates a struct that stores players' details

typedef struct {
    char team_name[20];
    player_t players[SQUAD_SIZE];
    int active_size;  // Current number of players in the squad
} club_t;

club_t clubs[NUM_TEAMS];
int club_count = 0;

//Function prototypes
void display_menu();
void enroll_club();

int main()
{
    display_menu();

    return 0;
}

void display_menu() {// Displays a menu with options
    printf("\n-- Menu --\n");
    printf("1. Enroll Club\n");
    printf("2. Add Player\n");
    printf("3. Search and Update Player\n");
    printf("4. Display Club Statistics\n");
    printf("Any other number to Exit\n");
}

void enroll_club() {// Allows input of a certain number of teams
    if (club_count >= NUM_TEAMS) {
        handle_error("Maximum number of clubs reached.");
        return;
    }
    printf("Enter club name: ");
    scanf(" %[^\n]", clubs[club_count].team_name);
    clubs[club_count].active_size = 0;
    club_count++;
    printf("Club enrolled successfully!\n");
}