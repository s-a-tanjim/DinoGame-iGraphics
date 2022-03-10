// For jumping stage of Dino
void jumpDino(){
	if (!jumping) return; // Check if it's in Jumping Stage
	else if (!jumpingUp && !jumpingDown){ // Initially in JumpingUp stage
		jumpingUp = true;
		jumpingDown = false;
	}

	if (jumpingUp){ // For Jumping Up Stage increase Height
		if (dinoBaseHeight < 210)
			dinoBaseHeight += 0.55;
		if (dinoBaseHeight >= 210){
			jumpingUp = false;
			jumpingDown = true;
		}
	}
	else if (jumpingDown) { // For Jumping Down stage decrease Height
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

bool inRange(float val, int start, int end) { //Helper function to check a value is inside a range
	if (val >= start && val <= end)
		return true;
	return false;
}

void checkGameOver(){
	if ((inRange(initialGroundPoint, 24, 26) || inRange(initialGroundPoint,-161,-159)) && !jumping){ // Check Dino is jumping before the tree
		//Game over
		GameOverFlag = true;
	}
}

void PlayGame(){
	initialGroundPoint -= 0.4; // Speed of the Background Motion.
	if (initialGroundPoint <= -270.0)
		initialGroundPoint = 90; // Loop back of Background Screen
	
	plotLandImg();
	jumpDino();
	plotDinoImg();
	checkGameOver();

  //For White Rectangle in both side of the game
	iFilledRectangle(0, BaseHeight, 90, BaseHeight + 40);
	iFilledRectangle(windowWidth - 90, BaseHeight, windowWidth, BaseHeight + 40);
}

// Reset all the values
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