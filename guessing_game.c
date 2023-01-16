/*
A guessing game is the first ever program I ever wrote, in Java. Now I recreated this in C
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL)); 

    /*
    srand(time(NULL)) is generally used when generating random numbers is a requirement for the program, 
    for example in games, simulations, and cryptography. 
    However, it's worth noting that in some libraries and frameworks, 
    the srand() function is called automatically on program startup, 
    so it's not always necessary to call it explicitly.
    */

    int random_number = rand() % 100 + 1; // generates a random number between 0 and 100 but adds 
    int guess;
    int number_of_guess;


    do {
        // printf("Random number: %d\n", random_number); prints out random number
        printf("\nEnter a number between 0 and 100: ");
        scanf("%d", &guess);
        number_of_guess++;

        if(guess > random_number) {
            printf("%d is too high.", guess);
        } else if(guess < random_number) {
            printf("%d is too low.", guess);
        } else {
            printf("%d is correct!\n", guess);
            printf("It only took you %d guesses.\n", number_of_guess);
            break;
        }

    } while (guess != random_number);



    return 0;
}
