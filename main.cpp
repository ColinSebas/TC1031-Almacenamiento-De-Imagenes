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

using namespace std;

void menu() {

    cout << "1. Quiero guardar los datos de una imagen.";
    cout << "2. Quiero crear una colección de imágenes.";

}

using namespace std;

int main() {
    
    vector<Image> coleccion;

    Image img(24.3, "29072019", "jpg", "Pepe");
    Image img2(25, "14022018", "RAW", "Luis");
    Image img3(22, "23122014", "png", "Mario");
    Image img4(20.2, "17042019", "jpg", "Pepe");


    coleccion.push_back(img); coleccion.push_back(img2); coleccion.push_back(img3); coleccion.push_back(img4);

    std::sort(coleccion.begin(), coleccion.end());

    for (auto& image : coleccion) {
        cout << image.get_year() << "\n";
    }

}