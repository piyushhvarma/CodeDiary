#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store item details
struct Item {
    int weight;
    int value;

    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator to sort items by value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to get maximum value using Greedy Fractional Knapsack
double fractionalKnapsack(int capacity, vector<Item> items) {
    // Sort items by descending value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (auto& item : items) {
        if (capacity == 0)
            break;

        // If item can be picked whole
        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            // Take fraction of the item
            totalValue += item.value * ((double)capacity / item.weight);
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {
        {60, 10},  // value, weight
        {100, 20},
        {120, 30}
    };

    int capacity = 50;

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
