#include <iostream>
#include <string>

using namespace std;

struct Aeroflot {
	string destination, aircraft_type;
	int flight_number;
};

void InputData(Aeroflot* aeroflot, const int kNumAeroflots);
void PrintAeroflots(Aeroflot* aeroflot, const int kNumAeroflots);
void SortAeroflots(Aeroflot* aeroflot, const int kNumAeroflots);
void FindFlights(Aeroflot* aeroflot, const int kNumAeroflots);

int main() {
	const int kNumAeroflots = 7;
	Aeroflot aeroflot[kNumAeroflots];

	InputData(aeroflot, kNumAeroflots);
	SortAeroflots(aeroflot, kNumAeroflots);
	PrintAeroflots(aeroflot, kNumAeroflots);
	FindFlights(aeroflot, kNumAeroflots);

	return 0;
}

void InputData(Aeroflot* aeroflot, const int kNumAeroflots) {
	for (int i = 0; i < kNumAeroflots; i++)	{
		cout << "Enter destination #" << i + 1 << ": ";
		getline(cin, aeroflot[i].destination);

		cout << "Enter flight number: ";
		cin >> aeroflot[i].flight_number;
		cin.ignore();

		cout << "Enter aircraft type: ";
		getline(cin, aeroflot[i].aircraft_type);

		cout << endl;
	}
}

void PrintAeroflots(Aeroflot* aeroflot, const int kNumAeroflots) {
	for (int i = 0; i < kNumAeroflots; i++) {
		cout << "Aeroflot #" << i + 1;
		cout << "\nDestination: " << aeroflot[i].destination;
		cout << "\nFlight number: " << aeroflot[i].flight_number;
		cout << "\nAircraft type: " << aeroflot[i].aircraft_type;
		cout << endl << endl;
	}
}

void SortAeroflots(Aeroflot* aeroflot, const int kNumAeroflots) {
	bool swapped;
	for (int i = 0; i < kNumAeroflots - 1; i++) {
		swapped = false;

		for (int j = 0; j < kNumAeroflots - i - 1; j++) {
			if (aeroflot[j].flight_number > aeroflot[j + 1].flight_number) {
				swap(aeroflot[j], aeroflot[j + 1]);
				swapped = true;
			}
		}

		if (swapped == false) break;
	}
}

void FindFlights(Aeroflot* aeroflot, const int kNumAeroflots) {
	string destination;
	cout << "Enter destination: ";
	getline(cin, destination);

	cout << "\nFlights to " << destination << ":\n";
	bool no_flights = true;
	for (int i = 0; i < kNumAeroflots; i++) {
		if (aeroflot[i].destination == destination)	{
			cout << "\nFlight number: " << aeroflot[i].flight_number;
			cout << "\nAircraft type: " << aeroflot[i].aircraft_type;
			cout << endl;
			no_flights = false;
		}
	}
	if (no_flights)
		cout << "No flights were found.\n";
}