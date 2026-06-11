#include <GL/glut.h>
#include <cmath>

void plotPoint(float x, float y)
{
    if (fabs(x) >= 5 || fabs(y) >= 5)
        glVertex2f(x, y);
}

void circleBresenham(float cx, float cy, float r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    while (x <= y)
    {
        plotPoint(cx + x, cy + y);
        plotPoint(cx - x, cy + y);
        plotPoint(cx - x, cy - y);
        plotPoint(cx + x, cy - y);

        plotPoint(cx + y, cy + x);
        plotPoint(cx + y, cy - x);
        plotPoint(cx - y, cy - x);
        plotPoint(cx - y, cy + x);

        if (d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);



    // Right Circle
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    circleBresenham(10, 0, 7);

    // Left Circle
    glColor3f(1.0, 1.0, 0.0);

    circleBresenham(-10, 0, 7);


    // Top Circle
    glColor3f(0.0, 0.0, 1.0);

    circleBresenham(0, 10, 7);


    // Bottom Circle
    glColor3f(1.0, 0.0, 0.0);

    circleBresenham(0, -10, 7);
    glEnd();



    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(2.0);
    glOrtho(-20, 20, -20, 20, -1, 1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Circle Clipping");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
