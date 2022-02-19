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


	//iShowBMP(50, 50, dino_img[0]);
}
