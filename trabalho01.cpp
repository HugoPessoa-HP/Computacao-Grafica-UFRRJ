#include <GL/glut.h>
#include <GL/gl.h>

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
		glVertex2i(100,150);      	  //vértice
		glVertex2i(150,150);     	  //vértice
		glColor3f(0.0f, 2.0f, 1.0f);	  // coloração
		glVertex2i(125,200);     	  //vértice
	glEnd();
	glFlush();
}

// Inicializa parâmetros de renderização
void Inicializa(void)
{
	// Cor preta da janela de visualização
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void AlteraTamanhoJanela(GLsizei w,GLsizei h){
	//Evita divisão por zero
	if (h == 0) h = 1; 
	
	//Especifica dimensões do Viewport
	glViewport(0, 0, w, h);

	//Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Janela de seleção
	if (w <= h)                                                
		gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);     //Especificação do tamanho mín e máx das coordenadas x e y
	else
		gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f);         //Especificação do tamanho nín e máx das coordenadas x e y

}

// Programa 

int main(int argc, char **argv)
{
	
	glutInit(&argc, argv);  
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
        glutInitWindowSize(500,500);
        glutInitWindowPosition(10,10);
        glutCreateWindow("Triangulo");
        glutDisplayFunc(Desenha);
        glutReshapeFunc(AlteraTamanhoJanela);
        Inicializa();
        glutMainLoop();	

}





