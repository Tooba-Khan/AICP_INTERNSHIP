#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// Function prototypes
void calculateParkingPrice();
void keepTotalPayments();
void calculateFairerPayments();
bool validateFrequentParkingNumber(const string& number);

// Global variables
double dailyTotal = 0.0;

int main() {
    char choice;

    do {
        cout << "Choose a task to perform:\n";
        cout << "1. Calculate the price to park.\n";
        cout << "2. Keep a total of the payments.\n";
        cout << "3. Make payments fairer.\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            calculateParkingPrice();
            break;
        case '2':
            keepTotalPayments();
            break;
        case '3':
            calculateFairerPayments();
            break;
        case '4':
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != '4');

    return 0;
}

void calculateParkingPrice() {
    // Constants
    const double PRICES[7][3] = {
        {2.00, 2.00, 8},    // Sunday
        {10.00, 2.00, 2},   // Monday
        {10.00, 2.00, 2},   // Tuesday
        {10.00, 2.00, 2},   // Wednesday
        {10.00, 2.00, 2},   // Thursday
        {10.00, 2.00, 2},   // Friday
        {3.00, 2.00, 4}     // Saturday
    };
    const double DISCOUNT_BEFORE_16 = 0.10;
    const double DISCOUNT_AFTER_16 = 0.50;
    const int HOURS_IN_DAY = 24;
    const int MINUTES_IN_HOUR = 60;

    // Variables
    string day;
    int arrivalHour;
    int numHours;
    string frequentParkingNumber;
    double totalPrice;

    cout << "Enter the day of the week (e.g., Sunday, Monday, ...): ";
    cin >> day;
    cout << "Enter the arrival hour (24-hour format, excluding minutes): ";
    cin >> arrivalHour;
    cout << "Enter the number of hours to leave the car: ";
    cin >> numHours;
    cout << "Enter the frequent parking number (if available): ";
    cin >> frequentParkingNumber;

    // Validate frequent parking number
    if (!validateFrequentParkingNumber(frequentParkingNumber)) {
        cout << "Invalid frequent parking number. No discount applied.\n";
        frequentParkingNumber = ""; // Reset the number if it's invalid
    }

    // Get the price information based on the day
    int dayIndex;
    if (day == "Sunday") dayIndex = 0;
    else if (day == "Monday") dayIndex = 1;
    else if (day == "Tuesday") dayIndex = 2;
    else if (day == "Wednesday") dayIndex = 3;
    else if (day == "Thursday") dayIndex = 4;
    else if (day == "Friday") dayIndex = 5;
    else if (day == "Saturday") dayIndex = 6;
    else {
        cout << "Invalid day.\n";
        return;
    }

    // Calculate the price
    double pricePerHour = arrivalHour < 16 ? PRICES[dayIndex][0] : PRICES[dayIndex][1];
    if (!frequentParkingNumber.empty()) {
        pricePerHour -= (arrivalHour < 16 ? DISCOUNT_BEFORE_16 : DISCOUNT_AFTER_16);
    }
    totalPrice = min(numHours, static_cast<int>(PRICES[dayIndex][2])) * pricePerHour;

    cout << "Total price to park: $" << fixed << setprecision(2) << totalPrice << endl;
}

void keepTotalPayments() {
    double payment;
    double totalPrice;

    dailyTotal = 0.0;

    cout << "Enter the total price displayed for the parking: $";
    cin >> totalPrice;

    // Keep taking payments until total is covered
    do {
        cout << "Enter the payment amount (greater than or equal to the displayed amount, or enter 0 to exit): $";
        cin >> payment;

        if (payment >= totalPrice) {
            dailyTotal += payment;
            cout << "Payment accepted. Daily total: $" << fixed << setprecision(2) << dailyTotal << endl;
            break; // Exit loop if payment is enough
        }
        else {
            cout << "Payment amount is insufficient. Try again.\n";
        }
    } while (payment != 0);

    cout << "End of day. Total payments received: $" << fixed << setprecision(2) << dailyTotal << endl;
}

void calculateFairerPayments() {
    // Reusing calculateParkingPrice() function for this task as it's essentially the same calculation
    calculateParkingPrice();
}

bool validateFrequentParkingNumber(const string& number) {
    // Check if the number is 5 characters long (4 digits + 1 check digit)
    if (number.length() != 5) return false;

    // Check if all characters are digits
    for (char c : number) {
        if (!isdigit(c)) return false;
    }

    // Calculate check digit using modulo 11 check digit calculation
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += (number[i] - '0') * (i + 1);
    }
    int checkDigit = sum % 11;

    // Validate check digit
    if (checkDigit == 10) {
        if (number[4] != '0') return false;
    }
    else {
        if (checkDigit != (number[4] - '0')) return false;
    }

    return true;
}
