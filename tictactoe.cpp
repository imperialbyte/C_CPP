#include <iostream>
#include <ctime>

// & address of operator
// * dereference operator

typedef std::string string;

// *spaces because we want to modify the content of spaces[9]
void draw_board(char *spaces);
void player_move(char *spaces, char player);
void computer_move(char *spaces, char computer);
bool check_winner(char *spaces, char player, char computer);
bool check_tie(char *spaces);

int main() {
    char spaces[9] =
    {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '
    };

    char player = 'X';
    char computer = 'O';
    bool running = true;

    draw_board(spaces);
    // arrays into pointers already pointer
    while (running) {
        player_move(spaces, player);
        draw_board(spaces);

        if(check_winner(spaces, player, computer))
        {
            running = false;
            break;
        } else if (check_tie(spaces)) {
            break;
        }

        computer_move(spaces, computer);
        draw_board(spaces);
        if(check_winner(spaces, player, computer))
        {
            running = false;
            break;
        } else if (check_tie(spaces)) {
            break;
        }
    }

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}

void draw_board(char *spaces) {
    std::cout << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << std::endl;
}

void player_move(char *spaces, char player) {
    int number;

    do {
        std::cout << "Enter a spot to place a marker (1-9): " << std::endl;
        std::cin >> number;

        number--;

        if(spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    } while(!number > 0 || !number < 8);
}

void computer_move(char *spaces, char computer) {
    int number;
    srand(time(NULL));

    while(true) {
        number = rand() % 9;
        if(spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

bool check_winner(char *spaces, char player, char computer) {

    if((spaces[0] != ' ') && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
        spaces[0] == player ? std::cout << "You won!" << std::endl : std::cout << "You lost!" << std::endl;
    } else if((spaces[3] != ' ') && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
        spaces[3] == player ? std::cout << "You won!" << std::endl : std::cout << "You lost!" << std::endl;
    } else if((spaces[6] != ' ') && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
        spaces[6] == player ? std::cout << "You won!" << std::endl : std::cout << "You lost!" << std::endl;
    } else if((spaces[0] != ' ') && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
        spaces[0] == player ? std::cout << "You won!" << std::endl : std::cout << "You lost!" << std::endl;
    } else if((spaces[1] != ' ') && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
        spaces[1] == player ? std::cout << "You won!" << std::endl : std::cout << "You lost!" << std::endl;
    } else if((spaces[2] != ' ') && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
        spaces[2] == player ? std::cout << "You won!" << std::endl : std::cout << "You lost!" << std::endl;
    } else if((spaces[0] != ' ') && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
        spaces[0] == player ? std::cout << "You won!" << std::endl : std::cout << "You lost!" << std::endl;
    } else if((spaces[2] != ' ') && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
        spaces[2] == player ? std::cout << "You won!" << std::endl : std::cout << "You lost!" << std::endl;
    } else {
        return false;
    }

    return true;
}

bool check_tie(char *spaces) {

    for (int i = 0; i < 9; i++) {
        if(spaces[i] == ' ') {
            return false;
        }
    }

    std::cout << "It's a tie!" << std::endl;
    return true;
}
