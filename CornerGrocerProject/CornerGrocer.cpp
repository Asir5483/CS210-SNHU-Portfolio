/*
 * Corner Grocer Item Tracker
 * SNHU CS-210 - Programming Languages
 * Adam Sir
 *
 * Description:
 * This program reads grocery purchase records, counts the frequency
 * of each item, allows users to search for items, displays frequency
 * lists and histograms, and saves a backup of item counts to
 * frequency.dat.
 */

#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class GroceryTracker {
public:
    // Loads the purchase history and counts how often each item appears.
    bool LoadData(const string& fileName) {
        ifstream inputFile(fileName);
        if (!inputFile.is_open()) {
            cerr << "Error: Could not open " << fileName << ".\n";
            return false;
        }

        string item;
        while (getline(inputFile, item)) {
            // Remove leading/trailing whitespace and ignore blank lines.
            const size_t first = item.find_first_not_of(" \t\r\n");
            if (first == string::npos) {
                continue;
            }
            const size_t last = item.find_last_not_of(" \t\r\n");
            item = item.substr(first, last - first + 1);
            ++itemCounts[item];
        }

        if (inputFile.bad()) {
            cerr << "Error: A problem occurred while reading " << fileName << ".\n";
            return false;
        }
        return true;
    }

    // Writes every item and its frequency to the automatic backup file.
    bool WriteBackup(const string& fileName) const {
        ofstream outputFile(fileName);
        if (!outputFile.is_open()) {
            cerr << "Error: Could not create " << fileName << ".\n";
            return false;
        }

        for (const auto& entry : itemCounts) {
            outputFile << entry.first << ' ' << entry.second << '\n';
        }
        if (!outputFile) {
            cerr << "Error: A problem occurred while writing " << fileName << ".\n";
            return false;
        }
        return true;
    }

    // Returns the count for an item, ignoring capitalization in the search.
    int GetFrequency(const string& requestedItem) const {
        const string searchKey = ToLower(requestedItem);
        for (const auto& entry : itemCounts) {
            if (ToLower(entry.first) == searchKey) {
                return entry.second;
            }
        }
        return 0;
    }

    // Prints each item alongside its purchase frequency.
    void PrintFrequencies() const {
        for (const auto& entry : itemCounts) {
            cout << entry.first << ' ' << entry.second << '\n';
        }
    }

    // Prints one asterisk per purchase for each item.
    void PrintHistogram() const {
        for (const auto& entry : itemCounts) {
            cout << entry.first << ' ' << string(static_cast<size_t>(entry.second), '*') << '\n';
        }
    }

private:
    map<string, int> itemCounts;

    // Converts text to lowercase for case-insensitive item searches.
    static string ToLower(string text) {
        for (char& character : text) {
            character = static_cast<char>(tolower(static_cast<unsigned char>(character)));
        }
        return text;
    }
};

int main() {
    const string inputFileName = "CS210_Project_Three_Input_File.txt";
    const string backupFileName = "frequency.dat";

    GroceryTracker tracker;
    // Load the purchase records and create the backup before showing the menu.
    if (!tracker.LoadData(inputFileName)) {
        cout << "Place the input file in the same folder as the program and try again.\n";
        return 1;
    }
    if (!tracker.WriteBackup(backupFileName)) {
        cout << "The program will continue, but the backup file could not be created.\n";
    }

    int choice = 0;
    while (choice != 4) {
        cout << "\n===== Corner Grocer Item Tracker =====\n"
             << "1. Search for an item\n"
             << "2. Display item frequencies\n"
             << "3. Display item histogram\n"
             << "4. Exit\n"
             << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number from 1 to 4.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(10000, '\n');

        switch (choice) {
        case 1: {
            string item;
            cout << "Enter the item to search for: ";
            getline(cin, item);
            if (item.find_first_not_of(" \t\r\n") == string::npos) {
                cout << "Please enter a non-empty item name.\n";
            } else {
                cout << item << " appears " << tracker.GetFrequency(item) << " time(s).\n";
            }
            break;
        }
        case 2:
            cout << "\nItem Purchase Frequencies\n";
            tracker.PrintFrequencies();
            break;
        case 3:
            cout << "\nItem Purchase Histogram\n";
            tracker.PrintHistogram();
            break;
        case 4:
            cout << "Exiting Corner Grocer Item Tracker. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please select an option from 1 to 4.\n";
            break;
        }
    }

    return 0;
}
