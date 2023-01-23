#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_ROUNDS = 6;

int current_chamber = 1;
int active_chamber = 0;

int decision;
int score = 1;

int dead = 0;


void spin_chamber() {
    active_chamber = rand() % 6 + 1; // generates a random number between 0 and 5 and adds 1
    current_chamber = 1; // resets chamber
    printf("You spun the chamber.\n");
}

void pull_trigger() {
    if(current_chamber == active_chamber) {
        dead = 1; // dead = true, breaking out of game loop
        printf("YOU DIED!!!\n***GAME OVER***\n");
        printf("You pulled the trigger %d time(s) and luck ran out.\n", score);
    } else {
        printf("***You Lived!***\n");
        current_chamber++; // increments the current chamber
        score++; // increments the current score
    }
}

int main() {
    srand(time(NULL));
    active_chamber = rand() % 6 + 1;
    printf("****************************************\n");
    printf("    **Welcome to Russian Roulette!**    \n");
    printf("****************************************\n");
    printf("    **What would you like to do?**      \n");
    int n = 0;
    do {
        printf("1. Spin chamber\n2. Pull trigger\n3. Reveal Chamber\n4. Fold\nEnter choice: ");
        n = scanf("%d", &decision);
        if(n != 1) {
            printf("*****Invalid input, please enter a number*****\n");
            scanf("%*s"); // read and discard the invalid input
        }
        else if(decision > 4 || decision < 1)
        {
            printf("*****Invalid choice, please enter a valid choice*****\n");
        }
        else
        {
            switch(decision)
            {
                case 1:
                    spin_chamber();
                    break;
                case 2:
                    pull_trigger();
                    break;
                case 3:
                    printf("Bullet is at chamber %d and you are at chamber %d.\n", active_chamber, current_chamber);
                    break;
                case 4:
                    printf("You decided not to play anymore.\n");
                    return 0; // terminates program
                    break;
            }
        }

    } while (!dead);

    return 0;
}
