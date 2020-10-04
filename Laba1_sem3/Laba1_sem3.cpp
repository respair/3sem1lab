#include "testSeq.hpp"
#include "testSort.hpp"
#include "time.hpp"
using namespace std;

int main() {
	string answ;
	int numbr;
	cout << "Hello!" << endl; 
	cout << "What do you want to do: run the program according to ready -" << endl;
	cout << "made tests (enter : 'run') or check on your own values (enter : 'own')?" << endl;

	cin >> answ;

	cout << "Then what sorting function do you want to test?" << endl;
	cout << "You can choose one (enter only sort numbers strictly one at a time):" << endl;
	cout << "1. Bubble sort," << endl;
	cout << "2. Quick sort," << endl;
	cout << "3. Sort by inserts," << endl;
	if (answ == "run") {
		cout << "4. All." << endl;
		cin >> numbr;
		if (numbr == 1) {
			cout << "result of test bubble sort: " << endl;
			test<int>(Bubble);
		}
		if (numbr == 2) {
			cout << "result of test quick sort: " << endl;
			test<int>(quickSort);
		}
		if (numbr == 3) {
			cout << "result of test sort by inserts: " << endl;
			test<int>(Sort);
		}
		if (numbr == 4) {
			cout << "result of all test: " << endl;
			cout << "result of test bubble sort: " << endl;
			test<int>(Bubble);
			cout << "result of test quick sort: " << endl;
			test<int>(quickSort);
			cout << "result of test sort by inserts: " << endl;
			test<int>(Sort);
		}
	}
	else {
		int size_of, el;
		string answ2;
		cin >> numbr;
		cout << "Do you want to use a list or an array?" << endl;
		cin >> answ;
		cout << "enter the size of the sequence:" << endl;
		cin >> size_of;
		cout << "generate sequence automatically?" << endl;
		cin >> answ2;
		int* arr = new int[size_of];
		if (answ2 == "yes") {
			for (int i = 0; i < size_of; i++)
				arr[i] = rand() % 100;
		}
		else {
			cout << "enter numbers:" << endl;
			for (int i = 0; i < size_of; i++) {
				cin >> el;
				arr[i] = el;
			}
		}
		if (answ == "list") {
			ListSequence<int> test(arr, size_of);
			Sequence<int>* seq = &test;
			if (numbr == 1) {
				cout << "bubble sort test result: " << endl;
				testUser<int>(Bubble, seq);
				cout << endl;
			}
			if (numbr == 2) {
				cout << "quick sort test result: " << endl;
				testUser<int>(quickSort, seq);
				cout << endl;
			}
			if (numbr == 3) {
				cout << "sort by inserts test result: " << endl;
				testUser<int>(Sort, seq);
				cout << endl;
			}
		}
		else {
			ArraySequence<int> test(arr, size_of);
			Sequence<int>* seq = &test;
			if (numbr == 1) {
				cout << "bubble sort test result: " << endl;
				testUser<int>(Bubble, seq);
				cout << endl;
			}
			if (numbr == 2) {
				cout << "quick sort test result: " << endl;
				testUser<int>(quickSort, seq);
				cout << endl;
			}
			if (numbr == 3) {
				cout << "sort by inserts test result: " << endl;
				testUser<int>(Sort, seq);
				cout << endl;
			}
		}
		cout << "is everything right? yes?" << endl;
		cin >> answ;
		if (answ == "yes") cout << "okay thank you!" << endl;
		else cout << "sorry, I'll fix it :(" << endl;
	}
	cout << "you can compare the two algorithms if you like. compare?" << endl;
	cin >> answ;
	if (answ == "yes") {
		cout << "You can choose two:" << endl;
		cout << "1. Bubble sort," << endl;
		cout << "2. Quick sort," << endl;
		cout << "3. Sort by inserts:" << endl;
		cin >> numbr;
		if (numbr == 1) {
			cin >> numbr;
			if (numbr == 2) {
				getTime<int>(Bubble, quickSort);
				cout << "(the first function is bubble, the second is quick sort)" << endl;
			}
			else {
				getTime<int>(Bubble, Sort);
				cout << "(the first function is bubble, the second is sort by inserts)" << endl;
			}
		}
		if (numbr == 2) {
			cin >> numbr;
			if (numbr == 1) {
				getTime<int>(Bubble, quickSort);
				cout << "(the first function is quick sort, the second is bubble)" << endl;
			}
			else {
				getTime<int>(quickSort, Sort);
				cout << "(the first function is quick sort, the second is sort by inserts)" << endl;
			}
		}
		if (numbr == 3) {
			cin >> numbr;
			if (numbr == 1) {
				getTime<int>(Bubble, Sort);
				cout << "(the first function is bubble, the second is quick sort)" << endl;
			}
			else {
				getTime<int>(Sort, quickSort);
				cout << "(the first function is sort by inserts, the second is quick sort)" << endl;
			}
		}
	}
	cout << "want to see the test results of the sequence class?" << endl;
	cin >> answ;
	if (answ == "yes") {
		TestGetSize();
		TestGet();
		TestSet();
		cout << endl;
		cout << "well, if that's all, then goodbye! if not, then restart the program." << endl;
	}
	else cout << "well, if that's all, then goodbye! if not, then restart the program." << endl;
	return 0;
}