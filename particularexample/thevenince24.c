#include <stdio.h>

int main() {
    float r1 = 8.0, r2 = 4.0, r3 = 1.333;
    float v1 = 5.0, v2 = 2.0, i1 = 2.0;

    // Vth Calculation using superposition:
    float v_5v = v1 * (r3 / (r2 + r3));     // Voltage divider
    float v_2a = i1 * r3;                   // Voltage drop due to 2A current
    float vth = v_5v + v2 - v_2a;

    // Rth: Replace voltage source by short, current source by open
    float r_parallel = (r1 * r2) / (r1 + r2);
    float rth = r_parallel + r3;

    printf("Thevenin Voltage (Vth) = %.2f V\n", vth);
    printf("Thevenin Resistance (Rth) = %.2f Ohm\n", rth);
    return 0;
}
