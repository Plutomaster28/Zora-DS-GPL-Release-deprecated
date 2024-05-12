#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> files;

void showCredits() {
  std::cout << "\n©Zora 1.0.0 system is licensed under the GPL License." << std::endl;
  std::cout << "\n1985 Meisei™ " << std::endl;
}

void createFile(const std::string &filename) {
  std::ofstream file(filename);
  file.close();
  std::cout << "File " << filename << " created successfully." << std::endl;
}

void deleteFile(const std::string &filename) {
  if (remove(filename.c_str()) != 0) {
    std::perror("Error deleting file");
  } else {
    std::cout << "File " << filename << " deleted successfully." << std::endl;
  }
}

void viewFiles() {
  std::cout << "Files stored in the terminal: " << std::endl;
  for (const auto &file : files) {
    std::cout << file << std::endl;
  }
}

void fileExplorer() {
  int choice;
  std::string filename;
  while (true) {
    std::cout << "File Explorer Menu:\n1. Create File\n2. Delete File\n3. View Files\n4. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    switch (choice) {
      case 1:
        std::cout << "\nEnter the filename to create: ";
        std::cin >> filename;
        createFile(filename);
        break;
      case 2:
        std::cout << "\nEnter the filename to delete: ";
        std::cin >> filename;
        deleteFile(filename);
        break;
      case 3:
        viewFiles();
        break;
      case 4:
        std::cout << "\nReturning to Main Menu..." << std::endl;
        return;
      default:
        std::cout << "\nInvalid choice. Please try again." << std::endl;
    }
  }
}

void displayDateTime() {
  time_t now = time(0);
  char *dt = ctime(&now);
  std::cout << "The local date and time is: " << dt << std::endl;
}

void systemInformation() {
  std::cout << "\nRunning Version 1.0 of Zora" << std::endl;
  showCredits();
}

void userInformation(const std::string &username, const std::string &password) {
  if (password == "admin") {
    std::cout << "\nWelcome, " << username << "! Here is some system information..." << std::endl;
    std::cout << "\nAdmin: " << username << std::endl;
  } else {
    std::cout << "\nAccess denied. Incorrect password." << std::endl;
  }
  showCredits();
}

bool basicShell() {
    std::string input;
    bool shouldReturn = false;
    while (true) {
        std::cout << "$ ";
        std::getline(std::cin, input);
        if (input == "exit") {
            shouldReturn = true;
            break; 
        } else if (input == "list") {
            viewFiles();
        } else if (input == "create") {
            std::string filename;
            std::cout << "Enter the filename to create: ";
            std::cin >> filename;
            createFile(filename);
        } else if (input == "delete") {
            std::string filename;
            std::cout << "Enter the filename to delete: ";
            std::cin >> filename;
            deleteFile(filename);
        } else {
            if (!input.empty()) {
                std::cout << "Error: Unknown command" << std::endl;
            }
        }
    }
    return shouldReturn;  
}

int main() {
  displayDateTime();
  std::string username, password;
  std::cout << "Enter username: ";
  std::cin >> username;
  std::cout << "Enter password: ";
  std::cin >> password;

  int choice;
  while (true) {
    std::cout << "\nWelcome! " << username << std::endl;
    std::cout
        << "\nMenu: \n1. Files\n2. System Information\n3. User Information\n4. Shell\n5. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      fileExplorer();
      break;
    case 2:
      systemInformation();
      break;
    case 3:
      userInformation(username, password);
      break;
    case 4:
      basicShell();
      break;
    case 5:
      std::cout << "Exiting...";
      return 0;
    default:
      std::cout << "Invalid choice. Please try again.";
    }
  }
  return 0;
}

// placeholder because i messed up initial commit qwq