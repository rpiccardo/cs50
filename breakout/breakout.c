//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//
/*

  ____          _          _   _             ____      _
 / ___|___   __| | ___  __| | | |__  _   _  |  _ \ ___| |__   ___  ___ __ _
| |   / _ \ / _` |/ _ \/ _` | | '_ \| | | | | |_) / _ \ '_ \ / _ \/ __/ _` |
| |__| (_) | (_| |  __/ (_| | | |_) | |_| | |  _ <  __/ |_) |  __/ (_| (_| |
 \____\___/ \__,_|\___|\__,_| |_.__/ \__, | |_| \_\___|_.__/ \___|\___\__,_|
                                      |___/


                (╯°□°）╯︵ ┻━┻   ┻━┻︵ \(°□°)/ ︵ ┻━┻           ¯\_(ツ)_/¯

*/

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

//height and width of paddle in pixels
#define P_HEIGHT 10
#define P_WIDTH 55

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);
    add(window,ball);
    waitForClick(); //makes ball wait for click to start game before moving

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);
    add(window, paddle);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);
    add(window,label);
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // keep playing until game over
                    double velocity = 3.0;
                    double velocity1 = drand48()+1.0;
    while (lives > 0 && bricks > 0)
    {
        GEvent event = getNextEvent(MOUSE_EVENT);

        //if we heard one
        if (event != NULL)
        {
           if(getEventType(event) == MOUSE_MOVED)
           {
                double x = getX(event)-getWidth(paddle)/2;
                setLocation(paddle, x,530);
           }
        }
                move(ball,velocity1,velocity);
                if(getX(ball) + getWidth(ball) >= getWidth (window))
                {
                    velocity1 = -velocity1;
                }
                else if(getX(ball) <=0)
                {
                    velocity1 = -velocity1;
                }
                else if(getY(ball) <=0)
                {
                    velocity = -velocity;
                }
                if(points > 10)
                {
                    pause(7);
                }
                else if(points > 20)
                {
                    pause(5);
                }
                else
                pause(10);

                //if ball goes past the paddle
                if(getY(ball) + getHeight(ball)>= getHeight(window) - getHeight(paddle))
               {
                   //reset location of ball, paddle, remove a life, and wait for click to begin
                   setLocation(ball,190,300);
                   setLocation(paddle,170,530);
                   lives--;
                   waitForClick();
                   {
                        if(waitForClick != NULL)
                        {
                            waitForEvent(MOUSE_EVENT);
                        }
                   }
               }

        //is ball detects collision with paddle, bounce. if ball detects collission with bricks, remove.
        GObject object = detectCollision(window,ball);
            if(object != NULL)
            {
                if (object == paddle)
                {
                    velocity= -velocity;
                }
                else if (strcmp (getType(object), "GRect") == 0)
                {
                    velocity = -velocity;
                    removeGWindow(window,object);
                    points++;
                    bricks--;
                    updateScoreboard(window,label, points);
                }
            }

        }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
     int n = 0;
     int j =0;

   for(int r=0;r<ROWS;r++)
   {
        for(int c=1;c <= COLS;c++)
        {
         if(c == 1)
         {
            n=1;
         }
         //rows of bricks alternate in color between red and blue.
         GRect bricks= newGRect(n,j,35,12);
         setFilled(bricks,true);
         if(j== 15)
         {
            setColor(bricks,"BLUE");
         }
         else if (j==45)
         {
            setColor(bricks,"BLUE");
         }
         else
         {
            setColor(bricks,"RED");
         }
         add(window,bricks);
         n += 40;
        }
        j +=15;
      }
}
/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    window = newGOval(200,300,RADIUS*2,RADIUS*2);
    setFilled(window, true);
    setColor(window,"BLACK");
    return window;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    window = newGRect(170,530,60,10);
    setFilled(window,true);
    setColor(window,"BLACK");
    return window;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    window = newGLabel("0");
    setFont(window, "SansSerif-36");
    return window;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
