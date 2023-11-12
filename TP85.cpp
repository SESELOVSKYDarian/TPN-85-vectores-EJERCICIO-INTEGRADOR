#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> GetSeniales(int n);
string ALetras(vector<int> V);
int EsNorte(string f);
int EsOeste(string f);
int EsSur(string f);
int EsEste(string f);
int CiclosCompletos(int n, int o, int s, int e);
float PorcentajeRecorridoCuadrante(int c, int r);
void MostrarVector(vector<int> A);

int main()
{
    vector<int> A;
    string cuadrantes;
    srand(time(NULL));
    int r = 14, n = 0, o = 0, s = 0, e = 0, cant;
    A = GetSeniales(r);
    MostrarVector(A);
    cuadrantes = ALetras(A);
    cout << cuadrantes << endl;
    n = EsNorte(cuadrantes);
    cout << n << endl;
    o = EsOeste(cuadrantes);
    cout << o << endl;
    s = EsSur(cuadrantes);
    cout << s << endl;
    e = EsEste(cuadrantes);
    cout << e << endl;
    cant = CiclosCompletos(n, o, s, e);
    cout << "Cantidad de ciclos completos: " << cant << endl;
    cout << "Porcentaje que es recorrido cuadrante norte: %" << PorcentajeRecorridoCuadrante(n, r) << endl;
    cout << "Porcentaje que es recorrido cuadrante oeste: %" << PorcentajeRecorridoCuadrante(o, r) << endl;
    cout << "Porcentaje que es recorrido cuadrante sur: %" << PorcentajeRecorridoCuadrante(s, r) << endl;
    cout << "Porcentaje que es recorrido cuadrante este: %" << PorcentajeRecorridoCuadrante(e, r) << endl;
    return 0;
}

vector<int> GetSeniales(int n)
{
    vector<int> V;
    int e;
    for (int i = 0; i < n; i++)
    {
        e = rand() % 361;
        V.push_back(e);
    }
    return V;
}

string ALetras(vector<int> V)
{
    string f;
    for (int i = 0; i < V.size(); i++)
    {
        if (V[i] >= 45 && V[i] < 135)
        {
            f += "/N";
        }
        if (V[i] >= 135 && V[i] < 225)
        {
            f += "/O";
        }
        if (V[i] >= 225 && V[i] < 315)
        {
            f += "/S";
        }
        if (V[i] >= 315 && V[i] < 360 || V[i] >= 0 && V[i] < 45)
        {
            f += "/E";
        }
    }
    return f;
}

int EsNorte(string f)
{
    int n = 0;
    for (int i = 0; i < f.size(); i++)
    {
        if (f[i] == 'N')
        {
            n++;
        }
    }
    return n;
}

int EsOeste(string f)
{
    int o = 0;
    for (int i = 0; i < f.size(); i++)
    {
        if (f[i] == 'O')
        {
            o++;
        }
    }
    return o;
}

int EsSur(string f)
{
    int s = 0;
    for (int i = 0; i < f.size(); i++)
    {
        if (f[i] == 'S')
        {
            s++;
        }
    }
    return s;
}

int EsEste(string f)
{
    int e = 0;
    for (int i = 0; i < f.size(); i++)
    {
        if (f[i] == 'E')
        {
            e++;
        }
    }
    return e;
}

int CiclosCompletos(int n, int o, int s, int e)
{
    int cant = 0;
    while (n > cant && o > cant && s > cant && e > cant)
    {
        cant++;
    }
    return cant;
}

float PorcentajeRecorridoCuadrante(int c, int r)
{
    float porcentaje;
    porcentaje = 100.0 * (c / (1.0 * r));
    return porcentaje;
}

void MostrarVector(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << "/";
    }
    cout << endl;
}
