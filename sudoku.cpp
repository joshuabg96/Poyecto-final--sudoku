// Solving Problems with Programming
// Professor Ken Bauer
//
// Sudoku

// Josué Bernabe González
// A01229975
// and
// Eduardo Torres Burgos 
// A01630914

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int sudoku[9][9];
int prohibido[9][9];
string archivo;
string rojo="\x1b[31m"; //colores inicio
string verde="\x1b[32m";
string blanco="\x1b[47m";
string azul="\x1b[34m";
string terminar="\x1b[0m"; //(regresar al color blanco)
//colores  final

void tablero()
{
	 int i,j, o=1;
	 for (j=0;j<=8;j++)
	 {
		 if (j>0&&j%3==0) cout<<"\n";
		 cout<<"                     "<<rojo<<o<<terminar<<verde<<"|  "<<terminar;
	 	 for (i=0;i<=8;i++)
	 	 {
		 	 if (i>0&&i%3==0) cout<<"\t";
			 if (sudoku[i][j] !=0 && prohibido[i][j]==1)
			 {
			 	cout<<blanco<<rojo;
			 }
			 else if(sudoku[i][j] !=0)
			 {
			 	cout<<terminar;
			 	cout<<verde;
			 }
		 	 cout<<" "<<sudoku[i][j];
		 	 cout<<terminar;
		 }
		 cout<<endl;
		 o++;
	 }
	 cout<<"                "<<blanco<<rojo<<"(filas)"<<terminar;
	 cout<<"\n";
}

void lectura(){
	 FILE* texto;
  	 texto = fopen(archivo.c_str(),"r");
	 while (texto==NULL){
	 	   system("cls");
	 	   cout<<"Error al abrir el archivo"<<endl;
		   cout<<"Introdusca el nombre del archivo en la forma archivo.txt"<<endl;
		   cin>>archivo;
  	 	   texto = fopen(archivo.c_str(),"r");
	 }
	 char car;
     int N,a,b;
	 car=getc(texto);
     a=0;b=0;
     while (!feof(texto))
     {
           N=car;
		   N=N-48;
           if ((N>=0)&&(N<=9))
           {
           	  sudoku[a][b]=N;
			  if (N!=0)
			  {
			  	 prohibido[a][b]=1;
			  }
			  else 
			  {
			  		prohibido[a][b]=0;
			  }
			  if (a==8) 
			  {
			  	 a=0;
				 b++;
			  } else{
			  	a++;
			  }
		   }
           car=getc(texto);
	 }
     fclose(texto);
    getchar();
}

void agregar(int colu, int fila, int num){

	 if (prohibido[colu-1][fila-1] ==1)
	 {
	 	cout<<"El valor de este espacio no se puede cambiar \npresiona enter para continuar"<<endl;
	 }
	 else
	 {
	 	   if (num>=1 && num<=9)
	 	   {
	 	   	sudoku[colu-1][fila-1] = num;
	 	    cout<<"Bien hecho \nun numero menos \npresiona enter para continuar"<<endl;
	 	   }
	 	   else
	 	   {
		   	cout<<"el numero ingresado no es valido \npresiona enter para continuar"<<endl;
		   }
	 }
}

void borrar(int colu, int fila)
{
	 if (prohibido[colu-1][fila-1] ==1)
	 {
	 	cout<<"El valor de este espacio no se puede borrar"<<endl;
	 }
	 else
	 {
	 	   sudoku[colu-1][fila-1]=0;
	 }
}
bool cfila(int fila, int num)
{
	 int i;
	 bool resul = false;
	 for (i=0;i<=9;i++)
	 {
	 	 if (sudoku[i][fila] == num)
	 	 {
		 	resul = true;
		 }
	 }
	 return resul;
}

bool gane()
{
	 int i, j;
 	 bool resul;
	 resul = true;
	 for (i=0;i<=9;i++)
	 {
	 	 for (j=0;j<=9;j++)
	 	 {
		 	 if (sudoku[i][j] == 0)
		 	 {
			 	resul = false;
			 }
		 }
	 }
	 return resul;
}

bool ccolumna(int colu, int num)
{
	 int j;
	 bool resul = false;
	 for (j=0;j<=9;j++)
	 {
	 	 if (sudoku[colu][j] == num)
	 	 {
		 	resul = true;
		 }
	 }
	 return resul;
}

bool ccuadro(int colu, int fila, int num){
	 int i,j;
	 bool resul = false;
	 for (i=((colu)*3);i<=(((colu/3)*3)+2);i++)
	 {
	 	 	 for (j=((fila/3)*3);j<=(((fila/3)*3)+2);j++)
	 	 	 {
			 	 if (sudoku[i][j] == num)
			 	 {
		 		 	resul = true;
		 		 }
			 }
	 }
	 return resul;
}

int main()
{

	string filename;
	int col, fila, n, opciones, del;
	cout<<"\n\n                  "<<verde<<"BIENVENIDO A ESTE MARAVILLOSO SUDOKU"<<terminar<<"\n       Escriba el nombre del tablero que desea jugar (extencion .txt)"<<endl;
	cin>>filename;
	archivo=filename;
    lectura();
	cout<<endl;
	while (opciones!=9)
	{

	  cout<<""<<endl;
	  cout<<"           1) decidiste ingresar un numero? hazlo aqui"<<endl;
	  cout<<"           2) no lo hiciste bien? borralo con esta opcion"<<endl;
	  cout<<"           3) Culturizando (leer es saber)"<<endl;
	  cout<<"           4) no sabes jugar? ingresa esta opcion :)"<<endl;
	  cout<<rojo<<"           5) SALIR"<<terminar<<endl;
		  
		  cout<<azul<<"                         1 2 3 "<<terminar<<verde<<"|"<<terminar<<azul<<" 4 5 6 "<<terminar<<verde<<"|"<<terminar<<azul<<" 7 8 9 "<<terminar<<verde<<"|"<<terminar<<"    "<<blanco<<azul<<"(columnas)"<<terminar<<endl;
		  tablero();
		  cin>>opciones;
		  switch (opciones)
		  {
		  		 case 1:
				 	  cout<<azul<<"en que se columna se encuentra?"<<endl;
					  cin>>col;
					  cout<<terminar;
					  getchar();
					  cout<<rojo<<"en que fila se encuentra?"<<endl;
					  cin>>fila;
					  cout<<terminar;
					  getchar();
					  cout<<verde<<"que numero quieres ingresar?"<<endl;
					  cin>>n;
					  cout<<terminar;
					  getchar();
						  if (cfila(fila-1,n) == false && ccolumna(col-1,n) == false && ccuadro(col-1,fila-1,n) == false)
						  {
						  	 agregar(col,fila,n);
							 if (gane())
							 {
							 	opciones = 9;
								cout<<verde<<"               FELICIDADES"<<terminar<<"\n          TERMINASTE EL RETO DE SUDOKU"<<endl;
								tablero();
							 }
						  }
						  else
						  {
						  		cout<<"Este numero no se puede colocar en esa posicion"<<endl;
						  		cout<<"Presiona enter para continuar"<<endl;
						  }
					  getchar();
					  system("cls");
				 break;
				 case 2:
				 	  cout<<rojo<<"en que columna se encuentra el numero?"<<endl;
					  cin>>col;
					  getchar();
					  cout<<terminar;
					  cout<<azul<<"en que fila se encuentra el numero?"<<endl;
					  cin>>fila;
					  getchar();
					  cout<<terminar;
					  cout<<"Seguro que quieres elminiarlo :("<<endl;
					  cout<<"1)si"<<endl;
					  cout<<"2)no"<<endl;
					  cin>>del;
					  if (del==1){
					  	 borrar(col,fila);
						 cout<<"el numero ha sido borrado con exito"<<endl;
					  }else cout<<"no se ha borrado el número"<<endl;
					  system("cls");
				 break;
              case 3:
                  cout<<blanco<<" Es un juego matematico que se publico por primera vez a finales de la decada de 1970 y se popularizo en Japon en 1986, dandose a conocer en el ambito internacional en 2005 cuando numerosos periodicos empezaron a publicarlo en su seccion de pasatiempos. El objetivo del sudoku es rellenar una cuadricula de 9 por 9 celdas (81 casillas) dividida en subcuadriculas de 3 por 3 (tambien llamadas cajas o regiones) con las cifras del 1 al 9 partiendo de algunos numeros ya dispuestos en algunas de las celdas. Aunque se podrian usar colores, letras, figuras, se conviene en usar numeros para mayor claridad, lo que importa, es que sean nueve elementos diferenciados, que no se deben repetir en una misma fila, columna o subcuadricula. Un sudoku esta bien planteado si la solucion es unica, algo que el matematico Gary McGuire ha demostrado que no es posible si no hay un minimo de 17 cifras de pista al principio. La solucion de un sudoku siempre es un cuadrado latino, aunque el reciproco en general no es cierto ya que el sudoku establece la restriccion de que no se puede repetir un mismo numero en una region. \n\n\ns/a. (s/f) Sudoku. Wikipedia, la enciclopedia libre. Recuperado de: http://es.wikipedia.org/wiki/Sudoku"<<terminar<<endl;
                  cout<<""<<endl;
                  cout<<""<<endl;
                  break;
              case 4:
              		cout<<"El sudoku es una cuadricula de 9 por 9 subdividida en cuadriculas de 3 por 3, en un principio, algunas casillas empeizan con numeros y otras blancas, el objetivo del juego es poder rellenar todas las casillas vacias con números del 1 al 9 en las casillas de 3 por 3, siempre y cuando cumplan ciertas especificaciones tales como que en cada fila solo debe de haber un número de cada uno, por ejemplo, no puede haber dos numeros 1 en la misma fila, esto es igual aplicable en las columnas ya que un número debe de aparecer solo una vez en cada columna. otra condicion es que en una region cada numero debe de aparecer solo una vez \n\nen resumen, un número debe de aparecer solamente una vez en cada fila, columna y region. \n\n y cuando logres haber llenado todos los espacios, habras ganado\n\n";
              break;
				 case 5:
				  opciones=9;
				 	  break;
				 	break;
				 default:
				 		 getchar();
				 		 cout<<"                        "<<rojo<<"OPCION INVALIDA"<<terminar<<"\n             por favor ingresa una opcion valida\n               presiona enter para continuar"<<endl;
						 getchar();
						 system("cls");
						 break;
		  }
	}
}
