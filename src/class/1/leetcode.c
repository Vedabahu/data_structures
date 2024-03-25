#include <stdio.h>

int myadd(int a, int b) {
	short carry = 0;
	while (b != 0) {
		carry = a&b;
		a = a^b;
		b = carry<<1;
	}
	return a;
}

int main() {
	printf("%d + %d = %d", 12322, 132323, myadd(12322, 132323));
}