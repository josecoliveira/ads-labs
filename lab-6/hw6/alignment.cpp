// alignment.cpp implementation file for sequence alignment assignment

#include "alignment.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <climits>

#include "progbar.h"
// Constructor
Alignment::Alignment()
{
}

void Alignment::initialize(string a, string b)
{
    progbar pbar(std::cerr);
    x = a;
    y = b;
    std::cerr << "allocating memory...";
    tab.resize(x.size() + 1, y.size() + 1);
    std::cerr << "done" << std::endl;
    std::cerr << "computing alignment...\n";

    /// FILL IN ///

    // If you have a loop index i that goes to n, you can output a text
    // "progress bar" that shows progress through the loop by calling
    //
    //  pbar(double(i)/double(n));
    //
    //

    for (int i = 0; i <= x.size(); i++)
    {
        for (int j = 0; j <= y.size(); j++)
        {
            if (i == 0 && j == 0)
            {
                tab[i][j] = 0;
            }
            else if (j == 0)
            {
                tab[i][j] = i;
            }
            else if (i == 0)
            {
                tab[i][j] = j;
            }
            else if (x[i - 1] == y[j - 1])
            {
                tab[i][j] = tab[i - 1][j - 1];
            }
            else
            {
                tab[i][j] = 1 + min(tab[i - 1][j], min(tab[i][j - 1], tab[i - 1][j - 1]));
            }
            // pbar(double(i * (j - 1) + j) / double(x.size() * y.size()));
        }
        // pbar(double(i) / double(x.size()));
    }
    
}

int Alignment::distance(void)
{
    /// FILL IN ///
    return tab[x.size()][y.size()];
}
