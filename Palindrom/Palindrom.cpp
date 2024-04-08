#include "Palindrom.h"

string Palindrom::SortNumber(int n) {
	cout << "\n---------------------------------------------------------------------\n";
	string N = to_string(n);
	cout << "Initial : " + N + "\n";
	bool hasChanged = true;
	while (hasChanged) {
		hasChanged = false;
		for (int i = 0; i < N.size() - 1; i++) {
			if (N[i] < N[i + 1]) {
				hasChanged = true;
				char temp = N[i];
				N[i] = N[i + 1];
				N[i + 1] = temp;
			}
		}
	}
	cout << "Sorted : " + N + "\n\n";
	return N;
}

int Palindrom::GetIndexOfDB(string N) {
	for (int i = 0; i < N.size() - 1; i++) {
		if (N[i + 1] == '0') break;
		if (N[i] == N[i + 1]) {
			cout << "Index of DB in " + N + " : " + to_string(i) + "\n";
			return i;
		}
	}
	cout << "Index of DB in " + N + " : -1\n";
	return -1;
}

string Palindrom::Compute(string N) {
	if (N.size() == 0)
		return "";

	int index = GetIndexOfDB(N);
	if (index == -1) {
		string mid = "";
		mid.append(&N[0]);
		mid.resize(1);
		cout << "Middle : " + mid + "\n";
		return mid;
	}

	string nCopy = N;
	nCopy.erase(nCopy.begin() + index, nCopy.begin() + index + 2);
	cout << "New str : " + nCopy + "\n\n";
	return N.c_str()[index] + Compute(nCopy) + N.c_str()[index];
}
