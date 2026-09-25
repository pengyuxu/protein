// Stateful wrapper over Tatsuma's exact i8_sobol sequence, for ctypes.
#include "../src/sobol.hpp"

static long long int g_seed = 0;

extern "C" {
void sobol_reset(void) { g_seed = 0; }   // i8_sobol re-inits on seed==0
void sobol_next_pair(double* out) {
    double r[2];
    i8_sobol(2, &g_seed, r);
    out[0] = r[0];
    out[1] = r[1];
}
void sobol_draws(long long int n, double* out) {
    for (long long int i = 0; i < n; ++i) {
        double r[2];
        i8_sobol(2, &g_seed, r);
        out[2*i]   = r[0];
        out[2*i+1] = r[1];
    }
}
}
