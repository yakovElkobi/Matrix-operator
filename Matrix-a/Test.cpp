/**
 * Test file for the exercise operators
 *
 * @author yakov elkobi
 * @since 2022-03
 * 
 */
#include "Matrix.hpp"
#include "doctest.h"
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace zich;
    
TEST_CASE("bad input constructor"){
    vector <double> a;
    CHECK_THROWS(Matrix(a,1,2));
    CHECK_THROWS(Matrix(a, 0, 0));
    a = {1,2,3,4};
    CHECK_THROWS(Matrix(a, 0, 0));
    CHECK_THROWS(Matrix(a,1,2));
    CHECK_THROWS(Matrix(a,0,2));
    CHECK_THROWS(Matrix(a,-1,2));
    CHECK_THROWS(Matrix(a,1,-2));
    CHECK_NOTHROW(Matrix(a,2,2));
    Matrix A(a,2,2);
    CHECK(A.getRow() == 2);
    CHECK(A.getCol() == 2);
}
TEST_CASE("bad input +, +=, -, -="){
    vector <double> a = {1,2,3,4,5,6,7,8,9};
    vector <double> b = {1,2,3,4};
    Matrix A(a, 3, 3);
    Matrix B(b,2,2);

    CHECK_THROWS(A+B);
    CHECK_THROWS(B+A);
    CHECK_THROWS(A+=B);
    CHECK_THROWS(B+=A);
    CHECK_THROWS(A-B);
    CHECK_THROWS(B-A);
    CHECK_THROWS(A-=B);
    CHECK_THROWS(B-=A);
}
TEST_CASE("bad input *, *="){
    vector <double> a = {1,2,3,4,5,6};
    vector <double> b = {1,2,3,4};
    Matrix A(a,2,3);
    Matrix B(b,2,2);
    CHECK_THROWS(A*B);
    CHECK_NOTHROW(B*A);
    CHECK_THROWS(A*=B);
    CHECK_NOTHROW(B*=A);
}
TEST_CASE("operator+()"){
    vector <double> a = {1,2,3,4,5,6,7,8,9};
    vector <double> b = {9,8,7,6,5,4,3,2,1};
    vector <double> c = {10,10,10,10,10,10,10,10,10};
    
    Matrix A(a,3,3);
    Matrix B(b,3,3);
    Matrix C(c,3,3);
    CHECK(A.getRow()==3);
    CHECK(A.getCol()==3);
    CHECK(B.getRow()==3);
    CHECK(B.getCol()==3);
    CHECK(C.getRow()==3);
    CHECK(C.getCol()==3);
    CHECK_NOTHROW(A+B);
    CHECK_NOTHROW(B+C);
    CHECK(((A+B) == C) == true);
    CHECK(((B+A) == C) == true);
    vector <double> d = {1,2,3,4,5,6,7,8,9};
    vector <double> e = {1,2,3,4};
    Matrix D(d, 3, 3);
    Matrix E(e,2,2);
    CHECK_THROWS(D+E);
    CHECK_THROWS(E+D);
}
TEST_CASE("operator++() prefix increment"){
    vector <double> a = {9,9,9,9,9,9,9,9,9};
    vector <double> b = {10,10,10,10,10,10,10,10,10};
    Matrix A(a,3,3);
    Matrix B(b,3,3);
    CHECK(((++A )== B) == true);
}

TEST_CASE("operator+=(Matrix)"){
    vector <double> a = {1,2,3,4,5,6,7,8,9};
    vector <double> b = {1,2,3,4};
    Matrix A(a, 3, 3);
    Matrix B(b,2,2);

    CHECK(A.getRow()==3);
    CHECK(A.getCol()==3);
    CHECK(B.getRow()==2);
    CHECK(B.getCol()==2);

    CHECK_THROWS(A+=B);
    CHECK_THROWS(B+=A);

    vector <double> c = {1,2,3,4,5,6,7,8,9};
    vector <double> d = {9,8,7,6,5,4,3,2,1};
    vector <double> e = {10,10,10,10,10,10,10,10,10};
    
    Matrix C(c,3,3);
    Matrix D(d,3,3);
    Matrix E(e,3,3);
    CHECK(C.getRow()== D.getRow());
    CHECK(D.getCol()==D.getCol());

    CHECK(((C+=D) == E) == true);
}
TEST_CASE("operator-()"){
    vector <double> a = {1,2,3,4,5,6,7,8,9};
    vector <double> b = {9,8,7,6,5,4,3,2,1};
    vector <double> c = {10,10,10,10,10,10,10,10,10};
    
    Matrix A(a,3,3);
    Matrix B(b,3,3);
    Matrix C(c,3,3);
    CHECK(A.getRow()==3);
    CHECK(A.getCol()==3);
    CHECK(B.getRow()==3);
    CHECK(B.getCol()==3);
    CHECK(C.getRow()==3);
    CHECK(C.getCol()==3);
    CHECK_NOTHROW(C-A);
    CHECK(((C-A) == B) == true);
    vector <double> d = {1,2,3,4,5,6,7,8,9};
    vector <double> e = {1,2,3,4};
    Matrix D(d, 3, 3);
    Matrix E(e,2,2);
    CHECK_THROWS(D-E);
    CHECK_THROWS(E-D);
}
TEST_CASE("operator--() prefix dicrement"){
    vector <double> a = {9,9,9,9,9,9,9,9,9};
    vector <double> b = {10,10,10,10,10,10,10,10,10};
    Matrix A(a,3,3);
    Matrix B(b,3,3);
    CHECK(((--B )== A) == true);
}
TEST_CASE("operator-(Matrix)"){
    vector<double> a = {1,2,3,4,5,6};
    vector<double> b = {-1,-2,-3,-4,-5,-6};

    Matrix A (a, 2,3);
    Matrix B(b,2,3);
    CHECK(((-A) == B)==true);
}
TEST_CASE("operator-=(Matrix)"){
    vector <double> a = {1,2,3,4,5,6,7,8,9};
    vector <double> b = {1,2,3,4};
    Matrix A(a, 3, 3);
    Matrix B(b,2,2);

    CHECK(A.getRow()==3);
    CHECK(A.getCol()==3);
    CHECK(B.getRow()==2);
    CHECK(B.getCol()==2);

    CHECK_THROWS(A-=B);
    CHECK_THROWS(B-=A);

    vector <double> c = {1,2,3,4,5,6,7,8,9};
    vector <double> d = {9,8,7,6,5,4,3,2,1};
    vector <double> e = {10,10,10,10,10,10,10,10,10};
    
    Matrix C(c,3,3);
    Matrix D(d,3,3);
    Matrix E(e,3,3);
    CHECK(C.getRow()== D.getRow());
    CHECK(D.getCol()==D.getCol());

    CHECK(((E-=D) == C) == true);
}
TEST_CASE("operator*(Matrix)"){
    vector<double> a = {1,2,3,4,5,6};// 2x3
    vector<double> b = {1,2,3,4,5,6};// 2x3;
    vector <double> c = {1,4,6,8,10,12}; // 2X3

    Matrix A(a,2,3);
    Matrix B(b,2,3);
    Matrix C(c,2,3);
    
   CHECK_THROWS(B*A);
   CHECK_THROWS(A*B);

    vector <double> e = {1,2,0,4,3,-1};// 3x2
    vector <double> f = {5,1,2,3,3,4};// 2x3;
    vector <double> g = {9,7,23,9}; // 2X2
    vector <double> h = {9,13,-1,14,13,-3,19,18,-4}; // 3X3

    Matrix E(e,2,3);
    Matrix F(f,3,2);
    Matrix G(g,2,2);
    Matrix H(h,3,3);

   CHECK_NOTHROW(E*F);
   CHECK(((E*F) == G) == true);
   CHECK_NOTHROW(F*E); 
}
TEST_CASE("operator*(double)"){
    vector<double> a = {1,2,3,4,5,6};
    vector<double> b = {2,4,6,8,10,12};

    Matrix A (a, 2,3);
    Matrix B(b,2,3);
    CHECK(((A*2) == B)==true);
}
TEST_CASE("operator*(scalar, Matrix)"){
    vector<double> a = {1,2,3,4,5,6};
    vector<double> b = {2,4,6,8,10,12};

    Matrix A (a, 2,3);
    Matrix B(b,2,3);
    CHECK(((2*A) == B)==true);
}
TEST_CASE("operator>(Matrix)"){
    vector<double> a = {1,2,3,4,5,6};
    vector<double> b = {2,4,6,8,10,12};
    Matrix A (a, 2,3);
    Matrix B(b,2,3);
    CHECK((B > A) == true);
    CHECK((A > B) == false);

}
TEST_CASE("operator>=(Matrix)"){
    vector<double> a = {1,2,3,4,5,6};
    vector<double> b = {2,4,6,8,10,12};
    Matrix A (a, 2,3);
    Matrix B(b,2,3);
    CHECK((B >= A) == true);
    CHECK((A >= B) == false);
    CHECK((A >=A)==true);

}
TEST_CASE("operator<(Matrix)"){
    vector<double> a = {1,2,3,4,5,6};
    vector<double> b = {2,4,6,8,10,12};
    Matrix A (a, 2,3);
    Matrix B(b,2,3);
    CHECK((B < A) == false);
    CHECK((A < B) == true);
    CHECK((A < A)== true);

}
TEST_CASE("operator<=(Matrix)"){
    vector<double> a = {1,2,3,4,5,6};
    vector<double> b = {2,4,6,8,10,12};
    Matrix A (a, 2,3);
    Matrix B(b,2,3);
    CHECK((A <= B) == true);
    CHECK((B <= A) == false);
    CHECK((A <=A)==true);
}
TEST_CASE("operator!=(Matrix)"){
vector<double> a = {1,2,3,4,5,6};
    vector<double> b = {2,4,6,8,10,12};
    Matrix A (a, 2,3);
    Matrix B(b,2,3);
    CHECK((A != B) == true);
    CHECK((B != A) == true);
    CHECK((A !=A)==false);
}