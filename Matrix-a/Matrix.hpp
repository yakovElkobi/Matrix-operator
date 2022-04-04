/**
 * Matrix.hpp file for the exercise operators
 *
 * @author yakov elkobi
 * @since 2022-03
 * 
 */
#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

namespace zich{
    class Matrix{
    private:
        /* The number of row in matrix */
        int _row;
        /* The number of columns in matrix */
        int _col;
        /* The size of matrix */
        int _size;
        /* The data in the matrix */
        std::vector<double> _data;

        /**
         ********************************
         *           setters            *
         ********************************
         */
        void setRow(int row){this->_row = row;}
        void setCol(int col){this->_col = col;}
        void setData(std::vector<double> data){this->_data = data;}
        void setSize(int row, int col){this->_size = row*col;}
        void setMatrix(std::vector<double> data, int row, int col);


        double multiplication(const Matrix& other, const int row, const int col);
        void isCorrect(const int row, const int col, const int size)const;
        void isCorrect(const int row, const int col)const;
        double sumMatrix()const;
        
    public:

        /**
         ********************************
         *         constructor          *
         ********************************
         */

        Matrix() = default;
        ~Matrix() = default;
        Matrix(const std::vector<double> data, const int row, const int col);
        Matrix(const int row, const int col);

        /**
         ********************************
         *           getters            *
         ********************************
         */
        int getRow()const{return this->_row;}
        int getCol()const{return this->_col;}
        std::vector<double> getData()const{return this->_data;}
        int getSize()const{return this->_row*this->_col;}

        /**
         ********************************
         *           operators           *
         ********************************
         */

        Matrix operator+(const Matrix& other)const;
        // prefix increment
        Matrix& operator++();
        // postfix increment
        Matrix operator++(const int num);
        Matrix& operator+=(const Matrix& other);

        Matrix operator-(const Matrix& other)const;
        Matrix& operator--();
        Matrix operator--(const int num);
        Matrix& operator-=(const Matrix& other);

        Matrix operator*(const double scalar)const;
        Matrix operator*(const Matrix& other);
        Matrix& operator*=(const double scalar);
        Matrix& operator*=(const Matrix& other);
        
        bool operator>(const Matrix& other);
        bool operator>=(const Matrix& other);
        bool operator<(const Matrix& other);
        bool operator<=(const Matrix& other);
        bool operator==(const Matrix& other);
        bool operator!=(const Matrix& other);

        /**
         **********************************
         * friend global binary operators *
         **********************************
         */

        friend Matrix operator*(const double scalar, Matrix &data);
        friend Matrix operator-(Matrix &data);

        /**
         ******************************
         * friend global IO operators *
         ******************************
         */


        friend std::ostream& operator<<(std::ostream& out, const Matrix& mat);
       //friend std::istream& operator>>(std::istream& in, Matrix& mat);
    };
}