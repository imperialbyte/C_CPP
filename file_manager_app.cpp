#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

// terrible

void print_animation(std::string text);
void create_file(const std::string& filename);
bool delete_file(const std::string& filename);
bool read_file(const std::string& filename);
void edit_file(const std::string& filename);

int main() {
    std::string filename;
    int option;

    while (true) {
        std::cout << "\n";
        std::cout << "File Manager" << std::endl;
        std::cout << "1. Read file" << std::endl;
        std::cout << "2. Edit file" << std::endl;
        std::cout << "3. Create file" << std::endl;
        std::cout << "4. Delete file" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cin >> option;
        std::cin.ignore();

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Enter a number between 1 and 5" << std::endl;
        }

        switch (option)
        {
        case 1:
            std::cout << "Enter filename" << std::endl;
            getline(std::cin, filename);
            read_file(filename);
            break;

        case 2:
            std::cout << "Enter filename" << std::endl;
            getline(std::cin, filename);
            edit_file(filename);
            break;

        case 3:
            std::cout << "Enter a filename" << std::endl;
            getline(std::cin, filename);
            create_file(filename);
            break;

        case 4:
            std::cout << "Enter a filename" << std::endl;
            getline(std::cin, filename);
            delete_file(filename);
            break;
        
        case 5:
            print_animation("Goodbye!");
            break;

        default:
            std::cout << "Invalid Option" << std::endl;
            break;
        }
    }

    
    return 0;
}

void create_file(const std::string& filename) {
    std::ofstream outfile;
    outfile.open(filename);
    outfile.close();
}

bool delete_file(const std::string& filename) {
    if(std::remove(filename.c_str()) != 0) {
        std::cerr << "Error deleting file: " << filename << std::endl;
        return false;
    }
    std::cout << "File successfully deleted: " << filename << std::endl;
    return true;
}

void print_animation(std::string text) {
    for(int i = 0; i < text.length(); i++) {
        std::cout << text[i];
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

bool read_file(const std::string& filename) {
    std::ifstream fileRead(filename, std::ios::in);
    if(fileRead.is_open() != false) {
        std::string line;
        while (std::getline(fileRead, line)) {
            std::cout << line << std::endl;
        }
        fileRead.close();
        return true;
    } else {
        std::cout << "Error reading file " << filename << std::endl;
        return false;
    }
}

void edit_file(const std::string& filename) {
    std::string line;
    std::ofstream fileEdit(filename, std::ios::app);

    if (fileEdit.is_open()) {
        std::cout << "Editing " << filename << std::endl;
        std::cout << "Enter '/q' on a new line to exit and save changes." << std::endl;

        do {
            std::getline(std::cin, line);
            if (line == "/q") {
                break;
            }
            fileEdit << line << std::endl;
        } while (line != "/q");

        fileEdit.close();
        std::cout << "File saved: " << filename << std::endl;
    } else {
        std::cout << "Error opening file for editing: " << filename << std::endl;
    }
}
