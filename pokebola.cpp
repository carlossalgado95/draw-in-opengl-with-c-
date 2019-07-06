/*
*Authors:   Arildes Lima
*	    Carlos Henrique Cruz Salgado
*	    João Ritter	
*/

#include <GL/glut.h> 
#include <cmath>

void desenho()
    {
        glColor3f(0.8f,0.8f,0.8f);
        glLineWidth(3);
        glBegin(GL_POINTS);
        float x = 0;
        while(x<=360.0f)
        {
            glVertex2f(cos(x)*7,sin(x)*7);
            glVertex2f(((cos(x)*7)/4),((sin(x)*7)/4));
            glVertex2f(((cos(x)*7)/8),((sin(x)*7)/8));
            glVertex2f((((cos(x)*7)/10)+3),(((sin(x)*7)/10)+4));

	    x=x+0.01;
            
        }
	float c=-7.0f;
	while(c<=7.0f)
        {
	    if(c<-1.75f || c>1.75f)
            {
            	glVertex2f(c,0.5f);
            	glVertex2f(c,-0.5f);
	    	
            }
            c=c+0.01;
            
        }
        glEnd();
       
    } 

void DesenhaNaTela(void) 

{ 

    glClear(GL_COLOR_BUFFER_BIT); 

    desenho(); 

    glutSwapBuffers(); 

} 

void Inicializa (void) 

{
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-10.0f,10.0f,-10.0f,10.0f);
        glMatrixMode(GL_MODELVIEW); 

} 



int main(int argc, char** argv) 

{ 

    glutInit(&argc,argv); 

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

    glutInitWindowSize(500,500); 

    glutInitWindowPosition(100,100); 

    glutCreateWindow("Pokebola"); 

    glutDisplayFunc(DesenhaNaTela); 

    Inicializa(); 

    glutMainLoop(); 

}
