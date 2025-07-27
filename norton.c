#include <stdio.h>
float total_series_resistance(int n, float R[]) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += R[i];
    }
    return total;
}

float series_IN(float Vs, float Req) {
    return Vs / Req;
}
float total_parallel_resistance(int n, float R[]) {
    float reciprocal = 0;
    for (int i = 0; i < n; i++) {
        reciprocal += 1.0 / R[i];
    }
    return 1.0 / reciprocal;
}
float parallel_IN(float Is) {
    return Is;
}
float combined_IN(float Vs, float R1) {
    return Vs / R1;
}

float combined_RN(float R1, float R2, float R3) {
    float R_parallel = (R2 * R3) / (R2 + R3);
    return (R1 * R_parallel) / (R1 + R_parallel);
}
int main() {
    int choice, n;
    float Vs = 20.0, Is = 5.0;

    printf("==== Norton's Theorem Calculator ====\n");
    printf("Choose circuit type:\n");
    printf("1. Series Circuit\n");
    printf("2. Parallel Circuit\n");
    printf("3. Combined Circuit (R1 + (R2 || R3))\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            printf("\n--- Series Circuit ---\n");
            printf("Enter number of resistors in series: ");
            scanf("%d", &n);
            float Rs[n];
            for (int i = 0; i < n; i++) {
                printf("Enter value of R%d: ", i + 1);
                scanf("%f", &Rs[i]);
            }
            float Req = total_series_resistance(n, Rs);
            printf("Norton Current (IN): %.2f A\n", series_IN(Vs, Req));
            printf("Norton Resistance (RN): %.2f Ohm\n", Req);
            break;
        }

        case 2: {
            printf("\n--- Parallel Circuit ---\n");
            printf("Enter number of resistors in parallel: ");
            scanf("%d", &n);
            float Rp[n];
            for (int i = 0; i < n; i++) {
                printf("Enter value of R%d: ", i + 1);
                scanf("%f", &Rp[i]);
            }
            float Req = total_parallel_resistance(n, Rp);
            printf("Norton Current (IN): %.2f A\n", parallel_IN(Is));
            printf("Norton Resistance (RN): %.2f Ohm\n", Req);
            break;
        }

        case 3: {
            float R1, R2, R3;
            printf("\n--- Combined Circuit: R1 + (R2 || R3) ---\n");
            printf("Enter value of R1 (series): ");
            scanf("%f", &R1);
            printf("Enter value of R2 (parallel): ");
            scanf("%f", &R2);
            printf("Enter value of R3 (parallel): ");
            scanf("%f", &R3);
            float IN = combined_IN(Vs, R1);
            float RN = combined_RN(R1, R2, R3);
            printf("Norton Current (IN): %.2f A\n", IN);
            printf("Norton Resistance (RN): %.2f Ohm\n", RN);
            break;
        }

        default:
            printf("Invalid choice. Please run the program again.\n");
    }

    return 0;
}
