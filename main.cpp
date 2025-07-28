#include "OutFile.h"
#include <cstdlib>

int main()
{
    srand(time(0));
    Out fOut;
    fOut.Run(10000, ' ');
}