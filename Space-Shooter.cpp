#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <raylib.h>
#include "Ship.h"
#include "Game_Manager.h"
#include "Bullets.h"
#include "Enemies.h"
#include "Console.h"
#include <chrono>
#include <thread>
#include <ctime>


using namespace std;
int main()
{

	srand(time(0));
	static int checking = 0;

	Console console;
	

	Color Grey = Color{ 99, 102, 112, 255 };
	Color Yellow = Color{ 243 , 216 , 63 , 255 };
	int offset = 50;
	const int screenWidth = 500;
	const int screenHeight = 600;

	InitAudioDevice();

	InitWindow(screenWidth +offset, screenHeight +(offset), "Space Shooter");
	// loading font

	Font font = LoadFontEx("Fonts/monogram.ttf", 64 , 0 , 0);
	SetTargetFPS(60);

	Game_Manager game(screenWidth);
	//Bullets bullet(300 , 600 );
	//Enemies enemy(300, 10);
	string gameScore = "0";
	game.printConsoleName(console);
	console.clearConsole();

	cout << "Enter your name : " << endl;
	string name;
	cin >> name;

	game.UserSetup(name);
	//Music music = LoadMusicStream("Sounds /test.mp3");

	Music music = LoadMusicStream("Sounds/game_bg.mp3");
	Sound hit = LoadSound("Sounds/hit2.mp3");
	Sound lose = LoadSound("Sounds/xpSound.mp3");
	PlayMusicStream(music);

	float timePlayed = 0.0f;
	int high = game.getHighestScore();
	string H_score = to_string(high);
	
	
	SetTargetFPS(60);

	static int menu = 0;
	

	while (!WindowShouldClose())
	{
		UpdateMusicStream(music);

		//if (IsKeyPressed(KEY_W)) PlaySound(lose);

		timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);

		if (timePlayed > 1.0f) timePlayed = 1.0f;
		
		BeginDrawing();
		ClearBackground(Grey);
		
		if (menu == 0)
		{
			DrawTextEx(font, "SPACE SHOOTER ", { 95 , 100 }, 50, 2, Yellow);
			DrawTextEx(font, "HIGH SCORE : ", { 150 , 190 }, 25, 2, Yellow);
			DrawTextEx(font, H_score.c_str(), { 315 , 190 }, 25, 2, Yellow);
			DrawTextEx(font, "Press Enter to Start ", { 105 , 260 }, 21, 2, Yellow);

			if(IsKeyPressed(KEY_ENTER))
				menu = 1;

			EndDrawing();
			continue;

		}

		
		

		DrawRectangleRoundedLines({ 10 ,10 ,520 , 630 }, 0.18f,20 , 2, Yellow);
		DrawLineEx({ 15 , 600 }, { 521 ,600 }, 3 , Yellow);
		game.handleInput();
		DrawTextEx(font, "Score", {400 , 604}, 20, 2, Yellow);
		gameScore = to_string(game.getScore());
		DrawTextEx(font, gameScore.c_str(), { 460 , 604 }, 20, 2, Yellow);
		
		game.draw();
		game.update();
		//cout << "Player name: " << name << endl;  // debugging purpose
		//cout << "Test 22 " << game.getScore() << endl;
		game.updatePlayerScore(game.getScore(), name);
		

		//ResumeSound()

		
		if (game.getGameOver())
		{
			DrawTextEx(font, "Game Over", { 250-50 , 300-50 }, 40, 2, Yellow);
		
			if (checking == 0)
			{
				PlaySound(lose);
				 //this_thread::sleep_for(std::chrono::seconds(3)); // Wait for 3 seconds
				checking = 1;

			}
			
		}
		gameScore = game.getScore();
		
		EndDrawing();


		
	
	}

	

	game.setHighestScore(game.getScore());
	
	UnloadMusicStream(music);   // Unload music stream buffers from RAM

	CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)

	//CloseWindow();

	return 0;
	
	
}