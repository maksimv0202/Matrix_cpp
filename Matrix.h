#pragma once

#include <iostream>

template <typename T = int, size_t M = 0, size_t N = 0, typename Alloc = std::allocator<T>>
class Matrix {
private:
    T matrix[M][N];
public:
    Matrix() {}
    
    Matrix(std::initializer_list<T> lst) {}

    Matrix(const T& fill) {}
    
    Matrix(const Matrix<T, M, N>& matrix) {}

    Matrix(Matrix<T, M, N>&& matrix) {}

    Matrix& operator=(const Matrix<T, M, N>& matrix) {}

    Matrix& operator=(Matrix<T, M, N>&& matrix) {}
    
    Matrix<T, M, N>& operator+=(const Matrix<T, M, N>& r_matrix) {}
    
    Matrix<T, M, N>& operator-=(const Matrix<T, M, N>& r_matrix) {}
    
    template <size_t K>
    Matrix<T, M, K>& operator*=(const Matrix<T, N, K>& r_matrix) {}
    
    Matrix<T, M, N>& operator+(const Matrix<T, M, N>& r_matrix) {}
    
    Matrix<T, M, N>& operator-(const Matrix<T, M, N>& r_matrix) {}
   
    template <size_t K>
    Matrix<T, M, K>& operator*(const Matrix<T, N, K>& r_matrix) {}
    
    T __det() {}

    Matrix<T, M, M>& __transponse() {}
    
    Matrix<T, M, M> __inverse() {}
    
    T __tr() {}

    ~Matrix() {}
};

