#include <stdio.h>

// Calculate equivalent resistance for R1, R2 in series and R3 in parallel with the series
float total_resistance(float R1, float R2, float R3) {
    float Rs = R1 + R2;
    return (Rs * R3) / (Rs + R3); // (R1 + R2) || R3
}

// Function to compute current when voltage source active
float current_due_to_voltage(float Vs, float R1, float R2, float R3) {
    float Req = total_resistance(R1, R2, R3);
    return Vs / Req;
}

// Function to compute current when current source active
float current_due_to_current(float Is) {
    return Is;  // Assuming all current flows through load (ideal case)
}

int main() {
    int choice;
    float R1, R2, R3, Vs1 = 0, Vs2 = 0, Is1 = 0, Is2 = 0;
    float I1 = 0, I2 = 0, totalI = 0;

    printf("===== Superposition Theorem Calculator =====\n");
    printf("Available Circuit Config: R1 + R2 in series, parallel with R3\n");
    printf("Choose configuration:\n");
    printf("1. Two Voltage Sources\n");
    printf("2. Two Current Sources\n");
    printf("3. One Voltage and One Current Source\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    // Get resistor values
    printf("Enter R1 (Ohm): ");
    scanf("%f", &R1);
    printf("Enter R2 (Ohm): ");
    scanf("%f", &R2);
    printf("Enter R3 (Ohm): ");
    scanf("%f", &R3);

    switch (choice) {
        case 1: // Two voltage sources
            printf("\n--- Two Voltage Sources ---\n");
            printf("Enter Vs1 (V): ");
            scanf("%f", &Vs1);
            printf("Enter Vs2 (V): ");
            scanf("%f", &Vs2);

            I1 = current_due_to_voltage(Vs1, R1, R2, R3);  // Vs1 active, Vs2 off (short)
            I2 = current_due_to_voltage(Vs2, R1, R2, R3);  // Vs2 active, Vs1 off (short)
            totalI = I1 + I2;

            printf("Current due to Vs1: %.2f A\n", I1);
            printf("Current due to Vs2: %.2f A\n", I2);
            printf("Total current by superposition: %.2f A\n", totalI);
            break;

        case 2: // Two current sources
            printf("\n--- Two Current Sources ---\n");
            printf("Enter Is1 (A): ");
            scanf("%f", &Is1);
            printf("Enter Is2 (A): ");
            scanf("%f", &Is2);

            I1 = current_due_to_current(Is1);  // Is1 active, Is2 off (open)
            I2 = current_due_to_current(Is2);  // Is2 active, Is1 off (open)
            totalI = I1 + I2;

            printf("Current due to Is1: %.2f A\n", I1);
            printf("Current due to Is2: %.2f A\n", I2);
            printf("Total current by superposition: %.2f A\n", totalI);
            break;

        case 3: // One voltage and one current source
            printf("\n--- One Voltage + One Current Source ---\n");
            printf("Enter Vs (V): ");
            scanf("%f", &Vs1);
            printf("Enter Is (A): ");
            scanf("%f", &Is1);

            I1 = current_due_to_voltage(Vs1, R1, R2, R3); // Vs active, Is off (open)
            I2 = current_due_to_current(Is1);             // Is active, Vs off (short)
            totalI = I1 + I2;

            printf("Current due to Vs: %.2f A\n", I1);
            printf("Current due to Is: %.2f A\n", I2);
            printf("Total current by superposition: %.2f A\n", totalI);
            break;

        default:
            printf("Invalid choice. Please run again.\n");
            break;
    }

    return 0;
}
