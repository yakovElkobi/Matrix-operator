#include "Matrix.hpp"
using namespace std;
namespace zich{

    void Matrix::isCorrect(const int row, const int col)const{
        if(this->_row != row || this->_col != col){
            throw runtime_error("The row and col most fit:");
        }
    }
    Matrix::Matrix(const vector<double> &data, const int row, const int col){
        if(row <= 0 || col <= 0){
            throw runtime_error("row and col most be postive:");
        }
        if(data.size() != row*col){
            throw runtime_error("The size not fit:");
        }
        this->_row = row;
        this->_col = col;
        this->_size = row*col;
        this->_data = data;
    }
    Matrix::~Matrix(){

    }
    /**
     * @brief add tow matrices.
     * 
     * @param other 
     * @return Matrix result of adding.
     */
    Matrix Matrix::operator+(const Matrix &other)const{
        isCorrect(other.getRow(), other.getCol());
        vector <double> ans;
        for(size_t i = 0; i < this->getSize(); ++i){
               ans.push_back(this->getData().at(i)+other.getData().at(i));
        }
        return Matrix(ans, _row, _col);
    }
    /**
     * @brief Define prefix incrment add +1 all matrix.
     */
    Matrix& Matrix::operator++(){
        for(size_t i = 0; i < this->getSize(); ++i){
            this->_data[i]++;
        }
        return *this;
    }
    /**
     * @brief Define postfix incrment add +1 all matrix.
     */
    Matrix Matrix::operator++(const int num){
        Matrix copy = *this;
        ++*this;
        return copy;
    }
    Matrix& Matrix::operator+=(const Matrix &other){
        *this = *this+other;
        return *this;
    }
    /**
     * @brief sub tow matrices.
     * 
     * @return Matrix result of sub.
     */
    Matrix Matrix::operator-(const Matrix& other)const{
        isCorrect(other.getRow(), other.getCol());
        vector <double> ans;
        for(size_t i = 0; i < _size; ++i){
            ans.push_back(this->getData().at(i)-other.getData().at(i));
        }
        return Matrix(ans, _row, _col);
    }
    /**
     * @brief Define prefix decrment, sub -1 all matrix.
     */
    Matrix& Matrix::operator--(){
        for(size_t i = 0; i < this->getSize(); ++i){
            this->_data[i]--;
        }
        return *this;
    }
    /**
     * @brief Define postfix decrment, sub -1 all matrix.
     */
    Matrix Matrix::operator--(const int num){
        Matrix copy = *this;
        --*this;
        return copy;
    }
    Matrix& Matrix::operator-=(const Matrix& other){
        isCorrect(other.getRow(), other.getCol());
        *this = *this-other;
        return *this;
    }
    double Matrix::multiplication(const Matrix& other, const size_t i, const size_t j)const{
        double sum = 0;

        for(size_t k = 0; k < this->_col; ++k){
            sum += this->getData().at(i*(size_t)(this->getCol())+k) * other.getData().at(k*(size_t)other.getCol()+j);
        }
        return sum;
    }
    /**
     * @brief define matrix multiplication.
     * 
     * @return Matrix result of multiplication tow matrics.
     */
    Matrix Matrix::operator*(const Matrix& other)const{
        if(this->getCol() != other.getRow()){
            throw runtime_error("The multiplication is invalid:");
        }
        vector <double> ans;
        for(size_t i = 0; i < this->getRow(); ++i){
            for(size_t j = 0; j < other.getCol(); ++j){
                ans.push_back(multiplication(other, i , j));
            }
        }
        return Matrix(ans, _row, other._col);
    }
    Matrix& Matrix::operator*=(const Matrix& other){
        *this = (*this*other);
        return *this;
    }
    /**
     * @brief mult all matrix in scalar.
     *
     * @return Matrix result of mult in scalar.
     */
    Matrix Matrix::operator*(const double scalar)const{
        Matrix copy = *this;
        for(size_t i = 0; i < this->getSize(); ++i){
            copy._data[i] *= scalar;
        }
        return copy;
    }
    Matrix& Matrix::operator*=(const double scalar){
        *this = (*this*scalar);
        return *this;
    }
    double Matrix::sumMatrix()const{
        double sum = 0;
        for (size_t i = 0; i < this->_size; i++){
            sum += this->getData().at(i);
        }
        return sum;
    }
    /**
     * @brief comparson tow matrics.
     * 
     * @return true if the sum of matrix big from other
     * @return false if the sum of other matrix bigger
     */
    bool Matrix::operator>(const Matrix& other)const{
        isCorrect(other.getRow(), other.getCol());
        return this->sumMatrix() > other.sumMatrix();
    }
    /**
     * @brief comparson tow matrics.
     * 
     * @return true if the sum of matrix big/equal from other.
     * @return false if the sum of other matrix bigger.
     */
    bool Matrix::operator>=(const Matrix& other)const{
        return *this > other || *this == other;
    }
    /**
     * @brief comparson tow matrics.
     * 
     * @return true if the sum of other matrix bigger.
     * @return false if the sum of other matrix smaller.
     */
    bool Matrix::operator<(const Matrix& other)const{
        isCorrect(other.getRow(), other.getCol());
        return this->sumMatrix() < other.sumMatrix();
    }
    bool Matrix::operator<=(const Matrix &other)const{
        return *this < other || *this == other;
    }
    /**
     * @brief comparson tow matrics.
     * 
     * @return true if all element in matrix equlas.
     * @return false if one element in matrix is different.
     */
    // bool Matrix::operator==(const Matrix& other){
    //     isCorrect(other._row, other._col);
    //     for (size_t i = 0; i < this->_size; ++i){
    //         if(this->_data[i] != other._data[i]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    
    /**
     * @brief comparson tow matrics.
     * 
     * @return true if all element in matrix is different. 
     * @return false if one element in matrix equlas.
     */
    bool Matrix::operator!=(const Matrix& other)const{
        return (!(*this == other));
    }
    /**
     * @brief mult all matrix in -1.
     */
    Matrix operator-(Matrix &data){
        return data*-1;
    }
    Matrix operator+(Matrix &data){
        return data;
    }
    bool operator==(const Matrix& a, const Matrix& b){
        if(a.getRow() != b.getRow() || a.getCol() != b.getCol()){
            throw runtime_error("The row and col most fit:");
        }
        for (size_t i = 0; i < a.getSize(); ++i){
            if(a._data[i] != b._data[i]){
                return false;
            }
        }
        return true;
    }
    Matrix operator*(const double scalar, Matrix &data){
        return data*scalar;
    }
    ostream &operator<<(ostream &out, const Matrix &mat){
        for (size_t i = 0; i < mat._row; i++){
            out << '[';
            for (size_t j = 0; j < mat._col; j++){
                if (j != mat._col - 1){
                    out << mat._data[(i * (size_t)mat._col + j)] << ' ';
                }
                else{
                    out << mat._data[(i * (size_t)mat._col + j)] << ']';
                }
            }
            if (i != mat._row - 1){
                out  << endl;
            }
        }
        return out;
    }
    void checkString(string str){
        for(unsigned int i = 0; i < str.length()-1; ++i){
            if(str.at(i) == ',' && str.at(i+1) != ' '){
                throw invalid_argument("The string is worng 1:");
            }
            if(str.at(i) == ']' && str.at(i+1) != ','){
                throw invalid_argument("The string is worng 2:");
            }
            if(str.at(i) == '[' && isdigit(int(str[i])) != 0){
                throw invalid_argument("The string is worng 3:");
            }
        }
    }
    istream &operator>>(istream &input, Matrix &mat){
        string str;
        while (input.peek() != '\n'){
            str += char(input.get());
        }
        checkString(str);
        int row = 0;
        int col = 0;
        for(size_t i = 1; str[i] != ']'; ++i){
            if(str[i] == ' '){
                col++;
            }
        }
        vector <double> temp;
        for (size_t i = 0; i < str.length(); i++){
            if(isdigit(int(str[i])) != 0){
                temp.push_back(double(str[i]));
            }
            else if(str[i] == '['){
                row++;
            }
        }
        mat._data = temp;
        mat._row = row;
        mat._col = col;
        return input;
    }
}
