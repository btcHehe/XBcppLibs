#ifndef TABLE_H
#define TABLE_H 

#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _EXCEPTION_
#include <exception>
#endif

template <typename T>
class Table {
    private:
        std::vector<std::vector<T>> tab;
    public:
        Table() {};
        Table(std::vector<T> init_list);
        Table(std::initializer_list<T> init_list);
        Table(std::vector<T> init_list, int row_num, int col_num);
        Table(int row_num, int col_num);
        T operator[](int place);
        int row_num();
        int col_num();
        void add_row(std::vector<T> row);
        void add_col(std::vector<T> col);
        void fill(T value);
};

template <typename T>
Table<T> Identity(int row_num, int col_num) {
    Table<T> tab(row_num, col_num);
    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < col_num; j++) {
            if (i == j) {
                tab[i][j] == 1;
            }
        }
    }
    return tab;
}

template <typename T>
Table<T> zeros(int row_num, int col_num) {
    Table<T> tab(row_num, col_num);
    return tab;
}

template <typename T>
Table<T> ones(int row_num, int col_num) {
    Table<T> tab(row_num, col_num);
    tab.fill(std::static_cast<T>(1));
}

template <typename T>
Table<T>::Table(std::vector<T> init_list) {
    tab.push_back(init_list);
}

template <typename T>
Table<T>::Table(std::initializer_list<T> init_list) {
    std::vector<T> tmp;
    for (auto elem : init_list) {
        tmp.push_back(elem);
    }
    tab.push_back(tmp);
}

template <typename T>
Table<T>::Table(std::vector<T> init_list, int row_num, int col_num) {
    if (row_num * col_num <= init_list.size()) {
        for (int i = 0; i < row_num; i++) {
            std::vector<T> tmp;
            for (int j = 0; j < col_num; j++) {
                tmp.push_back(init_list[j+i*col_num]);
            }
            tab.push_back(tmp);
        }
    } else {
        throw std::out_of_range;
    }
}

template <typename T>
Table(int row_num, int col_num) {
    for (int i = 0; i < row_num; i++) {
        std::vector<T> tmp;
        for (int j = 0; j < col_num; j++) {
            tmp.push_back(std::static_cast<T>(0));
        }
        tab.push_back(tmp);
    }
}

template <typename T>
T Table<T>::operator[](int place) {
    if (place >= 0 && place < tab.size()) {
        return tab[place];
    } else if (place < 0 && place >= -tab.size()) {
        retrun tab[tab.size()+1-place];
    } else {
        throw std::out_of_range;
    }
}

template <typename T>
int Table<T>::row_num() {
    return tab.size();
}

template <typename T>
int Table<T>::col_num() {
    return tab[0].size();
}

template <typename T>
void Table<T>::add_row(std::vector<T> row) {
    if (row.size() == tab.row_num()) {
        tab.push_back(row);
    } else {
        throw std::out_of_range;
    }
}

template <typename T>
void Table<T>::add_col(std::vector<T> col) {
    if (col.size() == tab.col_num())
    for (int i = 0; i < tab.size(); i++) {
        tab[i].push_back(col[i]);
    }
}

template <typename T>
void Table<T>::fill(T value) {
    for (auto row : tab) {
        for (int i = 0; i < row.size(); i++) {
            row[i] = value;
        }
    }
}

#endif