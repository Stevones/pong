#ifndef _PONG__H_
#define _PONG__H_

#include "raylib.h"
#include <stdio.h>


extern int screenWidth;
extern int screenHeight;
extern int time;
extern int frames;
extern enum state gameState;
extern bool leftWin;
extern bool rightWin;
extern int leftScore;
extern int rightScore;





typedef struct Paddle {
	Rectangle rect;
	Color color;

} Paddle;


typedef struct Ball {
	int x;
	int y;
	float radius;
	Color color;
	int xSpeed;
	int ySpeed;


} Ball;

typedef struct Timer {
	float Lifetime;
} Timer;


void startTimer(Timer* timer, float lifetime);
void updateTimer(Timer* timer);
bool timerDone(Timer* timer);





void handleMenuClicks();
void drawMenu();
void drawGame();
void setPaddleValues();
void updatePaddlePositions();
void setBallValues();



enum state {
	title,
	gameSetup,
	game,
	endGame
};






#endif