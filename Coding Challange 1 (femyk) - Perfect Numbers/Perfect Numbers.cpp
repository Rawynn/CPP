/*
Coding Challange 1 (Femyk): Perfect Numers
This code is going to list every perfect number and its factors from the range you enter.
*/


#include <iostream>
#include <conio.h>
#include <vector>
#include <utility>

using namespace std;


class PurrfectNumbers {
public:
	int limit = 0;
	vector<int> dividers;
	int sum = 0;
	vector<pair<int, vector<int>>> perfectNumbers;

	PurrfectNumbers(int a)
	{
		this->limit = a;
	}

	void solution()
	{
		for (int i = 1; i <= limit; ++i){
			for (int j = 1; j<=(i / 2); j++){
				if (((i) % j) == 0){
					dividers.push_back(j);
					sum += j;
				}
			}

			if (sum == i){
				perfectNumbers.push_back(pair<int, vector<int>>(i, dividers));
			}

			dividers.clear();
			sum = 0;
		}
	}

};

ostream& operator<<(ostream &os, PurrfectNumbers &p)
{
	os << "----------------------------------------------------------------------------" << endl;
	for (int i = 0; i < p.perfectNumbers.size(); ++i){
		os << "Perfect number: " << p.perfectNumbers[i].first << endl << "Factors: ";
		for (int j = 0; j < p.perfectNumbers[i].second.size(); ++j){
			os << p.perfectNumbers[i].second[j];
			os << " ";
		}
		os << endl << "----------------------------------------------------------------------------" << endl;
	}
	return os;
}

int main() {

	int limit = 0;

	cout << "Please enter the limit for perfect numbers greater than 0." << endl;

	while(true){		
		cout << "The limit is: ";
		cin >> limit;

		if (cin.fail()){		
			cout << "I don't know what to do with this. Please enter numeric limit greater than 0: " << endl << endl;
			limit = 0;
			cin.clear();
			cin.sync();
			//for Linux users:
			//cin.ignore(1000, '\n'); 
			//cin.ignore(numeric_limits < streamsize >::max(), '\n');
			
		}
		else if (limit < 1)
		{
			cout << "Please enter numeric limit greater than 0: " << endl << endl; 
			limit = 0;
			
		}
		else if (limit < 6){
			cout << "There are no perfect numbers less than 6." << endl << endl;
			limit = 0;
		}
		else{
			break;
		}		
	} 

	cout << endl;

	PurrfectNumbers meowtastic(limit);
	meowtastic.solution();
	cout << meowtastic;

	_getch();
	return 0;
}