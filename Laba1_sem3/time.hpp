#pragma once
#include <chrono>
#include <iostream>
#include "testSort.hpp"
using namespace std;

template <class T>
void getTime(Sequence<int>* (*s)(Sequence<T>* seqq, int (*cmp)(T a, T b)), 
	Sequence<int>* (*ss)(Sequence<T>* seqq, int (*cmp)(T a, T b))) {
	int size_of_;
	string answer;
	cout << "Do you want to use a list or an array?" << endl;
	cin >> answer;
	cout << "enter the size of the sequence:" << endl;
	cin >> size_of_;
	int* array = new int[size_of_];
	for (int i = 0; i < size_of_; i++)
		array[i] = rand() % 1000;
	if (answer == "list") {
		ListSequence<int> tester(array, size_of_);
		Sequence<int>* seq3 = &tester;
		Sequence<int>* seq4 = &tester;
		auto begin = std::chrono::steady_clock::now();
		testUser<int>(s, seq3);
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

		auto begin2 = std::chrono::steady_clock::now();
		testUser<int>(ss, seq4);
		auto end2 = std::chrono::steady_clock::now();
		auto elapsed_ms_2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		cout << endl;
		cout << "operating time of the first function: " << elapsed_ms.count() << " ms, " << "second function: " <<
			elapsed_ms_2.count() << " ms." << endl;
	}
	else {
		ArraySequence<int> tester(array, size_of_);
		Sequence<int>* seq3 = &tester;
		Sequence<int>* seq4 = &tester;
		auto begin = std::chrono::steady_clock::now();
		testUser<int>(s, seq3);
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		cout << endl;
		auto begin2 = std::chrono::steady_clock::now();
		testUser<int>(ss, seq4);
		auto end2 = std::chrono::steady_clock::now();
		auto elapsed_ms_2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		cout << endl;
		cout << "operating time of the first function: " << elapsed_ms.count() << " ms, " << "second function: " <<
			elapsed_ms_2.count() << " ms." << endl;
	}

}
