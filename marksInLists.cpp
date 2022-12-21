// Copyright Cristiano 2022
//
// Created by Cristiano Sellitto
// Created in December 2022
// A program that puts marks in a list and calculates the average of the list

#include <iostream>
#include <iomanip>
#include <list>

float findAverageInAList(std::list<int> list) {
    // Calculates the average of a list

    int sum = 0;
    float average = 0;

    for (int number : list) {
        sum += number;
    }
    average = static_cast<float>(sum) / list.size();

    return average;
}

int main() {
    // Gets marks, puts the marks in a list and calls the average function

    int markInt;
    float markAverage;
    std::string markText;
    std::list<int> markList;

    std::cout << "Enter marks | Enter a negative number to stop\n";
    std::cout << std::endl;
    while (true) {
        try {
            std::cout << "Enter a mark percent: ";
            std::cin >> markText;
            markInt = stoi(markText);
            if (markInt >= 0 && markInt <= 100) {
                markList.push_back(markInt);
            } else if (markInt > 100) {
                std::cout << std::endl;
                std::cout << "This isn't a valid mark.\n";
                std::cout << std::endl;
            } else {
                break;
            }
        } catch (std::invalid_argument) {
            std::cout << std::endl;
            std::cout << "This isn't a valid mark.\n";
            std::cout << std::endl;
        }
    }
    markAverage = findAverageInAList(markList);
    std::cout << std::endl;
    std::cout << "The mark average is ";
    std::cout << markAverage << std::setprecision(2) << ".";
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Done." << std::endl;
}
