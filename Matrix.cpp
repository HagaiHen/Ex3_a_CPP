#include <string>
#include "Matrix.hpp"

namespace zich {
    
    Matrix::Matrix(vector<double> vec, int rows, int cols) {
        this->vec = vec;
        this->rows = rows;
        this->cols = cols;
    }

    zich::Matrix Matrix::operator+(Matrix other) {
        Matrix ans{this->vec, this->rows, this->cols};
        if (this->cols != other.cols || this->rows != other.rows) {
            throw "The matrices do not match";
        }
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                ans.vec[(double) (i*ans.cols) + j] = (this->vec[(double)(i*this->cols) + j] + other.vec[(double)(i*other.cols) + j]); 
            }
        }
        return ans;
        
    }

    zich::Matrix Matrix::operator-(Matrix other) {
        Matrix ans{this->vec, this->rows, this->cols};
        if (this->cols != other.cols || this->rows != other.rows) {
            throw "The matrices do not match";
        }
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                ans.vec[(double) (i*ans.cols) + j] = (this->vec[(double)(i*this->cols) + j] - other.vec[(double)(i*other.cols) + j]); 
            }
        }
        return ans;
    }

    zich::Matrix Matrix::operator-() {
        for (int i = 0; i <this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                this->vec[(double) (i*this->cols) + j] = (-1) * this->vec[(double) (i*this->cols) + j];
            }
        }
        return *this;
    }

    zich::Matrix Matrix::operator+() {
        return *this;
    }

    zich::Matrix operator*(double n, const Matrix &other) {
        Matrix ans{other.vec, other.rows, other.cols};
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                ans.vec[(double) (i*other.cols) + j] = n * other.vec[(double) (i*other.cols) + j];
            }
        }
        return ans;
    }

    zich::Matrix operator*(int n, const Matrix &other) {
        Matrix ans{other.vec, other.rows, other.cols};
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                ans.vec[(double) (i*other.cols) + j] = n * other.vec[(double) (i*other.cols) + j];
            }
        }
        return ans;

    }
    
    zich::Matrix operator*(const Matrix &other, double n) {
        Matrix ans{other.vec, other.rows, other.cols};
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                ans.vec[(double) (i*other.cols) + j] = n * other.vec[(double) (i*other.cols) + j];
            }
        }
        return ans;
    }

    zich::Matrix operator*(const Matrix &other, int n) {
        Matrix ans{other.vec, other.rows, other.cols};
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                ans.vec[(double) (i*other.cols) + j] = n * other.vec[(double) (i*other.cols) + j];
            }
        }
        return ans;

    }

    Matrix operator*(Matrix other) {
        return other;

    }

    zich::Matrix operator*(const Matrix &mat1, const Matrix &mat2) {
        if (mat1.cols != mat2.rows || mat2.rows != mat2.rows) {
            throw "The matrices do not match";
        }
        double sum = 0;
        vector<double> v((double) mat1.rows * mat2.cols);
        Matrix ans{v, mat1.rows, mat2.cols};
        for (int i = 0; i <mat1.rows; i++) {
            for (int j = 0; j <mat1.rows; j++) {
                for (int k = 0; k < mat2.cols; k++) {
                    ans.vec[(double) (i*mat2.cols) + j] += mat1.vec[(double) (i*mat2.cols) + k] * mat1.vec[(double) (k*mat2.cols) + j];
                }
            }
        }
        cout << ans;
        return ans;

    }
    

    zich::Matrix Matrix::operator*=(int n) {
        return *this;
    }

    ostream& operator<<(ostream& os, const Matrix& mat) {
        for (int i = 0; i < mat.rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                os <<  "[" << mat.vec[(double)(i*mat.cols) + j] << "]";
            }
            os << endl;
        }
        return os;
    }

    bool Matrix::operator<=(Matrix other) {
        if (this->cols != other.cols || this->rows != other.rows) {
            return false;
        }
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                if (this->vec[(double)(i*this->cols) + j] > other.vec[(double)(i*other.cols) + j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool Matrix::operator<(Matrix other) {
        if (this->cols != other.cols || this->rows != other.rows) {
            return false;
        }
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                if (this->vec[(double)(i*this->cols) + j] >= other.vec[(double)(i*other.cols) + j]) {
                    return false;
                }
            }
        }
        return true;

    }
    bool Matrix::operator>=(Matrix other) {
        if (this->cols != other.cols || this->rows != other.rows) {
            return false;
        }
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                if (this->vec[(double)(i*this->cols) + j] < other.vec[(double)(i*other.cols) + j]) {
                    return false;
                }
            }
        }
        return true;

    }
    bool Matrix::operator>(Matrix other) {
        if (this->cols != other.cols || this->rows != other.rows) {
            return false;
        }
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                if (this->vec[(double)(i*this->cols) + j] <= other.vec[(double)(i*other.cols) + j]) {
                    return false;
                }
            }
        }
        return true;

    }
    bool Matrix::operator==(const zich::Matrix &other) {
        if (this->cols != other.cols || this->rows != other.rows) {
            return false;
        }
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                if (this->vec[(double)(i*this->cols) + j] != other.vec[(double)(i*other.cols) + j]) {
                    return false;
                }
            }
        }
        return true;
    }

}



