#define STATE_START 0
#define STATE_PLAYING 1
#define STATE_END 2

extern int GAME_STATE;

void auxButtonHandler(void)
{
    u16 buttons = INPUT;

    if ((buttons & KEY_START) == KEY_START)
    {
        GAME_STATE = STATE_PLAYING;
    }
}
