#include <stdint.h>
#include <stdio.h>

uint8_t top = 0, bottom = 0;
uint16_t combo = 0, combo2 = 0;
uint16_t out = 0;
uint8_t* pseudo;
uint8_t* pseudo2;

int main(){
	for (;;) {
		top = 0;
		bottom = 0;
		combo = 0;
		out = 0;

		printf("Top In: ");
		scanf("%d", &top);

		printf("Bottom In: ");
		scanf("%d", &bottom);

		printf("Top: %x \n", top);
		printf("Bottom: %x\n", bottom);

		pseudo = (uint8_t*)(&combo);

		pseudo[0] = top;
		pseudo[1] = bottom;

		printf("Combo: %x\n", combo);

		combo2 = combo;

		pseudo2 = (uint8_t*)(&combo2);

		top = pseudo2[0];
		bottom = pseudo2[1];

		printf("Recovered: %x, %x\n", top, bottom);
	}
	return 0;
}