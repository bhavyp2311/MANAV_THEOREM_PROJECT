#include <stdio.h>

// Function to solve 2x2 linear system using Cramer's Rule
void solveLinear(float a11, float a12, float a21, float a22, float b1, float b2, float* x1, float* x2) {
    float det = a11 * a22 - a12 * a21;
    if (det == 0) {
        printf("System has no unique solution (determinant = 0).\n");
        *x1 = *x2 = 0;
        return;
    }
    *x1 = (b1 * a22 - b2 * a12) / det;
    *x2 = (a11 * b2 - a21 * b1) / det;
}

int main() {
    // Resistances (Ohms)
    float R1, R2, R3;
    // Current sources I1, I2 (enter direction: into node = +ve)
    float I1, I2;
    // Voltage sources connected between V1-GND and V2-GND
    float Vs1, Vs2;

    printf("Enter Resistance R1 (between Node1 and GND): ");
    scanf("%f", &R1);
    printf("Enter Resistance R2 (between Node1 and Node2): ");
    scanf("%f", &R2);
    printf("Enter Resistance R3 (between Node2 and GND): ");
    scanf("%f", &R3);

    printf("Enter Current Source I1 (into Node1): ");
    scanf("%f", &I1);
    printf("Enter Current Source I2 (into Node2): ");
    scanf("%f", &I2);

    printf("Enter Voltage Source Vs1 (between Node1 and GND): ");
    scanf("%f", &Vs1);
    printf("Enter Voltage Source Vs2 (between Node2 and GND): ");
    scanf("%f", &Vs2);

    // Conductances
    float G1 = 1.0 / R1;
    float G2 = 1.0 / R2;
    float G3 = 1.0 / R3;

    float a11 = G1 + G2;
    float a12 = -G2;
    float a21 = -G2;
    float a22 = G2 + G3;

    // Right-hand side (currents)
    float b1 = I1 + G1 * Vs1;
    float b2 = I2 + G3 * Vs2;

    float V1, V2;
    solveLinear(a11, a12, a21, a22, b1, b2, &V1, &V2);

    // Output
    printf("\n--- Nodal Analysis Results ---\n");
    printf("Node Voltage V1: %.2f V\n", V1);
    printf("Node Voltage V2: %.2f V\n", V2);
    printf("Voltage V1-V2  : %.2f V\n", V1 - V2);

    return 0;
}
