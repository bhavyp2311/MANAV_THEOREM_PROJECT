#include <stdio.h>

int main() {
    // Given values
    float R1 = 10.0;
    float R2 = 20.0;
    float R3 = 30.0;
    float I1 = 4.0;     // Current source
    float V1 = 60.0;    // Voltage source
    float k = 0.4;      // Controlled voltage source is 0.4 * ix

    float V30_total = 0.0;

    // Step 1: Only I1 = 4A active, V1 = shorted
    // ------------------------------------------
    // Using KCL or equivalent resistance to find ix and V30
    float Req1 = (R2 * R3) / (R2 + R3); // R2 || R3
    float Req_total_1 = R1 + Req1;

    float V_R2 = (I1 * Req1) * (R2 / (R2 + R3));
    float ix = V_R2 / R2;
    float V_dep_1 = k * ix;
    float V30_1 = (I1 * Req1) * (R3 / (R2 + R3)) + V_dep_1;

    // Step 2: Only V1 = 60V active, I1 = open
    // ------------------------------------------
    // Using voltage division between R2 and R3
    float ix2 = V1 / (R2 + R3);
    float V_dep_2 = k * ix2;
    float V30_2 = V1 * (R3 / (R2 + R3)) + V_dep_2;

    // Superposition result
    V30_total = V30_1 + V30_2;

    printf("Voltage across 30Ω resistor using Superposition:\n");
    printf("Due to 4A current source: %.2f V\n", V30_1);
    printf("Due to 60V voltage source: %.2f V\n", V30_2);
    printf("Total voltage (V30): %.2f V\n", V30_total);

    return 0;
}
