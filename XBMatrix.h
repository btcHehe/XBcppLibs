#ifndef _IOSTREAM_
#include <iostream>
#endif

#ifndef _STD_EXCEPT_
#include <stdexcept>
#endif

#ifndef XBMATRIX_H
#define XBMATRIX_H

//indexing starts from 0 so element [0][0] is the element in the left upper row of the matrix

namespace xb {
	template<typename T>
	
	class matrix {
		private:
			int rowNum;
			int colNum;
			T** rows;
		public:
			matrix();
			matrix(int rowsNumber,int colsNumber) {
				rowNum = rowsNumber;
				colNum = colsNumber;
				rows = new T*[rowsNumber];
				for(int i=0; i<rowsNumber; i++)
					rows[i] = new T[colsNumber];
			}
			matrix(T** rowsTab) { 			//the array containing all the rows
				rows = rowsTab;
			}

			int getRowNum() {
				return rowNum;
			}

			int getColNum() {
				return colNum;
			}

			T& at(int r, int c) {
				return rows[r][c];
			}

			void fillOnes() {
				for(int i=0; i<rowNum; i++)
					for(int j=0; j<colNum; j++)
						rows[i][j] = 1;
			}

			void fillZeros() {
				for(int i=0; i<rowNum; i++)
					for(int j=0; j<colNum; j++)
						rows[i][j] = 0;
			}

			void makeIdentity() {
				if(rowNum == colNum) {
					for(int i=0; i<rowNum; i++)
						for(int j=0; j<colNum; j++) {
							if(j != i)
								rows[i][j] = 0;
							else
								rows[i][j] = 1;
						}
				}
				else
					throw
						std::length_error("matrix must be elementary");
			}

			matrix<T> operator*(matrix<T> mat2) {
				if(colNum == mat2.getRowNum()) {
					int resultRows = rowNum;
					int resultCols = mat2.getColNum();
					matrix<T> result(resultRows, resultCols);
					T sum = 0;
					int k = 0;
					for(int i=0; i<resultRows; i++) {
						for(int k=0; k<resultCols; k++) {
							for(int j=0; j<colNum; j++)
								sum += at(i,j)*mat2.at(j,k);	
							result.at(i,k) = sum;
							sum = 0;
						}
						
					}
					return result;
				}
				else
					throw
						std::length_error("matrices must be matching");
			}

			matrix<T> operator+(matrix<T> mat2) {
				if(colNum == mat2.getColNum() && rowNum == mat2.getRowNum()) {
					matrix<T> result(rowNum, colNum);
					for(int i=0; i<rowNum; i++)
						for(int j=0; j<colNum; j++)
							result.at(i,j) = at(i,j) + mat2.at(i,j);
					return result;
				}
				else
					throw
						std::length_error("matrices must match each other");
			}

			matrix<T> operator-(matrix<T> mat2) {
				if(colNum == mat2.getColNum() && rowNum == mat2.getRowNum()) {
					matrix<T> result(rowNum, colNum);
					for(int i=0; i<rowNum; i++)
						for(int j=0; j<colNum; j++)
							result.at(i,j) = at(i,j) - mat2.at(i,j);
					return result;
				}
				else
					throw
						std::length_error("matrices must match each other");
			}

			T minor(int r,int c) {  				//minor of the matrix after removing r row and c column
				matrix<T> m(rowNum-1, colNum-1);
				int rowCounter = 0;
				int colCounter = 0;
				for(int i=0; i<rowNum; i++) {
					for(int j=0; j<colNum; j++) {
						if(i == r) {
							rowCounter=1;
							continue;
						}
						else if( j == c) {
							colCounter++;
							continue;
						}
						else {
							m.at(i-rowCounter,j-colCounter) = at(i,j);
						}
					}
					colCounter = 0;
				}
				return m.det();
			}

			T det() { //to fix
				if(rowNum == colNum) {
					T d = 0;
					if(rowNum == 1)
						d = at(0,0);
					else
					{
						int j = 0;
						int pow = 1;
						for(int i=0; i<rowNum; i++) {
							for(int k=0; k<i+j+2; k++)
								pow *= -1;
							d += pow * at(j,i) * minor(j,i);
						}
					}
					return d;
				}
				else
					throw
						std::length_error("matrix must be elementary");
			}
	};
}

#endif
