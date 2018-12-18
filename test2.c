#include <stdint.h>
#include <stdio.h>

uint8_t top = 0, bottom = 0;
uint16_t combo = 0, combo2 = 0;
uint16_t out = 0;
uint8_t* pseudo;
uint8_t* pseudo2;


uint8_t joyScale(int16_t signd) {
	//if (signd < -32760) return 0;
	//if (signd > 32760) return 255;
	if (signd == 0) return 128;
	float r = ((float)(signd + 32767) / 65534);
	uint8_t uint8 = r * 255;
	return uint8;
}

void testconv(int16_t signd){
	printf("\nS16int: %i \n", signd);
	uint8_t n = joyScale(signd);
	printf("uint8:  %u \n", n);
	return;
	// float r = ((float)(signd + 32767) / 65534);
	// uint8_t uint8 = r * 255;

	// printf("\nRatio:  %f \n", r);
	// printf("uint8:  %u \n", joyScale(signd));
}

int main(){
	testconv(-32767);
	testconv(0);
	testconv(32767);
	for (;;){
		int16_t signd = 0;
		printf("S16int In: (-32768 - +32767): ");
		scanf("%d", &signd);

		// printf("Cast (0-65535): %i \n", (uint16_t)(signd-32768));
		// printf("Cast (0-255):   %i \n", (uint8_t)((signd-32768)/128));

		testconv(signd);
	}
}

int main2(){
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
		printf("Combo: %u\n", combo);

		combo2 = combo;

		pseudo2 = (uint8_t*)(&combo2);

		top = pseudo2[0];
		bottom = pseudo2[1];

		printf("Recovered: %x, %x\n", top, bottom);
	}
	return 0;
}