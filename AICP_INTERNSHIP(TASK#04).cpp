#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent an item in the auction
struct AuctionItem {
    int itemNumber;
    string description;
    double reservePrice;
    int numberOfBids;
    double highestBid;
    bool sold;
};

// Function prototypes
void setupAuction(vector<AuctionItem>& items);
void placeBid(vector<AuctionItem>& items, int buyerNumber);
void endAuction(vector<AuctionItem>& items);

int main() {
    vector<AuctionItem> items;

    // Task 1 - Setup auction
    setupAuction(items);

    // Task 2 - Buyer bids
    int numBuyers;
    cout << "Enter the number of buyers: ";
    cin >> numBuyers;
    for (int i = 0; i < numBuyers; ++i) {
        cout << "\nBuyer " << i + 1 << ":\n";
        placeBid(items, i + 1);
    }

    // Task 3 - End of auction
    endAuction(items);

    return 0;
}

void setupAuction(vector<AuctionItem>& items) {
    int numItems = 0;
    const int minItems = 10;

    do {
        cout << "Enter the number of items in the auction (must be at least 10): ";
        cin >> numItems;
    } while (numItems < minItems);

    for (int i = 0; i < numItems; ++i) {
        AuctionItem newItem;
        cout << "\nItem " << i + 1 << ":\n";
        cout << "Enter item number: ";
        cin >> newItem.itemNumber;
        cout << "Enter item description: ";
        cin.ignore();
        getline(cin, newItem.description);
        cout << "Enter reserve price: ";
        cin >> newItem.reservePrice;
        newItem.numberOfBids = 0;
        newItem.highestBid = 0; // Initialize highest bid to 0
        newItem.sold = false;
        items.push_back(newItem);
    }
}

void placeBid(vector<AuctionItem>& items, int buyerNumber) {
    int itemNumber;
    double bidAmount;

    cout << "Enter item number to bid for: ";
    cin >> itemNumber;

    for (auto& item : items) {
        if (item.itemNumber == itemNumber) {
            cout << "Enter your bid amount: ";
            cin >> bidAmount;
            if (bidAmount > item.highestBid) {
                item.highestBid = bidAmount;
                item.numberOfBids++;
                cout << "Bid successful!\n";
            }
            else {
                cout << "Your bid must be higher than the current highest bid.\n";
            }
            return;
        }
    }
    cout << "Item not found.\n";
}

void endAuction(vector<AuctionItem>& items) {
    double totalFee = 0.0;
    int numSold = 0;

    cout << "\nEnd of Auction Results:\n";
    for (auto& item : items) {
        if (item.highestBid >= item.reservePrice) {
            item.sold = true;
            totalFee += 0.1 * item.highestBid;
            numSold++;
            cout << "Item " << item.itemNumber << " sold for $" << item.highestBid << "\n";
        }
        else {
            cout << "Item " << item.itemNumber << " did not meet reserve price.\n";
        }
    }
    cout << "Total fees for sold items: $" << totalFee << "\n";
    cout << "Number of items sold: " << numSold << "\n";
}
