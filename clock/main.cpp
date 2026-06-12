#include <bits/stdc++.h>
#include <GL/freeglut.h>
//#include <OpenGL/gl.h>
using namespace std;

float spin_sec = 0;
float spin_min = 0;
float spin_hour = 0;

void idle_func(int val) {
    float base = 6;
    spin_hour -= base/3600;
    spin_min -= base/60;
    spin_sec -= base;
    glutPostRedisplay();
    glutTimerFunc(1000, idle_func, 0);
}


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    for(int i=0; i<360; i++) {
        float t = i * 3.14159f / 180.0;
        float x = 5 * cos(t);
        float y = 5 * sin(t);

        glVertex2d(x, y);
    }

    glEnd();

    glPushMatrix();
        glRotatef(spin_sec, 0, 0, 1);
        glBegin(GL_LINES);
        glVertex2d(0, 0);
        glVertex2d(0, 4);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotatef(spin_min, 0, 0, 1);
        glBegin(GL_LINES);
        glVertex2d(0, 0);
        glVertex2d(0, 3);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotatef(spin_hour, 0, 0, 1);
        glBegin(GL_LINES);
        glVertex2d(0, 0);
        glVertex2d(0, 2);
        glEnd();
    glPopMatrix();

    glFlush();

}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Demo");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, idle_func, 0);
    glutMainLoop();
    return 0;
}
