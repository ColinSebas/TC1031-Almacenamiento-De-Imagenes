/* 
 * ==========================
 * File: imagen.h
 * Author: Sebastián Colín 
 * Date: 09/11/2023
 * Description: This file defines the class, image
 * which stores different image traits
 * ==========================
*/

#include <vector> 
#include <cstring>
#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>

//using namespace std;

#ifndef IMAGEN_H_
#define IMAGEN_H_

class Image {

    private: 

        float size;
        std::string date;  //ddmmyyyy
        std::string extension; 
        int day, month, year;
        int id;

    public:

        std::string name;

        // Default Class Constructor 
        Image() : size(0.0), date(""), extension(""), day(0), month(0), year(0), id(0) {}


        Image(int i, float sz, std::string dt, std::string ext, std::string nm) {

                std::stringstream ss;
                id = i;
                size = sz;
                date = dt;
                const char* str = date.c_str();
                extension = ext;    
                name = nm;
                date_to_int();

        }; 
        

        // Copy constructor 
        Image(const Image&);
        int get_day() {return day;}; int get_month() {return month;}; int get_year() {return year;};

        // To String Function
        std::string toString() const;

        // Date to int function
        void date_to_int();

        // Sobre carga de operadores
        bool operator<(const Image*);
        bool operator<(const Image&);
        bool operator>(const Image*);
        bool operator>(const Image&);
        bool operator==(const Image*);
        bool operator==(const Image&);


        
};

void Image::date_to_int() {

    std::stringstream ssdt;

    const char* str = date.c_str();

    ssdt << str[0] << str[1];
    day = stoi(ssdt.str());
    ssdt.clear();
    ssdt.str("");
    ssdt << str[2] << str[3];
    month = stoi(ssdt.str());
    ssdt.clear();
    ssdt.str("");
    ssdt << str[4] << str[5] << str[6] << str[7];
    year = stoi(ssdt.str());
    ssdt.clear();
    ssdt.str("");   

}

Image::Image(const Image &other) {
    id = other.id;
    size = other.size;
    date = other.date;
    extension = other.extension;
    name = other.name;
    year = other.year;
    month = other.month;
    day = other.day;
}

bool Image::operator<(const Image* other) {

    if  (this->year < other->year) {
        return true;
    } 
    if (this->year == other->year) {
        if (this->month < other->month) {
            return true;
        } else if (this->month == other->month) {
            if (this->day < other->day) {
                return true;
            }
        }
    }
    return false;

}

bool Image::operator<(const Image& other) {

    if  (this->year < other.year) {
        return true;
    } 
    if (this->year == other.year) {
        if (this->month < other.month) {
            return true;
        } else if (this->month == other.month) {
            if (this->day < other.day) {
                return true;
            }
        }
    }
    return false;

}

bool Image::operator>(const Image* other) {

    if  (this->year > other->year) {
        return true;
    } 
    if (this->year == other->year) {
        if (this->month > other->month) {
            return true;
        } else if (this->month == other->month) {
            if (this->day > other->day) {
                return true;
            }
        }
    }
    return false;

}

bool Image::operator>(const Image& other) {

    if  (this->year > other.year) {
        return true;
    } 
    if (this->year == other.year) {
        if (this->month > other.month) {
            return true;
        } else if (this->month == other.month) {
            if (this->day > other.day) {
                return true;
            }
        }
    }
    return false;

}

bool Image::operator==(const Image *other) {
    if (this->year == other->year) {
        if (this->month == other->month) {
            if (this->day == other->day) {
                return true;
            }
        }
    }
    return false;
}

bool Image::operator==(const Image &other) {
    if (this->year == other.year) {
        if (this->month == other.month) {
            if (this->day == other.day) {
                return true;
            }
        }
    }
    return false;
}



std::string Image::toString() const {

    std::stringstream data;

    data << "\n" << "Imagen: " << id;
    data << "\n";
    data << "\tTomada por " << name << " el " << day << " del " << month << " de " << year;
    data << "\n";
    data << "\t" << extension << " " << size <<  " Mb";
    data << "\n";

    return data.str();

}


#endif 
