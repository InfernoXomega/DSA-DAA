#include <stdio.h>

void addpolynomials(int poly1[], int poly2[], int result[], int n) {
	for(int i=0; i<=n; i++) {
		result[i] = poly1[i] + poly2[i];
	}
}

void multiplypolynomials(int poly1[], int poly2[], int result[], int n) {
	for(int i=0; i<= 2*n; i++) {
		result[i] = 0;
	}
	
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			result[i+j] += poly1[i] * poly2[j];
		}
	}
}

int main() {
	int n;
	printf("Enter the degree of the polynomial: ");
	scanf("%d", &n);
	
	int poly1[n+1], poly2[n+1], sum[n+1], product[2 * n + 1];
	printf("Enter coefficients of the first polynomial:\n");
	for(int i=0; i<=n; i++) {
		printf("Coefficient for x^%d: ", i);
		scanf("%d", &poly1[i]);
	}
	printf("Enter coefficients of the second polynomial:\n");
	for(int i=0; i<=n; i++) {
		printf("Coefficient for x^%d: ", i);
		scanf("%d", &poly2[i]);
	}
	
	addpolynomials(poly1, poly2, sum, n);
	multiplypolynomials(poly1, poly2, product, n);
	
	printf("Sum of the polynomials:\n");
	for(int i=0; i<=n; i++) {
		printf("%dx^%d ", sum[i], i);
		if(i<n) {
			printf("+ ");
		}
	}
	printf("\n");
	
	printf("Product of the polynomials:\n");
	for(int i=0; i <= 2 * n; i++) {
		printf("%dx^%d ", product[i], i);
		if(i < 2 * n) {
			printf("+ ");
		}
	}
	printf("\n");
	
	return 0;
}
