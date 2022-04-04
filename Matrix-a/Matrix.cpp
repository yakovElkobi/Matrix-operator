/**
 * Matrix.cpp file for the exercise operators
 *
 * @author yakov elkobi
 * @since 2022-03
 * 
 */
#include "Matrix.hpp"

using namespace std;

namespace zich{
    void Matrix::isCorrect(const int row, const int col, const int size)const{
        if(row <= 0 || col <= 0){
            throw runtime_error("row and col most be postive:");
        }
        
        if(size != row*col){
            throw runtime_error("The size not fit:");
        }
    }
    void Matrix::isCorrect(const int row, const int col)const{
        if(this->getRow() != row || this->getCol() != col){
            throw runtime_error("The row and col most fit:");
        }
    }
    Matrix::Matrix(const int row, const int col){
        setRow(row);
        setCol(col);
        setSize(row,col);
        this->_data.resize((size_t)(row*col));
    }

    Matrix::Matrix(const vector<double> data, const int row, const int col){
        this->setMatrix(data, row, col);
    }
    void Matrix::setMatrix(const vector<double> data,int row, const int col){
        isCorrect(row, col, data.size());
        this->setData(data);
        this->setRow(row);
        this->setCol(col);
        this->setSize(row, col);
    }
    Matrix Matrix::operator+(const Matrix& other)const{
        isCorrect(other.getRow(), other.getCol());
        return Matrix();
    }
    Matrix& Matrix::operator++(){
        return *this;
    }
    Matrix Matrix::operator++(const int num){
        return Matrix();
}
    Matrix& Matrix::operator+=(const Matrix& other){
        isCorrect(other.getRow(), other.getCol());
        return *this;
    }
    Matrix Matrix::operator-(const Matrix& other)const{
        isCorrect(other.getRow(), other.getCol());
        return Matrix();
    }
    Matrix& Matrix::operator--(){
        return *this;
    }
    Matrix Matrix::operator--(const int num){
        return *this;
    }
    Matrix& Matrix::operator-=(const Matrix& other){
        isCorrect(other.getRow(), other.getCol());
        return *this;
    }
    double Matrix::multiplication(const Matrix& other, const int i, const int j){
        double sum = 0;
        return sum;
    }
    Matrix Matrix::operator*(const Matrix& other){
        if(this->getCol() != other.getRow()){
            throw runtime_error("The multiplication is invalid:");
        }
        return Matrix();
    }
    Matrix Matrix::operator*(const double scalar)const{
        return Matrix();
    }
    Matrix& Matrix::operator*=(const double scalar){
        return *this;
    }
    Matrix& Matrix::operator*=(const Matrix& other){
        return *this;
    }
    double Matrix::sumMatrix()const{
        double sum = 0;
        return sum;
    }
    bool Matrix::operator>(const Matrix& other){
        return true;
    }
    bool Matrix::operator>=(const Matrix& other){
        return true;
    }
    bool Matrix::operator<(const Matrix& other){
        return true;
    }
    bool Matrix::operator<=(const Matrix& other){
        return true;
    }
    bool Matrix::operator==(const Matrix& other){
        isCorrect(other.getRow(), other.getCol());
        return true;
    }
    bool Matrix::operator!=(const Matrix& other){
        return true;
    }
    Matrix operator*(const double scalar, Matrix &data){
        return Matrix();
    }
    Matrix operator-(Matrix &data){
        return Matrix();
    }
    ostream& operator<<(ostream& out, const Matrix& mat){
        for(int i = 0; i < mat.getRow(); ++i){
            out << '[';
            for(int j = 0; j < mat.getCol(); ++j){
                    out << mat._data[(size_t) (i * mat.getCol() + j)];
                    if(j!=mat.getCol()-1){
                        out << ' ';
                    }
            }
            out << ']' <<endl;
        }
        return out;
    }
    //istream& operator>>(std::istream& in, Matrix& mat)
}



