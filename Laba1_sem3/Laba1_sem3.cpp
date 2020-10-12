#include "testSeq.hpp"
#include "testSort.hpp"
#include "time.hpp"
using namespace std;

string answer = "no";

int main() {
	string answ, answ_;
	int numbr;
	cout << "Hello!" << endl;
	while (answer != "yes") {
		cout <<
			"What do you want to do? test(write 'test'), compare two algorithms(write 'compare')" << endl;
	    cout << "or see sequence tests(write 'tests')?" << endl;  //the answer must be complete !!
		cin >> answ;
		if (answ == "test") {
			cout << "What do you want to do: run the program according to ready -" << endl;
			cout << "made tests (enter : 'run') or check on your own values (enter : 'own')?" << endl;

			cin >> answ_;

			cout << "Then what sorting function do you want to test?" << endl;
			cout << "You can choose one (enter only sort numbers strictly one at a time):" << endl;
			cout << "1. Bubble sort," << endl;
			cout << "2. Quick sort," << endl;
			cout << "3. Sort by inserts," << endl;
			if (answ_ == "run") {
				cout << "4. All." << endl;
				cin >> numbr;
				if (numbr == 1) {
					cout << "result of test bubble sort: " << endl;
					test<int>(Bubble);
					cout << endl;
				}
				if (numbr == 2) {
					cout << "result of test quick sort: " << endl;
					test<int>(quickSort);
					cout << endl;
				}
				if (numbr == 3) {
					cout << "result of test sort by inserts: " << endl;
					test<int>(Sort);
					cout << endl;
				}
				if (numbr == 4) {
					cout << "result of all test: " << endl;
					cout << "result of test bubble sort: " << endl;
					test<int>(Bubble);
					cout << "result of test quick sort: " << endl;
					test<int>(quickSort);
					cout << "result of test sort by inserts: " << endl;
					test<int>(Sort);
					cout << endl;
				}
			}
			else {
				int size_of, el;
				string answ2;
				cin >> numbr;
				cout << "Do you want to use a list or an array?" << endl;
				cin >> answ_;
				cout << "enter the size of the sequence:" << endl;
				cin >> size_of;
				if (size_of <= 0) {
					cout << "error!" << endl;
					exit(1);
				}
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
				if (answ_ == "list") {
					//ListSequence<int> test(arr, size_of);
					Sequence<int>* seq = new ListSequence<int>(arr, size_of);
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
					//ArraySequence<int> test(arr, size_of);
					Sequence<int>* seq = new ArraySequence<int>(arr, size_of);
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
				cin >> answ_;
				if (answ_ == "yes") cout << "good!" << endl;
				else cout << "sorry, I'll fix it :(" << endl;
			}
		}
		else if (answ == "compare") {
				cout << "You can choose two:" << endl;
				cout << "1. Bubble sort," << endl;
				cout << "2. Quick sort," << endl;
				cout << "3. Sort by inserts:" << endl;
				cin >> numbr;
				int numbr_two;
				if (numbr == 1) {
					cin >> numbr_two;
					if (numbr_two == 2) {
						getTime<int>(Bubble, quickSort);
						cout << "(the first function is bubble, the second is quick sort)" << endl;
						cout << endl;
					}
					else if(numbr_two == 3) {
						getTime<int>(Bubble, Sort);
						cout << "(the first function is bubble, the second is sort by inserts)" << endl;
						cout << endl;
					}
					else {
						getTime<int>(Bubble, Bubble);
						cout << "(the first function is bubble, the second is bubble)" << endl;
						cout << endl;
					}
				}
				if (numbr == 2) {
					cin >> numbr_two;
					if (numbr_two == 1) {
						getTime<int>(Bubble, quickSort);
						cout << "(the first function is quick sort, the second is bubble)" << endl;
						cout << endl;
					}
					else if (numbr_two == 3) {
						getTime<int>(quickSort, Sort);
						cout << "(the first function is quick sort, the second is sort by inserts)" << endl;
						cout << endl;
					}
					else {
						getTime<int>(quickSort, quickSort);
						cout << "(the first function is quick sort, the second is quick sort)" << endl;
						cout << endl;
					}
				}
				if (numbr == 3) {
					cin >> numbr_two;
					if (numbr_two == 1) {
						getTime<int>(Bubble, Sort);
						cout << "(the first function is bubble, the second is quick sort)" << endl;
						cout << endl;
					}
					else if (numbr_two == 2) {
						getTime<int>(Sort, quickSort);
						cout << "(the first function is sort by inserts, the second is quick sort)" << endl;
						cout << endl;
					}
					else {
						getTime<int>(Sort, Sort);
						cout << "(the first function is sort by inserts, the second is sort by inserts)" << endl;
						cout << endl;
					}
				}
		}
		else if (answ == "tests") {
			TestGetSize();
			TestGet();
			TestSet();
			cout << endl;
		}
		else {
			cout << "input is incorrect! try again if you want :(" << endl;
		}
		cout << "ok, is that all? or..?" << endl;
		cin >> answer;
		if (answer == "yes") {
			cout << endl;
			cout << "well, goodbye!!" << endl;
			exit(1);
		}
		else cout << "okay, then.." << endl;
	}
	return 0;
}
