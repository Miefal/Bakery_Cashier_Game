#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

int main() {
    // Map to store items and their prices in euros
    map<string, double> itemPrices;
    itemPrices["Baguette"] = 2.50;
    itemPrices["Croissant"] = 1.20;
    itemPrices["Sourdough"] = 3.00;
    itemPrices["Multigrain"] = 2.80;
    itemPrices["Traditional"] = 0.50;
    itemPrices["Muffin"] = 1.80;
    itemPrices["Cake Slice"] = 2.20;
    itemPrices["Cappuccino"] = 2.50;
    itemPrices["Latte"] = 2.80;
    itemPrices["Whole Wheat"] = 2.40;
    itemPrices["Rye"] = 2.60;
    // Add more items and prices as needed

    // Vector to store item types
    vector<string> itemTypes;
    for (const auto& item : itemPrices) {
        itemTypes.push_back(item.first);
    }

    double amountPaid;
    int euros, cents;
    int changeEuros, changeCents;
    double correctChange;

    // Seed the random number generator
    srand(time(0));

    cout << "Welcome to the bakery!" << endl;

    // Game loop
    while (true) {
        vector<string> chosenItems;

        // Randomly choose the number of items the customer wants (between 1 and 3)
        int numItems = rand() % 3 + 1;

        cout << "\nCustomer wants to purchase " << numItems << " item(s)." << endl;

        double totalPrice = 0.0;

        // Randomly choose the items and calculate the total price
        for (int i = 0; i < numItems; i++) {
            int randomIndex = rand() % itemTypes.size();
            string itemType = itemTypes[randomIndex];

            double itemPrice = itemPrices[itemType];

            cout << "\nItem " << (i + 1) << " type: " << itemType << " (Price: " << fixed << setprecision(2) << itemPrice << " euros)" << endl;

            chosenItems.push_back(itemType);
            totalPrice += itemPrice;
        }

        // Randomly generate the amount paid by the customer
        if (rand() % 2 == 0) {
            amountPaid = totalPrice;
        } else {
            // Randomly generate an amount between the total price and 50 euros
            amountPaid = (rand() % static_cast<int>((50 - totalPrice) * 100) + static_cast<int>(totalPrice * 100)) / 100.0;
        }

        cout << "Total price: " << fixed << setprecision(2) << totalPrice << " euros" << endl;
        cout << "Amount paid: " << fixed << setprecision(2) << amountPaid << " euros" << endl;

        // Calculate the change
        double change = amountPaid - totalPrice;

        // Check if the amount paid is sufficient
        if (change < 0) {
            cout << "Insufficient amount. Please try again." << endl;
            continue;
        }

        // Convert change to euros and cents
        euros = static_cast<int>(change);
        cents = static_cast<int>((change - euros) * 100);

        // Ask the user for the correct change
        cout << "Please enter the correct change (in euros and cents, e.g., 2.60): ";
        string input;
        cin >> input;
        stringstream ss(input);
        ss >> correctChange;

        // Check if the correct change matches the calculated change
        if (ss.fail() || correctChange != change) {
            cout << "Incorrect change. The correct change is: " << euros << " euros and " << cents << " cents." << endl;
            continue;
        } else {
            cout << "Correct change! Well done!" << endl;
        }

        // Give change to the customer
        cout << "Change: " << euros << " euros and " << cents << " cents." << endl;

        // Display the items purchased
        cout << "\nItems purchased:" << endl;
        for (int i = 0; i < numItems; i++) {
            cout << "- " << chosenItems[i] << endl;
        }

        // Ask if the customer wants to choose more items
        char choice;
        cout << "\nDo you want to serve another customer (Y/N)? ";
        cin >> choice;

        if (choice == 'N' || choice == 'n') {
            cout << "Thank you for playing!" << endl;
            break;
        }
    }

    return 0;
}

