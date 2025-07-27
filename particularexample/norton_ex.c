#include <stdio.h>

// Function to calculate Norton equivalent current and resistance
int main() {
    // Given resistances
    float R1 = 2.0;  // Top left 2Ω
    float R2 = 2.0;  // Middle 2Ω (parallel path)
    float R3 = 2.0;  // Top right 2Ω
    float RL = 3.0;  // Load resistor (3Ω)
    float V = 12.0;  // Voltage source

    // Step 1: Remove RL (3Ω), find Norton current (IN)
    // IN is current through a short where RL was
    // Use current division between top and bottom branches

    // Top branch: R1 + R3 = 2 + 2 = 4Ω
    float Rt_top = R1 + R3;
    // Bottom branch: R2 = 2Ω

    // Total resistance seen by 12V source:
    float Rt_parallel = 1.0 / (1.0 / Rt_top + 1.0 / R2);
    
    // Total current from source:
    float Itotal = V / Rt_parallel;

    // IN = current through top branch = current divider
    float IN = Itotal * (1.0 / Rt_top) / (1.0 / Rt_top + 1.0 / R2);

    // Step 2: Find RN = Norton resistance (Rth)
    // Replace 12V source with short
    // Then find equivalent resistance across terminals of RL

    // RN = R1 in series with R3 in parallel with R2
    float R_top = R1 + R3;
    float RN = 1.0 / (1.0 / R_top + 1.0 / R2);

    // Step 3: Reattach RL (3Ω), find load current using:
    // I = IN * RN / (RN + RL)
    float IL = IN * RN / (RN + RL);

    // Print results
    printf("Norton Current (IN): %.2f A\n", IN);
    printf("Norton Resistance (RN): %.2f Ohm\n", RN);
    printf("Load Current through 3Ω (IL): %.2f A\n", IL);

    return 0;
}
