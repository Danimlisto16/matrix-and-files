#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// estructuras
struct estudiante
{
    float parcial1;
    float parcial2;
    float parcial3;
    float total;
    string observacion;
};

float valParcial(float parcialNum)
{

    float parcial = 0;
    do
    {
        cout << "\nIngresa la nota del parcial " << parcialNum << ": ";
        cin >> parcial;
        if (parcial < 0 || parcial > 10)
            cout << "*** Ingresa un valor entre 0 y 10***" << endl;
    } while (parcial < 0 || parcial > 10);
    return parcial;
}

int main()
{

    estudiante est[10];
    int numEst = 0;

    // ingresar numero de estudiantes
    do
    {
        cout << "\nIngresa el numero de estudiantes: ";
        cin >> numEst;
        if (numEst < 0 || numEst > 5)
            cout << "**** el valor debe ser entre 0 y 5" << endl;
    } while (numEst < 0 || numEst > 5);

    // redimensionar vector con estructura de estudiantes
    est[numEst];

    // ingresar notas de estudiantes
    for (int i = 0; i < numEst; i++)
    {
        cout << "==== Ingreso de notas del estudiante " << i + 1 << "=====" << endl;
        est[i].parcial1 = valParcial(1);
        est[i].parcial2 = valParcial(2);
        est[i].parcial3 = valParcial(3);
    }

    // calcular total de notas
    for (int i = 0; i < numEst; i++)
        est[i].total = est[i].parcial1 + est[i].parcial2 + est[i].parcial3;

    // generar observacion
    for (int i = 0; i < numEst; i++)
        if (est[i].total >= 24)
            est[i].observacion = "EXONERADO";
        else
            est[i].observacion = "PRINCIPAL";

    // guardar en archivo
    ofstream fileWrite("datos.txt");
    for (int i = 0; i < numEst; i++)
    {
        fileWrite << est[i].parcial1 << "\t" << est[i].parcial2 << "\t"
                  << est[i].parcial3 << "\t" << est[i].total << "\t" << est[i].observacion << endl;
    }
    fileWrite.close();

    // cargar estudiantes del archivo
    ifstream fileRead;

    fileRead.open("datos.txt");
    estudiante loadEst[numEst];
    for (int i = 0; i < numEst; i++)
    {
        fileRead >> loadEst[i].parcial1 >> loadEst[i].parcial2 >>
            loadEst[i].parcial3 >> loadEst[i].total >> loadEst[i].observacion;
    }
    fileWrite.close();

    // mostrar estudiantes
    cout << "TABLA CON TODOS LOS ESTUDIANTES" << endl;
    cout << "P1   P2   P3    TOTAL   OBS" << endl;
    for (int i = 0; i < numEst; i++)
    {
        cout << loadEst[i].parcial1 << "\t" << loadEst[i].parcial2 << "\t"
             << loadEst[i].parcial3 << "\t" << loadEst[i].total << "\t" << loadEst[i].observacion << endl;
    }

    // mostrar  estudiantes aprobados
    cout << "ESTUDIANTES EXONERADOS" << endl;
    cout << "P1   P2   P3    TOTAL   OBS" << endl;
    for (int i = 0; i < numEst; i++)
    {
        if (loadEst[i].total >= 24)
        {
            cout << loadEst[i].parcial1 << "\t" << loadEst[i].parcial2 << "\t"
                 << loadEst[i].parcial3 << "\t" << loadEst[i].total << "\t" << loadEst[i].observacion << endl;
        }
    }

    return 0;
}
