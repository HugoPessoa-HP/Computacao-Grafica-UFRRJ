#include <GL/glut.h>
#include <GL/gl.h>

// Tamanho e posição inicial do triângulo
        GLfloat x = 100.0f;
        GLfloat y = 150.0f;
        GLsizei aux = 25;

// Incremento nas direções x e y (pixels movidos a cada intervalo de tempo).
        GLfloat xstep = 1.0f;
        GLfloat ystep = 1.0f;

// Largura e altura da janela
	GLfloat windowWidth;
	GLfloat windowHeight;


int main(int argc, char **argv);

void Desenha(void){
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        //Limpa a janela de visualização
        glClear(GL_COLOR_BUFFER_BIT);

        //Especifica a cor corrente
        glColor3f(1.0f, 0.0f, 0.0f);

        //Desenha um triângulo preenchido com a cor corrente
        glBegin(GL_TRIANGLES);
                glVertex2i( x , y );                            //vértice
                glVertex2i( x + (2 * aux) , y );                //vértice
                glColor3f(0.0f, 2.0f, 1.0f);                    // coloração
                glVertex2i( x + aux , y + (4 * aux));            //vértice
        glEnd();
        glFlush();

	// Executa os comandos OpenGL
        glutSwapBuffers();
} 

// Função callback chamada pela GLUT a cada intervalo de tempo
void Timer(int value){

	// Muda a direção quando chega na borda esquerda ou direita
    	if(x > windowWidth-(2 * aux) || x < 0)
            xstep = -xstep;

    	// Verifica as bordas.  Se a window for menor e o
    	// Triangulo sair do volume de visualização
   	if(x > windowWidth-aux)
            x = windowWidth-aux-1;

    	// Move o Triangulo
            x += xstep;

    	// Redesenha o triangulo com as novas coordenadas
    	glutPostRedisplay();
    	glutTimerFunc(33,Timer, 1);
}

// Inicializa parâmetros de rendering
void Inicializa(void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
     // Evita a divisao por zero
     if(h == 0) h = 1;
                           
     // Especifica as dimensões da Viewport
     glViewport(0, 0, w, h);

     // Inicializa o sistema de coordenadas
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();

     // Estabelece a janela de seleção (left, right, bottom, top)     
     if (w <= h)  {
		windowHeight = 250.0f*h/w;
		windowWidth = 250.0f;
     }
     else  { 
		windowWidth = 250.0f*w/h;
		windowHeight = 250.0f;
     }
     
     gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}


// Programa Principal
int main(int argc, char **argv)
{
     glutInit(&argc, argv); 
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     glutInitWindowSize(500,500);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Animacao Triangulo");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     glutTimerFunc(33, Timer, 1);
     Inicializa();
     glutMainLoop();
}
