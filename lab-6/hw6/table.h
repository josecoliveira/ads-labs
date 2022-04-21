#ifndef TABLE_H
#define TABLE_H

// simple integer table for dynamic programming
#include <vector>

struct table
{
    table() : nc(0) {}
    table(int rows, int cols)
        : nc(cols)
    {
        data.resize(rows * cols);
    }
    table(table const &t) : data(t.data), nc(t.nc) {}
    int rows() const { return nc ? data.size() / nc : 0; }
    int cols() const { return nc; }
    int *operator[](int a) { return &data[a * nc]; }
    int const *operator[](int a) const { return &data[a * nc]; }

    void resize(int a, int b)
    {
        if (a == 0)
        {
            nc = 0;
        }
        data.resize(a * b);
        nc = b;
    }

private:
    std::vector<int> data;
    int nc;
};

#endif
