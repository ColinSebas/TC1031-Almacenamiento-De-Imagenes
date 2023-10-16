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

    cout << "1. Quiero guardar los datos de una imagen.";
    cout << "2. Quiero crear una colección de imágenes.";

}

int main(int argc, char* argv[]) {
    
    ifstream inputFile;
    ofstream outputFile;

    if (argc != 2) {
    cout << "usage: " << argv[0] << " input_file output_file\n";
    return -1;
    }

    inputFile.open(argv[1]);
        if (!inputFile.is_open()) {
            cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
        return -1;
    }

    //outputFile.open(argv[2]);

    // Vectores de Almacenamiento
    vector<Image> coleccionGral;
    List<int> years;

    // Contador de ID imágenes
    int idImages = 0;

    // Aux case variables
    int IM = 0; int event = 0;

    // Aux object creation variables
    float size = 0.0; 
    string date; string ext; string name;


    inputFile >> IM;

    for (int i = 0; i <= IM; i++) {

        inputFile >> event;

        switch(event) {

            case 1:

                inputFile >> size >> date >> ext >> name;
                coleccionGral.push_back(Image(idImages, size, date, ext, name));
                if (years.searchBool(coleccionGral[idImages].get_year()) == false) {
                    years.insertion(coleccionGral[idImages].get_year());
                }
                idImages++;
                break;

            default:
                break;
            }

    }

    
    for (auto& image : coleccionGral) {
        cout << image.toString();
    }

    std::sort(coleccionGral.begin(), coleccionGral.end());

    cout << "PAUSA" << "\n";

    for (auto& image : coleccionGral) {
        cout << image.toString();
    }

    cout << "\n" << "Years list:" << years.toString();

    inputFile.close();
    //outputFile.close();
    return 0;

}