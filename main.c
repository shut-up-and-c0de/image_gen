#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH  1920
#define HEIGHT 1080

int dist(int x1, int y1, int x2, int y2) {
	int dx = x1 - x2;
	int dy = y1 - y2;
	return dx*dx + dy*dy;
}

int lerp(int v0, int v1, int t) {
	return v0 + t * (v1 - t);
}

uint8_t rand_col(int col) {
	int adjusted = (int) (rand() * col);
	uint8_t out = (uint8_t) adjusted;
	return out;
}

int rand_square(int max) {
	return (rand() % max) * (rand() % max);
}

void draw() {
	FILE *file = fopen("image.ppm", "w");

	// Netpbm P6 Spec https://netpbm.sourceforge.net/doc/ppm.html
	/*
	  P6
	  WIDTH HEIGHT 255
	  RGBRGBRGB...
	 */
	fprintf(file, "P6\n%d %d 255\n", WIDTH, HEIGHT);

	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++) {
			int col =  dist(x, y, WIDTH/2, HEIGHT/2) <= rand_square(900/2)  ? lerp(0, rand_col(256), x*y) : 0; 
			uint8_t bytes[3] = {
				rand_col(col),
				rand_col(col),
				rand_col(col),
			};
			fwrite(bytes, sizeof(bytes), 1, file);
	}
	
	fclose(file);
}

int main(int argc, char **argv) {
	srand(time(0));
	draw();	
}
