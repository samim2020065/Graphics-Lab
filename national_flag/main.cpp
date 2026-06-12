#include<GL/freeglut.h>
#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>visited;
int h=0.0,k=0.0,r=8.0;
int mx=-1,my=-1;
void circlebresenham(int cx,int cy,int r){
    int x=0.0,y=r,d=3-2*r;
    while(x<=y){
        glVertex3f(cx+x,cy+y,0.0);
        glVertex3f(cx+x,cy-y,0.0);
        glVertex3f(cx-x,cy-y,0.0);
        glVertex3f(cx-x,cy+y,0.0);

        glVertex3f(cx+y,cy+x,0.0);
        glVertex3f(cx-y,cy+x,0.0);
        glVertex3f(cx-y,cy-x,0.0);
        glVertex3f(cx+y,cy-x,0.0);
        if(d>=0){
            d=d+4*(x-y)+10;
            y-=1;
        }
        else{
            d=d+4*x+6;
        }
        x+=1;
    }
}
/*void floodfillcircle(int x,int y,vector<vector<int>>&visited)
{
    if(visited[x+100][y+100])
        return;

    if((x-h)*(x-h)+(y-k)*(y-k) > r*r)
        return;

    visited[x+100][y+100]=1;

    glVertex3f(x,y,0.0);

    floodfillcircle(x,y-1,visited);
    floodfillcircle(x,y+1,visited);
    floodfillcircle(x-1,y,visited);
    floodfillcircle(x+1,y,visited);
}
void floodfillrectangle(int x,int y,vector<vector<int>>&visited){

    if(x < -20 || x > 30 || y < -15 || y > 15)
        return;
    if(visited[x+100][y+100]){
        return;
    }
    if((x-h)*(x-h)+(y-k)*(y-k)-(r*r)<=0){
        return;
    }
    visited[x+100][y+100]=1;
    glVertex3f(x,y,0.0);
    floodfillrectangle(x,y-1,visited);
    floodfillrectangle(x,y+1,visited);
    floodfillrectangle(x-1,y,visited);
    floodfillrectangle(x+1,y,visited);
}
void reset_visited_array(){
    for(int i=0;i<200;i++)
        {
            for(int j=0;j<200;j++)
            {
                visited[i][j] = 0;
            }
        }
}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2d(-20,-15);
    glVertex2d(30,-15);

    glVertex2d(30,-15);
    glVertex2d(30,15);

    glVertex2d(30,15);
    glVertex2d(-20,15);

    glVertex2d(-20,15);
    glVertex2d(-20,-15);
    glEnd();
    glBegin(GL_POINTS);
    circlebresenham(0.0,0.0,8.0);
    if(mx != -1 && my != -1)
    {
        if((mx-h)*(mx-h)+(my-k)*(my-k) <= r*r)
        {
            reset_visited_array();
            glColor3f(1.0,0.0,0.0);
            floodfillcircle(mx,my,visited);
        }
        else if(mx>=-20 && mx<=30 && my>=-15 && my<=15)
        {
            reset_visited_array();
            glColor3f(0.0,1.0,0.0);
            floodfillrectangle(mx,my,visited);
        }

    }
    glEnd();
    glFlush();
}

void my_mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mx =-100+ x * 200 / 600;
        my = -100+(600 - y) * 200 / 600;


        glutPostRedisplay();
    }
}*/
void floodfillrectangle(int x,int y,map<pair<int,int>,int>&visited){

    if(visited[{x,y}]==1){
        return ;
    }
    if(x < -20 || x > 30 || y < -15 || y > 15)
        return;
    if((x-h)*(x-h)+(y-k)*(y-k)<=r*r){
        return;
    }
    glVertex3f(x,y,0.0);
    visited[{x,y}]=1;
    floodfillrectangle(x-1,y,visited);
    floodfillrectangle(x+1,y,visited);
    floodfillrectangle(x,y-1,visited);
    floodfillrectangle(x,y+1,visited);

}
void floodfillcircle(int x,int y,map<pair<int,int>,int>&visited){
    if(visited[{x,y}]==1){
        return ;
    }
    if((x-h)*(x-h)+(y-k)*(y-k)>r*r){
        return;
    }
    glVertex3f(x,y,0.0);
    visited[{x,y}]=1;
    floodfillcircle(x-1,y,visited);
    floodfillcircle(x+1,y,visited);
    floodfillcircle(x,y-1,visited);
    floodfillcircle(x,y+1,visited);

}
void reset_visited(){
    visited.clear();
}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_LINES);

    glVertex2d(-20,-15);
    glVertex2d(30,-15);

    glVertex2d(30,-15);
    glVertex2d(30,15);

    glVertex2d(30,15);
    glVertex2d(-20,15);

    glVertex2d(-20,15);
    glVertex2d(-20,-15);
    glEnd();
    glBegin(GL_POINTS);
    circlebresenham(0.0,0.0,8.0);

    if(mx!=-1&&my!=-1){
        if((mx-h)*(mx-h)+(my-k)*(my-k)<=r*r){
            reset_visited();
            glColor3f(1,0,0);
            floodfillcircle(mx,my,visited);
        }
        else if(mx>=-20 && mx<=30 && my>=-15 && my<=15)
        {
            reset_visited();
            glColor3f(0.0,1.0,0.0);
            floodfillrectangle(mx,my,visited);
        }
    }
    glEnd();
    glFlush();
}
void my_mouse(int button,int state,int x,int y){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        mx=-100+x*200/600;
        my=-100+(600-y)*200/600;
    }
    glutPostRedisplay();
}
void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glOrtho(-100.0,100.0,-100.0,100.0,-1.0,1.0);
}
int main(int argc, char** agrv){
    glutInit(&argc, agrv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Demo");
    init ();
    glutDisplayFunc(display);
    glutMouseFunc(my_mouse);
    glutMainLoop();
    return 0;
}
