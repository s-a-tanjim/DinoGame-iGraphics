void plotLandImg(){
	//BG 1
	iShowBMP(initialGroundPoint, BaseHeight, ground_img[0]);
	//BG 2
	iShowBMP(initialGroundPoint + groundWidth, BaseHeight, ground_img[1]);
	//BG 3
	iShowBMP(initialGroundPoint+(groundWidth * 2), BaseHeight, ground_img[0]);
	//BG 4
	iShowBMP(initialGroundPoint+(groundWidth * 3), BaseHeight, ground_img[2]);
	//BG 5
	iShowBMP(initialGroundPoint+(groundWidth * 4), BaseHeight, ground_img[0]);
	//BG 6
	iShowBMP(initialGroundPoint +(groundWidth * 5), BaseHeight, ground_img[1]);
	//BG 7
	iShowBMP(initialGroundPoint+(groundWidth * 6), BaseHeight, ground_img[0]);
	//BG 8
	iShowBMP(initialGroundPoint + (groundWidth * 7), BaseHeight, ground_img[2]);
	//BG 9
	iShowBMP(initialGroundPoint + (groundWidth * 8), BaseHeight, ground_img[0]);

}

void showGameOverMsg(){
	iSetColor(0, 0, 0);
	iText(260, 250, "Game Over!", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(255, 230, "Press SPACE to Continue!", GLUT_BITMAP_HELVETICA_10);
}

void plotDinoImg(){
	iShowBMP(initialDinoPoint, dinoBaseHeight, dino_img[0]);
}

char* convertIntegerToChar(int N)
{
	int m = N;
	int digit = 0;
	while (m > 0)
	{
		digit++;
		m /= 10;
	}
	char *arr;
	char *arr1 = new char[digit + 1];
	arr = new char[digit];
	int index = 0;
	while (N > 0)
	{
		arr1[++index] = (char)(N % 10 + '0');
		N /= 10;
	}
	int i;
	for (i = 0; i < index; i++)
	{
		arr[i] = arr1[index - i];
	}
	arr[i] = '\0';
	return arr;
}

char* addScoreText(char *str){
	int len = 0;
	while (str[len] != '\0') len++;

	char *arr1 = new char[len + 15];
	
	arr1[0] = 'H';
	arr1[1] = 'I';
	arr1[2] = 'G';
	arr1[3] = 'H';
	arr1[4] = 'E';
	arr1[5] = 'S';
	arr1[6] = 'T';
	arr1[7] = ' ';
	arr1[8] = 'S';
	arr1[9] = 'C';
	arr1[10] = 'O';
	arr1[11] = 'R';
	arr1[12] = 'E';
	arr1[13] = ':';
	arr1[14] = ' ';

	int i = 15;
	for (int j = 0; j < len; j++){
		arr1[i] = str[j];
		i++;
	}
	arr1[i] = '\0';
		
	return arr1;
}

void initDisplay(){
	iSetColor(0, 0, 0);
	iText(270, 320, "Welcome!", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(310, 290, "To", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(260, 250, "Dino Game", GLUT_BITMAP_TIMES_ROMAN_24);

	iShowBMP(275, 100, "bitmaps\\others\\play.bmp");

	char *score_print = convertIntegerToChar(HIGHEST_SCORE);
	char *temp = addScoreText(score_print);
	iText(25, 35, temp, GLUT_BITMAP_8_BY_13);

	iShowBMP(570, 25, "bitmaps\\others\\info.bmp");
}

void showInfoDisplay(){
	iSetColor(0, 0, 0);
	iText(270, 320, "About", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(222, 230, "Control: Press SPACE to JUMP", GLUT_BITMAP_HELVETICA_10);
	iText(220, 210, "Created By: Shoeb Ahmed Tanjim", GLUT_BITMAP_HELVETICA_10);

	iText(250, 100, "Press SPACE to Exit", GLUT_BITMAP_HELVETICA_10);
}