#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

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

int numEstArchivo(string archivo)
{
    int number_of_lines = 0;
    string line;
    ifstream myfile(archivo.c_str());

    while (getline(myfile, line))
        ++number_of_lines;

    myfile.close();
    return number_of_lines;
}

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

void calcularTotal(estudiante est[10], int numEst)
{
    // calcular total de notas
    for (int i = 0; i < numEst; i++)
        est[i].total = est[i].parcial1 + est[i].parcial2 + est[i].parcial3;
}

void genObservacion(estudiante est[10], int numEst)
{
    for (int i = 0; i < numEst; i++)
        if (est[i].total >= 24)
            est[i].observacion = "EXONERADO";
        else
            est[i].observacion = "PRINCIPAL";
}

void cargarEstudiantes(estudiante loadEst[10])
{

    int numEst = numEstArchivo("datos.txt");
    ifstream fileRead;

    cout << "ESTUDIANTES NRO: " << numEst << endl;

    fileRead.open("datos.txt");
    // fileRead >> numEst;

    // redimensionar vector
    loadEst[numEst];

    for (int i = 0; i < numEst; i++)
    {
        fileRead >> loadEst[i].parcial1 >> loadEst[i].parcial2 >>
            loadEst[i].parcial3 >> loadEst[i].total >> loadEst[i].observacion;
    }
    fileRead.close();

    // return 0;
}

void guardaEstudiantes(estudiante est[10], int numEst)
{

    std::vector<std::string> all_the_lines;
    ifstream myfile("datos.txt");
    string line;
    int numEstArch = numEstArchivo("datos.txt");

    while (getline(myfile, line))
        all_the_lines.push_back(line + "\n");

    myfile.close();

    ofstream fileWrite("datos.txt");

    for (int i = 0; i < numEstArch; i++)
        fileWrite << all_the_lines[i];

    for (int i = 0; i < numEst; i++)
    {
        fileWrite << est[i].parcial1 << "\t" << est[i].parcial2 << "\t"
                  << est[i].parcial3 << "\t" << est[i].total << "\t" << est[i].observacion << endl;
    }
    fileWrite.close();
}

void mostrarEstudiantes(estudiante loadEst[10], int numEst)
{
    std::vector<std::string> all_the_lines;
    ifstream myfile("datos.txt");
    string line;
    int numEstArch = numEstArchivo("datos.txt");

    while (getline(myfile, line))
    {
        all_the_lines.push_back(line + "\n");
        cout << line << endl;
    }

    myfile.close();
}

void mostrarExonerados(estudiante loadEst[10], bool exonerado)
{
    int n = numEstArchivo("datos.txt");

    cout << "TABLA DE EXONERADOS" << endl;
    cout << "P1      P2      P3       TOTAL      OBS" << endl;
    for (int i = 0; i < n; i++)
    {
        if (exonerado && loadEst[i].observacion == "EXONERADO")
            cout << loadEst[i].parcial1 << "\t" << loadEst[i].parcial2 << "\t"
                 << loadEst[i].parcial3 << "\t" << loadEst[i].total << "\t" << loadEst[i].observacion << endl;
    }
}

int main()
{

    estudiante est[10], loadEst[10];
    ;
    int numEst = 0, opcion;

    do
    {
        do
        {
            cout << "===========MENU DE ESTUDIANTES============" << endl;
            cout << "1. INGRESAR NOTAS ESTUDIANTES" << endl;
            cout << "2. MOSTRAR TODOS LOS ESTUDIANTES DEL ARCHIVO" << endl;
            cout << "3. MOSTRAR ESTUDIANTES EXONERADOS" << endl;
            cout << "4. LIMPIAR ARCHIVO" << endl;
            cout << "5. SALIR" << endl;
            cout << "ELIGE UNA OPCION (1-5): ";
            cin >> opcion;
        } while (opcion > 5 || opcion < 1);

        if (opcion == 1)
        {
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
            // calcular total
            calcularTotal(est, numEst);
            // generar observacion
            genObservacion(est, numEst);
            // guardar en archivo
            guardaEstudiantes(est, numEst);
            // cargar estudiantes del archivo
        }

        if (opcion == 2)
        {
            cargarEstudiantes(loadEst);
            // mostrar estudiantes
            mostrarEstudiantes(loadEst, numEst);
        }

        if (opcion == 3)
        {
            cargarEstudiantes(loadEst);
            // mostrar  estudiantes aprobados
            mostrarExonerados(loadEst, true);
        }

        if (opcion == 4)
        {
            // limpiar archivo
            ofstream myfile("datos.txt");
            myfile << "";
            myfile.close();
            cout << "Archivo limpiado con exito" << endl;
        }

    } while (opcion != 5);
    cout << "Programa finalizado!";
    return 0;
}
