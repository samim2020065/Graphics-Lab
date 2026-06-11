#include <GL/gl.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
void linebreshemen(float x1,float y1,float x2,float y2){
    float dx=x2-x1;
    float dy=y2-y1;
    float m;
    if(dx==0){
        m=FLT_MAX;
    }
    else{
        m=dy/dx;
    }
    if(y1>y2||x1>x2){
        swap(x1,x2);
        swap(y1,y2);
    }
    if(m>1){
        swap(x1,y1);
        swap(x2,y2);
    }
    if(m<0&&m>=-1){
        x1*=-1.0;
        x2*=-1.0;

    }
    if(m<-1){
        x1*=-1.0;
        x2*=-1.0;
        swap(x1,y1);
        swap(x2,y2);
    }
    dx=x2-x1;
    dy=y2-y1;
    float p=2*dy-dx;
    for(float i=x1,j=y1;i<=x2&&j<=y2;){
        if(m>1){
            glVertex3f(j,i,0.0);
        }
        else if(m<0&&m>=-1){
            glVertex3f(-i,j,0.0);
        }
        else if(m<-1){
            glVertex3f(-j,i,0.0);
        }
        else{
            glVertex3f(i,j,0.0);
        }
        if(p>=0){


            i+=0.01;
            j+=0.01;
            if(i>x2||j>y2){
                break;
            }
            p=p+2*(dy-dx);
        }
        else{
            i+=0.01;
            if(i>x2||j>y2){
                break;
            }
            p=p+2*dy;
        }
    }
}
void display(void)
{
/* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
    glColor3f (0.0, 1.0, 0.0);




        glBegin(GL_POINTS); //Begin quadrilateral coordinates

        linebreshemen(3.0,3.0,-3.0,3.0);
        glColor3f (1.0, 0.0, 0.0);
        linebreshemen(3.0,3.0,-3.0,0.0);
        glColor3f (0.0, 0.0, 1.0);
        linebreshemen(0.0,5.0,-3.0,0.0);
        glColor3f (1.0, 1.0, 0.0);
        linebreshemen(-3.0,3.0,3.0,0.0);
        glColor3f (0.0, 1.0, 1.0);
        linebreshemen(0.0,5.0,3.0,0.0);
        //Trapezoid
        // glVertex3f(0.05f, 0.05f, 0.0f);
        // glVertex3f(0.35f, 0.05f, 0.0f);
        // glVertex3f(0.40f, 0.35f, 0.0f);




        glEnd(); //End quadrilateral coordinates


    //     glBegin(GL_TRIANGLES); //Begin triangle coordinates


    //     //Pentagon
    //     glColor3f (0.0, 1.0, 0.0);
    //     glVertex3f(0.5f, 0.05f, 0.0f);
    //     glVertex3f(0.75f, 0.05f, 0.0f);
    //     glVertex3f(0.5f, 0.35f, 0.0f);


    //     /*glVertex3f(0.5f, 0.35f, 0.0f);
    //     glVertex3f(0.75f, 0.05f, 0.0f);
    //     glVertex3f(0.75f, 0.35f, 0.0f);*/
    // glColor3f (0.0, 0.0, 1.0);
    //     glVertex3f(0.5f, 0.35f, 0.0f);
    //     glVertex3f(0.75f, 0.35f, 0.0f);
    //     glVertex3f(0.63f, 0.50f, 0.0f);


    //     //Triangle
    //     /*glVertex3f(0.30f, 0.65f, 0.0f);
    //     glVertex3f(0.60f, 0.65f, 0.0f);
    //     glVertex3f(0.45, 0.85f, 0.0f);*/


    //     glEnd();//End triangle coordinates
/* don't wait!
* start processing buffered OpenGL routines
*/
glFlush ();
}
void init (void)
{
/* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Demo");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
