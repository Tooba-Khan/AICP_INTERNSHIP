#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int NUM_COWS = 4;
const int NUM_DAYS = 7;
const int MILK_THRESHOLD = 12;

struct Cow {
    string identityCode;
    vector<vector<double>> dailyYields;
};

// Function prototypes
void recordYield(Cow& cow);
double calculateWeeklyVolume(const Cow& cow);
double calculateAverageYield(const Cow& cow);
void identifyMostProductive(const map<string, Cow>& herd);

int main() {
    map<string, Cow> herd;

    // Record yields for each cow
    for (int i = 0; i < NUM_COWS; ++i) {
        Cow cow;
        cout << "Enter 3-digit identity code for cow " << i + 1 << ": ";
        cin >> cow.identityCode;
        for (int day = 0; day < NUM_DAYS; ++day) {
            cout << "Day " << day + 1 << ":\n";
            recordYield(cow);
        }
        herd[cow.identityCode] = cow;
    }

    // Calculate total weekly volume and average yield
    double totalVolume = 0;
    for (const auto& pair : herd) {
        totalVolume += calculateWeeklyVolume(pair.second);
    }
    double averageYield = totalVolume / (NUM_COWS * NUM_DAYS);

    cout << "Total weekly volume of milk for the herd: " << totalVolume << " liters\n";
    cout << "Average yield per cow in a week: " << averageYield << " liters\n";

    // Identify the most productive cow
    identifyMostProductive(herd);

    return 0;
}

void recordYield(Cow& cow) {
    vector<double> yields;
    for (int i = 0; i < 2; ++i) {
        double yield;
        cout << "Enter yield for milking " << i + 1 << ": ";
        cin >> yield;
        yields.push_back(yield);
    }
    cow.dailyYields.push_back(yields);
}

double calculateWeeklyVolume(const Cow& cow) {
    double weeklyVolume = 0;
    for (const auto& day : cow.dailyYields) {
        for (double yield : day) {
            weeklyVolume += yield;
        }
    }
    return weeklyVolume;
}

double calculateAverageYield(const Cow& cow) {
    return calculateWeeklyVolume(cow) / NUM_DAYS;
}

void identifyMostProductive(const map<string, Cow>& herd) {
    string mostProductiveCow;
    double maxWeeklyVolume = 0;

    for (const auto& pair : herd) {
        double weeklyVolume = calculateWeeklyVolume(pair.second);
        if (weeklyVolume > maxWeeklyVolume) {
            maxWeeklyVolume = weeklyVolume;
            mostProductiveCow = pair.second.identityCode;
        }
    }

    cout << "Most productive cow: " << mostProductiveCow << " with weekly volume of " << maxWeeklyVolume << " liters\n";
}
