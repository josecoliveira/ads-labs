
#include "progbar.h"

progbar::progbar(std::ostream& out) : stream(out) {}

void progbar::operator()(double x)
{
    int barWidth = 50;

    stream << "[";
    int pos = barWidth * x;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) stream << "=";
        else if (i == pos) stream << ">";
        else stream << " ";
    }
    stream << "] " << int(x * 100.0) << " %\r";
    stream.flush();
}
