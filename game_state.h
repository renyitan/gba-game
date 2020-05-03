#define STATE_START 0
#define STATE_PLAYING 1
#define STATE_END 2

extern int GAME_STATE;

void auxButtonHandler(void)
{
    u16 buttons = INPUT;

    if ((buttons & KEY_START) == KEY_START)
    {
        clearGameStartScreen();
        GAME_STATE = STATE_PLAYING;
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