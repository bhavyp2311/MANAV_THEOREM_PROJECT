#include <stdio.h>
float calculate_vth_series(float V, float R1, float R2) {
    return V * (R2 / (R1 + R2));
}
float calculate_rth_series(float R2) {
    return R2;
}

float calculate_vth_parallel(float V) {
    return V;
}
float calculate_rth_parallel(float R1, float R2) {
    return (R1 * R2) / (R1 + R2);
}
float calculate_load_current(float Vth, float Rth, float RL) {
    return Vth / (Rth + RL);
}
int main() {
    int choice;
    float V, R1, R2, RL, Vth, Rth, IL;

    printf("------ Thevenin's Theorem Calculator ------\n");
    printf("Select Circuit Type:\n");
    printf("1. Series Circuit\n");
    printf("2. Parallel Circuit\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1) {
        // Series Circuit
        printf("\n--- Series Circuit Selected ---\n");
        printf("Enter Source Voltage (V): ");
        scanf("%f", &V);
        printf("Enter Resistance R1 (Ohms): ");
        scanf("%f", &R1);
        printf("Enter Resistance R2 (Ohms): ");
        scanf("%f", &R2);
        printf("Enter Load Resistance RL (Ohms): ");
        scanf("%f", &RL);

        Vth = calculate_vth_series(V, R1, R2);
        Rth = calculate_rth_series(R2);
        IL = calculate_load_current(Vth, Rth, RL);

    } else if(choice == 2) {
        // Parallel Circuit
        printf("\n--- Parallel Circuit Selected ---\n");
        printf("Enter Source Voltage (V): ");
        scanf("%f", &V);
        printf("Enter Resistance R1 (Ohms): ");
        scanf("%f", &R1);
        printf("Enter Resistance R2 (Ohms): ");
        scanf("%f", &R2);
        printf("Enter Load Resistance RL (Ohms): ");
        scanf("%f", &RL);

        Vth = calculate_vth_parallel(V);
        Rth = calculate_rth_parallel(R1, R2);
        IL = calculate_load_current(Vth, Rth, RL);

    } else {
        printf("Invalid choice! Please select 1 or 2.\n");
        return 1;
    }

    printf("\n------ Thevenin’s Equivalent Result ------\n");
    printf("Thevenin Voltage (Vth): %.2f V\n", Vth);
    printf("Thevenin Resistance (Rth): %.2f Ohms\n", Rth);
    printf("Load Current (IL): %.2f A\n", IL);

    return 0;
}