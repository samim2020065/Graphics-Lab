#include <GL/freeglut.h>
#include <bits/stdc++.h>
using namespace std;

// ---------------- SCREEN ----------------
/*const float W = 100.0f;
const float H = 100.0f;

// ---------------- BAR ----------------
float barX = 44.0f;
const float barY = H / 20.0f;     // 1/20 from bottom
const float barW = 12.0f;         // between 1/10 and 1/8 screen width

// ---------------- BALL ----------------
float r = H / 30.0f;              // 1/30 of screen height
float cx = barX + barW / 2.0f;
float cy = barY + r;

float vx = 0.0f;
float vy = 0.0f;
static float tx=0,ty=0;
bool started = false;

// ---------------- RANDOM VELOCITY ----------------
void initVelocity()
{
    srand(time(0));

    vx = (rand() % 2+0.2);
    if(rand() % 2) vx = -vx;

    vy = (rand() % 2+0.2);


}

// ---------------- BRESENHAM CIRCLE ----------------
void drawCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    glBegin(GL_POINTS);

    while(x <= y)
    {
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);

        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        x++;

        if(d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            y--;
            d += 4 * (x - y) + 10;
        }
    }

    glEnd();
}

// ---------------- BAR COLLISION ----------------
void checkCollision()
{
    if(vy < 0)
    {
        if(cy-r <= barY && cx >= barX+tx && cx <= barX+barW+tx)
        {

                vy = -vy;
                cy = barY + r;

        }
    }
}

// ---------------- UPDATE ----------------
void update(int value)
{
    if(started)
    {
        cx += vx;
        cy += vy;

        // Left wall
        if(cx - r < 0)
        {
            cx = r;
            vx = -vx;
        }

        // Right wall
        if(cx + r > W)
        {
            cx = W - r;
            vx = -vx;
        }

        // Top wall
        if(cy + r > H)
        {
            cy = H - r;
            vy = -vy;
        }

        checkCollision();

        // Game Over
        if(cy - r <= 0)
        {
            cout << "GAME OVER!" << endl;
            exit(0);
        }
    }


    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// ---------------- DISPLAY ----------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    // Draw Bar
        glColor3f(1, 1, 0);
        glTranslatef(tx,ty,0);
        glBegin(GL_LINES);
        glVertex2d(barX,barY);
        glVertex2d(barX+barW,barY);
        glEnd();
    glPopMatrix();


    // Draw Ball
    glColor3f(0, 1, 1);
    drawCircle((int)cx, (int)cy, (int)r);

    glFlush();
}

// ---------------- KEYBOARD ----------------
void specialKeys(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT:

            if(barX+tx >= 0)
                tx-=3;
            glutPostRedisplay();
            break;

        case GLUT_KEY_RIGHT:
            if(barX+barW+tx <= 100)
                tx+=3;
            glutPostRedisplay();
            break;

        case GLUT_KEY_UP:

            if(!started)
            {
                started = true;
                initVelocity();
            }
            glutPostRedisplay();
            break;
    }


}*/
int barW=12;
int barX=44,barY=5;
static int tx=0,ty=0;
int cx=50,cy=8,r=3;
bool started=false;
int vx,vy;
void drawCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    glBegin(GL_POINTS);

    while(x <= y)
    {
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);

        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        x++;

        if(d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            y--;
            d += 4 * (x - y) + 10;
        }
    }

    glEnd();
}
void initVelocity()
{
    srand(time(0));

    vx = (rand() % 2+0.5);
    if(rand() % 2) vx = -vx;

    vy = (rand() % 2+0.5);


}
void checkCollision(){
    if(vy<0){
        if(cy-r<=barY&&cx>=barX+tx&&cx<=barX+tx+barW){
            vy = -vy;
            //cy = barY + r;
        }
    }
}
void update(int value)
{
    if(started)
    {
        cx += vx;
        cy += vy;

        // Left wall
        if(cx - r < 0)
        {
            //cx = r;
            vx = -vx;
        }

        // Right wall
        if(cx + r > 100)
        {
            //cx = 100 - r;
            vx = -vx;
        }

        // Top wall
        if(cy + r > 100)
        {
            //cy = 100 - r;
            vy = -vy;
        }

        checkCollision();

        // Game Over
        if(cy - r <= 0)
        {
            cout << "GAME OVER!" << endl;
            exit(0);
        }
    }


    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void specialKeys(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT:

            if(barX+tx > 0)
                tx-=3;
            glutPostRedisplay();
            break;

        case GLUT_KEY_RIGHT:
            if(barX+barW+tx < 100)
                tx+=3;
            glutPostRedisplay();
            break;

        case GLUT_KEY_UP:

            if(!started)
            {
                started = true;
                initVelocity();
            }
            glutPostRedisplay();
            break;
    }


}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,0);
        glTranslatef(tx,ty,0);
        glBegin(GL_LINES);
        glVertex2d(barX,barY);
        glVertex2d(barX+barW,barY);
        glEnd();
    glPopMatrix();
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    drawCircle(cx,cy,r);
    glEnd();
    glFlush();
}


// ---------------- INIT ----------------
void init()
{
    glClearColor(0, 0, 0, 1);

    glPointSize(2);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, 100, 0, 100, -1, 1);
}

// ---------------- MAIN ----------------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100,100);

    glutCreateWindow("Ball and Paddle Game");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);

    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}
