/*
+-------------------------------------------------+
|Disciplina: Introdu��o a Computa��o Gr�fica      |
|Aluno: Rodrigo da Silva Costa                    |
|Turma: Manha                                     |
|Titulo trabalho: Lista 2                         | 
|Comandos:                                        |
|W ou w -> Mover submarino para cima              |
|S ou s -> Mover submarino para baixo             |
|A ou a -> Mover submarino para esquerda          |
|D ou d -> Mover submarino pra direita            |
|ENTER -> Mover submarino para o centro           |                                      |
+ ------------------------------------------------+
*/

#include <stdlib.h>
#include <GL/glut.h>
#include<math.h>
#define pi 3.14 //define  pi

// Vari�veis que guardam a transla��o que ser� aplicada 
// sobre o peixe
GLfloat Tx,Txx;
GLfloat Ty,Tyy;
// Vari�veis que guardam os valores m�nimos de x 
GLfloat minX,minXX, maxX,maxXX;
GLfloat rota,rota2,rotay;
// Vari�veis que guardam o tamanho do incremento nas 
// dire��es x  (n�mero de pixels para se mover a 
// cada intervalo de tempo)
GLfloat xStep;
// Vari�veis que guardam a largura e altura da janela
GLfloat windowXmin, windowXmax;

// Fun��o callback de redesenho da janela de visualiza��o
void DesenharPeixe(void)
{
      //Triangulo maior (Corpo do peixe)
      glBegin(GL_TRIANGLES); 
         glColor3f(0.1,0.1,0.44);
         glVertex2f(-8,0);
         glColor3f(0,0.5,1);
         glVertex2f(0,8);
         glColor3f(0,0.75,1);
         glVertex2f(0,-8);
      glEnd();
      
      //Efeito de contorno no triangulo maior(Corpo do peixe)
      glBegin(GL_LINE_LOOP);
         glColor3f(0,0,0);
         glVertex2f(-8,0);
         glVertex2f(0,8);
         glVertex2f(0,-8);
      glEnd();
     
      
      //Triangulo menor ( Calda do peixe)
      glBegin(GL_TRIANGLES);
         glColor3f(0.07,0.04,0.56);
         glVertex2f(0,0);
         glVertex2f(4,2);
         glVertex2f(4,-2);
      glEnd();
      
      //Efeito de contorno no triangulo menor(Calda do peixe)
      glBegin(GL_LINE_LOOP);
         glColor3f(0,0,0);
         glVertex2f(0,0);
         glVertex2f(4,2);
         glVertex2f(4,-2);
      glEnd();
      
      //Nadadeira do peixe
      glBegin(GL_QUADS);
         glColor3f(0.07,0.04,0.56);
         glVertex2f(-2.5,-1);
         glVertex2f(-2.5,1); 
         glVertex2f(-1,2);
         glVertex2f(-1,-2);
      glEnd();
      
      //Efeito de contorno na nadadeira do peixe
      glBegin(GL_LINE_LOOP);
         glColor3f(0,0,0);
         glVertex2f(-2.5,-1);
         glVertex2f(-2.5,1); 
         glVertex2f(-1,2);
         glVertex2f(-1,-2);
      glEnd();
      //Olho do peixe
      glBegin(GL_POLYGON);
         float teta,raio = 0.4;  // define o raio do circulo
         int angulo = 360, ; // define um circulo com angulo completo de 360
         int x = -6,y = 0; // define x e y no centro do plano cartesiano

         glColor3f(0,0,0);
              for(int i = 0; i <= angulo; i++) { 
                      teta = (i*pi)/180; 
                      glVertex2f(x + (cos(teta) * raio),
                      y +(sin(teta) * raio)); //seta os pontos que ser�o 
                                              // conectados em cada eixo formando 
                                              // assim o circulo 
             }
      glEnd(); 
    
      //Linhas do Peixe 
      glBegin(GL_LINES);
         glColor3f(0,0,0); 
         glVertex2f(-6,-2);
         glVertex2f(-4,0);
         glVertex2f(2.5,1);
         glVertex2f(4,1);
         glVertex2f(2.5,-1);
         glVertex2f(4,-1);
         glVertex2f(-6,2);
         glVertex2f(-4,0);
         glVertex2f(-8,0);
         glVertex2f(-7.5,0);
         glVertex2f(-2,0);
         glVertex2f(-1,0);
         glVertex2f(2,0);
         glVertex2f(4,0);
         glVertex2f(-2,1);
         glVertex2f(-1,1.5);
         glVertex2f(-2,-1);
         glVertex2f(-1,-1.5);   
      glEnd();

}
void DesenharJanelaSubmarino()
{     
      glBegin(GL_POLYGON);
      glColor3f(1,1,1);
         float teta,raio = 1.0;  // define o raio do circulo
         int angulo = 360;     // define um circulo com angulo completo de 360
         int x = 0,y = 0;     // define x e y no centro do plano cartesiano

         
              for(int i = 0; i <= angulo; i++) { 
                      teta = (i*pi)/180; 
                      glVertex2f(x + (cos(teta) * raio),
                      y +(sin(teta) * raio)); //seta os pontos que ser�o 
                                              // conectados em cada eixo formando 
                                              // assim o circulo 
             }
      glEnd(); 
      
      glBegin(GL_LINE_STRIP);

          teta,raio = 1.2;  // define o raio do circulo
          angulo = 360; // define um circulo com angulo completo de 360
          x = 0,y = 0; // define x e y no centro do plano cartesiano

         glColor3f(0,0,0);
              for(int i = 0; i <= angulo; i++) { 
                      teta = (i*pi)/180; 
                      glVertex2f(x + (cos(teta) * raio),
                      y +(sin(teta) * raio)); //seta os pontos que ser�o 
                                              // conectados em cada eixo formando 
                                              // assim o circulo 
             }
      glEnd(); 
    
    
  
     
}
void DesenharSubmarino(void)
{  

    
    // Corpo do submarino
    glColor3f(0.5f, 0.5f, 0.5f); // cinza
    glBegin(GL_POLYGON);
    
        glVertex2f(-4.5,0);
        glVertex2f(-4.5,0.5);
        glVertex2f(-3,2);
        glVertex2f(-2,2.5);
        glVertex2f(2,2.5);
        glVertex2f(3.5,1);
        glVertex2f(5.5,1);
        glVertex2f(6,0.5);
        glVertex2f(6,-0.5);
        glVertex2f(5.5,-1);
        glVertex2f(3.5,-1);
        glVertex2f(2,-2.5);
        glVertex2f(-2,-2.5);
        glVertex2f(-3,-2);
        glVertex2f(-4.5,-0.5);
        
    glEnd();
   	
    
    // Bloco superior Submarino
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_POLYGON);
    
        glVertex2f(-1.5,2.5);
        glVertex2f(-1,3);
        glVertex2f(1,3);
        glVertex2f(1.5,2.5);
    glEnd();
    

    
    // Cabine do submarino
    glColor3f(1.0f, 1.0f, 1.0f); // branco
    glBegin(GL_POLYGON);
        glVertex2f(-4.5,0);
        glVertex2f(-4.5,0.5);
        glVertex2f(-3,2);
        glVertex2f(-2,1);
        glVertex2f(-2,-1);
        glVertex2f(-3,-2);
        glVertex2f(-4.5,-0.5);        
    glEnd();
    
    
    // Calda Superior do submarino
    glColor3f(1.0f, 1.0f, 1.0f); // branco
    glBegin(GL_TRIANGLES);
        glVertex2f(3.5,1);
        glVertex2f(5.5,3);
        glVertex2f(5.5,1);
    glEnd();
        
    // Calda Inferior do submarino
    glColor3f(1.0f, 1.0f, 1.0f); // branco
    glBegin(GL_TRIANGLES);
        glVertex2f(3.5,-1);
        glVertex2f(5.5,-3);
        glVertex2f(5.5,-1);
        
    glEnd();
    
    // Helices do Submarino
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(6.5,1);
        glVertex2f(7.5,1);
        glVertex2f(7.0,0);
    glBegin(GL_TRIANGLES);
        glVertex2f(7.0,0);
        glVertex2f(7.5,-1);
        glVertex2f(6.5,-1);
       
    glEnd();
    
    glLineWidth(5.0f);
    // Eixo do Helice
    glBegin(GL_LINES); 
         glColor3f(0,0,0); 
         glVertex2f(6,0);
         glVertex2f(7,0);
    glEnd();
    glLineWidth(1.0f);
    
    // Visor do submarino
    glColor3f(0.5f, 0.5f, 0.5f); // cinza
    glBegin(GL_QUADS);
        glVertex2f(0,3); 
        glVertex2f(-0.5,3);
        glVertex2f(-0.5,4);
        glVertex2f(0,4);
    glColor3f(0.5f, 0.5f, 0.5f); // cinza 
    glBegin(GL_QUADS);
        glVertex2f(0,4); 
        glVertex2f(-1.5,4);
        glVertex2f(-1.5,4.5);   
        glVertex2f(0,4.5);             
    glEnd();
    
    DesenharJanelaSubmarino();
   	glTranslatef(4.5f,0.0f, 0.0f);
   	glScalef(0.50f, 0.50f, 1.0f);
   	DesenharJanelaSubmarino();
      
}

void DesenharPedra()
{
     glColor3f(0.59f, 0.29f, 0.0f); // marrom
     glBegin(GL_POLYGON);
        glVertex2f(0,-2.5);
        glVertex2f(-0.5,-2.2);
        glVertex2f(-1,-2.1);
        glVertex2f(-1.5,-2.1);
        glVertex2f(-2,-2);
        glVertex2f(-2.5,-2.2);
        glVertex2f(-3,-2.4);
        glVertex2f(-3.5,-2.5);
        glVertex2f(-3.7,-2.5);
        glVertex2f(-3.9,-2.3);
        glVertex2f(-3.8,-2);
        glVertex2f(-3.5,-1);
        glVertex2f(-2.5,-0.5);
        glVertex2f(-2,-0.3);
        glVertex2f(-1.5,-0.2);
        glVertex2f(-1,-0.3);
        glVertex2f(-0.5,-0.1);
        glVertex2f(-0.5,0);
        glVertex2f(0.5,-0.1);
        glVertex2f(1,-0.2);
        glVertex2f(1.5,-0.1);
        glVertex2f(2,-0.2);
        glVertex2f(2.5,-0.5);
        glVertex2f(2.8,-1);
        glVertex2f(2.7,-1.5);
        glVertex2f(2.5,-2);
        glVertex2f(2,-2.5);
        glVertex2f(1.5,-2.6);
        glVertex2f(1,-2.7);
        glVertex2f(0.5,-2.6);
    glEnd();
   	
}

void DesenharAreia()
{
    glColor3f(0.98f, 0.93f, 0.36f); // Amarelo(Milho)
    glBegin(GL_QUADS);
        glVertex2f(-50,0); 
        glVertex2f(108,0);
        glVertex2f(108,-40);   
        glVertex2f(-50,-40); 
    glEnd();
     
}
void DesenharFolha()
{
     glColor3f(0.13f, 0.55f, 0.13f); // verde floresta
     glBegin(GL_POLYGON);
        glVertex2f(0,-0.5);
        glVertex2f(0.5,0);
        glVertex2f(0.3,0.5);
        glVertex2f(0.5,1);
        glVertex2f(0.8,1.5);
        glVertex2f(1,2);
        glVertex2f(1.5,2);
        glVertex2f(2,2.5);
        glVertex2f(2.5,3);
        glVertex2f(3,3.5);
        glVertex2f(4,4);
        glVertex2f(5,7);
        glVertex2f(5.5,7.5);
        glVertex2f(5.8,8);
        glVertex2f(6,8.5);
        glVertex2f(6.5,9);
        glVertex2f(7,9.5);
        glVertex2f(6,8.8);
        glVertex2f(5.5,8.5);
        glVertex2f(5,8);
        glVertex2f(4.5,7.8);
        glVertex2f(4,7.5);
        glVertex2f(3.5,7.3);
        glVertex2f(3,7);
        glVertex2f(2.5,6.5);
        glVertex2f(2,6);
        glVertex2f(1.5,5.5);
        glVertex2f(1.3,5);
        glVertex2f(1,4.5);
        glVertex2f(0.8,4);
        glVertex2f(0.8,3.5);
        glVertex2f(0.8,3);
        glVertex2f(0.9,2.5);
        glVertex2f(0.9,2.2);
        glVertex2f(0.5,1.6);
        glVertex2f(0.3,1);
        glVertex2f(0,0.5);
        glVertex2f(0,0);
        glVertex2f(-0.5,-0.5);

    glEnd();
}
void exibirPeixes()
{
     // Inicializa a matriz de transforma��o corrente
	glLoadIdentity();
	
     // Aplica uma transla��o sobre o peixe
	glTranslatef(Tx, Ty, 0.0f);
	// Aplica rota��o no Peixe
	glRotatef(rota, 0.0f, 0.0f, 1.0f); 
	// Desenha o Peixe
	DesenharPeixe();
	
	glLoadIdentity();
	
    glScalef(0.50f, 0.50f, 1.0f);	
	glTranslatef(Tx+10, 20.0f, 0.0f);
	glRotatef(rota, 0.0f, 0.0f, 1.0f); 
	DesenharPeixe();
	
	glLoadIdentity();
	
    glScalef(0.80f, 0.80f, 1.0f);	
	glTranslatef(Tx+15, -20.0f, 0.0f);
	glRotatef(rota, 0.0f, 0.0f, 1.0f); 
	DesenharPeixe();
	
	glLoadIdentity();
	
    glScalef(0.20f, 0.20f, 1.0f);	
	glTranslatef(Tx+5, -25.0f, 0.0f);
	glRotatef(rota, 0.0f, 0.0f, 1.0f); 
	DesenharPeixe();
	
	glLoadIdentity();
	
    glScalef(0.30f, 0.30f, 1.0f);	
	glTranslatef(Tx+40, 40.0f, 0.0f);
	glRotatef(rota, 0.0f, 0.0f, 1.0f); 
	DesenharPeixe();
	
	// Muda a dire��o do peixe quando atinge a borda
	 if( (Tx+maxX) > windowXmax || (Tx+minX) < windowXmin ){ 
		rota += 180;                                          
		                                                     
        }
}
void exibirSubmarino()
{    
     glLoadIdentity();
     
     glTranslatef(Txx, Tyy, 0.0f);
     glRotatef(rota2,rotay,0.0f,1.0f); 
     glScalef(2.0f, 2.0f, 1.0f);	
     DesenharSubmarino();
     
    
  
}
void exibirPedra()
{
     glLoadIdentity();
     
     glTranslatef(-35, -25, 0.0f);
     glScalef(5.0f, 5.0f, 1.0f);	
     DesenharPedra();
     
     glLoadIdentity();
     
     glTranslatef(40, -25, 0.0f);
     glScalef(2.0f, 2.0f, 1.0f);
     glRotatef(0, 0.0f, 0.0f, 1.0f); 	
     DesenharPedra();
     
     
}
void exibirAreia()
{
     glLoadIdentity();
     
     glTranslatef(-30, -20, 0.0f);
     DesenharAreia();
}
void exibirFolha()
{
     glLoadIdentity();
     
     glScalef(2.0f, 4.0f, 1.0f);
     glTranslatef(-20.0f, -6.3f, 0.0f);
     DesenharFolha();
     
     glLoadIdentity();
     
     glScalef(3.0f, 4.0f, 1.0f);
     glTranslatef(-14.0f, -6.3f, 0.0f);
     glRotatef(90.0f, 0.0f, 0.0f, 1.0f); 
     DesenharFolha();
     
     glLoadIdentity();
     
     glScalef(3.0f, 4.0f, 1.0f);
     glTranslatef(-13.0f, -6.3f, 0.0f);
     glRotatef(-35.0f, 0.0f, 0.0f, 1.0f); 
     DesenharFolha();
     
      
     glLoadIdentity();
     
     glScalef(1.0f, 1.0f, 1.0f);
     glTranslatef(40.0, -25.0, 0.0);
     glRotatef(-35.0f, 0.0f, 0.0f, 1.0f); 
     DesenharFolha();
     
      glLoadIdentity();
     
     glScalef(1.0f, 1.0f, 1.0f);
     glTranslatef(40.0, -25.0, 0.0);
     glRotatef(90.0f, 0.0f, 0.0f, 1.0f); 
     DesenharFolha();
     
     glLoadIdentity();
     
     glScalef(1.0f, 1.0f, 1.0f);
     glTranslatef(40.0, -25.0, 0.0);
     DesenharFolha();
}

void Display(void)
{
     
	// Muda para o sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa a matriz de transforma��o corrente Limpa a janela de
    // visualiza��o com a cor de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);
	
    exibirAreia();
	exibirPeixes();
    exibirSubmarino();
    exibirFolha();
    exibirPedra();
    
    
    
   

	glutSwapBuffers();	
}


// Fun��o callback chamada quando o tamanho da janela � alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	GLsizei largura, altura;

	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as vari�veis
	largura = w;
	altura = h;

	// Especifica as dimens�es da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de sele��o (esquerda, direita, inferior, 
	// superior) mantendo a propor��o com a janela de visualiza��o
	if (largura <= altura) 
	{
		gluOrtho2D (-40.0f, 40.0f, -40.0f*altura/largura, 40.0f*altura/largura);
		windowXmin = -40.0f;
		windowXmax =  40.0f;

	}
	else
	{ 
		gluOrtho2D (-40.0f*largura/altura, 40.0f*largura/altura, -40.0f, 40.0f);
		windowXmin = -40.0f*largura/altura;
		windowXmax =  40.0f*largura/altura;

	}
}

// Fun��o callback chamada pela GLUT a cada intervalo de tempo
void Anima(int value)
{
	// Muda a dire��o quando chega na borda esquerda ou direita
	if( (Tx+maxX) > windowXmax || (Tx+minX) < windowXmin )
		xStep = -xStep;

	// Move o peixe no eixo X
	Tx += xStep;

	// Redesenha o peixe em outra posi��o
	glutPostRedisplay();
	glutTimerFunc(150,Anima, 1);
}


// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
     
    // Fechar Programa (sair) ESC
    if(key == 27)
    {
        exit(0);
    }
    //Mover para direita  D
	if(key == 100 || key == 68){
              
       Txx ++;
              
    }
    // Mover para esquerda A
   	if(key == 97 || key == 65)
    { 
       if(Tyy >= -18){ 
       Txx --;
       }
    }
    
    // Mover para Cima  W
	if(key == 119 || key == 87){ 
      if(Tyy <= 40){
       Tyy++; 
       }
     }
    // Mover para baixo  S
   	if(key == 115 || key == 83){ 
      if(Tyy >= -17){
       Tyy--; 
       }
     }
    // Centraliza ENTERaaaaaa
	if(key == 13 ){ 
       
       Txx = Tyy = 0; 

     }
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa (void)
{   
	// Define a cor de fundo da janela de visualiza��o
	glClearColor(0.13f, 0.70f, 0.67f, 1.0f );

	// Inicializa��o das vari�veis globais
	rota = 180.0f;
	rota2 = 0.0f;
	xStep = 1.0f;
	Tx = Ty = Txx = Tyy = 0.0f;
	minX = -10.0f;
	maxX =  10.0f;

	windowXmin = -40.0f;
	windowXmax = 40.0f;
}

// Programa Principal 
int main(void)
{
	// Define do modo de opera��o da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 

	// Especifica a posi��o inicial da janela GLUT
	glutInitWindowPosition(0,0); 

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(1366,768 ); 

	// Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Aquario 2D Animado");

	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(Display);

	// Registra a fun��o callback de redimensionamento da janela de visualiza��o
	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a fun��o callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	// Registra a fun��o callback que ser� chamada a cada intervalo de tempo
	glutTimerFunc(150, Anima, 1);
	//glutTimerFunc(150, Anima2, 1);

	// Chama a fun��o respons�vel por fazer as inicializa��es 
	Inicializa();

	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();

	return 0;
}
