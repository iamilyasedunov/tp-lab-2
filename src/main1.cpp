#include "task1.h"

int main() {
    const size_t n = 6;
    float val[n]{4.1f, 3.453f, 2.412f, 2.5221f, 2.12213f, -1.123f};
    msort(val, n);
    for(size_t i = 0; i < n; i++)
        cout<<val[i]<<" ";
    return 0;
}

