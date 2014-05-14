#include <stdint.h>
#include <math.h>

typedef uint8_t row_t[256] __attribute__((aligned(16)));

/* row is a pointer to a 256-byte vector
 * table is a pointer to 64 256-byte vectors
 * n is a 256-bit vector
 * Compute: row += n . table
 */
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
