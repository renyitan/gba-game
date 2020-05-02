/**
 * Global Properties for Player
*/
extern int PLAYER_XPOS;
extern int PLAYER_YPOS;
extern int PLAYER_SPRITE;
extern int PLAYER_ID;
extern int PLAYER_LIFE_COUNTS;


// Sprite Properties
#define LIFE_XPOS 0
#define LIFE_YPOS (SCREEN_HEIGHT - 16)
#define PLAYER_PADDING 8

// typedef struct Player
// {
//     int id;
//     int xPos;
//     int yPos;
// } Player;

// void InitPlayer(Player *player)
// {
//     player->id = 1;
//     player->xPos = SCREEN_HEIGHT / 2;
//     player->yPos = 10;
// }

// void updatePlayerPosition(Player *player, int xPos, int yPos)
// {
//     player->xPos = xPos;
//     player->yPos = yPos;
// }