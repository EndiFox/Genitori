#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "FuncBase.h"
#include "Player.h"
#include <chrono>

using namespace std;

Player player1(100, 3, 5);
FuncDatabase fbase(1);
fstream conscii;
fstream logs;

int main(int argc, char* argv[])
{
	conscii.open("Conscious.txt", ios_base::in | ios_base::out);
	logs.open("Logs.txt", ios_base::in | ios_base::out);
	setlocale(LC_ALL, "rus");
	char buff[50];
	time_t now = time(0);

	while(true)
	{
		char* date = ctime(&now);
		date = ctime(&now);
		tm* dt = gmtime(&now);
		date = asctime(dt);

		if (player1.GetHealth() <= 0) { cout << "u r die";  break; }
		if (player1.GetHunger() <= 0) { player1.StateHunger(); player1.LowingHealth(1); }
		else {	player1.LowingHunger(); }

		vector<float> playerdata = { player1.GetHealth(), player1.GetLevel(), player1.GetHunger(), player1.GetDamage() };
		vector<float> weights = { 0.3, fbase.Microrandomise(-1, 1), 0.5, 0.2 };
		
		float result = fbase.Complexion(playerdata, weights);

		if (result >= 51) 
		{ 
			cout << "spawning Blast" << endl;
			cout << date << endl;		
			cout << "Data of weights:" << endl;			
			cout << "[";
			
			logs << date << endl;
			logs << "spawning Blast" << "\n";
			logs << "Data of weights:" << endl;
			logs << "[";

			for (int i = 0; i < size(weights); i++)
			{
				cout << weights[i];
				logs << weights[i];
				cout << " ";
				logs << " ";
			}

			cout << "]";
			cout << "\n";
			logs << "]" << endl;

			cout << "Data of player: ";
			cout << "\n";
			cout << "[";

			logs << "Data of player: " << endl;
			logs << "[";
			for (int i = 0; i < size(playerdata); i++)
			{
				cout << playerdata[i];
				logs << playerdata[i];
				cout << " ";
				logs << " ";
			}
			cout << "]";		
			cout << "\n";			
			cout << result;			
			cout << "\n";
			

			logs << "]" << endl;
			logs << "\n";
			logs << result;
			logs << "\n" << "\n";
		}
		else 
		{ 
			cout << "spawning Beast" << endl;
			cout << date << endl;
			logs << date << endl;
			logs << "spawning Beast" << endl;
			cout << "Data of weights: " << endl;
			logs << "Data of weights: " << endl;
			cout << "[";
			logs << "[";
			for (int i = 0; i < size(weights); i++)
			{
				cout << weights[i];
				logs << weights[i];
				cout << " ";
				logs << " ";
			}
			cout << "]";
			logs << "]" << endl;
			cout << "\n";

			cout << "Data of player: ";
			logs << "Data of player: " << endl;
			cout << "\n";
			cout << "[";
			logs << "[";
			for (int i = 0; i < size(playerdata); i++)
			{
				cout << playerdata[i];
				logs << playerdata[i];
				cout << " ";
				logs << " ";
			}
			cout << "]";
			logs << "]" << endl;
			cout << "\n";
			logs << "\n";
			cout << result;
			logs << result;
			cout << "\n";
			logs << "\n" << "\n";
		}
		cin.get();
	}

	cin.get();


	conscii.close();
	logs.close();
	return 0;
}