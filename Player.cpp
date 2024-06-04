#include "Player.h"
/*
#include "Player.h"
#include "external_lib/nlohmann/json.hpp"

using json = nlohmann::json;



template<class U, class S>
Player<U, S>::Player(U name, S score)
{
	player[name] = score;
}

template<class U, class S>
U Player<U, S>::getName()
{
	return U;
}

template<class U, class S>
S Player<U, S>::getScore()
{
	return S;
}

template<class U, class S>
void Player<U, S>::setName(U name)
{

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
	}
}

template<class U, class S>
void Player<U, S>::saveToFile(U name) 
{
	json j = serialize();
	std::string filename = name + ".json";
	std::ofstream file(filename);
	file << j;
}

template<class U, class S>
void Player<U, S>::loadFromFile(U name) 
{
	std::string filename = name + ".json";
	json j;
	std::ifstream file(filename);
	file >> j;
	deserialize(j);
}



template<class U, class S>
void Player<U, S>::saveToFile()
{
	ofstream file;
	string filename = 
	file.open("player.txt");
	for (auto it = player.begin(); it != player.end(); it++)
	{
		file << it->first << " " << it->second << endl;
	}
	file.close();
}

*/



