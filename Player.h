#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <map>
#include "external_lib/nlohmann/json.hpp"
#include <fstream>
using json = nlohmann::json;


using namespace std;

template <class U, class S>
class Player
{
private:
	map<U, S> player;
	U currentUsername;
	

public:
	Player() = default;
	Player(U name, S score);

	U getName();
	S getScore(U name);
	void setName(U name);
	void setScore(S score);

	void update(U key, S value);

	json serialize();
	void deserialize(json j);
	void saveToFile(U name);
	void loadFromFile(U name);
	void clearData();

	void printPlayerData();

	static bool validateUser(U name);
	static bool registerUser();

	Player operator+(int score);

	
	friend ostream& operator<<(ostream& os, const Player<U, S>& plyr);
	
};





#endif // !_PLAYER_H




template<class U, class S>
Player<U, S>::Player(U name, S score)
{
	player[name] = score;
	currentUsername = name;
}

template<class U, class S>
U Player<U, S>::getName()
{
	return currentUsername;
}

template<class U, class S>
S Player<U, S>::getScore(U name)
{
	// Check if the player exists in the map
	if (player.find(name) != player.end()) {
		// Return the player's score
		return player[name];
	}
	else {
		
		// Here we return a default score of 0
		return 0;
	}
}


template<class U, class S>
void Player<U, S>::setName(U name)
{
	currentUsername = name;
}

template<class U, class S>
void Player<U, S>::setScore(S score)
{
	player[getName()] = score;
	
}

template<class U, class S>
void Player<U, S>::update(U key, S value)
{
	player[key] = value;
}

template<class U, class S>
json Player<U, S>::serialize()
{
	json j;
	for (auto& it : player) {
		j[it.first] = it.second;
	}
	return j;
}

template<class U, class S>
void Player<U, S>::deserialize(json j) {
	for (auto& it : j.items()) {
		player[it.key()] = it.value();
		currentUsername = it.key();
	}
}

template<class U, class S>
void Player<U, S>::saveToFile(U name) {
	if (name.empty()) {
		std::cerr << "Player name cannot be empty" << '\n';
		return;
	}
	// Load existing JSON from file
	json j;
	string filename = name + ".json";
	ifstream file(filename);
	if (file.is_open()) {
		file >> j;
		file.close();
	}

	
	// Update the value
	j[name] = getScore(name);

	// Save updated JSON to file
	ofstream outfile(filename);
	try {
		outfile << setw(4) << j;
		outfile.close();
	}
	catch (const std::exception& e) {
		std::cerr << "A problem occurred when saving to file: " << e.what() << '\n';
	}
}




template<class U, class S>
void Player<U, S>::loadFromFile(U name) {
	string filename = name + ".json";
	ifstream file(filename);
	if (file.is_open()) {
		json j;
		file >> j;
		deserialize(j);
		file.close();
	}
	else {
		// Handle error
		cout << "Unable to open file " << filename << endl;
	}
}


template<class U, class S>
ostream& operator<<(ostream& os, const Player<U, S>& plyr)
{
	for (const auto& p : plyr.player)
	{
		os << "Name: " << p.first << ", Score: " << p.second << "\n";
	}
	return os;
}
