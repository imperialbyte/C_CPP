#include <iostream>

/*
    Luhn Algorithm

    1. Double every second digit from RIGHT to LEFT
        If doubled number is 2 digits, split them 
    2. Add all single digits from step one
    3. Add all odd numbered digits from RIGHT to LEFT.
        This means the odd place, not odd numbers.
    4. Sum results from step 2 and 3.
    5. If step 4 is divisible by 10, number is valid.


    Valid Credit card example: 6011000990139424
*/

//typedef to declare a synonym for an existing data type.
typedef std::string string;

//Function prototypes
int get_digit(const int number);
int sum_odd_digits(const std::string card_number);
int sum_even_digits(const std::string card_number);

int main() {
    int result = 0;
    string card_number;

    //Request user input
    std::cout << "Enter your credit card number #: " << std::endl;
    std::cin >> card_number;

    //Sum up the result of the sum_even_digits function and sum_odd_digits function
    result = sum_even_digits(card_number) + sum_odd_digits(card_number);

    //Debugging line to show the length of the credit card number string
    std::cout << card_number.size() << std::endl;

    //Check if the result is divisible by 10
    if(result % 10 == 0)
    {
        //If divisible by 10, the credit card number is valid
        std::cout << "Your credit card is valid." << std::endl;
    } else {
        //If not divisible by 10, the credit card number is invalid
        std::cout << "Your credit card is invalid." << std::endl;
    }

    return 0;
}

//A function to sum the digits of a number
int get_digit(const int number) {
    return number % 10 + (number / 10 % 10);
}

//A function to sum the odd numbered digits of a credit card number
int sum_odd_digits(const std::string card_number) {

    int sum = 0;

    //Loop through the credit card number string starting from the rightmost digit
    //and adding every second digit (odd position) to the sum
    for (int i = card_number.size() - 1; i >= 0; i-=2) {
        sum += card_number[i] - '0';
    }

    return sum;
}

//A function to sum the even numbered digits of a credit card number
int sum_even_digits(const std::string card_number) {

    int sum = 0;

    //Loop through the credit card number string starting from the second rightmost digit
    //and adding every second digit (even position) to the sum
    for (int i = card_number.size() - 2; i >= 0; i-=2) {
        sum += get_digit((card_number[i] - '0') * 2);
    }

    return sum;
}
