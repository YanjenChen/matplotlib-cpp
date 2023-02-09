#include <map>
#include <string>

#include "../matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    // u and v are respectively the x and y components of the arrows we're plotting
    int n0 = 5;
    int n1 = 5;
    int n2 = 5;

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
                x[idx] = k - 2;
                y[idx] = j - 2;
                z[idx] = i - 2;
                u[idx] = k - 2;
                v[idx] = j - 2;
                w[idx] = i - 2;
            }
        }
    }

    std::map<std::string, std::string> subplot_kwargs = {{"projection", "3d"}};
    plt::subplot(1, 1, 1, subplot_kwargs);
    std::map<std::string, std::string> quiver_kwargs = {{"normalize", "True"}, {"length", "0.3"}};
    plt::quiver(x, y, z, u, v, w, n0, n1, n2, quiver_kwargs);
    plt::show();

    delete[] x;
    delete[] y;
    delete[] z;
    delete[] u;
    delete[] v;
    delete[] w;
}