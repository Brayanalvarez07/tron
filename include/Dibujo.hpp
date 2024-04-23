#include <ftxui/dom/elements.hpp>
#include <fstream>
#include <string>

using namespace std;
using namespace ftxui;
class Dibujo
{
private:
    fstream archivo;
    Element contenido;

public:
    Dibujo(string path)
    {
        archivo.open(path);

        string linea;
        Elements elementos;
        while (getline(archivo, linea))
        {
            elementos.emplace_back(text(linea));
        }
        contenido = vbox(elementos);
        archivo.close();
    }
    Element GetElement(){
        return this->contenido;
    }
    ~Dibujo() {}
};