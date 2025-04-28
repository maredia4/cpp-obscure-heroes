#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

const int SIZE = 10;

// Parallel arrays
string names[SIZE] = {
"Squirrel Girl", "Arm-Fall-Off-Boy", "The Tick", "Matter-Eater Lad",
"Dogwelder", "Zeitgeist", "Color Kid", "Hellcow",
"Ruby Thursday", "Maggott"
};

string superpowers[SIZE] = {
"Control Squirrels", "Detachable Limbs", "Super Strength", "Eat Anything",
"Weld Dogs to People", "Acid Vomit", "Change Colors", "Vampiric Cow",
"Morphing Head", "Sentient Slugs"
};

string weaknesses[SIZE] = {
"Time Limits", "Heavy Objects", "Poor Judgment", "Indigestion",
"Unethical", "Teamwork", "Static Colors", "Sunlight",
"Decapitation", "Hunger"
};

// Multidimensional array: [2][SIZE] -> 0 = Year, 1 = Universe
int info[2][SIZE] = {
{1992, 1989, 1986, 1962, 1996, 2001, 1966, 1975, 1973, 1997}, // Year
{0, 1, 2, 1, 1, 2, 1, 2, 2, 2}  // Universe: 0 = Marvel, 1 = DC, 2 = Other
};

string universeStr(int id) {
switch (id) {
case 0: return "Marvel";
case 1: return "DC";
default: return "Other";
}
}

string toLowercase(string str) {
transform(str.begin(), str.end(), str.begin(), ::tolower);
return str;
}

string toUppercase(string str) {
transform(str.begin(), str.end(), str.begin(), ::toupper);
return str;
}

void displayHero(int i, bool upper = false, bool lower = false) {
string name = names[i], power = superpowers[i], weak = weaknesses[i];
if (upper) {
name = toUppercase(name);
power = toUppercase(power);
weak = toUppercase(weak);
} else if (lower) {
name = toLowercase(name);
power = toLowercase(power);
weak = toLowercase(weak);
}
cout << "Name: " << name << "\n"
<< "Power: " << power << "\n"
<< "Weakness: " << weak << "\n"
<< "Year: " << info[0][i] << "\n"
<< "Universe: " << universeStr(info[1][i]) << "\n\n";
}

void searchByName(string query) {
bool found = false;
for (int i = 0; i < SIZE; i++) {
if (toLowercase(names[i]).find(toLowercase(query)) != string::npos) {
displayHero(i);
found = true;
}
}
if (!found) cout << "No superhero found with that name.\n";
}

void searchByPower(string query) {
bool found = false;
for (int i = 0; i < SIZE; i++) {
if (toLowercase(superpowers[i]).find(toLowercase(query)) != string::npos) {
displayHero(i);
found = true;
}
}
if (!found) cout << "No superhero found with that power.\n";
}

void sortAlphabetically() {
for (int i = 0; i < SIZE - 1; i++) {
for (int j = i + 1; j < SIZE; j++) {
if (names[i] > names[j]) {
swap(names[i], names[j]);
swap(superpowers[i], superpowers[j]);
swap(weaknesses[i], weaknesses[j]);
swap(info[0][i], info[0][j]);
swap(info[1][i], info[1][j]);
}
}
}
cout << "Sorted superheroes alphabetically!\n";
}

void displayAll(bool upper = false, bool lower = false) {
for (int i = 0; i < SIZE; i++) {
displayHero(i, upper, lower);
}
}

int main() {
int choice;
string input;
do {
cout << "\n=== Superhero Database ===\n";
cout << "1. Search by name\n";
cout << "2. Search by superpower\n";
cout << "3. Sort alphabetically\n";
cout << "4. Display all (UPPERCASE)\n";
cout << "5. Display all (lowercase)\n";
cout << "6. Exit\n";
cout << "Choice: ";
cin >> choice;
cin.ignore();

switch (choice) {
case 1:
cout << "Enter superhero name to search: ";
getline(cin, input);
searchByName(input);
break;
case 2:
cout << "Enter superpower to search: ";
getline(cin, input);
searchByPower(input);
break;
case 3:
sortAlphabetically();
break;
case 4:
displayAll(true, false);
break;
case 5:
displayAll(false, true);
break;
case 6:
cout << "Goodbye!\n";
break;
default:
cout << "Invalid choice.\n";
}
} while (choice != 6);

return 0;
}