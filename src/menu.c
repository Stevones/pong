#include "pong.h"



void handleMenuClicks() {
	// Play Button
		if ( GetMouseX() > screenWidth/2 - 75 
		&& GetMouseX() < screenWidth/2 + 75 
			&& GetMouseY() > screenHeight/2 - 15 
			&& GetMouseY() < (screenHeight/2 + 45)
			&& IsMouseButtonPressed(MOUSE_BUTTON_LEFT))  {
		gameState = gameSetup;
	}



	// Exit Button	
	if ( GetMouseX() > screenWidth/2 - 75 
		&& GetMouseX() < screenWidth/2 + 75 
			&& GetMouseY() > screenHeight/2 + 100 
			&& GetMouseY() < (screenHeight/2 + 160)
			&& IsMouseButtonPressed(MOUSE_BUTTON_LEFT))  {
		CloseWindow();
	}


	// Check for touch
	// Play Button
	if ( GetMouseX() > screenWidth/2 - 75 
			&& GetTouchX() < screenWidth/2 + 75 
			&& GetTouchY() > screenHeight/2 - 15 
			&& GetTouchY() < (screenHeight/2 + 45)
			&& IsGestureDetected(GESTURE_TAP))  {
		gameState = gameSetup;
	}

	// Exit
	if ( GetTouchX() > screenWidth/2 - 75 
		&& GetTouchX() < screenWidth/2 + 75 
			&& GetTouchY() > screenHeight/2 + 100 
			&& GetTouchY() < (screenHeight/2 + 160)
			&& IsGestureDetected(GESTURE_TAP))  {
		CloseWindow();
	}
  

	leftWin = false;
	rightWin = false;
	leftScore = 0;
	rightScore = 0;


}

void drawMenu() {
	if (gameState == title) {
	DrawText("Pong", screenWidth/2 - (MeasureText("Pong", 100)/2), screenHeight/6, 100, RAYWHITE);
	DrawRectangle(screenWidth/2 - 75, screenHeight/2 - 15, 150, 60, GRAY);
	DrawRectangle(screenWidth/2 - 75, screenHeight/2 + 100, 150, 60, GRAY);
	DrawText("Play", screenWidth/2 - (MeasureText("Play", 25)/2), screenHeight/2, 25, RAYWHITE);
	DrawText("Exit", screenWidth/2 - (MeasureText("Exit", 25)/2), screenHeight/2 + 120, 25, RAYWHITE);
	DrawText("Left Paddle: W/S    Right Paddle: Up/Down", 5, screenHeight - 20, 20, RAYWHITE);
	}
}