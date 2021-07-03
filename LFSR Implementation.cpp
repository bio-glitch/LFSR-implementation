#include <stdint.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    uint16_t lfsr = 0xACE1u;
    unsigned period = 0;
    char s[16+1];

    do {
          unsigned lsb = lfsr & 1;  /* Get lsb (i.e., the output bit). */
          lfsr >>= 1;               /* Shift register */
          if (lsb == 1)             /* Only apply toggle mask if output bit is 1. */
            lfsr ^= 0xB400u;        /* Apply toggle mask, value has 1 at bits corresponding to taps, 0 elsewhere. */
                                   
          ++period;

          for (int i = 0; i < 16; i++)
          {
             s[15 - i] = (lfsr & (1 << i)) ? '1' : '0';
          }
          s[16] = '\0';
          printf("\n%10d: %s", period, s);
    } while(lfsr != 0xACE1u);

    return 0;
}
