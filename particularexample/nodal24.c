#include <stdio.h>

int main() {
    // Node Va between 4Ω, 1.333Ω, and 2A current source
    float va, numerator, denominator;

    numerator = (5.0 / 4.0) + (2.0 / 1.333) + 2.0;
    denominator = (1.0 / 4.0) + (1.0 / 1.333);

    va = numerator / denominator;
    float vr3 = va - 2.0;

    printf("Voltage across RL using Nodal Analysis = %.2f V\n", vr3);
    return 0;
}
