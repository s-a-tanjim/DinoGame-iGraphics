void jumpDino(){
	if (!jumping) return;
	else if (!jumpingUp && !jumpingDown){
		jumpingUp = true;
		jumpingDown = false;
	}

	if (jumpingUp){
		if (dinoBaseHeight < 210)
			dinoBaseHeight += 0.55;
		if (dinoBaseHeight >= 210){
			jumpingUp = false;
			jumpingDown = true;
		}
	}
	else if (jumpingDown) {
		if (dinoBaseHeight > 155){
			dinoBaseHeight -= 0.55;
		}
		if (dinoBaseHeight <= 155){
			dinoBaseHeight = 155;
			jumpingDown = false;
			jumping = false;
		}
	}

}

// Check if two line intersects
/*bool isInside(float a1, float a2, float b1, float b2){
	if ((a1<=b1 && a2>=b1) || (a1<=b2 && a2>=b2))
		return true;
	return false;
}*/

bool inRange(float val, int start, int end) {
	if (val >= start && val <= end)
		return true;
	return false;
}

void checkGameOver(){
	/*if (isInside(initialDinoPoint, initialDinoPoint + 25, 0, 0) && isInside(dinoBaseHeight, dinoBaseHeight + 35, BaseHeight, BaseHeight + 30)) {

	}*/

	if ((inRange(initialGroundPoint, 24, 26) || inRange(initialGroundPoint,-161,-159)) && !jumping){
		//Game over
		GameOverFlag = true;
	}
}

void PlayGame(){
	initialGroundPoint -= 0.4;
	if (initialGroundPoint <= -270.0)
		initialGroundPoint = 90;
	
	plotLandImg();
	jumpDino();
	plotDinoImg();
	checkGameOver();

	iFilledRectangle(0, BaseHeight, 90, BaseHeight + 40);
	iFilledRectangle(windowWidth - 90, BaseHeight, windowWidth, BaseHeight + 40);
}

void RestartGame(){
	if (HIGHEST_SCORE < UserScore)
		HIGHEST_SCORE = UserScore;
	UserScore = 0;
	showInitDisplay = true;
	showInfoDsiplay = false;
	GameOverFlag = false;

	MusicOn = true;
	
	initialGroundPoint = 90;

	initialDinoPoint = 100;
	dinoBaseHeight = 155;
	jumping = false;
	jumpingUp = false;
	jumpingDown = false;

	SPEED = 1;
}