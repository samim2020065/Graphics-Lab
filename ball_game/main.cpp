#include <GL/freeglut.h>
#include <bits/stdc++.h>
using namespace std;

static int tx = 0, ty = 0;

// Ball
float cx = 50, cy = 50;
float vx, vy;

// ---------------- INIT VELOCITY ----------------
void initVelocity()
{
    srand(time(0));
    vx = rand() % 2;
    vy = rand() % 2;
}

// ---------------- BRESENHAM CIRCLE ----------------
void drawCircleBresenham(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (x <= y)
    {
        glBegin(GL_POINTS);

        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);

        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        glEnd();

        x++;

        if (d < 0)
            d = d + 4 * x + 6;
        else
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
    }
}

// ---------------- UPDATE ----------------
void update(int value)
{
    cx += vx;
    cy += vy;

    float r = 5;

    // WINDOW BOUNDARY
    if (cx + r > 100 || cx - r < -100)
        vx = -vx;

    if (cy + r > 100)
        vy = -vy;

    // ❌ GAME OVER CONDITION (EXIT WINDOW)
    if (cy - r < -100)
    {
        exit(0);
    }

    // ---------------- RECTANGLE ----------------
    float rx1 = -100 + tx;
    float rx2 = -80 + tx;
    float ry1 = -100 + ty;
    float ry2 = -95 + ty;

    float bx1 = cx - r;
    float bx2 = cx + r;
    float by1 = cy - r;
    float by2 = cy + r;

    if (bx2 >= rx1 && bx1 <= rx2 && by2 >= ry1 && by1 <= ry2)
    {
        float overlapLeft   = bx2 - rx1;
        float overlapRight  = rx2 - bx1;
        float overlapTop    = ry2 - by1;
        float overlapBottom = by2 - ry1;

        float minOverlap = min({overlapLeft, overlapRight, overlapTop, overlapBottom});

        if (minOverlap == overlapLeft || minOverlap == overlapRight)
            vx = -vx;
        else
            vy = -vy;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// ---------------- DISPLAY ----------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Rectangle
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glBegin(GL_LINES);
    glVertex2d(0,5);
    glVertex2d(10,5);
    glPopMatrix();

    // Ball
    glColor3f(0, 1, 1);
    drawCircleBresenham((int)cx, (int)cy, 3);

    glFlush();
}

// ---------------- KEY CONTROL ----------------
void spe_key(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        if (-100 + tx > -100) tx -= 5;
        break;

    case GLUT_KEY_RIGHT:
        if (-80 + tx < 100) tx += 5;
        break;

    case GLUT_KEY_UP:
        if (-95 + ty < 100) ty += 5;
        break;

    case GLUT_KEY_DOWN:
        if (-100 + ty > -100) ty -= 5;
        break;
    }

    glutPostRedisplay();
}

// ---------------- INIT ----------------
void init()
{
    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -1, 1);

    //glMatrixMode(GL_MODELVIEW);
    //glPointSize(2);

    initVelocity();
}

// ---------------- MAIN ----------------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Ball Game - Auto Exit");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
