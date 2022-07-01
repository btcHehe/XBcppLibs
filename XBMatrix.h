#ifndef MATRIX_H
#define MATRIX_H 

#ifndef _VECTOR_
#include <vector>
#endif

#include <iostream>

#ifndef _EXCEPTION_
#include <exception>
#endif

namespace xb {
template <typename T>
class Matrix {
    private:
        std::vector<std::vector<T>> tab;
    public:
        Matrix() {};
        Matrix(std::vector<T> init_list);
        Matrix(std::initializer_list<T> init_list);
        Matrix(std::vector<T> init_list, int row_num, int col_num);
        Matrix(int row_num, int col_num);
        std::vector<T>& operator[](int place);
        Matrix<T> operator*(const Matrix<T> tab);
        Matrix<T> operator+(const Matrix<T> tab);
        Matrix<T> operator-(const Matrix<T> tab);
        Matrix<T> operator=(const Matrix<T> tab);
        Matrix<T> mul_each(const Matrix<T> arg1, const Matrix<T> arg2);
        int row_num();
        int col_num(); 
        void add_row(Matrix<T> row);
        void add_col(Matrix<T> col);
        void add_row(std::vector<T> row);
        void add_col(std::vector<T> col);
        void fill(T value);
        T det();
        Matrix<T> abs();
};


// ------------------------- Library functions --------------------------------------

template <typename T>
T abs(T x) {
    if (x < static_cast<T>(0)) {
        return static_cast<T>(-1)*x;
    } else {
        return x;
    }
}

template <typename T>
Matrix<T> Identity(int N) {
    Matrix<T> tab(N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                tab[i][j] = 1;
            }
        }
    }
    return tab;
}

template <typename T>
Matrix<T> zeros(int row_num, int col_num) {
    Matrix<T> tab(row_num, col_num);
    return tab;
}

template <typename T>
Matrix<T> ones(int row_num, int col_num) {
    Matrix<T> tab(row_num, col_num);
    tab.fill(static_cast<T>(1));
}

template <typename T>
Matrix<T> transpose(Matrix<T> table) {
    if (table.row_num() == table.col_num()) {
        Matrix<T> ret(table.row_num(), table.col_num());
        for (int i = 0; i < table.row_num(); i++) {
            for (int j = 0; j < table.col_num(); j++) {
                if (i != j) {
                    ret[i][j] = table[j][i];
                } else {
                    ret[i][j] = table[i][j];
                }
            }
        }
    } else {
        throw std::length_error("Matrix must have equal number of rows and columns")
    }
    return ret;
}

// Returns table after LU decomposition with Doolittle method containing X = (L+U)-Identity
// Example:
// X = [[a b c],
//      [d e f],
//      [g h i]]
// L = [[1 0 0],       U = [[a b c],
//      [d 1 0],            [0 e f],
//      [g h 1]]            [0 0 i]]
template <typename T>
Matrix<T> LUDecomposition(Matrix<T> A) {
    if (A.row_num() == A.col_num()) {
        int N = A.row_num();
        Matrix<T> X = zeros<T>(N, N);
        for (int k = 0; k < N; k++) {
            for (int j = k; j < N; j++) {
                T sum = static_cast<T>(0);
                for (int p = 0; p < k; p++) {
                    sum += X[k][p] * X[p][j];
                }
                X[k][j] = A[k][j] - sum;
            }
            for (int i = k+1; i < N; i++) {
                T sum = static_cast<T>(0);
                for (int p = 0; p < k; p++) {
                    sum += X[i][p] * X[p][k];
                }
                X[i][k] = (A[i][k] - sum) / X[k][k];
           }
        }
        return X;
    } else {
        throw std::length_error("Matrix must have equal number of rows and columns");
    }
}

// Helper function for getting L Matrix from Matrix received from LUDecomposition()
template <typename T>
Matrix<T> getLfromLU(Matrix<T> LU) {
    if (LU.row_num() == LU.col_num()) {
        int N = LU.row_num();
        Matrix<T> L = Identity<T>(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i > j) {
                    L[i][j] = LU[i][j];
                } else {
                    continue;
                }
            }
        }
        return L;
    } else {
        throw std::length_error("Matrix must have equal number of rows and columns");
    }
}

// Helper function for getting U Matrix from Matrix received from LUDecomposition()
template <typename T>
Matrix<T> getUfromLU(Matrix<T> LU) {
    if (LU.row_num() == LU.col_num()) {
        int N = LU.row_num();
        Matrix<T> U(N, N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i <= j) {
                    U[i][j] = LU[i][j];
                } else {
                    continue;
                }
            }
        }
        return U;
    } else {
        throw std::length_error("Matrix must have equal number of rows and columns");
    }
}

// ---------------------------- Class methods --------------------------------------

template <typename T>
Matrix<T>::Matrix(std::vector<T> init_list) {
    this->tab.push_back(init_list);
}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<T> init_list) {
    std::vector<T> tmp;
    for (auto elem : init_list) {
        tmp.push_back(elem);
    }
    this->tab.push_back(tmp);
}

template <typename T>
Matrix<T>::Matrix(std::vector<T> init_list, int row_num, int col_num) {
    if (row_num * col_num <= init_list.size()) {
        for (int i = 0; i < row_num; i++) {
            std::vector<T> tmp;
            for (int j = 0; j < col_num; j++) {
                tmp.push_back(init_list[j+i*col_num]);
            }
            this->tab.push_back(tmp);
        }
    } else {
        throw std::length_error("Initializer list is too big for declared table");
    }
}

template <typename T>
Matrix<T>::Matrix(int row_num, int col_num) {
    for (int i = 0; i < row_num; i++) {
        std::vector<T> tmp;
        for (int j = 0; j < col_num; j++) {
            tmp.push_back(static_cast<T>(0));
        }
        this->tab.push_back(tmp);
    }
}

template <typename T>
std::vector<T>& Matrix<T>::operator[](int place) {
    if (place >= 0 && place < tab.size()) {
        return this->tab[place];
    } else if (place < 0 && place >= -tab.size()) {
        return this->tab[this->tab.size()+1-place];
    } else {
        throw std::out_of_range("Wrong index");
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> tab) {
    if (this->col_num() == tab.row_num()) {
        Matrix<T> ret(this->row_num(), tab.col_num());
        for (int i = 0; i < this->row_num(); i++) {
            for (int j = 0; j < tab.col_num(); j++) {
                T sum = 0;
                for (int k = 0; k < this->col_num(); k++) {
                    sum += this->tab[i][k] + tab[k][j];
                }
                ret.tab[i][j] = sum;
            }
        }
        return ret;
    } else {
        throw std::length_error("Number of columns must be equal to number of rows");
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> tab) {
    if ((this->col_num() == tab.col_num()) && (this->row_num() == tab.row_num())) {
        Matrix<T> ret(this->row_num(), this->col_num());
        for (int i = 0; i < this->row_num(); i++) {
            for (int j = 0; j < this->col_num(); j++) {
                ret.tab[i][j] = this->tab[i][j] + tab[i][j];
            }
        }
        return ret;
    } else {
        throw std::length_error("Matrixs must have equal dimensions");
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> tab) {
    if ((this->col_num() == tab.col_num()) && (this->row_num() == tab.row_num())) {
        Matrix<T> ret(this->row_num(), this->col_num());
        for (int i = 0; i < this->row_num(); i++) {
            for (int j = 0; j < this->col_num(); j++) {
                ret.tab[i][j] = this->tab[i][j] - tab[i][j];
            }
        }
        return ret;
    } else {
        throw std::length_error("Matrixs must have equal dimensions");
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T> tab) {
    Matrix<T> ret = Matrix<T>(tab.row_num(), tab.col_num())
    for (int i = 0; i < tab.row_num(); i++) {
        for (int j = 0; j < tab.col_num(); j++) {
            ret[i][j] = tab[i][j];
        }
    }
}

template <typename T>
Matrix<T> mul_each(const Matrix<T> arg1, const Matrix<T> arg2) {
     if (this->col_num() == tab.col_num() && this->row_num() == tab.row_num()) {
        Matrix<T> ret(this->row_num(), this->col_num());
        for (int i = 0; i < this->row_num(); i++) {
            for (int j = 0; j < this->col_num(); j++) {
                ret.tab[i][j] = this->tab[i][j] * tab[i][j];
            }
        }
        return ret;
    } else {
        throw std::length_error("Matrixs must have equal dimensions");
    }
}

template <typename T>
int Matrix<T>::row_num() {
    if (this->tab[0].size() != 0) {
        return this->tab.size();
    } else {
        return 0;
    }
}

template <typename T>
int Matrix<T>::col_num() {
    return this->tab[0].size();
}

template <typename T>
void Matrix<T>::add_row(Matrix<T> row) {
    if (row.row_num() == 1 && this->col_num() == row.col_num()) {
        this->tab.push_back(row[0]);
    } else {
        throw std::length_error("Added row must have number of rows equal to 1 and proper number of columns")
    }
}

template <typename T>
void Matrix<T>::add_col(Matrix<T> col) {
    if (col.col_num() == 1 && this->row_num() == row.row_num()) {
        for(int i = 0; i < this->row_num(); i++) {
            this->tab[i].push_back(col[i][0])
        }
    } else {
        throw std::length_error("Added column must have number of columns equal to 1 and proper number of rows")
    }
}

template <typename T>
void Matrix<T>::add_row(std::vector<T> row) {
    if (row.size() == this->row_num()) {
        this->tab.push_back(row);
    } else {
        throw std::length_error("Row size doesn\'t match the size of the table");
    }
}

template <typename T>
void Matrix<T>::add_col(std::vector<T> col) {
    if (col.size() == this->col_num()) {
        for (int i = 0; i < this->tab.size(); i++) {
            this->tab[i].push_back(col[i]);
        }
    } else {
        std::length_error("Column size doesn\'t match the size of table")
    }
}

template <typename T>
void Matrix<T>::fill(T value) {
    for (auto row : tab) {
        for (int i = 0; i < row.size(); i++) {
            row[i] = value;
        }
    }
}

template <typename T>
T Matrix<T>::det() {
    Matrix<T> LU = LUDecomposition(*this);
    Matrix<T> L = getLfromLU(LU);
    Matrix<T> U = getUfromLU(LU);
}

template <typename T>
Matrix<T> Matrix<T>::abs() {
    Matrix<T> ret(this->row_num(), this->col_num());
    for (int i = 0; i < this->row_num(); i++) {
        for (int j = 0; j < this->col_num(); j++) {
            if (ret[i][j] < static_cast<T>(0)) {
                ret[i][j] = static_cast<T>(-1)*ret[i][j];
            } else {
                continue;
            }
        }
    }
    return ret;
}

}
#endif