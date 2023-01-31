#include <stdlib.h> // includes standard library for srand and rand functions
#include <stdio.h> // includes standard input/output library for printf and scanf functions
#include <time.h> // includes time library for time function

int main() {
    srand(time(NULL)); // generates a random seed using the current time as input for srand function
 
    int random_number = rand() % 100 + 1; // generates a random number between 0 and 100 but adds 1 to get a range of 1 to 100
    int guess; // integer variable to store the player's guess
    int number_of_guess = 0; // integer variable to store the number of guesses, initialized to 0


    do { // start of a do-while loop that continues until the player guesses the correct number
        printf("\nEnter a number between 0 and 100: "); // prompt for player's guess
        scanf("%d", &guess); // scan the player's guess and store it in the variable 'guess'
        number_of_guess++; // increment the number of guesses by 1

        if(guess > random_number) { // if player's guess is greater than the random number
            printf("%d is too high.", guess); // print that the guess is too high
        } else if(guess < random_number) { // if player's guess is less than the random number
            printf("%d is too low.", guess); // print that the guess is too low
        } else { // if player's guess is equal to the random number
            printf("%d is correct!\n", guess); // print that the guess is correct
            printf("It only took you %d guesses.\n", number_of_guess); // print the number of guesses
            break; // exit the do-while loop
        }

    } while (guess != random_number); // continue the do-while loop until the player's guess is equal to the random number



    return 0; // return 0 to indicate that the program has run successfully
}
