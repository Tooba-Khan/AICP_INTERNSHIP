#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// Constants for ticket prices
const map<string, double> ONE_DAY_TICKET_PRICES = {
    {"adult", 20.00},
    {"child", 12.00},
    {"senior", 16.00},
    {"family", 60.00}
};

const map<string, double> TWO_DAY_TICKET_PRICES = {
    {"adult", 30.00},
    {"child", 18.00},
    {"senior", 24.00},
    {"family", 90.00}
};

const map<string, double> EXTRA_ATTRACTION_PRICES = {
    {"lion feeding", 2.50},
    {"penguin feeding", 2.00},
    {"evening barbecue", 5.00}
};

// Function to display ticket options and prices for one-day tickets
void display_one_day_ticket_options() {
    cout << "Ticket Options for One-Day Visit:" << endl;
    for (const auto& ticket : ONE_DAY_TICKET_PRICES) {
        cout << ticket.first << ": $" << ticket.second << endl;
    }
}

// Function to display ticket options and prices for two-day tickets
void display_two_day_ticket_options() {
    cout << "Ticket Options for Two-Day Visit:" << endl;
    for (const auto& ticket : TWO_DAY_TICKET_PRICES) {
        cout << ticket.first << ": $" << ticket.second << endl;
    }
}

// Function to display available attractions and prices
void display_attractions() {
    cout << "Extra Attractions:" << endl;
    for (const auto& attraction : EXTRA_ATTRACTION_PRICES) {
        cout << attraction.first << ": $" << attraction.second << endl;
    }
}

// Function to process a booking
void process_booking() {
    // Input ticket type and quantity
    string ticket_type;
    int quantity;
    cout << "Enter ticket type (adult/child/senior/family): ";
    cin >> ticket_type;
    cout << "Enter quantity: ";
    cin >> quantity;

    // Calculate total cost
    double total_cost = 0.0;
    if (ONE_DAY_TICKET_PRICES.find(ticket_type) != ONE_DAY_TICKET_PRICES.end()) {
        total_cost = ONE_DAY_TICKET_PRICES.at(ticket_type) * quantity;
    }
    else if (TWO_DAY_TICKET_PRICES.find(ticket_type) != TWO_DAY_TICKET_PRICES.end()) {
        total_cost = TWO_DAY_TICKET_PRICES.at(ticket_type) * quantity;
    }

    // Input extra attractions
    string attraction;
    cout << "Enter extra attractions (separated by space, enter 'done' to finish): ";
    vector<string> chosen_attractions;
    while (cin >> attraction && attraction != "done") {
        chosen_attractions.push_back(attraction);
    }

    // Calculate extra attractions cost
    for (const auto& chosen_attraction : chosen_attractions) {
        if (EXTRA_ATTRACTION_PRICES.find(chosen_attraction) != EXTRA_ATTRACTION_PRICES.end()) {
            total_cost += EXTRA_ATTRACTION_PRICES.at(chosen_attraction);
        }
    }

    // Display booking details
    cout << "Total cost: $" << fixed << setprecision(2) << total_cost * quantity << endl;
}

int main() {
    // Task 1 - Displaying ticket options and attractions
    display_one_day_ticket_options();
    cout << endl;
    display_two_day_ticket_options();
    cout << endl;
    display_attractions();
    cout << endl;

    // Task 2 - Process a booking
    process_booking();

    return 0;
}
