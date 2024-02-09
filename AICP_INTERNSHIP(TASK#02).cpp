#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Constants
const int MIN_SENIORS = 10;
const int MAX_SENIORS = 36;
const int MIN_CARERS = 2;
const int ADDITIONAL_CARERS_THRESHOLD = 24;

// Structure to hold outing details for each person
struct OutingDetails {
    string name;
    double amountPaid;
};

// Function to calculate the total cost and cost per person
pair<double, double> calculateCost(int numSeniors) {
    if (numSeniors < MIN_SENIORS || numSeniors > MAX_SENIORS) {
        cout << "Error: Number of seniors should be between 10 and 36." << endl;
        return make_pair(0.0, 0.0);
    }

    int carersNeeded = MIN_CARERS;
    if (numSeniors > ADDITIONAL_CARERS_THRESHOLD) {
        carersNeeded++;
    }

    // Define cost constants
    const double coachHire[] = { 225.0, 190.0, 150.0 };
    const double mealCost = 14.00;
    const double theatreTicketCost[] = { 13.50, 13.00, 12.00 };

    double coachCost, theatreTicket, totalCost, costPerPerson;

    // Calculate coach cost
    if (numSeniors >= 12 && numSeniors <= 16)
        coachCost = coachHire[0];
    else if (numSeniors >= 17 && numSeniors <= 26)
        coachCost = coachHire[1];
    else
        coachCost = coachHire[2];

    // Calculate theatre ticket cost
    if (numSeniors >= 12 && numSeniors <= 16)
        theatreTicket = theatreTicketCost[0];
    else if (numSeniors >= 17 && numSeniors <= 26)
        theatreTicket = theatreTicketCost[1];
    else
        theatreTicket = theatreTicketCost[2];

    // Calculate total cost and cost per person
    totalCost = coachCost + (mealCost + theatreTicket) * numSeniors;
    costPerPerson = totalCost / numSeniors;

    return make_pair(totalCost, costPerPerson);
}

int main() {
    // Task 1
    int numSeniors;
    cout << "Enter the number of seniors interested in the outing: ";
    cin >> numSeniors;

    pair<double, double> costDetails = calculateCost(numSeniors);
    double totalCost = costDetails.first;
    double costPerPerson = costDetails.second;

    if (totalCost != 0.0) {
        cout << fixed << setprecision(2);
        cout << "Total cost of the outing: $" << totalCost << endl;
        cout << "Cost per person: $" << costPerPerson << endl;
    }

    // Task 2
    vector<OutingDetails> outingDetails;
    int numExtraPeople;
    cout << "Enter the number of extra people (if any): ";
    cin >> numExtraPeople;
    for (int i = 0; i < numSeniors + numExtraPeople; ++i) {
        OutingDetails person;
        cout << "Enter the name of person " << i + 1 << ": ";
        cin >> person.name;
        if (i < numSeniors) {
            cout << "Enter the amount paid by " << person.name << ": $";
            cin >> person.amountPaid;
        }
        else {
            person.amountPaid = costPerPerson;
        }
        outingDetails.push_back(person);
    }

    // Print list of people on the outing
    cout << "List of people on the outing:" << endl;
    for (const auto& person : outingDetails) {
        cout << person.name << " - Amount Paid: $" << person.amountPaid << endl;
    }

    // Task 3
    double totalCollected = 0.0;
    for (const auto& person : outingDetails) {
        totalCollected += person.amountPaid;
    }

    cout << fixed << setprecision(2);
    if (totalCollected >= totalCost) {
        cout << "The outing has made a profit of $" << totalCollected - totalCost << "." << endl;
    }
    else {
        cout << "The outing has not made a profit and has a shortfall of $" << totalCost - totalCollected << "." << endl;
    }

    return 0;
}
