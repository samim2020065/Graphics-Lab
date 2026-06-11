#include <GL/freeglut.h>
#include <bits/stdc++.h>
using namespace std;

const int WIDTH = 600;
const int HEIGHT = 600;



bool vis[WIDTH][HEIGHT];
int disArr[WIDTH][HEIGHT];

bool generated = false;

// --------------------------------------------
// BFS WAVE GENERATION
// --------------------------------------------
void BFS(int sx, int sy)
{
    memset(vis, false, sizeof(vis));

    queue<pair<int,int>> q;

    vis[sx][sy] = true;
    disArr[sx][sy] = 0;

    q.push({sx, sy});

    while (!q.empty())
    {
        auto cur = q.front();
        int x=cur.first;
        int y=cur.second;
        q.pop();

        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};

        for (int k = 0; k < 8; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < WIDTH &&
                ny >= 0 && ny < HEIGHT &&
                !vis[nx][ny])
            {
                vis[nx][ny] = true;

                disArr[nx][ny] =
                    disArr[x][y] + 1;

                q.push({nx, ny});
            }
        }
    }

    generated = true;
    glutPostRedisplay();
}

// --------------------------------------------
// DISPLAY
// --------------------------------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (generated)
    {
        glBegin(GL_POINTS);

        for (int x = 0; x < WIDTH; x++)
        {
            for (int y = 0; y < HEIGHT; y++)
            {
                float blue =
                    0.1f +
                    0.9f *
                    fabs(sin((float)disArr[x][y]));

                glColor3f(0.0f, 0.0f, blue);

                glVertex2i(x, y);
            }
        }

        glEnd();
    }

    glFlush();
}

// --------------------------------------------
// MOUSE CALLBACK
// --------------------------------------------
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON &&
        state == GLUT_DOWN)
    {
        y = HEIGHT - y;

        BFS(x, y);
    }
}

// --------------------------------------------
// INIT
// --------------------------------------------
void init()
{
    glClearColor(1,1,1,1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

// --------------------------------------------
// MAIN
// --------------------------------------------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(WIDTH, HEIGHT);

    glutInitWindowPosition(100,100);

    glutCreateWindow("Wave Generation using BFS");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}
