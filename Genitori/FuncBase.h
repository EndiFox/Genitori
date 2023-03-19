#pragma once
#include <iostream>
#include <random>

using namespace std;

class FuncDatabase
{
	int launch;
public:

	FuncDatabase(int launch)
	{
		this->launch = launch;
	}

	int Dice(int dicemin, int dicemax)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(dicemin, dicemax);
		return dist(gen);
	}

	float Microrandomise(float mn, float mx)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<> dist(mn, mx);
		return dist(gen);
	}

	float Complexion(const vector<float>&A, const vector<float>&B)
	{
		size_t size1 = A.size();
		vector<float> res;
		float summa = 0;

		for (int i = 0; i < size1; i++)
		{
			res.push_back(A[i] * B[i]);
			summa += res[i];
		}

		return summa;
	}

};