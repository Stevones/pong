#include "pong.h"


Paddle *leftPaddle;
Paddle *rightPaddle;
Paddle LeftPaddle;
Paddle RightPaddle;
Ball ball;
int frames = 0;
int time = 0;
bool leftWin = false;
bool rightWin = false;



int leftScore = 0;
int rightScore = 0;

char scoreLabelLeft[] = "";
char scoreLabelRight[] = "";



void setPaddleValues() {

	leftPaddle = &LeftPaddle;
	rightPaddle = &RightPaddle;	



	leftPaddle->rect.x = 15;
	leftPaddle->rect.y = screenHeight/2 - 50;
	leftPaddle->rect.width = 15;
	leftPaddle->rect.height = 100;
	leftPaddle->color = RAYWHITE;

	rightPaddle->rect.x = screenWidth - 30;
	rightPaddle->rect.y = screenHeight/2 - 50;
	rightPaddle->rect.width = 15;
	rightPaddle->rect.height = 100;
	rightPaddle->color = RAYWHITE;

	



	ball.xSpeed = 10;
	ball.ySpeed = 10;

	




	
}
 





void drawGame() {
	
		// Middle wall
	for (int i = 0, j = 0; i < 6; i++) {
		DrawRectangle(screenWidth/2, 30 + j, 20, 40, RAYWHITE);
		j += 100;
	}

	// Left paddle
	 DrawRectangleRec(leftPaddle->rect, leftPaddle->color);
	// Right paddle
	 DrawRectangleRec(rightPaddle->rect, rightPaddle->color);
	// Ball
	DrawCircle(ball.x, ball.y, ball.radius, ball.color);
	// Score
	DrawText(TextFormat("%d", leftScore), screenWidth/4 - (MeasureText(TextFormat("%d", leftScore), 50)/2), 10, 50, RAYWHITE);
	DrawText(TextFormat("%d", rightScore), 600 - (MeasureText(TextFormat("%d", rightScore), 50)/2), 10, 50, RAYWHITE);



	

	
}





void updatePaddlePositions() {


Rectangle top = { 0, 0, screenWidth, 1 };
Rectangle bottom = { 0, screenHeight, screenWidth, 1 };


	int speed = 10;

	if (IsKeyDown(KEY_W)) {
		leftPaddle->rect.y -= speed;
	}

	if (IsKeyDown(KEY_S)) {
		leftPaddle->rect.y += speed;
	}

	if (IsKeyDown(KEY_UP)) {
		rightPaddle->rect.y -= speed;
	}		

	if (IsKeyDown(KEY_DOWN)) {
		rightPaddle->rect.y += speed;
	}


	if (leftPaddle->rect.y < 0) {
		leftPaddle->rect.y = 0;
	}

	if (leftPaddle->rect.y + leftPaddle->rect.height > screenHeight) {
		leftPaddle->rect.y = screenHeight - leftPaddle->rect.height;
	}


	if (rightPaddle->rect.y < 0) {
		rightPaddle->rect.y = 0;
	}

	if (rightPaddle->rect.y + rightPaddle->rect.height > screenHeight) {
		rightPaddle->rect.y = screenHeight - rightPaddle->rect.height;
	}










	if (CheckCollisionCircleRec((Vector2){ ball.x, ball.y }, ball.radius, leftPaddle->rect)) {
		ball.xSpeed = -(ball.xSpeed);
		ball.x += 10;
	}

	if (CheckCollisionCircleRec((Vector2){ ball.x, ball.y }, ball.radius, rightPaddle->rect)) {
		ball.xSpeed = -(ball.xSpeed);
		ball.x -= 10;
	}

	if ( CheckCollisionCircleRec((Vector2){ ball.x, ball.y }, ball.radius, top) || CheckCollisionCircleRec((Vector2){ ball.x, ball.y }, ball.radius, bottom) ) {
		ball.ySpeed = -(ball.ySpeed);
	}

	if (ball.x < 0) {
		rightScore++;
		
		setBallValues();
		
	}

	else if (ball.x > screenWidth) {
		leftScore++;
		
		setBallValues();
		
	}


	if (leftScore == 5) {
		gameState = endGame;
		leftWin = true;

	}

	if (rightScore == 5) {
		gameState = endGame;
		rightWin = true;
	}








	frames++;

	if (frames == 60) {
		time++;
	}




 	


	if (time == 1) {
	ball.x += ball.xSpeed;
	ball.y += ball.ySpeed;

}




	






}

void setBallValues() {
	ball.x = screenWidth/2 + 10;
	ball.y = screenHeight/2;
	ball.radius = 20.0;
	ball.color = RAYWHITE;
	frames = 0;
	time = 0;
	ball.xSpeed += 1;
	ball.xSpeed = -(ball.xSpeed);
	ball.ySpeed += 1;
	ball.ySpeed = -(ball.ySpeed);
	gameState = game;



}





 



void startTimer(Timer* timer, float lifetime) {
	if (timer != NULL) {
		timer->Lifetime = lifetime;
	}

}

void updateTimer(Timer* timer) {
	if (timer != NULL && timer->Lifetime > 0) {
		timer->Lifetime -= GetFrameTime();
	}
}


bool timerDone(Timer* timer) {
	if (timer != NULL) {
		return timer->Lifetime <= 0;
	}
}