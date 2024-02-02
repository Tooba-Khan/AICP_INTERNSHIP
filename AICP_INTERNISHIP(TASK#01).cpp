#include <iostream>
#include <string>
#include <cmath> // for absolute function

const int arraySize = 30;

int main() {
    std::string studentNames[arraySize];
    double studentWeights[arraySize];
    double updatedStudentWeights[arraySize];

    // Input for student names and weights
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Enter name for student " << i + 1 << ": ";
        std::getline(std::cin, studentNames[i]);

        // Input validation for weight (between 40 and 100 kg)
        do {
            std::cout << "Enter weight for student " << i + 1 << " on first day (in kg): ";
            std::cin >> studentWeights[i];

            if (std::cin.fail() || studentWeights[i] < 40 || studentWeights[i] > 100) {
                std::cin.clear(); // clear input buffer to restore cin to a usable state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore last input
                std::cout << "Invalid input! Weight must be between 40 and 100 kg. Try again.\n";
            }
            else {
                break; // valid input, exit loop
            }
        } while (true);

        std::cin.ignore(); // clear the newline character left in the buffer
    }
    std::cout << "\n\n";
    // Input for updated student names and weights
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Enter updated weight for student " << i + 1 << " on last day (in kg): ";
        std::cin >> updatedStudentWeights[i];
        std::cin.ignore(); // clear the newline character left in the buffer
    }

    // Displaying the output and checking for differences
    std::cout << "\n\n\nStudent Data:\n";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Name: " << studentNames[i] << "\tWeight: " << studentWeights[i] << " kg\t";

        // Check the difference in weights
        double weightDifference = std::abs(studentWeights[i] - updatedStudentWeights[i]);
        if (weightDifference > 2.5) {
            if (studentWeights[i] < updatedStudentWeights[i]) {
                std::cout << "Rise: " << weightDifference << " kg for " << studentNames[i] << "\n";
            }
            else {
                std::cout << "Fall: " << weightDifference << " kg for " << studentNames[i] << "\n";
            }
        }
        else {
            std::cout << "No significant change in weight\n";
        }
    }

    return 0;
}
