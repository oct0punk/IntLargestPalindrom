#pragma once
#include <string>
#include <iostream>

using namespace std;

class Palindrom
{
	static string SortNumber(int n);
	static int GetIndexOfDB(string N);
	static string Compute(string N);

public:
	static string Get(int n) { return Compute(SortNumber(n)); }
};