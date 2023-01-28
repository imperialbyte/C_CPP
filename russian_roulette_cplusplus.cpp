#include <iostream>
#include <limits>

const int MAX_ROUNDS = 6;

int option;

int active_chamber = 0;
int current_chamber = 1;
int score = 0;
bool alive = true;

void spin_chamber()
{
    active_chamber = rand() % MAX_ROUNDS;
    current_chamber = 1;
    std::cout << "You spun the chamber!" << std::endl;
}

void shoot()
{
    if(current_chamber == active_chamber)
    {
        std::cout << "You are dead." << std::endl;
        std::cout << "You clicked the trigger " << score << " time(s) before you died" << std::endl;
        current_chamber++;
        alive = false;
    } else {
        std::cout << "You are alive!!!" << std::endl;
        score++;
        current_chamber++;
    }
}

void reveal_chamber() {
    std::cout << "The bullet is at chamber " << active_chamber << std::endl;
    std::cout << "You are at chamber " << current_chamber << std::endl;
}

int main() {
    srand(time(NULL));

    std::cout << "****************" << std::endl;
    std::cout << "RUSSIAN ROULETTE" << std::endl;
    std::cout << "****************" << std::endl;
    std::cout << "You have a revolver,\nwhat would you like to do?" << std::endl;

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
            std::cout << "Invalid input, please enter a number between 1 and 4." << std::endl;
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
                    std::cout << "*******************" << std::endl;
                    std::cout << "YOU DECIDED TO QUIT" << std::endl;
                    std::cout << "*******************" << std::endl;
                    return 0;
                default:
                    std::cout << "How did you even get this error?" << std::endl;
                    break;;
            }
        }

    } while (alive);
    

    return 0;
}
