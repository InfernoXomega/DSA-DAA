#include <stdio.h>

int hornerRule(int coefficients[], int n, int x) {
    if (n == 1) {
        return coefficients[0];
    }

    return coefficients[n - 1] + x * hornerRule(coefficients, n - 1, x);
}

int main() {
    int n, x;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);

    int coefficients[n + 1];

    printf("Enter the coefficients of the polynomial (from highest degree to constant term):\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &coefficients[i]);
    }

    printf("Enter the value of x for evaluation: ");
    scanf("%d", &x);

    int result = hornerRule(coefficients, n + 1, x);

    printf("The result of the polynomial at x = %d is: %d\n", x, result);

    return 0;
}