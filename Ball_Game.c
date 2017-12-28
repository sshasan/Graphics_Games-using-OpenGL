#include <GL/glut.h>
#include <math.h> 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


float XX=300, YY = 300;
int delta =5;
int count=0;
int flag = 0;
int speed=0;
int r = 10;
float tx1=0,ty1=0;
int scorevar = 0;
// Trajectory Equation

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  
	glMatrixMode (GL_PROJECTION);
	//gluOrtho2D (-400.0, 800.0, -400.0, 800.0);
	gluOrtho2D (0.0, 1000.0, 0.0, 1000.0);
}

void ball(float x, float y)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		//glColor3f(0, 1.0, 0.0);	
        int i=0,j=0;
        for(i=0;i<5000;i++)
        {
        	for(j=0;j<r;j++)
        	{
	        		glVertex2f(x+j*cos(i),j*sin(i)+y);
            }
        }
	}		

void Target()
	{

		if(flag ==0)
			{	
				tx1 = (rand() % 400) + 120 ;
				ty1 = (rand() % 400)+ 110;
				flag = 1;
			}
			glBegin(GL_POINTS);
			glColor3f(0, 1, 0);	
			ball(tx1,ty1);
			glEnd();

	}

void Player()
	{
		glBegin(GL_POINTS);
		glColor3f(1.0, 0.0, 0.0);	
		ball(XX,YY);
		glEnd();

	}	

void SpecialKeys(int key, int x, int y)
	{
		if(key == GLUT_KEY_RIGHT)
			{
				XX = XX + delta;
				//count--;
			}
		else if(key == GLUT_KEY_LEFT)
			{
				XX = XX - delta;
				//count--;
			}
		else if(key == GLUT_KEY_UP)
			{
				YY = YY + delta;
				//count--;
			}
		else if(key == GLUT_KEY_DOWN)
			{
				YY = YY - delta;
				//count--;
			}			
		glutPostRedisplay();	
	}

void Keys(unsigned char key, int x, int y)
	{
		if(key == '1')
			{
				speed=1;
			}
		else if(key == '2')
			{
				speed=2;
			}
		else if(key == '3')
			{
				speed=3;
			}		
		glutPostRedisplay();	
	}		

void Timer(int value)
{
	glutPostRedisplay();
	if(speed = 1)		
	glutTimerFunc(100,Timer,0);
    else if(speed == 2)
    glutTimerFunc(60,Timer,0);	
    else if(speed == 3)
    glutTimerFunc(30,Timer,0);	
}

float dis(float x1, float y1, float x2, float y2)
	{
		return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	}

void colloid()
	{
		if(dis(tx1,ty1,XX,YY)<20)
			{	flag = 0;
				scorevar++;
				glColor3f(0,0,1);
				ball(XX,YY);
			}
		else if(count % 80==0)
			flag=0;
					

	}

void scoredisplay (int posx, int posy, int posz, int space_char, int scorevar)
{
        int j=0;
        int p,k;
        GLvoid *font_style1 = GLUT_BITMAP_TIMES_ROMAN_24;
       
        p = scorevar;
        j = 0;
        k = 0;
        while(p > 9)
        {
            k = p % 10;
            glRasterPos3f ((posx-(j*space_char)),posy, posz);   
            glutBitmapCharacter(font_style1,48+k);
            j++;
            p /= 10;
        }
            glRasterPos3f ((posx-(j*space_char)), posy, posz);   
            glutBitmapCharacter(font_style1,48+p);
      
}

void border()
	{

		glColor3f(0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(100,100);
		glVertex2f(600,100);
		glVertex2f(600,120);
		glVertex2f(100,120);
		glEnd();

		glColor3f(0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(600,100);
		glVertex2f(600,600);
		glVertex2f(580,600);
		glVertex2f(580,100);
		glEnd();

		glColor3f(0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(100,100);
		glVertex2f(120,100);
		glVertex2f(120,600);
		glVertex2f(100,600);
		glEnd();

		glColor3f(0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(100,600);
		glVertex2f(600,600);
		glVertex2f(600,620);
		glVertex2f(100,620);
		glEnd();
	}
/*
void drawStrokeText(char*string,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,z);
	  glScalef(0.09f,-0.08f,z);
  
	  for (c=string; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}

void drawBitmapText(char *string,float x,float y,float z) 
{  
	char *c;
	glRasterPos3f(x, y,z);

	//for (c=string; *c != ' '; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}

void render(void)
{ 
	//gglClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();
 
	glColor3f(0,1,0);
	drawStrokeText("Osama Hosam's OpenGL Tutorials",200,200,0);

	glutSwapBuffers(); 
}
*/

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	

	border();
	scoredisplay(900,800,0,10,scorevar);
	scoredisplay(900,750,0,10,count++);
	colloid();

	Player();

	Target();

	glFlush();
}


void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1300, 700);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutSpecialFunc(SpecialKeys);
	glutTimerFunc(0,Timer,0);
	glutKeyboardFunc(Keys);
	glutMainLoop();
}