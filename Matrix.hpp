#include <iostream>
#include <vector>
using namespace std;

namespace zich {
    
    class Matrix {
        private:
            vector<double> vec;
            int rows;
            int cols;

        public:
            Matrix operator+(Matrix other);
            //friend Matrix operator+(Matrix mat1, Matrix mat2);

            Matrix operator-(Matrix other);
            Matrix operator-();
            Matrix operator+();
            Matrix operator*(Matrix other);
            friend Matrix operator*(double n, const Matrix &mat);
            friend Matrix operator*(int n, const Matrix &mat);
            friend Matrix operator*(const Matrix &mat, double n); 
            friend Matrix operator*(const Matrix &mat, int n);            
            friend Matrix operator*(const Matrix &mat1, const Matrix &mat2);            
            Matrix operator*=(int n);
            friend ostream& operator<<(ostream& os, const Matrix& mat);
            bool operator<=(Matrix other);
            bool operator<(Matrix other);
            bool operator>=(Matrix other);
            bool operator>(Matrix other);
            bool operator==(const zich::Matrix &other);
            Matrix to_string (Matrix mat);
            Matrix(vector<double> vec, int rows, int cols);
	};

}
