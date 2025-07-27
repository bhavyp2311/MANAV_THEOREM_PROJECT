#include <stdio.h>

int main() {
    float vth = 1.17;   // Use result from Thevenin
    float rth = 4.67;

    float inorton = vth / rth;

    printf("Norton Current (In) = %.2f A\n", inorton);
    printf("Norton Resistance (Rn) = %.2f Ohm\n", rth);
    return 0;
}
