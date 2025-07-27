#include <stdio.h>

// Function to calculate Thevenin equivalent voltage Vth
float calculate_vth(float Vs, float Rs1, float R10, float R4, float Is) {
    // Using node voltage method at A, when RL is removed
    // Vth = voltage at node A w.r.t B
    // Superposition principle:
    // From voltage source: V1 = Vs * R4 / (Rs1 + R4)
    // From current source: V2 = current flows through R10 => V2 = Is * R10 * R4 / (R10 + R4)
    
    float V_from_Vs = Vs * R4 / (Rs1 + R4);
    float V_from_Is = Is * (R10 * R4) / (R10 + R4);
    
    return V_from_Vs + V_from_Is;
}

// Function to calculate Thevenin resistance Rth
float calculate_rth(float Rs1, float R10, float R4) {
    // Deactivate voltage source → short circuit
    // Deactivate current source → open circuit
    // Rth = Rs1 in parallel with (R10 + R4)
    float right_series = R10 + R4;
    return (Rs1 * right_series) / (Rs1 + right_series);
}

// Calculate load current using Vth and Rth
float calculate_il(float Vth, float Rth, float RL) {
    return Vth / (Rth + RL);
}

int main() {
    // Given values
    float Vs = 20.0;   // 20∠0° V
    float Is = 5.0;    // 5∠0° A
    float Rs1 = 5.0;   // Left side resistor
    float R10 = 10.0;  // Right side top resistor
    float R4 = 4.0;    // Right side bottom resistor
    float RL = 5.0;    // Load resistor

    float Vth = calculate_vth(Vs, Rs1, R10, R4, Is);
    float Rth = calculate_rth(Rs1, R10, R4);
    float IL = calculate_il(Vth, Rth, RL);

    printf("---- Thevenin’s Theorem Result ----\n");
    printf("Thevenin Voltage (Vth): %.2f V\n", Vth);
    printf("Thevenin Resistance (Rth): %.2f Ohms\n", Rth);
    printf("Load Current (IL through 5Ω): %.2f A\n", IL);

    return 0;
}