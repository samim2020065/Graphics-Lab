/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

/*#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<bits/stdc++.h>
#include <stdlib.h>

float cx=10,cy=10;
int r=10;
float vx,vy;
float cx1 = rand() % 96 + 2;   // keep inside screen
float cy1 = rand() % 96 + 2;
int r1=2;
static int tx=0,ty=0;
void circlebresenham(int cx,int cy,int r){
    int x=0,y=r,d=3-2*r;
    while(x<=y){
        glVertex2d(cx+x,cy+y);
        glVertex2d(cx+x,cy-y);
        glVertex2d(cx-x,cy-y);
        glVertex2d(cx-x,cy+y);

        glVertex2d(cx+y,cy+x);
        glVertex2d(cx-y,cy+x);
        glVertex2d(cx-y,cy-x);
        glVertex2d(cx+y,cy-x);
        x++;
        if(d>=0){
            y--;
            d+=4*(x-y)+10;
        }
        else{
            d+=4*x+6;
        }
    }

}
void update(int value)
{
    cx1 += vx;
    cy1 += vy;

    // Wall collision
    if(cx1 + r1 > 100 || cx1 - r1 < 0)
        vx = -vx;

    if(cy1 + r1 > 100 || cy1 - r1 < 0)
        vy = -vy;

    // Distance between centers
    float dx = cx1 - (cx + tx);
    float dy = cy1 - (cy + ty);

    float dist = sqrt(dx * dx + dy * dy);

    // Collision between circles
    if(dist <= r + r1)
    {
        exit(0);   // Game complete
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}
void spe_key(int key,int x,int y){
    switch(key){
        case GLUT_KEY_RIGHT:
            if(cx+r+tx<100){
                tx+=10;
            }
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            if(cx-r+tx>0){
                tx-=10;
            }
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            if(cy+r+ty<100){
                ty+=10;
            }
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            if(cy-r+ty>0){
                ty-=10;
            }
            glutPostRedisplay();
            break;
    }
}
static void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
        glTranslatef(tx,ty,0.0);
        glBegin(GL_POINTS);

        circlebresenham((int)cx,(int)cy,r);
        glEnd();
    glPopMatrix();
        glColor3d(0,0,1);
        glBegin(GL_POINTS);
        circlebresenham((int)cx1,(int)cy1,r1);
        glEnd();


    glFlush();
}
void initVelocity()
{
    srand(time(0));

    // Random velocity between 0.4 and 0.8
    vx = (40 + rand() % 41) / 100.0f;
    vy = (40 + rand() % 41) / 100.0f;

    // Random direction
    if(rand() % 2) vx = -vx;
    if(rand() % 2) vy = -vy;
}
void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,100.0,0.0,100.0,-10.0,10.0);
    glPointSize(3);
    initVelocity();
}*/



/* Program entry point */
#include<GL/freeglut.h>
#include<bits/stdc++.h>
using namespace std;
static int tx=0,ty=0;
int cx=10,cy=10,r=10;
float cx1=rand()%96+2,cy1=rand()%96+2;
float vx,vy;
int r1=2;
void circlebresenham(int cx,int cy,int r){
    int x=0,y=r,d=3-2*r;
    while(x<=y){
        glVertex2d(cx+x,cy+y);
        glVertex2d(cx+x,cy-y);
        glVertex2d(cx-x,cy-y);
        glVertex2d(cx-x,cy+y);

        glVertex2d(cx+y,cy+x);
        glVertex2d(cx-y,cy+x);
        glVertex2d(cx-y,cy-x);
        glVertex2d(cx+y,cy-x);
        x++;
        if(d>=0){
            y--;
            d+=4*(x-y)+10;

        }
        else{
            d+=4*x+6;
        }
    }
}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(tx,ty,0);
        glColor3f(1,0,0);
        glBegin(GL_POINTS);
        circlebresenham(cx,cy,r);
        glEnd();
    glPopMatrix();
    glColor3f(0,0,1);
    glBegin(GL_POINTS);
        circlebresenham((int)cx1,(int)cy1,r1);
        glEnd();
    glFlush();
}
void update(int value){
    cx1+=vx;
    cy1+=vy;
    if(cx1+r1>100||cx1-r1<0){
        vx=-vx;
    }
    if(cy1+r1>100||cy1-r1<0){
        vy=-vy;
    }
    float dx=cx1-(cx+tx);
    float dy=cy1-(cy+ty);
    float dist=sqrt(dx*dx+dy*dy);
    if(dist<=r+r1){
        exit(0);
    }
    glutPostRedisplay();
    glutTimerFunc(16,update,0);
}
void spe_key(int key,int x,int y){
    switch(key){
        case GLUT_KEY_RIGHT:
            if(cx+tx+r<100){
                tx+=10;
            }
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            if(cx+tx-r>0){
                tx-=10;
            }
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            if(cy+ty+r<100){
                ty+=10;
            }
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            if(cy+ty-r>0){
                ty-=10;
            }
            glutPostRedisplay();
            break;


    }
}
void initVelocity(){
    srand(time(0));
    vx=(rand()%41+40)/100.0f;
    vy=(rand()%41+40)/100.0f;
    if(rand()%2){
        vx=-vx;
        vy=-vy;
    }
}
void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,100.0,0.0,100.0,-10.0,10.0);
    glPointSize(3);
    initVelocity();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("GLUT Shapes");

    init();
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutTimerFunc(0,update,0);
    glutMainLoop();

    return 0;
}
