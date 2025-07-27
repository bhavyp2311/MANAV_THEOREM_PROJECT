#include <stdio.h>

int main() {
    float r2 = 4.0, r3 = 1.333;
    float v1 = 5.0, v2 = 2.0, i1 = 2.0;

    // Voltage from 5V source
    float v_from_5v = v1 * (r3 / (r2 + r3));

    // Voltage from 2V source is directly in series
    float v_from_2v = v2;

    // Voltage drop from 2A current source
    float v_from_2a = i1 * r3;

    float net_voltage = v_from_5v + v_from_2v - v_from_2a;

    printf("Net Voltage across RL by Superposition = %.2f V\n", net_voltage);
    return 0;
}
