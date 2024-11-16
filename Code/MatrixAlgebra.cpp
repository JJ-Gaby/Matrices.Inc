/*Nathaniel Perez Marrero-Y00645223
Leyra Gabriela Bonilla Maldonado- Y00653864

Distribucion de trabajo:
Menu-Leyra
Estructura de informacion y ejemplos- Leyra
Do while- Leyra
Ejercicios de case 2 y 5- Leyra
Ejercicios de case 1, 3, 4- Nathaniel
Libreria stdlib- Nathaniel
Libreria Eigen- Leyra y Nathaniel
Array y loops- Nathaniel
Randomizadors de numeros en case 1- Nathaniel
Estructura de if, else para correctos e incorrectos- Leyra
Ejercicios de suma y resta (No en codigo)- Josmary*/

#include <iostream>
#include <Eigen/Dense>
#include <stdlib.h>
using namespace Eigen;
using namespace std;

int main(){ 
    srand(time(NULL)); //esta funcion genera numeros random 
    //el valor asignado viene siendo "NULL" que pone el seed y genera numeros aleatorios usando el valor de tiempo actual
    int menuOpc; //Variable para menu de opciones.
    Matrix2d matA, matB, matA2, matB2, matC, matD, matC2, matD2, matE, matF, matE2, matF2, mat2x2, mat2x2_2, mat2x2_3; //Matrix2d sirve para matrices 2x2, funciona como data type para guardar variables.
    Matrix3d matA3, matB3, matA4, matB4, matA5, matB5, matC3, matD3, matC4, matD4, matC5, matD5, matE3, matF3, matE4, matF4, matE5, matF5,  mat3x3, mat3x3_2, mat3x3_3, mat3x3_4; //Matrix3d sirve para matrices 3x3, funciona como data type para guardar variables.
    int correctas = 0, incorrectas = 0; //Contadores para respuestas correctas e incorrectas.
    double respuesta; //Variable para la respuesta del usuario.
    char respuestaLetra, continuar; //Variable para la respuesta del usuario para seleccion multiple y continuar para do while.
    
    //Bienvenida al usuario
    cout<<"Bienvenido a Matrices.Inc, aqui aprenderas todo lo relacionado con algebra de matrices.\n\n";

do {
    //Menu de opciones.
    cout<<"Menu de opciones desde lo mas basico a los mas complejo:\n";
    cout<<"1- Matrices especiales\n";
    cout<<"2- Suma de matrices\n";
    cout<<"3- Resta de matrices\n";
    cout<<"4- Multiplicacion de matrices\n";
    cout<<"5- Determinante de una matriz\n";
    cout<<"Introduce el numero de lo que desea aprender: ";
    cin>>menuOpc; //El usuario entra lo que desea aprender.
    cout<<"\n";
   
    switch(menuOpc){
    //Explicacion de material y ejemplo.
    case 1:{
     cout << "Ha seleccionado matrices especiales.\n\n";
    cout << "¿Que es una matriz?\n";
    cout << "Una matriz es una estructura matematica organizada en forma de una tabla rectangular de numeros, simbolos o expresiones, dispuestos en filas y columnas.\n";
    cout << "\nLas matrices se componen de filas y columnas, juntas forman lo que se le conoce como dimension. ";
    cout << "Una dimension se hace escribiendo la cantidad de filas primero y luego la cantidad de columnas de esta forma: fila x columna.\n";
    cout << "Ejemplo: \n";
    cout << "Supongamos que tenemos una matriz:\n";
    cout << "1 2\n";
    cout << "3 4\n";
    cout << "5 6\n";
    cout << "Esta matriz tiene 3 filas y 2 columnas y se escribe de la siguiente manera: 3x2. Primero se lee la fila hacia abajo y luego columna hacia la derecha.\n\n";
    //Ejercicios de practica.
    cout<<"\nResuelve los siguientes ejercicios:\n";
     
      for (int i = 0; i < 5; i++) { //Un loop basico que por cada num. que se le add a la i repite el mismo loop por cada ejercicio
        cout<< "\nEjercicio #" << i + 1 << "\n";

        //Generar random el tamaño de la matriz (2x2 o 3x3)
        int filas = (rand() % 2) + 2;  //Random 2 o 3 filas|| esto es lo mismo que (num.rand % 2 + 2), la misma formula en ambos generadores
        int columnas = (rand() % 2) + 2;  //Random 2 o 3 columnas

        //Esto crea una matriz 3x3, en un multi-dimensional array(capitulo de W3school)
        int matriz[3][3] = {0};  // los dos cubos de array empiezan y son igual a 0

        //Llena la matriz con num. random entre 1 y 9
        for (int f = 0; f < filas; f++) { //Aqui la f se suma hasta llegar al resultado del int filas que seria 2 o 3.
            for (int c = 0; c < columnas; c++) { //Aqui viene siendo lo mismo que en filas, se suma hasta llegar al num. generado en columnas
                matriz[f][c] = rand() % 9 + 1;  //Num. aleatorios entre 1 y 9 en ambas cajas del array, como lo hicimos arriba asignando 0 en ambos
            }
        }

        //Mostrar matriz al usuario
        cout << "\nMatriz generada:" << "\n";
        for (int f = 0; f < filas; f++) { //Aqui es lo mismo que arriba lo unico que ahora cada fila tiene el num. random generado por rand.
            for (int c = 0; c < columnas; c++) {  //En la variable de c es lo mismo se imprimen  los numeros random
                cout<< matriz[f][c] << " ";        //Ejem. columnas=3 c=3{1= rand. num, 2= rand. num., 3= rand. num.} asi mismo se imprimen por cada fila.
            }
            cout << "\n";
        }

        //Usuario ingresa respuesta sobre cuantas filas y columnas tiene
        int filas_respuesta, columnas_respuesta;
        cout<<"\n¿Cuantas filas tiene esta matriz? ";
        cin>>filas_respuesta;
        cout<<"¿Cuantas columnas tiene esta matriz? ";
        cin>>columnas_respuesta;

        //Verificar si la respuesta es correcta
        if (filas_respuesta == filas && columnas_respuesta == columnas) {
            cout<< "Correcto! La matriz tiene " << filas << " filas y " << columnas << " columnas." << "/n";
        } else {
            cout<< "Incorrecto. La matriz tiene " << filas << " filas y " << columnas << " columnas." << "/n";
        }
    }
            
             } break;
     
      case 2:{
    //Explicacion de material y ejemplos.
    cout << "Ha seleccionado suma de matrices.\n\n";
    cout << "Como se suman las matrices?\n";
    cout << "Para sumar matrices, debes seguir estos pasos:\n1.Verifica que las matrices sean del mismo tamaño: La suma de matrices solo es posible si ambas tienen el mismo numero de filas y columnas.\n";
    cout << "2.Suma los elementos correspondientes: Toma cada elemento en la misma posicion de ambas matrices y sumalos.\n";
    cout << "Ejemplo:\nSupongamos que tienes dos matrices:\n";
    cout << "A= 1 2  y  B= 5 6\n";
    cout << "   3 4        7 8\n";
    cout << "Para sumarlas, sumas los elementos en cada posicion:\n";
    cout << "A+B= 1+5  2+6\n";
    cout << "     3+7  4+8\n";
    cout << "El resultado de A+B es:\n";
    cout << "6    8\n";
    cout << "10  12\n";
    //Ejercicios de practica.
    cout << "\nResuelve los siguientes ejercicios:\n";
    cout << "Para cada matriz, ingresa el valor de la suma.\n\n";
    //Ejercicio #1
    cout << "Ejercicio 1: Matriz 2x2\n";
    cout << "Ejercicio 1: Calcula la suma de la matriz 2x2:\n";
    //Indica valores de la matriz 2x2.
    matA << 4, 7, 2, 5; 
    matB << 7, 6, 9, 5;
    //Mostrar matriz al usuario.
    cout << matA << "\n\n";
    cout << matB << "\n";

    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la suma de la matriz A + B:\n";
    cout << "A. \n11 13\n11 10\n";
    cout << "B. \n12 12\n12 12\n";
    cout << "C. \n11 11\n13 10\n";
    cout << "D. \n10 14\n12 11\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";
    
    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'A' || respuestaLetra == 'a') {
        cout << "¡Correcto! La suma de la matriz A + B es:\n" << matA + matB << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable.
    } else {
        cout << "Incorrecto. La respuesta correcta es A.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

    //Ejercicio 2
    cout << "\nEjercicio 2: Matriz 2x2\n";
    //Indica valores de la matriz 2x2.
    matA2 << 3, 8, 1, 4;
    matB2 << 5, 3, 6, 7;
    //Mostrar matriz al usuario.
    cout << matA2 << "\n\n";
    cout << matB2 << "\n";
    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la suma de la matriz A + B:\n";
    cout << "A. \n8 11\n7 11\n";
    cout << "B. \n9 9\n6 9\n";
    cout << "C. \n9 11\n7 11\n";
    cout << "D. \n8 10\n8 10\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";

    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'C' || respuestaLetra == 'c') {
        cout << "¡Correcto! La suma de matA + matB es:\n" << matA2 + matB2 << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable.
    } else {
        cout << "Incorrecto. La respuesta correcta es C.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

    //Ejercicio 3
    cout << "\nEjercicio 3: Matriz 3x3\n";
    //Indica valores de la matriz 3x3.
    matA3 << 2, 5, 3, 1, 4, 7, 6, 8, 9;
    matB3 << 3, 4, 5, 2, 3, 6, 1, 5, 2;
    //Mostrar matriz al usuario.
    cout << matA3 << "\n\n";
    cout << matB3 << "\n";
    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la suma de matA + matB:\n";
    cout << "A. \n5 9 8\n3 7 13\n7 13 11\n";
    cout << "B. \n4 8 7\n3 7 11\n6 12 10\n";
    cout << "C. \n6 9 7\n4 8 13\n6 13 11\n";
    cout << "D. \n5 8 8\n3 7 13\n7 13 11\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";

    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'A' || respuestaLetra == 'a') {
        cout << "¡Correcto! La suma de matA + matB es:\n" << matA3 + matB3 << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable.
    } else {
        cout << "Incorrecto. La respuesta correcta es A.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

    //Ejercicio 4
    cout << "\nEjercicio 4: Matriz 3x3\n";
    //Indica valores de la matriz 3x3.
    matA4 << 4, 2, 5, 7, 1, 3, 8, 4, 2;
    matB4 << 1, 7, 3, 4, 6, 2, 5, 3, 4;
    //Mostrar matriz al usuario.
    cout << matA4 << "\n\n";
    cout << matB4 << "\n";
    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la suma de matA + matB:\n";
    cout << "A. \n5 9 8\n11 7 5\n13 7 6\n";
    cout << "B. \n5 8 8\n11 7 5\n13 6 6\n";
    cout << "C. \n5 8 8\n11 7 6\n13 7 6\n";
    cout << "D. \n6 9 9\n12 7 7\n13 6 6\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";

    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'C' || respuestaLetra == 'c') {
        cout << "¡Correcto! La suma de matA + matB es:\n" << matA4 + matB4 << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable.
    } else {
        cout << "Incorrecto. La respuesta correcta es C.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

     //Ejercicio 5
    cout << "\nEjercicio 4: Matriz 3x3\n";
    cout << "Calcula la suma de la siguiente matriz 3x3:\n";
    //Indica valores de la matriz 3x3.
    matA5 << 4, 2, 5, 7, 1, 3, 8, 4, 2;
    matB5 << 1, 7, 3, 4, 6, 2, 5, 3, 4;
    //Mostrar matriz al usuario.
    cout << matA5 << "\n\n";
    cout << matB5 << "\n";
    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la suma de matC + matD:\n";
    cout << "A. \n5 9 8\n11 7 5\n13 7 6\n";
    cout << "B. \n5 8 8\n11 7 5\n13 6 6\n";
    cout << "C. \n5 8 8\n11 7 6\n13 7 6\n";
    cout << "D. \n6 9 9\n12 7 7\n13 6 6\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";

    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'C' || respuestaLetra == 'c') {
        cout << "¡Correcto! La suma de matA + matB es:\n" << matA5 + matB5 << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable. 
    } else {
        cout << "Incorrecto. La respuesta correcta es C.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

    
    //Resultado final
    cout << "\nResultados:\n";
    cout << "Respuestas correctas: " << correctas << "\n";
    cout << "Respuestas incorrectas: " << incorrectas << "\n";

    //Explicacion del resultado
    if (correctas >= 4) {
        cout << "¡Buen trabajo! Has entendido bien la suma de matrices.\n";
    } else {
        cout << "Sigue practicando los pasos para calcular la suma de matrices. Revisa los ejemplos y formulas.\n";
    }
      }
    break;

      case 3:{
    //Explicacion de material y ejemplos sobre diferentes casos paso a paso. 
    cout << "Ha seleccionado resta de matrices.\n\n";
    cout << "Como se restan las matrices?\n";
    cout << "Para restar matrices, sigue estos pasos:\n";
    cout << "1. Verifica que las matrices sean del mismo tamaño: La resta de matrices solo es posible si ambas tienen el mismo numero de filas y columnas.\n";
    cout << "2. Resta los elementos correspondientes: Toma cada elemento en la misma posicion de ambas matrices y restalos.\n";
    cout << "Ejemplo:\nSupongamos que tienes dos matrices:\n";
    cout << "A= 1 2  y  B= 5 6\n";
    cout << "   3 4        7 8\n";
    cout << "Para restarlas, resta los elementos en cada posicion:\n";
    cout << "A-B= 1-5  2-6\n";
    cout << "     3-7  4-8\n";
    cout << "El resultado de A-B es:\n";
    cout << "-4  -4\n";
    cout << "-4  -4\n";
    cout << "Ejemplo 2:\n";
    cout << "A= 8  3  y  B= -4  2\n";
    cout << "   6  5        1  -7\n";
    cout << "Para restarlas, resta los elementos en cada posicion:\n";
    cout << "A-B= 8-(-4)  3-2\n";
    cout << "     6-1     5-(-7)\n";
    cout << "El resultado de A-B es:\n";
    cout << " 12   1\n";
    cout << " 5   12\n";
    //Ejercicios de practica.
    cout << "\nResuelve los siguientes ejercicios:\n";
    cout << "Para cada matriz, ingresa el valor de la resta.\n\n";
    //Ejercicio #1
    cout << "Ejercicio 1: Matriz 2x2\n";
    cout << "Ejercicio 1: Calcula la resta de la matriz 2x2:\n";
    //Indica valores de la matriz 2x2.
    matC << 9, 1, 1, 1; 
    matD << 1, 2, 1, 8;
    //Mostrar matriz al usuario.
    cout << matC << "\n\n";
    cout << matD << "\n";

    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la resta de la matriz A - B:\n";
    cout << "A. \n8 -1\n0 -7\n";
    cout << "B. \n8 0\n2 -7\n";
    cout << "C. \n10 -3\n0 9\n";
    cout << "D. \n10 -14\n12 -11\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";
    
    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'A' || respuestaLetra == 'a') {
        cout << "¡Correcto! La resta de la matriz es:\n" << matC - matD << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable.
    } else {
        cout << "Incorrecto. La respuesta correcta es A.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

    //Ejercicio 2
    cout << "\nEjercicio 2: Matriz 2x2\n";
    //Indica valores de la matriz 2x2.
    matC2 << 7, 9, 2, 8;
    matD2 << 12, 3, 6, 5;
    //Mostrar matriz al usuario.
    cout << matC2 << "\n\n";
    cout << matD2 << "\n";
    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la resta de las matrices:\n";
    cout << "A. \n5 6\n-4 3\n";
    cout << "B. \n9 0\n6 8\n";
    cout << "C. \n-5 6\n-4 3\n";
    cout << "D. \n8 10\n8 8\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";

    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'C' || respuestaLetra == 'c') {
        cout << "¡Correcto! La resta de las matrices es:\n" << matC2 - matD2 << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable.
    } else {
        cout << "Incorrecto. La respuesta correcta es C.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

    //Ejercicio 3
    cout << "\nEjercicio 3: Matriz 3x3\n";
    //Indica valores de la matriz 3x3.
    matC3 << 2, 5, 3, 1, 4, 7, 6, 8, 9;
    matD3 << 3, 4, 5, 2, 3, 6, 1, 5, 2;
    //Mostrar matriz al usuario.
    cout << matC3 << "\n\n";
    cout << matD3 << "\n";
    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la resta de las matrices:\n";
    cout << "A. \n1 1 2\n-1 -1 1\n-5 6 4\n";
    cout << "B. \n6 7 9\n7 0 12\n4 5 3\n";
    cout << "C. \n6 8 5\n3 9 6\n5 6 -7\n";
    cout << "D. \n-1 1 -2\n-1 1 1\n5 3 7\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";

    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'D' || respuestaLetra == 'd') {
        cout << "¡Correcto! La resta de la matrices es:\n" << matC3 - matD3 << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable.
    } else {
        cout << "Incorrecto. La respuesta correcta es D.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

    //Ejercicio 4
    cout << "\nEjercicio 4: Matriz 3x3\n";
    //Indica valores de la matriz 3x3.
    matC4 << 6, 2, 4, 8, 3, 9, 12, 2, -5;
    matD4 << 21, 6, 8, 2, 7, 19, 2, 4, -9;
    //Mostrar matriz al usuario.
    cout << matC4 << "\n\n";
    cout << matD4 << "\n";
    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la resta de las matrices:\n";
    cout << "A. \n-15 5 6 \n-4 7 5\n13 7 6\n";
    cout << "B. \n -15 -4 -4 \n 6 -4 -10 \n 10 -2 4 \n";
    cout << "C. \n4 8 8\n6 4 10\n-10 2 4\n";
    cout << "D. \n-15 5 6\n-4 -7 5\n13 7 6\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";

    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'B' || respuestaLetra == 'b') {
        cout << "¡Correcto! La resta de las matrices es:\n" << matC4 -  matD4 << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable.
    } else {
        cout << "Incorrecto. La respuesta correcta es B.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

     //Ejercicio 5
    cout << "\nEjercicio 4: Matriz 3x3\n";
    cout << "Calcula la resta de la siguiente matriz 3x3:\n";
    //Indica valores de la matriz 3x3.
    matC5 << -12, 4, 17, -8, 3, -8, 5, 4, 1;
    matD5 << 3, 7, -5, 3, 2, -5, -3, 12, -21;
    //Mostrar matriz al usuario.
    cout << matC5 << "\n\n";
    cout << matD5 << "\n";
    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la resta de las matrices:\n";
    cout << "A. \n2 9 15\n11 7 5\n-11 8 20\n";
    cout << "B. \n9 -3 22\n-11 1 3\n8 -8 22\n";
    cout << "C. \n-15 -3 22\n-11 1 -3\n8 -8 22\n";
    cout << "D. \n6 9 9\n12 7 7\n13 6 6\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";

    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'C' || respuestaLetra == 'c') {
        cout << "¡Correcto! La resta de las matrices es:\n" << matC5 - matD5 << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable. 
    } else {
        cout << "Incorrecto. La respuesta correcta es C.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

    
    //Resultado final
    cout << "\nResultados:\n";
    cout << "Respuestas correctas: " << correctas << "\n";
    cout << "Respuestas incorrectas: " << incorrectas << "\n";

    //Explicacion del resultado
    if (correctas >= 4) {
        cout << "¡Buen trabajo! Has entendido bien la suma de matrices.\n";
    } else {
        cout << "Sigue practicando los pasos para calcular la suma de matrices. Revisa los ejemplos y formulas.\n";
    }
      }
    break;

      case 4:{
    //Explicacion de material y ejemplos de distintos casos.
    cout << "Ha seleccionado multiplicacion de matrices.\n\n";
    cout << "Como se multiplican las matrices?\n";
    cout << "Para multiplicar matrices, sigue estos pasos:\n";
    cout << "1. Verifica que el numero de columnas de la primera matriz sea igual al numero de filas de la segunda matriz.\n";
    cout << "2. Multiplica cada fila de la primera matriz por cada columna de la segunda matriz y suma los productos.\n";
    cout << "Ejemplo:\nSupongamos que tienes dos matrices:\n";
    cout << "A = 1  2  y  B = 3  4\n";
    cout << "    3  4         5  6\n";
    cout << "Para multiplicarlas, multiplica las filas de A por las columnas de B:\n";
    cout << "A*B = (1*3 + 2*5)  (1*4 + 2*6)\n";
    cout << "      (3*3 + 4*5)  (3*4 + 4*6)\n";
    cout << "El resultado de A*B es:\n";
    cout << " 13  16\n";
    cout << " 29  36\n";
    cout << "Ejemplo 2: Multiplicacion de matrices rectangulares (2x3) x (3x2)\n";
    cout << "A = 1  2  3  y  B = 7  8\n";
    cout << "    4  5  6        9 10\n";
    cout << "                 11 12\n";
    cout << "A*B = (1*7 + 2*9 + 3*11)  (1*8 + 2*10 + 3*12)\n";
    cout << "      (4*7 + 5*9 + 6*11)  (4*8 + 5*10 + 6*12)\n";
    cout << "Resultado:\n";
    cout << " 58  64\n";
    cout << "139 154\n\n";
     cout << "Ejemplo 3: Multiplicacion de matrices (3x2) x (2x3)\n";
    cout << "A = 1  2  y  B = 7  8  9\n";
    cout << "    3  4        10 11 12\n";
    cout << "    5  6\n";
    cout << "A*B = (1*7 + 2*10)  (1*8 + 2*11)  (1*9 + 2*12)\n";
    cout << "      (3*7 + 4*10)  (3*8 + 4*11)  (3*9 + 4*12)\n";
    cout << "      (5*7 + 6*10)  (5*8 + 6*11)  (5*9 + 6*12)\n";
    cout << "Resultado:\n";
    cout << "27  30  33\n";
    cout << "61  68  75\n";
    cout << "95 106 117\n\n";
     cout << "Ejemplo 4: Multiplicacion con matriz identidad (2x2)\n";
    cout << "A = 1  2  y  I = 1  0\n";
    cout << "    3  4         0  1\n";
    cout << "A*I = (1*1 + 2*0)  (1*0 + 2*1)\n";
    cout << "      (3*1 + 4*0)  (3*0 + 4*1)\n";
    cout << "Resultado:\n";
    cout << " 1  2\n";
    cout << " 3  4\n";
    //Ejercicios de practica.
    cout << "\nResuelve los siguientes ejercicios:\n";

     cout << "Para cada matriz, ingresa el valor de la multiplicacion.\n\n";
    //Ejercicio #1
    cout << "Ejercicio 1: Matriz 2x2\n";
    cout << "Ejercicio 1: Calcula la multiplicacion de la matriz 2x2:\n";
    //Indica valores de la matriz 2x2.
    matE << 4, 7, 2, 5; 
    matF << 7, 6, 9, 5;
    //Mostrar matriz al usuario.
    cout << matE << "\n\n";
    cout << matF << "\n";

    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la multiplicacion de la matriz:\n";
    cout << "A. \n95 61\n60 38\n";
    cout << "B. \n12 12\n12 12\n";      
    cout << "C. \n90 49\n98 30\n";
    cout << "D. \n91 59\n59 37\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";
    
    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'D' || respuestaLetra == 'd') {
        cout << "¡Correcto! La multiplicacion de las matrices es:\n" << matE * matF << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable.
    } else {
        cout << "Incorrecto. La respuesta correcta es D.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

    //Ejercicio 2
    cout << "\nEjercicio 2: Matriz 2x2\n";
    //Indica valores de la matriz 2x2.
    matE2 << 3, 8, 1, 4;
    matF2 << 5, 3, 6, 7;
    //Mostrar matriz al usuario.
    cout << matE2 << "\n\n";
    cout << matF2 << "\n";
    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la multiplicacion de la matrices:\n";
    cout << "A. \n63 65\n29 31\n";
    cout << "B. \n65 29\n65 31\n";
    cout << "C. \n55 19\n70 22\n";
    cout << "D. \n10 19\n8 10\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";

    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'A' || respuestaLetra == 'a') {
        cout << "¡Correcto! La multiplicacion de las matrices es:\n" << matE2 * matF2 << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable.
    } else {
        cout << "Incorrecto. La respuesta correcta es A.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

    //Ejercicio 3
    cout << "\nEjercicio 3: Matriz 3x3\n";
    //Indica valores de la matriz 3x3.
    matE3 << 2, 9, 3, 1, 4, 10, 7, -8, 9;
    matF3 << 3, 4, -5, 2, 3, 12, 6, -7, 2;
    //Mostrar matriz al usuario.
    cout << matE3 << "\n\n";
    cout << matF3 << "\n";
    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la multiplicacion de las matrices:\n";
    cout << "A. \n5 9 8\n3 7 13\n7 13 11\n";
    cout << "B. \n5 9 70\n31 7 -11\n-56 12 10\n";
    cout << "C. \n42 14 104\n71 -54 63\n59 -59 -113\n";
    cout << "D. \n50 60 31\n6 89 -8\n186 34 -11\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";

    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'C' || respuestaLetra == 'c') {
        cout << "¡Correcto! La multiplicacion de esas matrices es:\n" << matE3 * matF3 << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable.
    } else {
        cout << "Incorrecto. La respuesta correcta es C.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

    //Ejercicio 4
    cout << "\nEjercicio 4: Matriz 3x3\n";
    //Indica valores de la matriz 3x3.
    matE4 << 14, 9, 5, 7, 6, 0, 9, 2, 4;
    matF4 << 15, 7, 30, 43, 5, 55, 3, 7, 0;
    //Mostrar matriz al usuario.
    cout << matE4 << "\n\n";
    cout << matF4 << "\n";
    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la multiplicacion de las matrices:\n";
    cout << "A. \n87 45 345\n745 987 132\n135 25 412\n";
    cout << "B. \n52 88 84\n115 79 57\n136 346 753\n";
    cout << "C. \n612 178 915\n363 79 540\n233 101 380\n";
    cout << "D. \n612 90 912\n128 87 100\n135 640 680\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";

    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'C' || respuestaLetra == 'c') {
        cout << "¡Correcto! La multiplicacion de estas matrices es:\n" << matE4 * matF4 << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable.
    } else {
        cout << "Incorrecto. La respuesta correcta es C.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

     //Ejercicio 5
    cout << "\nEjercicio 4: Matriz 3x3\n";
    cout << "Calcula la multiplicacion de la siguiente matriz 3x3:\n";
    //Indica valores de la matriz 3x3.
    matE5 << 47,102,88,59,207,34,88,2,6;
    matF5 << 5, 9, 6, 8, 7, 3, 4, 2, 5;
    //Mostrar matriz al usuario.
    cout << matE5 << "\n\n";
    cout << matF5 << "\n";
    //Mostrar opciones de respuesta al usuario.
    cout << "Selecciona la respuesta correcta para la multiplicacion de las matrices:\n";
    cout << "A. \n512 93 867\n113 789 598\n1323 732 634\n";
    cout << "B. \n1403 1313 1028\n2087 2048 1145\n480 818 564\n";
    cout << "C. \n555 834 876\n116 734 66\n136 71 62\n";
    cout << "D. \n62 95 92\n126 732 7432\n135 687 688\n";
    cout << "\nIngresa tu respuesta (A, B, C o D): ";

    //Entrada de respuesta del usuario.
    cin >> respuestaLetra;

    //Verifica si la respuesta es correcta.
    if (respuestaLetra == 'B' || respuestaLetra == 'b') {
        cout << "¡Correcto! La multiplicacion de las matrices es:\n" << matE5 + matF5 << endl;
        correctas++; //Cada contestacion correcta es sumada a esta variable. 
    } else {
        cout << "Incorrecto. La respuesta correcta es C.\n";
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
    }

    
    //Resultado final
    cout << "\nResultados:\n";
    cout << "Respuestas correctas: " << correctas << "\n";
    cout << "Respuestas incorrectas: " << incorrectas << "\n";

    //Explicacion del resultado
    if (correctas >= 4) {
        cout << "¡Buen trabajo! Has entendido bien la suma de matrices.\n";
    } else {
        cout << "Sigue practicando los pasos para calcular la suma de matrices. Revisa los ejemplos y formulas.\n";
    }
      }
    break;

      case 5:{
    //Explicacion de material y ejemplos.
    cout << "Ha seleccionado determinante de una matriz.\n\n";
    cout << "Como se saca la determinante de una matriz?\n";
    cout << "El determinante es un valor unico que se calcula a partir de los elementos de una matriz cuadrada (es decir, una matriz con el mismo numero de filas y columnas). Los determinantes tienen propiedades muy utiles, como indicar si una matriz es invertible y en la resolucion de sistemas de ecuaciones lineales.\n";
    cout << "Ejemplo de las diferentes formas de sacar la determinante de una matriz: \n\n";
    cout << "Ejemplo 1: Matriz 2x2\n";
    cout << "La formula del determinante para una matriz 2x2 A = [a b; c d] es: det(A) = (a * d) - (b * c)\n";
    //Indica valor de la matriz 2x2.
    mat2x2 << 4, 3,
              2, 1;
    //Explicacion en pasos sobre como llegar al resultado.
    cout << "Primera fila: a = 4, b = 3\n";
    cout << "Segunda fila: c = 2, d = 1\n";
    cout << "Matriz 2x2:\n" << mat2x2 << "\n";
    cout << "Determinante de la matriz 2x2: " << mat2x2.determinant() << "\n";
    cout << "Se deduce el resultado con el siguiente proceso: (4*1) - (3*2) = 4 - 6 = -2 \n\n";
    cout << "Ejemplo 2: Matriz 3x3\n";
    cout << "La formula del determinante para una matriz 3x3 A = [a b c; d e f; g h i] es: det(A) = a(ei - fh) - b(di - fg) + c(dh - eg)\n";
   //Indica valor de la matriz 3x3.
    mat3x3 << 6, 1, 1,  
              4, -2, 5,  
              2, 8, 7;  
    //Explicacion en pasos sobre como llegar al resultado.
    cout << "Primera fila: a = 6, b = 1, c = 1\n";
    cout << "Segunda fila: d = 4, e = -2, f = 5\n";
    cout << "Tercera fila: g = 2, h = 8, i = 7\n";
    cout << "Matriz 3x3:\n" << mat3x3 << "\n";
    cout << "Determinante de la matriz 3x3: " << mat3x3.determinant() << "\n\n";
    cout << "Paso a paso:\n";
    cout << "Primer termino: 6 * ((-2 * 7) - (5 * 8)) = 6 * (-54) = -324\n";
    cout << "Segundo termino: -1 * ((4 * 7) - (5 * 2)) = -1 * 18 = -18\n";
    cout << "Tercer termino: 1 * ((4 * 8) - (-2 * 2)) = 1 * 36 = 36\n";
    cout << "Sumando: -324 - 18 + 36 = -306\n\n";
    cout << "\nResuelve los siguientes ejercicios:\n";
    //Ejercicios de practica
    cout << "Para cada matriz, ingresa el valor del determinante.\n\n";
    //Ejercicio #1
    cout << "Ejercicio 1: Matriz 2x2\n";
    cout << "Ejercicio 1: Calcula el determinante de la matriz 2x2:\n";
   
    //Indica valor de la matriz 3x3.
    mat2x2_2 << 3, 4, 2, 5;
    //Mostrar matriz al usuario.
    cout << mat2x2_2 << "\n";
    cout << "Ingresa el determinante: ";

    //Entrada de respuesta del usuario.
    cin >> respuesta;
    cout << endl;

      //Verificar respuesta
      if (respuesta == mat2x2_2.determinant()) {
        correctas++; //Cada contestacion correcta es sumada a esta variable. 
      } else {
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
        cout << "Incorrecto. La respuesta correcta es: " << mat2x2_2.determinant() << "\n\n";
        }

    //Ejercicio #2:
    cout << "Ejercicio 2: Matriz 2x2\n";
    cout << "Ejercicio 2: Calcula el determinante de la matriz 2x2:\n";

    //Indica valor de la matriz 2x2.
    mat2x2_3 << -1, 2, 4, 3;
    //Mostrar matriz al usuario.
    cout << mat2x2_3 << "\n";
    cout << "Ingresa el determinante: ";

    //Entrada de respuesta del usuario.
    cin >> respuesta;
    cout << endl;

    //Verificar respuesta
    if (respuesta == mat2x2_3.determinant()) {
        correctas++; //Cada contestacion correcta es sumada a esta variable. 
    } else {
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
        cout << "Incorrecto. La respuesta correcta es: " << mat2x2_3.determinant() << "\n\n";
    }

    //Ejercicio #3
    cout << "Ejercicio 3: Matriz 3x3\n";
    cout << "Ejercicio 3: Calcula el determinante de la matriz 3x3:\n";

    //Indica valor de la matriz 3x3.
    mat3x3_2 << 1, 2, 3, 0, -1, 4, 2, 3, -2;
    //Mostrar matriz al usuario.
    cout << mat3x3_2 << "\n";
    cout << "Ingresa el determinante: ";
    
    //Entrada de respuesta del usuario.
    cin >> respuesta;
    cout << endl;

    //Verificar respuesta
    if (respuesta == mat3x3_2.determinant()) {
        correctas++; //Cada contestacion correcta es sumada a esta variable. 
    } else {
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
        cout << "Incorrecto. La respuesta correcta es: " << mat3x3_2.determinant() << "\n\n";
    }

    //Ejercicio #4
    cout << "Ejercicio 4: Matriz 3x3\n";
    cout << "Ejercicio 4: Calcula el determinante de la matriz 3x3:\n";
    
    //Indica valor de la matriz 3x3.
    mat3x3_3 << 5, 1, 0, 3, -2, 4, -1, 2, 1;
    //Mostrar matriz al usuario.
    cout << mat3x3_3 << "\n";
    cout << "Ingresa el determinante: ";

    //Entrada de respuesta del usuario.
    cin >> respuesta;
    cout << endl;

    //Verificar respuesta
    if (respuesta == mat3x3_3.determinant()) {
        correctas++; //Cada contestacion correcta es sumada a esta variable. 
    } else {
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
        cout << "Incorrecto. La respuesta correcta es: " << mat3x3_3.determinant() << "\n\n";
    }

    //Ejercicio #5
    cout << "Ejercicio 5: Matriz 3x3\n";
    cout << "Ejercicio 5: Calcula el determinante de la matriz 3x3:\n";
    
    //Indica valor de la matriz 3x3.
    mat3x3_4 << 3, 4, 1, 2, -1, 0, 5, 2, -3;
    //Mostrar matriz al usuario.
    cout << mat3x3_4 << "\n";
    cout << "Ingresa el determinante: ";

    //Entrada de respuesta del usuario.
    cin >> respuesta;
    cout << endl;

    //Verificar respuesta
    if (respuesta == mat3x3_4.determinant()) {
        correctas++; //Cada contestacion correcta es sumada a esta variable. 
    } else {
        incorrectas++; //Cada contestacion incorrecta es sumada a esta variable.
        cout << "Incorrecto. La respuesta correcta es: " << mat3x3_4.determinant() << "\n\n";
    }

    //Resultado final
    cout << "\nResultados:\n";
    cout << "Respuestas correctas: " << correctas << "\n";
    cout << "Respuestas incorrectas: " << incorrectas << "\n";

    //Explicación del resultado
    if (correctas >= 4) {
        cout << "¡Buen trabajo! Has entendido bien el cálculo de determinantes.\n";
    } else {
        cout << "Sigue practicando los pasos para calcular determinantes. Revisa los ejemplos y formulas.\n";
    }
      }
    break;
 
    //En caso de que el usuario ponga 0 u otro numero mayor de 5 sera marcado como invalido.
    default:
    cout << "Input invalido";
    break;
    }
   
   //Pregunta si desea continuar con otro tema.
    cout << "\n¿Te gustaria aprender sobre otra seccion? (s/n): ";
    cin >> continuar;

    } while (continuar == 's' || continuar == 'S'); //Mientras el usuario quiera continuar.

    //Mensaje de despedida
    cout << "Gracias por aprender con nosotros. Hasta la proxima!\n";

 return 0;
}
