#include <iostream>
#include <unordered_map>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;


unordered_map<string, double> unitToML = {
    {"cup", 240}, {"tablespoon", 15}, {"teaspoon", 5}, {"ml", 1}, {"liter", 1000},
    {"ounce", 28.35}, {"pound", 453.6}, {"quart", 946}, {"pint", 473}, {"gallon", 3785},
    {"dash", 0.5}, {"pinch", 0.3}, {"drop", 0.05}, {"cup (UK)", 284}, {"tablespoon (UK)", 17.75},
    {"teaspoon (UK)", 4.9}, {"fluid ounce", 29.5735}, {"fluid ounce (UK)", 28.4131}, {"milliliter (UK)", 1},
    {"cup (metric)", 250}, {"deciliter", 100}, {"centiliter", 10}, {"hectoliter", 10000},
    {"fifth", 757}, {"quart (UK)", 1136}, {"gill", 118.3}, {"barrel", 158987}, {"drams", 3.55},
    {"scruple", 1.3}, {"ounce (UK)", 28.3495}, {"bushel", 35239}, {"peck", 8848}, {"ounce (dry)", 31.1035},
    {"gill (UK)", 142.065}, {"cup (US)", 240}, {"tablespoon (US)", 14.79}, {"teaspoon (US)", 4.93},
    {"pint (US)", 473.176}, {"quart (US)", 946.352}, {"gallon (US)", 3785.41}, {"tablespoon (metric)", 15},
    {"gallon (UK)", 4546.09}, {"ton", 907184}, {"cubic inch", 16.387}, {"cubic foot", 28316.8},
    {"cubic yard", 764554.9}, {"cubic millimeter", 0.001}, {"cubic centimeter", 1}, {"cubic meter", 1000000},
    {"centimeter", 10}, {"inch", 25.4}
};

// Function to convert recipe to grams
void convertToGrams(string input) {
    stringstream ss(input);
    double quantity;
    string unit, ingredient, temp;
    
    ss >> quantity >> unit;  // Extract first two words (quantity + unit)

    // Remaining words = Ingredient name
    while (ss >> temp) {
        if (!ingredient.empty()) ingredient += " ";
        ingredient += temp;
    }

    // Convert unit to mL
    if (unitToML.find(unit) == unitToML.end()) {
        cout << "❌ Error: Unit '" << unit << "' not recognized.\n";
        return;
    }

// will add more functionaliy in this block

    // Output conversion result
    cout << "✅ " << quantity << " " << unit << " of " << ingredient 
         << " ≈ " << fixed << setprecision(2) << (quantity * unitToML[unit]) << " mL.\n";
}

int main() {
    string userInput;
    
    cout << "🍰 Recipe Converter (Enter 'exit' to stop)\n";
    
    while (true) {
        cout << "\nEnter a recipe (e.g., '1 cup of sugar') or 'exit' to stop: ";
        getline(cin, userInput);

        if (userInput == "exit") {
            break;
        }

        // Convert entered recipe to grams
        convertToGrams(userInput);
    }

    return 0;
}
