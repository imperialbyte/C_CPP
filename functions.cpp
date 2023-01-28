#include <iostream>

using namespace std;

int power(int value, int times);
string reverse_string(string value);

int main() {

    cout << reverse_string(".yadot nuf emos evah ot ekil dluow I !dlroW olleH") << endl;

    return 0;
}

int power(int value, int times) {
    int result = 1;
    for (int i = 1; i <= times; i++) // i is 1, while i is less than or equal to number of times, run the loop
    {
        result = result * value; // result times value how many times
    }
    return result;
}

string reverse_string(string value) {
    for (int i = value.length(); i >= 0; i--) {
        cout << value[i];
    }
    return "";
}
