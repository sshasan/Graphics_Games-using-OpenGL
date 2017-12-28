#include <GL/glut.h>
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


float YY = 800,YY1=800;
int delta =5;
int rot = 0;
int speed=0;
int CarP = 1;
int Div = 1;
int side=0;
int XX=0;
int coll=0;
int score=0;
int fps = 8;
int cond=0;
// Trajectory Equation

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  
	glMatrixMode (GL_PROJECTION);
	//gluOrtho2D (-400.0, 800.0, -400.0, 800.0);
	gluOrtho2D (0.0, 1000.0, 0.0, 1000.0);

}

void coordinate()
	{
		int i=0;

		for(i=-400;i<1000;i++)
			{
				glVertex2f(i,30);
				glVertex2f(30,i);
			}// xy-axis

	}

void dash()
	{
		int i=0;

		for(i=-400;i<1000;i=i+50)
			{
				glVertex2f(i,20);
				glVertex2f(i,40);

				glVertex2f(20,i);
				glVertex2f(40,i);
			}// xy-axis

	}//dash	


void tree(int x, int y)
	{
		//rest1
		glColor3f(0.0,1,0);
		glBegin(GL_POLYGON);
		{
			glVertex2f(x+110,y+45 );
			glVertex2f(x+150,y+70 );
			glVertex2f(x+125,y+100 );
			glVertex2f(x+140,y+120);
			glVertex2f(x+105,y+170);
			glVertex2f(x+70,y+120 );
			glVertex2f(x+85,y+100);
			glVertex2f(x+60,y+70);
			glVertex2f(x+100,y+45 );
			glVertex2f(x+105,y+120);
		}glEnd();

		//stem1
		glColor3f(0.5,0.35,0.05);
		glBegin(GL_POLYGON);
		{
			glVertex2f(x+100,5 );
			glVertex2f(x+110,5 );
			glVertex2f(x+110,y+25 );
			glVertex2f(x+105,y+100);
			glVertex2f(x+100,y+25);
		}glEnd();

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

int Colloid()
	{
		if((CarP == 1) && (YY == 75) && (side==0))
			coll = 1;
		if((CarP == 2) && (YY== 75)&& (side==1))
			coll=2;

		if(coll==1 || coll==2)
		{	
			printf("Bye");
			cond=1;
			return 1;
		}

		printf("Colloid %d YY%f\n",coll,YY);

		return 0;
	}

void mountain(int x, int y, int w)
	{
		glColor3f(0.5,0.35,0.05);
		glBegin(GL_POLYGON);
			{
				glVertex2f(120,0);
				glVertex2f(300,0);
				glVertex2f(200,300);
			}glEnd();
	}	

void CarL1(int YY) // enemy car
	{
		glColor3f(0,1,0);
		glBegin(GL_POLYGON);
			{
				glVertex2f(350,YY+30);
				glVertex2f(400,YY+30);
				glVertex2f(400,YY+120);
				glVertex2f(350,YY+120);
			}glEnd();
		}

void CarR1(int YY) // enemy car
	{
		XX = 150;
		glColor3f(0,1,0);
		glBegin(GL_POLYGON);
			{
				glVertex2f(XX+350,YY+30);
				glVertex2f(XX+400,YY+30);
				glVertex2f(XX+400,YY+120);
				glVertex2f(XX+350,YY+120);
			}glEnd();
		}				

void CarL()
	{
		glColor3f(1,0,0);
		glBegin(GL_POLYGON);
			{
				glVertex2f(350,30);
				glVertex2f(400,30);
				glVertex2f(400,120);
				glVertex2f(350,120);
			}glEnd();
		}	
void CarR()
	{
		glColor3f(1,0,0);
		glBegin(GL_POLYGON);
			{
				glVertex2f(500,30);
				glVertex2f(550,30);
				glVertex2f(550,120);
				glVertex2f(500,120);
			}glEnd();
		}	

void road()
	{
		glColor3f(0.5,0.35,0.05);
		glBegin(GL_POLYGON);
			glVertex2f(300,0);
			glVertex2f(600,0);
			glVertex2f(600,950);
			glVertex2f(300,950);
			//glVertex2f(600,800);
		glEnd();	
	}

void Divider(int y)
	{
		
		glColor3f(0,0,0);
		glBegin(GL_POLYGON);
			{
			glVertex2f(440,0+y);
			glVertex2f(460,0+y);
			glVertex2f(460,50+y);
			glVertex2f(440,50+y);	
			}
		glEnd();	
	}


void backGround()
	{
		
		tree(0,0);
		tree(200,50);
		tree(300,10);
		tree(800,20);
		//cloud(100,100);
	}		

void SpecialKeys(int key, int x, int y)
	{
		if(key == GLUT_KEY_RIGHT)
			{
				//XX = XX + delta;
				CarP = 2;
			}
		else if(key == GLUT_KEY_LEFT)
			{
				CarP = 1;
				//XX = XX - delta;
			}

		glutPostRedisplay();	
	}

void speed_control()
	{

		if(speed >1000 && speed < 2000)
			{
				fps=1;
			}
		else if(speed >=2000 && speed < 3000)
			{
				fps=1;
			}
		else if(speed >=3000)
			{
				fps=1;
			}		
	}	

void Keys(unsigned char key, int x, int y)
	{
		if(key == '1')
			{
				exit(1);
			}	
	}		

void Timer(int value)
{	
	if(coll!=1)
	speed++;
	printf("%d fps %d",speed,fps);
	glutPostRedisplay();
    glutTimerFunc(fps,Timer,0);	
}

void Divider1()
	{
		//Divider(0);
		Divider(90);
		Divider(190);
		Divider(290);
		Divider(390);
		Divider(490);
		Divider(590);
		Divider(690);
		Divider(790);
		Divider(890);
	}

void Divider2()
	{
		Divider(40);
		Divider(150);
		Divider(250);
		Divider(350);
		Divider(450);
		Divider(550);
		Divider(650);
		Divider(750);
		Divider(850);
		Divider(950);
	}	

void GameOver()
	{
		glRasterPos2f(350,400);
		char *s = "GAME OVER\n(press 1 to exit)";
		int j=0;

		while(j<strlen(s))
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(char)s[j]);
				j++;
			}

	}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);

	speed_control();
	//tree(60,0);

	if(coll!=1 && cond==0)
		YY = YY-1;

	if(speed%800==0 && cond==0)
		{ 
			YY = 800;
			side = rand()%2;
			int c= 0;
			score++;
			printf("%dside",side);
		}

	if(coll!=1 && cond==0)
		YY1 = YY1-1;

	if(speed%400==0 && cond==0)
		{ 
			YY1 = 800;
			side = rand()%2;
			int c= 0;
			//score++;
			printf("%dside",side);
		}	

	printf("Score---%d\n",score);	
	road();

	if(speed%200==0)
		Div = -1*Div;
		
	if(Div==1 && cond==0 )
		Divider1();
	else Divider2();

	if(side==0)
	{
		CarL1(YY);
	}
	else if(side==1) {
		CarR1(YY);
	}	 
	
	if(CarP==1)  //control
	CarL();
	else
	CarR();	

	int p=Colloid();
	
	if(p==1)
	{
		GameOver();
		//exit(1);
	}

	scoredisplay(900,750,0,10,score);

		glFlush();
}


void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1200, 800);
	glutInitWindowPosition (300, 300);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutSpecialFunc(SpecialKeys);
	glutTimerFunc(0,Timer,0);
	
	glutKeyboardFunc(Keys);
	glutMainLoop();
}
