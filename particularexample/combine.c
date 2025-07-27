#include <stdio.h>
#include <stdlib.h>
// Function: Thevenin Voltage
float thevenin_voltage() {
    float v1 = 5.0 * (1.333 / (1.333 + 4.0));
    float v2 = 2.0;
    float v3 = 2.0 * 1.333;
    float vth = v1 + v2 - v3;
    return vth;
}

// Function: Thevenin Resistance
float thevenin_resistance() {
    float r_parallel = (8.0 * 4.0) / (8.0 + 4.0);
    return r_parallel + 1.333;
}

// Function: Norton Current
float norton_current(float vth, float rth) {
    return vth / rth;
}

// Function: Superposition
void superposition_voltage_on_RL() {
    float v1 = 5.0 * (1.333 / (1.333 + 4.0));
    float v2 = 2.0;
    float v3 = 2.0 * 1.333;
    float v_net = v1 + v2 - v3;
    printf("Superposition: Voltage across RL = %.2f V\n", v_net);
}

// Function: Nodal Analysis
void nodal_analysis() {
    float va;
    va = ((5.0/4.0) + (2.0/1.333) + 2) / ((1.0/4.0) + (1.0/1.333));
    float vr3 = va - 2.0;
    printf("Nodal Analysis: Voltage across RL = %.2f V\n", vr3);
}

// Function: Max Power Transfer
void max_power_transfer() {
    float rth = thevenin_resistance();
    float vth = thevenin_voltage();
    float rl = rth;
    float p_max = (vth * vth) / (4 * rl);
    printf("Maximum Power Transfer:\n");
    printf("RL = %.2f Ohm\n", rl);
    printf("Maximum Power = %.2f W\n", p_max);
}

int main() {
    int choice;
    float vth, rth, inorton;

    do {
        printf("\n==== NETWORK THEOREMS MENU ====\n");
        printf("1. Thevenin Equivalent\n");
        printf("2. Norton Equivalent\n");
        printf("3. Superposition\n");
        printf("4. Nodal Analysis\n");
        printf("5. Maximum Power Transfer\n");
        printf("6. All Together\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                vth = thevenin_voltage();
                rth = thevenin_resistance();
                printf("Thevenin Equivalent Voltage: %.2f V\n", vth);
                printf("Thevenin Equivalent Resistance: %.2f Ohm\n", rth);
                break;

            case 2:
                vth = thevenin_voltage();
                rth = thevenin_resistance();
                inorton = norton_current(vth, rth);
                printf("Norton Equivalent Current: %.2f A\n", inorton);
                printf("Norton Resistance: %.2f Ohm\n", rth);
                break;

            case 3:
                superposition_voltage_on_RL();
                break;

            case 4:
                nodal_analysis();
                break;

            case 5:
                max_power_transfer();
                break;

            case 6:
                vth = thevenin_voltage();
                rth = thevenin_resistance();
                inorton = norton_current(vth, rth);
                printf("Thevenin Voltage: %.2f V\n", vth);
                printf("Thevenin Resistance: %.2f Ohm\n", rth);
                printf("Norton Current: %.2f A\n", inorton);
                superposition_voltage_on_RL();
                nodal_analysis();
                max_power_transfer();
                break;

            case 7:
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 0);

    return 0;
}
