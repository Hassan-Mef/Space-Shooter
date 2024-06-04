#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

#include <iostream>
#include "Ship.h"
#include <vector>
#include "Bullets.h"
#include "Enemies.h"
#include "Player.h"
#include "raylib.h"
#include "Console.h"

class Game_Manager
{
private:
	Ship *ship;  // Setting ships start position
	int ScreenWidth;
	vector <Bullets> bullets;
	vector <Enemies> enemies;
	double LastFiretime;
	int score;
	Player<string, int> player;
	bool gameOver;
	Sound laser;
	float level;

public:
	Game_Manager(const int screenWidth) : ScreenWidth(screenWidth), LastFiretime(0.0), gameOver(false), level(0.0) {
		ship = new Ship((GetScreenWidth() - 30) / 2, (GetScreenHeight() - 40 - 50 - 30));
		laser = LoadSound("Sounds/laser.mp3");
	}
	~Game_Manager();
	void draw();

	void update();

	void handleInput();
	bool getGameOver();

	void UserSetup(string name);

	int getScore();

	int getHighestScore();
	void setHighestScore(int score);

	void updatePlayerScore(int score, string name);

	float level_Manager();

	void printConsoleName(Console& console) {
		cout << "Console Name: " << console.consoleName << std::endl;
	}


};

#endif 

