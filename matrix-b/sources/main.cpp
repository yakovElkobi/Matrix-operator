/**
 * main.cpp file for the exercise operators
 *
 * @author yakov elkobi
 * @since 2022-03
 * 
 */
#include "Matrix.hpp"
#include <fstream>
#include <sstream>

using namespace zich;
using namespace std;

void add(){
    char choice;
   
    do{
        int row, col;
        double num;
        vector <double> a;
        vector <double> b;

        cout << "Please choose:" << endl;
        cout << "FOR ADD TWO MATRIX + PRESS 1 :"<<endl;
        cout << "FOR PREFIX INCREMENT ++ PRESS 2 :"<<endl;
        cout << "FOR POSTFIX INCREMENT ++ PRESS 3 :"<<endl;
        cout << "FOR ADD TO MATRIX += PRESS 4 :"<<endl;
        cout << "FOR EXIT PRES E :"<<endl;
        cin >> choice;
        if(choice == 'E'){
            return;
        }
        cout<< "enter row of matrix A:"<<endl;
        cin >> row;
        cout<< "enter col of matrix A:"<<endl;
        cin >> col;
        cout<< "enter number in matrix A:"<<endl;
        
        for (int i = 0; i < row*col; i++){
            cin >> num;
            a.push_back(num);
        }
        Matrix A(a, row, col);

        if(choice == '1'){
            cout<< "enter row of matrix B:"<<endl;
            cin >> row;
            cout<< "enter col of matrix B:"<<endl;
            cin >> col;
            cout<< "enter number in matrix B:"<<endl;
            for (int i = 0; i < row*col; i++){
                cin >> num;
                b.push_back(num);
            }
            Matrix B(b, row, col);
            cout << A << " = A "<< endl << endl;
            cout << B << " = B "<< endl << endl;
            try{
               cout  << A+B << " = A + B"<< endl;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
        else if(choice == '2'){
            cout << A << " = A "<< endl << endl;
            cout << ++A <<" = ++A PREFIX INCREMENT" << endl;
        }
        else if(choice == '3'){
            cout << A++ <<" = A++ POSTFIX INCREMENT" << endl << endl;
            cout << A++ <<" = A++ after" << endl;
        }
        else if(choice == '4'){
            cout<< "enter row of matrix B:"<<endl;
            cin >> row;
            cout<< "enter col of matrix B:"<<endl;
            cin >> col;
            cout<< "enter number in matrix B:"<<endl;
            for (int i = 0; i < row*col; i++){
                cin >> num;
                b.push_back(num);
            }
            Matrix B(b, row, col);
            cout << A << " = A "<< endl << endl;
            cout << B << " = B "<< endl << endl;
            try{
                A+=B;
                cout << A  << "  = A+=B "<< endl;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
    }
    while (choice != 'E');
    return;
}
void sub(){
    char choice;
    
    do{
        int row, col;
        double num;
        vector <double> a;
        vector <double> b;

        cout << "Please choose:" << endl;
        cout << "FOR SUB TWO MATRIX - PRES 1 :"<<endl;
        cout << "FOR PREFIX DISCREMENT ++ PRESS 2 :"<<endl;
        cout << "FOR POSTFIX DISCREMENT ++ PRESS 3 :"<<endl;
        cout << "FOR SUB TO MATRIX += PRESS 4 :"<<endl;
        cout << "FOR EXIT PRESS E :"<<endl;
        cin >> choice;
        if(choice == 'E'){
            return;
        }

        cout<< "enter row of matrix A:"<<endl;
        cin >> row;
        cout<< "enter col of matrix A:"<<endl;
        cin >> col;
        cout<< "enter number in matrix A:"<<endl;
        
        for (int i = 0; i < row*col; i++){
            cin >> num;
            a.push_back(num);
        }
        Matrix A(a, row, col);

        if(choice == '1'){
            cout<< "enter row of matrix B:"<<endl;
            cin >> row;
            cout<< "enter col of matrix B:"<<endl;
            cin >> col;
            cout<< "enter number in matrix B:"<<endl;
            for (int i = 0; i < row*col; i++){
                cin >> num;
                b.push_back(num);
            }
            Matrix B(b, row, col);
            cout << A << " = A "<< endl << endl;
            cout << B << " = B "<< endl << endl;
            try{
               cout  << A-B << " = A - B"<< endl;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
        else if(choice == '2'){
            cout << --A <<" = --A PREFIX DISCREMENT" << endl;
        }
        else if(choice == '3'){
            cout << A-- <<" = A-- POSTFIX DISCREMENT" << endl << endl;
            cout << A-- <<" = A-- after" << endl;
        }
        else if(choice == '4'){
            cout<< "enter row of matrix B:"<<endl;
            cin >> row;
            cout<< "enter col of matrix B:"<<endl;
            cin >> col;
            cout<< "enter number in matrix B:"<<endl;
            for (int i = 0; i < row*col; i++){
                cin >> num;
                b.push_back(num);
            }
            Matrix B(b, row, col);
            cout << A << " = A "<< endl << endl;
            cout << B << " = B "<< endl << endl;
            try{
                A-=B;
                cout << A  << "  = A-=B "<< endl;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
    }
    while (choice != 'E');
    return;
}
void mult(){
    char choice;
    
    do{
        int row, col;
        double num;
        double scalar;
        vector <double> a;
        vector <double> b;

        cout << "Please choose:" << endl;
        cout << "FOR MULT TWO MATRIX * PRES 1 :"<<endl;
        cout << "FOR MULT SCALAR: MATRIX*SCALAR PRESS 2 :"<<endl;
        cout << "FOR MULT SCALAR: SCALAR*MATRIX PRESS 3 :"<<endl;
        cout << "FOR MULT SCALAR: MATRIX*=SCALAR PRESS 4 :"<<endl;
        cout << "FOR MULT TWO MATRIX *= PRESS 4 :"<<endl;
        cout << "FOR EXIT PRESS E :"<<endl;
        cin >> choice;
        if(choice == 'E'){
            return;
        }

        cout<< "enter row of matrix A:"<<endl;
        cin >> row;
        cout<< "enter col of matrix A:"<<endl;
        cin >> col;
        cout<< "enter number in matrix A:"<<endl;
        
        for (int i = 0; i < row*col; i++){
            cin >> num;
            a.push_back(num);
        }
        Matrix A(a, row, col);

        if(choice == '1'){
            cout<< "enter row of matrix B:"<<endl;
            cin >> row;
            cout<< "enter col of matrix B:"<<endl;
            cin >> col;
            cout<< "enter number in matrix B:"<<endl;
            for (int i = 0; i < row*col; i++){
                cin >> num;
                b.push_back(num);
            }
            Matrix B(b, row, col);
            cout << A << " = A "<< endl << endl;
            cout << B << " = B "<< endl << endl;
            try{
                cout  << A*B << " = A * B"<< endl;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
        else if(choice == '2'){
            cout << "ENTER SCALAR:" << endl;
            cin >> scalar;
            cout << A <<" = A " << endl<<endl;
            cout << A*scalar <<" = A*"<<scalar << endl;
        }
        else if(choice == '3'){
            cout << "ENTER SCALAR:" << endl;
            cin >> scalar;
            cout << A <<" = A " << endl<<endl;
            cout << scalar*A <<" ="<<scalar<<" *A" << endl;
        }
        else if(choice == '4'){
            cout << "ENTER SCALAR:" << endl;
            cin >> scalar;
            cout << A <<" = A " << endl<<endl;
            try{
                A*=scalar;
                cout << A <<" = A*="<<scalar << endl;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
    }
    while (choice != 'E');
    return;
}
void comparson(){
    char choice;
    
    do{
        int row, col;
        double num;
        vector <double> a;
        vector <double> b;

        cout << "Please choose:" << endl;
        cout << "FOR COMPARE TWO MATRIX > PRES 1 :"<<endl;
        cout << "FOR COMPARE TWO MATRIX >= 2 :"<<endl;
        cout << "FOR COMPARE TWO MATRIX < PRESS 3 :"<<endl;
        cout << "FOR COMPARE TWO MATRIX <= PRESS 4 :"<<endl;
        cout << "FOR COMPARE TWO MATRIX == PRESS 5 :"<<endl;
        cout << "FOR COMPARE TWO MATRIX != PRESS 6 :"<<endl;
        cout << "FOR EXIT PRESS E :"<<endl;
        cin >> choice;
        if(choice == 'E'){
            return;
        }

        cout<< "enter row of matrix A:"<<endl;
        cin >> row;
        cout<< "enter col of matrix A:"<<endl;
        cin >> col;
        cout<< "enter number in matrix A:"<<endl;

        for (int i = 0; i < row*col; i++){
            cin >> num;
            a.push_back(num);
        }
        Matrix A(a, row, col);

        cout<< "enter row of matrix B:"<<endl;
            cin >> row;
            cout<< "enter col of matrix B:"<<endl;
            cin >> col;
            cout<< "enter number in matrix B:"<<endl;
            for (int i = 0; i < row*col; i++){
                cin >> num;
                b.push_back(num);
            }
            Matrix B(b, row, col);

        if(choice == '1'){
            cout << A << " = A "<< endl << endl;
            cout << B << " = B "<< endl << endl;
            try{
                cout << (A > B) <<" A > B "<< endl << endl;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
        else if(choice == '2'){
           cout << A << " = A "<< endl << endl;
            cout << B << " = B "<< endl << endl;
            try{
                cout << (A >= B) <<" A >= B "<< endl << endl;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
        else if(choice == '3'){
            cout << A << " = A "<< endl << endl;
            cout << B << " = B "<< endl << endl;
            try{
                cout << (A < B) <<" A < B "<< endl << endl;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
        else if(choice == '4'){
            cout << A << " = A "<< endl << endl;
            cout << B << " = B "<< endl << endl;
            try{
                cout << (A <= B) <<" A <= B "<< endl << endl;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
        else if(choice == '5'){
            cout << A << " = A "<< endl << endl;
            cout << B << " = B "<< endl << endl;
            try{
                cout << (A == B) <<" A == B "<< endl << endl;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
        else if(choice == '4'){
            cout << A << " = A "<< endl << endl;
            cout << B << " = B "<< endl << endl;
            try{
                cout << (A != B) <<" A != B "<< endl << endl;
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
        }
    }
    while (choice != 'E');
    return;
}
int main(){
    char choice;
    do{
        cout << "Please choose:" << endl;
        cout << "FOR ADD OPERATOR PRESS + :"<< endl;
        cout << "FOR SUB OPERATOR PRESS - :"<< endl;
        cout << "FOR MULTI OPERATOR PRESS * :"<< endl;
        cout << "FOR COMPARISON OPERATOR PRESS = :"<< endl;
      //  cout << "FOR ISTREAM OPERATOR PRESS > :"<< endl;
        cout << "FOR EXIT PRESS E :"<< endl;
        
        cin >> choice;
        switch(choice){

            case '+':
                add();
            break;

            case '-':
                sub();
            break;

            case '*':
                mult();
            break;

            case '=':
                comparson();
            break;

         //   case '>':
          //      is();
          //  break;

        default:
            break; 
        }
    }
    while (choice != 'E');
    return 0;
}