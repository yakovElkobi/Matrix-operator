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
#include <string>

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

        double multiplication(const Matrix& other, const size_t i, const size_t j)const;
        void isCorrect(const int row, const int col)const;
        double sumMatrix()const;
        
    public:
        
        /**
         ********************************
         *         constructor          *
         ********************************
         */
        Matrix() = default;
        Matrix(const std::vector<double> &data, const int row, const int col);
        ~Matrix();

        /**
         ********************************
         *           geeters            *
         ********************************
         */

        int getRow()const{return this->_row;}
        int getCol()const{return this->_col;}
        int getSize()const{return this->_size;}
        std::vector<double> getData()const{return this->_data;}

        
         /**
         ********************************
         *     addition operators       *
         ********************************
         */


        // Matrix addition
        Matrix operator+(const Matrix &other)const;
        // prefix increment
        Matrix& operator++();
        // postfix increment
        Matrix operator++(const int num);
        //add a number to the matrix
        Matrix& operator+=(const Matrix &other);

         /**
         ********************************
         *     subtraction operators    *
         ********************************
         */

        // Matrix subtraction
        Matrix operator-(const Matrix &other)const;
        // prefix decrement
        Matrix& operator--();
        // postfix decrement
        Matrix operator--(const int num);
        // sub  a number to the matrix
        Matrix& operator-=(const Matrix &other);

        /**
         ********************************
         *   multiplication operators   *
         ********************************
         */

        // Matrix multiplication
        Matrix operator*(const Matrix &other)const;
        // scalar multiplication
        Matrix operator*(const double scalar)const;
        Matrix& operator*=(const double scalar);
        Matrix& operator*=(const Matrix &other);
        
        /**
         ********************************
         *      comparson operators     *
         ********************************
         */

        bool operator>(const Matrix &other)const;
        bool operator>=(const Matrix &other)const;
        bool operator<(const Matrix &other)const;
        bool operator<=(const Matrix &other)const;
        //bool operator==(const Matrix &other);
        bool operator!=(const Matrix &other)const;

        /**
         **********************************
         *     friend global operators    *
         **********************************
         */

        friend Matrix operator*(const double scalar, Matrix &data);
        friend Matrix operator+(Matrix &data);
        friend Matrix operator-(Matrix &data);
        friend bool operator==(const Matrix& a, const Matrix& b);

        /**
         ******************************
         * friend global IO operators *
         ******************************
         */

        friend std::ostream& operator<<(std::ostream& out, const Matrix& mat);
        friend std::istream& operator>>(std::istream& input, Matrix& mat);
    };
}