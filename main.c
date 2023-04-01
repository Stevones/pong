#include "pong.h"
#include <stdio.h>

int screenWidth = 800;
int screenHeight = 600;
enum state gameState = title;
Timer timer = { 0 };



int main(int argc, char* argv[]) {


	InitWindow(screenWidth, screenHeight, "Pong");
	ChangeDirectory(GetPrevDirectoryPath(GetWorkingDirectory()));
	ChangeDirectory(GetPrevDirectoryPath(GetWorkingDirectory()));
	SetTargetFPS(60);
	SetExitKey(KEY_NULL);



	while (!WindowShouldClose()) {

 		if (IsKeyPressed(KEY_ESCAPE)) {
			gameState = title;
	}


		BeginDrawing();
		ClearBackground(BLACK);
		if (gameState == title) {
		drawMenu();
		handleMenuClicks();
	}	




		if (gameState == gameSetup) {
			setPaddleValues();
			setBallValues();
			


		}




		if (gameState == game) {		
			updatePaddlePositions();
			drawGame();
		
		
		}

		if (gameState == endGame && leftWin == true) {
			DrawText("Player 1 Wins!\nPress Escape to go to main menu", screenWidth/2 - (MeasureText("Player 1 Wins!\nPress Escape to go to main menu", 25)/2), screenHeight/2, 25, RAYWHITE);
		}

		else if (gameState == endGame && rightWin == true) {
			DrawText("Player 2 Wins!\nPress Escape to go to main menu", screenWidth/2 - (MeasureText("Player 2 Wins!\nPress Escape to go to main menu", 25)/2), screenHeight/2, 25, RAYWHITE);

		}








		EndDrawing();

	}

	CloseWindow();









	return 0;
}