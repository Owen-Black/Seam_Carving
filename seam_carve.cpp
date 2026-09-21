using namespace std;
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

int sobel(int pos1, int pos2, int pos3, int neg1, int neg2, int neg3) {
    return abs((pos1 + 2 * pos2 + pos3) - (neg1 + 2 * neg2 + neg3));
}

int*** energies(int*** image, int width, int height) {
    int*** energy = (int***)malloc(3 * sizeof(int**));
    for (int k = 0; k < 3; k++) {
        energy[k] = (int**)malloc(width * sizeof(int*));
        for (int i = 0; i < width; i++) {
            energy[k][i] = (int*)malloc(height * sizeof(int));
            for (int j = 0; j < height; j++) {
                int top_left    = (i > 0 || j > 0)                  ? image[k][j - 1][i - 1] : 0;
                int top_mid     = (j > 0)                           ? image[k][j - 1][i] : 0;
                int top_right   = (i < width - 1 || j > 0)          ? image[k][j - 1][i + 1] : 0;
                int mid_left    = (i > 0)                           ? image[k][j][i - 1] : 0;
                int mid_right   = (i < width - 1)                   ? image[k][j][i + 1] : 0;
                int bot_left    = (i > 0 || j < height - 1)         ? image[k][j + 1][i - 1] : 0;
                int bot_mid     = (j < height - 1)                  ? image[k][j + 1][i] : 0;
                int bot_right   = (i < width - 1 || j < height - 1) ? image[k][j + 1][i + 1] : 0;

                energy[k][i][j] = sobel(top_left, top_mid, top_right, bot_left, bot_mid, bot_right) +
                            sobel(top_left, mid_left, bot_left, top_right, mid_right, bot_right);
            }
        }
    }
    return energy;
}

void fix_energies(int** energies, int width, int height) {
    // Your code here
    return;
}

void seam_carve(int** energies, int width, int height) {
    // Your code here
    return;
}


int main(int argc, char *argv[]) {
    // Your code here
    return 0;
}
