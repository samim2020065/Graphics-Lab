#include<GL/freeglut.h>
#include<bits/stdc++.h>
using namespace std;
static int tx=0,ty=0;
int cx_red=10,cy_red=10,r_red=10;
float cx_green=rand()%96+2,cy_green=rand()%96+2;
int r_green=2;
float vx,vy;
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
void spe_key(int key,int x,int y){
    switch(key){
        case GLUT_KEY_LEFT:
            if(cx_red-r_red+tx>0){
                tx-=10;
            }
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            if(cx_red+r_red+tx<100){
                tx+=10;
            }
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            if(cy_red+r_red+ty<100){
                ty+=10;
            }
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            if(cy_red-r_red+ty>0){
                ty-=10;
            }
            glutPostRedisplay();
            break;
    }


}
void update(int value){
    cx_green+=vx;
    cy_green+=vy;
    if(cx_green+r_green>100||cx_green-r_green<0){
        vx=-vx;
    }
    if(cy_green+r_green>100||cy_green-r_green<0){
        vy=-vy;
    }
    int d1=cx_green-((int)cx_red+tx);
    int d2=cy_green-((int)cy_red+ty);
    float dist=sqrt(d1*d1+d2*d2);
    if(dist<=r_red+r_green){
        exit(0);
    }
    glutPostRedisplay();
    glutTimerFunc(16,update,0);
}
void initVelocity(){
    srand(time(0));
    vx=(rand()%41+40)/100.f;
    vy=(rand()%41+40)/100.f;
    if(rand()%2){
        vx=-vx;
        vy=-vy;
    }
}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,0,0);
        glTranslatef(tx,ty,0);
        glBegin(GL_POINTS);
        circlebresenham(cx_red,cy_red,r_red);
        glEnd();
    glPopMatrix();
    glColor3f(0,1,0);
    glBegin(GL_POINTS);
    circlebresenham((int)cx_green,(int)cy_green,r_green);
    glEnd();
    glFlush();
}

void init(void){
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,100,0,100,-10,10);
    glPointSize(3);
    initVelocity();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Demo");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0,update,0);
    glutSpecialFunc(spe_key);
    glutMainLoop();
    return 0;
}
