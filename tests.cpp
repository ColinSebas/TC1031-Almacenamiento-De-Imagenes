// ========================================
// File: main.cpp
// Author: Sebastian Colin
// Date: 13/09/23
// Description: This file tests different functions from the list.h file
// ========================================

#include <iostream>
#include <string>
#include <sstream>


#include "imagen.h"
#include "list.h"

using namespace std;


int main(int argc, char* argv[]) {

    List<Image> tests_1;

    std::stringstream ans; 
    std::string f_ans;

    tests_1.insert(Image(1,25.3,"28042017","RAW","Sebastian"));
    tests_1.insert(Image(2,21.6,"29122009","jpg","Luis"));
    tests_1.insert(Image(3,10.4,"05072007","jpeg","Gabriela"));
    tests_1.insert(Image(4,14.9,"16042016","png","Andrea"));

    ans << "\nImagen: 4" << "\n\t" << "Tomada por Andrea el 16 del 4 de 2016" << 
        "\n\t" << "png 14.9 Mb" << "\n";
    ans << "\nImagen: 3" << "\n\t" << "Tomada por Gabriela el 5 del 7 de 2007" << 
        "\n\t" << "jpeg 10.4 Mb" << "\n";
    ans << "\nImagen: 2" << "\n\t" << "Tomada por Luis el 29 del 12 de 2009" << 
        "\n\t" << "jpg 21.6 Mb" << "\n";
    ans << "\nImagen: 1" << "\n\t" << "Tomada por Sebastian el 28 del 4 de 2017" << 
        "\n\t" << "RAW 25.3 Mb" << "\n";

    f_ans = ans.str();

    cout << tests_1.toString();
    cout << "Test 1: " << ((!f_ans.compare(tests_1.toString().c_str())) ? "Success!\n":"Fail!\n");

    ans.str("");
    tests_1.sort();

    ans << "\nImagen: 3" << "\n\t" << "Tomada por Gabriela el 5 del 7 de 2007" << 
        "\n\t" << "jpeg 10.4 Mb" << "\n";
    ans << "\nImagen: 2" << "\n\t" << "Tomada por Luis el 29 del 12 de 2009" << 
        "\n\t" << "jpg 21.6 Mb" << "\n";
    ans << "\nImagen: 4" << "\n\t" << "Tomada por Andrea el 16 del 4 de 2016" << 
        "\n\t" << "png 14.9 Mb" << "\n";
    ans << "\nImagen: 1" << "\n\t" << "Tomada por Sebastian el 28 del 4 de 2017" << 
        "\n\t" << "RAW 25.3 Mb" << "\n";
    
    f_ans = ans.str();

    cout << tests_1.toString();
    cout << "Test 2: " << ((!f_ans.compare(tests_1.toString().c_str())) ? "Success!\n":"Fail!\n");

    ans.str("");

    Image traca(5,18.5,"21072004","jpg","Benji");
    Image perron(6, 23.9,"08122018","RAW","Andrea");
    Image ecuaciones(7, 21.7,"12022022","jpeg","Paul");

    tests_1.insert(traca); tests_1.insert(perron); tests_1.insert(ecuaciones);
    
    ans << "\nImagen: 6" << "\n\t" << "Tomada por Andrea el 8 del 12 de 2018" << 
        "\n\t" << "RAW 23.9 Mb" << "\n";
    f_ans = ans.str();

    cout << tests_1.search(traca) << "\n";
    //cout << f_ans;

    if (tests_1.search(perron) == 1) {
        cout << "Test 3: Success!\n";
    } else {
        cout << "Test 3: Fail!\n";
    }

    tests_1.clear();

    return 0;

}