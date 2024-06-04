#include "Game_Manager.h"
#include <algorithm>
#include <raylib.h>
#include <ctime>




Game_Manager::~Game_Manager()
{


}

void Game_Manager::draw()
{
	ship->draw();

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].draw();
	}
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].draw();
	}
}

void Game_Manager::update()
{
	if (!gameOver) {
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i].moveUp();


			if (bullets[i].getY() <= 0)  // deleting bullet out of window
			{
				bullets.erase(bullets.begin() + i);
				i--;
				cout << "deleted Bullets" << endl; // for testing purposes
			}
		}

		level = level_Manager();

		

		if (rand() % 200 < 1 ) { // 1% chance to generate a new enemy
			int enemyX = rand() % (GetScreenWidth() - 40) + 1;

			enemies.push_back(Enemies(enemyX, 1));
		}

		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i].moveDown(); // enemy collosion

			if (enemies[i].getX() < ship->getX() + ship->getWidth() &&
				enemies[i].getX() + enemies[i].getWidth() > ship->getX() &&
				enemies[i].getY() < ship->getY() + ship->getHeight() &&
				enemies[i].getY() + enemies[i].getHeight() > ship->getY())
			{
				enemies.erase(enemies.begin() + i);
				i--;
				gameOver = true;
				cout << "Enemies hit " << endl;
			}
			// Remove enemy if it has reached the bottom of the 
			// Check if i is still within range before accessing enemies[i]
			if (i < enemies.size() && enemies[i].getY() >= GetScreenHeight() - 60) {
				enemies.erase(enemies.begin() + i);
				i--; // decrement i after erasing
				score -= 10;
				cout << "deleted enemy" << endl;
			}
		}

		for (int i = 0; i < enemies.size(); i++)
		{
			for (int j = 0; j < bullets.size(); j++)
			{
				// Find the closest x and y coordinates on the enemy rectangle to the bullet
				float closestX = max(enemies[i].getX(), min(bullets[j].getX(), enemies[i].getX() + enemies[i].getWidth()));
				float closestY = max(enemies[i].getY(), min(bullets[j].getY(), enemies[i].getY() + enemies[i].getHeight()));

				// Calculate the distance between the bullet's center and this closest point
				float distanceX = bullets[j].getX() - closestX;
				float distanceY = bullets[j].getY() - closestY;

				// If the distance is less than the bullet's radius, a collision occurred
				if ((distanceX * distanceX) + (distanceY * distanceY) <= (bullets[j].getRadius() * bullets[j].getRadius()))
				{
					// Collision detected, remove the bullet and the enemy
					bullets.erase(bullets.begin() + j);
					enemies.erase(enemies.begin() + i);
					j--;
					i--;
					score += 10;
					break;
				}
			}
		}



	}

	// Checking for Highest Score

	


		
}

void Game_Manager::handleInput()
{
	
   if (!gameOver)
   {
	  
	if (IsKeyDown(KEY_A))
		ship->moveLeft();
	if (IsKeyDown(KEY_D))
		ship->moveRight(ScreenWidth);
	if (IsKeyDown(KEY_SPACE))
	{
		if (GetTime() - LastFiretime >= 0.50)
			bullets.push_back(Bullets((ship->getX() + ship->getWidth() / 2), ship->getY() + 3));
		LastFiretime = GetTime();
		PlaySound(laser);
	}
   }


}

bool Game_Manager::getGameOver()
{
	return gameOver;
}

void Game_Manager::UserSetup(string name)
{
	// Construct the filename from the player's name
	string filename = name + ".json";

	// Check if the player's file exists
	ifstream file(filename);
	if (file.good())
	{
		// The file exists, so load the player's data
		player.loadFromFile(name);
	}
	else
	{
		// The file doesn't exist, so create a new player
		player = Player<string, int>(name, 0);
		player.saveToFile(name);
	}

	// Update the player's high score if their new score is higher
	
}


int Game_Manager::getScore()
{
	return score;
}

void Game_Manager::updatePlayerScore(int score, string name) {
	if (name.empty()) {
		std::cerr << "Player name cannot be empty" << '\n';
		return;
	}

	static int check = 0;
	if (check == 0)
	{
		// Load existing scores
		player.loadFromFile(name);
		check =+1;
	}

	// Update score if necessary
	if (score > player.getScore(name)) {
		player.setScore(getScore());
	

		// Save updated scores
		player.saveToFile(name);
	}
}

float Game_Manager::level_Manager()
{
	if (score > 100)
	{
		return 0.5;
	}
	else if (score < 200)
	{
		return 1.0;
	}

	return 0.0;
}


void Game_Manager::setHighestScore(int score)
{
	if (score > getHighestScore())
	{
		
		ofstream H_score("HighestScore.txt");
		if (H_score.is_open())
		{
			H_score << score;
			cout << "High Score Updated" << endl;
		}
	}
	
	
}

int Game_Manager::getHighestScore()
{
	ifstream H_score("HighestScore.txt");
	int highScore = 0;  // Initialize highScore to 0

	if (H_score.is_open())
	{
		H_score >> highScore;
		cout << "High Score testing " << highScore << endl;
	}
	else
	{
		cout << "Unable to open file" << endl;
	}

	return highScore;
}




