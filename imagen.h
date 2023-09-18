/* ==========================
 * File: imagen.h
 * Author: Sebastián Colín 
 * Date: 09/11/2023
 * Description: This file defines the class, image
 * which stores different image traits
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
        Image(float sz, std::string dt, std::string ext, std::string nm) {

                //id = this->id;
                std::stringstream ss;
                if (size < 0.0) {
                    size = 0.0;
                } else {
                    size = sz; 
                }
                date = dt;
                const char* str = date.c_str();
                extension = ext;    
                name = nm;
                
                ss << str[0] << str[1];
                day = stoi(ss.str());
                ss.clear();
                ss.str("");
                ss << str[2] << str[3];
                month = stoi(ss.str());
                ss.clear();
                ss.str("");
                ss << str[4] << str[5] << str[6] << str[7];
                year = stoi(ss.str());
                ss.clear();
                ss.str("");

        }; 
        Image(const Image&);
        int get_day() {return day;}; int get_month() {return month;}; int get_year() {return year;};

        // To String Function
        std::string toString() const;

        // Sobre carga de operadores
        bool operator<(const Image*);
        bool operator<(const Image&);
        bool operator>(const Image*);
        bool operator>(const Image&);


        
};

Image::Image(const Image &other) {
    size = other.size;
    date = other.date;
    extension = other.extension;
    name = other.name;
    year = other.year;
    month = other.month;
    day = other.day;
}

bool Image::operator< (const Image* other) {

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

bool Image::operator< (const Image& other) {

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

bool Image::operator> (const Image* other) {

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

bool Image::operator> (const Image& other) {

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

std::string Image::toString() const {

    std::stringstream data;

    //data << "Imagen: " << id;
    data << "\n";
    data << "\tTomada por " << name << " el " << day << " del " << month << " de " << year;
    data << "\n";
    data << "\t" << extension << " " << size <<  "Mb";
    data << "\n";

    return data.str();

}


#endif 
