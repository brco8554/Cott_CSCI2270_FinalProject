#include "TotalControl.h"
#include <iostream>
#include <string>

int main()
{
    // Sets up strings to be used during main function
    std::string cityFname, connectFname, civilFname;
    std::string city, name, hair, eyes, emptyCity, relocateCity;
    // File names to be read for data
    cityFname = "citylist1.txt";
    connectFname = "cityconnections1.txt";
    civilFname = "civilians1.txt";

    // Uses constructor to create class country
    dictatorship country(cityFname,connectFname,civilFname);

    // Creates a main menu for easy traversal of the 8 functional public functions
    std::string userChoice = "";
    while (userChoice != "9")
    {
        std::cout << "======Main Menu======" << std::endl;
        std::cout << "1. Select city" << std::endl;
        std::cout << "2. List all cities" << std::endl;
        std::cout << "3. List populace" << std::endl;
        std::cout << "4. Execute citizen" << std::endl;
        std::cout << "5. Add citizen" << std::endl;
        std::cout << "6. Glass city" << std::endl;
        std::cout << "7. Relocate citizen" << std::endl;
        std::cout << "8. Relocate population" << std::endl;
        std::cout << "9. Quit" << std::endl;
        country.printCurrentCity();
        getline(std::cin,userChoice);
        if (userChoice == "1")
        {
            // Select City public function
            std::cout << "Enter city name:" << std::endl;
            getline(std::cin, city);
            country.selectCity(city);
        }
        else if (userChoice == "2")
        {
            // List all cities public function
            country.listCities();
        }
        else if (userChoice == "3")
        {
            // List population public function
            country.listCitizens();
        }
        else if (userChoice == "4")
        {
            // Execute citizen public function
            std::cout << "Enter citizen name:" << std::endl;
            getline(std::cin, name);
            country.executeCitizen(name);
        }
        else if (userChoice == "5")
        {
            // Add citizen to currently selected city public function
            std::cout << "Enter citizen name:" << std::endl;
            getline(std::cin, name);
            std::cout << "Enter citizen hair color ('none' if bald):" << std::endl;
            getline(std::cin, hair);
            std::cout << "Enter citizen eye color ('black' if unknown):" << std::endl;
            getline(std::cin, eyes);
            country.addCitizen(name,hair,eyes);
        }
        else if (userChoice == "6")
        {
            // Glass city public function
            // Destroy all inhabitants of a city
            std::cout << "Enter city name:" << std::endl;
            getline(std::cin, city);
            country.glassCity(city);
        }
        else if (userChoice == "7")
        {
            // Relocate citizen public function
            // Move one citizen from one city to another
            std::cout << "Enter citizen name:" << std::endl;
            getline(std::cin, name);
            std::cout << "Enter city name to move to:" << std::endl;
            getline(std::cin, city);
            country.moveCitizen(name,city);
        }
        else if (userChoice == "8")
        {
            // Relocate populace public function
            // Move entire population of one city to another
            std::cout << "Enter city name to vacate:" << std::endl;
            getline(std::cin, emptyCity);
            std::cout << "Enter city name to fill:" << std::endl;
            getline(std::cin, relocateCity);
            country.relocatePopulace(emptyCity,relocateCity);
        }
    }
    std::cout << "In a final act of tyranny, as you walk out of your office," << std::endl;
    std::cout << "you launch the entire supply of nuclear warheads" << std::endl;
    std::cout << "and execute your advisor." << std::endl;
}
