#include <stdio.h>

int main() {
    // Given values
    float R1 = 1.0;
    float R2 = 4.0;
    float R3 = 5.0;
    float Is1 = 2.0;
    float Is2 = 1.0;

    // Applying nodal analysis at node 'Va'
    // (Va/R1) + (Va/R2) + (Va/R3) = Is1 - Is2

    float LHS_coeff = (1.0 / R1) + (1.0 / R2) + (1.0 / R3);
    float RHS = Is1 - Is2;

    float Va = RHS / LHS_coeff;

    printf("Voltage across R3 (Va): %.4f V\n", Va);

    // Optional: current through R3
    float I_R3 = Va / R3;
    printf("Current through R3: %.4f A\n", I_R3);

    return 0;
}
