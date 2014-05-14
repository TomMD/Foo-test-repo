#include <stdint.h>
#include <math.h>

typedef uint8_t row_t[256] __attribute__((aligned(16)));

void rowSum(row_t row, row_t *table, uint64_t n) {
        int j;
        for (; n; n>>=1, table++) {
                if (n & 1) {
                        for (j = 0; j < 256; j++) {
                                row[j] ^= (*table)[j];
                        }
                }
        }
}
