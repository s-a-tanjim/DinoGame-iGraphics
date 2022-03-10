int windowWidth = 630, windowHeight = 400;

unsigned long int HIGHEST_SCORE = 0;
unsigned long int UserScore = 0;
int SPEED = 1;

bool showInitDisplay = true;
bool showInfoDsiplay = false;
bool GameOverFlag = false;
bool MusicOn = true;

// Ground Plot Variables
int BaseHeight = 150;
int groundWidth = 90;
float initialGroundPoint = 90;
//float initialGroundPoint = 25;

// Dino Jumping Variables
float initialDinoPoint = 100;
float dinoBaseHeight = 155;
bool jumping = false, jumpingUp = false, jumpingDown = false;

char dino_img[4][50] = {
	"bitmaps\\dino\\dino_default.bmp",
	"bitmaps\\dino\\dino_ducking_leftstep.bmp",
	"bitmaps\\dino\\dino_default.bmp",
	"bitmaps\\dino\\dino_default.bmp"
};

char ground_img[3][50] = {
	"bitmaps\\ground\\ground_0.bmp",
	"bitmaps\\ground\\cactus_0.bmp",
	"bitmaps\\ground\\cactus_3.bmp",
};
