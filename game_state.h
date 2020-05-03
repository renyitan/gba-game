#define STATE_START 0
#define STATE_PLAYING_L1 1
#define STATE_PLAYING_L2 2
#define STATE_GAMEOVER 3
#define STATE_END 4

extern int GAME_STATE;
extern int GAME_LEVEL;

extern int VIRUSES_MAX;
extern int MASKS_MAX;

#

void auxButtonHandler(void)
{
    u16 buttons = INPUT;

    if ((buttons & KEY_START) == KEY_START)
    {

        clearGameStartScreen();
        GAME_STATE = STATE_PLAYING_L1;
    }
}

void clearGameStartScreen()
{
    int i;
    for (i = TITLE_LETTER_ID; i <= TITLE_LETTER_ID + 7; i++)
    {
        removeSprite(i);
    }

    for (i = SUBTITLE_LETTER_ID; i <= SUBTITLE_LETTER_ID + 9; i++)
    {
        removeSprite(i);
    }
}

void clearScreenLevel_1()
{
    int i;
    for (i = VIRUS_INITIAL_ID; i < VIRUSES_MAX; i++)
    {
        removeSprite(i);
    }
    for (i = SUBTITLE_LETTER_ID; i <= SUBTITLE_LETTER_ID + 9; i++)
    {
        removeSprite(i);
    }
}