#include<iostream>
#include "iGraphics.h"
#include "all_variables.h"
#include "displayFunctions.h"
#include "gamePlayFunc.h"
int mposx,  mposy;

using namespace std;

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	iSetColor(255, 255, 255);
	iFilledRectangle(0, 0, windowWidth, windowHeight);
	if (showInfoDsiplay){
		showInfoDisplay();
	}
	else if (showInitDisplay){
		initDisplay();
	}
	else if (GameOverFlag){
		showGameOverMsg();
	}
	else {
		PlayGame();
		UserScore++;
		//cout << dinoBaseHeight << endl;
	}
	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//cout<<mx<<"  "<<my<<endl;
		if (mx>=275 && mx<=355 && my>=100 && my<=180 && showInitDisplay) {
			showInitDisplay = false;
		}
		else if (mx >= 570 && mx <= 605 && my >= 25 && my <= 60 && showInitDisplay) {
			showInfoDsiplay = true;
		} else if (showInfoDsiplay)
			showInfoDsiplay = false;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
	}
	else if (key == ' '){
		if (GameOverFlag){
			RestartGame();
		}
		else if (showInfoDsiplay){
			showInfoDsiplay = false;
		}
		else {
			jumping = true;
		}
	}
	else if (key == 'm' || key == 'M'){
		MusicOn = false;
		PlaySound(0, 0, 0);
	}
	else {
		if (MusicOn)
			PlaySound(L"music\\music.wav", NULL, SND_LOOP);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}
//
int main()
{
	
	//place your own initialization codes here.
	iInitialize(windowWidth, windowHeight, "Dino Game");
	
	return 0;
}
