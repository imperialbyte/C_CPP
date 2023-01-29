#include <iostream>
#include <limits>
#include <Windows.h>
#include <thread>

// russian roulette version 2


const int MAX_ROUNDS = 6;

std::string print_animation(std::string text);

int option;

int active_chamber = 0;
int current_chamber = 1;
int score = 0;
bool alive = true;

void spin_chamber()
{
    active_chamber = rand() % MAX_ROUNDS + 1;
    current_chamber = 1;
    print_animation("You spun the chamber!");
    std::cout << std::endl;
}

void shoot()
{
    if(current_chamber == active_chamber)
    {
        std::cout << "***BANG!***" << std::endl;
        Sleep(1000);
        print_animation("You are dead!");
        std::cout << std::endl;
        std::cout << "You clicked the trigger " << score << " time(s) before you died" << std::endl;
        current_chamber++;
        alive = false;
    } else {
        std::cout << "**CLICK!**" << std::endl;
        Sleep(1000);
        print_animation("Nothing happened...");
        std::cout << std::endl;
        score++;
        current_chamber++;
    }
}

void reveal_chamber() {
    print_animation("The bullet is at chamber "); std::cout<< active_chamber; print_animation("...");
    Sleep(500);
    std::cout << std::endl;
    print_animation("Your gun is at chamber "); std::cout<< current_chamber; print_animation("...");
    std::cout << std::endl;

    if(current_chamber == active_chamber) {
        print_animation("You will be killed if you pull the trigger!");
        std::cout << std::endl;
    }
}

int main() {
    srand(time(NULL));

    print_animation("****************");
    std::cout << std::endl;
    print_animation("RUSSIAN ROULETTE");
    std::cout << std::endl;
    print_animation("****************");
    std::cout << std::endl;
    Sleep(1000);
    print_animation("WELCOME TO RUSSIAN ROULETTE!");
    std::cout << std::endl;
    Sleep(500);
    print_animation("There are no winners here...");
    std::cout << std::endl;
    Sleep(1000);
    print_animation("You have a revolver,\nwhat would you like to do?");
    std::cout << std::endl;

    active_chamber = rand() % MAX_ROUNDS + 1;

    do
    {
        std::cout << "1. Shoot" << std::endl;
        std::cout << "2. Spin chamber" << std::endl;
        std::cout << "3. Reveal chamber" << std::endl;
        std::cout << "4. Fold" << std::endl;
        std::cout << "Input(1-4): ";
        std::cin >> option;
        std::cout << std::endl;

        if(std::cin.fail() || option > 4 || option < 1 || std::cin.fail()) {
            print_animation("Invalid input, please enter a number between 1 and 4.");
            std::cout << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // clear the input buffer and ignore any other input until newline character is reached
        }
        else {
            switch (option)
            {
                case 1:
                    shoot();
                    break;
                case 2:
                    spin_chamber();
                    break;
                case 3:
                    reveal_chamber();
                    break;
                case 4:
                    print_animation("You decided to quit!");
                    return 0;
                default:
                    std::cout << "How did you even get this error?" << std::endl;
                    break;
            }
        }
    } while (alive);
    

    return 0;
}

std::string print_animation(std::string text)
{
    for (int i = 0; i < text.length(); i++) {
        std::cout << text[i];
        Sleep(50);
    }
    return "";
}
