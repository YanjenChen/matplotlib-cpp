#include <map>
#include <string>

#include "../matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    // u and v are respectively the x and y components of the arrows we're plotting
    int n0 = 11;
    int n1 = 11;
    int n2 = 11;

    int *x, *y, *z, *u, *v, *w;
    x = new int[n0 * n1 * n2];
    y = new int[n0 * n1 * n2];
    z = new int[n0 * n1 * n2];
    u = new int[n0 * n1 * n2];
    v = new int[n0 * n1 * n2];
    w = new int[n0 * n1 * n2];

    for (int i = 0; i < n0; i++) {
        for (int j = 0; j < n1; j++) {
            for (int k = 0; k < n2; k++) {
                int idx = k + n2 * (j + n1 * i);
                x[idx] = k - 5;
                y[idx] = j - 5;
                z[idx] = i - 5;
                u[idx] = k - 5;
                v[idx] = j - 5;
                w[idx] = i - 5;
            }
        }
    }

    std::map<std::string, std::string> kwargs = {{"normalize", "True"}};
    plt::quiver(x, y, z, u, v, w, n0, n1, n2, kwargs);
    plt::show();

    delete[] x;
    delete[] y;
    delete[] z;
    delete[] u;
    delete[] v;
    delete[] w;
}