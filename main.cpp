    // ========================================
// File: main.cpp
// Author: Sebastian Colin
// Date: 13/09/23
// Description: This file manages the whole project.
// ========================================

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <algorithm>


#include "imagen.h"
#include "list.h"

using namespace std;

void menu() {

    cout << "\n1. Agregar imagenes de archivo de lectura\n";
    cout << "2. Ordenar imagenes por fecha\n";
    cout << "3. Buscar imagen con base en ID\n";
    cout << "4. Imprimir lista de imagenes y generar archivo de salida\n";
    cout << "5. Salir\n";
    cout << "NO ELEGIR OPCION 4 HASTA ORDENAR LAS IMAGENES\n";

}

int main(int argc, char* argv[]) {
    
    ifstream inputFile;
    ofstream outputFile;

    if (argc != 3) {
    cout << "usage: " << argv[0] << " input_file output_file\n";
    return -1;
    }

    inputFile.open(argv[1]);
        if (!inputFile.is_open()) {
            cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
        return -1;
    }

    outputFile.open(argv[2]);

    

    // Vectores auxiliar para recorrido
    vector<Image> coleccionGral; 

    //Lista de almacenamiento 
    List<Image> col;

    // Contador de ID imágenes
    int idImages = 0;

    // Aux case variables
    int IM = 0; int event = 0;

    // Aux object creation variables
    float size = 0.0; 
    string date; string ext; string name;

    // Menu nav var
    int menuOpt = 0;



    while(menuOpt < 5 && menuOpt > -1) {

        menu();
        cin >> menuOpt;

        switch(menuOpt) {

            case 1:
            {
                inputFile >> IM;

                for (int i = 0; i <= IM; i++) {

                    inputFile >> event;

                    switch(event) {

                        case 1:

                            inputFile >> size >> date >> ext >> name;
                            coleccionGral.push_back(Image(idImages, size, date, ext, name));
                            idImages++;
                            break;

                        default:
                            break;
                        }

                }

                outputFile << "BEFORE SORTING\n";
                for (auto& image : coleccionGral) {
                    col.insert(image);
                    outputFile << image.toString();
                }
            }    
            break;

            case 2:
            {
                //cout << "BEFORE SORTING\n";
                //cout << col.toString() << "\n";
                col.sort();
                //cout << "\nAFTER SORTING" << "\n";
                outputFile << "\nAFTER SORTING" << "\n";
                //cout << col.toString();
                outputFile << col.toString();
            }    
                break;

            case 3: 
            {
                int id_im = 0;
                cout << "Que ID de imagen quieres buscar? (de 0 a 19)\n";
                cin >> id_im;

                if (id_im < 20 && id_im > -1) {
                    col.search(coleccionGral[id_im]);
                    break;
                } else {
                    cout << "ID no valido";
                    break;
                }
            }
            break;

            case 4:
                cout << col.toString() << "\n";
                break;

            case 5:
                break;  


        }
    
    }

    inputFile.close();
    outputFile.close();
    return 0;

}